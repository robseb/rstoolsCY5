/**
 * @file    main.cpp
 * @brief	FPGA-gpiRead
 * @author  Robin Sebastian (https://github.com/robseb) (git@robseb.de)
 * @mainpage
 * rstools application to read the general purpose input line 
 * from the FPGA 
 */

#include <cstdio>
#include "alt_fpga_manager.h"
#include "hps.h"
#include <string.h>
#include <fstream>
#include <iostream>
#include <bitset>
using namespace std;

#define CHECK_BIT(var,pos) ((var) & (1<<(pos)))


int main(int argc, const char* argv[])
{
	///////// init the Virtual Memory for I/O access /////////
	__VIRTUALMEM_SPACE_INIT();

	/////////	 init the FPGA Manager	 /////////
	alt_fpga_init();

	// Take the right to controll the FPGA
	alt_fpga_control_enable();

	/////////  read the GPI register /////////
	uint32_t gpi = 0;

	if (alt_fpga_state_get() == ALT_FPGA_STATE_USER_MODE)
		gpi = alt_fpga_gpi_read(0xFFFFFFFF);

	if ((argc > 1) && (std::string(argv[1]) == "-h"))
	{
		cout << "	Command to read general-purpose input signals (gpi) from " << endl;
		cout << "	the FPGA fabric " << endl;
		cout << "	The FPGA can set the 32 Bit gpi (input) register" << endl;
		cout << "	FPGA-gpiRead" << endl;
		cout << "		read gpi with detailed output" << endl;
		cout << "	FPGA-gpiRead -d" << endl;
		cout << "		read gpi as decimal value" << endl;
	}

	else if ((argc > 1) && (std::string(argv[1]) == "-d")) 
			cout << gpi;
	else
	{
		// Print the MSEL Value as detailed string 
		cout << "-- Reading of the general purpose FPGA Input Registers (gpi) --" << endl;

		if (alt_fpga_state_get() != ALT_FPGA_STATE_USER_MODE)
			cout << "	ERROR: failed to read! FPGA is not in the USER State!" << endl;
		else
		{
			cout << "	gpi Register: " << gpi <<"  0x"<< hex <<gpi<<dec<< endl;


			for (int i = 0; i < 32; i++)
			{
				cout << "	gpi[" << ((i < 10) ? " " : "") <<i<< "] = ";
				cout << ((gpi & (1 << i)) ? 1 : 0) << endl;
			}
		}
	}

	// Give the right to controll the FPGA
	alt_fpga_control_disable();

	// free the dynamic access memory
	__VIRTUALMEM_SPACE_DEINIT();

	return 0;
}
