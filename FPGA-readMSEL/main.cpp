/**
 * @file    main.cpp
 * @brief	FPGA-readMSEL 
 * @author  Robin Sebastian (https://github.com/robseb) (git@robseb.de)
 * @mainpage
 * rstools application to read the FPGA MSEL Switch with the
 * FPGA Manager
 */

#include <cstdio>
#include "alt_fpga_manager.h"
#include "hps.h"
#include <string.h>
#include <fstream>
#include <iostream>
using namespace std;


// Enable the Diagnostic Mode
#define DEBUG_ALT_FPGA_MANAGER

#pragma region convert to string 
string cfg2str(ALT_FPGA_CFG_MODE_t cfg)
{
	switch (cfg)
	{
	case ALT_FPGA_CFG_MODE_PP16_FAST_NOAES_NODC:
		return "MSEL[4..0]       : 00000 [0x0]\n"\
				"MODE             : Passive Parallel x16 (FPPx16)\n"\
				"POR Delay        : Fast power on\n"\
				"Security         : AES Encryption Disabled\n"\
				"cdratio          : x1\n"\
				"cfgwdth		  : 0\n"\
				"Partial Reconfig.: supported\n"\
				"Data Compression : Disabled";

	case	ALT_FPGA_CFG_MODE_PP16_FAST_AES_NODC:
		return "MSEL[4..0]       : 00001 [0x01]\n"\
				"MODE             : Passive Parallel x16 (FPPx16)\n"\
				"POR Delay        : Fast power on\n"\
				"Security         : AES Encryption\n"\
				"cdratio          : x2\n"\
				"cfgwdth		  : 0\n"\
				"Partial Reconfig.: supported\n"\
				"Data Compression : Disabled";

	case ALT_FPGA_CFG_MODE_PP16_FAST_AESOPT_DC:
		return "MSEL[4..0]       : 00010 [0x02]\n"\
				"MODE             : Passive Parallel x16 (FPPx16)\n"\
				"POR Delay        : Fast power on\n"\
				"Security         : Optional AES Encryption\n"\
				"cdratio          : x4\n"\
				"cfgwdth		  : 0\n"\
				"Partial Reconfig.: supported\n"\
				"Data Compression : Disabled";

	case ALT_FPGA_CFG_MODE_PP16_SLOW_NOAES_NODC:
		return "MSEL[4..0]       : 00100 [0x04]\n"\
				"MODE             : Passive Parallel x16 (FPPx16)\n"\
				"POR Delay        : Slow power on\n"\
				"Security         : AES Encryption Disabled\n"\
				"cdratio          : x1\n"\
				"cfgwdth		  : 0\n"\
				"Partial Reconfig.: supported\n"\
				"Data Compression : Disabled";
		
	case	ALT_FPGA_CFG_MODE_PP16_SLOW_AES_NODC:
		return "MSEL[4..0]       : 00101 [0x05]\n"\
				"MODE             : Passive Parallel x16 (FPPx16)\n"\
				"POR Delay        : Slow power on\n"\
				"Security         : AES encoding\n"\
				"cdratio          : x4\n"\
				"cfgwdth		  : 0\n"\
				"Partial Reconfig.: supported\n"\
				"Data Compression : Disabled";

	case	ALT_FPGA_CFG_MODE_PP16_SLOW_AESOPT_DC:
		return "MSEL[4..0]       : 00110 [0x06]\n"\
				"MODE             : Passive Parallel x16 (FPPx16)\n"\
				"POR Delay        : Slow power on\n"\
				"Security         : Optional AES Encryption\n"\
				"cdratio          : x8\n"\
				"cfgwdth		  : 0\n"\
				"Partial Reconfig.: supported\n"\
				"Data Compression : Enabled";

	case	ALT_FPGA_CFG_MODE_PP32_FAST_NOAES_NODC:
		return "MSEL[4..0]       : 01000 [0x08]\n"\
				"MODE             : Passive Parallel x32 (FPPx32)\n"\
				"POR Delay        : Fast power on\n"\
				"Security         : AES Encryption Disabled\n"\
				"cdratio          : x1\n"\
				"cfgwdth		  : 1\n"\
				"Partial Reconfig.: not supported\n"\
				"Data Compression : Disabled";

	case	ALT_FPGA_CFG_MODE_PP32_FAST_AES_NODC:
		return "MSEL[4..0]       : 01001 [0x09]\n"\
				"MODE             : Passive Parallel x32 (FPPx32)\n"\
				"POR Delay        : Fast power on\n"\
				"Security         : AES Encryption\n"\
				"cdratio          : x4\n"\
				"cfgwdth		  : 1\n"\
				"Partial Reconfig.: not supported\n"\
				"Data Compression : Enabled";

	case	ALT_FPGA_CFG_MODE_PP32_FAST_AESOPT_DC:
		return "MSEL[4..0]       : 01010 [0x0a]\n"\
				"MODE             : Passive Parallel x32 (FPPx32)\n"\
				"POR Delay        : Fast power on\n"\
				"Security         : Optional AES Encryption\n"\
				"cdratio          : x8\n"\
				"cfgwdth		  : 1\n"\
				"Partial Reconfig.: not supported\n"\
				"Data Compression : Enabled";

	case	ALT_FPGA_CFG_MODE_PP32_SLOW_NOAES_NODC:
		return "MSEL[4..0]       : 01100 [0x0c]\n"\
				"MODE             : Passive Parallel x32 (FPPx32)\n"\
				"POR Delay        : Slow power on\n"\
				"Security         : AES Encryption Disabled\n"\
				"cdratio          : x1\n"\
				"cfgwdth		  : 1\n"\
				"Partial Reconfig.: not supported\n"\
				"Data Compression : Disabled";

	case	ALT_FPGA_CFG_MODE_PP32_SLOW_AES_NODC:
		return "MSEL[4..0]       : 01101 [0x0d]\n"\
				"MODE             : Passive Parallel x32 (FPPx32)\n"\
				"POR Delay        : Slow power on\n"\
				"Security         : AES Encryption\n"\
				"cdratio          : x4\n"\
				"cfgwdth		  : 1\n"\
				"Partial Reconfig.: not supported\n"\
				"Data Compression : Disabled";

	case	ALT_FPGA_CFG_MODE_PP32_SLOW_AESOPT_DC:
		return "MSEL[4..0]       : 01110 [0x0e]\n"\
				"MODE             : Passive Parallel x32 (FPPx32)\n"\
				"POR Delay        : Slow power on\n"\
				"Security         : Optional AES Encryption\n"\
				"cdratio          : x8\n"\
				"cfgwdth		  : 1\n"\
				"Partial Reconfig.: not supported\n"\
				"Data Compression : Enabled";
	default:
		return "ERROR: unknown MSEL selection!";
	}
}
#pragma endregion


