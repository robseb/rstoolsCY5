/**
 * @file    main.cpp
 * @brief	FPGA-readBridge
 * @author  Robin Sebastian (https://github.com/robseb) (git@robseb.de)
 * @mainpage
 * rstools application to read any HSP-to-FPGA Bridges or the MPU address space
 * address
 */

#include <cstdio>
#include "hps.h"
#include <string.h>
#include <fstream>
#include <iostream>
#include <unistd.h>
#include <sstream>
#include <thread>					// Required for putting task to sleep 
#include <chrono>					// Required for putting task to sleep 

using namespace std;

// Bridge Interfaces Base addresses 
#define LWHPSFPGA_OFST  0xff200000 // LWHPS2FPGA Bridge 
#define HPSFPGA_OFST    0xC0000000 // HPS2FPGA Bridge 
#define MPU_OFSET		0x0        // MPU (HPS Address space)

// Bridge interface End address 
#define LWHPSFPGA_END   0xFF3FFFFF
#define HPSFPGA_END     0xFBFFFFFF
#define MPU_END         0xFFFFFFFF

// Bridge interface range (allowed input offset)
#define LWH2F_RANGE    (LWHPSFPGA_END - LWHPSFPGA_OFST)
#define H2F_RANGE      (HPSFPGA_END - HPSFPGA_OFST)
#define MPU_RANGE      (MPU_END - MPU_OFSET)

#define MAP_SIZE 4096UL
#define MAP_MASK (MAP_SIZE - 1)

// Auto refresh Mode settings
#define REFRECHMODE_DELAY_MS	50
#define REFRECHMODE_DURATION_MS 15000
#define REFRECHMODE_MAX_COUNT   (REFRECHMODE_DURATION_MS/REFRECHMODE_DELAY_MS)

bool checkIfInputIsVailed(string input, bool DecHex)
{
	if (input.length() < 1) return false;
	uint16_t i = 0;
	// remove suffix "0x"
	if ((input.find_first_of("0x",0) == 0) && (!DecHex))
	{
		input.replace(0, 2, "");
	}

	for (i = 0; i < input.length(); i++)
	{
		if (i != input.find_first_of(DecHex ? "0123456789" : "0123456789abcdefABCDEF", i)) break;
	}
	if (i == input.length()) return true;

	return false;
}

