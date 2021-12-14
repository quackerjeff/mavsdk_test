#include <iostream>
#include "generic_port.h"
#include "serial_port.h"

int main()
{
#ifdef __APPLE__
	char uart_name[] = "/dev/tty.usbmodem01";
#else
	char uart_name[] = "/dev/ttyUSB0";
#endif

	Generic_Port* port = new Serial_Port(uart_name, 57600);

	try {
		port->start();
	}
	catch (int error) {
		std::cerr << "Could not start port" << std::endl;
		return error;
	}
	mavlink_message_t message;
	while (!port->read_message(message))
	{
		std::cout << "Could not read message" << std::endl;
	}

	std::cout << "Read message" << std::endl;

	port->stop();
	delete port;
	return 0;
}
