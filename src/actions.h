#ifndef ACTIONS_H
#define ACTIONS_H

#include <Wire.h>

#include "pwm_servo.h"

//   servo number sequence:  in pwm_servo.h, servo starts from 0
//   FL(1) servo          FR(2) servo
//   BL(4) servo          BR(3) servo

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

#define STOP_GAP 100

void FL_1() {
  pwm_servo_set(0, 0);
}

void FL_up() {
  pwm_servo_set(0, 45);
}

void FL_down() {
  pwm_servo_set(0, 90);
}

void FL_back() {
  pwm_servo_set(0, 145);
}

void FL_5() {
  pwm_servo_set(0, 180);
}

void FR_1() {
  pwm_servo_set(1, 180);
}

void FR_up() {
  pwm_servo_set(1, 135);
}

void FR_down() {
  pwm_servo_set(1, 90);
}

void FR_back() {
  pwm_servo_set(1, 45);
}

void FR_5() {
  pwm_servo_set(1, 0);
}

void BR_1() {
  pwm_servo_set(2, 180);
}

void BR_up() {
  pwm_servo_set(2, 135);
}

void BR_down() {
  pwm_servo_set(2, 90);
}

void BR_back() {
  pwm_servo_set(2, 45);
}

void BR_5() {
  pwm_servo_set(2, 0);
}

void BL_1() {
  pwm_servo_set(3, 0);
}

void BL_up() {
  pwm_servo_set(3, 45);
}

void BL_down() {
  pwm_servo_set(3, 90);
}

void BL_back() {
  pwm_servo_set(3, 135);
}

void BL_5() {
  pwm_servo_set(3, 180);
}

// void initServo()
// {
//     FL.attach(18);
//     FR.attach(17);
//     BL.attach(26);
//     BR.attach(27);
// }

void forward() {
    FL_up();
    BR_up();
    delay(STOP_GAP);
    FR_back();
    BL_back();
    delay(STOP_GAP);
    FL_down();
    BR_down();
    delay(STOP_GAP);
    FR_down();
    BL_down();
    delay(STOP_GAP);

    FR_up();
    BL_up();
    delay(STOP_GAP);
    FL_back();
    BR_back();
    delay(STOP_GAP);
    FR_down();
    BL_down();
    delay(STOP_GAP);
    FL_down();
    BR_down();
    delay(STOP_GAP);
}

void backward() {
    FL_back();
    BR_back();
    delay(STOP_GAP);
    FR_up();
    BL_up();
    delay(STOP_GAP);
    FL_down();
    BR_down();
    delay(STOP_GAP);
    FR_down();
    BL_down();
    delay(STOP_GAP);

    FR_back();
    BL_back();
    delay(STOP_GAP);
    FL_up();
    BR_up();
    delay(STOP_GAP);
    FR_down();
    BL_down();
    delay(STOP_GAP);
    FL_down();
    BR_down();
    delay(STOP_GAP);
}

void turn_right() {
    FL_up();
    BR_up();
    delay(STOP_GAP);
    FR_back();
    BL_back();
    delay(STOP_GAP);
    FL_down();
    BR_down();
    delay(STOP_GAP);
    FR_down();
    BL_down();
    delay(STOP_GAP);
}

void stand_up() {
    FL_down();
    FR_down();
    BL_down();
    BR_down();
}

void sit_down() {
    FL_1();
    FR_1();
    BL_5();
    BR_5();
}

void left_front_hand_up() {
    FL_1();
}

void right_front_hand_up() {
    FR_1();
}

void dance() {
  FL_up();
  FR_up();
  BL_up();
  BR_up();
  delay(STOP_GAP * 3);
  FL_down();
  FR_down();
  BL_down();
  BR_down();
  delay(STOP_GAP * 3);
  FL_back();
  FR_back();
  BL_back();
  BR_back();
  delay(STOP_GAP * 3);
  FL_down();
  FR_down();
  BL_down();
  BR_down();
  delay(STOP_GAP * 3);
}

void dance2()
{
  FL_1();
  BL_1();
  delay(STOP_GAP * 5);
  FL_down();
  BL_down();
  delay(STOP_GAP * 5);
  FL_5();
  BL_5();
  delay(STOP_GAP * 5);
  FL_down();
  BL_down();
  delay(STOP_GAP * 5);

  FR_1();
  BR_1();
  delay(STOP_GAP * 5);
  FR_down();
  BR_down();
  delay(STOP_GAP * 5);
  FR_5();
  BR_5();
  delay(STOP_GAP * 5);
  FR_down();
  BR_down();
  delay(STOP_GAP * 5);

}

#endif