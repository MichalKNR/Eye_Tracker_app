#include "Control.h"

using namespace Control;

Controler::Controler(){

}

Controler::Controler(ET_Connection::Connector* connector) : connector(connector){

}

Controler::~Controler(){

}

void Controler::async_remote_control(void){

}

void Controler::Control(){
    bool forward_key_pressed = keyboard.getKeyState(movement_forward_key);
    bool backward_key_pressed = keyboard.getKeyState(movement_backward_key);
    bool left_key_pressed = keyboard.getKeyState(movement_left_key);
    bool right_key_pressed = keyboard.getKeyState(movement_right_key);

    /* shift values bitwise to use them as one variable
     * order of shift
     * b0 - forward
     * b1 - backward
     * b2 - left
     * b3 - right
     */

    short keys = forward_key_pressed         |
                     (backward_key_pressed << 1) |
                     (left_key_pressed << 2)     |
                     (right_key_pressed << 3);

    movement_control controls;
    calculate_movement_control(&controls, keys);
    send_robot_movement_frame(controls);
}

void Controler::calculate_movement_control(movement_control* controls, short keys){
    switch (keys) {
    case movement_forward:
        controls->left = 100;
        controls->right = 100;
        break;
    case movement_backward:
        controls->left = -100;
        controls->right = -100;
        break;
    case movement_left:
        controls->left = -100;
        controls->right = 100;
        break;
    case movement_right:
        controls->left = 100;
        controls->right = -100;
        break;
    case movement_left_forward:
        controls->left = 20;
        controls->right = 100;
        break;
    case movement_right_forward:
        controls->left = 100;
        controls->right = 20;
        break;
    case movement_left_backward:
        controls->left = -20;
        controls->right = -100;
        break;
    case movement_right_backward:
        controls->left = -100;
        controls->right = -20;
        break;
    case movement_stop:
        controls->left = 0;
        controls->right = 0;
        break;
    default:
        controls->left = 0;
        controls->right = 0;
        break;
    }
}

void Controler::send_robot_movement_frame(movement_control controls){
    ET_Connection::frame control_frame;
    control_frame.data[0] = ET_Connection::control_frame_character;
    control_frame.data[1] = 'W'/*controls.left*/;
    control_frame.data[2] = 'W'/*controls.right*/;
    control_frame.size = movement_frame_size;

    connector->send_data(control_frame);
}
