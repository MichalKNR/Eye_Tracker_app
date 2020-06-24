#include <iostream>
#include "Connector.h"
#include "Keyboard.h"

namespace Control {

const short default_axis_1_key_up = KEY_LEFT;
const short default_axis_1_key_down = KEY_RIGHT;

const short default_axis_2_key_up = KEY_UP;
const short default_axis_2_key_down = KEY_DOWN;

const short default_axis_3_key_up = KEY_Q;
const short default_axis_3_key_down = KEY_E;

const short default_movement_left_key = KEY_A;
const short default_movement_right_key = KEY_D;
const short default_movement_forward_key = KEY_W;
const short default_movement_backward_key = KEY_S;

const short movement_stop = 0;
const short movement_forward = 1;
const short movement_backward = 2;
const short movement_left = 4;
const short movement_right = 8;
const short movement_left_forward = 5;
const short movement_right_forward = 9;
const short movement_left_backward = 6;
const short movement_right_backward = 10;

const char control_frame_character = '!';
const int movement_frame_size = 3;

struct movement_control{
    int right;
    int left;
};

struct manipulator_control{
    int axis_1;
    int axis_2;
    int axis_3;
};

class Controler{

public:
    short movement_left_key = default_movement_left_key;
    short movement_right_key = default_movement_right_key;
    short movement_forward_key = default_movement_forward_key;
    short movement_backward_key = default_movement_backward_key;

    short axis_1_key_up = default_axis_1_key_up;
    short axis_1_key_down = default_axis_1_key_down;
    short axis_2_key_up = default_axis_2_key_up;
    short axis_2_key_down = default_axis_2_key_down;
    short axis_3_key_up = default_axis_3_key_up;
    short axis_3_key_down = default_axis_3_key_down;
private:
    ET_Connection::Connector* connector;
    Keyboard_State keyboard;

    void calculate_movement_control(movement_control* controls, short keys);
    void send_robot_movement_frame(movement_control controls);
public:
    Controler();
    Controler(ET_Connection::Connector* connector);

    ~Controler();

    void Control();

};

}
