/**
 * @file    main.cpp
 * @brief	FPGA-writeBridge 
 * @author  Robin Sebastian (https://github.com/robseb) (git@robseb.de)
 * @mainpage
 * rstools application to write to any HSP-to-FPGA Bridges or the MPU address space
 * address
 */

#include <cstdio>
#include "hps.h"
#include <string.h>
#include <fstream>
#include <iostream>
#include <unistd.h>
#include <sstream>
#include <cstdint>
using namespace std;

#define DEC_INPUT 1
#define HEX_INPUT 0
#define BIN_INPUT 2

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

#pragma region Check user input 
bool checkIfInputIsVailed(string input, bool DecHex)
{
	if (input.length() < 1) return false;
	uint16_t i = 0;

	// remove suffix "0x"
	if ((input.find_first_of("0x", 0) == 0) && (!DecHex))
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
#pragma endregion

int main(int argc, const char* argv[])
{
	// Debugging Test values 
	//argv[1] = "-hf";
	//argv[2] =(const char*) "0"; // Address 
	//argv[3] = (const char*)"123"; // Value
	//argc = 3;

	// Read to the Light Wightweight or AXI HPS to FPGA Interface
	if (((argc > 3) && (std::string(argv[1]) == "-lw")) || ((argc > 3) && (std::string(argv[1]) == "-hf"))|| \
	    ((argc > 3) && (std::string(argv[1]) == "-mpu")))
	{
		// read the selected Bridge Interface 
		bool lwBdrige = false;
		uint8_t address_space = 0; // 0: HPS2FPGA | 1: LWHPS2FPGA | 2: MPU
		if (std::string(argv[1]) == "-lw")
			lwBdrige = true;
		else if (std::string(argv[1]) == "-mpu")
			address_space = 2;

		/// check the value input type (Dec or Hex) ///
		// 1: DEC Value input | 0: HEX Dec Input | 2: Binary Bit Set/Reset 
		int DecHexBin = DEC_INPUT;
		bool ConsloeOutput = true;

		// check the Value input type (dec,hex,bin)
		if ((argc >= 4) && (std::string(argv[3]) == "-h"))
			DecHexBin = HEX_INPUT;

		if ((argc > 4) && (std::string(argv[3]) == "-b"))
			DecHexBin = BIN_INPUT;

		string ValueString;

		switch (DecHexBin)
		{
		case DEC_INPUT:
			if ((argc > 4) && (std::string(argv[4]) == "-b"))
				ConsloeOutput = false;
			ValueString = argv[3];
			break;
		case HEX_INPUT:
			if ((argc > 5) && (std::string(argv[5]) == "-b"))
				ConsloeOutput = false;
			ValueString = argv[4];
			break;
		case BIN_INPUT:
			if ((argc > 6) && (std::string(argv[6]) == "-b"))
				ConsloeOutput = false;
			break;
		default:
			break;
		}

		/// Check the user inputs ///

		string AddresshexString =argv[2];
		uint32_t addressOffset = 0;

		uint32_t ValueInput = 0;
		uint64_t ValueInputTemp = ValueInput;

		uint32_t BitPosValue = 0;
		uint32_t SetResetBit = 0;

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
			else if (address_space == 1)
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
			// address input is not vailed
			if (ConsloeOutput)
				cout << "	ERROR: selected address input is no hex address!" << endl;
			InputVailed = false;
		}

		// only for binary mode: check if the Set or Reset input is vailed //
		if (DecHexBin == BIN_INPUT)
		{
			// read and check the Pos input value
			string SetInputString = argv[5];
			string BitPosString = argv[4];

			// check if the Bit pos value input is okay
			if (checkIfInputIsVailed(BitPosString, true))
			{
				istringstream buffer(BitPosString);
				buffer >> BitPosValue;

				if (BitPosValue < 32)
					InputVailed = true;
			}

			// read and check the Set or Reset input
			if (checkIfInputIsVailed(SetInputString, true))
			{
				istringstream buffer(SetInputString);
				buffer >> SetResetBit;

				if (SetResetBit < 2)
					InputVailed = true;
			}
		}
		else
		{
			// for DEC and HEX
			// check if the address hex input is vailed

			if (checkIfInputIsVailed(ValueString, !(DecHexBin == HEX_INPUT)))
			{
				istringstream buffer(ValueString);

				if (DecHexBin == DEC_INPUT)
					buffer >> dec >> ValueInputTemp;
				else
					buffer >> hex >> ValueInputTemp;

				// value a 32 Bit value 
				if (ValueInputTemp > UINT32_MAX)
				{
					if (ConsloeOutput)
						cout << "	ERROR: selected Value greater the 32 bit" << endl;
					InputVailed = false;
				}

				ValueInput = ValueInputTemp;
			}
			else
			{
				// value input is not vailed
				if (ConsloeOutput)
					cout << "	ERROR: selected value is input is not vailed!" << endl;
				InputVailed = false;
			}
		}

		uint32_t address;
		if (address_space < 2)
			address = (lwBdrige ? LWHPSFPGA_OFST : HPSFPGA_OFST) + addressOffset;
		else
			address = addressOffset;
		// only in case the input is vailed write the request to the light wight bus
		if (InputVailed)
		{
			if (ConsloeOutput)
			{
				if (address_space < 2)
				{
					cout << "	------- Write to a FPGA Register via a HPS-to-FPGA Bridge -------" << endl;
					cout << "	Bridge:      " << (lwBdrige ? "Lightweight HPS-to-FPGA" : "HPS-to-FPGA") << endl;
					cout << "	Brige Base:  0x" << hex << (lwBdrige ? LWHPSFPGA_OFST : HPSFPGA_OFST) << dec << endl;
					cout << "	Your Offset: 0x" << hex << addressOffset << dec << endl;
					cout << "	Address:     0x" << hex << address << dec << endl;
					cout << "	Value:       " << ValueInput <<hex<<" [0x"<< ValueInput<<"]"<<dec<<endl;
				}
				else
				{
					cout << "	-------    Write to a MPU (HPS) memory address register  -------" << endl;
					cout << "	Address:     0x" << hex << address << dec << endl;
					cout << "	Value:       " << ValueInput << hex << " [0x" << ValueInput << "]" << dec << endl;
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

				// configure a virtual memory interface to the bridge or mpu
				bridgeMap = mmap(NULL, MAP_SIZE, PROT_READ|PROT_WRITE, MAP_SHARED, fd, \
					address & ~MAP_MASK);

				// check if opening was sucsessful
				if (bridgeMap == MAP_FAILED)
				{
					if (ConsloeOutput)
						cout << "ERROR: Accesing the virtual memory failed!" << endl;
					else
						cout << 0;
					close(fd);
					return 0;
				}

				// access to Bridge is okay 
				// write the value to the address 
				void* write_bridge = bridgeMap +(address & MAP_MASK);

				uint16_t delay_count = 0;
				uint32_t value = *((uint32_t*)write_bridge);
				// print also the old value of the selected register
				if (ConsloeOutput)
				{
					
					cout << "        old Value:   " << value << " [0x" << hex << value << "]" << dec << endl;
				}
	
				// write the value to the address 

				// write the new value to the selected register
				
				if (DecHexBin == BIN_INPUT)
				{
					if (SetResetBit) *((uint32_t*)write_bridge) |= (1 << BitPosValue);
					else			 *((uint32_t*)write_bridge) &= ~(1 << BitPosValue);
				}
				else
					*((uint32_t*)write_bridge) = ValueInput;
				

				// Close the MAP 
				if (munmap(bridgeMap, MAP_SIZE) < 0)
				{
					if (ConsloeOutput)
						cout << "ERROR: Closing of shared memory failed!" << endl;
				}

				// close the driver port 
				close(fd);

				if (ConsloeOutput)
					cout << "Writing was successfully" << endl;
			/*	else
					cout << 1;*/

			} while (0);
		}
		else
		{
			// the user input is not okay 
			if (!ConsloeOutput)
				cout << 0;
		}
	}
	else
	{
		// help output 
		cout << "-------------------------------------------------------------------------------------" << endl;
		cout << "|	Command to write to a 32-bit register of a HPS-to-FPGA Bridge	            |" << endl;
		cout << "|		or of the entire MPU (HPS) Memory space				    |" << endl;
		cout << "|  Note: Be sure that the bridge to write is enabled within the Platform Designer   |" << endl;
		cout << "-------------------------------------------------------------------------------------" << endl;
		cout << "|$	FPGA-writeBridge -lw [offset address in hex] [value in dec]					" << endl;
		cout << "|		write to a 32-bit register of the Lightweight HPS-to-FPGA Bridge in dec	" << endl;
		cout << "|		e.g.: FPGA-writeBridge -lw 0A 10						" << endl;
		cout << "|$	FPGA-writeBridge -lw [offset address in hex] -h [value in hex]			" << endl;
		cout << "|		write to a 32-bit register of the Lightweight HPS-to-FPGA Bridge in hex		" << endl;
		cout << "|		e.g.: FPGA-writeBridge -lw 0A -h 12						" << endl;
		cout << "|$	FPGA-writeBridge -lw [offset address in hex] -b [bit pos] [bit value] " << endl;
		cout << "|		set a bit of the Lightweight HPS-to-FPGA Bridge		" << endl;
		cout << "|		e.g.: FPGA-writeBridge -lw 0A -b 3 1						" << endl;
		cout << "|$	FPGA-writeBridge -hf [offset address in hex] [value dec]				" << endl;
		cout << "|		write to a 32-bit register of the HPS-to-FPGA AXI Bridge	" << endl;
		cout << "|		e.g.: FPGA-writeBridge -hf 8C							" << endl;
		cout << "|$	FPGA-writeBridge -mpu [module address in hex] [value dec]" << endl;
		cout << "|		write to a 32-bit register for the entire MPU (HPS) memory space" << endl;
		cout << "|		e.g.: FPGA-writeBridge -mpu 87" << endl;
		cout << "|		Suffix: -b -> only decimal result output" << endl;
		cout << "|$	FPGA-writeBridge -lw|hf|mpu| <offset address in hex> -h|-b|<value dec> <value hex>|<bit pos> <bit value>  -b" << endl;
		cout << "-------------------------------------------------------------------------------------" << endl;
	}


	// free the dynamic access memory
	__VIRTUALMEM_SPACE_DEINIT();

	return 0;
}