#include <stdlib.h>
#include <string>

const std::string motor_left_direction_1_path;
const std::string motor_left_direction_2_path;

const std::string motor_right_direction_1_path;
const std::string motor_right_direction_2_path;

const std::string motor_left_PWM_path;
const std::string motor_right_PWM_path;

namespace Control {

class Robot{
private:

public:
    Robot();
    void Control(char* frame);
};

}
