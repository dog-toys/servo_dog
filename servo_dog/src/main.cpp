#include <Arduino.h>

#include "actions.h"
#include "mqtt.h"

#include <ArduinoBLE.h>

BLEService myService("fff0");
BLEIntCharacteristic myCharacteristic("fff1", BLERead | BLEBroadcast);
// Advertising parameters should have a global scope. Do NOT define them in 'setup' or in 'loop'
const uint8_t completeRawAdvertisingData[] = {0x02,0x01,0x06,0x09,0xff,0x01,0x01,0x00,0x01,0x02,0x03,0x04,0x05};

void setup() {
    Serial.begin(115200);
    s1.attach(18);
    s2.attach(17);
    s3.attach(26);
    s4.attach(27);

    down();

    // MQTT SETUP
    // setup_wifi();
    // client.setServer(mqtt_server, mqtt_port);
    // client.setCallback(callback);


    // BLE 
    if (!BLE.begin()) {
        Serial.println("failed to initialize BLE!");
        while (1);
    }

    myService.addCharacteristic(myCharacteristic);
    BLE.addService(myService);

    // Build advertising data packet
    BLEAdvertisingData advData;
    // If a packet has a raw data parameter, then all the other parameters of the packet will be ignored
    advData.setRawData(completeRawAdvertisingData, sizeof(completeRawAdvertisingData));  
    // Copy set parameters in the actual advertising packet
    BLE.setAdvertisingData(advData);

    // Build scan response data packet
    BLEAdvertisingData scanData;
    scanData.setLocalName("Test advertising raw data");
    // Copy set parameters in the actual scan response packet
    BLE.setScanResponseData(scanData);
    
    BLE.advertise();

    Serial.println("advertising ...");
}


void loop() {
    // MQTT LOOP
    // if (!client.connected()) {
    //     reconnect();
    // }
    // client.loop();


    BLE.poll();
}

