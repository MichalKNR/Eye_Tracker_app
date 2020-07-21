#include <stdlib.h>
#include <string>
#include <wiringPi.h>

namespace Control {

const int motor_left_direction_1_pin = 22;
const int motor_left_direction_2_pin = 24;

const int motor_right_direction_1_pin = 26;
const int motor_right_direction_2_pin = 28;

const int motor_left_PWM_pin = 32;
const int motor_right_PWM_pin = 33;

const int pwm_range_multiplier = 10;

class Robot{
private:
    void set_direction_forward();
    void set_direction_backward();
    void set_direction_left();
    void set_direction_right();
    void move(int speed_left, int speed_right);

public:
    Robot();
    void Control(char* frame);
};

}
