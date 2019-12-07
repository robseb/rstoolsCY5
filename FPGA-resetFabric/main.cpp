/**
 * @file    main.cpp
 * @brief	FPGA-resetFabric
 * @author  Robin Sebastian (https://github.com/robseb)
 * @mainpage
 * rstools application to delate the FPGA Fabric configuration
 * with FPGA Manager
 */

#include <cstdio>
#include "alt_fpga_manager.h"
#include "hps.h"
#include <string.h>
#include <fstream>
#include <iostream>
using namespace std;

int main(int argc, const char* argv[])
{
	///////// init the Virtual Memory for I/O access /////////
	__VIRTUALMEM_SPACE_INIT();

	/////////	 init the FPGA Manager	 /////////
	alt_fpga_init();

	// Take the right to controll the FPGA
	alt_fpga_control_enable();

	if ((argc > 1) && (std::string(argv[1]) == "-d"))
	{
		// Reset the FPGA Configuration
		alt_fpga_reset_assert();
		if (alt_fpga_state_get() != ALT_FPGA_STATE_RESET)
			cout << 0;
		else
			cout << 1;
	}
	else if ((argc > 1) && (std::string(argv[1]) == "-r"))
	{
		// Reset the FPGA Configuration with responce 
		alt_fpga_reset_assert();

		// Check the new status of the FPGA 
		if (alt_fpga_state_get() != ALT_FPGA_STATE_RESET)
			cout << "	ERROR: Resting of the FPGA failed!" << endl;
		else
			cout << "	Success: FPGA config is deleted" << endl;
	}
	else
	{
		cout << "	Command to reset the FPGA fabic" << endl;
		cout << "	A reset clears the current configuration" << endl;
		cout << "	of the FPGA fabric" << endl;
		cout << "	After a reset is the FPGA in the RESET Mode" << endl;
		cout << "	FPGA-resetFabric -r" << endl;
		cout << "		reset the FPGA with detailed output" << endl;
		cout << "	FPGA-status -d" << endl;
		cout << "		read the status as decimal value" << endl;
		cout << "		0 => ERROR: Resting of the FPGA failed!" << endl;
		cout << "		1 => Success: FPGA config is deleted" << endl;
	}

	// Give the right to controll the FPGA
	alt_fpga_control_disable();

	return 0;
}