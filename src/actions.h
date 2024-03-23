#include <ESP32Servo.h>
Servo s1, s2, s3, s4;

//   servo number sequence:
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

void servoAttach()
{
    s1.attach(18);
    s2.attach(17);
    s3.attach(26);
    s4.attach(27);
}

void forward() {
    s1_up();
    s4_up();
    delay(STOP_GAP);
    s2_back();
    s3_back();
    delay(STOP_GAP);
    s1_down();
    s4_down();
    delay(STOP_GAP);
    s2_down();
    s3_down();
    delay(STOP_GAP);

    s2_up();
    s3_up();
    delay(STOP_GAP);
    s1_back();
    s4_back();
    delay(STOP_GAP);
    s2_down();
    s3_down();
    delay(STOP_GAP);
    s1_down();
    s4_down();
    delay(STOP_GAP);
}

void back() {
    s1_back();
    s4_back();
    delay(STOP_GAP);
    s2_up();
    s3_up();
    delay(STOP_GAP);
    s1_down();
    s4_down();
    delay(STOP_GAP);
    s2_down();
    s3_down();
    delay(STOP_GAP);

    s2_back();
    s3_back();
    delay(STOP_GAP);
    s1_up();
    s4_up();
    delay(STOP_GAP);
    s2_down();
    s3_down();
    delay(STOP_GAP);
    s1_down();
    s4_down();
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
