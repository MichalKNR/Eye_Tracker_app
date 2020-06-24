#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <iostream>

#define DEFAULT_PORT 2020
#define BUFFER_SIZE 256
#define DEFUALT_TIMEOUT 5

namespace ET_Connection{

enum connection_result{
    connected_successfully,
    failed_to_connect,
    timeout
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
    void error(const char *message);
public:
    Connector();

    ~Connector();

    connection_result open_connection(int port_number, int timeout_sec = DEFUALT_TIMEOUT);

    void send_data(frame frame);

    bool is_data_availible();

    int receive_data(char* data);

    void terminate_all_connections();
};
}
