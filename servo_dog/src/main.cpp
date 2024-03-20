#include <Arduino.h>
#include <ESP32Servo.h>
Servo s1, s2, s3, s4;

void s1_1() {
  s1.write(0);
}

void s1_up() {
  s1.write(45);
}

void s1_down() {
  s1.write(90);
}

void s1_back() {
  s1.write(135);
}

void s1_5() {
  s1.write(180);
}

void s2_1() {
  s2.write(180);
}

void s2_up() {
  s2.write(135);
}

void s2_down() {
  s2.write(90);
}

void s2_back() {
  s2.write(45);
}

void s2_5() {
  s2.write(0);
}

void s3_1() {
  s3.write(0);
}

void s3_up() {
  s3.write(45);
}

void s3_down() {
  s3.write(90);
}

void s3_back() {
  s3.write(135);
}

void s3_5() {
  s3.write(180);
}

void s4_1() {
  s4.write(180);
}

void s4_up() {
  s4.write(135);
}

void s4_down() {
  s4.write(90);
}

void s4_back() {
  s4.write(45);
}

void s4_5() {
  s4.write(0);
}



void setup() {
  Serial.begin(115200);
  s1.attach(18);
  s2.attach(17);
  s3.attach(26);
  s4.attach(27);

  s1_down();
  s2_down();
  s3_down();
  s4_down();
}

void loop() {
  s1_up();
  s4_up();
  delay(100);
  s2_back();
  s3_back();
  delay(100);
  s1_down();
  s4_down();
  delay(100);
  s2_down();
  s3_down();
  delay(100);

  s2_up();
  s3_up();
  delay(100);
  s1_back();
  s4_back();
  delay(100);
  s2_down();
  s3_down();
  delay(100);
  s1_down();
  s4_down();
  delay(100);

}

