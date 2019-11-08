#include "every_command.h"
int every_command::serial_command=0;
int every_command::serial_command_memory = 0;
bool every_command::if_serial_command_change()
{
	bool if_change = false;
	if_change=(every_command::serial_command != every_command::serial_command_memory) ? true : false;
	every_command::serial_command_memory = (if_change == true) ? every_command::serial_command : every_command::serial_command_memory;
	return if_change;
}
