#include <iostream>
#include "Control.h"

int main(int argc, char *argv[])
{
    int port = DEFAULT_PORT;
    ET_Connection::Connector* connector = new ET_Connection::Connector();
    if (argc == 0){
        std::cout<<"no port number provided, using default port 2020"<<std::endl;
    } else {
       //port = atoi(argv[0]);
    }

    connector->open_connection(port);
    Control::Controler* main_control_unit = new Control::Controler(connector);
    std::cout<<"use wsad to control"<<std::endl;
    char buffer[BUFFER_SIZE]; // TODO use Control Module data member
    while(1){
        //reading should be asynchronous
        usleep(50000); //sleep for 50ms
        int size = connector->receive_data(buffer);
        printf("received data: %s\n", buffer);
        //TODO do control based on data
        bzero(buffer, BUFFER_SIZE);

        main_control_unit->Control();
    }
     return 0;
}