int main(int argc, const char* argv[])
{
	// Read a Register of the light Lightweight or AXI HPS to FPGA Interface
	if (((argc >2) && (std::string(argv[1]) == "-lw")) || ((argc > 2) && (std::string(argv[1]) == "-hf")) \
		|| ((argc > 2) && (std::string(argv[1]) == "-mpu")))
	{
		// Read the selected Bridge Interface 
		uint8_t address_space = 0; // 0: HPS2FPGA | 1: LWHPS2FPGA | 2: MPU
		bool lwBdrige = false;

		if (std::string(argv[1]) == "-lw") 
		{
			address_space = 1;
			lwBdrige = true;
		}
		else  if(std::string(argv[1]) == "-mpu")
		    address_space = 2;

		bool ConsloeOutput = true;
		bool refreshMode = false;
		string ValueString;

		// check if only decimal output is enabled 
		if ((argc > 3) && (std::string(argv[3]) == "-b"))
			ConsloeOutput = false;

		// Check if the refreshMode was enabled
		if ((argc > 3) && (std::string(argv[3]) == "-r"))
			refreshMode = true;

		/// Check the user inputs ///
		string AddresshexString = argv[2];
		uint32_t addressOffset = 0;

		// check if the address hex input is vailed
		bool InputVailed = true;
		if (checkIfInputIsVailed(AddresshexString, false))
		{
			istringstream buffer(AddresshexString);
			buffer >> hex >> addressOffset;

			// HPS2FPGA
			if (address_space == 0)
			{
				// check the range of the AXI HPS-to-FPGA Bridge Interface 
				if (addressOffset > H2F_RANGE)
				{
					if (ConsloeOutput)
						cout << "	ERROR: selected address is outside of the HPS to "\
						"FPGA AXI Bridge range!" << endl;
					InputVailed = false;
				}
			}
			// LWHPS2FPGA
			else if (address_space==1)
			{
				// check the range of the Lightweight HPS-to-FPGA Bridge Interface 
				if (addressOffset > LWH2F_RANGE)
				{
					if (ConsloeOutput)
						cout << "	ERROR: selected address is outside of"\
						"the Lightweight HPS-to-FPGA Bridge range!" << endl;
					InputVailed = false;
				}
			}
			// MPU
			else
			{
				// check the range of the MPU address space
				if (addressOffset > MPU_RANGE)
				{
					if (ConsloeOutput)
						cout << "	ERROR: selected address is outside MPU (HPS) address range!" << endl;
					InputVailed = false;
				}
			}
		}
		else
		{
			// address input is not vadid
			if (ConsloeOutput)
				cout << "	ERROR: selected address input is no hex address!" << endl;
			InputVailed = false;
		}
		uint32_t address;
		if (address_space < 2)
			address = (lwBdrige ? LWHPSFPGA_OFST : HPSFPGA_OFST) + addressOffset;
		else
			address = addressOffset;

		// only in case the input is valid read the bridge
		if (InputVailed)
		{
			if (ConsloeOutput)
			{
				if (address_space < 2)
				{
					cout << "	------- Read a FPGA Register via a HPS-to-FPGA Bridge -------" << endl;
					cout << "	Bridge:      " << (lwBdrige ? "Lightweight HPS-to-FPGA" : "HPS-to-FPGA") << endl;
					cout << "	Brige Base:  0x" << hex << (lwBdrige ? LWHPSFPGA_OFST : HPSFPGA_OFST) << dec << endl;
					cout << "	Your Offset: 0x" << hex << addressOffset << dec << endl;
					cout << "	Address:     0x" << hex << address << dec << endl;
				}
				else 
				{
					cout << "	-------     Read MPU (HPS) memory address register  -------" << endl;
					cout << "	Address:     0x" << hex << address << dec << endl;
				}
			}
			do
			{
				void* bridgeMap;
				int fd;

				// open memory driver 
				fd = open("/dev/mem", (O_RDWR | O_SYNC));

				// was opening okay
				if (fd < 0)
				{
					if (ConsloeOutput)
						cout << "ERROR: Failed to open memory driver!" << endl;
					else
						cout << 0;
					break;
				}

				bridgeMap = mmap(NULL, MAP_SIZE, PROT_READ, MAP_SHARED, fd, \
						address & ~MAP_MASK);
				// check if opening was successfully
				if (bridgeMap == MAP_FAILED)
				{
					if (ConsloeOutput)
						cout << "ERROR: Accessing the virtual memory failed!" << endl;
					else
						cout << 0;
					close(fd);
					break;
				}
				void* readMap = bridgeMap + (address & MAP_MASK);
				uint16_t delay_count = 0;
				do
				{
					// Read the address 
					uint32_t value = *((uint32_t*)readMap);

					if (ConsloeOutput)
					{
						cout << "-------------------------------------------------------------------------------------" << endl;
						cout << "			      Value: " << value << " [0x" << hex << value << "]" << dec << endl;
						cout << "-------------------------------------------------------------------------------------" << endl;
						cout << "No  |";
						for (uint16_t i = 31; i > 15; i--)
						{
							cout << " " << i << " |";
						}
						cout << endl << "Bit |";
						for (uint16_t i = 31; i > 15; i--)
						{
							cout << "  " << (value & (1 << i) ? 1 : 0) << " |";
						}
						cout << endl;
						cout << "-------------------------------------------------------------------------------------" << endl;

						cout << "No  |";
						for (int16_t i = 15; i >= 0; i--)
						{
							if (i > 9)
								cout << " " << i << " |";
							else
								cout << " 0" << i << " |";
						}
						cout << endl << "Bit |";
						for (int16_t i = 15; i >= 0; i--)
						{
							cout << "  " << (value & (1 << i) ? 1 : 0) << " |";
						}
						cout << endl;
						cout << "-------------------------------------------------------------------------------------" << endl;
					}
					else
					{
						// output only the value as decimal 
						cout << value;
					}

					if (!refreshMode)
						break;
					else
					{
						delay_count++;
						// Print the refrech status
						cout << "Auto Refrech Mode for " << REFRECHMODE_DURATION_MS << "ms [" << delay_count << \
							"/" << REFRECHMODE_MAX_COUNT << "]" << endl;

						// C++11: Put this task to sleep 
						std::this_thread::sleep_until(std::chrono::system_clock::now() + \
							std::chrono::milliseconds(REFRECHMODE_DELAY_MS));
						// Remove the last 10 rows 
						if (delay_count < REFRECHMODE_MAX_COUNT)
							cout << "\033[F\033[F\033[F\033[F\033[F\033[F\033[F\033[F\033[F\033[F";
					}

				} while (delay_count<REFRECHMODE_MAX_COUNT);

				// Close the MAP 
				if (munmap(bridgeMap, MAP_SIZE) < 0)
				{
					if (ConsloeOutput)
						cout << "ERROR: Closing of shared memory failed!" << endl;
				}

				// Close the driver port 
				close(fd);

				if (ConsloeOutput)
					cout << "Reading was successfully" << endl;
				else
					cout << 1;

			} while (0);
		}
		else
		{
			// User input is not okay 
			if (!ConsloeOutput)
				cout << 0;
		}

	}
	else
	{
		// help output 
		cout << "-------------------------------------------------------------------------------------" << endl;
		cout << "|	Command to read a 32-bit register of a HPS-to-FPGA Bridge	         	    |" << endl;			
		cout << "|		or of the entire MPU (HPS) Memory space				    |" << endl;
		cout << "|  Note: Be sure that the bridge to read is enabled within the Platform Designer    |" << endl;
		cout << "-------------------------------------------------------------------------------------" << endl;
		cout << "|$	FPGA-readBridge -lw [offset address in hex]					" << endl;
		cout << "|		read a 32-bit register of the Lightweight HPS-to-FPGA Bridge		" << endl;
		cout << "|		e.g.: FPGA-readBridge -lw 0A							" << endl;
		cout << "|$	FPGA-readBridge -hf [offset address in hex]				" << endl;
		cout << "|		read a 32-bit register of the HPS-to-FPGA AXI Bridge	" << endl;
		cout << "|		e.g.: FPGA-readBridge -hf 8C							" << endl;
		cout << "|$	FPGA-readBridge -mpu [module address in hex]" << endl;
		cout << "|		read a 32-bit register for the entire MPU (HPS) memory space" << endl;
		cout << "|		e.g.: FPGA-readBridge -mpu 87" << endl;
		cout << "|		Suffix: -b -> only decimal result output" << endl;
		cout << "|		Suffix: -r -> Auto refrech the value for 15sec" << endl;
		cout << "|$	FPGA-readBridge -lw|hf|mpu| <offset address in hex> -b|r" << endl;
		cout << "-------------------------------------------------------------------------------------" << endl;

	}

	return 0;
}
