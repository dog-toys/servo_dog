#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_PWMServoDriver.h>
#include <U8g2lib.h>

// #include "actions.h"
#include "mqtt.h"
#include "ble.h"
#include "actions_pwm.h"

// #define SDA_OLED 27
// #define SCL_OLED 26
// #define SDA_SERVO 21
// #define SCL_SERVO 22
// TwoWire I2Cone = TwoWire(0);
// TwoWire I2Ctwo = TwoWire(1);

// SCL, SDA
// U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, SCL_SERVO, SDA_SERVO, U8X8_PIN_NONE);

// unsigned long lastMillis = 0;

void setup() {
    // lastMillis = millis();
    // Wire.begin();
    // I2Cone.begin(SDA_OLED, SCL_OLED);
    // I2Ctwo.begin(SDA_SERVO, SCL_SERVO);

    Serial.begin(115200);

    // initServo();
    // stand_up();

    // MQTT SETUP
    // setup_wifi();
    // client.setServer(mqtt_server, mqtt_port);
    // client.setCallback(callback);

    // BLE
    // BLEInit();

    // Directly use PWM to control servo
    pwm_servo_init();

    // u8g2.setBusClock(800000);
    // u8g2.begin();
    // u8g2.enableUTF8Print();
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
    // dance2();

    // if (millis() - lastMillis <= 3000) {
    //     forward();
    // } else if (millis() - lastMillis <= 6000) {
    //     backward();
    // } else if (millis() - lastMillis <= 9000) {}

    // static unsigned int start = millis();
    // u8g2.clearBuffer();
    // u8g2.setFont(u8g2_font_ncenB14_tr);
    // u8g2.drawStr(0, 13, "eeeeo, World!");

    // u8g2.setFont(u8g2_font_wqy14_t_gb2312b);
    // u8g2.setCursor(0, 30);
    // u8g2.print("你好，世界！");
    // u8g2.drawUTF8(0, 50, "世界！");

    // u8g2.setFont(u8g2_font_open_iconic_weather_4x_t);
    // u8g2.drawGlyph(90, 60, 0x0045);

    // u8g2.sendBuffer();
    // static unsigned int end = millis();
    // Serial.println(end - start);

    // pwm_servo_set(0, 0);
    // delay(1000);
    // pwm_servo_set(0, 180);
    // delay(1000);


}

