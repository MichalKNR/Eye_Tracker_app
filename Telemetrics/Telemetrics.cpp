#include "Telemetrics.h"

using namespace Telemetrics;

Telemetry::Telemetry(){

}

Telemetry::Telemetry(ET_Connection::Connector* connector) : connector(connector){

}

void Telemetry::send_telemetry(double current, double battery_voltage){
    send_current(current);
    send_battery_voltage(battery_voltage);
}

void Telemetry::send_current(double current){

}

void Telemetry::send_battery_voltage(double battery_voltage){

}
