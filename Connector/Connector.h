#include <stdlib.h>
#include <string.h>
#include <vector>

namespace Connection{

enum connection_result{
    connected_successfully,
    failed_to_connect,
    timeout
};

class Connector
{
public:
private:
    std::vector<int> rx_buffer;
    std::vector<int> tx_buffer;
    int port;
public:
    Connector();

    connection_result connect_to_device(struct sockaddr_in address, int timeout_sec);

    void send_data(struct sockaddr_in address, std::vector<int> data);

    bool is_data_availible_from_device(struct sockaddr_in address);

    std::vector<int> receive_data_from_device(struct sockaddr_in address);

    void terminate_connection_with_device(struct sockaddr_in address);

    void terminate_all_connections();
};
}
