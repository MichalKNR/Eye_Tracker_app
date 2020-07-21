#include <iostream>
#include "Control.h"
#include "Telemetrics.h"
#include "Robot.h"

static int data_port = DEFAULT_PORT;
static bool is_server = true;
static char* server_name;
static char buffer[BUFFER_SIZE]; // TODO use Control Module data member

void validate_input_arguments(int argc, char *argv[]);

int main(int argc, char *argv[])
{
    validate_input_arguments(argc, argv);

    ET_Connection::Connector* connector = new ET_Connection::Connector();
    if(is_server){
        connector->open_connection(data_port);
    } else {
        connector->connect_to_server(server_name, data_port);
    }
    Control::Controler* main_control_unit = new Control::Controler(connector);
    Telemetrics::Telemetry* telemetry = new Telemetrics::Telemetry(connector);
    Control::Robot* robot;

    if(is_server){
        std::cout<<"use wsad to control"<<std::endl;
    } else{
        robot = new Control::Robot();
    }

    while(1){
        //reading should be asynchronous
        usleep(50000); //sleep for 50ms
        int size = connector->receive_data(buffer);

        if(is_server){
            main_control_unit->Control();
        } else {
            robot->Control(buffer);
        }

    }
     return 0;
}

void validate_input_arguments(int argc, char *argv[]){
    if(argc <= 1){
        std::cout<<"no arguments provided, please provide:\n\r - port number as integer\n\r - app type: server or client\n\r"
                   " - optional for client type: server machine name\n\r"
                   "Correct: eye_tracker app <data_port_number> <client/server> <server machine name if client type>"<<std::endl;
        exit(-1);
    }

    try{
        data_port = atoi(argv[1]);
    }
    catch(error_t error){
        std::cout<<"wrong data input, port should be integer"<<std::endl;
        exit(-1);
    }

    if(argc < 3){
        std::cout<<"no app type provided, please provide:\n\r - port number as integer\n\r - app type: server or client\n\r"
                   " - optional for client type: server machine name\n\r"
                   "Correct: eye_tracker app <data_port_number> <client/server> <server machine name if client type>"<<std::endl;
        exit(-1);
    } else{
        if(strcmp(argv[2], "server") == 0){
            is_server = true;
        } else if (strcmp(argv[2], "client") == 0){
            is_server = false;
        } else{
            std::cout<<"wrong app type provided, please provide:\n\r - port number as integer\n\r - app type: server or client\n\r"
                       " - optional for client type: server machine name\n\r"
                       "Correct: eye_tracker app <data_port_number> <client/server> <server machine name if client type>"<<std::endl;
            exit(-1);
        }
    }

    if(!is_server){
        if(argc < 4){
            std::cout<<"no server machine name provided, please provide:\n\r - port number as integer\n\r - app type: server or client\n\r"
                       " - optional for client type: server machine name\n\r"
                       "Correct: eye_tracker app <data_port_number> <client/server> <server machine name if client type>"<<std::endl;
        } else {
            server_name = argv[3];
        }
    }
}