int main(int argc, const char* argv[])
{
	///////// init the Virtual Memory for I/O access /////////
	__VIRTUALMEM_SPACE_INIT();

	/////////	 init the FPGA Manager	 /////////
	alt_fpga_init();
	
	// Take the right to controll the FPGA
	alt_fpga_control_enable();

	/////////  read the MSEL-switch postion			/////////
	ALT_FPGA_CFG_MODE_t st = alt_fpga_cfg_mode_get();

	if ((argc > 1) && (std::string(argv[1]) == "-h"))
	{
		cout << "	Command to read the selected FPGA configuration mode." << endl;
		cout << "	This is set with the MSEL-Switch."<< endl;
		cout << "	FPGA-readMSEL" << endl;
		cout << "		read MSEL with detailed output" << endl;
		cout << "	FPGA-readMSEL -d" << endl;
		cout << "		read MSEL as decimal value" << endl;
	}
	else if ((argc > 1) && (std::string(argv[1]) == "-d"))
		// Print only the MSEL Value 
		cout << st;
	else
	{
		// Print the MSEL Value as detailed string 
		cout << "-- Read the MSEL-Switch Status with the FPGA Manager of Intel Cyclone V  --" << endl;
		cout << "      MSEL-switch postion: " << endl << cfg2str(st) << endl;
		cout << "\nNote: cdratio: Clock-to-data ratio field" << endl;
		cout << "      cfgwdth: Configuration data width bit" << endl;
	}
	
	// Give the right to controll the FPGA
	alt_fpga_control_disable();

	// free the dynamic access memory
	__VIRTUALMEM_SPACE_DEINIT();

	return 0;
}
