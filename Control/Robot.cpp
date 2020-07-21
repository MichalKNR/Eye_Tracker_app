#include "Robot.h"
#include <math.h>
#include "iostream"

using namespace Control;

Robot::Robot(){
    wiringPiSetup();
    pinMode(motor_left_direction_1_pin, OUTPUT);
    pinMode(motor_left_direction_2_pin, OUTPUT);
    pinMode(motor_right_direction_1_pin, OUTPUT);
    pinMode(motor_right_direction_2_pin, OUTPUT);
    pinMode(motor_left_PWM_pin, OUTPUT);
    pinMode(motor_right_PWM_pin, OUTPUT);
}

void Robot::Control(char *frame){
    int speed_left = abs(frame[1]);
    int speed_right= abs(frame[2]);

    if(frame[1] > 0 && frame[2] > 0){
        std::cout<<"move FORWARD"<<std::endl;
        set_direction_forward();
    }
    if(frame[1] < 0 && frame[2] < 0){
        std::cout<<"move BACKWARD"<<std::endl;
        set_direction_backward();
    }
    if(frame[1] > 0 && frame[2] < 0){
        std::cout<<"turn LEFT"<<std::endl;
        set_direction_left();
    }
    if(frame[1] < 0 && frame[2] > 0){
        std::cout<<"turn RIGHT"<<std::endl;
        set_direction_right();
    }
    move(speed_left, speed_right);
}

void Robot::set_direction_forward(){
    digitalWrite(motor_left_direction_1_pin, 1);
    digitalWrite(motor_left_direction_2_pin, 0);

    digitalWrite(motor_right_direction_1_pin, 1);
    digitalWrite(motor_right_direction_2_pin, 0);
}

void Robot::set_direction_backward(){
    digitalWrite(motor_left_direction_1_pin, 0);
    digitalWrite(motor_left_direction_2_pin, 1);

    digitalWrite(motor_right_direction_1_pin, 0);
    digitalWrite(motor_right_direction_2_pin, 1);
}

void Robot::set_direction_left(){
    digitalWrite(motor_left_direction_1_pin, 1);
    digitalWrite(motor_left_direction_2_pin, 0);

    digitalWrite(motor_right_direction_1_pin, 0);
    digitalWrite(motor_right_direction_2_pin, 1);
}

void Robot::set_direction_right(){
    digitalWrite(motor_left_direction_1_pin, 0);
    digitalWrite(motor_left_direction_2_pin, 1);

    digitalWrite(motor_right_direction_1_pin, 1);
    digitalWrite(motor_right_direction_2_pin, 0);
}

void Robot::move(int speed_left, int speed_right){
    pwmWrite(motor_left_PWM_pin, speed_left * pwm_range_multiplier);
    pwmWrite(motor_right_PWM_pin, speed_right * pwm_range_multiplier);
}
