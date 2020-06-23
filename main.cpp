#include <iostream>
#include "Connector.h"

int main(int argc, char *argv[])
{
    int port = DEFAULT_PORT;
    ET_Connection::Connector* connector = new ET_Connection::Connector();
    if (argc == 0){
        std::cout<<"no port number provided, using default port 2020"<<std::endl;
    } else {
       port = atoi(argv[0]);
    }
    connector->open_connection(port);
    char buffer[BUFFER_SIZE]; // TODO use Control Module data member
    while(1){
        connector->receive_data(buffer);
        printf("received data: %s\n", buffer);
        //TODO do control based on data
        bzero(buffer, BUFFER_SIZE);
    }
     return 0;
}
