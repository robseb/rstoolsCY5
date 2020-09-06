# rstools

 **`rstools`is the source code of the *socfpgatools* of the [*meta-intelfpga*](https://github.com/robseb/meta-intelfpga) BSP-Layer**

`meta-intelfpga` is a BSP-Layer for bringing support for *Intel* (*ALTERA*) SoC-FPGAs (*SoCFPGAs*) to the *Yocto Project*.
The *socfpgatools* add a simple way for fully accessing the FPGA Manager of the Intel (*ALTERA*) Cyclone V SoC-FPGA (*SoCFPGA*).

Additionally, with a single command it is possible to read or write the *ARM AXI-Bridge* (*Lightweight HPS-to-FPGA-* (*LWHPS2FPGA*) or *HPS-to-FPGA (*HPS2FPGA*) Bridge*) to the FPGA Fabric.
It enables to check the startus of the FPGA Fabric, write or read any address of the MPU (*HPS*) Memory space or the read and write the general purpose in- (*GPI*) and output- (*GPO*) registers. 

This source code and the [*meta-intelfpga*](https://github.com/robseb/meta-intelfpga) is a part of my [*rsyocto*](https://github.com/robseb/rsyocto). A embedded Linux Distribution for *Intel* SoC-FPGAs.

<br>

![Alt text](FPGAConfigurationAction.gif?raw=true "Write FPGA Configuration")

**Write the FPGA configuration with a single Linux command** 

___
## Features 

* **The layer adds following features to the final Linux command set:**
  *  **FPGA Status**
      * Reading the Status of the FPGA fabric 
      ````bash
      FPGA-status 
      ````
      * Help- and Info- Output with the suffix `-h` 
        ````bash
          Command to read current Status mode of the FPGA fabric
          FPGA-status
                  read the status with detailed output
          FPGA-status -d
                  POWER UP:        0
                  RESET:           1
                  CONFIG:          2
                  INIT:            3
                  USER:            4
                  UNKNOWN:         5
        ````
  * **FPGA Configuration Mode / MSEL** 
    * Reading the Configuration mode of the FPGA (selected with the MSEL-Bit Switch)
        ````bash
        FPGA-status
        ````
     * Help- and Info- Output with the suffix `-h`  
           ````bash
          Command to read the selected FPGA configuration mode.
          This is set with the MSEL-Switch.
          FPGA-readMSEL
                  read MSEL with detailed output
          FPGA-readMSEL -d
                  read MSEL as decimal value
          ````
 * **FPGA Fabric Reset** 
    * Resetting the FPGA fabric (remove the running configuration)
        ````bash
        FPGA-resetFabric
        ````
     * Help output with the suffix `-h`  
          ````bash
          Command to reset the FPGA fabic
          A reset clears the current configuration
          of the FPGA fabric
          After a reset is the FPGA in the RESET Mode
          FPGA-resetFabric -r
                  reset the FPGA with detailed output
          FPGA-status -d
                  read the status as decimal value
                  0 => ERROR: Resting of the FPGA failed!
                  1 => Success: FPGA config is deleted
          ````
  * **Write FPGA Configuration** 
    * Writing a new FPGA configuration
        ````bash
        FPGA-writeConfig
        ````
     * Help output with the suffix `-h`  
          ````bash
            Command to change the FPGA fabric configuration
            for Cyclone V use following RBF (.rbf) config file settings
            MSEL=00100: PP16 with no AES and no Data compression
            MSEL=00101: PP16 with AES and no Data compression
            FPGA-writeConfig -f [config rbf file path] {-b [optional]}
                    change the FPGA config with a selected .rbf file
            FPGA-writeConfig -r {-b [optional]}
                    restore to the boot up FPGA configuration
                    this conf File is located: /usr/rsyocto/running_bootloader_fpgaconfig.rbf
                    suffix: -b -> only decimal result output
                                                    Error:  0
                                                    Succses:1
          ````
      * Required MSEL-Bit Switch Selection to allow Linux to change the FPGA configuration:
        * `MSEL= 00100`: Passive parallel x16 with no AES and Data compression
        * `MSEL= 00101`: Passive parallel x16  with AES and Data compression

 * **LWHPS2FPGA-, HPS2FPGA-Bridge or MPU address space read** 
    * Reading a address (*32-Bit* register) of the *HPS-to-FPGA-*, *Lightweight-HPS-to-FPGA- Bridge* or from the *MPU* (*HPS*) memory space interface
        ````bash
        FPGA-readBridge
        ````
     * Help output with the suffix `-h`  
        ````bash
        -------------------------------------------------------------------------------------
        |	Command to read a 32-bit register of a HPS-to-FPGA Bridge	            |
        |		or of the entire MPU (HPS) Memory space				    |
        |  Note: Be sure that the bridge to read is enabled within the Platform Designer    |
        -------------------------------------------------------------------------------------
        |$	FPGA-readBridge -lw [offset address in hex]					
        |		read a 32-bit register of the Lightweight HPS-to-FPGA Bridge		
        |		e.g.: FPGA-readBridge -lw 0A							
        |$	FPGA-readBridge -hf [offset address in hex]				
        |		read a 32-bit register of the HPS-to-FPGA AXI Bridge	
        |		e.g.: FPGA-readBridge -hf 8C							
        |$	FPGA-readBridge -mpu [module address in hex]
        |		read a 32-bit register for the entire MPU (HPS) memory space
        |		e.g.: FPGA-readBridge -mpu 87
        |		Suffix: -b -> only decimal result output
        |		Suffix: -r -> Auto refrech the value for 15sec
        |$	FPGA-readBridge -lw|hf|mpu| <offset address in hex> -b|r
        -------------------------------------------------------------------------------------
        ````
 * **LWHPS2FPGA-, HPS2FPGA-Bridge or MPU address space Read** 
    * * Writing to a address (*32-Bit* register) of the *HPS-to-FPGA-*, *Lightweight-HPS-to-FPGA- Bridge* or from the *MPU* (*HPS*) memory space interface
        ````bash
        FPGA-writeBridge
        ````
     * Help- and Info- Output with the suffix `-h`  
        ````bash
        -------------------------------------------------------------------------------------
        |	Command to write to a 32-bit register of a HPS-to-FPGA Bridge	            |
        |		or of the entire MPU (HPS) Memory space				    |
        |  Note: Be sure that the bridge to write is enabled within the Platform Designer   |
        -------------------------------------------------------------------------------------
        |$	FPGA-writeBridge -lw [offset address in hex] [value in dec]					
        |		write to a 32-bit register of the Lightweight HPS-to-FPGA Bridge in dec	
        |		e.g.: FPGA-writeBridge -lw 0A 10						
        |$	FPGA-writeBridge -lw [offset address in hex] -h [value in hex]			
        |		write to a 32-bit register of the Lightweight HPS-to-FPGA Bridge in hex		
        |		e.g.: FPGA-writeBridge -lw 0A -h 12						
        |$	FPGA-writeBridge -lw [offset address in hex] -b [bit pos] [bit value] 
        |		set a bit of the Lightweight HPS-to-FPGA Bridge		
        |		e.g.: FPGA-writeBridge -lw 0A -b 3 1						
        |$	FPGA-writeBridge -hf [offset address in hex] [value dec]				
        |		write to a 32-bit register of the HPS-to-FPGA AXI Bridge	
        |		e.g.: FPGA-writeBridge -hf 8C							
        |$	FPGA-writeBridge -mpu [module address in hex] [value dec]
        |		write to a 32-bit register for the entire MPU (HPS) memory space
        |		e.g.: FPGA-writeBridge -mpu 87
        |		Suffix: -b -> only decimal result output
        |$	FPGA-writeBridge -lw|hf|mpu| <offset address in hex> -h|-b|<value dec> <value hex>|<bit pos> <bit value>  -b
        -------------------------------------------------------------------------------------
        ````
* **GPI Register Read (*GPI*)** 
    * Reading the 32-Bit direct access Register (*written by the FPGA*)
        ````bash
        FPGA-gpiRead
        ````
     * Help- and Info- Output with the suffix `-h`  
        ````bash
             Command to read general-purpose input signals (gpi) from
             the FPGA fabric.
             The FPGA can set the 32 Bit gpi (input) register
              FPGA-gpiRead
                      read gpi with detailed output
              FPGA-gpiRead -d
                      read gpi as decimal value
         ````
* **GPO Register Write (*GPO*)** 
    * Writing the 32-Bit direct access Register to the FPGA
        ````bash
        FPGA-gpoWrite
        ````
     * Help- and Info- Output with the suffix `-h`  
        ````bash
               Command to write the general-purpose output signals (gpo) to
              the FPGA fabric
              The HPS get write a 32 Bit register to the FPGA
              FPGA-gpoWrite -h [uint]
                      writing the whole 32 Bit gpo as HEX
                      e.g.: FPGA-gpoWrite -h ffffffff
              FPGA-gpoWrite -d [uint]
                      writing the whole 32 Bit gpo as DEC
                      e.g.: FPGA-gpoWrite -d 12345
              FPGA-gpoWrite -b [bit pos] [value]
                      writing a specific Bit position
                      e.g.: FPGA-gpoWrite -b 16 1
                                (to set the Bit 16 of the gpo Regiser)
         ````
 ### For more informations and examples about the usage of these commands please follow the [*rsYocto*](https://github.com/robseb/rsyocto) documentation. 
 <br>
        

## Using this Code 
The Code was writen with **Microsoft Visual Studio 2019 with Linux Development for C++** and as target [*rsYocto*](https://github.com/robseb/rsyocto) used. 
For informations how to use Microsoft Visual Studio 2019 for embedded Linux development please follow the [*rsYocto*](https://github.com/robseb/rsyocto) documentation.


<br>

# Author
* **Robin Sebastian**

*rstools*  and *meta-intelfpa* are projects, that I have fully developed on my own. No companies are involved in my projects. 
I’m recently graduated as a master in electrical engineering with the major embedded systems (M. Sc.).

[![Gitter](https://badges.gitter.im/rsyocto/community.svg)](https://gitter.im/rsyocto/community?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge)
[![Email me!](https://img.shields.io/badge/Ask%20me-anything-1abc9c.svg)](mailto:git@robseb.de)

