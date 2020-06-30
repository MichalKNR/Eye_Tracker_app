#include "Connector.h"

namespace Telemetrics {

class Telemetry{

public:
private:
    ET_Connection::Connector* connector;

    void send_current(double current);
    void send_battery_voltage(double battery_voltage);
public:
    Telemetry();
    Telemetry(ET_Connection::Connector* connector);

    void send_telemetry(double current, double battery_voltage);
};

}
