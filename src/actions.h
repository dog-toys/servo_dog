#ifndef ACTIONS_H
#define ACTIONS_H

#include <ESP32Servo.h>
#include <Wire.h>

#include "pwm_servo.h"

Servo s1, s2, s3, s4;

//   servo number sequence:  in pwm_servo.h, servo starts from 0
//   1 servo         2 servo
//   3 servo         4 servo

//   angle:
//   ------------------------> this is forward
//   5 ------  O  ------ 1
//          /  |  \
//         /   |   \
//        /    |    \
//       4     |     2
//             3

// 4 is back 45 degrees
// 2 is up 45 degrees

// 2 is called "up" in code
// 4 is called "back" in code

#define STOP_GAP 50

void s1_1() {
  pwm_servo_set(0, 0);
}

void s1_up() {
  pwm_servo_set(0, 45);
}

void s1_down() {
  pwm_servo_set(0, 90);
}

void s1_back() {
  pwm_servo_set(0, 145);
}

void s1_5() {
  pwm_servo_set(0, 180);
}

void s2_1() {
  pwm_servo_set(1, 180);
}

void s2_up() {
  pwm_servo_set(1, 135);
}

void s2_down() {
  pwm_servo_set(1, 90);
}

void s2_back() {
  pwm_servo_set(1, 45);
}

void s2_5() {
  pwm_servo_set(1, 0);
}

void s3_1() {
  pwm_servo_set(2, 180);
}

void s3_up() {
  pwm_servo_set(2, 135);
}

void s3_down() {
  pwm_servo_set(2, 90);
}

void s3_back() {
  pwm_servo_set(2, 45);
}

void s3_5() {
  pwm_servo_set(2, 0);
}

void s4_1() {
  pwm_servo_set(3, 0);
}

void s4_up() {
  pwm_servo_set(3, 45);
}

void s4_down() {
  pwm_servo_set(3, 90);
}

void s4_back() {
  pwm_servo_set(3, 135);
}

void s4_5() {
  pwm_servo_set(3, 180);
}

// void initServo()
// {
//     s1.attach(18);
//     s2.attach(17);
//     s3.attach(26);
//     s4.attach(27);
// }

void forward() {
    s1_up();
    s3_up();
    delay(STOP_GAP);
    s2_back();
    s4_back();
    delay(STOP_GAP);
    s1_down();
    s3_down();
    delay(STOP_GAP);
    s2_down();
    s4_down();
    delay(STOP_GAP);

    s2_up();
    s4_up();
    delay(STOP_GAP);
    s1_back();
    s3_back();
    delay(STOP_GAP);
    s2_down();
    s4_down();
    delay(STOP_GAP);
    s1_down();
    s3_down();
    delay(STOP_GAP);
}

void backward() {
    s1_back();
    s3_back();
    delay(STOP_GAP);
    s2_up();
    s4_up();
    delay(STOP_GAP);
    s1_down();
    s3_down();
    delay(STOP_GAP);
    s2_down();
    s4_down();
    delay(STOP_GAP);

    s2_back();
    s4_back();
    delay(STOP_GAP);
    s1_up();
    s3_up();
    delay(STOP_GAP);
    s2_down();
    s4_down();
    delay(STOP_GAP);
    s1_down();
    s3_down();
    delay(STOP_GAP);

}

void stand_up() {
    s1_down();
    s2_down();
    s3_down();
    s4_down();
}

void sit_down() {
    s1_1();
    s2_1();
    s3_5();
    s4_5();
}

void left_front_hand_up() {
    s1_1();
}

void right_front_hand_up() {
    s2_1();
}

void dance() {
  s1_up();
  s2_up();
  s3_up();
  s4_up();
  delay(STOP_GAP * 3);
  s1_down();
  s2_down();
  s3_down();
  s4_down();
  delay(STOP_GAP * 3);
  s1_back();
  s2_back();
  s3_back();
  s4_back();
  delay(STOP_GAP * 3);
  s1_down();
  s2_down();
  s3_down();
  s4_down();
  delay(STOP_GAP * 3);
}

void dance2()
{
  s1_1();
  s3_1();
  delay(STOP_GAP * 5);
  s1_down();
  s3_down();
  delay(STOP_GAP * 5);
  s1_5();
  s3_5();
  delay(STOP_GAP * 5);
  s1_down();
  s3_down();
  delay(STOP_GAP * 5);

  s2_1();
  s4_1();
  delay(STOP_GAP * 5);
  s2_down();
  s4_down();
  delay(STOP_GAP * 5);
  s2_5();
  s4_5();
  delay(STOP_GAP * 5);
  s2_down();
  s4_down();
  delay(STOP_GAP * 5);

}

#endif