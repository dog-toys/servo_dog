#ifndef ACTION_PWM_H
#define ACTION_PWM_H

#include <Arduino.h>
#include <Adafruit_PWMServoDriver.h>

// 参考
// https://blog.csdn.net/weixin_43453553/article/details/103811498

// 舵机的最小和最大脉冲长度（这些值可能需要根据你的舵机进行调整）
// 控制程序
// 舵机的控制一般需要一个20ms的时基脉冲，该脉冲的高电平部分一般为0.5ms~2.5ms范围内的角度控制脉冲部分。以180度角度舵机为例，那么对应的控制关系是这样的：
// 0.5ms————–0度；
// 1.0ms————45度；
// 1.5ms————90度；
// 2.0ms———–135度；
// 2.5ms———–180度；

// 204096 约等于 4096 * 50
// PCA9685可以设置更新频率，时基脉冲周期20ms相当于50HZ更新频率。PCA9685采用12位的寄存器来控制PWM占比，对于0.5ms，相当于0.5/204096=102的寄存器值。以此类推如下：
// 0.5ms————–0度：0.5/204096 = 102
// 1.0ms————45度：1/204096 = 204
// 1.5ms————90度：1.5/204096 = 306
// 2.0ms———–135度：2/204096 = 408
// 2.5ms———–180度：2.5/204096 =510

// 但是实际使用的时候，还是有偏差，除了0度以及180度，其他需要乘以0.915系数。最后的寄存器值如下：
// 0.5ms————–0度：0.5/204096 = 102
// 1.0ms————45度：1/204096 = 204 * 0.915 = 187
// 1.5ms————90度：1.5/204096 = 306 * 0.915 = 280
// 2.0ms———–135度：2/204096 = 408 * 0.915 = 373
// 2.5ms———–180度：2.5/20*4096 =510

uint16_t SERVOMIN = 102;
uint16_t SERVOMAX = 510;
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

int angle2pwm(int angle) {
    int res = map(angle, 0, 180, SERVOMIN, SERVOMAX);
    return res;
}

void pwm_servo_init() {
    pwm.begin();
    pwm.setPWMFreq(50);  // 设置PWM频率为50Hz
}

void pwm_servo_set(int channel, int angle) {
    pwm.setPWM(channel, 0, angle2pwm(angle));
}

#endif