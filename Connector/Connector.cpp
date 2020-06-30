#include "Connector.h"

using namespace ET_Connection;

Connector::Connector(){
    this->own_socket = socket(AF_INET, SOCK_STREAM, 0);
}

Connector::~Connector(){
    terminate_all_connections();
}

connection_result Connector::open_connection(int port_number, int timeout_sec){
    this->address.sin_family = AF_INET;
    this->address.sin_addr.s_addr = INADDR_ANY; //TODO change to address of the current machine
    this->address.sin_port = htons(port_number);
    bind(this->own_socket, (struct sockaddr *) &this->address, sizeof(this->address));
    listen(this->own_socket,5);

    socklen_t client_length = sizeof(this->client_address);
    // TODO make use of the timeout
    this->client_socket = accept(this->own_socket, (struct sockaddr *) &this->client_address, &client_length);
    if (this->client_socket < 0){
         error("ERROR on accept"); // TODO make use of other connection results
    } else{
        std::cout<<"Device successfully connected"<<std::endl;
        return connected_successfully;
    }
}

connection_result Connector::connect_to_server(char* host_name, int server_port){
    server = gethostbyname(host_name);
    own_socket = socket(AF_INET, SOCK_STREAM, 0);
    server_address.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&server_address.sin_addr.s_addr, server->h_length);
    server_address.sin_port = htons(server_port);
    if (connect(own_socket,(struct sockaddr *) &server_address, sizeof(server_address)) < 0){
        error("ERROR connecting to server");
    }

}

frame_type Connector::analyze_frame_type(char first_argument){

}

void Connector::send_data(frame frame){
    int size = write(this->client_socket, frame.data, frame.size);
    if (size < 0){
        error("ERROR writing to socket");
    }
}

bool Connector::is_data_availible(){
    return true; //TODO implementation
}

int Connector::receive_data(char* data){
    bzero(data,256);
    int size = read(this->client_socket, data, 255);
    if (size < 0){
        error("ERROR reading from socket");
    }
    printf("received data: %s\n", data);
    return size;
}

void Connector::terminate_all_connections(){
    close(this->client_socket);
    close(this->own_socket);
}

void Connector::error(const char *message){
    perror(message);
    exit(1);
}
