#include "Connection.h"

Connection::Connection(int _channel) {
    setChannel(_channel);
    setStatus("Connected");
}

Connection::~Connection() {

}

void Connection::setChannel(int _channel) {
    channel = _channel;
}

void Connection::setStatus(string _status) {
    if (_status == "Connected" || _status == "Not connected")
        status = _status;
    else // ERROR
        printf("INVALID VALUE \n");

}

int Connection::getChannel(void) {
    return channel;
}

string Connection::getStauts(void) {
    return status;
}