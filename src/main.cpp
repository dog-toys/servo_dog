#include <Arduino.h>

#include "actions.h"
#include "mqtt.h"

#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>

#define SERVICE_UUID "1da9979b-c9c7-4a23-83fd-b4459898db47"
#define CHARACTERISTIC_UUID "92e539eb-6962-411b-9842-f73c26581fc2"

bool isAdvertising = true;
int clientCount = 0;

class MyServerCallbacks: public BLEServerCallbacks {
    void onConnect(BLEServer* pServer) {
        clientCount++;
        isAdvertising = false;
        Serial.println("Client connected, client count: " + String(clientCount));
    }

    void onDisconnect(BLEServer* pServer) {
        clientCount--;
        Serial.println("Client disconnected, client count: " + String(clientCount));
    }
};

class MySecurity: public BLESecurityCallbacks {
    // 显示本机要求的静态码
    void onPassKeyNotify(uint32_t pass_key) {
        Serial.println("The passkey Notify number: " + String(pass_key));
    }

    // 认证结果
    void onAuthenticationComplete(esp_ble_auth_cmpl_t auth_cmpl) {
        if (!auth_cmpl.success) {
            Serial.println("Authentication failed!");
        } else {
            Serial.println("Authentication success!");
        }
    }

    // 显示动态码并确定是否同意配对
    bool onConfirmPIN(uint32_t pin) {
        Serial.println("onConfirm: " + String(pin));
        return true;
    }

    uint32_t onPassKeyRequest() {
        Serial.println("The passkey Request");
        return 0;
    }

    bool onSecurityRequest() {
        return true;
    }

};

class MyCharacteristicCallbacks: public BLECharacteristicCallbacks {
    void onWrite(BLECharacteristic *pCharacteristic) {
        std::string value = pCharacteristic->getValue();
        if (value.length() > 0) {
            Serial.println("Received value: " + String(value.c_str()));
            if (value == "forward") {
                forward();
            } else if (value == "backward") {
                backward();
            // } else if (value == "left") {
            //     left();
            // } else if (value == "right") {
            //     right();
            } else if (value == "stand_up") {
                stand_up();
            } else if (value == "sit_down") {
                sit_down();
            }
        }
    }
};

void BLEInit()
{
    BLEDevice::init("Fish Fish");
    auto local_address = BLEDevice::getAddress();
    Serial.println(local_address.toString().c_str());

    // set security， 使用静态密码认证
    // BLEDevice::setEncryptionLevel(ESP_BLE_SEC_ENCRYPT_MITM);
    // BLEDevice::setSecurityCallbacks(new MySecurity());
    // BLESecurity *pSecurity = new BLESecurity();
    // pSecurity->setStaticPIN(252525);


    // Create server and service
    BLEServer *pServer = BLEDevice::createServer();
    BLEService *pService = pServer->createService(SERVICE_UUID);
    BLECharacteristic *pCharateristic = pService->createCharacteristic(
        CHARACTERISTIC_UUID,
        BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_WRITE
    );
    pCharateristic->setValue("Hello World");
    pCharateristic->setCallbacks(new MyCharacteristicCallbacks());

    pServer->setCallbacks(new MyServerCallbacks());
    pService->start();

    BLEAdvertising *pAdvertising = pServer->getAdvertising();
    pAdvertising->addServiceUUID(SERVICE_UUID);
    pAdvertising->setScanResponse(true);
    pAdvertising->setMinPreferred(0x12);
    BLEDevice::startAdvertising();
    Serial.println("BLE Advertising first start");
}

unsigned long lastMillis = 0;

void setup() {
    lastMillis = millis();
    Serial.begin(115200);
    servoAttach();
    stand_up();

    // MQTT SETUP
    // setup_wifi();
    // client.setServer(mqtt_server, mqtt_port);
    // client.setCallback(callback);

    // BLE
    BLEInit();
}



void loop() {
    // MQTT LOOP
    // if (!client.connected()) {
    //     reconnect();
    // }
    // client.loop();

    // BLE LOOP
    if (BLEDevice::getInitialized() && !isAdvertising && clientCount == 0) {
        delay(500);
        BLEDevice::startAdvertising();
        isAdvertising = true;
        Serial.println("BLE Advertising start again");
    }
    delay(100);

    // dance2();

    // if (millis() - lastMillis <= 3000) {
    //     forward();
    // } else if (millis() - lastMillis <= 6000) {
    //     backward();
    // } else if (millis() - lastMillis <= 9000) {
    //     sit_down();
    // } else if (millis() - lastMillis <= 12000) {
    //     stand_up();
    // } else if (millis() - lastMillis <= 15000) {
    //     left_front_hand_up();
    // } else if (millis() - lastMillis <= 18000) {
    //     stand_up();
    //     right_front_hand_up();
    // } else if (millis() - lastMillis <= 21000) {
    //     stand_up();
    // } else if (millis() - lastMillis <= 40000) {
    // }

}

