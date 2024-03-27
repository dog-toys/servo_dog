#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_PWMServoDriver.h>

// #include "actions.h"
#include "mqtt.h"
#include "ble.h"
#include "actions_pwm.h"

unsigned long lastMillis = 0;

void setup() {
    lastMillis = millis();
    Serial.begin(115200);
    // initServo();
    // stand_up();

    // MQTT SETUP
    // setup_wifi();
    // client.setServer(mqtt_server, mqtt_port);
    // client.setCallback(callback);

    // BLE
    // BLEInit();
    pwm_servo_init();

}



void loop() {
    // MQTT LOOP
    // if (!client.connected()) {
    //     reconnect();
    // }
    // client.loop();

    // BLE LOOP
    // if (BLEDevice::getInitialized() && !isAdvertising && clientCount == 0) {
    //     delay(500);
    //     BLEDevice::startAdvertising();
    //     isAdvertising = true;
    //     Serial.println("BLE Advertising start again");
    // }
    // delay(10);


    pwm_servo_set(0, 0);
    pwm_servo_set(1, 0);
    pwm_servo_set(2, 0);
    pwm_servo_set(3, 0);
    delay(1000); // 等待1秒
    pwm_servo_set(0, 180);
    pwm_servo_set(1, 180);
    pwm_servo_set(2, 180);
    pwm_servo_set(3, 180);
    delay(1000); // 等待1秒
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

