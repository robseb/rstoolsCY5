/**
 * @file    main.cpp
 * @brief   FPGA-status
 * @author  Robin Sebastian (https://github.com/robseb) (git@robseb.de)
 * @mainpage
 * rstools application to read the Status of the FPGA Fabric
 * with FPGA Manager
 */

#include <cstdio>
#include "alt_fpga_manager.h"
#include "hps.h"
#include <string.h>
#include <fstream>
#include <iostream>
using namespace std;

#pragma region convert to string 

string std2str(ALT_FPGA_STATE_t std)
{
	switch (std)
	{
	case ALT_FPGA_STATE_POWER_UP:
		return "FPGA POWER UP STATE\n"\
			"	FPGA is in Power Up Phase. This is the state of the FPGA just after\n"\
			"	powering up";

	case ALT_FPGA_STATE_RESET:
		return "FPGA RESET STATE\n"\
			"	FPGA is in Reset Phase. In this phase, the FPGA resets, clears the FPGA\n"\
			"	configuration RAM bits, tri-states all FPGA user I/O pins, pulls the\n"\
			"	nSTATUS and CONF_DONE pins low, and determines the configuration mode\n"\
			"	by reading the value of the MSEL pins.";

	case ALT_FPGA_STATE_CFG:
		return "FPGA CONFIGURATION STATE\n"\
			"	FPGA is in Configuration Phase. This state represents the phase when the\n"\
			"	configuration bitstream is loaded into the FPGA fabric. The\n"\
			"	configuration phase is complete after the FPGA has received all the\n"\
			"	configuration data.";

	case ALT_FPGA_STATE_INIT:
		return "FPGA INITIALIZATION STATE\n"\
			"	FPGA is in Initialization Phase. In this state the FPGA prepares to enter\n"\
			"	User Mode. In Configuration via PCI Express (CVP), this state indicates\n"\
			"	I/O configuration has completed";

	case ALT_FPGA_STATE_USER_MODE:
		return "FPGA USER MODE STATE\n"\
			"	FPGA is in the User Mode State. In this state, the FPGA performs the\n"\
			"	function loaded during the configuration phase. The FPGA user \n"\
			"	I/O are functional as determined at design time.";

	case ALT_FPGA_STATE_UNKNOWN:
		return "ERROR: FPGA State unknown";

	default:
		return "ERROR: FPGA State unknown";
	}
}
#pragma endregion

int main(int argc, const char* argv[])
{

	///////// init the Virtual Memory for I/O access /////////
	__VIRTUALMEM_SPACE_INIT();


	/////////	 init the FPGA Manager	 /////////
	alt_fpga_init();

	///////// Take the right to controll the FPGA /////////
	alt_fpga_control_enable();

	///////// read the status of the FPGA		/////////
	ALT_FPGA_STATE_t stat = alt_fpga_state_get();

	if ((argc > 1) && (std::string(argv[1]) == "-h"))
	{
		cout << "	Command to read current Status mode of the FPGA fabric" << endl;
		cout << "	FPGA-status" << endl;
		cout << "		read the status with detailed output" << endl;
		cout << "	FPGA-status -d" << endl;
		cout << "		POWER UP:	 0" << endl;
		cout << "		RESET:		 1" << endl;
		cout << "		CONFIG:		 2" << endl;
		cout << "		INIT:		 3" << endl;
		cout << "		USER:		 4" << endl;
		cout << "		UNKNOWN:	 5" << endl;
	}
	else if ((argc > 1) && (std::string(argv[1]) == "-d"))
		// Print only the Status Code 
		cout << stat;
	else
	{
		// Print the MSEL Value as detailed string 
		cout << "-- Read the current Status of the FPGA fabric  --" << endl;
		cout << "   Status of the FPGA: "  << std2str(stat) << endl;
	}

	// Give the right to controll the FPGA
	alt_fpga_control_disable();

	// free the dynamic access memory
	__VIRTUALMEM_SPACE_DEINIT();

	return 0;
}
