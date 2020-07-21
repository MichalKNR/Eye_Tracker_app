#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <netdb.h>
#include <iostream>

#ifndef CONNECTOR_LIB
#define CONNECTOR_LIB

#define DEFAULT_PORT 2020
#define BUFFER_SIZE 256
#define DEFUALT_TIMEOUT 5

namespace ET_Connection{

const char control_frame_character = '!';
const char telemetrics_frame_character = '@';

enum connection_result{
    connected_successfully,
    failed_to_connect,
    timeout
};

enum frame_type{
    control,
    telemetrics,
};

struct frame
{
    char data[BUFFER_SIZE];
    int size;
};

class Connector{

public:
private:
    char rx_buffer[BUFFER_SIZE];
    char tx_buffer[BUFFER_SIZE];
    int port;
    int own_socket;
    int client_socket;
    struct sockaddr_in address;
    struct sockaddr_in client_address;
    struct hostent *server;
    struct sockaddr_in server_address;
    void error(const char *message);
public:
    Connector();

    ~Connector();

    connection_result open_connection(int port_number, int timeout_sec = DEFUALT_TIMEOUT);

    connection_result connect_to_server(char *host_name, int server_port);

    frame_type analyze_frame_type(char first_argument);

    void send_data(frame frame);

    bool is_data_availible();

    int receive_data(char* data);

    void terminate_all_connections();
};
}

#endif
