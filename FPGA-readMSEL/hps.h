/***********************************************************************************
*                                                                                  *
* Copyright 2013-2015 Altera Corporation. All Rights Reserved.                     *
*                                                                                  *
* Redistribution and use in source and binary forms, with or without               *
* modification, are permitted provided that the following conditions are met:      *
*                                                                                  *
* 1. Redistributions of source code must retain the above copyright notice,        *
*    this list of conditions and the following disclaimer.                         *
*                                                                                  *
* 2. Redistributions in binary form must reproduce the above copyright notice,     *
*    this list of conditions and the following disclaimer in the documentation     *
*    and/or other materials provided with the distribution.                        *
*                                                                                  *
* 3. Neither the name of the copyright holder nor the names of its contributors    *
*    may be used to endorse or promote products derived from this software without *
*    specific prior written permission.                                            *
*                                                                                  *
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"      *
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE        *
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE       *
* ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE        *
* LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR              *
* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF             *
* SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS         *
* INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN          *
* CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)          *
* ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE       *
* POSSIBILITY OF SUCH DAMAGE.                                                      *
*                                                                                  *
***********************************************************************************/

/* Altera - hps */

#ifndef __ALT_SOCAL_HPS_H__
#define __ALT_SOCAL_HPS_H__

#ifndef __ASSEMBLY__
#ifdef __cplusplus
#include <cstdint>
extern "C"
{
#else   /* __cplusplus */
#include <stdint.h>
#endif  /* __cplusplus */
#endif  /* __ASSEMBLY__ */
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define LINUX_TASK_MODE

volatile void* __hps_virtualAdreess_FPGAMGR;
volatile void* __hps_virtualAdreess_FPGAMFRDATA;

volatile int __fd;

//
// macro to include the virtual Memory 
//
//
#define __VIRTUALMEM_SPACE_INIT()                                                                                               \          
__fd = open("/dev/mem", (O_RDWR | O_SYNC));                                                                                  \
__hps_virtualAdreess_FPGAMGR = mmap(NULL, 0x1000, (PROT_READ | PROT_WRITE), MAP_SHARED, __fd, ALT_FPGAMGR_OFST);                \
__hps_virtualAdreess_FPGAMFRDATA = mmap(NULL, 0x400, (PROT_READ | PROT_WRITE), MAP_SHARED, __fd, ALT_FPGAMGRDATA_OFST)


#define __VIRTUALMEM_SPACE_DEINIT()                                                                                              \
        munmap((void*) __hps_virtualAdreess_FPGAMGR, 0x1000);                                                                            \
        munmap((void*) __hps_virtualAdreess_FPGAMFRDATA, 0x400);                                                         \
        close(__fd)


#define ALT_HPS_ADDR        0
/*
 * Address Space : ALT_HPS
 * 
 */
/*
 * Component Instance : i_fpga_bridge_soc2fpga128
 * 
 * Instance i_fpga_bridge_soc2fpga128 of component ALT_FPGA_BRIDGE_H2F128.
 * 
 * 
 */
/* The base address byte offset for the start of the ALT_FPGA_BRIDGE_H2F128 component. */
#define ALT_FPGA_BRIDGE_H2F128_OFST        0xc0000000
/* The start address of the ALT_FPGA_BRIDGE_H2F128 component. */
#define ALT_FPGA_BRIDGE_H2F128_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_FPGA_BRIDGE_H2F128_OFST))
/* The lower bound address range of the ALT_FPGA_BRIDGE_H2F128 component. */
#define ALT_FPGA_BRIDGE_H2F128_LB_ADDR     ALT_FPGA_BRIDGE_H2F128_ADDR
/* The upper bound address range of the ALT_FPGA_BRIDGE_H2F128 component. */
#define ALT_FPGA_BRIDGE_H2F128_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_FPGA_BRIDGE_H2F128_ADDR) + 0x3c000000) - 1))


/*
 * Component Instance : i_fpga_bridge_lwsoc2fpga
 * 
 * Instance i_fpga_bridge_lwsoc2fpga of component ALT_FPGA_BRIDGE_LWH2F.
 * 
 * 
 */
/* The base address byte offset for the start of the ALT_FPGA_BRIDGE_LWH2F component. */
#define ALT_FPGA_BRIDGE_LWH2F_OFST        0xff200000
/* The start address of the ALT_FPGA_BRIDGE_LWH2F component. */
#define ALT_FPGA_BRIDGE_LWH2F_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_FPGA_BRIDGE_LWH2F_OFST))
/* The lower bound address range of the ALT_FPGA_BRIDGE_LWH2F component. */
#define ALT_FPGA_BRIDGE_LWH2F_LB_ADDR     ALT_FPGA_BRIDGE_LWH2F_ADDR
/* The upper bound address range of the ALT_FPGA_BRIDGE_LWH2F component. */
#define ALT_FPGA_BRIDGE_LWH2F_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_FPGA_BRIDGE_LWH2F_ADDR) + 0x200000) - 1))


/*
 * Component Instance : i_emac_emac0
 * 
 * Instance i_emac_emac0 of component ALT_EMAC.
 * 
 * 
 */
/* The address of the ALT_EMAC_GMAC_MAC_CFG register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_CFG_ADDR  ALT_EMAC_GMAC_MAC_CFG_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_FRM_FLT register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_FRM_FLT_ADDR  ALT_EMAC_GMAC_MAC_FRM_FLT_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_GMII_ADDR register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_GMII_ADDR_ADDR  ALT_EMAC_GMAC_GMII_ADDR_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_GMII_DATA register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_GMII_DATA_ADDR  ALT_EMAC_GMAC_GMII_DATA_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_FLOW_CTL register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_FLOW_CTL_ADDR  ALT_EMAC_GMAC_FLOW_CTL_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_VLAN_TAG register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_VLAN_TAG_ADDR  ALT_EMAC_GMAC_VLAN_TAG_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_VER register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_VER_ADDR  ALT_EMAC_GMAC_VER_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_DBG register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_DBG_ADDR  ALT_EMAC_GMAC_DBG_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_LPI_CTL_STAT register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_LPI_CTL_STAT_ADDR  ALT_EMAC_GMAC_LPI_CTL_STAT_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_LPI_TMRS_CTL register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_LPI_TMRS_CTL_ADDR  ALT_EMAC_GMAC_LPI_TMRS_CTL_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_INT_STAT register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_INT_STAT_ADDR  ALT_EMAC_GMAC_INT_STAT_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_INT_MSK register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_INT_MSK_ADDR  ALT_EMAC_GMAC_INT_MSK_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR0_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR0_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR0_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR0_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR0_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR0_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR1_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR1_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR1_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR1_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR1_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR1_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR2_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR2_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR2_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR2_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR2_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR2_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR3_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR3_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR3_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR3_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR3_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR3_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR4_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR4_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR4_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR4_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR4_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR4_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR5_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR5_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR5_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR5_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR5_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR5_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR6_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR6_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR6_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR6_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR6_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR6_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR7_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR7_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR7_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR7_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR7_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR7_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR8_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR8_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR8_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR8_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR8_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR8_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR9_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR9_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR9_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR9_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR9_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR9_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR10_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR10_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR10_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR10_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR10_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR10_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR11_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR11_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR11_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR11_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR11_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR11_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR12_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR12_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR12_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR12_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR12_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR12_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR13_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR13_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR13_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR13_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR13_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR13_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR14_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR14_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR14_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR14_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR14_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR14_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR15_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR15_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR15_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR15_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR15_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR15_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MII_CTL_STAT register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_SGMII_RGMII_SMII_CTL_STAT_ADDR  ALT_EMAC_GMAC_MII_CTL_STAT_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_WDOG_TMO register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_WDOG_TMO_ADDR  ALT_EMAC_GMAC_WDOG_TMO_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_GENPIO register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_GENPIO_ADDR  ALT_EMAC_GMAC_GENPIO_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MMC_CTL register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MMC_CTL_ADDR  ALT_EMAC_GMAC_MMC_CTL_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MMC_RX_INT register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MMC_RX_INT_ADDR  ALT_EMAC_GMAC_MMC_RX_INT_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MMC_TX_INT register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MMC_TX_INT_ADDR  ALT_EMAC_GMAC_MMC_TX_INT_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MMC_RX_INT_MSK register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MMC_RX_INT_MSK_ADDR  ALT_EMAC_GMAC_MMC_RX_INT_MSK_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MMC_TX_INT_MSK register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MMC_TX_INT_MSK_ADDR  ALT_EMAC_GMAC_MMC_TX_INT_MSK_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_TXOCTETCOUNT_GB register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_TXOCTETCOUNT_GB_ADDR  ALT_EMAC_GMAC_TXOCTETCOUNT_GB_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_TXFRMCOUNT_GB register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_TXFRMCOUNT_GB_ADDR  ALT_EMAC_GMAC_TXFRMCOUNT_GB_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_TXBCASTFRMS_G register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_TXBCASTFRMS_G_ADDR  ALT_EMAC_GMAC_TXBCASTFRMS_G_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_TXMCASTFRMS_G register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_TXMCASTFRMS_G_ADDR  ALT_EMAC_GMAC_TXMCASTFRMS_G_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_TX64OCTETS_GB register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_TX64OCTETS_GB_ADDR  ALT_EMAC_GMAC_TX64OCTETS_GB_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_TX65TO127OCTETS_GB register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_TX65TO127OCTETS_GB_ADDR  ALT_EMAC_GMAC_TX65TO127OCTETS_GB_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_TX128TO255OCTETS_GB register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_TX128TO255OCTETS_GB_ADDR  ALT_EMAC_GMAC_TX128TO255OCTETS_GB_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_TX256TO511OCTETS_GB register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_TX256TO511OCTETS_GB_ADDR  ALT_EMAC_GMAC_TX256TO511OCTETS_GB_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_TX512TO1023OCTETS_GB register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_TX512TO1023OCTETS_GB_ADDR  ALT_EMAC_GMAC_TX512TO1023OCTETS_GB_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_TX1024TOMAXOCTETS_GB register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_TX1024TOMAXOCTETS_GB_ADDR  ALT_EMAC_GMAC_TX1024TOMAXOCTETS_GB_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_TXUNICASTFRMS_GB register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_TXUNICASTFRMS_GB_ADDR  ALT_EMAC_GMAC_TXUNICASTFRMS_GB_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_TXMCASTFRMS_GB register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_TXMCASTFRMS_GB_ADDR  ALT_EMAC_GMAC_TXMCASTFRMS_GB_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_TXBCASTFRMS_GB register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_TXBCASTFRMS_GB_ADDR  ALT_EMAC_GMAC_TXBCASTFRMS_GB_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_TXUNDERFLOWERROR register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_TXUNDERFLOWERROR_ADDR  ALT_EMAC_GMAC_TXUNDERFLOWERROR_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_TXSINGLECOL_G register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_TXSINGLECOL_G_ADDR  ALT_EMAC_GMAC_TXSINGLECOL_G_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_TXMULTICOL_G register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_TXMULTICOL_G_ADDR  ALT_EMAC_GMAC_TXMULTICOL_G_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_TXDEFERRED register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_TXDEFERRED_ADDR  ALT_EMAC_GMAC_TXDEFERRED_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_TXLATECOL register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_TXLATECOL_ADDR  ALT_EMAC_GMAC_TXLATECOL_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_TXEXESSCOL register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_TXEXESSCOL_ADDR  ALT_EMAC_GMAC_TXEXESSCOL_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_TXCARRIERERR register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_TXCARRIERERR_ADDR  ALT_EMAC_GMAC_TXCARRIERERR_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_TXOCTETCNT register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_TXOCTETCNT_ADDR  ALT_EMAC_GMAC_TXOCTETCNT_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_TXFRMCOUNT_G register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_TXFRMCOUNT_G_ADDR  ALT_EMAC_GMAC_TXFRMCOUNT_G_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_TXEXCESSDEF register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_TXEXCESSDEF_ADDR  ALT_EMAC_GMAC_TXEXCESSDEF_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_TXPAUSEFRMS register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_TXPAUSEFRMS_ADDR  ALT_EMAC_GMAC_TXPAUSEFRMS_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_TXVLANFRMS_G register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_TXVLANFRMS_G_ADDR  ALT_EMAC_GMAC_TXVLANFRMS_G_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_TXOVERSIZE_G register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_TXOVERSIZE_G_ADDR  ALT_EMAC_GMAC_TXOVERSIZE_G_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_RXFRMCOUNT_GB register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_RXFRMCOUNT_GB_ADDR  ALT_EMAC_GMAC_RXFRMCOUNT_GB_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_RXOCTETCOUNT_GB register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_RXOCTETCOUNT_GB_ADDR  ALT_EMAC_GMAC_RXOCTETCOUNT_GB_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_RXOCTETCOUNT_G register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_RXOCTETCOUNT_G_ADDR  ALT_EMAC_GMAC_RXOCTETCOUNT_G_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_RXBCASTFRMS_G register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_RXBCASTFRMS_G_ADDR  ALT_EMAC_GMAC_RXBCASTFRMS_G_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_RXMCASTFRMS_G register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_RXMCASTFRMS_G_ADDR  ALT_EMAC_GMAC_RXMCASTFRMS_G_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_RXCRCERROR register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_RXCRCERROR_ADDR  ALT_EMAC_GMAC_RXCRCERROR_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_RXALIGNMENTERROR register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_RXALIGNMENTERROR_ADDR  ALT_EMAC_GMAC_RXALIGNMENTERROR_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_RXRUNTERROR register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_RXRUNTERROR_ADDR  ALT_EMAC_GMAC_RXRUNTERROR_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_RXJABBERERROR register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_RXJABBERERROR_ADDR  ALT_EMAC_GMAC_RXJABBERERROR_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_RXUNDERSIZE_G register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_RXUNDERSIZE_G_ADDR  ALT_EMAC_GMAC_RXUNDERSIZE_G_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_RXOVERSIZE_G register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_RXOVERSIZE_G_ADDR  ALT_EMAC_GMAC_RXOVERSIZE_G_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_RX64OCTETS_GB register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_RX64OCTETS_GB_ADDR  ALT_EMAC_GMAC_RX64OCTETS_GB_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_RX65TO127OCTETS_GB register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_RX65TO127OCTETS_GB_ADDR  ALT_EMAC_GMAC_RX65TO127OCTETS_GB_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_RX128TO255OCTETS_GB register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_RX128TO255OCTETS_GB_ADDR  ALT_EMAC_GMAC_RX128TO255OCTETS_GB_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_RX256TO511OCTETS_GB register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_RX256TO511OCTETS_GB_ADDR  ALT_EMAC_GMAC_RX256TO511OCTETS_GB_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_RX512TO1023OCTETS_GB register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_RX512TO1023OCTETS_GB_ADDR  ALT_EMAC_GMAC_RX512TO1023OCTETS_GB_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_RX1024TOMAXOCTETS_GB register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_RX1024TOMAXOCTETS_GB_ADDR  ALT_EMAC_GMAC_RX1024TOMAXOCTETS_GB_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_RXUNICASTFRMS_G register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_RXUNICASTFRMS_G_ADDR  ALT_EMAC_GMAC_RXUNICASTFRMS_G_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_RXLENERROR register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_RXLENERROR_ADDR  ALT_EMAC_GMAC_RXLENERROR_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_RXOUTOFRANGETYPE register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_RXOUTOFRANGETYPE_ADDR  ALT_EMAC_GMAC_RXOUTOFRANGETYPE_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_RXPAUSEFRMS register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_RXPAUSEFRMS_ADDR  ALT_EMAC_GMAC_RXPAUSEFRMS_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_RXFIFOOVF register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_RXFIFOOVF_ADDR  ALT_EMAC_GMAC_RXFIFOOVF_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_RXVLANFRMS_GB register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_RXVLANFRMS_GB_ADDR  ALT_EMAC_GMAC_RXVLANFRMS_GB_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_RXWDERROR register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_RXWDERROR_ADDR  ALT_EMAC_GMAC_RXWDERROR_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_RXRCVERROR register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_RXRCVERROR_ADDR  ALT_EMAC_GMAC_RXRCVERROR_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_RXCTLFRMS_G register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_RXCTLFRMS_G_ADDR  ALT_EMAC_GMAC_RXCTLFRMS_G_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MMC_IPC_RX_INT_MSK register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MMC_IPC_RX_INT_MSK_ADDR  ALT_EMAC_GMAC_MMC_IPC_RX_INT_MSK_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MMC_IPC_RX_INT register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MMC_IPC_RX_INT_ADDR  ALT_EMAC_GMAC_MMC_IPC_RX_INT_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_RXIPV4_GD_FRMS register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_RXIPV4_GD_FRMS_ADDR  ALT_EMAC_GMAC_RXIPV4_GD_FRMS_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_RXIPV4_HDRERR_FRMS register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_RXIPV4_HDRERR_FRMS_ADDR  ALT_EMAC_GMAC_RXIPV4_HDRERR_FRMS_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_RXIPV4_NOPAY_FRMS register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_RXIPV4_NOPAY_FRMS_ADDR  ALT_EMAC_GMAC_RXIPV4_NOPAY_FRMS_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_RXIPV4_FRAG_FRMS register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_RXIPV4_FRAG_FRMS_ADDR  ALT_EMAC_GMAC_RXIPV4_FRAG_FRMS_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_RXIPV4_UDSBL_FRMS register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_RXIPV4_UDSBL_FRMS_ADDR  ALT_EMAC_GMAC_RXIPV4_UDSBL_FRMS_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_RXIPV6_GD_FRMS register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_RXIPV6_GD_FRMS_ADDR  ALT_EMAC_GMAC_RXIPV6_GD_FRMS_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_RXIPV6_HDRERR_FRMS register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_RXIPV6_HDRERR_FRMS_ADDR  ALT_EMAC_GMAC_RXIPV6_HDRERR_FRMS_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_RXIPV6_NOPAY_FRMS register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_RXIPV6_NOPAY_FRMS_ADDR  ALT_EMAC_GMAC_RXIPV6_NOPAY_FRMS_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_RXUDP_GD_FRMS register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_RXUDP_GD_FRMS_ADDR  ALT_EMAC_GMAC_RXUDP_GD_FRMS_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_RXUDP_ERR_FRMS register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_RXUDP_ERR_FRMS_ADDR  ALT_EMAC_GMAC_RXUDP_ERR_FRMS_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_RXTCP_GD_FRMS register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_RXTCP_GD_FRMS_ADDR  ALT_EMAC_GMAC_RXTCP_GD_FRMS_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_RXTCP_ERR_FRMS register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_RXTCP_ERR_FRMS_ADDR  ALT_EMAC_GMAC_RXTCP_ERR_FRMS_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_RXICMP_GD_FRMS register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_RXICMP_GD_FRMS_ADDR  ALT_EMAC_GMAC_RXICMP_GD_FRMS_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_RXICMP_ERR_FRMS register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_RXICMP_ERR_FRMS_ADDR  ALT_EMAC_GMAC_RXICMP_ERR_FRMS_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_RXIPV4_GD_OCTETS register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_RXIPV4_GD_OCTETS_ADDR  ALT_EMAC_GMAC_RXIPV4_GD_OCTETS_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_RXIPV4_HDRERR_OCTETS register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_RXIPV4_HDRERR_OCTETS_ADDR  ALT_EMAC_GMAC_RXIPV4_HDRERR_OCTETS_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_RXIPV4_NOPAY_OCTETS register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_RXIPV4_NOPAY_OCTETS_ADDR  ALT_EMAC_GMAC_RXIPV4_NOPAY_OCTETS_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_RXIPV4_FRAG_OCTETS register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_RXIPV4_FRAG_OCTETS_ADDR  ALT_EMAC_GMAC_RXIPV4_FRAG_OCTETS_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_RXIPV4_UDSBL_OCTETS register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_RXIPV4_UDSBL_OCTETS_ADDR  ALT_EMAC_GMAC_RXIPV4_UDSBL_OCTETS_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_RXIPV6_GD_OCTETS register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_RXIPV6_GD_OCTETS_ADDR  ALT_EMAC_GMAC_RXIPV6_GD_OCTETS_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_RXIPV6_HDRERR_OCTETS register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_RXIPV6_HDRERR_OCTETS_ADDR  ALT_EMAC_GMAC_RXIPV6_HDRERR_OCTETS_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_RXIPV6_NOPAY_OCTETS register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_RXIPV6_NOPAY_OCTETS_ADDR  ALT_EMAC_GMAC_RXIPV6_NOPAY_OCTETS_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_RXUDP_GD_OCTETS register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_RXUDP_GD_OCTETS_ADDR  ALT_EMAC_GMAC_RXUDP_GD_OCTETS_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_RXUDP_ERR_OCTETS register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_RXUDP_ERR_OCTETS_ADDR  ALT_EMAC_GMAC_RXUDP_ERR_OCTETS_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_RXTCP_GD_OCTETS register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_RXTCP_GD_OCTETS_ADDR  ALT_EMAC_GMAC_RXTCP_GD_OCTETS_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_RXTCPERROCTETS register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_RXTCPERROCTETS_ADDR  ALT_EMAC_GMAC_RXTCPERROCTETS_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_RXICMP_GD_OCTETS register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_RXICMP_GD_OCTETS_ADDR  ALT_EMAC_GMAC_RXICMP_GD_OCTETS_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_RXICMP_ERR_OCTETS register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_RXICMP_ERR_OCTETS_ADDR  ALT_EMAC_GMAC_RXICMP_ERR_OCTETS_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_L3_L4_CTL0 register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_L3_L4_CTL0_ADDR  ALT_EMAC_GMAC_L3_L4_CTL0_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_LYR4_ADDR0 register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_LYR4_ADDR0_ADDR  ALT_EMAC_GMAC_LYR4_ADDR0_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_LYR3_ADDR0_REG0 register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_LYR3_ADDR0_REG0_ADDR  ALT_EMAC_GMAC_LYR3_ADDR0_REG0_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_LYR3_ADDR1_REG0 register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_LYR3_ADDR1_REG0_ADDR  ALT_EMAC_GMAC_LYR3_ADDR1_REG0_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_LYR3_ADDR2_REG0 register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_LYR3_ADDR2_REG0_ADDR  ALT_EMAC_GMAC_LYR3_ADDR2_REG0_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_LYR3_ADDR3_REG0 register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_LYR3_ADDR3_REG0_ADDR  ALT_EMAC_GMAC_LYR3_ADDR3_REG0_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_L3_L4_CTL1 register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_L3_L4_CTL1_ADDR  ALT_EMAC_GMAC_L3_L4_CTL1_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_LYR4_ADDR1 register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_LYR4_ADDR1_ADDR  ALT_EMAC_GMAC_LYR4_ADDR1_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_LYR3_ADDR0_REG1 register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_LYR3_ADDR0_REG1_ADDR  ALT_EMAC_GMAC_LYR3_ADDR0_REG1_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_LYR3_ADDR1_REG1 register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_LYR3_ADDR1_REG1_ADDR  ALT_EMAC_GMAC_LYR3_ADDR1_REG1_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_LYR3_ADDR2_REG1 register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_LYR3_ADDR2_REG1_ADDR  ALT_EMAC_GMAC_LYR3_ADDR2_REG1_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_LYR3_ADDR3_REG1 register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_LYR3_ADDR3_REG1_ADDR  ALT_EMAC_GMAC_LYR3_ADDR3_REG1_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_L3_L4_CTL2 register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_L3_L4_CTL2_ADDR  ALT_EMAC_GMAC_L3_L4_CTL2_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_LYR4_ADDR2 register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_LYR4_ADDR2_ADDR  ALT_EMAC_GMAC_LYR4_ADDR2_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_LYR3_ADDR0_REG2 register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_LYR3_ADDR0_REG2_ADDR  ALT_EMAC_GMAC_LYR3_ADDR0_REG2_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_LYR3_ADDR1_REG2 register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_LYR3_ADDR1_REG2_ADDR  ALT_EMAC_GMAC_LYR3_ADDR1_REG2_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_LYR3_ADDR2_REG2 register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_LYR3_ADDR2_REG2_ADDR  ALT_EMAC_GMAC_LYR3_ADDR2_REG2_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_LYR3_ADDR3_REG2 register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_LYR3_ADDR3_REG2_ADDR  ALT_EMAC_GMAC_LYR3_ADDR3_REG2_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_L3_L4_CTL3 register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_L3_L4_CTL3_ADDR  ALT_EMAC_GMAC_L3_L4_CTL3_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_LYR4_ADDR3 register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_LYR4_ADDR3_ADDR  ALT_EMAC_GMAC_LYR4_ADDR3_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_LYR3_ADDR0_REG3 register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_LYR3_ADDR0_REG3_ADDR  ALT_EMAC_GMAC_LYR3_ADDR0_REG3_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_LYR3_ADDR1_REG3 register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_LYR3_ADDR1_REG3_ADDR  ALT_EMAC_GMAC_LYR3_ADDR1_REG3_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_LYR3_ADDR2_REG3 register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_LYR3_ADDR2_REG3_ADDR  ALT_EMAC_GMAC_LYR3_ADDR2_REG3_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_LYR3_ADDR3_REG3 register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_LYR3_ADDR3_REG3_ADDR  ALT_EMAC_GMAC_LYR3_ADDR3_REG3_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_HASH_TABLE_REG0 register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_HASH_TABLE_REG0_ADDR  ALT_EMAC_GMAC_HASH_TABLE_REG0_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_HASH_TABLE_REG1 register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_HASH_TABLE_REG1_ADDR  ALT_EMAC_GMAC_HASH_TABLE_REG1_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_HASH_TABLE_REG2 register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_HASH_TABLE_REG2_ADDR  ALT_EMAC_GMAC_HASH_TABLE_REG2_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_HASH_TABLE_REG3 register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_HASH_TABLE_REG3_ADDR  ALT_EMAC_GMAC_HASH_TABLE_REG3_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_HASH_TABLE_REG4 register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_HASH_TABLE_REG4_ADDR  ALT_EMAC_GMAC_HASH_TABLE_REG4_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_HASH_TABLE_REG5 register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_HASH_TABLE_REG5_ADDR  ALT_EMAC_GMAC_HASH_TABLE_REG5_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_HASH_TABLE_REG6 register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_HASH_TABLE_REG6_ADDR  ALT_EMAC_GMAC_HASH_TABLE_REG6_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_HASH_TABLE_REG7 register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_HASH_TABLE_REG7_ADDR  ALT_EMAC_GMAC_HASH_TABLE_REG7_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_VLAN_INCL_REG register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_VLAN_INCL_REG_ADDR  ALT_EMAC_GMAC_VLAN_INCL_REG_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_VLAN_HASH_TABLE_REG register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_VLAN_HASH_TABLE_REG_ADDR  ALT_EMAC_GMAC_VLAN_HASH_TABLE_REG_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_TS_CTL register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_TS_CTL_ADDR  ALT_EMAC_GMAC_TS_CTL_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_SUB_SEC_INCREMENT register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_SUB_SEC_INCREMENT_ADDR  ALT_EMAC_GMAC_SUB_SEC_INCREMENT_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_SYS_TIME_SECS register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_SYS_TIME_SECS_ADDR  ALT_EMAC_GMAC_SYS_TIME_SECS_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_SYS_TIME_NANOSECS register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_SYS_TIME_NANOSECS_ADDR  ALT_EMAC_GMAC_SYS_TIME_NANOSECS_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_SYS_TIME_SECS_UPDATE register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_SYS_TIME_SECS_UPDATE_ADDR  ALT_EMAC_GMAC_SYS_TIME_SECS_UPDATE_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_SYS_TIME_NANOSECS_UPDATE register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_SYS_TIME_NANOSECS_UPDATE_ADDR  ALT_EMAC_GMAC_SYS_TIME_NANOSECS_UPDATE_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_TS_ADDEND register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_TS_ADDEND_ADDR  ALT_EMAC_GMAC_TS_ADDEND_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_TGT_TIME_SECS register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_TGT_TIME_SECS_ADDR  ALT_EMAC_GMAC_TGT_TIME_SECS_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_TGT_TIME_NANOSECS register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_TGT_TIME_NANOSECS_ADDR  ALT_EMAC_GMAC_TGT_TIME_NANOSECS_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_SYS_TIME_HIGHER_WORD_SECS register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_SYS_TIME_HIGHER_WORD_SECS_ADDR  ALT_EMAC_GMAC_SYS_TIME_HIGHER_WORD_SECS_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_TS_STAT register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_TS_STAT_ADDR  ALT_EMAC_GMAC_TS_STAT_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_PPS_CTL register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_PPS_CTL_ADDR  ALT_EMAC_GMAC_PPS_CTL_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_AUX_TS_NANOSECS register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_AUX_TS_NANOSECS_ADDR  ALT_EMAC_GMAC_AUX_TS_NANOSECS_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_AUX_TS_SECS register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_AUX_TS_SECS_ADDR  ALT_EMAC_GMAC_AUX_TS_SECS_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_PPS0_INTERVAL register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_PPS0_INTERVAL_ADDR  ALT_EMAC_GMAC_PPS0_INTERVAL_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_PPS0_WIDTH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_PPS0_WIDTH_ADDR  ALT_EMAC_GMAC_PPS0_WIDTH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR16_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR16_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR16_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR16_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR16_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR16_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR17_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR17_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR17_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR17_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR17_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR17_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR18_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR18_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR18_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR18_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR18_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR18_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR19_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR19_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR19_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR19_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR19_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR19_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR20_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR20_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR20_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR20_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR20_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR20_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR21_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR21_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR21_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR21_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR21_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR21_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR22_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR22_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR22_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR22_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR22_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR22_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR23_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR23_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR23_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR23_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR23_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR23_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR24_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR24_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR24_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR24_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR24_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR24_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR25_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR25_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR25_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR25_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR25_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR25_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR26_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR26_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR26_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR26_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR26_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR26_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR27_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR27_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR27_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR27_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR27_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR27_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR28_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR28_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR28_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR28_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR28_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR28_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR29_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR29_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR29_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR29_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR29_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR29_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR30_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR30_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR30_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR30_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR30_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR30_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR31_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR31_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR31_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR31_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR31_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR31_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR32_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR32_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR32_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR32_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR32_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR32_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR33_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR33_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR33_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR33_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR33_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR33_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR34_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR34_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR34_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR34_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR34_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR34_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR35_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR35_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR35_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR35_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR35_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR35_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR36_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR36_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR36_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR36_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR36_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR36_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR37_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR37_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR37_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR37_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR37_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR37_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR38_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR38_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR38_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR38_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR38_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR38_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR39_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR39_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR39_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR39_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR39_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR39_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR40_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR40_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR40_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR40_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR40_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR40_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR41_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR41_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR41_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR41_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR41_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR41_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR42_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR42_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR42_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR42_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR42_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR42_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR43_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR43_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR43_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR43_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR43_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR43_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR44_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR44_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR44_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR44_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR44_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR44_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR45_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR45_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR45_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR45_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR45_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR45_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR46_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR46_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR46_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR46_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR46_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR46_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR47_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR47_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR47_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR47_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR47_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR47_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR48_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR48_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR48_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR48_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR48_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR48_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR49_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR49_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR49_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR49_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR49_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR49_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR50_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR50_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR50_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR50_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR50_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR50_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR51_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR51_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR51_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR51_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR51_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR51_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR52_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR52_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR52_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR52_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR52_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR52_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR53_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR53_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR53_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR53_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR53_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR53_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR54_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR54_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR54_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR54_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR54_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR54_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR55_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR55_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR55_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR55_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR55_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR55_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR56_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR56_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR56_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR56_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR56_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR56_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR57_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR57_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR57_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR57_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR57_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR57_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR58_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR58_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR58_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR58_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR58_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR58_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR59_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR59_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR59_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR59_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR59_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR59_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR60_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR60_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR60_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR60_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR60_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR60_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR61_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR61_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR61_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR61_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR61_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR61_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR62_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR62_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR62_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR62_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR62_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR62_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR63_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR63_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR63_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR63_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR63_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR63_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR64_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR64_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR64_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR64_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR64_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR64_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR65_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR65_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR65_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR65_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR65_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR65_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR66_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR66_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR66_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR66_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR66_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR66_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR67_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR67_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR67_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR67_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR67_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR67_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR68_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR68_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR68_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR68_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR68_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR68_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR69_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR69_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR69_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR69_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR69_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR69_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR70_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR70_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR70_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR70_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR70_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR70_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR71_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR71_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR71_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR71_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR71_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR71_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR72_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR72_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR72_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR72_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR72_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR72_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR73_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR73_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR73_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR73_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR73_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR73_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR74_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR74_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR74_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR74_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR74_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR74_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR75_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR75_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR75_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR75_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR75_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR75_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR76_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR76_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR76_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR76_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR76_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR76_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR77_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR77_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR77_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR77_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR77_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR77_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR78_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR78_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR78_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR78_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR78_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR78_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR79_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR79_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR79_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR79_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR79_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR79_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR80_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR80_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR80_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR80_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR80_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR80_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR81_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR81_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR81_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR81_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR81_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR81_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR82_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR82_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR82_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR82_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR82_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR82_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR83_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR83_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR83_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR83_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR83_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR83_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR84_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR84_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR84_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR84_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR84_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR84_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR85_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR85_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR85_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR85_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR85_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR85_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR86_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR86_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR86_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR86_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR86_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR86_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR87_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR87_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR87_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR87_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR87_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR87_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR88_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR88_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR88_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR88_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR88_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR88_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR89_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR89_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR89_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR89_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR89_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR89_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR90_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR90_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR90_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR90_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR90_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR90_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR91_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR91_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR91_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR91_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR91_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR91_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR92_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR92_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR92_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR92_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR92_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR92_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR93_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR93_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR93_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR93_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR93_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR93_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR94_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR94_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR94_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR94_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR94_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR94_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR95_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR95_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR95_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR95_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR95_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR95_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR96_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR96_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR96_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR96_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR96_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR96_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR97_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR97_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR97_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR97_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR97_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR97_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR98_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR98_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR98_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR98_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR98_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR98_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR99_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR99_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR99_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR99_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR99_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR99_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR100_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR100_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR100_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR100_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR100_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR100_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR101_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR101_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR101_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR101_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR101_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR101_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR102_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR102_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR102_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR102_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR102_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR102_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR103_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR103_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR103_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR103_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR103_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR103_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR104_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR104_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR104_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR104_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR104_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR104_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR105_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR105_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR105_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR105_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR105_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR105_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR106_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR106_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR106_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR106_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR106_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR106_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR107_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR107_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR107_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR107_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR107_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR107_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR108_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR108_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR108_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR108_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR108_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR108_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR109_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR109_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR109_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR109_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR109_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR109_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR110_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR110_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR110_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR110_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR110_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR110_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR111_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR111_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR111_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR111_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR111_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR111_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR112_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR112_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR112_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR112_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR112_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR112_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR113_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR113_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR113_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR113_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR113_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR113_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR114_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR114_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR114_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR114_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR114_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR114_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR115_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR115_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR115_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR115_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR115_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR115_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR116_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR116_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR116_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR116_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR116_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR116_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR117_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR117_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR117_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR117_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR117_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR117_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR118_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR118_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR118_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR118_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR118_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR118_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR119_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR119_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR119_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR119_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR119_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR119_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR120_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR120_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR120_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR120_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR120_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR120_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR121_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR121_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR121_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR121_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR121_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR121_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR122_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR122_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR122_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR122_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR122_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR122_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR123_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR123_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR123_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR123_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR123_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR123_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR124_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR124_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR124_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR124_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR124_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR124_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR125_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR125_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR125_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR125_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR125_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR125_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR126_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR126_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR126_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR126_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR126_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR126_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR127_HIGH register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR127_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR127_HIGH_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR127_LOW register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_GMAC_MAC_ADDR127_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR127_LOW_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_DMA_BUS_MOD register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_DMA_BUS_MOD_ADDR  ALT_EMAC_DMA_BUS_MOD_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_DMA_TX_POLL_DEMAND register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_DMA_TX_POLL_DEMAND_ADDR  ALT_EMAC_DMA_TX_POLL_DEMAND_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_DMA_RX_POLL_DEMAND register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_DMA_RX_POLL_DEMAND_ADDR  ALT_EMAC_DMA_RX_POLL_DEMAND_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_DMA_RX_DESC_LIST_ADDR register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_DMA_RX_DESC_LIST_ADDR_ADDR  ALT_EMAC_DMA_RX_DESC_LIST_ADDR_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_DMA_TX_DESC_LIST_ADDR register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_DMA_TX_DESC_LIST_ADDR_ADDR  ALT_EMAC_DMA_TX_DESC_LIST_ADDR_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_DMA_STAT register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_DMA_STAT_ADDR  ALT_EMAC_DMA_STAT_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_DMA_OP_MOD register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_DMA_OP_MOD_ADDR  ALT_EMAC_DMA_OP_MOD_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_DMA_INT_EN register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_DMA_INT_EN_ADDR  ALT_EMAC_DMA_INT_EN_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_DMA_MFRM_BUF_OVF_CNTR register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_DMA_MISSED_FRM_AND_BUF_OVF_CNTR_ADDR  ALT_EMAC_DMA_MFRM_BUF_OVF_CNTR_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_DMA_RX_INT_WDT register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_DMA_RX_INT_WDT_ADDR  ALT_EMAC_DMA_RX_INT_WDT_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_DMA_AXI_BUS_MOD register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_DMA_AXI_BUS_MOD_ADDR  ALT_EMAC_DMA_AXI_BUS_MOD_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_DMA_AHB_OR_AXI_STAT register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_DMA_AHB_OR_AXI_STAT_ADDR  ALT_EMAC_DMA_AHB_OR_AXI_STAT_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_DMA_CUR_HOST_TX_DESC register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_DMA_CUR_HOST_TX_DESC_ADDR  ALT_EMAC_DMA_CUR_HOST_TX_DESC_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_DMA_CUR_HOST_RX_DESC register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_DMA_CUR_HOST_RX_DESC_ADDR  ALT_EMAC_DMA_CUR_HOST_RX_DESC_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_DMA_CUR_HOST_TX_BUF_ADDR register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_DMA_CUR_HOST_TX_BUF_ADDR_ADDR  ALT_EMAC_DMA_CUR_HOST_TX_BUF_ADDR_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_DMA_CUR_HOST_RX_BUF_ADDR register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_DMA_CUR_HOST_RX_BUF_ADDR_ADDR  ALT_EMAC_DMA_CUR_HOST_RX_BUF_ADDR_ADDR(ALT_EMAC0_ADDR)
/* The address of the ALT_EMAC_DMA_HW_FEATURE register for the ALT_EMAC0 instance. */
#define ALT_EMAC0_DMA_HW_FEATURE_ADDR  ALT_EMAC_DMA_HW_FEATURE_ADDR(ALT_EMAC0_ADDR)
/* The base address byte offset for the start of the ALT_EMAC0 component. */
#define ALT_EMAC0_OFST        0xff800000
/* The start address of the ALT_EMAC0 component. */
#define ALT_EMAC0_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_EMAC0_OFST))
/* The lower bound address range of the ALT_EMAC0 component. */
#define ALT_EMAC0_LB_ADDR     ALT_EMAC0_ADDR
/* The upper bound address range of the ALT_EMAC0 component. */
#define ALT_EMAC0_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_EMAC0_ADDR) + 0x105c) - 1))


/*
 * Component Instance : i_emac_emac1
 * 
 * Instance i_emac_emac1 of component ALT_EMAC.
 * 
 * 
 */
/* The address of the ALT_EMAC_GMAC_MAC_CFG register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_CFG_ADDR  ALT_EMAC_GMAC_MAC_CFG_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_FRM_FLT register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_FRM_FLT_ADDR  ALT_EMAC_GMAC_MAC_FRM_FLT_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_GMII_ADDR register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_GMII_ADDR_ADDR  ALT_EMAC_GMAC_GMII_ADDR_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_GMII_DATA register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_GMII_DATA_ADDR  ALT_EMAC_GMAC_GMII_DATA_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_FLOW_CTL register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_FLOW_CTL_ADDR  ALT_EMAC_GMAC_FLOW_CTL_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_VLAN_TAG register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_VLAN_TAG_ADDR  ALT_EMAC_GMAC_VLAN_TAG_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_VER register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_VER_ADDR  ALT_EMAC_GMAC_VER_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_DBG register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_DBG_ADDR  ALT_EMAC_GMAC_DBG_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_LPI_CTL_STAT register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_LPI_CTL_STAT_ADDR  ALT_EMAC_GMAC_LPI_CTL_STAT_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_LPI_TMRS_CTL register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_LPI_TMRS_CTL_ADDR  ALT_EMAC_GMAC_LPI_TMRS_CTL_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_INT_STAT register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_INT_STAT_ADDR  ALT_EMAC_GMAC_INT_STAT_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_INT_MSK register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_INT_MSK_ADDR  ALT_EMAC_GMAC_INT_MSK_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR0_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR0_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR0_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR0_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR0_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR0_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR1_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR1_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR1_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR1_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR1_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR1_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR2_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR2_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR2_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR2_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR2_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR2_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR3_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR3_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR3_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR3_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR3_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR3_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR4_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR4_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR4_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR4_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR4_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR4_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR5_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR5_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR5_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR5_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR5_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR5_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR6_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR6_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR6_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR6_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR6_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR6_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR7_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR7_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR7_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR7_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR7_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR7_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR8_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR8_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR8_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR8_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR8_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR8_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR9_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR9_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR9_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR9_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR9_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR9_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR10_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR10_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR10_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR10_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR10_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR10_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR11_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR11_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR11_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR11_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR11_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR11_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR12_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR12_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR12_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR12_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR12_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR12_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR13_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR13_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR13_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR13_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR13_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR13_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR14_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR14_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR14_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR14_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR14_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR14_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR15_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR15_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR15_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR15_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR15_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR15_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MII_CTL_STAT register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_SGMII_RGMII_SMII_CTL_STAT_ADDR  ALT_EMAC_GMAC_MII_CTL_STAT_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_WDOG_TMO register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_WDOG_TMO_ADDR  ALT_EMAC_GMAC_WDOG_TMO_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_GENPIO register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_GENPIO_ADDR  ALT_EMAC_GMAC_GENPIO_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MMC_CTL register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MMC_CTL_ADDR  ALT_EMAC_GMAC_MMC_CTL_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MMC_RX_INT register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MMC_RX_INT_ADDR  ALT_EMAC_GMAC_MMC_RX_INT_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MMC_TX_INT register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MMC_TX_INT_ADDR  ALT_EMAC_GMAC_MMC_TX_INT_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MMC_RX_INT_MSK register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MMC_RX_INT_MSK_ADDR  ALT_EMAC_GMAC_MMC_RX_INT_MSK_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MMC_TX_INT_MSK register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MMC_TX_INT_MSK_ADDR  ALT_EMAC_GMAC_MMC_TX_INT_MSK_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_TXOCTETCOUNT_GB register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_TXOCTETCOUNT_GB_ADDR  ALT_EMAC_GMAC_TXOCTETCOUNT_GB_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_TXFRMCOUNT_GB register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_TXFRMCOUNT_GB_ADDR  ALT_EMAC_GMAC_TXFRMCOUNT_GB_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_TXBCASTFRMS_G register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_TXBCASTFRMS_G_ADDR  ALT_EMAC_GMAC_TXBCASTFRMS_G_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_TXMCASTFRMS_G register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_TXMCASTFRMS_G_ADDR  ALT_EMAC_GMAC_TXMCASTFRMS_G_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_TX64OCTETS_GB register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_TX64OCTETS_GB_ADDR  ALT_EMAC_GMAC_TX64OCTETS_GB_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_TX65TO127OCTETS_GB register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_TX65TO127OCTETS_GB_ADDR  ALT_EMAC_GMAC_TX65TO127OCTETS_GB_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_TX128TO255OCTETS_GB register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_TX128TO255OCTETS_GB_ADDR  ALT_EMAC_GMAC_TX128TO255OCTETS_GB_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_TX256TO511OCTETS_GB register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_TX256TO511OCTETS_GB_ADDR  ALT_EMAC_GMAC_TX256TO511OCTETS_GB_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_TX512TO1023OCTETS_GB register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_TX512TO1023OCTETS_GB_ADDR  ALT_EMAC_GMAC_TX512TO1023OCTETS_GB_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_TX1024TOMAXOCTETS_GB register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_TX1024TOMAXOCTETS_GB_ADDR  ALT_EMAC_GMAC_TX1024TOMAXOCTETS_GB_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_TXUNICASTFRMS_GB register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_TXUNICASTFRMS_GB_ADDR  ALT_EMAC_GMAC_TXUNICASTFRMS_GB_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_TXMCASTFRMS_GB register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_TXMCASTFRMS_GB_ADDR  ALT_EMAC_GMAC_TXMCASTFRMS_GB_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_TXBCASTFRMS_GB register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_TXBCASTFRMS_GB_ADDR  ALT_EMAC_GMAC_TXBCASTFRMS_GB_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_TXUNDERFLOWERROR register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_TXUNDERFLOWERROR_ADDR  ALT_EMAC_GMAC_TXUNDERFLOWERROR_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_TXSINGLECOL_G register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_TXSINGLECOL_G_ADDR  ALT_EMAC_GMAC_TXSINGLECOL_G_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_TXMULTICOL_G register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_TXMULTICOL_G_ADDR  ALT_EMAC_GMAC_TXMULTICOL_G_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_TXDEFERRED register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_TXDEFERRED_ADDR  ALT_EMAC_GMAC_TXDEFERRED_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_TXLATECOL register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_TXLATECOL_ADDR  ALT_EMAC_GMAC_TXLATECOL_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_TXEXESSCOL register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_TXEXESSCOL_ADDR  ALT_EMAC_GMAC_TXEXESSCOL_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_TXCARRIERERR register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_TXCARRIERERR_ADDR  ALT_EMAC_GMAC_TXCARRIERERR_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_TXOCTETCNT register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_TXOCTETCNT_ADDR  ALT_EMAC_GMAC_TXOCTETCNT_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_TXFRMCOUNT_G register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_TXFRMCOUNT_G_ADDR  ALT_EMAC_GMAC_TXFRMCOUNT_G_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_TXEXCESSDEF register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_TXEXCESSDEF_ADDR  ALT_EMAC_GMAC_TXEXCESSDEF_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_TXPAUSEFRMS register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_TXPAUSEFRMS_ADDR  ALT_EMAC_GMAC_TXPAUSEFRMS_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_TXVLANFRMS_G register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_TXVLANFRMS_G_ADDR  ALT_EMAC_GMAC_TXVLANFRMS_G_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_TXOVERSIZE_G register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_TXOVERSIZE_G_ADDR  ALT_EMAC_GMAC_TXOVERSIZE_G_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_RXFRMCOUNT_GB register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_RXFRMCOUNT_GB_ADDR  ALT_EMAC_GMAC_RXFRMCOUNT_GB_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_RXOCTETCOUNT_GB register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_RXOCTETCOUNT_GB_ADDR  ALT_EMAC_GMAC_RXOCTETCOUNT_GB_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_RXOCTETCOUNT_G register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_RXOCTETCOUNT_G_ADDR  ALT_EMAC_GMAC_RXOCTETCOUNT_G_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_RXBCASTFRMS_G register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_RXBCASTFRMS_G_ADDR  ALT_EMAC_GMAC_RXBCASTFRMS_G_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_RXMCASTFRMS_G register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_RXMCASTFRMS_G_ADDR  ALT_EMAC_GMAC_RXMCASTFRMS_G_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_RXCRCERROR register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_RXCRCERROR_ADDR  ALT_EMAC_GMAC_RXCRCERROR_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_RXALIGNMENTERROR register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_RXALIGNMENTERROR_ADDR  ALT_EMAC_GMAC_RXALIGNMENTERROR_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_RXRUNTERROR register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_RXRUNTERROR_ADDR  ALT_EMAC_GMAC_RXRUNTERROR_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_RXJABBERERROR register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_RXJABBERERROR_ADDR  ALT_EMAC_GMAC_RXJABBERERROR_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_RXUNDERSIZE_G register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_RXUNDERSIZE_G_ADDR  ALT_EMAC_GMAC_RXUNDERSIZE_G_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_RXOVERSIZE_G register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_RXOVERSIZE_G_ADDR  ALT_EMAC_GMAC_RXOVERSIZE_G_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_RX64OCTETS_GB register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_RX64OCTETS_GB_ADDR  ALT_EMAC_GMAC_RX64OCTETS_GB_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_RX65TO127OCTETS_GB register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_RX65TO127OCTETS_GB_ADDR  ALT_EMAC_GMAC_RX65TO127OCTETS_GB_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_RX128TO255OCTETS_GB register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_RX128TO255OCTETS_GB_ADDR  ALT_EMAC_GMAC_RX128TO255OCTETS_GB_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_RX256TO511OCTETS_GB register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_RX256TO511OCTETS_GB_ADDR  ALT_EMAC_GMAC_RX256TO511OCTETS_GB_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_RX512TO1023OCTETS_GB register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_RX512TO1023OCTETS_GB_ADDR  ALT_EMAC_GMAC_RX512TO1023OCTETS_GB_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_RX1024TOMAXOCTETS_GB register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_RX1024TOMAXOCTETS_GB_ADDR  ALT_EMAC_GMAC_RX1024TOMAXOCTETS_GB_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_RXUNICASTFRMS_G register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_RXUNICASTFRMS_G_ADDR  ALT_EMAC_GMAC_RXUNICASTFRMS_G_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_RXLENERROR register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_RXLENERROR_ADDR  ALT_EMAC_GMAC_RXLENERROR_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_RXOUTOFRANGETYPE register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_RXOUTOFRANGETYPE_ADDR  ALT_EMAC_GMAC_RXOUTOFRANGETYPE_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_RXPAUSEFRMS register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_RXPAUSEFRMS_ADDR  ALT_EMAC_GMAC_RXPAUSEFRMS_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_RXFIFOOVF register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_RXFIFOOVF_ADDR  ALT_EMAC_GMAC_RXFIFOOVF_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_RXVLANFRMS_GB register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_RXVLANFRMS_GB_ADDR  ALT_EMAC_GMAC_RXVLANFRMS_GB_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_RXWDERROR register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_RXWDERROR_ADDR  ALT_EMAC_GMAC_RXWDERROR_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_RXRCVERROR register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_RXRCVERROR_ADDR  ALT_EMAC_GMAC_RXRCVERROR_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_RXCTLFRMS_G register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_RXCTLFRMS_G_ADDR  ALT_EMAC_GMAC_RXCTLFRMS_G_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MMC_IPC_RX_INT_MSK register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MMC_IPC_RX_INT_MSK_ADDR  ALT_EMAC_GMAC_MMC_IPC_RX_INT_MSK_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MMC_IPC_RX_INT register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MMC_IPC_RX_INT_ADDR  ALT_EMAC_GMAC_MMC_IPC_RX_INT_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_RXIPV4_GD_FRMS register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_RXIPV4_GD_FRMS_ADDR  ALT_EMAC_GMAC_RXIPV4_GD_FRMS_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_RXIPV4_HDRERR_FRMS register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_RXIPV4_HDRERR_FRMS_ADDR  ALT_EMAC_GMAC_RXIPV4_HDRERR_FRMS_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_RXIPV4_NOPAY_FRMS register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_RXIPV4_NOPAY_FRMS_ADDR  ALT_EMAC_GMAC_RXIPV4_NOPAY_FRMS_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_RXIPV4_FRAG_FRMS register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_RXIPV4_FRAG_FRMS_ADDR  ALT_EMAC_GMAC_RXIPV4_FRAG_FRMS_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_RXIPV4_UDSBL_FRMS register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_RXIPV4_UDSBL_FRMS_ADDR  ALT_EMAC_GMAC_RXIPV4_UDSBL_FRMS_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_RXIPV6_GD_FRMS register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_RXIPV6_GD_FRMS_ADDR  ALT_EMAC_GMAC_RXIPV6_GD_FRMS_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_RXIPV6_HDRERR_FRMS register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_RXIPV6_HDRERR_FRMS_ADDR  ALT_EMAC_GMAC_RXIPV6_HDRERR_FRMS_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_RXIPV6_NOPAY_FRMS register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_RXIPV6_NOPAY_FRMS_ADDR  ALT_EMAC_GMAC_RXIPV6_NOPAY_FRMS_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_RXUDP_GD_FRMS register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_RXUDP_GD_FRMS_ADDR  ALT_EMAC_GMAC_RXUDP_GD_FRMS_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_RXUDP_ERR_FRMS register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_RXUDP_ERR_FRMS_ADDR  ALT_EMAC_GMAC_RXUDP_ERR_FRMS_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_RXTCP_GD_FRMS register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_RXTCP_GD_FRMS_ADDR  ALT_EMAC_GMAC_RXTCP_GD_FRMS_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_RXTCP_ERR_FRMS register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_RXTCP_ERR_FRMS_ADDR  ALT_EMAC_GMAC_RXTCP_ERR_FRMS_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_RXICMP_GD_FRMS register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_RXICMP_GD_FRMS_ADDR  ALT_EMAC_GMAC_RXICMP_GD_FRMS_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_RXICMP_ERR_FRMS register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_RXICMP_ERR_FRMS_ADDR  ALT_EMAC_GMAC_RXICMP_ERR_FRMS_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_RXIPV4_GD_OCTETS register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_RXIPV4_GD_OCTETS_ADDR  ALT_EMAC_GMAC_RXIPV4_GD_OCTETS_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_RXIPV4_HDRERR_OCTETS register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_RXIPV4_HDRERR_OCTETS_ADDR  ALT_EMAC_GMAC_RXIPV4_HDRERR_OCTETS_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_RXIPV4_NOPAY_OCTETS register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_RXIPV4_NOPAY_OCTETS_ADDR  ALT_EMAC_GMAC_RXIPV4_NOPAY_OCTETS_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_RXIPV4_FRAG_OCTETS register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_RXIPV4_FRAG_OCTETS_ADDR  ALT_EMAC_GMAC_RXIPV4_FRAG_OCTETS_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_RXIPV4_UDSBL_OCTETS register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_RXIPV4_UDSBL_OCTETS_ADDR  ALT_EMAC_GMAC_RXIPV4_UDSBL_OCTETS_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_RXIPV6_GD_OCTETS register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_RXIPV6_GD_OCTETS_ADDR  ALT_EMAC_GMAC_RXIPV6_GD_OCTETS_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_RXIPV6_HDRERR_OCTETS register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_RXIPV6_HDRERR_OCTETS_ADDR  ALT_EMAC_GMAC_RXIPV6_HDRERR_OCTETS_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_RXIPV6_NOPAY_OCTETS register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_RXIPV6_NOPAY_OCTETS_ADDR  ALT_EMAC_GMAC_RXIPV6_NOPAY_OCTETS_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_RXUDP_GD_OCTETS register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_RXUDP_GD_OCTETS_ADDR  ALT_EMAC_GMAC_RXUDP_GD_OCTETS_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_RXUDP_ERR_OCTETS register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_RXUDP_ERR_OCTETS_ADDR  ALT_EMAC_GMAC_RXUDP_ERR_OCTETS_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_RXTCP_GD_OCTETS register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_RXTCP_GD_OCTETS_ADDR  ALT_EMAC_GMAC_RXTCP_GD_OCTETS_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_RXTCPERROCTETS register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_RXTCPERROCTETS_ADDR  ALT_EMAC_GMAC_RXTCPERROCTETS_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_RXICMP_GD_OCTETS register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_RXICMP_GD_OCTETS_ADDR  ALT_EMAC_GMAC_RXICMP_GD_OCTETS_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_RXICMP_ERR_OCTETS register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_RXICMP_ERR_OCTETS_ADDR  ALT_EMAC_GMAC_RXICMP_ERR_OCTETS_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_L3_L4_CTL0 register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_L3_L4_CTL0_ADDR  ALT_EMAC_GMAC_L3_L4_CTL0_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_LYR4_ADDR0 register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_LYR4_ADDR0_ADDR  ALT_EMAC_GMAC_LYR4_ADDR0_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_LYR3_ADDR0_REG0 register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_LYR3_ADDR0_REG0_ADDR  ALT_EMAC_GMAC_LYR3_ADDR0_REG0_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_LYR3_ADDR1_REG0 register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_LYR3_ADDR1_REG0_ADDR  ALT_EMAC_GMAC_LYR3_ADDR1_REG0_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_LYR3_ADDR2_REG0 register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_LYR3_ADDR2_REG0_ADDR  ALT_EMAC_GMAC_LYR3_ADDR2_REG0_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_LYR3_ADDR3_REG0 register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_LYR3_ADDR3_REG0_ADDR  ALT_EMAC_GMAC_LYR3_ADDR3_REG0_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_L3_L4_CTL1 register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_L3_L4_CTL1_ADDR  ALT_EMAC_GMAC_L3_L4_CTL1_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_LYR4_ADDR1 register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_LYR4_ADDR1_ADDR  ALT_EMAC_GMAC_LYR4_ADDR1_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_LYR3_ADDR0_REG1 register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_LYR3_ADDR0_REG1_ADDR  ALT_EMAC_GMAC_LYR3_ADDR0_REG1_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_LYR3_ADDR1_REG1 register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_LYR3_ADDR1_REG1_ADDR  ALT_EMAC_GMAC_LYR3_ADDR1_REG1_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_LYR3_ADDR2_REG1 register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_LYR3_ADDR2_REG1_ADDR  ALT_EMAC_GMAC_LYR3_ADDR2_REG1_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_LYR3_ADDR3_REG1 register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_LYR3_ADDR3_REG1_ADDR  ALT_EMAC_GMAC_LYR3_ADDR3_REG1_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_L3_L4_CTL2 register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_L3_L4_CTL2_ADDR  ALT_EMAC_GMAC_L3_L4_CTL2_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_LYR4_ADDR2 register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_LYR4_ADDR2_ADDR  ALT_EMAC_GMAC_LYR4_ADDR2_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_LYR3_ADDR0_REG2 register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_LYR3_ADDR0_REG2_ADDR  ALT_EMAC_GMAC_LYR3_ADDR0_REG2_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_LYR3_ADDR1_REG2 register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_LYR3_ADDR1_REG2_ADDR  ALT_EMAC_GMAC_LYR3_ADDR1_REG2_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_LYR3_ADDR2_REG2 register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_LYR3_ADDR2_REG2_ADDR  ALT_EMAC_GMAC_LYR3_ADDR2_REG2_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_LYR3_ADDR3_REG2 register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_LYR3_ADDR3_REG2_ADDR  ALT_EMAC_GMAC_LYR3_ADDR3_REG2_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_L3_L4_CTL3 register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_L3_L4_CTL3_ADDR  ALT_EMAC_GMAC_L3_L4_CTL3_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_LYR4_ADDR3 register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_LYR4_ADDR3_ADDR  ALT_EMAC_GMAC_LYR4_ADDR3_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_LYR3_ADDR0_REG3 register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_LYR3_ADDR0_REG3_ADDR  ALT_EMAC_GMAC_LYR3_ADDR0_REG3_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_LYR3_ADDR1_REG3 register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_LYR3_ADDR1_REG3_ADDR  ALT_EMAC_GMAC_LYR3_ADDR1_REG3_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_LYR3_ADDR2_REG3 register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_LYR3_ADDR2_REG3_ADDR  ALT_EMAC_GMAC_LYR3_ADDR2_REG3_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_LYR3_ADDR3_REG3 register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_LYR3_ADDR3_REG3_ADDR  ALT_EMAC_GMAC_LYR3_ADDR3_REG3_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_HASH_TABLE_REG0 register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_HASH_TABLE_REG0_ADDR  ALT_EMAC_GMAC_HASH_TABLE_REG0_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_HASH_TABLE_REG1 register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_HASH_TABLE_REG1_ADDR  ALT_EMAC_GMAC_HASH_TABLE_REG1_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_HASH_TABLE_REG2 register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_HASH_TABLE_REG2_ADDR  ALT_EMAC_GMAC_HASH_TABLE_REG2_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_HASH_TABLE_REG3 register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_HASH_TABLE_REG3_ADDR  ALT_EMAC_GMAC_HASH_TABLE_REG3_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_HASH_TABLE_REG4 register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_HASH_TABLE_REG4_ADDR  ALT_EMAC_GMAC_HASH_TABLE_REG4_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_HASH_TABLE_REG5 register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_HASH_TABLE_REG5_ADDR  ALT_EMAC_GMAC_HASH_TABLE_REG5_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_HASH_TABLE_REG6 register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_HASH_TABLE_REG6_ADDR  ALT_EMAC_GMAC_HASH_TABLE_REG6_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_HASH_TABLE_REG7 register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_HASH_TABLE_REG7_ADDR  ALT_EMAC_GMAC_HASH_TABLE_REG7_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_VLAN_INCL_REG register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_VLAN_INCL_REG_ADDR  ALT_EMAC_GMAC_VLAN_INCL_REG_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_VLAN_HASH_TABLE_REG register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_VLAN_HASH_TABLE_REG_ADDR  ALT_EMAC_GMAC_VLAN_HASH_TABLE_REG_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_TS_CTL register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_TS_CTL_ADDR  ALT_EMAC_GMAC_TS_CTL_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_SUB_SEC_INCREMENT register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_SUB_SEC_INCREMENT_ADDR  ALT_EMAC_GMAC_SUB_SEC_INCREMENT_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_SYS_TIME_SECS register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_SYS_TIME_SECS_ADDR  ALT_EMAC_GMAC_SYS_TIME_SECS_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_SYS_TIME_NANOSECS register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_SYS_TIME_NANOSECS_ADDR  ALT_EMAC_GMAC_SYS_TIME_NANOSECS_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_SYS_TIME_SECS_UPDATE register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_SYS_TIME_SECS_UPDATE_ADDR  ALT_EMAC_GMAC_SYS_TIME_SECS_UPDATE_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_SYS_TIME_NANOSECS_UPDATE register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_SYS_TIME_NANOSECS_UPDATE_ADDR  ALT_EMAC_GMAC_SYS_TIME_NANOSECS_UPDATE_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_TS_ADDEND register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_TS_ADDEND_ADDR  ALT_EMAC_GMAC_TS_ADDEND_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_TGT_TIME_SECS register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_TGT_TIME_SECS_ADDR  ALT_EMAC_GMAC_TGT_TIME_SECS_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_TGT_TIME_NANOSECS register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_TGT_TIME_NANOSECS_ADDR  ALT_EMAC_GMAC_TGT_TIME_NANOSECS_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_SYS_TIME_HIGHER_WORD_SECS register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_SYS_TIME_HIGHER_WORD_SECS_ADDR  ALT_EMAC_GMAC_SYS_TIME_HIGHER_WORD_SECS_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_TS_STAT register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_TS_STAT_ADDR  ALT_EMAC_GMAC_TS_STAT_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_PPS_CTL register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_PPS_CTL_ADDR  ALT_EMAC_GMAC_PPS_CTL_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_AUX_TS_NANOSECS register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_AUX_TS_NANOSECS_ADDR  ALT_EMAC_GMAC_AUX_TS_NANOSECS_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_AUX_TS_SECS register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_AUX_TS_SECS_ADDR  ALT_EMAC_GMAC_AUX_TS_SECS_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_PPS0_INTERVAL register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_PPS0_INTERVAL_ADDR  ALT_EMAC_GMAC_PPS0_INTERVAL_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_PPS0_WIDTH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_PPS0_WIDTH_ADDR  ALT_EMAC_GMAC_PPS0_WIDTH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR16_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR16_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR16_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR16_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR16_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR16_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR17_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR17_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR17_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR17_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR17_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR17_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR18_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR18_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR18_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR18_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR18_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR18_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR19_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR19_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR19_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR19_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR19_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR19_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR20_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR20_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR20_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR20_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR20_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR20_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR21_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR21_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR21_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR21_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR21_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR21_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR22_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR22_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR22_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR22_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR22_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR22_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR23_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR23_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR23_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR23_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR23_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR23_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR24_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR24_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR24_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR24_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR24_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR24_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR25_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR25_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR25_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR25_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR25_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR25_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR26_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR26_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR26_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR26_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR26_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR26_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR27_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR27_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR27_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR27_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR27_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR27_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR28_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR28_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR28_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR28_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR28_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR28_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR29_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR29_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR29_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR29_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR29_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR29_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR30_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR30_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR30_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR30_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR30_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR30_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR31_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR31_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR31_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR31_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR31_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR31_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR32_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR32_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR32_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR32_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR32_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR32_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR33_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR33_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR33_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR33_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR33_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR33_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR34_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR34_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR34_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR34_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR34_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR34_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR35_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR35_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR35_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR35_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR35_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR35_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR36_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR36_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR36_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR36_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR36_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR36_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR37_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR37_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR37_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR37_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR37_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR37_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR38_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR38_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR38_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR38_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR38_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR38_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR39_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR39_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR39_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR39_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR39_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR39_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR40_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR40_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR40_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR40_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR40_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR40_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR41_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR41_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR41_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR41_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR41_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR41_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR42_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR42_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR42_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR42_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR42_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR42_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR43_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR43_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR43_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR43_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR43_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR43_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR44_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR44_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR44_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR44_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR44_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR44_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR45_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR45_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR45_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR45_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR45_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR45_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR46_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR46_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR46_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR46_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR46_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR46_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR47_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR47_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR47_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR47_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR47_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR47_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR48_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR48_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR48_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR48_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR48_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR48_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR49_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR49_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR49_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR49_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR49_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR49_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR50_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR50_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR50_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR50_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR50_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR50_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR51_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR51_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR51_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR51_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR51_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR51_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR52_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR52_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR52_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR52_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR52_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR52_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR53_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR53_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR53_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR53_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR53_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR53_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR54_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR54_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR54_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR54_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR54_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR54_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR55_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR55_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR55_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR55_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR55_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR55_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR56_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR56_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR56_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR56_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR56_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR56_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR57_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR57_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR57_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR57_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR57_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR57_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR58_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR58_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR58_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR58_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR58_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR58_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR59_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR59_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR59_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR59_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR59_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR59_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR60_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR60_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR60_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR60_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR60_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR60_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR61_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR61_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR61_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR61_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR61_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR61_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR62_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR62_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR62_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR62_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR62_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR62_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR63_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR63_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR63_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR63_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR63_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR63_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR64_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR64_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR64_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR64_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR64_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR64_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR65_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR65_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR65_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR65_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR65_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR65_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR66_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR66_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR66_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR66_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR66_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR66_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR67_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR67_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR67_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR67_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR67_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR67_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR68_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR68_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR68_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR68_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR68_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR68_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR69_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR69_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR69_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR69_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR69_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR69_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR70_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR70_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR70_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR70_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR70_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR70_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR71_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR71_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR71_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR71_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR71_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR71_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR72_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR72_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR72_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR72_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR72_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR72_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR73_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR73_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR73_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR73_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR73_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR73_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR74_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR74_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR74_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR74_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR74_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR74_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR75_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR75_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR75_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR75_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR75_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR75_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR76_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR76_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR76_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR76_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR76_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR76_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR77_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR77_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR77_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR77_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR77_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR77_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR78_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR78_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR78_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR78_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR78_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR78_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR79_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR79_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR79_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR79_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR79_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR79_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR80_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR80_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR80_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR80_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR80_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR80_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR81_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR81_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR81_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR81_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR81_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR81_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR82_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR82_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR82_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR82_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR82_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR82_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR83_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR83_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR83_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR83_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR83_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR83_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR84_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR84_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR84_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR84_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR84_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR84_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR85_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR85_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR85_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR85_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR85_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR85_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR86_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR86_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR86_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR86_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR86_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR86_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR87_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR87_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR87_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR87_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR87_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR87_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR88_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR88_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR88_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR88_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR88_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR88_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR89_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR89_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR89_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR89_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR89_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR89_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR90_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR90_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR90_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR90_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR90_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR90_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR91_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR91_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR91_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR91_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR91_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR91_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR92_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR92_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR92_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR92_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR92_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR92_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR93_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR93_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR93_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR93_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR93_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR93_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR94_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR94_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR94_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR94_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR94_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR94_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR95_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR95_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR95_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR95_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR95_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR95_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR96_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR96_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR96_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR96_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR96_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR96_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR97_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR97_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR97_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR97_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR97_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR97_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR98_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR98_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR98_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR98_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR98_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR98_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR99_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR99_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR99_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR99_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR99_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR99_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR100_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR100_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR100_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR100_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR100_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR100_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR101_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR101_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR101_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR101_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR101_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR101_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR102_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR102_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR102_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR102_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR102_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR102_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR103_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR103_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR103_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR103_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR103_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR103_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR104_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR104_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR104_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR104_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR104_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR104_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR105_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR105_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR105_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR105_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR105_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR105_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR106_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR106_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR106_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR106_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR106_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR106_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR107_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR107_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR107_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR107_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR107_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR107_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR108_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR108_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR108_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR108_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR108_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR108_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR109_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR109_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR109_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR109_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR109_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR109_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR110_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR110_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR110_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR110_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR110_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR110_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR111_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR111_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR111_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR111_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR111_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR111_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR112_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR112_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR112_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR112_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR112_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR112_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR113_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR113_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR113_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR113_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR113_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR113_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR114_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR114_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR114_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR114_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR114_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR114_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR115_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR115_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR115_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR115_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR115_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR115_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR116_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR116_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR116_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR116_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR116_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR116_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR117_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR117_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR117_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR117_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR117_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR117_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR118_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR118_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR118_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR118_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR118_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR118_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR119_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR119_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR119_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR119_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR119_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR119_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR120_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR120_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR120_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR120_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR120_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR120_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR121_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR121_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR121_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR121_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR121_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR121_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR122_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR122_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR122_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR122_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR122_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR122_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR123_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR123_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR123_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR123_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR123_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR123_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR124_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR124_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR124_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR124_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR124_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR124_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR125_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR125_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR125_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR125_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR125_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR125_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR126_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR126_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR126_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR126_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR126_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR126_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR127_HIGH register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR127_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR127_HIGH_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR127_LOW register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_GMAC_MAC_ADDR127_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR127_LOW_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_DMA_BUS_MOD register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_DMA_BUS_MOD_ADDR  ALT_EMAC_DMA_BUS_MOD_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_DMA_TX_POLL_DEMAND register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_DMA_TX_POLL_DEMAND_ADDR  ALT_EMAC_DMA_TX_POLL_DEMAND_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_DMA_RX_POLL_DEMAND register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_DMA_RX_POLL_DEMAND_ADDR  ALT_EMAC_DMA_RX_POLL_DEMAND_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_DMA_RX_DESC_LIST_ADDR register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_DMA_RX_DESC_LIST_ADDR_ADDR  ALT_EMAC_DMA_RX_DESC_LIST_ADDR_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_DMA_TX_DESC_LIST_ADDR register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_DMA_TX_DESC_LIST_ADDR_ADDR  ALT_EMAC_DMA_TX_DESC_LIST_ADDR_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_DMA_STAT register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_DMA_STAT_ADDR  ALT_EMAC_DMA_STAT_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_DMA_OP_MOD register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_DMA_OP_MOD_ADDR  ALT_EMAC_DMA_OP_MOD_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_DMA_INT_EN register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_DMA_INT_EN_ADDR  ALT_EMAC_DMA_INT_EN_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_DMA_MFRM_BUF_OVF_CNTR register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_DMA_MISSED_FRM_AND_BUF_OVF_CNTR_ADDR  ALT_EMAC_DMA_MFRM_BUF_OVF_CNTR_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_DMA_RX_INT_WDT register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_DMA_RX_INT_WDT_ADDR  ALT_EMAC_DMA_RX_INT_WDT_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_DMA_AXI_BUS_MOD register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_DMA_AXI_BUS_MOD_ADDR  ALT_EMAC_DMA_AXI_BUS_MOD_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_DMA_AHB_OR_AXI_STAT register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_DMA_AHB_OR_AXI_STAT_ADDR  ALT_EMAC_DMA_AHB_OR_AXI_STAT_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_DMA_CUR_HOST_TX_DESC register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_DMA_CUR_HOST_TX_DESC_ADDR  ALT_EMAC_DMA_CUR_HOST_TX_DESC_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_DMA_CUR_HOST_RX_DESC register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_DMA_CUR_HOST_RX_DESC_ADDR  ALT_EMAC_DMA_CUR_HOST_RX_DESC_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_DMA_CUR_HOST_TX_BUF_ADDR register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_DMA_CUR_HOST_TX_BUF_ADDR_ADDR  ALT_EMAC_DMA_CUR_HOST_TX_BUF_ADDR_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_DMA_CUR_HOST_RX_BUF_ADDR register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_DMA_CUR_HOST_RX_BUF_ADDR_ADDR  ALT_EMAC_DMA_CUR_HOST_RX_BUF_ADDR_ADDR(ALT_EMAC1_ADDR)
/* The address of the ALT_EMAC_DMA_HW_FEATURE register for the ALT_EMAC1 instance. */
#define ALT_EMAC1_DMA_HW_FEATURE_ADDR  ALT_EMAC_DMA_HW_FEATURE_ADDR(ALT_EMAC1_ADDR)
/* The base address byte offset for the start of the ALT_EMAC1 component. */
#define ALT_EMAC1_OFST        0xff802000
/* The start address of the ALT_EMAC1 component. */
#define ALT_EMAC1_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_EMAC1_OFST))
/* The lower bound address range of the ALT_EMAC1 component. */
#define ALT_EMAC1_LB_ADDR     ALT_EMAC1_ADDR
/* The upper bound address range of the ALT_EMAC1 component. */
#define ALT_EMAC1_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_EMAC1_ADDR) + 0x105c) - 1))


/*
 * Component Instance : i_emac_emac2
 * 
 * Instance i_emac_emac2 of component ALT_EMAC.
 * 
 * 
 */
/* The address of the ALT_EMAC_GMAC_MAC_CFG register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_CFG_ADDR  ALT_EMAC_GMAC_MAC_CFG_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_FRM_FLT register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_FRM_FLT_ADDR  ALT_EMAC_GMAC_MAC_FRM_FLT_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_GMII_ADDR register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_GMII_ADDR_ADDR  ALT_EMAC_GMAC_GMII_ADDR_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_GMII_DATA register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_GMII_DATA_ADDR  ALT_EMAC_GMAC_GMII_DATA_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_FLOW_CTL register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_FLOW_CTL_ADDR  ALT_EMAC_GMAC_FLOW_CTL_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_VLAN_TAG register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_VLAN_TAG_ADDR  ALT_EMAC_GMAC_VLAN_TAG_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_VER register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_VER_ADDR  ALT_EMAC_GMAC_VER_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_DBG register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_DBG_ADDR  ALT_EMAC_GMAC_DBG_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_LPI_CTL_STAT register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_LPI_CTL_STAT_ADDR  ALT_EMAC_GMAC_LPI_CTL_STAT_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_LPI_TMRS_CTL register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_LPI_TMRS_CTL_ADDR  ALT_EMAC_GMAC_LPI_TMRS_CTL_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_INT_STAT register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_INT_STAT_ADDR  ALT_EMAC_GMAC_INT_STAT_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_INT_MSK register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_INT_MSK_ADDR  ALT_EMAC_GMAC_INT_MSK_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR0_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR0_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR0_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR0_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR0_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR0_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR1_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR1_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR1_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR1_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR1_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR1_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR2_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR2_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR2_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR2_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR2_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR2_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR3_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR3_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR3_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR3_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR3_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR3_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR4_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR4_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR4_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR4_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR4_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR4_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR5_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR5_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR5_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR5_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR5_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR5_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR6_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR6_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR6_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR6_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR6_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR6_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR7_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR7_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR7_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR7_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR7_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR7_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR8_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR8_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR8_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR8_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR8_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR8_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR9_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR9_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR9_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR9_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR9_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR9_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR10_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR10_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR10_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR10_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR10_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR10_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR11_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR11_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR11_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR11_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR11_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR11_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR12_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR12_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR12_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR12_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR12_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR12_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR13_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR13_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR13_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR13_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR13_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR13_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR14_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR14_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR14_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR14_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR14_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR14_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR15_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR15_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR15_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR15_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR15_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR15_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MII_CTL_STAT register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_SGMII_RGMII_SMII_CTL_STAT_ADDR  ALT_EMAC_GMAC_MII_CTL_STAT_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_WDOG_TMO register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_WDOG_TMO_ADDR  ALT_EMAC_GMAC_WDOG_TMO_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_GENPIO register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_GENPIO_ADDR  ALT_EMAC_GMAC_GENPIO_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MMC_CTL register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MMC_CTL_ADDR  ALT_EMAC_GMAC_MMC_CTL_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MMC_RX_INT register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MMC_RX_INT_ADDR  ALT_EMAC_GMAC_MMC_RX_INT_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MMC_TX_INT register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MMC_TX_INT_ADDR  ALT_EMAC_GMAC_MMC_TX_INT_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MMC_RX_INT_MSK register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MMC_RX_INT_MSK_ADDR  ALT_EMAC_GMAC_MMC_RX_INT_MSK_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MMC_TX_INT_MSK register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MMC_TX_INT_MSK_ADDR  ALT_EMAC_GMAC_MMC_TX_INT_MSK_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_TXOCTETCOUNT_GB register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_TXOCTETCOUNT_GB_ADDR  ALT_EMAC_GMAC_TXOCTETCOUNT_GB_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_TXFRMCOUNT_GB register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_TXFRMCOUNT_GB_ADDR  ALT_EMAC_GMAC_TXFRMCOUNT_GB_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_TXBCASTFRMS_G register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_TXBCASTFRMS_G_ADDR  ALT_EMAC_GMAC_TXBCASTFRMS_G_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_TXMCASTFRMS_G register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_TXMCASTFRMS_G_ADDR  ALT_EMAC_GMAC_TXMCASTFRMS_G_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_TX64OCTETS_GB register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_TX64OCTETS_GB_ADDR  ALT_EMAC_GMAC_TX64OCTETS_GB_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_TX65TO127OCTETS_GB register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_TX65TO127OCTETS_GB_ADDR  ALT_EMAC_GMAC_TX65TO127OCTETS_GB_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_TX128TO255OCTETS_GB register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_TX128TO255OCTETS_GB_ADDR  ALT_EMAC_GMAC_TX128TO255OCTETS_GB_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_TX256TO511OCTETS_GB register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_TX256TO511OCTETS_GB_ADDR  ALT_EMAC_GMAC_TX256TO511OCTETS_GB_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_TX512TO1023OCTETS_GB register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_TX512TO1023OCTETS_GB_ADDR  ALT_EMAC_GMAC_TX512TO1023OCTETS_GB_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_TX1024TOMAXOCTETS_GB register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_TX1024TOMAXOCTETS_GB_ADDR  ALT_EMAC_GMAC_TX1024TOMAXOCTETS_GB_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_TXUNICASTFRMS_GB register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_TXUNICASTFRMS_GB_ADDR  ALT_EMAC_GMAC_TXUNICASTFRMS_GB_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_TXMCASTFRMS_GB register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_TXMCASTFRMS_GB_ADDR  ALT_EMAC_GMAC_TXMCASTFRMS_GB_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_TXBCASTFRMS_GB register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_TXBCASTFRMS_GB_ADDR  ALT_EMAC_GMAC_TXBCASTFRMS_GB_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_TXUNDERFLOWERROR register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_TXUNDERFLOWERROR_ADDR  ALT_EMAC_GMAC_TXUNDERFLOWERROR_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_TXSINGLECOL_G register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_TXSINGLECOL_G_ADDR  ALT_EMAC_GMAC_TXSINGLECOL_G_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_TXMULTICOL_G register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_TXMULTICOL_G_ADDR  ALT_EMAC_GMAC_TXMULTICOL_G_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_TXDEFERRED register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_TXDEFERRED_ADDR  ALT_EMAC_GMAC_TXDEFERRED_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_TXLATECOL register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_TXLATECOL_ADDR  ALT_EMAC_GMAC_TXLATECOL_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_TXEXESSCOL register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_TXEXESSCOL_ADDR  ALT_EMAC_GMAC_TXEXESSCOL_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_TXCARRIERERR register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_TXCARRIERERR_ADDR  ALT_EMAC_GMAC_TXCARRIERERR_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_TXOCTETCNT register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_TXOCTETCNT_ADDR  ALT_EMAC_GMAC_TXOCTETCNT_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_TXFRMCOUNT_G register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_TXFRMCOUNT_G_ADDR  ALT_EMAC_GMAC_TXFRMCOUNT_G_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_TXEXCESSDEF register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_TXEXCESSDEF_ADDR  ALT_EMAC_GMAC_TXEXCESSDEF_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_TXPAUSEFRMS register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_TXPAUSEFRMS_ADDR  ALT_EMAC_GMAC_TXPAUSEFRMS_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_TXVLANFRMS_G register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_TXVLANFRMS_G_ADDR  ALT_EMAC_GMAC_TXVLANFRMS_G_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_TXOVERSIZE_G register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_TXOVERSIZE_G_ADDR  ALT_EMAC_GMAC_TXOVERSIZE_G_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_RXFRMCOUNT_GB register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_RXFRMCOUNT_GB_ADDR  ALT_EMAC_GMAC_RXFRMCOUNT_GB_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_RXOCTETCOUNT_GB register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_RXOCTETCOUNT_GB_ADDR  ALT_EMAC_GMAC_RXOCTETCOUNT_GB_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_RXOCTETCOUNT_G register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_RXOCTETCOUNT_G_ADDR  ALT_EMAC_GMAC_RXOCTETCOUNT_G_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_RXBCASTFRMS_G register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_RXBCASTFRMS_G_ADDR  ALT_EMAC_GMAC_RXBCASTFRMS_G_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_RXMCASTFRMS_G register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_RXMCASTFRMS_G_ADDR  ALT_EMAC_GMAC_RXMCASTFRMS_G_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_RXCRCERROR register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_RXCRCERROR_ADDR  ALT_EMAC_GMAC_RXCRCERROR_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_RXALIGNMENTERROR register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_RXALIGNMENTERROR_ADDR  ALT_EMAC_GMAC_RXALIGNMENTERROR_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_RXRUNTERROR register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_RXRUNTERROR_ADDR  ALT_EMAC_GMAC_RXRUNTERROR_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_RXJABBERERROR register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_RXJABBERERROR_ADDR  ALT_EMAC_GMAC_RXJABBERERROR_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_RXUNDERSIZE_G register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_RXUNDERSIZE_G_ADDR  ALT_EMAC_GMAC_RXUNDERSIZE_G_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_RXOVERSIZE_G register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_RXOVERSIZE_G_ADDR  ALT_EMAC_GMAC_RXOVERSIZE_G_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_RX64OCTETS_GB register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_RX64OCTETS_GB_ADDR  ALT_EMAC_GMAC_RX64OCTETS_GB_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_RX65TO127OCTETS_GB register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_RX65TO127OCTETS_GB_ADDR  ALT_EMAC_GMAC_RX65TO127OCTETS_GB_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_RX128TO255OCTETS_GB register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_RX128TO255OCTETS_GB_ADDR  ALT_EMAC_GMAC_RX128TO255OCTETS_GB_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_RX256TO511OCTETS_GB register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_RX256TO511OCTETS_GB_ADDR  ALT_EMAC_GMAC_RX256TO511OCTETS_GB_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_RX512TO1023OCTETS_GB register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_RX512TO1023OCTETS_GB_ADDR  ALT_EMAC_GMAC_RX512TO1023OCTETS_GB_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_RX1024TOMAXOCTETS_GB register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_RX1024TOMAXOCTETS_GB_ADDR  ALT_EMAC_GMAC_RX1024TOMAXOCTETS_GB_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_RXUNICASTFRMS_G register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_RXUNICASTFRMS_G_ADDR  ALT_EMAC_GMAC_RXUNICASTFRMS_G_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_RXLENERROR register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_RXLENERROR_ADDR  ALT_EMAC_GMAC_RXLENERROR_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_RXOUTOFRANGETYPE register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_RXOUTOFRANGETYPE_ADDR  ALT_EMAC_GMAC_RXOUTOFRANGETYPE_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_RXPAUSEFRMS register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_RXPAUSEFRMS_ADDR  ALT_EMAC_GMAC_RXPAUSEFRMS_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_RXFIFOOVF register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_RXFIFOOVF_ADDR  ALT_EMAC_GMAC_RXFIFOOVF_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_RXVLANFRMS_GB register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_RXVLANFRMS_GB_ADDR  ALT_EMAC_GMAC_RXVLANFRMS_GB_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_RXWDERROR register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_RXWDERROR_ADDR  ALT_EMAC_GMAC_RXWDERROR_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_RXRCVERROR register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_RXRCVERROR_ADDR  ALT_EMAC_GMAC_RXRCVERROR_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_RXCTLFRMS_G register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_RXCTLFRMS_G_ADDR  ALT_EMAC_GMAC_RXCTLFRMS_G_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MMC_IPC_RX_INT_MSK register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MMC_IPC_RX_INT_MSK_ADDR  ALT_EMAC_GMAC_MMC_IPC_RX_INT_MSK_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MMC_IPC_RX_INT register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MMC_IPC_RX_INT_ADDR  ALT_EMAC_GMAC_MMC_IPC_RX_INT_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_RXIPV4_GD_FRMS register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_RXIPV4_GD_FRMS_ADDR  ALT_EMAC_GMAC_RXIPV4_GD_FRMS_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_RXIPV4_HDRERR_FRMS register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_RXIPV4_HDRERR_FRMS_ADDR  ALT_EMAC_GMAC_RXIPV4_HDRERR_FRMS_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_RXIPV4_NOPAY_FRMS register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_RXIPV4_NOPAY_FRMS_ADDR  ALT_EMAC_GMAC_RXIPV4_NOPAY_FRMS_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_RXIPV4_FRAG_FRMS register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_RXIPV4_FRAG_FRMS_ADDR  ALT_EMAC_GMAC_RXIPV4_FRAG_FRMS_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_RXIPV4_UDSBL_FRMS register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_RXIPV4_UDSBL_FRMS_ADDR  ALT_EMAC_GMAC_RXIPV4_UDSBL_FRMS_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_RXIPV6_GD_FRMS register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_RXIPV6_GD_FRMS_ADDR  ALT_EMAC_GMAC_RXIPV6_GD_FRMS_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_RXIPV6_HDRERR_FRMS register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_RXIPV6_HDRERR_FRMS_ADDR  ALT_EMAC_GMAC_RXIPV6_HDRERR_FRMS_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_RXIPV6_NOPAY_FRMS register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_RXIPV6_NOPAY_FRMS_ADDR  ALT_EMAC_GMAC_RXIPV6_NOPAY_FRMS_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_RXUDP_GD_FRMS register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_RXUDP_GD_FRMS_ADDR  ALT_EMAC_GMAC_RXUDP_GD_FRMS_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_RXUDP_ERR_FRMS register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_RXUDP_ERR_FRMS_ADDR  ALT_EMAC_GMAC_RXUDP_ERR_FRMS_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_RXTCP_GD_FRMS register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_RXTCP_GD_FRMS_ADDR  ALT_EMAC_GMAC_RXTCP_GD_FRMS_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_RXTCP_ERR_FRMS register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_RXTCP_ERR_FRMS_ADDR  ALT_EMAC_GMAC_RXTCP_ERR_FRMS_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_RXICMP_GD_FRMS register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_RXICMP_GD_FRMS_ADDR  ALT_EMAC_GMAC_RXICMP_GD_FRMS_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_RXICMP_ERR_FRMS register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_RXICMP_ERR_FRMS_ADDR  ALT_EMAC_GMAC_RXICMP_ERR_FRMS_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_RXIPV4_GD_OCTETS register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_RXIPV4_GD_OCTETS_ADDR  ALT_EMAC_GMAC_RXIPV4_GD_OCTETS_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_RXIPV4_HDRERR_OCTETS register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_RXIPV4_HDRERR_OCTETS_ADDR  ALT_EMAC_GMAC_RXIPV4_HDRERR_OCTETS_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_RXIPV4_NOPAY_OCTETS register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_RXIPV4_NOPAY_OCTETS_ADDR  ALT_EMAC_GMAC_RXIPV4_NOPAY_OCTETS_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_RXIPV4_FRAG_OCTETS register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_RXIPV4_FRAG_OCTETS_ADDR  ALT_EMAC_GMAC_RXIPV4_FRAG_OCTETS_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_RXIPV4_UDSBL_OCTETS register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_RXIPV4_UDSBL_OCTETS_ADDR  ALT_EMAC_GMAC_RXIPV4_UDSBL_OCTETS_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_RXIPV6_GD_OCTETS register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_RXIPV6_GD_OCTETS_ADDR  ALT_EMAC_GMAC_RXIPV6_GD_OCTETS_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_RXIPV6_HDRERR_OCTETS register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_RXIPV6_HDRERR_OCTETS_ADDR  ALT_EMAC_GMAC_RXIPV6_HDRERR_OCTETS_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_RXIPV6_NOPAY_OCTETS register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_RXIPV6_NOPAY_OCTETS_ADDR  ALT_EMAC_GMAC_RXIPV6_NOPAY_OCTETS_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_RXUDP_GD_OCTETS register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_RXUDP_GD_OCTETS_ADDR  ALT_EMAC_GMAC_RXUDP_GD_OCTETS_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_RXUDP_ERR_OCTETS register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_RXUDP_ERR_OCTETS_ADDR  ALT_EMAC_GMAC_RXUDP_ERR_OCTETS_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_RXTCP_GD_OCTETS register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_RXTCP_GD_OCTETS_ADDR  ALT_EMAC_GMAC_RXTCP_GD_OCTETS_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_RXTCPERROCTETS register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_RXTCPERROCTETS_ADDR  ALT_EMAC_GMAC_RXTCPERROCTETS_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_RXICMP_GD_OCTETS register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_RXICMP_GD_OCTETS_ADDR  ALT_EMAC_GMAC_RXICMP_GD_OCTETS_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_RXICMP_ERR_OCTETS register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_RXICMP_ERR_OCTETS_ADDR  ALT_EMAC_GMAC_RXICMP_ERR_OCTETS_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_L3_L4_CTL0 register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_L3_L4_CTL0_ADDR  ALT_EMAC_GMAC_L3_L4_CTL0_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_LYR4_ADDR0 register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_LYR4_ADDR0_ADDR  ALT_EMAC_GMAC_LYR4_ADDR0_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_LYR3_ADDR0_REG0 register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_LYR3_ADDR0_REG0_ADDR  ALT_EMAC_GMAC_LYR3_ADDR0_REG0_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_LYR3_ADDR1_REG0 register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_LYR3_ADDR1_REG0_ADDR  ALT_EMAC_GMAC_LYR3_ADDR1_REG0_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_LYR3_ADDR2_REG0 register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_LYR3_ADDR2_REG0_ADDR  ALT_EMAC_GMAC_LYR3_ADDR2_REG0_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_LYR3_ADDR3_REG0 register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_LYR3_ADDR3_REG0_ADDR  ALT_EMAC_GMAC_LYR3_ADDR3_REG0_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_L3_L4_CTL1 register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_L3_L4_CTL1_ADDR  ALT_EMAC_GMAC_L3_L4_CTL1_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_LYR4_ADDR1 register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_LYR4_ADDR1_ADDR  ALT_EMAC_GMAC_LYR4_ADDR1_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_LYR3_ADDR0_REG1 register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_LYR3_ADDR0_REG1_ADDR  ALT_EMAC_GMAC_LYR3_ADDR0_REG1_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_LYR3_ADDR1_REG1 register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_LYR3_ADDR1_REG1_ADDR  ALT_EMAC_GMAC_LYR3_ADDR1_REG1_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_LYR3_ADDR2_REG1 register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_LYR3_ADDR2_REG1_ADDR  ALT_EMAC_GMAC_LYR3_ADDR2_REG1_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_LYR3_ADDR3_REG1 register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_LYR3_ADDR3_REG1_ADDR  ALT_EMAC_GMAC_LYR3_ADDR3_REG1_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_L3_L4_CTL2 register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_L3_L4_CTL2_ADDR  ALT_EMAC_GMAC_L3_L4_CTL2_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_LYR4_ADDR2 register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_LYR4_ADDR2_ADDR  ALT_EMAC_GMAC_LYR4_ADDR2_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_LYR3_ADDR0_REG2 register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_LYR3_ADDR0_REG2_ADDR  ALT_EMAC_GMAC_LYR3_ADDR0_REG2_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_LYR3_ADDR1_REG2 register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_LYR3_ADDR1_REG2_ADDR  ALT_EMAC_GMAC_LYR3_ADDR1_REG2_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_LYR3_ADDR2_REG2 register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_LYR3_ADDR2_REG2_ADDR  ALT_EMAC_GMAC_LYR3_ADDR2_REG2_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_LYR3_ADDR3_REG2 register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_LYR3_ADDR3_REG2_ADDR  ALT_EMAC_GMAC_LYR3_ADDR3_REG2_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_L3_L4_CTL3 register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_L3_L4_CTL3_ADDR  ALT_EMAC_GMAC_L3_L4_CTL3_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_LYR4_ADDR3 register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_LYR4_ADDR3_ADDR  ALT_EMAC_GMAC_LYR4_ADDR3_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_LYR3_ADDR0_REG3 register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_LYR3_ADDR0_REG3_ADDR  ALT_EMAC_GMAC_LYR3_ADDR0_REG3_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_LYR3_ADDR1_REG3 register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_LYR3_ADDR1_REG3_ADDR  ALT_EMAC_GMAC_LYR3_ADDR1_REG3_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_LYR3_ADDR2_REG3 register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_LYR3_ADDR2_REG3_ADDR  ALT_EMAC_GMAC_LYR3_ADDR2_REG3_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_LYR3_ADDR3_REG3 register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_LYR3_ADDR3_REG3_ADDR  ALT_EMAC_GMAC_LYR3_ADDR3_REG3_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_HASH_TABLE_REG0 register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_HASH_TABLE_REG0_ADDR  ALT_EMAC_GMAC_HASH_TABLE_REG0_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_HASH_TABLE_REG1 register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_HASH_TABLE_REG1_ADDR  ALT_EMAC_GMAC_HASH_TABLE_REG1_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_HASH_TABLE_REG2 register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_HASH_TABLE_REG2_ADDR  ALT_EMAC_GMAC_HASH_TABLE_REG2_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_HASH_TABLE_REG3 register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_HASH_TABLE_REG3_ADDR  ALT_EMAC_GMAC_HASH_TABLE_REG3_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_HASH_TABLE_REG4 register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_HASH_TABLE_REG4_ADDR  ALT_EMAC_GMAC_HASH_TABLE_REG4_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_HASH_TABLE_REG5 register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_HASH_TABLE_REG5_ADDR  ALT_EMAC_GMAC_HASH_TABLE_REG5_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_HASH_TABLE_REG6 register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_HASH_TABLE_REG6_ADDR  ALT_EMAC_GMAC_HASH_TABLE_REG6_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_HASH_TABLE_REG7 register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_HASH_TABLE_REG7_ADDR  ALT_EMAC_GMAC_HASH_TABLE_REG7_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_VLAN_INCL_REG register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_VLAN_INCL_REG_ADDR  ALT_EMAC_GMAC_VLAN_INCL_REG_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_VLAN_HASH_TABLE_REG register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_VLAN_HASH_TABLE_REG_ADDR  ALT_EMAC_GMAC_VLAN_HASH_TABLE_REG_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_TS_CTL register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_TS_CTL_ADDR  ALT_EMAC_GMAC_TS_CTL_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_SUB_SEC_INCREMENT register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_SUB_SEC_INCREMENT_ADDR  ALT_EMAC_GMAC_SUB_SEC_INCREMENT_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_SYS_TIME_SECS register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_SYS_TIME_SECS_ADDR  ALT_EMAC_GMAC_SYS_TIME_SECS_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_SYS_TIME_NANOSECS register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_SYS_TIME_NANOSECS_ADDR  ALT_EMAC_GMAC_SYS_TIME_NANOSECS_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_SYS_TIME_SECS_UPDATE register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_SYS_TIME_SECS_UPDATE_ADDR  ALT_EMAC_GMAC_SYS_TIME_SECS_UPDATE_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_SYS_TIME_NANOSECS_UPDATE register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_SYS_TIME_NANOSECS_UPDATE_ADDR  ALT_EMAC_GMAC_SYS_TIME_NANOSECS_UPDATE_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_TS_ADDEND register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_TS_ADDEND_ADDR  ALT_EMAC_GMAC_TS_ADDEND_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_TGT_TIME_SECS register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_TGT_TIME_SECS_ADDR  ALT_EMAC_GMAC_TGT_TIME_SECS_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_TGT_TIME_NANOSECS register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_TGT_TIME_NANOSECS_ADDR  ALT_EMAC_GMAC_TGT_TIME_NANOSECS_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_SYS_TIME_HIGHER_WORD_SECS register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_SYS_TIME_HIGHER_WORD_SECS_ADDR  ALT_EMAC_GMAC_SYS_TIME_HIGHER_WORD_SECS_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_TS_STAT register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_TS_STAT_ADDR  ALT_EMAC_GMAC_TS_STAT_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_PPS_CTL register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_PPS_CTL_ADDR  ALT_EMAC_GMAC_PPS_CTL_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_AUX_TS_NANOSECS register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_AUX_TS_NANOSECS_ADDR  ALT_EMAC_GMAC_AUX_TS_NANOSECS_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_AUX_TS_SECS register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_AUX_TS_SECS_ADDR  ALT_EMAC_GMAC_AUX_TS_SECS_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_PPS0_INTERVAL register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_PPS0_INTERVAL_ADDR  ALT_EMAC_GMAC_PPS0_INTERVAL_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_PPS0_WIDTH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_PPS0_WIDTH_ADDR  ALT_EMAC_GMAC_PPS0_WIDTH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR16_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR16_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR16_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR16_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR16_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR16_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR17_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR17_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR17_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR17_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR17_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR17_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR18_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR18_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR18_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR18_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR18_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR18_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR19_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR19_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR19_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR19_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR19_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR19_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR20_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR20_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR20_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR20_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR20_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR20_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR21_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR21_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR21_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR21_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR21_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR21_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR22_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR22_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR22_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR22_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR22_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR22_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR23_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR23_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR23_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR23_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR23_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR23_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR24_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR24_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR24_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR24_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR24_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR24_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR25_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR25_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR25_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR25_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR25_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR25_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR26_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR26_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR26_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR26_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR26_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR26_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR27_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR27_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR27_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR27_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR27_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR27_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR28_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR28_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR28_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR28_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR28_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR28_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR29_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR29_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR29_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR29_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR29_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR29_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR30_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR30_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR30_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR30_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR30_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR30_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR31_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR31_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR31_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR31_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR31_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR31_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR32_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR32_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR32_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR32_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR32_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR32_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR33_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR33_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR33_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR33_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR33_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR33_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR34_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR34_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR34_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR34_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR34_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR34_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR35_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR35_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR35_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR35_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR35_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR35_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR36_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR36_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR36_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR36_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR36_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR36_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR37_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR37_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR37_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR37_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR37_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR37_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR38_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR38_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR38_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR38_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR38_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR38_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR39_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR39_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR39_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR39_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR39_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR39_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR40_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR40_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR40_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR40_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR40_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR40_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR41_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR41_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR41_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR41_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR41_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR41_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR42_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR42_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR42_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR42_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR42_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR42_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR43_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR43_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR43_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR43_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR43_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR43_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR44_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR44_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR44_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR44_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR44_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR44_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR45_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR45_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR45_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR45_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR45_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR45_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR46_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR46_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR46_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR46_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR46_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR46_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR47_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR47_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR47_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR47_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR47_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR47_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR48_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR48_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR48_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR48_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR48_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR48_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR49_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR49_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR49_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR49_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR49_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR49_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR50_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR50_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR50_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR50_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR50_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR50_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR51_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR51_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR51_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR51_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR51_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR51_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR52_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR52_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR52_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR52_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR52_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR52_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR53_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR53_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR53_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR53_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR53_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR53_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR54_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR54_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR54_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR54_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR54_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR54_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR55_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR55_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR55_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR55_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR55_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR55_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR56_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR56_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR56_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR56_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR56_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR56_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR57_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR57_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR57_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR57_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR57_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR57_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR58_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR58_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR58_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR58_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR58_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR58_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR59_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR59_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR59_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR59_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR59_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR59_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR60_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR60_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR60_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR60_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR60_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR60_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR61_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR61_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR61_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR61_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR61_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR61_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR62_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR62_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR62_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR62_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR62_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR62_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR63_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR63_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR63_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR63_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR63_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR63_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR64_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR64_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR64_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR64_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR64_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR64_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR65_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR65_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR65_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR65_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR65_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR65_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR66_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR66_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR66_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR66_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR66_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR66_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR67_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR67_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR67_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR67_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR67_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR67_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR68_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR68_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR68_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR68_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR68_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR68_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR69_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR69_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR69_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR69_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR69_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR69_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR70_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR70_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR70_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR70_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR70_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR70_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR71_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR71_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR71_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR71_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR71_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR71_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR72_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR72_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR72_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR72_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR72_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR72_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR73_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR73_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR73_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR73_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR73_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR73_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR74_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR74_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR74_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR74_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR74_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR74_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR75_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR75_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR75_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR75_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR75_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR75_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR76_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR76_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR76_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR76_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR76_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR76_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR77_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR77_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR77_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR77_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR77_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR77_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR78_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR78_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR78_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR78_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR78_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR78_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR79_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR79_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR79_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR79_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR79_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR79_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR80_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR80_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR80_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR80_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR80_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR80_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR81_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR81_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR81_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR81_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR81_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR81_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR82_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR82_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR82_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR82_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR82_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR82_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR83_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR83_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR83_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR83_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR83_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR83_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR84_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR84_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR84_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR84_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR84_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR84_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR85_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR85_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR85_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR85_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR85_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR85_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR86_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR86_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR86_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR86_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR86_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR86_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR87_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR87_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR87_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR87_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR87_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR87_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR88_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR88_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR88_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR88_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR88_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR88_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR89_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR89_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR89_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR89_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR89_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR89_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR90_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR90_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR90_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR90_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR90_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR90_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR91_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR91_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR91_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR91_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR91_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR91_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR92_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR92_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR92_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR92_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR92_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR92_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR93_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR93_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR93_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR93_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR93_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR93_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR94_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR94_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR94_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR94_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR94_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR94_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR95_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR95_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR95_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR95_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR95_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR95_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR96_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR96_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR96_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR96_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR96_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR96_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR97_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR97_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR97_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR97_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR97_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR97_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR98_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR98_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR98_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR98_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR98_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR98_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR99_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR99_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR99_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR99_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR99_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR99_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR100_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR100_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR100_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR100_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR100_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR100_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR101_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR101_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR101_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR101_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR101_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR101_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR102_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR102_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR102_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR102_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR102_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR102_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR103_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR103_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR103_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR103_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR103_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR103_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR104_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR104_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR104_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR104_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR104_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR104_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR105_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR105_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR105_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR105_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR105_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR105_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR106_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR106_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR106_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR106_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR106_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR106_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR107_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR107_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR107_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR107_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR107_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR107_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR108_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR108_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR108_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR108_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR108_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR108_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR109_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR109_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR109_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR109_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR109_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR109_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR110_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR110_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR110_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR110_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR110_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR110_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR111_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR111_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR111_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR111_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR111_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR111_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR112_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR112_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR112_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR112_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR112_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR112_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR113_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR113_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR113_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR113_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR113_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR113_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR114_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR114_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR114_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR114_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR114_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR114_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR115_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR115_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR115_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR115_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR115_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR115_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR116_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR116_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR116_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR116_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR116_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR116_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR117_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR117_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR117_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR117_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR117_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR117_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR118_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR118_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR118_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR118_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR118_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR118_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR119_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR119_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR119_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR119_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR119_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR119_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR120_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR120_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR120_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR120_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR120_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR120_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR121_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR121_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR121_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR121_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR121_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR121_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR122_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR122_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR122_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR122_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR122_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR122_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR123_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR123_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR123_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR123_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR123_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR123_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR124_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR124_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR124_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR124_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR124_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR124_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR125_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR125_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR125_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR125_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR125_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR125_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR126_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR126_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR126_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR126_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR126_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR126_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR127_HIGH register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR127_HIGH_ADDR  ALT_EMAC_GMAC_MAC_ADDR127_HIGH_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_GMAC_MAC_ADDR127_LOW register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_GMAC_MAC_ADDR127_LOW_ADDR  ALT_EMAC_GMAC_MAC_ADDR127_LOW_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_DMA_BUS_MOD register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_DMA_BUS_MOD_ADDR  ALT_EMAC_DMA_BUS_MOD_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_DMA_TX_POLL_DEMAND register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_DMA_TX_POLL_DEMAND_ADDR  ALT_EMAC_DMA_TX_POLL_DEMAND_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_DMA_RX_POLL_DEMAND register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_DMA_RX_POLL_DEMAND_ADDR  ALT_EMAC_DMA_RX_POLL_DEMAND_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_DMA_RX_DESC_LIST_ADDR register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_DMA_RX_DESC_LIST_ADDR_ADDR  ALT_EMAC_DMA_RX_DESC_LIST_ADDR_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_DMA_TX_DESC_LIST_ADDR register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_DMA_TX_DESC_LIST_ADDR_ADDR  ALT_EMAC_DMA_TX_DESC_LIST_ADDR_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_DMA_STAT register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_DMA_STAT_ADDR  ALT_EMAC_DMA_STAT_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_DMA_OP_MOD register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_DMA_OP_MOD_ADDR  ALT_EMAC_DMA_OP_MOD_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_DMA_INT_EN register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_DMA_INT_EN_ADDR  ALT_EMAC_DMA_INT_EN_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_DMA_MFRM_BUF_OVF_CNTR register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_DMA_MISSED_FRM_AND_BUF_OVF_CNTR_ADDR  ALT_EMAC_DMA_MFRM_BUF_OVF_CNTR_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_DMA_RX_INT_WDT register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_DMA_RX_INT_WDT_ADDR  ALT_EMAC_DMA_RX_INT_WDT_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_DMA_AXI_BUS_MOD register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_DMA_AXI_BUS_MOD_ADDR  ALT_EMAC_DMA_AXI_BUS_MOD_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_DMA_AHB_OR_AXI_STAT register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_DMA_AHB_OR_AXI_STAT_ADDR  ALT_EMAC_DMA_AHB_OR_AXI_STAT_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_DMA_CUR_HOST_TX_DESC register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_DMA_CUR_HOST_TX_DESC_ADDR  ALT_EMAC_DMA_CUR_HOST_TX_DESC_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_DMA_CUR_HOST_RX_DESC register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_DMA_CUR_HOST_RX_DESC_ADDR  ALT_EMAC_DMA_CUR_HOST_RX_DESC_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_DMA_CUR_HOST_TX_BUF_ADDR register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_DMA_CUR_HOST_TX_BUF_ADDR_ADDR  ALT_EMAC_DMA_CUR_HOST_TX_BUF_ADDR_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_DMA_CUR_HOST_RX_BUF_ADDR register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_DMA_CUR_HOST_RX_BUF_ADDR_ADDR  ALT_EMAC_DMA_CUR_HOST_RX_BUF_ADDR_ADDR(ALT_EMAC2_ADDR)
/* The address of the ALT_EMAC_DMA_HW_FEATURE register for the ALT_EMAC2 instance. */
#define ALT_EMAC2_DMA_HW_FEATURE_ADDR  ALT_EMAC_DMA_HW_FEATURE_ADDR(ALT_EMAC2_ADDR)
/* The base address byte offset for the start of the ALT_EMAC2 component. */
#define ALT_EMAC2_OFST        0xff804000
/* The start address of the ALT_EMAC2 component. */
#define ALT_EMAC2_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_EMAC2_OFST))
/* The lower bound address range of the ALT_EMAC2 component. */
#define ALT_EMAC2_LB_ADDR     ALT_EMAC2_ADDR
/* The upper bound address range of the ALT_EMAC2 component. */
#define ALT_EMAC2_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_EMAC2_ADDR) + 0x105c) - 1))


/*
 * Component Instance : i_sdmmc_sdmmc
 * 
 * Instance i_sdmmc_sdmmc of component ALT_SDMMC.
 * 
 * 
 */
/* The address of the ALT_SDMMC_CTL register for the ALT_SDMMC instance. */
#define ALT_SDMMC_CTL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SDMMC_ADDR) + ALT_SDMMC_CTL_OFST))
/* The address of the ALT_SDMMC_PWREN register for the ALT_SDMMC instance. */
#define ALT_SDMMC_PWREN_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SDMMC_ADDR) + ALT_SDMMC_PWREN_OFST))
/* The address of the ALT_SDMMC_CLKDIV register for the ALT_SDMMC instance. */
#define ALT_SDMMC_CLKDIV_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SDMMC_ADDR) + ALT_SDMMC_CLKDIV_OFST))
/* The address of the ALT_SDMMC_CLKSRC register for the ALT_SDMMC instance. */
#define ALT_SDMMC_CLKSRC_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SDMMC_ADDR) + ALT_SDMMC_CLKSRC_OFST))
/* The address of the ALT_SDMMC_CLKENA register for the ALT_SDMMC instance. */
#define ALT_SDMMC_CLKENA_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SDMMC_ADDR) + ALT_SDMMC_CLKENA_OFST))
/* The address of the ALT_SDMMC_TMOUT register for the ALT_SDMMC instance. */
#define ALT_SDMMC_TMOUT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SDMMC_ADDR) + ALT_SDMMC_TMOUT_OFST))
/* The address of the ALT_SDMMC_CTYPE register for the ALT_SDMMC instance. */
#define ALT_SDMMC_CTYPE_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SDMMC_ADDR) + ALT_SDMMC_CTYPE_OFST))
/* The address of the ALT_SDMMC_BLKSIZ register for the ALT_SDMMC instance. */
#define ALT_SDMMC_BLKSIZ_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SDMMC_ADDR) + ALT_SDMMC_BLKSIZ_OFST))
/* The address of the ALT_SDMMC_BYTCNT register for the ALT_SDMMC instance. */
#define ALT_SDMMC_BYTCNT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SDMMC_ADDR) + ALT_SDMMC_BYTCNT_OFST))
/* The address of the ALT_SDMMC_INTMSK register for the ALT_SDMMC instance. */
#define ALT_SDMMC_INTMSK_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SDMMC_ADDR) + ALT_SDMMC_INTMSK_OFST))
/* The address of the ALT_SDMMC_CMDARG register for the ALT_SDMMC instance. */
#define ALT_SDMMC_CMDARG_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SDMMC_ADDR) + ALT_SDMMC_CMDARG_OFST))
/* The address of the ALT_SDMMC_CMD register for the ALT_SDMMC instance. */
#define ALT_SDMMC_CMD_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SDMMC_ADDR) + ALT_SDMMC_CMD_OFST))
/* The address of the ALT_SDMMC_RESP0 register for the ALT_SDMMC instance. */
#define ALT_SDMMC_RESP0_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SDMMC_ADDR) + ALT_SDMMC_RESP0_OFST))
/* The address of the ALT_SDMMC_RESP1 register for the ALT_SDMMC instance. */
#define ALT_SDMMC_RESP1_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SDMMC_ADDR) + ALT_SDMMC_RESP1_OFST))
/* The address of the ALT_SDMMC_RESP2 register for the ALT_SDMMC instance. */
#define ALT_SDMMC_RESP2_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SDMMC_ADDR) + ALT_SDMMC_RESP2_OFST))
/* The address of the ALT_SDMMC_RESP3 register for the ALT_SDMMC instance. */
#define ALT_SDMMC_RESP3_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SDMMC_ADDR) + ALT_SDMMC_RESP3_OFST))
/* The address of the ALT_SDMMC_MINTSTS register for the ALT_SDMMC instance. */
#define ALT_SDMMC_MINTSTS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SDMMC_ADDR) + ALT_SDMMC_MINTSTS_OFST))
/* The address of the ALT_SDMMC_RINTSTS register for the ALT_SDMMC instance. */
#define ALT_SDMMC_RINTSTS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SDMMC_ADDR) + ALT_SDMMC_RINTSTS_OFST))
/* The address of the ALT_SDMMC_STAT register for the ALT_SDMMC instance. */
#define ALT_SDMMC_STAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SDMMC_ADDR) + ALT_SDMMC_STAT_OFST))
/* The address of the ALT_SDMMC_FIFOTH register for the ALT_SDMMC instance. */
#define ALT_SDMMC_FIFOTH_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SDMMC_ADDR) + ALT_SDMMC_FIFOTH_OFST))
/* The address of the ALT_SDMMC_CDETECT register for the ALT_SDMMC instance. */
#define ALT_SDMMC_CDETECT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SDMMC_ADDR) + ALT_SDMMC_CDETECT_OFST))
/* The address of the ALT_SDMMC_WRTPRT register for the ALT_SDMMC instance. */
#define ALT_SDMMC_WRTPRT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SDMMC_ADDR) + ALT_SDMMC_WRTPRT_OFST))
/* The address of the ALT_SDMMC_GPIO register for the ALT_SDMMC instance. */
#define ALT_SDMMC_GPIO_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SDMMC_ADDR) + ALT_SDMMC_GPIO_OFST))
/* The address of the ALT_SDMMC_TCBCNT register for the ALT_SDMMC instance. */
#define ALT_SDMMC_TCBCNT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SDMMC_ADDR) + ALT_SDMMC_TCBCNT_OFST))
/* The address of the ALT_SDMMC_TBBCNT register for the ALT_SDMMC instance. */
#define ALT_SDMMC_TBBCNT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SDMMC_ADDR) + ALT_SDMMC_TBBCNT_OFST))
/* The address of the ALT_SDMMC_DEBNCE register for the ALT_SDMMC instance. */
#define ALT_SDMMC_DEBNCE_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SDMMC_ADDR) + ALT_SDMMC_DEBNCE_OFST))
/* The address of the ALT_SDMMC_USRID register for the ALT_SDMMC instance. */
#define ALT_SDMMC_USRID_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SDMMC_ADDR) + ALT_SDMMC_USRID_OFST))
/* The address of the ALT_SDMMC_VERID register for the ALT_SDMMC instance. */
#define ALT_SDMMC_VERID_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SDMMC_ADDR) + ALT_SDMMC_VERID_OFST))
/* The address of the ALT_SDMMC_HCON register for the ALT_SDMMC instance. */
#define ALT_SDMMC_HCON_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SDMMC_ADDR) + ALT_SDMMC_HCON_OFST))
/* The address of the ALT_SDMMC_UHS_REG register for the ALT_SDMMC instance. */
#define ALT_SDMMC_UHS_REG_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SDMMC_ADDR) + ALT_SDMMC_UHS_REG_OFST))
/* The address of the ALT_SDMMC_RST_N register for the ALT_SDMMC instance. */
#define ALT_SDMMC_RST_N_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SDMMC_ADDR) + ALT_SDMMC_RST_N_OFST))
/* The address of the ALT_SDMMC_BMOD register for the ALT_SDMMC instance. */
#define ALT_SDMMC_BMOD_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SDMMC_ADDR) + ALT_SDMMC_BMOD_OFST))
/* The address of the ALT_SDMMC_PLDMND register for the ALT_SDMMC instance. */
#define ALT_SDMMC_PLDMND_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SDMMC_ADDR) + ALT_SDMMC_PLDMND_OFST))
/* The address of the ALT_SDMMC_DBADDR register for the ALT_SDMMC instance. */
#define ALT_SDMMC_DBADDR_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SDMMC_ADDR) + ALT_SDMMC_DBADDR_OFST))
/* The address of the ALT_SDMMC_IDSTS register for the ALT_SDMMC instance. */
#define ALT_SDMMC_IDSTS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SDMMC_ADDR) + ALT_SDMMC_IDSTS_OFST))
/* The address of the ALT_SDMMC_IDINTEN register for the ALT_SDMMC instance. */
#define ALT_SDMMC_IDINTEN_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SDMMC_ADDR) + ALT_SDMMC_IDINTEN_OFST))
/* The address of the ALT_SDMMC_DSCADDR register for the ALT_SDMMC instance. */
#define ALT_SDMMC_DSCADDR_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SDMMC_ADDR) + ALT_SDMMC_DSCADDR_OFST))
/* The address of the ALT_SDMMC_BUFADDR register for the ALT_SDMMC instance. */
#define ALT_SDMMC_BUFADDR_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SDMMC_ADDR) + ALT_SDMMC_BUFADDR_OFST))
/* The address of the ALT_SDMMC_CARDTHRCTL register for the ALT_SDMMC instance. */
#define ALT_SDMMC_CARDTHRCTL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SDMMC_ADDR) + ALT_SDMMC_CARDTHRCTL_OFST))
/* The address of the ALT_SDMMC_BACK_END_POWER_R register for the ALT_SDMMC instance. */
#define ALT_SDMMC_BACK_END_POWER_R_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SDMMC_ADDR) + ALT_SDMMC_BACK_END_POWER_R_OFST))
/* The address of the ALT_SDMMC_UHS_REG_EXT register for the ALT_SDMMC instance. */
#define ALT_SDMMC_UHS_REG_EXT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SDMMC_ADDR) + ALT_SDMMC_UHS_REG_EXT_OFST))
/* The address of the ALT_SDMMC_EMMC_DDR_REG register for the ALT_SDMMC instance. */
#define ALT_SDMMC_EMMC_DDR_REG_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SDMMC_ADDR) + ALT_SDMMC_EMMC_DDR_REG_OFST))
/* The address of the ALT_SDMMC_EN_SHIFT register for the ALT_SDMMC instance. */
#define ALT_SDMMC_EN_SHIFT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SDMMC_ADDR) + ALT_SDMMC_EN_SHIFT_OFST))
/* The address of the ALT_SDMMC_DATA register for the ALT_SDMMC instance. */
#define ALT_SDMMC_DATA_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SDMMC_ADDR) + ALT_SDMMC_DATA_OFST))
/* The base address byte offset for the start of the ALT_SDMMC component. */
#define ALT_SDMMC_OFST        0xff808000
/* The start address of the ALT_SDMMC component. */
#define ALT_SDMMC_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_SDMMC_OFST))
/* The lower bound address range of the ALT_SDMMC component. */
#define ALT_SDMMC_LB_ADDR     ALT_SDMMC_ADDR
/* The upper bound address range of the ALT_SDMMC component. */
#define ALT_SDMMC_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_SDMMC_ADDR) + 0x400) - 1))


/*
 * Component Instance : i_qspi_qspiregs
 * 
 * Instance i_qspi_qspiregs of component ALT_QSPI.
 * 
 * 
 */
/* The address of the ALT_QSPI_CFG register for the ALT_QSPI instance. */
#define ALT_QSPI_CFG_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_QSPI_ADDR) + ALT_QSPI_CFG_OFST))
/* The address of the ALT_QSPI_DEVRD register for the ALT_QSPI instance. */
#define ALT_QSPI_DEVRD_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_QSPI_ADDR) + ALT_QSPI_DEVRD_OFST))
/* The address of the ALT_QSPI_DEVWR register for the ALT_QSPI instance. */
#define ALT_QSPI_DEVWR_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_QSPI_ADDR) + ALT_QSPI_DEVWR_OFST))
/* The address of the ALT_QSPI_DELAY register for the ALT_QSPI instance. */
#define ALT_QSPI_DELAY_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_QSPI_ADDR) + ALT_QSPI_DELAY_OFST))
/* The address of the ALT_QSPI_RDDATACAP register for the ALT_QSPI instance. */
#define ALT_QSPI_RDDATACAP_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_QSPI_ADDR) + ALT_QSPI_RDDATACAP_OFST))
/* The address of the ALT_QSPI_DEVSZ register for the ALT_QSPI instance. */
#define ALT_QSPI_DEVSZ_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_QSPI_ADDR) + ALT_QSPI_DEVSZ_OFST))
/* The address of the ALT_QSPI_SRAMPART register for the ALT_QSPI instance. */
#define ALT_QSPI_SRAMPART_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_QSPI_ADDR) + ALT_QSPI_SRAMPART_OFST))
/* The address of the ALT_QSPI_INDADDRTRIG register for the ALT_QSPI instance. */
#define ALT_QSPI_INDADDRTRIG_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_QSPI_ADDR) + ALT_QSPI_INDADDRTRIG_OFST))
/* The address of the ALT_QSPI_DMAPER register for the ALT_QSPI instance. */
#define ALT_QSPI_DMAPER_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_QSPI_ADDR) + ALT_QSPI_DMAPER_OFST))
/* The address of the ALT_QSPI_REMAPADDR register for the ALT_QSPI instance. */
#define ALT_QSPI_REMAPADDR_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_QSPI_ADDR) + ALT_QSPI_REMAPADDR_OFST))
/* The address of the ALT_QSPI_MODBIT register for the ALT_QSPI instance. */
#define ALT_QSPI_MODBIT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_QSPI_ADDR) + ALT_QSPI_MODBIT_OFST))
/* The address of the ALT_QSPI_SRAMFILL register for the ALT_QSPI instance. */
#define ALT_QSPI_SRAMFILL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_QSPI_ADDR) + ALT_QSPI_SRAMFILL_OFST))
/* The address of the ALT_QSPI_TXTHRESH register for the ALT_QSPI instance. */
#define ALT_QSPI_TXTHRESH_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_QSPI_ADDR) + ALT_QSPI_TXTHRESH_OFST))
/* The address of the ALT_QSPI_RXTHRESH register for the ALT_QSPI instance. */
#define ALT_QSPI_RXTHRESH_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_QSPI_ADDR) + ALT_QSPI_RXTHRESH_OFST))
/* The address of the ALT_QSPI_IRQSTAT register for the ALT_QSPI instance. */
#define ALT_QSPI_IRQSTAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_QSPI_ADDR) + ALT_QSPI_IRQSTAT_OFST))
/* The address of the ALT_QSPI_IRQMSK register for the ALT_QSPI instance. */
#define ALT_QSPI_IRQMSK_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_QSPI_ADDR) + ALT_QSPI_IRQMSK_OFST))
/* The address of the ALT_QSPI_LOWWRPROT register for the ALT_QSPI instance. */
#define ALT_QSPI_LOWWRPROT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_QSPI_ADDR) + ALT_QSPI_LOWWRPROT_OFST))
/* The address of the ALT_QSPI_UPPWRPROT register for the ALT_QSPI instance. */
#define ALT_QSPI_UPPWRPROT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_QSPI_ADDR) + ALT_QSPI_UPPWRPROT_OFST))
/* The address of the ALT_QSPI_WRPROT register for the ALT_QSPI instance. */
#define ALT_QSPI_WRPROT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_QSPI_ADDR) + ALT_QSPI_WRPROT_OFST))
/* The address of the ALT_QSPI_INDRD register for the ALT_QSPI instance. */
#define ALT_QSPI_INDRD_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_QSPI_ADDR) + ALT_QSPI_INDRD_OFST))
/* The address of the ALT_QSPI_INDRDWATER register for the ALT_QSPI instance. */
#define ALT_QSPI_INDRDWATER_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_QSPI_ADDR) + ALT_QSPI_INDRDWATER_OFST))
/* The address of the ALT_QSPI_INDRDSTADDR register for the ALT_QSPI instance. */
#define ALT_QSPI_INDRDSTADDR_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_QSPI_ADDR) + ALT_QSPI_INDRDSTADDR_OFST))
/* The address of the ALT_QSPI_INDRDCNT register for the ALT_QSPI instance. */
#define ALT_QSPI_INDRDCNT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_QSPI_ADDR) + ALT_QSPI_INDRDCNT_OFST))
/* The address of the ALT_QSPI_INDWR register for the ALT_QSPI instance. */
#define ALT_QSPI_INDWR_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_QSPI_ADDR) + ALT_QSPI_INDWR_OFST))
/* The address of the ALT_QSPI_INDWRWATER register for the ALT_QSPI instance. */
#define ALT_QSPI_INDWRWATER_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_QSPI_ADDR) + ALT_QSPI_INDWRWATER_OFST))
/* The address of the ALT_QSPI_INDWRSTADDR register for the ALT_QSPI instance. */
#define ALT_QSPI_INDWRSTADDR_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_QSPI_ADDR) + ALT_QSPI_INDWRSTADDR_OFST))
/* The address of the ALT_QSPI_INDWRCNT register for the ALT_QSPI instance. */
#define ALT_QSPI_INDWRCNT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_QSPI_ADDR) + ALT_QSPI_INDWRCNT_OFST))
/* The address of the ALT_QSPI_FLSHCMD register for the ALT_QSPI instance. */
#define ALT_QSPI_FLSHCMD_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_QSPI_ADDR) + ALT_QSPI_FLSHCMD_OFST))
/* The address of the ALT_QSPI_FLSHCMDADDR register for the ALT_QSPI instance. */
#define ALT_QSPI_FLSHCMDADDR_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_QSPI_ADDR) + ALT_QSPI_FLSHCMDADDR_OFST))
/* The address of the ALT_QSPI_FLSHCMDRDDATALO register for the ALT_QSPI instance. */
#define ALT_QSPI_FLSHCMDRDDATALO_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_QSPI_ADDR) + ALT_QSPI_FLSHCMDRDDATALO_OFST))
/* The address of the ALT_QSPI_FLSHCMDRDDATAUP register for the ALT_QSPI instance. */
#define ALT_QSPI_FLSHCMDRDDATAUP_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_QSPI_ADDR) + ALT_QSPI_FLSHCMDRDDATAUP_OFST))
/* The address of the ALT_QSPI_FLSHCMDWRDATALO register for the ALT_QSPI instance. */
#define ALT_QSPI_FLSHCMDWRDATALO_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_QSPI_ADDR) + ALT_QSPI_FLSHCMDWRDATALO_OFST))
/* The address of the ALT_QSPI_FLSHCMDWRDATAUP register for the ALT_QSPI instance. */
#define ALT_QSPI_FLSHCMDWRDATAUP_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_QSPI_ADDR) + ALT_QSPI_FLSHCMDWRDATAUP_OFST))
/* The address of the ALT_QSPI_MODULEID register for the ALT_QSPI instance. */
#define ALT_QSPI_MODULEID_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_QSPI_ADDR) + ALT_QSPI_MODULEID_OFST))
/* The base address byte offset for the start of the ALT_QSPI component. */
#define ALT_QSPI_OFST        0xff809000
/* The start address of the ALT_QSPI component. */
#define ALT_QSPI_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_QSPI_OFST))
/* The lower bound address range of the ALT_QSPI component. */
#define ALT_QSPI_LB_ADDR     ALT_QSPI_ADDR
/* The upper bound address range of the ALT_QSPI component. */
#define ALT_QSPI_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_QSPI_ADDR) + 0x100) - 1))


/*
 * Component Instance : ecc_emac0_rx_ecc_registerBlock
 * 
 * Instance ecc_emac0_rx_ecc_registerBlock of component ALT_ECC_EMAC0_RX_ECC.
 * 
 * 
 */
/* The address of the ALT_ECC_EMAC0_RX_ECC_IP_REV_ID register for the ALT_ECC_EMAC0_RX_ECC instance. */
#define ALT_ECC_EMAC0_RX_ECC_IP_REV_ID_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC0_RX_ECC_ADDR) + ALT_ECC_EMAC0_RX_ECC_IP_REV_ID_OFST))
/* The address of the ALT_ECC_EMAC0_RX_ECC_CTL register for the ALT_ECC_EMAC0_RX_ECC instance. */
#define ALT_ECC_EMAC0_RX_ECC_CTL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC0_RX_ECC_ADDR) + ALT_ECC_EMAC0_RX_ECC_CTL_OFST))
/* The address of the ALT_ECC_EMAC0_RX_ECC_INITSTAT register for the ALT_ECC_EMAC0_RX_ECC instance. */
#define ALT_ECC_EMAC0_RX_ECC_INITSTAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC0_RX_ECC_ADDR) + ALT_ECC_EMAC0_RX_ECC_INITSTAT_OFST))
/* The address of the ALT_ECC_EMAC0_RX_ECC_ERRINTEN register for the ALT_ECC_EMAC0_RX_ECC instance. */
#define ALT_ECC_EMAC0_RX_ECC_ERRINTEN_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC0_RX_ECC_ADDR) + ALT_ECC_EMAC0_RX_ECC_ERRINTEN_OFST))
/* The address of the ALT_ECC_EMAC0_RX_ECC_ERRINTENS register for the ALT_ECC_EMAC0_RX_ECC instance. */
#define ALT_ECC_EMAC0_RX_ECC_ERRINTENS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC0_RX_ECC_ADDR) + ALT_ECC_EMAC0_RX_ECC_ERRINTENS_OFST))
/* The address of the ALT_ECC_EMAC0_RX_ECC_ERRINTENR register for the ALT_ECC_EMAC0_RX_ECC instance. */
#define ALT_ECC_EMAC0_RX_ECC_ERRINTENR_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC0_RX_ECC_ADDR) + ALT_ECC_EMAC0_RX_ECC_ERRINTENR_OFST))
/* The address of the ALT_ECC_EMAC0_RX_ECC_INTMOD register for the ALT_ECC_EMAC0_RX_ECC instance. */
#define ALT_ECC_EMAC0_RX_ECC_INTMOD_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC0_RX_ECC_ADDR) + ALT_ECC_EMAC0_RX_ECC_INTMOD_OFST))
/* The address of the ALT_ECC_EMAC0_RX_ECC_INTSTAT register for the ALT_ECC_EMAC0_RX_ECC instance. */
#define ALT_ECC_EMAC0_RX_ECC_INTSTAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC0_RX_ECC_ADDR) + ALT_ECC_EMAC0_RX_ECC_INTSTAT_OFST))
/* The address of the ALT_ECC_EMAC0_RX_ECC_INTTEST register for the ALT_ECC_EMAC0_RX_ECC instance. */
#define ALT_ECC_EMAC0_RX_ECC_INTTEST_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC0_RX_ECC_ADDR) + ALT_ECC_EMAC0_RX_ECC_INTTEST_OFST))
/* The address of the ALT_ECC_EMAC0_RX_ECC_MODSTAT register for the ALT_ECC_EMAC0_RX_ECC instance. */
#define ALT_ECC_EMAC0_RX_ECC_MODSTAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC0_RX_ECC_ADDR) + ALT_ECC_EMAC0_RX_ECC_MODSTAT_OFST))
/* The address of the ALT_ECC_EMAC0_RX_ECC_DERRADDRA register for the ALT_ECC_EMAC0_RX_ECC instance. */
#define ALT_ECC_EMAC0_RX_ECC_DERRADDRA_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC0_RX_ECC_ADDR) + ALT_ECC_EMAC0_RX_ECC_DERRADDRA_OFST))
/* The address of the ALT_ECC_EMAC0_RX_ECC_SERRADDRA register for the ALT_ECC_EMAC0_RX_ECC instance. */
#define ALT_ECC_EMAC0_RX_ECC_SERRADDRA_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC0_RX_ECC_ADDR) + ALT_ECC_EMAC0_RX_ECC_SERRADDRA_OFST))
/* The address of the ALT_ECC_EMAC0_RX_ECC_SERRCNTREG register for the ALT_ECC_EMAC0_RX_ECC instance. */
#define ALT_ECC_EMAC0_RX_ECC_SERRCNTREG_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC0_RX_ECC_ADDR) + ALT_ECC_EMAC0_RX_ECC_SERRCNTREG_OFST))
/* The address of the ALT_ECC_EMAC0_RX_ECC_ECC_ADDRBUS register for the ALT_ECC_EMAC0_RX_ECC instance. */
#define ALT_ECC_EMAC0_RX_ECC_ECC_ADDRBUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC0_RX_ECC_ADDR) + ALT_ECC_EMAC0_RX_ECC_ECC_ADDRBUS_OFST))
/* The address of the ALT_ECC_EMAC0_RX_ECC_ECC_RDATA0BUS register for the ALT_ECC_EMAC0_RX_ECC instance. */
#define ALT_ECC_EMAC0_RX_ECC_ECC_RDATA0BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC0_RX_ECC_ADDR) + ALT_ECC_EMAC0_RX_ECC_ECC_RDATA0BUS_OFST))
/* The address of the ALT_ECC_EMAC0_RX_ECC_ECC_RDATA1BUS register for the ALT_ECC_EMAC0_RX_ECC instance. */
#define ALT_ECC_EMAC0_RX_ECC_ECC_RDATA1BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC0_RX_ECC_ADDR) + ALT_ECC_EMAC0_RX_ECC_ECC_RDATA1BUS_OFST))
/* The address of the ALT_ECC_EMAC0_RX_ECC_ECC_RDATA2BUS register for the ALT_ECC_EMAC0_RX_ECC instance. */
#define ALT_ECC_EMAC0_RX_ECC_ECC_RDATA2BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC0_RX_ECC_ADDR) + ALT_ECC_EMAC0_RX_ECC_ECC_RDATA2BUS_OFST))
/* The address of the ALT_ECC_EMAC0_RX_ECC_ECC_RDATA3BUS register for the ALT_ECC_EMAC0_RX_ECC instance. */
#define ALT_ECC_EMAC0_RX_ECC_ECC_RDATA3BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC0_RX_ECC_ADDR) + ALT_ECC_EMAC0_RX_ECC_ECC_RDATA3BUS_OFST))
/* The address of the ALT_ECC_EMAC0_RX_ECC_ECC_WDATA0BUS register for the ALT_ECC_EMAC0_RX_ECC instance. */
#define ALT_ECC_EMAC0_RX_ECC_ECC_WDATA0BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC0_RX_ECC_ADDR) + ALT_ECC_EMAC0_RX_ECC_ECC_WDATA0BUS_OFST))
/* The address of the ALT_ECC_EMAC0_RX_ECC_ECC_WDATA1BUS register for the ALT_ECC_EMAC0_RX_ECC instance. */
#define ALT_ECC_EMAC0_RX_ECC_ECC_WDATA1BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC0_RX_ECC_ADDR) + ALT_ECC_EMAC0_RX_ECC_ECC_WDATA1BUS_OFST))
/* The address of the ALT_ECC_EMAC0_RX_ECC_ECC_WDATA2BUS register for the ALT_ECC_EMAC0_RX_ECC instance. */
#define ALT_ECC_EMAC0_RX_ECC_ECC_WDATA2BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC0_RX_ECC_ADDR) + ALT_ECC_EMAC0_RX_ECC_ECC_WDATA2BUS_OFST))
/* The address of the ALT_ECC_EMAC0_RX_ECC_ECC_WDATA3BUS register for the ALT_ECC_EMAC0_RX_ECC instance. */
#define ALT_ECC_EMAC0_RX_ECC_ECC_WDATA3BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC0_RX_ECC_ADDR) + ALT_ECC_EMAC0_RX_ECC_ECC_WDATA3BUS_OFST))
/* The address of the ALT_ECC_EMAC0_RX_ECC_ECC_RDATAECC0BUS register for the ALT_ECC_EMAC0_RX_ECC instance. */
#define ALT_ECC_EMAC0_RX_ECC_ECC_RDATAECC0BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC0_RX_ECC_ADDR) + ALT_ECC_EMAC0_RX_ECC_ECC_RDATAECC0BUS_OFST))
/* The address of the ALT_ECC_EMAC0_RX_ECC_ECC_RDATAECC1BUS register for the ALT_ECC_EMAC0_RX_ECC instance. */
#define ALT_ECC_EMAC0_RX_ECC_ECC_RDATAECC1BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC0_RX_ECC_ADDR) + ALT_ECC_EMAC0_RX_ECC_ECC_RDATAECC1BUS_OFST))
/* The address of the ALT_ECC_EMAC0_RX_ECC_ECC_WDATAECC0BUS register for the ALT_ECC_EMAC0_RX_ECC instance. */
#define ALT_ECC_EMAC0_RX_ECC_ECC_WDATAECC0BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC0_RX_ECC_ADDR) + ALT_ECC_EMAC0_RX_ECC_ECC_WDATAECC0BUS_OFST))
/* The address of the ALT_ECC_EMAC0_RX_ECC_ECC_WDATAECC1BUS register for the ALT_ECC_EMAC0_RX_ECC instance. */
#define ALT_ECC_EMAC0_RX_ECC_ECC_WDATAECC1BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC0_RX_ECC_ADDR) + ALT_ECC_EMAC0_RX_ECC_ECC_WDATAECC1BUS_OFST))
/* The address of the ALT_ECC_EMAC0_RX_ECC_ECC_DBYTECTL register for the ALT_ECC_EMAC0_RX_ECC instance. */
#define ALT_ECC_EMAC0_RX_ECC_ECC_DBYTECTL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC0_RX_ECC_ADDR) + ALT_ECC_EMAC0_RX_ECC_ECC_DBYTECTL_OFST))
/* The address of the ALT_ECC_EMAC0_RX_ECC_ECC_ACCCTL register for the ALT_ECC_EMAC0_RX_ECC instance. */
#define ALT_ECC_EMAC0_RX_ECC_ECC_ACCCTL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC0_RX_ECC_ADDR) + ALT_ECC_EMAC0_RX_ECC_ECC_ACCCTL_OFST))
/* The address of the ALT_ECC_EMAC0_RX_ECC_ECC_STARTACC register for the ALT_ECC_EMAC0_RX_ECC instance. */
#define ALT_ECC_EMAC0_RX_ECC_ECC_STARTACC_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC0_RX_ECC_ADDR) + ALT_ECC_EMAC0_RX_ECC_ECC_STARTACC_OFST))
/* The address of the ALT_ECC_EMAC0_RX_ECC_ECC_WDCTL register for the ALT_ECC_EMAC0_RX_ECC instance. */
#define ALT_ECC_EMAC0_RX_ECC_ECC_WDCTL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC0_RX_ECC_ADDR) + ALT_ECC_EMAC0_RX_ECC_ECC_WDCTL_OFST))
/* The address of the ALT_ECC_EMAC0_RX_ECC_SERRLKUPA0 register for the ALT_ECC_EMAC0_RX_ECC instance. */
#define ALT_ECC_EMAC0_RX_ECC_SERRLKUPA0_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC0_RX_ECC_ADDR) + ALT_ECC_EMAC0_RX_ECC_SERRLKUPA0_OFST))
/* The base address byte offset for the start of the ALT_ECC_EMAC0_RX_ECC component. */
#define ALT_ECC_EMAC0_RX_ECC_OFST        0xff8c0800
/* The start address of the ALT_ECC_EMAC0_RX_ECC component. */
#define ALT_ECC_EMAC0_RX_ECC_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_ECC_EMAC0_RX_ECC_OFST))
/* The lower bound address range of the ALT_ECC_EMAC0_RX_ECC component. */
#define ALT_ECC_EMAC0_RX_ECC_LB_ADDR     ALT_ECC_EMAC0_RX_ECC_ADDR
/* The upper bound address range of the ALT_ECC_EMAC0_RX_ECC component. */
#define ALT_ECC_EMAC0_RX_ECC_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_ECC_EMAC0_RX_ECC_ADDR) + 0x400) - 1))


/*
 * Component Instance : ecc_emac0_tx_ecc_registerBlock
 * 
 * Instance ecc_emac0_tx_ecc_registerBlock of component ALT_ECC_EMAC0_TX_ECC.
 * 
 * 
 */
/* The address of the ALT_ECC_EMAC0_TX_ECC_IP_REV_ID register for the ALT_ECC_EMAC0_TX_ECC instance. */
#define ALT_ECC_EMAC0_TX_ECC_IP_REV_ID_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC0_TX_ECC_ADDR) + ALT_ECC_EMAC0_TX_ECC_IP_REV_ID_OFST))
/* The address of the ALT_ECC_EMAC0_TX_ECC_CTL register for the ALT_ECC_EMAC0_TX_ECC instance. */
#define ALT_ECC_EMAC0_TX_ECC_CTL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC0_TX_ECC_ADDR) + ALT_ECC_EMAC0_TX_ECC_CTL_OFST))
/* The address of the ALT_ECC_EMAC0_TX_ECC_INITSTAT register for the ALT_ECC_EMAC0_TX_ECC instance. */
#define ALT_ECC_EMAC0_TX_ECC_INITSTAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC0_TX_ECC_ADDR) + ALT_ECC_EMAC0_TX_ECC_INITSTAT_OFST))
/* The address of the ALT_ECC_EMAC0_TX_ECC_ERRINTEN register for the ALT_ECC_EMAC0_TX_ECC instance. */
#define ALT_ECC_EMAC0_TX_ECC_ERRINTEN_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC0_TX_ECC_ADDR) + ALT_ECC_EMAC0_TX_ECC_ERRINTEN_OFST))
/* The address of the ALT_ECC_EMAC0_TX_ECC_ERRINTENS register for the ALT_ECC_EMAC0_TX_ECC instance. */
#define ALT_ECC_EMAC0_TX_ECC_ERRINTENS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC0_TX_ECC_ADDR) + ALT_ECC_EMAC0_TX_ECC_ERRINTENS_OFST))
/* The address of the ALT_ECC_EMAC0_TX_ECC_ERRINTENR register for the ALT_ECC_EMAC0_TX_ECC instance. */
#define ALT_ECC_EMAC0_TX_ECC_ERRINTENR_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC0_TX_ECC_ADDR) + ALT_ECC_EMAC0_TX_ECC_ERRINTENR_OFST))
/* The address of the ALT_ECC_EMAC0_TX_ECC_INTMOD register for the ALT_ECC_EMAC0_TX_ECC instance. */
#define ALT_ECC_EMAC0_TX_ECC_INTMOD_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC0_TX_ECC_ADDR) + ALT_ECC_EMAC0_TX_ECC_INTMOD_OFST))
/* The address of the ALT_ECC_EMAC0_TX_ECC_INTTEST register for the ALT_ECC_EMAC0_TX_ECC instance. */
#define ALT_ECC_EMAC0_TX_ECC_INTTEST_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC0_TX_ECC_ADDR) + ALT_ECC_EMAC0_TX_ECC_INTTEST_OFST))
/* The address of the ALT_ECC_EMAC0_TX_ECC_MODSTAT register for the ALT_ECC_EMAC0_TX_ECC instance. */
#define ALT_ECC_EMAC0_TX_ECC_MODSTAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC0_TX_ECC_ADDR) + ALT_ECC_EMAC0_TX_ECC_MODSTAT_OFST))
/* The address of the ALT_ECC_EMAC0_TX_ECC_DERRADDRA register for the ALT_ECC_EMAC0_TX_ECC instance. */
#define ALT_ECC_EMAC0_TX_ECC_DERRADDRA_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC0_TX_ECC_ADDR) + ALT_ECC_EMAC0_TX_ECC_DERRADDRA_OFST))
/* The address of the ALT_ECC_EMAC0_TX_ECC_SERRADDRA register for the ALT_ECC_EMAC0_TX_ECC instance. */
#define ALT_ECC_EMAC0_TX_ECC_SERRADDRA_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC0_TX_ECC_ADDR) + ALT_ECC_EMAC0_TX_ECC_SERRADDRA_OFST))
/* The address of the ALT_ECC_EMAC0_TX_ECC_INTSTAT register for the ALT_ECC_EMAC0_TX_ECC instance. */
#define ALT_ECC_EMAC0_TX_ECC_INTSTAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC0_TX_ECC_ADDR) + ALT_ECC_EMAC0_TX_ECC_INTSTAT_OFST))
/* The address of the ALT_ECC_EMAC0_TX_ECC_SERRCNTREG register for the ALT_ECC_EMAC0_TX_ECC instance. */
#define ALT_ECC_EMAC0_TX_ECC_SERRCNTREG_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC0_TX_ECC_ADDR) + ALT_ECC_EMAC0_TX_ECC_SERRCNTREG_OFST))
/* The address of the ALT_ECC_EMAC0_TX_ECC_ECC_ADDRBUS register for the ALT_ECC_EMAC0_TX_ECC instance. */
#define ALT_ECC_EMAC0_TX_ECC_ECC_ADDRBUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC0_TX_ECC_ADDR) + ALT_ECC_EMAC0_TX_ECC_ECC_ADDRBUS_OFST))
/* The address of the ALT_ECC_EMAC0_TX_ECC_ECC_RDATA0BUS register for the ALT_ECC_EMAC0_TX_ECC instance. */
#define ALT_ECC_EMAC0_TX_ECC_ECC_RDATA0BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC0_TX_ECC_ADDR) + ALT_ECC_EMAC0_TX_ECC_ECC_RDATA0BUS_OFST))
/* The address of the ALT_ECC_EMAC0_TX_ECC_ECC_RDATA1BUS register for the ALT_ECC_EMAC0_TX_ECC instance. */
#define ALT_ECC_EMAC0_TX_ECC_ECC_RDATA1BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC0_TX_ECC_ADDR) + ALT_ECC_EMAC0_TX_ECC_ECC_RDATA1BUS_OFST))
/* The address of the ALT_ECC_EMAC0_TX_ECC_ECC_RDATA2BUS register for the ALT_ECC_EMAC0_TX_ECC instance. */
#define ALT_ECC_EMAC0_TX_ECC_ECC_RDATA2BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC0_TX_ECC_ADDR) + ALT_ECC_EMAC0_TX_ECC_ECC_RDATA2BUS_OFST))
/* The address of the ALT_ECC_EMAC0_TX_ECC_ECC_RDATA3BUS register for the ALT_ECC_EMAC0_TX_ECC instance. */
#define ALT_ECC_EMAC0_TX_ECC_ECC_RDATA3BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC0_TX_ECC_ADDR) + ALT_ECC_EMAC0_TX_ECC_ECC_RDATA3BUS_OFST))
/* The address of the ALT_ECC_EMAC0_TX_ECC_ECC_WDATA0BUS register for the ALT_ECC_EMAC0_TX_ECC instance. */
#define ALT_ECC_EMAC0_TX_ECC_ECC_WDATA0BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC0_TX_ECC_ADDR) + ALT_ECC_EMAC0_TX_ECC_ECC_WDATA0BUS_OFST))
/* The address of the ALT_ECC_EMAC0_TX_ECC_ECC_WDATA1BUS register for the ALT_ECC_EMAC0_TX_ECC instance. */
#define ALT_ECC_EMAC0_TX_ECC_ECC_WDATA1BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC0_TX_ECC_ADDR) + ALT_ECC_EMAC0_TX_ECC_ECC_WDATA1BUS_OFST))
/* The address of the ALT_ECC_EMAC0_TX_ECC_ECC_WDATA2BUS register for the ALT_ECC_EMAC0_TX_ECC instance. */
#define ALT_ECC_EMAC0_TX_ECC_ECC_WDATA2BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC0_TX_ECC_ADDR) + ALT_ECC_EMAC0_TX_ECC_ECC_WDATA2BUS_OFST))
/* The address of the ALT_ECC_EMAC0_TX_ECC_ECC_WDATA3BUS register for the ALT_ECC_EMAC0_TX_ECC instance. */
#define ALT_ECC_EMAC0_TX_ECC_ECC_WDATA3BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC0_TX_ECC_ADDR) + ALT_ECC_EMAC0_TX_ECC_ECC_WDATA3BUS_OFST))
/* The address of the ALT_ECC_EMAC0_TX_ECC_ECC_RDATAECC0BUS register for the ALT_ECC_EMAC0_TX_ECC instance. */
#define ALT_ECC_EMAC0_TX_ECC_ECC_RDATAECC0BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC0_TX_ECC_ADDR) + ALT_ECC_EMAC0_TX_ECC_ECC_RDATAECC0BUS_OFST))
/* The address of the ALT_ECC_EMAC0_TX_ECC_ECC_RDATAECC1BUS register for the ALT_ECC_EMAC0_TX_ECC instance. */
#define ALT_ECC_EMAC0_TX_ECC_ECC_RDATAECC1BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC0_TX_ECC_ADDR) + ALT_ECC_EMAC0_TX_ECC_ECC_RDATAECC1BUS_OFST))
/* The address of the ALT_ECC_EMAC0_TX_ECC_ECC_WDATAECC0BUS register for the ALT_ECC_EMAC0_TX_ECC instance. */
#define ALT_ECC_EMAC0_TX_ECC_ECC_WDATAECC0BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC0_TX_ECC_ADDR) + ALT_ECC_EMAC0_TX_ECC_ECC_WDATAECC0BUS_OFST))
/* The address of the ALT_ECC_EMAC0_TX_ECC_ECC_WDATAECC1BUS register for the ALT_ECC_EMAC0_TX_ECC instance. */
#define ALT_ECC_EMAC0_TX_ECC_ECC_WDATAECC1BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC0_TX_ECC_ADDR) + ALT_ECC_EMAC0_TX_ECC_ECC_WDATAECC1BUS_OFST))
/* The address of the ALT_ECC_EMAC0_TX_ECC_ECC_DBYTECTL register for the ALT_ECC_EMAC0_TX_ECC instance. */
#define ALT_ECC_EMAC0_TX_ECC_ECC_DBYTECTL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC0_TX_ECC_ADDR) + ALT_ECC_EMAC0_TX_ECC_ECC_DBYTECTL_OFST))
/* The address of the ALT_ECC_EMAC0_TX_ECC_ECC_ACCCTL register for the ALT_ECC_EMAC0_TX_ECC instance. */
#define ALT_ECC_EMAC0_TX_ECC_ECC_ACCCTL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC0_TX_ECC_ADDR) + ALT_ECC_EMAC0_TX_ECC_ECC_ACCCTL_OFST))
/* The address of the ALT_ECC_EMAC0_TX_ECC_ECC_STARTACC register for the ALT_ECC_EMAC0_TX_ECC instance. */
#define ALT_ECC_EMAC0_TX_ECC_ECC_STARTACC_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC0_TX_ECC_ADDR) + ALT_ECC_EMAC0_TX_ECC_ECC_STARTACC_OFST))
/* The address of the ALT_ECC_EMAC0_TX_ECC_ECC_WDCTL register for the ALT_ECC_EMAC0_TX_ECC instance. */
#define ALT_ECC_EMAC0_TX_ECC_ECC_WDCTL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC0_TX_ECC_ADDR) + ALT_ECC_EMAC0_TX_ECC_ECC_WDCTL_OFST))
/* The address of the ALT_ECC_EMAC0_TX_ECC_SERRLKUPA0 register for the ALT_ECC_EMAC0_TX_ECC instance. */
#define ALT_ECC_EMAC0_TX_ECC_SERRLKUPA0_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC0_TX_ECC_ADDR) + ALT_ECC_EMAC0_TX_ECC_SERRLKUPA0_OFST))
/* The base address byte offset for the start of the ALT_ECC_EMAC0_TX_ECC component. */
#define ALT_ECC_EMAC0_TX_ECC_OFST        0xff8c0c00
/* The start address of the ALT_ECC_EMAC0_TX_ECC component. */
#define ALT_ECC_EMAC0_TX_ECC_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_ECC_EMAC0_TX_ECC_OFST))
/* The lower bound address range of the ALT_ECC_EMAC0_TX_ECC component. */
#define ALT_ECC_EMAC0_TX_ECC_LB_ADDR     ALT_ECC_EMAC0_TX_ECC_ADDR
/* The upper bound address range of the ALT_ECC_EMAC0_TX_ECC component. */
#define ALT_ECC_EMAC0_TX_ECC_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_ECC_EMAC0_TX_ECC_ADDR) + 0x400) - 1))


/*
 * Component Instance : ecc_emac1_rx_ecc_registerBlock
 * 
 * Instance ecc_emac1_rx_ecc_registerBlock of component ALT_ECC_EMAC1_RX_ECC.
 * 
 * 
 */
/* The address of the ALT_ECC_EMAC1_RX_ECC_IP_REV_ID register for the ALT_ECC_EMAC1_RX_ECC instance. */
#define ALT_ECC_EMAC1_RX_ECC_IP_REV_ID_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC1_RX_ECC_ADDR) + ALT_ECC_EMAC1_RX_ECC_IP_REV_ID_OFST))
/* The address of the ALT_ECC_EMAC1_RX_ECC_CTL register for the ALT_ECC_EMAC1_RX_ECC instance. */
#define ALT_ECC_EMAC1_RX_ECC_CTL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC1_RX_ECC_ADDR) + ALT_ECC_EMAC1_RX_ECC_CTL_OFST))
/* The address of the ALT_ECC_EMAC1_RX_ECC_INITSTAT register for the ALT_ECC_EMAC1_RX_ECC instance. */
#define ALT_ECC_EMAC1_RX_ECC_INITSTAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC1_RX_ECC_ADDR) + ALT_ECC_EMAC1_RX_ECC_INITSTAT_OFST))
/* The address of the ALT_ECC_EMAC1_RX_ECC_ERRINTEN register for the ALT_ECC_EMAC1_RX_ECC instance. */
#define ALT_ECC_EMAC1_RX_ECC_ERRINTEN_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC1_RX_ECC_ADDR) + ALT_ECC_EMAC1_RX_ECC_ERRINTEN_OFST))
/* The address of the ALT_ECC_EMAC1_RX_ECC_ERRINTENS register for the ALT_ECC_EMAC1_RX_ECC instance. */
#define ALT_ECC_EMAC1_RX_ECC_ERRINTENS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC1_RX_ECC_ADDR) + ALT_ECC_EMAC1_RX_ECC_ERRINTENS_OFST))
/* The address of the ALT_ECC_EMAC1_RX_ECC_ERRINTENR register for the ALT_ECC_EMAC1_RX_ECC instance. */
#define ALT_ECC_EMAC1_RX_ECC_ERRINTENR_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC1_RX_ECC_ADDR) + ALT_ECC_EMAC1_RX_ECC_ERRINTENR_OFST))
/* The address of the ALT_ECC_EMAC1_RX_ECC_INTMOD register for the ALT_ECC_EMAC1_RX_ECC instance. */
#define ALT_ECC_EMAC1_RX_ECC_INTMOD_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC1_RX_ECC_ADDR) + ALT_ECC_EMAC1_RX_ECC_INTMOD_OFST))
/* The address of the ALT_ECC_EMAC1_RX_ECC_INTSTAT register for the ALT_ECC_EMAC1_RX_ECC instance. */
#define ALT_ECC_EMAC1_RX_ECC_INTSTAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC1_RX_ECC_ADDR) + ALT_ECC_EMAC1_RX_ECC_INTSTAT_OFST))
/* The address of the ALT_ECC_EMAC1_RX_ECC_INTTEST register for the ALT_ECC_EMAC1_RX_ECC instance. */
#define ALT_ECC_EMAC1_RX_ECC_INTTEST_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC1_RX_ECC_ADDR) + ALT_ECC_EMAC1_RX_ECC_INTTEST_OFST))
/* The address of the ALT_ECC_EMAC1_RX_ECC_MODSTAT register for the ALT_ECC_EMAC1_RX_ECC instance. */
#define ALT_ECC_EMAC1_RX_ECC_MODSTAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC1_RX_ECC_ADDR) + ALT_ECC_EMAC1_RX_ECC_MODSTAT_OFST))
/* The address of the ALT_ECC_EMAC1_RX_ECC_DERRADDRA register for the ALT_ECC_EMAC1_RX_ECC instance. */
#define ALT_ECC_EMAC1_RX_ECC_DERRADDRA_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC1_RX_ECC_ADDR) + ALT_ECC_EMAC1_RX_ECC_DERRADDRA_OFST))
/* The address of the ALT_ECC_EMAC1_RX_ECC_SERRADDRA register for the ALT_ECC_EMAC1_RX_ECC instance. */
#define ALT_ECC_EMAC1_RX_ECC_SERRADDRA_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC1_RX_ECC_ADDR) + ALT_ECC_EMAC1_RX_ECC_SERRADDRA_OFST))
/* The address of the ALT_ECC_EMAC1_RX_ECC_SERRCNTREG register for the ALT_ECC_EMAC1_RX_ECC instance. */
#define ALT_ECC_EMAC1_RX_ECC_SERRCNTREG_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC1_RX_ECC_ADDR) + ALT_ECC_EMAC1_RX_ECC_SERRCNTREG_OFST))
/* The address of the ALT_ECC_EMAC1_RX_ECC_ECC_ADDRBUS register for the ALT_ECC_EMAC1_RX_ECC instance. */
#define ALT_ECC_EMAC1_RX_ECC_ECC_ADDRBUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC1_RX_ECC_ADDR) + ALT_ECC_EMAC1_RX_ECC_ECC_ADDRBUS_OFST))
/* The address of the ALT_ECC_EMAC1_RX_ECC_ECC_RDATA0BUS register for the ALT_ECC_EMAC1_RX_ECC instance. */
#define ALT_ECC_EMAC1_RX_ECC_ECC_RDATA0BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC1_RX_ECC_ADDR) + ALT_ECC_EMAC1_RX_ECC_ECC_RDATA0BUS_OFST))
/* The address of the ALT_ECC_EMAC1_RX_ECC_ECC_RDATA1BUS register for the ALT_ECC_EMAC1_RX_ECC instance. */
#define ALT_ECC_EMAC1_RX_ECC_ECC_RDATA1BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC1_RX_ECC_ADDR) + ALT_ECC_EMAC1_RX_ECC_ECC_RDATA1BUS_OFST))
/* The address of the ALT_ECC_EMAC1_RX_ECC_ECC_RDATA2BUS register for the ALT_ECC_EMAC1_RX_ECC instance. */
#define ALT_ECC_EMAC1_RX_ECC_ECC_RDATA2BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC1_RX_ECC_ADDR) + ALT_ECC_EMAC1_RX_ECC_ECC_RDATA2BUS_OFST))
/* The address of the ALT_ECC_EMAC1_RX_ECC_ECC_RDATA3BUS register for the ALT_ECC_EMAC1_RX_ECC instance. */
#define ALT_ECC_EMAC1_RX_ECC_ECC_RDATA3BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC1_RX_ECC_ADDR) + ALT_ECC_EMAC1_RX_ECC_ECC_RDATA3BUS_OFST))
/* The address of the ALT_ECC_EMAC1_RX_ECC_ECC_WDATA0BUS register for the ALT_ECC_EMAC1_RX_ECC instance. */
#define ALT_ECC_EMAC1_RX_ECC_ECC_WDATA0BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC1_RX_ECC_ADDR) + ALT_ECC_EMAC1_RX_ECC_ECC_WDATA0BUS_OFST))
/* The address of the ALT_ECC_EMAC1_RX_ECC_ECC_WDATA1BUS register for the ALT_ECC_EMAC1_RX_ECC instance. */
#define ALT_ECC_EMAC1_RX_ECC_ECC_WDATA1BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC1_RX_ECC_ADDR) + ALT_ECC_EMAC1_RX_ECC_ECC_WDATA1BUS_OFST))
/* The address of the ALT_ECC_EMAC1_RX_ECC_ECC_WDATA2BUS register for the ALT_ECC_EMAC1_RX_ECC instance. */
#define ALT_ECC_EMAC1_RX_ECC_ECC_WDATA2BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC1_RX_ECC_ADDR) + ALT_ECC_EMAC1_RX_ECC_ECC_WDATA2BUS_OFST))
/* The address of the ALT_ECC_EMAC1_RX_ECC_ECC_WDATA3BUS register for the ALT_ECC_EMAC1_RX_ECC instance. */
#define ALT_ECC_EMAC1_RX_ECC_ECC_WDATA3BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC1_RX_ECC_ADDR) + ALT_ECC_EMAC1_RX_ECC_ECC_WDATA3BUS_OFST))
/* The address of the ALT_ECC_EMAC1_RX_ECC_ECC_RDATAECC0BUS register for the ALT_ECC_EMAC1_RX_ECC instance. */
#define ALT_ECC_EMAC1_RX_ECC_ECC_RDATAECC0BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC1_RX_ECC_ADDR) + ALT_ECC_EMAC1_RX_ECC_ECC_RDATAECC0BUS_OFST))
/* The address of the ALT_ECC_EMAC1_RX_ECC_ECC_RDATAECC1BUS register for the ALT_ECC_EMAC1_RX_ECC instance. */
#define ALT_ECC_EMAC1_RX_ECC_ECC_RDATAECC1BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC1_RX_ECC_ADDR) + ALT_ECC_EMAC1_RX_ECC_ECC_RDATAECC1BUS_OFST))
/* The address of the ALT_ECC_EMAC1_RX_ECC_ECC_WDATAECC0BUS register for the ALT_ECC_EMAC1_RX_ECC instance. */
#define ALT_ECC_EMAC1_RX_ECC_ECC_WDATAECC0BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC1_RX_ECC_ADDR) + ALT_ECC_EMAC1_RX_ECC_ECC_WDATAECC0BUS_OFST))
/* The address of the ALT_ECC_EMAC1_RX_ECC_ECC_WDATAECC1BUS register for the ALT_ECC_EMAC1_RX_ECC instance. */
#define ALT_ECC_EMAC1_RX_ECC_ECC_WDATAECC1BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC1_RX_ECC_ADDR) + ALT_ECC_EMAC1_RX_ECC_ECC_WDATAECC1BUS_OFST))
/* The address of the ALT_ECC_EMAC1_RX_ECC_ECC_DBYTECTL register for the ALT_ECC_EMAC1_RX_ECC instance. */
#define ALT_ECC_EMAC1_RX_ECC_ECC_DBYTECTL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC1_RX_ECC_ADDR) + ALT_ECC_EMAC1_RX_ECC_ECC_DBYTECTL_OFST))
/* The address of the ALT_ECC_EMAC1_RX_ECC_ECC_ACCCTL register for the ALT_ECC_EMAC1_RX_ECC instance. */
#define ALT_ECC_EMAC1_RX_ECC_ECC_ACCCTL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC1_RX_ECC_ADDR) + ALT_ECC_EMAC1_RX_ECC_ECC_ACCCTL_OFST))
/* The address of the ALT_ECC_EMAC1_RX_ECC_ECC_STARTACC register for the ALT_ECC_EMAC1_RX_ECC instance. */
#define ALT_ECC_EMAC1_RX_ECC_ECC_STARTACC_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC1_RX_ECC_ADDR) + ALT_ECC_EMAC1_RX_ECC_ECC_STARTACC_OFST))
/* The address of the ALT_ECC_EMAC1_RX_ECC_ECC_WDCTL register for the ALT_ECC_EMAC1_RX_ECC instance. */
#define ALT_ECC_EMAC1_RX_ECC_ECC_WDCTL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC1_RX_ECC_ADDR) + ALT_ECC_EMAC1_RX_ECC_ECC_WDCTL_OFST))
/* The address of the ALT_ECC_EMAC1_RX_ECC_SERRLKUPA0 register for the ALT_ECC_EMAC1_RX_ECC instance. */
#define ALT_ECC_EMAC1_RX_ECC_SERRLKUPA0_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC1_RX_ECC_ADDR) + ALT_ECC_EMAC1_RX_ECC_SERRLKUPA0_OFST))
/* The base address byte offset for the start of the ALT_ECC_EMAC1_RX_ECC component. */
#define ALT_ECC_EMAC1_RX_ECC_OFST        0xff8c1000
/* The start address of the ALT_ECC_EMAC1_RX_ECC component. */
#define ALT_ECC_EMAC1_RX_ECC_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_ECC_EMAC1_RX_ECC_OFST))
/* The lower bound address range of the ALT_ECC_EMAC1_RX_ECC component. */
#define ALT_ECC_EMAC1_RX_ECC_LB_ADDR     ALT_ECC_EMAC1_RX_ECC_ADDR
/* The upper bound address range of the ALT_ECC_EMAC1_RX_ECC component. */
#define ALT_ECC_EMAC1_RX_ECC_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_ECC_EMAC1_RX_ECC_ADDR) + 0x400) - 1))


/*
 * Component Instance : ecc_emac1_tx_ecc_registerBlock
 * 
 * Instance ecc_emac1_tx_ecc_registerBlock of component ALT_ECC_EMAC1_TX_ECC.
 * 
 * 
 */
/* The address of the ALT_ECC_EMAC1_TX_ECC_IP_REV_ID register for the ALT_ECC_EMAC1_TX_ECC instance. */
#define ALT_ECC_EMAC1_TX_ECC_IP_REV_ID_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC1_TX_ECC_ADDR) + ALT_ECC_EMAC1_TX_ECC_IP_REV_ID_OFST))
/* The address of the ALT_ECC_EMAC1_TX_ECC_CTL register for the ALT_ECC_EMAC1_TX_ECC instance. */
#define ALT_ECC_EMAC1_TX_ECC_CTL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC1_TX_ECC_ADDR) + ALT_ECC_EMAC1_TX_ECC_CTL_OFST))
/* The address of the ALT_ECC_EMAC1_TX_ECC_INITSTAT register for the ALT_ECC_EMAC1_TX_ECC instance. */
#define ALT_ECC_EMAC1_TX_ECC_INITSTAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC1_TX_ECC_ADDR) + ALT_ECC_EMAC1_TX_ECC_INITSTAT_OFST))
/* The address of the ALT_ECC_EMAC1_TX_ECC_ERRINTEN register for the ALT_ECC_EMAC1_TX_ECC instance. */
#define ALT_ECC_EMAC1_TX_ECC_ERRINTEN_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC1_TX_ECC_ADDR) + ALT_ECC_EMAC1_TX_ECC_ERRINTEN_OFST))
/* The address of the ALT_ECC_EMAC1_TX_ECC_ERRINTENS register for the ALT_ECC_EMAC1_TX_ECC instance. */
#define ALT_ECC_EMAC1_TX_ECC_ERRINTENS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC1_TX_ECC_ADDR) + ALT_ECC_EMAC1_TX_ECC_ERRINTENS_OFST))
/* The address of the ALT_ECC_EMAC1_TX_ECC_ERRINTENR register for the ALT_ECC_EMAC1_TX_ECC instance. */
#define ALT_ECC_EMAC1_TX_ECC_ERRINTENR_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC1_TX_ECC_ADDR) + ALT_ECC_EMAC1_TX_ECC_ERRINTENR_OFST))
/* The address of the ALT_ECC_EMAC1_TX_ECC_INTMOD register for the ALT_ECC_EMAC1_TX_ECC instance. */
#define ALT_ECC_EMAC1_TX_ECC_INTMOD_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC1_TX_ECC_ADDR) + ALT_ECC_EMAC1_TX_ECC_INTMOD_OFST))
/* The address of the ALT_ECC_EMAC1_TX_ECC_INTTEST register for the ALT_ECC_EMAC1_TX_ECC instance. */
#define ALT_ECC_EMAC1_TX_ECC_INTTEST_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC1_TX_ECC_ADDR) + ALT_ECC_EMAC1_TX_ECC_INTTEST_OFST))
/* The address of the ALT_ECC_EMAC1_TX_ECC_MODSTAT register for the ALT_ECC_EMAC1_TX_ECC instance. */
#define ALT_ECC_EMAC1_TX_ECC_MODSTAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC1_TX_ECC_ADDR) + ALT_ECC_EMAC1_TX_ECC_MODSTAT_OFST))
/* The address of the ALT_ECC_EMAC1_TX_ECC_DERRADDRA register for the ALT_ECC_EMAC1_TX_ECC instance. */
#define ALT_ECC_EMAC1_TX_ECC_DERRADDRA_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC1_TX_ECC_ADDR) + ALT_ECC_EMAC1_TX_ECC_DERRADDRA_OFST))
/* The address of the ALT_ECC_EMAC1_TX_ECC_SERRADDRA register for the ALT_ECC_EMAC1_TX_ECC instance. */
#define ALT_ECC_EMAC1_TX_ECC_SERRADDRA_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC1_TX_ECC_ADDR) + ALT_ECC_EMAC1_TX_ECC_SERRADDRA_OFST))
/* The address of the ALT_ECC_EMAC1_TX_ECC_INTSTAT register for the ALT_ECC_EMAC1_TX_ECC instance. */
#define ALT_ECC_EMAC1_TX_ECC_INTSTAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC1_TX_ECC_ADDR) + ALT_ECC_EMAC1_TX_ECC_INTSTAT_OFST))
/* The address of the ALT_ECC_EMAC1_TX_ECC_SERRCNTREG register for the ALT_ECC_EMAC1_TX_ECC instance. */
#define ALT_ECC_EMAC1_TX_ECC_SERRCNTREG_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC1_TX_ECC_ADDR) + ALT_ECC_EMAC1_TX_ECC_SERRCNTREG_OFST))
/* The address of the ALT_ECC_EMAC1_TX_ECC_ECC_ADDRBUS register for the ALT_ECC_EMAC1_TX_ECC instance. */
#define ALT_ECC_EMAC1_TX_ECC_ECC_ADDRBUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC1_TX_ECC_ADDR) + ALT_ECC_EMAC1_TX_ECC_ECC_ADDRBUS_OFST))
/* The address of the ALT_ECC_EMAC1_TX_ECC_ECC_RDATA0BUS register for the ALT_ECC_EMAC1_TX_ECC instance. */
#define ALT_ECC_EMAC1_TX_ECC_ECC_RDATA0BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC1_TX_ECC_ADDR) + ALT_ECC_EMAC1_TX_ECC_ECC_RDATA0BUS_OFST))
/* The address of the ALT_ECC_EMAC1_TX_ECC_ECC_RDATA1BUS register for the ALT_ECC_EMAC1_TX_ECC instance. */
#define ALT_ECC_EMAC1_TX_ECC_ECC_RDATA1BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC1_TX_ECC_ADDR) + ALT_ECC_EMAC1_TX_ECC_ECC_RDATA1BUS_OFST))
/* The address of the ALT_ECC_EMAC1_TX_ECC_ECC_RDATA2BUS register for the ALT_ECC_EMAC1_TX_ECC instance. */
#define ALT_ECC_EMAC1_TX_ECC_ECC_RDATA2BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC1_TX_ECC_ADDR) + ALT_ECC_EMAC1_TX_ECC_ECC_RDATA2BUS_OFST))
/* The address of the ALT_ECC_EMAC1_TX_ECC_ECC_RDATA3BUS register for the ALT_ECC_EMAC1_TX_ECC instance. */
#define ALT_ECC_EMAC1_TX_ECC_ECC_RDATA3BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC1_TX_ECC_ADDR) + ALT_ECC_EMAC1_TX_ECC_ECC_RDATA3BUS_OFST))
/* The address of the ALT_ECC_EMAC1_TX_ECC_ECC_WDATA0BUS register for the ALT_ECC_EMAC1_TX_ECC instance. */
#define ALT_ECC_EMAC1_TX_ECC_ECC_WDATA0BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC1_TX_ECC_ADDR) + ALT_ECC_EMAC1_TX_ECC_ECC_WDATA0BUS_OFST))
/* The address of the ALT_ECC_EMAC1_TX_ECC_ECC_WDATA1BUS register for the ALT_ECC_EMAC1_TX_ECC instance. */
#define ALT_ECC_EMAC1_TX_ECC_ECC_WDATA1BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC1_TX_ECC_ADDR) + ALT_ECC_EMAC1_TX_ECC_ECC_WDATA1BUS_OFST))
/* The address of the ALT_ECC_EMAC1_TX_ECC_ECC_WDATA2BUS register for the ALT_ECC_EMAC1_TX_ECC instance. */
#define ALT_ECC_EMAC1_TX_ECC_ECC_WDATA2BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC1_TX_ECC_ADDR) + ALT_ECC_EMAC1_TX_ECC_ECC_WDATA2BUS_OFST))
/* The address of the ALT_ECC_EMAC1_TX_ECC_ECC_WDATA3BUS register for the ALT_ECC_EMAC1_TX_ECC instance. */
#define ALT_ECC_EMAC1_TX_ECC_ECC_WDATA3BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC1_TX_ECC_ADDR) + ALT_ECC_EMAC1_TX_ECC_ECC_WDATA3BUS_OFST))
/* The address of the ALT_ECC_EMAC1_TX_ECC_ECC_RDATAECC0BUS register for the ALT_ECC_EMAC1_TX_ECC instance. */
#define ALT_ECC_EMAC1_TX_ECC_ECC_RDATAECC0BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC1_TX_ECC_ADDR) + ALT_ECC_EMAC1_TX_ECC_ECC_RDATAECC0BUS_OFST))
/* The address of the ALT_ECC_EMAC1_TX_ECC_ECC_RDATAECC1BUS register for the ALT_ECC_EMAC1_TX_ECC instance. */
#define ALT_ECC_EMAC1_TX_ECC_ECC_RDATAECC1BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC1_TX_ECC_ADDR) + ALT_ECC_EMAC1_TX_ECC_ECC_RDATAECC1BUS_OFST))
/* The address of the ALT_ECC_EMAC1_TX_ECC_ECC_WDATAECC0BUS register for the ALT_ECC_EMAC1_TX_ECC instance. */
#define ALT_ECC_EMAC1_TX_ECC_ECC_WDATAECC0BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC1_TX_ECC_ADDR) + ALT_ECC_EMAC1_TX_ECC_ECC_WDATAECC0BUS_OFST))
/* The address of the ALT_ECC_EMAC1_TX_ECC_ECC_WDATAECC1BUS register for the ALT_ECC_EMAC1_TX_ECC instance. */
#define ALT_ECC_EMAC1_TX_ECC_ECC_WDATAECC1BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC1_TX_ECC_ADDR) + ALT_ECC_EMAC1_TX_ECC_ECC_WDATAECC1BUS_OFST))
/* The address of the ALT_ECC_EMAC1_TX_ECC_ECC_DBYTECTL register for the ALT_ECC_EMAC1_TX_ECC instance. */
#define ALT_ECC_EMAC1_TX_ECC_ECC_DBYTECTL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC1_TX_ECC_ADDR) + ALT_ECC_EMAC1_TX_ECC_ECC_DBYTECTL_OFST))
/* The address of the ALT_ECC_EMAC1_TX_ECC_ECC_ACCCTL register for the ALT_ECC_EMAC1_TX_ECC instance. */
#define ALT_ECC_EMAC1_TX_ECC_ECC_ACCCTL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC1_TX_ECC_ADDR) + ALT_ECC_EMAC1_TX_ECC_ECC_ACCCTL_OFST))
/* The address of the ALT_ECC_EMAC1_TX_ECC_ECC_STARTACC register for the ALT_ECC_EMAC1_TX_ECC instance. */
#define ALT_ECC_EMAC1_TX_ECC_ECC_STARTACC_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC1_TX_ECC_ADDR) + ALT_ECC_EMAC1_TX_ECC_ECC_STARTACC_OFST))
/* The address of the ALT_ECC_EMAC1_TX_ECC_ECC_WDCTL register for the ALT_ECC_EMAC1_TX_ECC instance. */
#define ALT_ECC_EMAC1_TX_ECC_ECC_WDCTL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC1_TX_ECC_ADDR) + ALT_ECC_EMAC1_TX_ECC_ECC_WDCTL_OFST))
/* The address of the ALT_ECC_EMAC1_TX_ECC_SERRLKUPA0 register for the ALT_ECC_EMAC1_TX_ECC instance. */
#define ALT_ECC_EMAC1_TX_ECC_SERRLKUPA0_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC1_TX_ECC_ADDR) + ALT_ECC_EMAC1_TX_ECC_SERRLKUPA0_OFST))
/* The base address byte offset for the start of the ALT_ECC_EMAC1_TX_ECC component. */
#define ALT_ECC_EMAC1_TX_ECC_OFST        0xff8c1400
/* The start address of the ALT_ECC_EMAC1_TX_ECC component. */
#define ALT_ECC_EMAC1_TX_ECC_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_ECC_EMAC1_TX_ECC_OFST))
/* The lower bound address range of the ALT_ECC_EMAC1_TX_ECC component. */
#define ALT_ECC_EMAC1_TX_ECC_LB_ADDR     ALT_ECC_EMAC1_TX_ECC_ADDR
/* The upper bound address range of the ALT_ECC_EMAC1_TX_ECC component. */
#define ALT_ECC_EMAC1_TX_ECC_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_ECC_EMAC1_TX_ECC_ADDR) + 0x400) - 1))


/*
 * Component Instance : ecc_emac2_rx_ecc_registerBlock
 * 
 * Instance ecc_emac2_rx_ecc_registerBlock of component ALT_ECC_EMAC2_RX_ECC.
 * 
 * 
 */
/* The address of the ALT_ECC_EMAC2_RX_ECC_IP_REV_ID register for the ALT_ECC_EMAC2_RX_ECC instance. */
#define ALT_ECC_EMAC2_RX_ECC_IP_REV_ID_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC2_RX_ECC_ADDR) + ALT_ECC_EMAC2_RX_ECC_IP_REV_ID_OFST))
/* The address of the ALT_ECC_EMAC2_RX_ECC_CTL register for the ALT_ECC_EMAC2_RX_ECC instance. */
#define ALT_ECC_EMAC2_RX_ECC_CTL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC2_RX_ECC_ADDR) + ALT_ECC_EMAC2_RX_ECC_CTL_OFST))
/* The address of the ALT_ECC_EMAC2_RX_ECC_INITSTAT register for the ALT_ECC_EMAC2_RX_ECC instance. */
#define ALT_ECC_EMAC2_RX_ECC_INITSTAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC2_RX_ECC_ADDR) + ALT_ECC_EMAC2_RX_ECC_INITSTAT_OFST))
/* The address of the ALT_ECC_EMAC2_RX_ECC_ERRINTEN register for the ALT_ECC_EMAC2_RX_ECC instance. */
#define ALT_ECC_EMAC2_RX_ECC_ERRINTEN_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC2_RX_ECC_ADDR) + ALT_ECC_EMAC2_RX_ECC_ERRINTEN_OFST))
/* The address of the ALT_ECC_EMAC2_RX_ECC_ERRINTENS register for the ALT_ECC_EMAC2_RX_ECC instance. */
#define ALT_ECC_EMAC2_RX_ECC_ERRINTENS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC2_RX_ECC_ADDR) + ALT_ECC_EMAC2_RX_ECC_ERRINTENS_OFST))
/* The address of the ALT_ECC_EMAC2_RX_ECC_ERRINTENR register for the ALT_ECC_EMAC2_RX_ECC instance. */
#define ALT_ECC_EMAC2_RX_ECC_ERRINTENR_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC2_RX_ECC_ADDR) + ALT_ECC_EMAC2_RX_ECC_ERRINTENR_OFST))
/* The address of the ALT_ECC_EMAC2_RX_ECC_INTMOD register for the ALT_ECC_EMAC2_RX_ECC instance. */
#define ALT_ECC_EMAC2_RX_ECC_INTMOD_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC2_RX_ECC_ADDR) + ALT_ECC_EMAC2_RX_ECC_INTMOD_OFST))
/* The address of the ALT_ECC_EMAC2_RX_ECC_INTSTAT register for the ALT_ECC_EMAC2_RX_ECC instance. */
#define ALT_ECC_EMAC2_RX_ECC_INTSTAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC2_RX_ECC_ADDR) + ALT_ECC_EMAC2_RX_ECC_INTSTAT_OFST))
/* The address of the ALT_ECC_EMAC2_RX_ECC_INTTEST register for the ALT_ECC_EMAC2_RX_ECC instance. */
#define ALT_ECC_EMAC2_RX_ECC_INTTEST_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC2_RX_ECC_ADDR) + ALT_ECC_EMAC2_RX_ECC_INTTEST_OFST))
/* The address of the ALT_ECC_EMAC2_RX_ECC_MODSTAT register for the ALT_ECC_EMAC2_RX_ECC instance. */
#define ALT_ECC_EMAC2_RX_ECC_MODSTAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC2_RX_ECC_ADDR) + ALT_ECC_EMAC2_RX_ECC_MODSTAT_OFST))
/* The address of the ALT_ECC_EMAC2_RX_ECC_DERRADDRA register for the ALT_ECC_EMAC2_RX_ECC instance. */
#define ALT_ECC_EMAC2_RX_ECC_DERRADDRA_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC2_RX_ECC_ADDR) + ALT_ECC_EMAC2_RX_ECC_DERRADDRA_OFST))
/* The address of the ALT_ECC_EMAC2_RX_ECC_SERRADDRA register for the ALT_ECC_EMAC2_RX_ECC instance. */
#define ALT_ECC_EMAC2_RX_ECC_SERRADDRA_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC2_RX_ECC_ADDR) + ALT_ECC_EMAC2_RX_ECC_SERRADDRA_OFST))
/* The address of the ALT_ECC_EMAC2_RX_ECC_SERRCNTREG register for the ALT_ECC_EMAC2_RX_ECC instance. */
#define ALT_ECC_EMAC2_RX_ECC_SERRCNTREG_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC2_RX_ECC_ADDR) + ALT_ECC_EMAC2_RX_ECC_SERRCNTREG_OFST))
/* The address of the ALT_ECC_EMAC2_RX_ECC_ECC_ADDRBUS register for the ALT_ECC_EMAC2_RX_ECC instance. */
#define ALT_ECC_EMAC2_RX_ECC_ECC_ADDRBUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC2_RX_ECC_ADDR) + ALT_ECC_EMAC2_RX_ECC_ECC_ADDRBUS_OFST))
/* The address of the ALT_ECC_EMAC2_RX_ECC_ECC_RDATA0BUS register for the ALT_ECC_EMAC2_RX_ECC instance. */
#define ALT_ECC_EMAC2_RX_ECC_ECC_RDATA0BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC2_RX_ECC_ADDR) + ALT_ECC_EMAC2_RX_ECC_ECC_RDATA0BUS_OFST))
/* The address of the ALT_ECC_EMAC2_RX_ECC_ECC_RDATA1BUS register for the ALT_ECC_EMAC2_RX_ECC instance. */
#define ALT_ECC_EMAC2_RX_ECC_ECC_RDATA1BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC2_RX_ECC_ADDR) + ALT_ECC_EMAC2_RX_ECC_ECC_RDATA1BUS_OFST))
/* The address of the ALT_ECC_EMAC2_RX_ECC_ECC_RDATA2BUS register for the ALT_ECC_EMAC2_RX_ECC instance. */
#define ALT_ECC_EMAC2_RX_ECC_ECC_RDATA2BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC2_RX_ECC_ADDR) + ALT_ECC_EMAC2_RX_ECC_ECC_RDATA2BUS_OFST))
/* The address of the ALT_ECC_EMAC2_RX_ECC_ECC_RDATA3BUS register for the ALT_ECC_EMAC2_RX_ECC instance. */
#define ALT_ECC_EMAC2_RX_ECC_ECC_RDATA3BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC2_RX_ECC_ADDR) + ALT_ECC_EMAC2_RX_ECC_ECC_RDATA3BUS_OFST))
/* The address of the ALT_ECC_EMAC2_RX_ECC_ECC_WDATA0BUS register for the ALT_ECC_EMAC2_RX_ECC instance. */
#define ALT_ECC_EMAC2_RX_ECC_ECC_WDATA0BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC2_RX_ECC_ADDR) + ALT_ECC_EMAC2_RX_ECC_ECC_WDATA0BUS_OFST))
/* The address of the ALT_ECC_EMAC2_RX_ECC_ECC_WDATA1BUS register for the ALT_ECC_EMAC2_RX_ECC instance. */
#define ALT_ECC_EMAC2_RX_ECC_ECC_WDATA1BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC2_RX_ECC_ADDR) + ALT_ECC_EMAC2_RX_ECC_ECC_WDATA1BUS_OFST))
/* The address of the ALT_ECC_EMAC2_RX_ECC_ECC_WDATA2BUS register for the ALT_ECC_EMAC2_RX_ECC instance. */
#define ALT_ECC_EMAC2_RX_ECC_ECC_WDATA2BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC2_RX_ECC_ADDR) + ALT_ECC_EMAC2_RX_ECC_ECC_WDATA2BUS_OFST))
/* The address of the ALT_ECC_EMAC2_RX_ECC_ECC_WDATA3BUS register for the ALT_ECC_EMAC2_RX_ECC instance. */
#define ALT_ECC_EMAC2_RX_ECC_ECC_WDATA3BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC2_RX_ECC_ADDR) + ALT_ECC_EMAC2_RX_ECC_ECC_WDATA3BUS_OFST))
/* The address of the ALT_ECC_EMAC2_RX_ECC_ECC_RDATAECC0BUS register for the ALT_ECC_EMAC2_RX_ECC instance. */
#define ALT_ECC_EMAC2_RX_ECC_ECC_RDATAECC0BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC2_RX_ECC_ADDR) + ALT_ECC_EMAC2_RX_ECC_ECC_RDATAECC0BUS_OFST))
/* The address of the ALT_ECC_EMAC2_RX_ECC_ECC_RDATAECC1BUS register for the ALT_ECC_EMAC2_RX_ECC instance. */
#define ALT_ECC_EMAC2_RX_ECC_ECC_RDATAECC1BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC2_RX_ECC_ADDR) + ALT_ECC_EMAC2_RX_ECC_ECC_RDATAECC1BUS_OFST))
/* The address of the ALT_ECC_EMAC2_RX_ECC_ECC_WDATAECC0BUS register for the ALT_ECC_EMAC2_RX_ECC instance. */
#define ALT_ECC_EMAC2_RX_ECC_ECC_WDATAECC0BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC2_RX_ECC_ADDR) + ALT_ECC_EMAC2_RX_ECC_ECC_WDATAECC0BUS_OFST))
/* The address of the ALT_ECC_EMAC2_RX_ECC_ECC_WDATAECC1BUS register for the ALT_ECC_EMAC2_RX_ECC instance. */
#define ALT_ECC_EMAC2_RX_ECC_ECC_WDATAECC1BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC2_RX_ECC_ADDR) + ALT_ECC_EMAC2_RX_ECC_ECC_WDATAECC1BUS_OFST))
/* The address of the ALT_ECC_EMAC2_RX_ECC_ECC_DBYTECTL register for the ALT_ECC_EMAC2_RX_ECC instance. */
#define ALT_ECC_EMAC2_RX_ECC_ECC_DBYTECTL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC2_RX_ECC_ADDR) + ALT_ECC_EMAC2_RX_ECC_ECC_DBYTECTL_OFST))
/* The address of the ALT_ECC_EMAC2_RX_ECC_ECC_ACCCTL register for the ALT_ECC_EMAC2_RX_ECC instance. */
#define ALT_ECC_EMAC2_RX_ECC_ECC_ACCCTL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC2_RX_ECC_ADDR) + ALT_ECC_EMAC2_RX_ECC_ECC_ACCCTL_OFST))
/* The address of the ALT_ECC_EMAC2_RX_ECC_ECC_STARTACC register for the ALT_ECC_EMAC2_RX_ECC instance. */
#define ALT_ECC_EMAC2_RX_ECC_ECC_STARTACC_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC2_RX_ECC_ADDR) + ALT_ECC_EMAC2_RX_ECC_ECC_STARTACC_OFST))
/* The address of the ALT_ECC_EMAC2_RX_ECC_ECC_WDCTL register for the ALT_ECC_EMAC2_RX_ECC instance. */
#define ALT_ECC_EMAC2_RX_ECC_ECC_WDCTL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC2_RX_ECC_ADDR) + ALT_ECC_EMAC2_RX_ECC_ECC_WDCTL_OFST))
/* The address of the ALT_ECC_EMAC2_RX_ECC_SERRLKUPA0 register for the ALT_ECC_EMAC2_RX_ECC instance. */
#define ALT_ECC_EMAC2_RX_ECC_SERRLKUPA0_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC2_RX_ECC_ADDR) + ALT_ECC_EMAC2_RX_ECC_SERRLKUPA0_OFST))
/* The base address byte offset for the start of the ALT_ECC_EMAC2_RX_ECC component. */
#define ALT_ECC_EMAC2_RX_ECC_OFST        0xff8c1800
/* The start address of the ALT_ECC_EMAC2_RX_ECC component. */
#define ALT_ECC_EMAC2_RX_ECC_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_ECC_EMAC2_RX_ECC_OFST))
/* The lower bound address range of the ALT_ECC_EMAC2_RX_ECC component. */
#define ALT_ECC_EMAC2_RX_ECC_LB_ADDR     ALT_ECC_EMAC2_RX_ECC_ADDR
/* The upper bound address range of the ALT_ECC_EMAC2_RX_ECC component. */
#define ALT_ECC_EMAC2_RX_ECC_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_ECC_EMAC2_RX_ECC_ADDR) + 0x400) - 1))


/*
 * Component Instance : ecc_emac2_tx_ecc_registerBlock
 * 
 * Instance ecc_emac2_tx_ecc_registerBlock of component ALT_ECC_EMAC2_TX_ECC.
 * 
 * 
 */
/* The address of the ALT_ECC_EMAC2_TX_ECC_IP_REV_ID register for the ALT_ECC_EMAC2_TX_ECC instance. */
#define ALT_ECC_EMAC2_TX_ECC_IP_REV_ID_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC2_TX_ECC_ADDR) + ALT_ECC_EMAC2_TX_ECC_IP_REV_ID_OFST))
/* The address of the ALT_ECC_EMAC2_TX_ECC_CTL register for the ALT_ECC_EMAC2_TX_ECC instance. */
#define ALT_ECC_EMAC2_TX_ECC_CTL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC2_TX_ECC_ADDR) + ALT_ECC_EMAC2_TX_ECC_CTL_OFST))
/* The address of the ALT_ECC_EMAC2_TX_ECC_INITSTAT register for the ALT_ECC_EMAC2_TX_ECC instance. */
#define ALT_ECC_EMAC2_TX_ECC_INITSTAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC2_TX_ECC_ADDR) + ALT_ECC_EMAC2_TX_ECC_INITSTAT_OFST))
/* The address of the ALT_ECC_EMAC2_TX_ECC_ERRINTEN register for the ALT_ECC_EMAC2_TX_ECC instance. */
#define ALT_ECC_EMAC2_TX_ECC_ERRINTEN_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC2_TX_ECC_ADDR) + ALT_ECC_EMAC2_TX_ECC_ERRINTEN_OFST))
/* The address of the ALT_ECC_EMAC2_TX_ECC_ERRINTENS register for the ALT_ECC_EMAC2_TX_ECC instance. */
#define ALT_ECC_EMAC2_TX_ECC_ERRINTENS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC2_TX_ECC_ADDR) + ALT_ECC_EMAC2_TX_ECC_ERRINTENS_OFST))
/* The address of the ALT_ECC_EMAC2_TX_ECC_ERRINTENR register for the ALT_ECC_EMAC2_TX_ECC instance. */
#define ALT_ECC_EMAC2_TX_ECC_ERRINTENR_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC2_TX_ECC_ADDR) + ALT_ECC_EMAC2_TX_ECC_ERRINTENR_OFST))
/* The address of the ALT_ECC_EMAC2_TX_ECC_INTMOD register for the ALT_ECC_EMAC2_TX_ECC instance. */
#define ALT_ECC_EMAC2_TX_ECC_INTMOD_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC2_TX_ECC_ADDR) + ALT_ECC_EMAC2_TX_ECC_INTMOD_OFST))
/* The address of the ALT_ECC_EMAC2_TX_ECC_INTTEST register for the ALT_ECC_EMAC2_TX_ECC instance. */
#define ALT_ECC_EMAC2_TX_ECC_INTTEST_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC2_TX_ECC_ADDR) + ALT_ECC_EMAC2_TX_ECC_INTTEST_OFST))
/* The address of the ALT_ECC_EMAC2_TX_ECC_MODSTAT register for the ALT_ECC_EMAC2_TX_ECC instance. */
#define ALT_ECC_EMAC2_TX_ECC_MODSTAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC2_TX_ECC_ADDR) + ALT_ECC_EMAC2_TX_ECC_MODSTAT_OFST))
/* The address of the ALT_ECC_EMAC2_TX_ECC_DERRADDRA register for the ALT_ECC_EMAC2_TX_ECC instance. */
#define ALT_ECC_EMAC2_TX_ECC_DERRADDRA_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC2_TX_ECC_ADDR) + ALT_ECC_EMAC2_TX_ECC_DERRADDRA_OFST))
/* The address of the ALT_ECC_EMAC2_TX_ECC_SERRADDRA register for the ALT_ECC_EMAC2_TX_ECC instance. */
#define ALT_ECC_EMAC2_TX_ECC_SERRADDRA_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC2_TX_ECC_ADDR) + ALT_ECC_EMAC2_TX_ECC_SERRADDRA_OFST))
/* The address of the ALT_ECC_EMAC2_TX_ECC_INTSTAT register for the ALT_ECC_EMAC2_TX_ECC instance. */
#define ALT_ECC_EMAC2_TX_ECC_INTSTAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC2_TX_ECC_ADDR) + ALT_ECC_EMAC2_TX_ECC_INTSTAT_OFST))
/* The address of the ALT_ECC_EMAC2_TX_ECC_SERRCNTREG register for the ALT_ECC_EMAC2_TX_ECC instance. */
#define ALT_ECC_EMAC2_TX_ECC_SERRCNTREG_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC2_TX_ECC_ADDR) + ALT_ECC_EMAC2_TX_ECC_SERRCNTREG_OFST))
/* The address of the ALT_ECC_EMAC2_TX_ECC_ECC_ADDRBUS register for the ALT_ECC_EMAC2_TX_ECC instance. */
#define ALT_ECC_EMAC2_TX_ECC_ECC_ADDRBUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC2_TX_ECC_ADDR) + ALT_ECC_EMAC2_TX_ECC_ECC_ADDRBUS_OFST))
/* The address of the ALT_ECC_EMAC2_TX_ECC_ECC_RDATA0BUS register for the ALT_ECC_EMAC2_TX_ECC instance. */
#define ALT_ECC_EMAC2_TX_ECC_ECC_RDATA0BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC2_TX_ECC_ADDR) + ALT_ECC_EMAC2_TX_ECC_ECC_RDATA0BUS_OFST))
/* The address of the ALT_ECC_EMAC2_TX_ECC_ECC_RDATA1BUS register for the ALT_ECC_EMAC2_TX_ECC instance. */
#define ALT_ECC_EMAC2_TX_ECC_ECC_RDATA1BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC2_TX_ECC_ADDR) + ALT_ECC_EMAC2_TX_ECC_ECC_RDATA1BUS_OFST))
/* The address of the ALT_ECC_EMAC2_TX_ECC_ECC_RDATA2BUS register for the ALT_ECC_EMAC2_TX_ECC instance. */
#define ALT_ECC_EMAC2_TX_ECC_ECC_RDATA2BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC2_TX_ECC_ADDR) + ALT_ECC_EMAC2_TX_ECC_ECC_RDATA2BUS_OFST))
/* The address of the ALT_ECC_EMAC2_TX_ECC_ECC_RDATA3BUS register for the ALT_ECC_EMAC2_TX_ECC instance. */
#define ALT_ECC_EMAC2_TX_ECC_ECC_RDATA3BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC2_TX_ECC_ADDR) + ALT_ECC_EMAC2_TX_ECC_ECC_RDATA3BUS_OFST))
/* The address of the ALT_ECC_EMAC2_TX_ECC_ECC_WDATA0BUS register for the ALT_ECC_EMAC2_TX_ECC instance. */
#define ALT_ECC_EMAC2_TX_ECC_ECC_WDATA0BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC2_TX_ECC_ADDR) + ALT_ECC_EMAC2_TX_ECC_ECC_WDATA0BUS_OFST))
/* The address of the ALT_ECC_EMAC2_TX_ECC_ECC_WDATA1BUS register for the ALT_ECC_EMAC2_TX_ECC instance. */
#define ALT_ECC_EMAC2_TX_ECC_ECC_WDATA1BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC2_TX_ECC_ADDR) + ALT_ECC_EMAC2_TX_ECC_ECC_WDATA1BUS_OFST))
/* The address of the ALT_ECC_EMAC2_TX_ECC_ECC_WDATA2BUS register for the ALT_ECC_EMAC2_TX_ECC instance. */
#define ALT_ECC_EMAC2_TX_ECC_ECC_WDATA2BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC2_TX_ECC_ADDR) + ALT_ECC_EMAC2_TX_ECC_ECC_WDATA2BUS_OFST))
/* The address of the ALT_ECC_EMAC2_TX_ECC_ECC_WDATA3BUS register for the ALT_ECC_EMAC2_TX_ECC instance. */
#define ALT_ECC_EMAC2_TX_ECC_ECC_WDATA3BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC2_TX_ECC_ADDR) + ALT_ECC_EMAC2_TX_ECC_ECC_WDATA3BUS_OFST))
/* The address of the ALT_ECC_EMAC2_TX_ECC_ECC_RDATAECC0BUS register for the ALT_ECC_EMAC2_TX_ECC instance. */
#define ALT_ECC_EMAC2_TX_ECC_ECC_RDATAECC0BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC2_TX_ECC_ADDR) + ALT_ECC_EMAC2_TX_ECC_ECC_RDATAECC0BUS_OFST))
/* The address of the ALT_ECC_EMAC2_TX_ECC_ECC_RDATAECC1BUS register for the ALT_ECC_EMAC2_TX_ECC instance. */
#define ALT_ECC_EMAC2_TX_ECC_ECC_RDATAECC1BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC2_TX_ECC_ADDR) + ALT_ECC_EMAC2_TX_ECC_ECC_RDATAECC1BUS_OFST))
/* The address of the ALT_ECC_EMAC2_TX_ECC_ECC_WDATAECC0BUS register for the ALT_ECC_EMAC2_TX_ECC instance. */
#define ALT_ECC_EMAC2_TX_ECC_ECC_WDATAECC0BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC2_TX_ECC_ADDR) + ALT_ECC_EMAC2_TX_ECC_ECC_WDATAECC0BUS_OFST))
/* The address of the ALT_ECC_EMAC2_TX_ECC_ECC_WDATAECC1BUS register for the ALT_ECC_EMAC2_TX_ECC instance. */
#define ALT_ECC_EMAC2_TX_ECC_ECC_WDATAECC1BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC2_TX_ECC_ADDR) + ALT_ECC_EMAC2_TX_ECC_ECC_WDATAECC1BUS_OFST))
/* The address of the ALT_ECC_EMAC2_TX_ECC_ECC_DBYTECTL register for the ALT_ECC_EMAC2_TX_ECC instance. */
#define ALT_ECC_EMAC2_TX_ECC_ECC_DBYTECTL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC2_TX_ECC_ADDR) + ALT_ECC_EMAC2_TX_ECC_ECC_DBYTECTL_OFST))
/* The address of the ALT_ECC_EMAC2_TX_ECC_ECC_ACCCTL register for the ALT_ECC_EMAC2_TX_ECC instance. */
#define ALT_ECC_EMAC2_TX_ECC_ECC_ACCCTL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC2_TX_ECC_ADDR) + ALT_ECC_EMAC2_TX_ECC_ECC_ACCCTL_OFST))
/* The address of the ALT_ECC_EMAC2_TX_ECC_ECC_STARTACC register for the ALT_ECC_EMAC2_TX_ECC instance. */
#define ALT_ECC_EMAC2_TX_ECC_ECC_STARTACC_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC2_TX_ECC_ADDR) + ALT_ECC_EMAC2_TX_ECC_ECC_STARTACC_OFST))
/* The address of the ALT_ECC_EMAC2_TX_ECC_ECC_WDCTL register for the ALT_ECC_EMAC2_TX_ECC instance. */
#define ALT_ECC_EMAC2_TX_ECC_ECC_WDCTL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC2_TX_ECC_ADDR) + ALT_ECC_EMAC2_TX_ECC_ECC_WDCTL_OFST))
/* The address of the ALT_ECC_EMAC2_TX_ECC_SERRLKUPA0 register for the ALT_ECC_EMAC2_TX_ECC instance. */
#define ALT_ECC_EMAC2_TX_ECC_SERRLKUPA0_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_EMAC2_TX_ECC_ADDR) + ALT_ECC_EMAC2_TX_ECC_SERRLKUPA0_OFST))
/* The base address byte offset for the start of the ALT_ECC_EMAC2_TX_ECC component. */
#define ALT_ECC_EMAC2_TX_ECC_OFST        0xff8c1c00
/* The start address of the ALT_ECC_EMAC2_TX_ECC component. */
#define ALT_ECC_EMAC2_TX_ECC_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_ECC_EMAC2_TX_ECC_OFST))
/* The lower bound address range of the ALT_ECC_EMAC2_TX_ECC component. */
#define ALT_ECC_EMAC2_TX_ECC_LB_ADDR     ALT_ECC_EMAC2_TX_ECC_ADDR
/* The upper bound address range of the ALT_ECC_EMAC2_TX_ECC component. */
#define ALT_ECC_EMAC2_TX_ECC_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_ECC_EMAC2_TX_ECC_ADDR) + 0x400) - 1))


/*
 * Component Instance : ecc_nandecc_ecc_registerBlock
 * 
 * Instance ecc_nandecc_ecc_registerBlock of component ALT_ECC_NAND.
 * 
 * 
 */
/* The address of the ALT_ECC_NAND_IP_REV_ID register for the ALT_ECC_NAND instance. */
#define ALT_ECC_NAND_IP_REV_ID_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_NAND_ADDR) + ALT_ECC_NAND_IP_REV_ID_OFST))
/* The address of the ALT_ECC_NAND_CTL register for the ALT_ECC_NAND instance. */
#define ALT_ECC_NAND_CTL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_NAND_ADDR) + ALT_ECC_NAND_CTL_OFST))
/* The address of the ALT_ECC_NAND_INITSTAT register for the ALT_ECC_NAND instance. */
#define ALT_ECC_NAND_INITSTAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_NAND_ADDR) + ALT_ECC_NAND_INITSTAT_OFST))
/* The address of the ALT_ECC_NAND_ERRINTEN register for the ALT_ECC_NAND instance. */
#define ALT_ECC_NAND_ERRINTEN_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_NAND_ADDR) + ALT_ECC_NAND_ERRINTEN_OFST))
/* The address of the ALT_ECC_NAND_ERRINTENS register for the ALT_ECC_NAND instance. */
#define ALT_ECC_NAND_ERRINTENS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_NAND_ADDR) + ALT_ECC_NAND_ERRINTENS_OFST))
/* The address of the ALT_ECC_NAND_ERRINTENR register for the ALT_ECC_NAND instance. */
#define ALT_ECC_NAND_ERRINTENR_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_NAND_ADDR) + ALT_ECC_NAND_ERRINTENR_OFST))
/* The address of the ALT_ECC_NAND_INTMOD register for the ALT_ECC_NAND instance. */
#define ALT_ECC_NAND_INTMOD_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_NAND_ADDR) + ALT_ECC_NAND_INTMOD_OFST))
/* The address of the ALT_ECC_NAND_INTSTAT register for the ALT_ECC_NAND instance. */
#define ALT_ECC_NAND_INTSTAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_NAND_ADDR) + ALT_ECC_NAND_INTSTAT_OFST))
/* The address of the ALT_ECC_NAND_INTTEST register for the ALT_ECC_NAND instance. */
#define ALT_ECC_NAND_INTTEST_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_NAND_ADDR) + ALT_ECC_NAND_INTTEST_OFST))
/* The address of the ALT_ECC_NAND_MODSTAT register for the ALT_ECC_NAND instance. */
#define ALT_ECC_NAND_MODSTAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_NAND_ADDR) + ALT_ECC_NAND_MODSTAT_OFST))
/* The address of the ALT_ECC_NAND_DERRADDRA register for the ALT_ECC_NAND instance. */
#define ALT_ECC_NAND_DERRADDRA_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_NAND_ADDR) + ALT_ECC_NAND_DERRADDRA_OFST))
/* The address of the ALT_ECC_NAND_SERRADDRA register for the ALT_ECC_NAND instance. */
#define ALT_ECC_NAND_SERRADDRA_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_NAND_ADDR) + ALT_ECC_NAND_SERRADDRA_OFST))
/* The address of the ALT_ECC_NAND_SERRCNTREG register for the ALT_ECC_NAND instance. */
#define ALT_ECC_NAND_SERRCNTREG_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_NAND_ADDR) + ALT_ECC_NAND_SERRCNTREG_OFST))
/* The address of the ALT_ECC_NAND_ECC_ADDRBUS register for the ALT_ECC_NAND instance. */
#define ALT_ECC_NAND_ECC_ADDRBUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_NAND_ADDR) + ALT_ECC_NAND_ECC_ADDRBUS_OFST))
/* The address of the ALT_ECC_NAND_ECC_RDATA0BUS register for the ALT_ECC_NAND instance. */
#define ALT_ECC_NAND_ECC_RDATA0BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_NAND_ADDR) + ALT_ECC_NAND_ECC_RDATA0BUS_OFST))
/* The address of the ALT_ECC_NAND_ECC_RDATA1BUS register for the ALT_ECC_NAND instance. */
#define ALT_ECC_NAND_ECC_RDATA1BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_NAND_ADDR) + ALT_ECC_NAND_ECC_RDATA1BUS_OFST))
/* The address of the ALT_ECC_NAND_ECC_RDATA2BUS register for the ALT_ECC_NAND instance. */
#define ALT_ECC_NAND_ECC_RDATA2BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_NAND_ADDR) + ALT_ECC_NAND_ECC_RDATA2BUS_OFST))
/* The address of the ALT_ECC_NAND_ECC_RDATA3BUS register for the ALT_ECC_NAND instance. */
#define ALT_ECC_NAND_ECC_RDATA3BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_NAND_ADDR) + ALT_ECC_NAND_ECC_RDATA3BUS_OFST))
/* The address of the ALT_ECC_NAND_ECC_WDATA0BUS register for the ALT_ECC_NAND instance. */
#define ALT_ECC_NAND_ECC_WDATA0BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_NAND_ADDR) + ALT_ECC_NAND_ECC_WDATA0BUS_OFST))
/* The address of the ALT_ECC_NAND_ECC_WDATA1BUS register for the ALT_ECC_NAND instance. */
#define ALT_ECC_NAND_ECC_WDATA1BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_NAND_ADDR) + ALT_ECC_NAND_ECC_WDATA1BUS_OFST))
/* The address of the ALT_ECC_NAND_ECC_WDATA2BUS register for the ALT_ECC_NAND instance. */
#define ALT_ECC_NAND_ECC_WDATA2BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_NAND_ADDR) + ALT_ECC_NAND_ECC_WDATA2BUS_OFST))
/* The address of the ALT_ECC_NAND_ECC_WDATA3BUS register for the ALT_ECC_NAND instance. */
#define ALT_ECC_NAND_ECC_WDATA3BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_NAND_ADDR) + ALT_ECC_NAND_ECC_WDATA3BUS_OFST))
/* The address of the ALT_ECC_NAND_ECC_RDATAECC0BUS register for the ALT_ECC_NAND instance. */
#define ALT_ECC_NAND_ECC_RDATAECC0BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_NAND_ADDR) + ALT_ECC_NAND_ECC_RDATAECC0BUS_OFST))
/* The address of the ALT_ECC_NAND_ECC_RDATAECC1BUS register for the ALT_ECC_NAND instance. */
#define ALT_ECC_NAND_ECC_RDATAECC1BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_NAND_ADDR) + ALT_ECC_NAND_ECC_RDATAECC1BUS_OFST))
/* The address of the ALT_ECC_NAND_ECC_WDATAECC0BUS register for the ALT_ECC_NAND instance. */
#define ALT_ECC_NAND_ECC_WDATAECC0BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_NAND_ADDR) + ALT_ECC_NAND_ECC_WDATAECC0BUS_OFST))
/* The address of the ALT_ECC_NAND_ECC_WDATAECC1BUS register for the ALT_ECC_NAND instance. */
#define ALT_ECC_NAND_ECC_WDATAECC1BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_NAND_ADDR) + ALT_ECC_NAND_ECC_WDATAECC1BUS_OFST))
/* The address of the ALT_ECC_NAND_ECC_DBYTECTL register for the ALT_ECC_NAND instance. */
#define ALT_ECC_NAND_ECC_DBYTECTL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_NAND_ADDR) + ALT_ECC_NAND_ECC_DBYTECTL_OFST))
/* The address of the ALT_ECC_NAND_ECC_ACCCTL register for the ALT_ECC_NAND instance. */
#define ALT_ECC_NAND_ECC_ACCCTL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_NAND_ADDR) + ALT_ECC_NAND_ECC_ACCCTL_OFST))
/* The address of the ALT_ECC_NAND_ECC_STARTACC register for the ALT_ECC_NAND instance. */
#define ALT_ECC_NAND_ECC_STARTACC_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_NAND_ADDR) + ALT_ECC_NAND_ECC_STARTACC_OFST))
/* The address of the ALT_ECC_NAND_ECC_WDCTL register for the ALT_ECC_NAND instance. */
#define ALT_ECC_NAND_ECC_WDCTL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_NAND_ADDR) + ALT_ECC_NAND_ECC_WDCTL_OFST))
/* The address of the ALT_ECC_NAND_SERRLKUPA0 register for the ALT_ECC_NAND instance. */
#define ALT_ECC_NAND_SERRLKUPA0_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_NAND_ADDR) + ALT_ECC_NAND_SERRLKUPA0_OFST))
/* The base address byte offset for the start of the ALT_ECC_NAND component. */
#define ALT_ECC_NAND_OFST        0xff8c2000
/* The start address of the ALT_ECC_NAND component. */
#define ALT_ECC_NAND_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_ECC_NAND_OFST))
/* The lower bound address range of the ALT_ECC_NAND component. */
#define ALT_ECC_NAND_LB_ADDR     ALT_ECC_NAND_ADDR
/* The upper bound address range of the ALT_ECC_NAND component. */
#define ALT_ECC_NAND_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_ECC_NAND_ADDR) + 0x400) - 1))


/*
 * Component Instance : ecc_nandr_ecc_registerBlock
 * 
 * Instance ecc_nandr_ecc_registerBlock of component ALT_ECC_NANDR.
 * 
 * 
 */
/* The address of the ALT_ECC_NANDR_IP_REV_ID register for the ALT_ECC_NANDR instance. */
#define ALT_ECC_NANDR_IP_REV_ID_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_NANDR_ADDR) + ALT_ECC_NANDR_IP_REV_ID_OFST))
/* The address of the ALT_ECC_NANDR_CTL register for the ALT_ECC_NANDR instance. */
#define ALT_ECC_NANDR_CTL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_NANDR_ADDR) + ALT_ECC_NANDR_CTL_OFST))
/* The address of the ALT_ECC_NANDR_INITSTAT register for the ALT_ECC_NANDR instance. */
#define ALT_ECC_NANDR_INITSTAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_NANDR_ADDR) + ALT_ECC_NANDR_INITSTAT_OFST))
/* The address of the ALT_ECC_NANDR_ERRINTEN register for the ALT_ECC_NANDR instance. */
#define ALT_ECC_NANDR_ERRINTEN_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_NANDR_ADDR) + ALT_ECC_NANDR_ERRINTEN_OFST))
/* The address of the ALT_ECC_NANDR_ERRINTENS register for the ALT_ECC_NANDR instance. */
#define ALT_ECC_NANDR_ERRINTENS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_NANDR_ADDR) + ALT_ECC_NANDR_ERRINTENS_OFST))
/* The address of the ALT_ECC_NANDR_ERRINTENR register for the ALT_ECC_NANDR instance. */
#define ALT_ECC_NANDR_ERRINTENR_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_NANDR_ADDR) + ALT_ECC_NANDR_ERRINTENR_OFST))
/* The address of the ALT_ECC_NANDR_INTMOD register for the ALT_ECC_NANDR instance. */
#define ALT_ECC_NANDR_INTMOD_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_NANDR_ADDR) + ALT_ECC_NANDR_INTMOD_OFST))
/* The address of the ALT_ECC_NANDR_INTSTAT register for the ALT_ECC_NANDR instance. */
#define ALT_ECC_NANDR_INTSTAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_NANDR_ADDR) + ALT_ECC_NANDR_INTSTAT_OFST))
/* The address of the ALT_ECC_NANDR_INTTEST register for the ALT_ECC_NANDR instance. */
#define ALT_ECC_NANDR_INTTEST_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_NANDR_ADDR) + ALT_ECC_NANDR_INTTEST_OFST))
/* The address of the ALT_ECC_NANDR_MODSTAT register for the ALT_ECC_NANDR instance. */
#define ALT_ECC_NANDR_MODSTAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_NANDR_ADDR) + ALT_ECC_NANDR_MODSTAT_OFST))
/* The address of the ALT_ECC_NANDR_DERRADDRA register for the ALT_ECC_NANDR instance. */
#define ALT_ECC_NANDR_DERRADDRA_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_NANDR_ADDR) + ALT_ECC_NANDR_DERRADDRA_OFST))
/* The address of the ALT_ECC_NANDR_SERRADDRA register for the ALT_ECC_NANDR instance. */
#define ALT_ECC_NANDR_SERRADDRA_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_NANDR_ADDR) + ALT_ECC_NANDR_SERRADDRA_OFST))
/* The address of the ALT_ECC_NANDR_SERRCNTREG register for the ALT_ECC_NANDR instance. */
#define ALT_ECC_NANDR_SERRCNTREG_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_NANDR_ADDR) + ALT_ECC_NANDR_SERRCNTREG_OFST))
/* The address of the ALT_ECC_NANDR_ADDRBUS register for the ALT_ECC_NANDR instance. */
#define ALT_ECC_NANDR_ECC_ADDRBUS_ADDR  ALT_ECC_NANDR_ADDRBUS_ADDR(ALT_ECC_NANDR_ADDR)
/* The address of the ALT_ECC_NANDR_RDATA0BUS register for the ALT_ECC_NANDR instance. */
#define ALT_ECC_NANDR_ECC_RDATA0BUS_ADDR  ALT_ECC_NANDR_RDATA0BUS_ADDR(ALT_ECC_NANDR_ADDR)
/* The address of the ALT_ECC_NANDR_RDATA1BUS register for the ALT_ECC_NANDR instance. */
#define ALT_ECC_NANDR_ECC_RDATA1BUS_ADDR  ALT_ECC_NANDR_RDATA1BUS_ADDR(ALT_ECC_NANDR_ADDR)
/* The address of the ALT_ECC_NANDR_RDATA2BUS register for the ALT_ECC_NANDR instance. */
#define ALT_ECC_NANDR_ECC_RDATA2BUS_ADDR  ALT_ECC_NANDR_RDATA2BUS_ADDR(ALT_ECC_NANDR_ADDR)
/* The address of the ALT_ECC_NANDR_RDATA3BUS register for the ALT_ECC_NANDR instance. */
#define ALT_ECC_NANDR_ECC_RDATA3BUS_ADDR  ALT_ECC_NANDR_RDATA3BUS_ADDR(ALT_ECC_NANDR_ADDR)
/* The address of the ALT_ECC_NANDR_WDATA0BUS register for the ALT_ECC_NANDR instance. */
#define ALT_ECC_NANDR_ECC_WDATA0BUS_ADDR  ALT_ECC_NANDR_WDATA0BUS_ADDR(ALT_ECC_NANDR_ADDR)
/* The address of the ALT_ECC_NANDR_WDATA1BUS register for the ALT_ECC_NANDR instance. */
#define ALT_ECC_NANDR_ECC_WDATA1BUS_ADDR  ALT_ECC_NANDR_WDATA1BUS_ADDR(ALT_ECC_NANDR_ADDR)
/* The address of the ALT_ECC_NANDR_WDATA2BUS register for the ALT_ECC_NANDR instance. */
#define ALT_ECC_NANDR_ECC_WDATA2BUS_ADDR  ALT_ECC_NANDR_WDATA2BUS_ADDR(ALT_ECC_NANDR_ADDR)
/* The address of the ALT_ECC_NANDR_WDATA3BUS register for the ALT_ECC_NANDR instance. */
#define ALT_ECC_NANDR_ECC_WDATA3BUS_ADDR  ALT_ECC_NANDR_WDATA3BUS_ADDR(ALT_ECC_NANDR_ADDR)
/* The address of the ALT_ECC_NANDR_RDATAECC0BUS register for the ALT_ECC_NANDR instance. */
#define ALT_ECC_NANDR_ECC_RDATAECC0BUS_ADDR  ALT_ECC_NANDR_RDATAECC0BUS_ADDR(ALT_ECC_NANDR_ADDR)
/* The address of the ALT_ECC_NANDR_RDATAECC1BUS register for the ALT_ECC_NANDR instance. */
#define ALT_ECC_NANDR_ECC_RDATAECC1BUS_ADDR  ALT_ECC_NANDR_RDATAECC1BUS_ADDR(ALT_ECC_NANDR_ADDR)
/* The address of the ALT_ECC_NANDR_WDATAECC0BUS register for the ALT_ECC_NANDR instance. */
#define ALT_ECC_NANDR_ECC_WDATAECC0BUS_ADDR  ALT_ECC_NANDR_WDATAECC0BUS_ADDR(ALT_ECC_NANDR_ADDR)
/* The address of the ALT_ECC_NANDR_WDATAECC1BUS register for the ALT_ECC_NANDR instance. */
#define ALT_ECC_NANDR_ECC_WDATAECC1BUS_ADDR  ALT_ECC_NANDR_WDATAECC1BUS_ADDR(ALT_ECC_NANDR_ADDR)
/* The address of the ALT_ECC_NANDR_DBYTECTL register for the ALT_ECC_NANDR instance. */
#define ALT_ECC_NANDR_ECC_DBYTECTL_ADDR  ALT_ECC_NANDR_DBYTECTL_ADDR(ALT_ECC_NANDR_ADDR)
/* The address of the ALT_ECC_NANDR_ACCCTL register for the ALT_ECC_NANDR instance. */
#define ALT_ECC_NANDR_ECC_ACCCTL_ADDR  ALT_ECC_NANDR_ACCCTL_ADDR(ALT_ECC_NANDR_ADDR)
/* The address of the ALT_ECC_NANDR_STARTACC register for the ALT_ECC_NANDR instance. */
#define ALT_ECC_NANDR_ECC_STARTACC_ADDR  ALT_ECC_NANDR_STARTACC_ADDR(ALT_ECC_NANDR_ADDR)
/* The address of the ALT_ECC_NANDR_WDCTL register for the ALT_ECC_NANDR instance. */
#define ALT_ECC_NANDR_ECC_WDCTL_ADDR  ALT_ECC_NANDR_WDCTL_ADDR(ALT_ECC_NANDR_ADDR)
/* The address of the ALT_ECC_NANDR_SERRLKUPA0 register for the ALT_ECC_NANDR instance. */
#define ALT_ECC_NANDR_SERRLKUPA0_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_NANDR_ADDR) + ALT_ECC_NANDR_SERRLKUPA0_OFST))
/* The base address byte offset for the start of the ALT_ECC_NANDR component. */
#define ALT_ECC_NANDR_OFST        0xff8c2400
/* The start address of the ALT_ECC_NANDR component. */
#define ALT_ECC_NANDR_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_ECC_NANDR_OFST))
/* The lower bound address range of the ALT_ECC_NANDR component. */
#define ALT_ECC_NANDR_LB_ADDR     ALT_ECC_NANDR_ADDR
/* The upper bound address range of the ALT_ECC_NANDR component. */
#define ALT_ECC_NANDR_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_ECC_NANDR_ADDR) + 0x400) - 1))


/*
 * Component Instance : ecc_nandw_ecc_registerBlock
 * 
 * Instance ecc_nandw_ecc_registerBlock of component ALT_ECC_NANDW.
 * 
 * 
 */
/* The address of the ALT_ECC_NANDW_IP_REV_ID register for the ALT_ECC_NANDW instance. */
#define ALT_ECC_NANDW_IP_REV_ID_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_NANDW_ADDR) + ALT_ECC_NANDW_IP_REV_ID_OFST))
/* The address of the ALT_ECC_NANDW_CTL register for the ALT_ECC_NANDW instance. */
#define ALT_ECC_NANDW_CTL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_NANDW_ADDR) + ALT_ECC_NANDW_CTL_OFST))
/* The address of the ALT_ECC_NANDW_INITSTAT register for the ALT_ECC_NANDW instance. */
#define ALT_ECC_NANDW_INITSTAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_NANDW_ADDR) + ALT_ECC_NANDW_INITSTAT_OFST))
/* The address of the ALT_ECC_NANDW_ERRINTEN register for the ALT_ECC_NANDW instance. */
#define ALT_ECC_NANDW_ERRINTEN_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_NANDW_ADDR) + ALT_ECC_NANDW_ERRINTEN_OFST))
/* The address of the ALT_ECC_NANDW_ERRINTENS register for the ALT_ECC_NANDW instance. */
#define ALT_ECC_NANDW_ERRINTENS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_NANDW_ADDR) + ALT_ECC_NANDW_ERRINTENS_OFST))
/* The address of the ALT_ECC_NANDW_ERRINTENR register for the ALT_ECC_NANDW instance. */
#define ALT_ECC_NANDW_ERRINTENR_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_NANDW_ADDR) + ALT_ECC_NANDW_ERRINTENR_OFST))
/* The address of the ALT_ECC_NANDW_INTMOD register for the ALT_ECC_NANDW instance. */
#define ALT_ECC_NANDW_INTMOD_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_NANDW_ADDR) + ALT_ECC_NANDW_INTMOD_OFST))
/* The address of the ALT_ECC_NANDW_INTSTAT register for the ALT_ECC_NANDW instance. */
#define ALT_ECC_NANDW_INTSTAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_NANDW_ADDR) + ALT_ECC_NANDW_INTSTAT_OFST))
/* The address of the ALT_ECC_NANDW_INTTEST register for the ALT_ECC_NANDW instance. */
#define ALT_ECC_NANDW_INTTEST_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_NANDW_ADDR) + ALT_ECC_NANDW_INTTEST_OFST))
/* The address of the ALT_ECC_NANDW_MODSTAT register for the ALT_ECC_NANDW instance. */
#define ALT_ECC_NANDW_MODSTAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_NANDW_ADDR) + ALT_ECC_NANDW_MODSTAT_OFST))
/* The address of the ALT_ECC_NANDW_DERRADDRA register for the ALT_ECC_NANDW instance. */
#define ALT_ECC_NANDW_DERRADDRA_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_NANDW_ADDR) + ALT_ECC_NANDW_DERRADDRA_OFST))
/* The address of the ALT_ECC_NANDW_SERRADDRA register for the ALT_ECC_NANDW instance. */
#define ALT_ECC_NANDW_SERRADDRA_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_NANDW_ADDR) + ALT_ECC_NANDW_SERRADDRA_OFST))
/* The address of the ALT_ECC_NANDW_SERRCNTREG register for the ALT_ECC_NANDW instance. */
#define ALT_ECC_NANDW_SERRCNTREG_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_NANDW_ADDR) + ALT_ECC_NANDW_SERRCNTREG_OFST))
/* The address of the ALT_ECC_NANDW_ADDRBUS register for the ALT_ECC_NANDW instance. */
#define ALT_ECC_NANDW_ECC_ADDRBUS_ADDR  ALT_ECC_NANDW_ADDRBUS_ADDR(ALT_ECC_NANDW_ADDR)
/* The address of the ALT_ECC_NANDW_RDATA0BUS register for the ALT_ECC_NANDW instance. */
#define ALT_ECC_NANDW_ECC_RDATA0BUS_ADDR  ALT_ECC_NANDW_RDATA0BUS_ADDR(ALT_ECC_NANDW_ADDR)
/* The address of the ALT_ECC_NANDW_RDATA1BUS register for the ALT_ECC_NANDW instance. */
#define ALT_ECC_NANDW_ECC_RDATA1BUS_ADDR  ALT_ECC_NANDW_RDATA1BUS_ADDR(ALT_ECC_NANDW_ADDR)
/* The address of the ALT_ECC_NANDW_RDATA2BUS register for the ALT_ECC_NANDW instance. */
#define ALT_ECC_NANDW_ECC_RDATA2BUS_ADDR  ALT_ECC_NANDW_RDATA2BUS_ADDR(ALT_ECC_NANDW_ADDR)
/* The address of the ALT_ECC_NANDW_RDATA3BUS register for the ALT_ECC_NANDW instance. */
#define ALT_ECC_NANDW_ECC_RDATA3BUS_ADDR  ALT_ECC_NANDW_RDATA3BUS_ADDR(ALT_ECC_NANDW_ADDR)
/* The address of the ALT_ECC_NANDW_WDATA0BUS register for the ALT_ECC_NANDW instance. */
#define ALT_ECC_NANDW_ECC_WDATA0BUS_ADDR  ALT_ECC_NANDW_WDATA0BUS_ADDR(ALT_ECC_NANDW_ADDR)
/* The address of the ALT_ECC_NANDW_WDATA1BUS register for the ALT_ECC_NANDW instance. */
#define ALT_ECC_NANDW_ECC_WDATA1BUS_ADDR  ALT_ECC_NANDW_WDATA1BUS_ADDR(ALT_ECC_NANDW_ADDR)
/* The address of the ALT_ECC_NANDW_WDATA2BUS register for the ALT_ECC_NANDW instance. */
#define ALT_ECC_NANDW_ECC_WDATA2BUS_ADDR  ALT_ECC_NANDW_WDATA2BUS_ADDR(ALT_ECC_NANDW_ADDR)
/* The address of the ALT_ECC_NANDW_WDATA3BUS register for the ALT_ECC_NANDW instance. */
#define ALT_ECC_NANDW_ECC_WDATA3BUS_ADDR  ALT_ECC_NANDW_WDATA3BUS_ADDR(ALT_ECC_NANDW_ADDR)
/* The address of the ALT_ECC_NANDW_RDATAECC0BUS register for the ALT_ECC_NANDW instance. */
#define ALT_ECC_NANDW_ECC_RDATAECC0BUS_ADDR  ALT_ECC_NANDW_RDATAECC0BUS_ADDR(ALT_ECC_NANDW_ADDR)
/* The address of the ALT_ECC_NANDW_RDATAECC1BUS register for the ALT_ECC_NANDW instance. */
#define ALT_ECC_NANDW_ECC_RDATAECC1BUS_ADDR  ALT_ECC_NANDW_RDATAECC1BUS_ADDR(ALT_ECC_NANDW_ADDR)
/* The address of the ALT_ECC_NANDW_WDATAECC0BUS register for the ALT_ECC_NANDW instance. */
#define ALT_ECC_NANDW_ECC_WDATAECC0BUS_ADDR  ALT_ECC_NANDW_WDATAECC0BUS_ADDR(ALT_ECC_NANDW_ADDR)
/* The address of the ALT_ECC_NANDW_WDATAECC1BUS register for the ALT_ECC_NANDW instance. */
#define ALT_ECC_NANDW_ECC_WDATAECC1BUS_ADDR  ALT_ECC_NANDW_WDATAECC1BUS_ADDR(ALT_ECC_NANDW_ADDR)
/* The address of the ALT_ECC_NANDW_DBYTECTL register for the ALT_ECC_NANDW instance. */
#define ALT_ECC_NANDW_ECC_DBYTECTL_ADDR  ALT_ECC_NANDW_DBYTECTL_ADDR(ALT_ECC_NANDW_ADDR)
/* The address of the ALT_ECC_NANDW_ACCCTL register for the ALT_ECC_NANDW instance. */
#define ALT_ECC_NANDW_ECC_ACCCTL_ADDR  ALT_ECC_NANDW_ACCCTL_ADDR(ALT_ECC_NANDW_ADDR)
/* The address of the ALT_ECC_NANDW_STARTACC register for the ALT_ECC_NANDW instance. */
#define ALT_ECC_NANDW_ECC_STARTACC_ADDR  ALT_ECC_NANDW_STARTACC_ADDR(ALT_ECC_NANDW_ADDR)
/* The address of the ALT_ECC_NANDW_WDCTL register for the ALT_ECC_NANDW instance. */
#define ALT_ECC_NANDW_ECC_WDCTL_ADDR  ALT_ECC_NANDW_WDCTL_ADDR(ALT_ECC_NANDW_ADDR)
/* The address of the ALT_ECC_NANDW_SERRLKUPA0 register for the ALT_ECC_NANDW instance. */
#define ALT_ECC_NANDW_SERRLKUPA0_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_NANDW_ADDR) + ALT_ECC_NANDW_SERRLKUPA0_OFST))
/* The base address byte offset for the start of the ALT_ECC_NANDW component. */
#define ALT_ECC_NANDW_OFST        0xff8c2800
/* The start address of the ALT_ECC_NANDW component. */
#define ALT_ECC_NANDW_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_ECC_NANDW_OFST))
/* The lower bound address range of the ALT_ECC_NANDW component. */
#define ALT_ECC_NANDW_LB_ADDR     ALT_ECC_NANDW_ADDR
/* The upper bound address range of the ALT_ECC_NANDW component. */
#define ALT_ECC_NANDW_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_ECC_NANDW_ADDR) + 0x400) - 1))


/*
 * Component Instance : ecc_sdmmc_ecc_registerBlock
 * 
 * Instance ecc_sdmmc_ecc_registerBlock of component ALT_ECC_SDMMC.
 * 
 * 
 */
/* The address of the ALT_ECC_SDMMC_IP_REV_ID register for the ALT_ECC_SDMMC instance. */
#define ALT_ECC_SDMMC_IP_REV_ID_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_SDMMC_ADDR) + ALT_ECC_SDMMC_IP_REV_ID_OFST))
/* The address of the ALT_ECC_SDMMC_CTL register for the ALT_ECC_SDMMC instance. */
#define ALT_ECC_SDMMC_CTL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_SDMMC_ADDR) + ALT_ECC_SDMMC_CTL_OFST))
/* The address of the ALT_ECC_SDMMC_INITSTAT register for the ALT_ECC_SDMMC instance. */
#define ALT_ECC_SDMMC_INITSTAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_SDMMC_ADDR) + ALT_ECC_SDMMC_INITSTAT_OFST))
/* The address of the ALT_ECC_SDMMC_ERRINTEN register for the ALT_ECC_SDMMC instance. */
#define ALT_ECC_SDMMC_ERRINTEN_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_SDMMC_ADDR) + ALT_ECC_SDMMC_ERRINTEN_OFST))
/* The address of the ALT_ECC_SDMMC_ERRINTENS register for the ALT_ECC_SDMMC instance. */
#define ALT_ECC_SDMMC_ERRINTENS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_SDMMC_ADDR) + ALT_ECC_SDMMC_ERRINTENS_OFST))
/* The address of the ALT_ECC_SDMMC_ERRINTENR register for the ALT_ECC_SDMMC instance. */
#define ALT_ECC_SDMMC_ERRINTENR_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_SDMMC_ADDR) + ALT_ECC_SDMMC_ERRINTENR_OFST))
/* The address of the ALT_ECC_SDMMC_INTMOD register for the ALT_ECC_SDMMC instance. */
#define ALT_ECC_SDMMC_INTMOD_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_SDMMC_ADDR) + ALT_ECC_SDMMC_INTMOD_OFST))
/* The address of the ALT_ECC_SDMMC_INTSTAT register for the ALT_ECC_SDMMC instance. */
#define ALT_ECC_SDMMC_INTSTAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_SDMMC_ADDR) + ALT_ECC_SDMMC_INTSTAT_OFST))
/* The address of the ALT_ECC_SDMMC_INTTEST register for the ALT_ECC_SDMMC instance. */
#define ALT_ECC_SDMMC_INTTEST_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_SDMMC_ADDR) + ALT_ECC_SDMMC_INTTEST_OFST))
/* The address of the ALT_ECC_SDMMC_MODSTAT register for the ALT_ECC_SDMMC instance. */
#define ALT_ECC_SDMMC_MODSTAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_SDMMC_ADDR) + ALT_ECC_SDMMC_MODSTAT_OFST))
/* The address of the ALT_ECC_SDMMC_DERRADDRA register for the ALT_ECC_SDMMC instance. */
#define ALT_ECC_SDMMC_DERRADDRA_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_SDMMC_ADDR) + ALT_ECC_SDMMC_DERRADDRA_OFST))
/* The address of the ALT_ECC_SDMMC_SERRADDRA register for the ALT_ECC_SDMMC instance. */
#define ALT_ECC_SDMMC_SERRADDRA_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_SDMMC_ADDR) + ALT_ECC_SDMMC_SERRADDRA_OFST))
/* The address of the ALT_ECC_SDMMC_DERRADDRB register for the ALT_ECC_SDMMC instance. */
#define ALT_ECC_SDMMC_DERRADDRB_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_SDMMC_ADDR) + ALT_ECC_SDMMC_DERRADDRB_OFST))
/* The address of the ALT_ECC_SDMMC_SERRADDRB register for the ALT_ECC_SDMMC instance. */
#define ALT_ECC_SDMMC_SERRADDRB_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_SDMMC_ADDR) + ALT_ECC_SDMMC_SERRADDRB_OFST))
/* The address of the ALT_ECC_SDMMC_SERRCNTREG register for the ALT_ECC_SDMMC instance. */
#define ALT_ECC_SDMMC_SERRCNTREG_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_SDMMC_ADDR) + ALT_ECC_SDMMC_SERRCNTREG_OFST))
/* The address of the ALT_ECC_SDMMC_ADDRBUS register for the ALT_ECC_SDMMC instance. */
#define ALT_ECC_SDMMC_ECC_ADDRBUS_ADDR  ALT_ECC_SDMMC_ADDRBUS_ADDR(ALT_ECC_SDMMC_ADDR)
/* The address of the ALT_ECC_SDMMC_RDATA0BUS register for the ALT_ECC_SDMMC instance. */
#define ALT_ECC_SDMMC_ECC_RDATA0BUS_ADDR  ALT_ECC_SDMMC_RDATA0BUS_ADDR(ALT_ECC_SDMMC_ADDR)
/* The address of the ALT_ECC_SDMMC_RDATA1BUS register for the ALT_ECC_SDMMC instance. */
#define ALT_ECC_SDMMC_ECC_RDATA1BUS_ADDR  ALT_ECC_SDMMC_RDATA1BUS_ADDR(ALT_ECC_SDMMC_ADDR)
/* The address of the ALT_ECC_SDMMC_RDATA2BUS register for the ALT_ECC_SDMMC instance. */
#define ALT_ECC_SDMMC_ECC_RDATA2BUS_ADDR  ALT_ECC_SDMMC_RDATA2BUS_ADDR(ALT_ECC_SDMMC_ADDR)
/* The address of the ALT_ECC_SDMMC_RDATA3BUS register for the ALT_ECC_SDMMC instance. */
#define ALT_ECC_SDMMC_ECC_RDATA3BUS_ADDR  ALT_ECC_SDMMC_RDATA3BUS_ADDR(ALT_ECC_SDMMC_ADDR)
/* The address of the ALT_ECC_SDMMC_WDATA0BUS register for the ALT_ECC_SDMMC instance. */
#define ALT_ECC_SDMMC_ECC_WDATA0BUS_ADDR  ALT_ECC_SDMMC_WDATA0BUS_ADDR(ALT_ECC_SDMMC_ADDR)
/* The address of the ALT_ECC_SDMMC_WDATA1BUS register for the ALT_ECC_SDMMC instance. */
#define ALT_ECC_SDMMC_ECC_WDATA1BUS_ADDR  ALT_ECC_SDMMC_WDATA1BUS_ADDR(ALT_ECC_SDMMC_ADDR)
/* The address of the ALT_ECC_SDMMC_WDATA2BUS register for the ALT_ECC_SDMMC instance. */
#define ALT_ECC_SDMMC_ECC_WDATA2BUS_ADDR  ALT_ECC_SDMMC_WDATA2BUS_ADDR(ALT_ECC_SDMMC_ADDR)
/* The address of the ALT_ECC_SDMMC_WDATA3BUS register for the ALT_ECC_SDMMC instance. */
#define ALT_ECC_SDMMC_ECC_WDATA3BUS_ADDR  ALT_ECC_SDMMC_WDATA3BUS_ADDR(ALT_ECC_SDMMC_ADDR)
/* The address of the ALT_ECC_SDMMC_RDATAECC0BUS register for the ALT_ECC_SDMMC instance. */
#define ALT_ECC_SDMMC_ECC_RDATAECC0BUS_ADDR  ALT_ECC_SDMMC_RDATAECC0BUS_ADDR(ALT_ECC_SDMMC_ADDR)
/* The address of the ALT_ECC_SDMMC_RDATAECC1BUS register for the ALT_ECC_SDMMC instance. */
#define ALT_ECC_SDMMC_ECC_RDATAECC1BUS_ADDR  ALT_ECC_SDMMC_RDATAECC1BUS_ADDR(ALT_ECC_SDMMC_ADDR)
/* The address of the ALT_ECC_SDMMC_WDATAECC0BUS register for the ALT_ECC_SDMMC instance. */
#define ALT_ECC_SDMMC_ECC_WDATAECC0BUS_ADDR  ALT_ECC_SDMMC_WDATAECC0BUS_ADDR(ALT_ECC_SDMMC_ADDR)
/* The address of the ALT_ECC_SDMMC_WDATAECC1BUS register for the ALT_ECC_SDMMC instance. */
#define ALT_ECC_SDMMC_ECC_WDATAECC1BUS_ADDR  ALT_ECC_SDMMC_WDATAECC1BUS_ADDR(ALT_ECC_SDMMC_ADDR)
/* The address of the ALT_ECC_SDMMC_DBYTECTL register for the ALT_ECC_SDMMC instance. */
#define ALT_ECC_SDMMC_ECC_DBYTECTL_ADDR  ALT_ECC_SDMMC_DBYTECTL_ADDR(ALT_ECC_SDMMC_ADDR)
/* The address of the ALT_ECC_SDMMC_ACCCTL register for the ALT_ECC_SDMMC instance. */
#define ALT_ECC_SDMMC_ECC_ACCCTL_ADDR  ALT_ECC_SDMMC_ACCCTL_ADDR(ALT_ECC_SDMMC_ADDR)
/* The address of the ALT_ECC_SDMMC_STARTACC register for the ALT_ECC_SDMMC instance. */
#define ALT_ECC_SDMMC_ECC_STARTACC_ADDR  ALT_ECC_SDMMC_STARTACC_ADDR(ALT_ECC_SDMMC_ADDR)
/* The address of the ALT_ECC_SDMMC_WDCTL register for the ALT_ECC_SDMMC instance. */
#define ALT_ECC_SDMMC_ECC_WDCTL_ADDR  ALT_ECC_SDMMC_WDCTL_ADDR(ALT_ECC_SDMMC_ADDR)
/* The address of the ALT_ECC_SDMMC_SERRLKUPA0 register for the ALT_ECC_SDMMC instance. */
#define ALT_ECC_SDMMC_SERRLKUPA0_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_SDMMC_ADDR) + ALT_ECC_SDMMC_SERRLKUPA0_OFST))
/* The address of the ALT_ECC_SDMMC_SERRLKUPB0 register for the ALT_ECC_SDMMC instance. */
#define ALT_ECC_SDMMC_SERRLKUPB0_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_SDMMC_ADDR) + ALT_ECC_SDMMC_SERRLKUPB0_OFST))
/* The base address byte offset for the start of the ALT_ECC_SDMMC component. */
#define ALT_ECC_SDMMC_OFST        0xff8c2c00
/* The start address of the ALT_ECC_SDMMC component. */
#define ALT_ECC_SDMMC_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_ECC_SDMMC_OFST))
/* The lower bound address range of the ALT_ECC_SDMMC component. */
#define ALT_ECC_SDMMC_LB_ADDR     ALT_ECC_SDMMC_ADDR
/* The upper bound address range of the ALT_ECC_SDMMC component. */
#define ALT_ECC_SDMMC_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_ECC_SDMMC_ADDR) + 0x400) - 1))


/*
 * Component Instance : ecc_onchip_ram_ecc_registerBlock
 * 
 * Instance ecc_onchip_ram_ecc_registerBlock of component ALT_ECC_OCRAM_ECC.
 * 
 * 
 */
/* The address of the ALT_ECC_OCRAM_ECC_IP_REV_ID register for the ALT_ECC_OCRAM_ECC instance. */
#define ALT_ECC_OCRAM_ECC_IP_REV_ID_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OCRAM_ECC_ADDR) + ALT_ECC_OCRAM_ECC_IP_REV_ID_OFST))
/* The address of the ALT_ECC_OCRAM_ECC_CTL register for the ALT_ECC_OCRAM_ECC instance. */
#define ALT_ECC_OCRAM_ECC_CTL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OCRAM_ECC_ADDR) + ALT_ECC_OCRAM_ECC_CTL_OFST))
/* The address of the ALT_ECC_OCRAM_ECC_INITSTAT register for the ALT_ECC_OCRAM_ECC instance. */
#define ALT_ECC_OCRAM_ECC_INITSTAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OCRAM_ECC_ADDR) + ALT_ECC_OCRAM_ECC_INITSTAT_OFST))
/* The address of the ALT_ECC_OCRAM_ECC_ERRINTEN register for the ALT_ECC_OCRAM_ECC instance. */
#define ALT_ECC_OCRAM_ECC_ERRINTEN_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OCRAM_ECC_ADDR) + ALT_ECC_OCRAM_ECC_ERRINTEN_OFST))
/* The address of the ALT_ECC_OCRAM_ECC_ERRINTENS register for the ALT_ECC_OCRAM_ECC instance. */
#define ALT_ECC_OCRAM_ECC_ERRINTENS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OCRAM_ECC_ADDR) + ALT_ECC_OCRAM_ECC_ERRINTENS_OFST))
/* The address of the ALT_ECC_OCRAM_ECC_ERRINTENR register for the ALT_ECC_OCRAM_ECC instance. */
#define ALT_ECC_OCRAM_ECC_ERRINTENR_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OCRAM_ECC_ADDR) + ALT_ECC_OCRAM_ECC_ERRINTENR_OFST))
/* The address of the ALT_ECC_OCRAM_ECC_INTMOD register for the ALT_ECC_OCRAM_ECC instance. */
#define ALT_ECC_OCRAM_ECC_INTMOD_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OCRAM_ECC_ADDR) + ALT_ECC_OCRAM_ECC_INTMOD_OFST))
/* The address of the ALT_ECC_OCRAM_ECC_INTSTAT register for the ALT_ECC_OCRAM_ECC instance. */
#define ALT_ECC_OCRAM_ECC_INTSTAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OCRAM_ECC_ADDR) + ALT_ECC_OCRAM_ECC_INTSTAT_OFST))
/* The address of the ALT_ECC_OCRAM_ECC_INTTEST register for the ALT_ECC_OCRAM_ECC instance. */
#define ALT_ECC_OCRAM_ECC_INTTEST_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OCRAM_ECC_ADDR) + ALT_ECC_OCRAM_ECC_INTTEST_OFST))
/* The address of the ALT_ECC_OCRAM_ECC_MODSTAT register for the ALT_ECC_OCRAM_ECC instance. */
#define ALT_ECC_OCRAM_ECC_MODSTAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OCRAM_ECC_ADDR) + ALT_ECC_OCRAM_ECC_MODSTAT_OFST))
/* The address of the ALT_ECC_OCRAM_ECC_DERRADDRA register for the ALT_ECC_OCRAM_ECC instance. */
#define ALT_ECC_OCRAM_ECC_DERRADDRA_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OCRAM_ECC_ADDR) + ALT_ECC_OCRAM_ECC_DERRADDRA_OFST))
/* The address of the ALT_ECC_OCRAM_ECC_SERRADDRA register for the ALT_ECC_OCRAM_ECC instance. */
#define ALT_ECC_OCRAM_ECC_SERRADDRA_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OCRAM_ECC_ADDR) + ALT_ECC_OCRAM_ECC_SERRADDRA_OFST))
/* The address of the ALT_ECC_OCRAM_ECC_SERRCNTREG register for the ALT_ECC_OCRAM_ECC instance. */
#define ALT_ECC_OCRAM_ECC_SERRCNTREG_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OCRAM_ECC_ADDR) + ALT_ECC_OCRAM_ECC_SERRCNTREG_OFST))
/* The address of the ALT_ECC_OCRAM_ECC_ECC_ADDRBUS register for the ALT_ECC_OCRAM_ECC instance. */
#define ALT_ECC_OCRAM_ECC_ECC_ADDRBUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OCRAM_ECC_ADDR) + ALT_ECC_OCRAM_ECC_ECC_ADDRBUS_OFST))
/* The address of the ALT_ECC_OCRAM_ECC_ECC_RDATA0BUS register for the ALT_ECC_OCRAM_ECC instance. */
#define ALT_ECC_OCRAM_ECC_ECC_RDATA0BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OCRAM_ECC_ADDR) + ALT_ECC_OCRAM_ECC_ECC_RDATA0BUS_OFST))
/* The address of the ALT_ECC_OCRAM_ECC_ECC_RDATA1BUS register for the ALT_ECC_OCRAM_ECC instance. */
#define ALT_ECC_OCRAM_ECC_ECC_RDATA1BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OCRAM_ECC_ADDR) + ALT_ECC_OCRAM_ECC_ECC_RDATA1BUS_OFST))
/* The address of the ALT_ECC_OCRAM_ECC_ECC_RDATA2BUS register for the ALT_ECC_OCRAM_ECC instance. */
#define ALT_ECC_OCRAM_ECC_ECC_RDATA2BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OCRAM_ECC_ADDR) + ALT_ECC_OCRAM_ECC_ECC_RDATA2BUS_OFST))
/* The address of the ALT_ECC_OCRAM_ECC_ECC_RDATA3BUS register for the ALT_ECC_OCRAM_ECC instance. */
#define ALT_ECC_OCRAM_ECC_ECC_RDATA3BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OCRAM_ECC_ADDR) + ALT_ECC_OCRAM_ECC_ECC_RDATA3BUS_OFST))
/* The address of the ALT_ECC_OCRAM_ECC_ECC_WDATA0BUS register for the ALT_ECC_OCRAM_ECC instance. */
#define ALT_ECC_OCRAM_ECC_ECC_WDATA0BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OCRAM_ECC_ADDR) + ALT_ECC_OCRAM_ECC_ECC_WDATA0BUS_OFST))
/* The address of the ALT_ECC_OCRAM_ECC_ECC_WDATA1BUS register for the ALT_ECC_OCRAM_ECC instance. */
#define ALT_ECC_OCRAM_ECC_ECC_WDATA1BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OCRAM_ECC_ADDR) + ALT_ECC_OCRAM_ECC_ECC_WDATA1BUS_OFST))
/* The address of the ALT_ECC_OCRAM_ECC_ECC_WDATA2BUS register for the ALT_ECC_OCRAM_ECC instance. */
#define ALT_ECC_OCRAM_ECC_ECC_WDATA2BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OCRAM_ECC_ADDR) + ALT_ECC_OCRAM_ECC_ECC_WDATA2BUS_OFST))
/* The address of the ALT_ECC_OCRAM_ECC_ECC_WDATA3BUS register for the ALT_ECC_OCRAM_ECC instance. */
#define ALT_ECC_OCRAM_ECC_ECC_WDATA3BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OCRAM_ECC_ADDR) + ALT_ECC_OCRAM_ECC_ECC_WDATA3BUS_OFST))
/* The address of the ALT_ECC_OCRAM_ECC_ECC_RDATAECC0BUS register for the ALT_ECC_OCRAM_ECC instance. */
#define ALT_ECC_OCRAM_ECC_ECC_RDATAECC0BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OCRAM_ECC_ADDR) + ALT_ECC_OCRAM_ECC_ECC_RDATAECC0BUS_OFST))
/* The address of the ALT_ECC_OCRAM_ECC_ECC_RDATAECC1BUS register for the ALT_ECC_OCRAM_ECC instance. */
#define ALT_ECC_OCRAM_ECC_ECC_RDATAECC1BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OCRAM_ECC_ADDR) + ALT_ECC_OCRAM_ECC_ECC_RDATAECC1BUS_OFST))
/* The address of the ALT_ECC_OCRAM_ECC_ECC_WDATAECC0BUS register for the ALT_ECC_OCRAM_ECC instance. */
#define ALT_ECC_OCRAM_ECC_ECC_WDATAECC0BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OCRAM_ECC_ADDR) + ALT_ECC_OCRAM_ECC_ECC_WDATAECC0BUS_OFST))
/* The address of the ALT_ECC_OCRAM_ECC_ECC_WDATAECC1BUS register for the ALT_ECC_OCRAM_ECC instance. */
#define ALT_ECC_OCRAM_ECC_ECC_WDATAECC1BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OCRAM_ECC_ADDR) + ALT_ECC_OCRAM_ECC_ECC_WDATAECC1BUS_OFST))
/* The address of the ALT_ECC_OCRAM_ECC_ECC_DBYTECTL register for the ALT_ECC_OCRAM_ECC instance. */
#define ALT_ECC_OCRAM_ECC_ECC_DBYTECTL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OCRAM_ECC_ADDR) + ALT_ECC_OCRAM_ECC_ECC_DBYTECTL_OFST))
/* The address of the ALT_ECC_OCRAM_ECC_ECC_ACCCTL register for the ALT_ECC_OCRAM_ECC instance. */
#define ALT_ECC_OCRAM_ECC_ECC_ACCCTL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OCRAM_ECC_ADDR) + ALT_ECC_OCRAM_ECC_ECC_ACCCTL_OFST))
/* The address of the ALT_ECC_OCRAM_ECC_ECC_STARTACC register for the ALT_ECC_OCRAM_ECC instance. */
#define ALT_ECC_OCRAM_ECC_ECC_STARTACC_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OCRAM_ECC_ADDR) + ALT_ECC_OCRAM_ECC_ECC_STARTACC_OFST))
/* The address of the ALT_ECC_OCRAM_ECC_ECC_WDCTL register for the ALT_ECC_OCRAM_ECC instance. */
#define ALT_ECC_OCRAM_ECC_ECC_WDCTL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OCRAM_ECC_ADDR) + ALT_ECC_OCRAM_ECC_ECC_WDCTL_OFST))
/* The address of the ALT_ECC_OCRAM_ECC_SERRLKUPA0 register for the ALT_ECC_OCRAM_ECC instance. */
#define ALT_ECC_OCRAM_ECC_SERRLKUPA0_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OCRAM_ECC_ADDR) + ALT_ECC_OCRAM_ECC_SERRLKUPA0_OFST))
/* The base address byte offset for the start of the ALT_ECC_OCRAM_ECC component. */
#define ALT_ECC_OCRAM_ECC_OFST        0xff8c3000
/* The start address of the ALT_ECC_OCRAM_ECC component. */
#define ALT_ECC_OCRAM_ECC_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_ECC_OCRAM_ECC_OFST))
/* The lower bound address range of the ALT_ECC_OCRAM_ECC component. */
#define ALT_ECC_OCRAM_ECC_LB_ADDR     ALT_ECC_OCRAM_ECC_ADDR
/* The upper bound address range of the ALT_ECC_OCRAM_ECC component. */
#define ALT_ECC_OCRAM_ECC_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_ECC_OCRAM_ECC_ADDR) + 0x400) - 1))


/*
 * Component Instance : ecc_dmac_ecc_registerBlock
 * 
 * Instance ecc_dmac_ecc_registerBlock of component ALT_ECC_DMAC.
 * 
 * 
 */
/* The address of the ALT_ECC_DMAC_IP_REV_ID register for the ALT_ECC_DMAC instance. */
#define ALT_ECC_DMAC_IP_REV_ID_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_DMAC_ADDR) + ALT_ECC_DMAC_IP_REV_ID_OFST))
/* The address of the ALT_ECC_DMAC_CTL register for the ALT_ECC_DMAC instance. */
#define ALT_ECC_DMAC_CTL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_DMAC_ADDR) + ALT_ECC_DMAC_CTL_OFST))
/* The address of the ALT_ECC_DMAC_INITSTAT register for the ALT_ECC_DMAC instance. */
#define ALT_ECC_DMAC_INITSTAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_DMAC_ADDR) + ALT_ECC_DMAC_INITSTAT_OFST))
/* The address of the ALT_ECC_DMAC_ERRINTEN register for the ALT_ECC_DMAC instance. */
#define ALT_ECC_DMAC_ERRINTEN_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_DMAC_ADDR) + ALT_ECC_DMAC_ERRINTEN_OFST))
/* The address of the ALT_ECC_DMAC_ERRINTENS register for the ALT_ECC_DMAC instance. */
#define ALT_ECC_DMAC_ERRINTENS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_DMAC_ADDR) + ALT_ECC_DMAC_ERRINTENS_OFST))
/* The address of the ALT_ECC_DMAC_ERRINTENR register for the ALT_ECC_DMAC instance. */
#define ALT_ECC_DMAC_ERRINTENR_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_DMAC_ADDR) + ALT_ECC_DMAC_ERRINTENR_OFST))
/* The address of the ALT_ECC_DMAC_INTMOD register for the ALT_ECC_DMAC instance. */
#define ALT_ECC_DMAC_INTMOD_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_DMAC_ADDR) + ALT_ECC_DMAC_INTMOD_OFST))
/* The address of the ALT_ECC_DMAC_INTSTAT register for the ALT_ECC_DMAC instance. */
#define ALT_ECC_DMAC_INTSTAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_DMAC_ADDR) + ALT_ECC_DMAC_INTSTAT_OFST))
/* The address of the ALT_ECC_DMAC_INTTEST register for the ALT_ECC_DMAC instance. */
#define ALT_ECC_DMAC_INTTEST_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_DMAC_ADDR) + ALT_ECC_DMAC_INTTEST_OFST))
/* The address of the ALT_ECC_DMAC_MODSTAT register for the ALT_ECC_DMAC instance. */
#define ALT_ECC_DMAC_MODSTAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_DMAC_ADDR) + ALT_ECC_DMAC_MODSTAT_OFST))
/* The address of the ALT_ECC_DMAC_DERRADDRA register for the ALT_ECC_DMAC instance. */
#define ALT_ECC_DMAC_DERRADDRA_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_DMAC_ADDR) + ALT_ECC_DMAC_DERRADDRA_OFST))
/* The address of the ALT_ECC_DMAC_SERRADDRA register for the ALT_ECC_DMAC instance. */
#define ALT_ECC_DMAC_SERRADDRA_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_DMAC_ADDR) + ALT_ECC_DMAC_SERRADDRA_OFST))
/* The address of the ALT_ECC_DMAC_SERRCNTREG register for the ALT_ECC_DMAC instance. */
#define ALT_ECC_DMAC_SERRCNTREG_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_DMAC_ADDR) + ALT_ECC_DMAC_SERRCNTREG_OFST))
/* The address of the ALT_ECC_DMAC_ADDRBUS register for the ALT_ECC_DMAC instance. */
#define ALT_ECC_DMAC_ECC_ADDRBUS_ADDR  ALT_ECC_DMAC_ADDRBUS_ADDR(ALT_ECC_DMAC_ADDR)
/* The address of the ALT_ECC_DMAC_RDATA0BUS register for the ALT_ECC_DMAC instance. */
#define ALT_ECC_DMAC_ECC_RDATA0BUS_ADDR  ALT_ECC_DMAC_RDATA0BUS_ADDR(ALT_ECC_DMAC_ADDR)
/* The address of the ALT_ECC_DMAC_RDATA1BUS register for the ALT_ECC_DMAC instance. */
#define ALT_ECC_DMAC_ECC_RDATA1BUS_ADDR  ALT_ECC_DMAC_RDATA1BUS_ADDR(ALT_ECC_DMAC_ADDR)
/* The address of the ALT_ECC_DMAC_RDATA2BUS register for the ALT_ECC_DMAC instance. */
#define ALT_ECC_DMAC_ECC_RDATA2BUS_ADDR  ALT_ECC_DMAC_RDATA2BUS_ADDR(ALT_ECC_DMAC_ADDR)
/* The address of the ALT_ECC_DMAC_RDATA3BUS register for the ALT_ECC_DMAC instance. */
#define ALT_ECC_DMAC_ECC_RDATA3BUS_ADDR  ALT_ECC_DMAC_RDATA3BUS_ADDR(ALT_ECC_DMAC_ADDR)
/* The address of the ALT_ECC_DMAC_WDATA0BUS register for the ALT_ECC_DMAC instance. */
#define ALT_ECC_DMAC_ECC_WDATA0BUS_ADDR  ALT_ECC_DMAC_WDATA0BUS_ADDR(ALT_ECC_DMAC_ADDR)
/* The address of the ALT_ECC_DMAC_WDATA1BUS register for the ALT_ECC_DMAC instance. */
#define ALT_ECC_DMAC_ECC_WDATA1BUS_ADDR  ALT_ECC_DMAC_WDATA1BUS_ADDR(ALT_ECC_DMAC_ADDR)
/* The address of the ALT_ECC_DMAC_WDATA2BUS register for the ALT_ECC_DMAC instance. */
#define ALT_ECC_DMAC_ECC_WDATA2BUS_ADDR  ALT_ECC_DMAC_WDATA2BUS_ADDR(ALT_ECC_DMAC_ADDR)
/* The address of the ALT_ECC_DMAC_WDATA3BUS register for the ALT_ECC_DMAC instance. */
#define ALT_ECC_DMAC_ECC_WDATA3BUS_ADDR  ALT_ECC_DMAC_WDATA3BUS_ADDR(ALT_ECC_DMAC_ADDR)
/* The address of the ALT_ECC_DMAC_RDATAECC0BUS register for the ALT_ECC_DMAC instance. */
#define ALT_ECC_DMAC_ECC_RDATAECC0BUS_ADDR  ALT_ECC_DMAC_RDATAECC0BUS_ADDR(ALT_ECC_DMAC_ADDR)
/* The address of the ALT_ECC_DMAC_RDATAECC1BUS register for the ALT_ECC_DMAC instance. */
#define ALT_ECC_DMAC_ECC_RDATAECC1BUS_ADDR  ALT_ECC_DMAC_RDATAECC1BUS_ADDR(ALT_ECC_DMAC_ADDR)
/* The address of the ALT_ECC_DMAC_WDATAECC0BUS register for the ALT_ECC_DMAC instance. */
#define ALT_ECC_DMAC_ECC_WDATAECC0BUS_ADDR  ALT_ECC_DMAC_WDATAECC0BUS_ADDR(ALT_ECC_DMAC_ADDR)
/* The address of the ALT_ECC_DMAC_WDATAECC1BUS register for the ALT_ECC_DMAC instance. */
#define ALT_ECC_DMAC_ECC_WDATAECC1BUS_ADDR  ALT_ECC_DMAC_WDATAECC1BUS_ADDR(ALT_ECC_DMAC_ADDR)
/* The address of the ALT_ECC_DMAC_DBYTECTL register for the ALT_ECC_DMAC instance. */
#define ALT_ECC_DMAC_ECC_DBYTECTL_ADDR  ALT_ECC_DMAC_DBYTECTL_ADDR(ALT_ECC_DMAC_ADDR)
/* The address of the ALT_ECC_DMAC_ACCCTL register for the ALT_ECC_DMAC instance. */
#define ALT_ECC_DMAC_ECC_ACCCTL_ADDR  ALT_ECC_DMAC_ACCCTL_ADDR(ALT_ECC_DMAC_ADDR)
/* The address of the ALT_ECC_DMAC_STARTACC register for the ALT_ECC_DMAC instance. */
#define ALT_ECC_DMAC_ECC_STARTACC_ADDR  ALT_ECC_DMAC_STARTACC_ADDR(ALT_ECC_DMAC_ADDR)
/* The address of the ALT_ECC_DMAC_WDCTL register for the ALT_ECC_DMAC instance. */
#define ALT_ECC_DMAC_ECC_WDCTL_ADDR  ALT_ECC_DMAC_WDCTL_ADDR(ALT_ECC_DMAC_ADDR)
/* The address of the ALT_ECC_DMAC_SERRLKUPA0 register for the ALT_ECC_DMAC instance. */
#define ALT_ECC_DMAC_SERRLKUPA0_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_DMAC_ADDR) + ALT_ECC_DMAC_SERRLKUPA0_OFST))
/* The base address byte offset for the start of the ALT_ECC_DMAC component. */
#define ALT_ECC_DMAC_OFST        0xff8c8000
/* The start address of the ALT_ECC_DMAC component. */
#define ALT_ECC_DMAC_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_ECC_DMAC_OFST))
/* The lower bound address range of the ALT_ECC_DMAC component. */
#define ALT_ECC_DMAC_LB_ADDR     ALT_ECC_DMAC_ADDR
/* The upper bound address range of the ALT_ECC_DMAC component. */
#define ALT_ECC_DMAC_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_ECC_DMAC_ADDR) + 0x400) - 1))


/*
 * Component Instance : ecc_qspi_ecc_registerBlock
 * 
 * Instance ecc_qspi_ecc_registerBlock of component ALT_ECC_QSPI.
 * 
 * 
 */
/* The address of the ALT_ECC_QSPI_IP_REV_ID register for the ALT_ECC_QSPI instance. */
#define ALT_ECC_QSPI_IP_REV_ID_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_QSPI_ADDR) + ALT_ECC_QSPI_IP_REV_ID_OFST))
/* The address of the ALT_ECC_QSPI_CTL register for the ALT_ECC_QSPI instance. */
#define ALT_ECC_QSPI_CTL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_QSPI_ADDR) + ALT_ECC_QSPI_CTL_OFST))
/* The address of the ALT_ECC_QSPI_INITSTAT register for the ALT_ECC_QSPI instance. */
#define ALT_ECC_QSPI_INITSTAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_QSPI_ADDR) + ALT_ECC_QSPI_INITSTAT_OFST))
/* The address of the ALT_ECC_QSPI_ERRINTEN register for the ALT_ECC_QSPI instance. */
#define ALT_ECC_QSPI_ERRINTEN_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_QSPI_ADDR) + ALT_ECC_QSPI_ERRINTEN_OFST))
/* The address of the ALT_ECC_QSPI_ERRINTENS register for the ALT_ECC_QSPI instance. */
#define ALT_ECC_QSPI_ERRINTENS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_QSPI_ADDR) + ALT_ECC_QSPI_ERRINTENS_OFST))
/* The address of the ALT_ECC_QSPI_ERRINTENR register for the ALT_ECC_QSPI instance. */
#define ALT_ECC_QSPI_ERRINTENR_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_QSPI_ADDR) + ALT_ECC_QSPI_ERRINTENR_OFST))
/* The address of the ALT_ECC_QSPI_INTMOD register for the ALT_ECC_QSPI instance. */
#define ALT_ECC_QSPI_INTMOD_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_QSPI_ADDR) + ALT_ECC_QSPI_INTMOD_OFST))
/* The address of the ALT_ECC_QSPI_INTSTAT register for the ALT_ECC_QSPI instance. */
#define ALT_ECC_QSPI_INTSTAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_QSPI_ADDR) + ALT_ECC_QSPI_INTSTAT_OFST))
/* The address of the ALT_ECC_QSPI_INTTEST register for the ALT_ECC_QSPI instance. */
#define ALT_ECC_QSPI_INTTEST_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_QSPI_ADDR) + ALT_ECC_QSPI_INTTEST_OFST))
/* The address of the ALT_ECC_QSPI_MODSTAT register for the ALT_ECC_QSPI instance. */
#define ALT_ECC_QSPI_MODSTAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_QSPI_ADDR) + ALT_ECC_QSPI_MODSTAT_OFST))
/* The address of the ALT_ECC_QSPI_DERRADDRA register for the ALT_ECC_QSPI instance. */
#define ALT_ECC_QSPI_DERRADDRA_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_QSPI_ADDR) + ALT_ECC_QSPI_DERRADDRA_OFST))
/* The address of the ALT_ECC_QSPI_SERRADDRA register for the ALT_ECC_QSPI instance. */
#define ALT_ECC_QSPI_SERRADDRA_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_QSPI_ADDR) + ALT_ECC_QSPI_SERRADDRA_OFST))
/* The address of the ALT_ECC_QSPI_SERRCNTREG register for the ALT_ECC_QSPI instance. */
#define ALT_ECC_QSPI_SERRCNTREG_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_QSPI_ADDR) + ALT_ECC_QSPI_SERRCNTREG_OFST))
/* The address of the ALT_ECC_QSPI_ADDRBUS register for the ALT_ECC_QSPI instance. */
#define ALT_ECC_QSPI_ECC_ADDRBUS_ADDR  ALT_ECC_QSPI_ADDRBUS_ADDR(ALT_ECC_QSPI_ADDR)
/* The address of the ALT_ECC_QSPI_RDATA0BUS register for the ALT_ECC_QSPI instance. */
#define ALT_ECC_QSPI_ECC_RDATA0BUS_ADDR  ALT_ECC_QSPI_RDATA0BUS_ADDR(ALT_ECC_QSPI_ADDR)
/* The address of the ALT_ECC_QSPI_RDATA1BUS register for the ALT_ECC_QSPI instance. */
#define ALT_ECC_QSPI_ECC_RDATA1BUS_ADDR  ALT_ECC_QSPI_RDATA1BUS_ADDR(ALT_ECC_QSPI_ADDR)
/* The address of the ALT_ECC_QSPI_RDATA2BUS register for the ALT_ECC_QSPI instance. */
#define ALT_ECC_QSPI_ECC_RDATA2BUS_ADDR  ALT_ECC_QSPI_RDATA2BUS_ADDR(ALT_ECC_QSPI_ADDR)
/* The address of the ALT_ECC_QSPI_RDATA3BUS register for the ALT_ECC_QSPI instance. */
#define ALT_ECC_QSPI_ECC_RDATA3BUS_ADDR  ALT_ECC_QSPI_RDATA3BUS_ADDR(ALT_ECC_QSPI_ADDR)
/* The address of the ALT_ECC_QSPI_WDATA0BUS register for the ALT_ECC_QSPI instance. */
#define ALT_ECC_QSPI_ECC_WDATA0BUS_ADDR  ALT_ECC_QSPI_WDATA0BUS_ADDR(ALT_ECC_QSPI_ADDR)
/* The address of the ALT_ECC_QSPI_WDATA1BUS register for the ALT_ECC_QSPI instance. */
#define ALT_ECC_QSPI_ECC_WDATA1BUS_ADDR  ALT_ECC_QSPI_WDATA1BUS_ADDR(ALT_ECC_QSPI_ADDR)
/* The address of the ALT_ECC_QSPI_WDATA2BUS register for the ALT_ECC_QSPI instance. */
#define ALT_ECC_QSPI_ECC_WDATA2BUS_ADDR  ALT_ECC_QSPI_WDATA2BUS_ADDR(ALT_ECC_QSPI_ADDR)
/* The address of the ALT_ECC_QSPI_WDATA3BUS register for the ALT_ECC_QSPI instance. */
#define ALT_ECC_QSPI_ECC_WDATA3BUS_ADDR  ALT_ECC_QSPI_WDATA3BUS_ADDR(ALT_ECC_QSPI_ADDR)
/* The address of the ALT_ECC_QSPI_RDATAECC0BUS register for the ALT_ECC_QSPI instance. */
#define ALT_ECC_QSPI_ECC_RDATAECC0BUS_ADDR  ALT_ECC_QSPI_RDATAECC0BUS_ADDR(ALT_ECC_QSPI_ADDR)
/* The address of the ALT_ECC_QSPI_RDATAECC1BUS register for the ALT_ECC_QSPI instance. */
#define ALT_ECC_QSPI_ECC_RDATAECC1BUS_ADDR  ALT_ECC_QSPI_RDATAECC1BUS_ADDR(ALT_ECC_QSPI_ADDR)
/* The address of the ALT_ECC_QSPI_WDATAECC0BUS register for the ALT_ECC_QSPI instance. */
#define ALT_ECC_QSPI_ECC_WDATAECC0BUS_ADDR  ALT_ECC_QSPI_WDATAECC0BUS_ADDR(ALT_ECC_QSPI_ADDR)
/* The address of the ALT_ECC_QSPI_WDATAECC1BUS register for the ALT_ECC_QSPI instance. */
#define ALT_ECC_QSPI_ECC_WDATAECC1BUS_ADDR  ALT_ECC_QSPI_WDATAECC1BUS_ADDR(ALT_ECC_QSPI_ADDR)
/* The address of the ALT_ECC_QSPI_DBYTECTL register for the ALT_ECC_QSPI instance. */
#define ALT_ECC_QSPI_ECC_DBYTECTL_ADDR  ALT_ECC_QSPI_DBYTECTL_ADDR(ALT_ECC_QSPI_ADDR)
/* The address of the ALT_ECC_QSPI_ACCCTL register for the ALT_ECC_QSPI instance. */
#define ALT_ECC_QSPI_ECC_ACCCTL_ADDR  ALT_ECC_QSPI_ACCCTL_ADDR(ALT_ECC_QSPI_ADDR)
/* The address of the ALT_ECC_QSPI_STARTACC register for the ALT_ECC_QSPI instance. */
#define ALT_ECC_QSPI_ECC_STARTACC_ADDR  ALT_ECC_QSPI_STARTACC_ADDR(ALT_ECC_QSPI_ADDR)
/* The address of the ALT_ECC_QSPI_WDCTL register for the ALT_ECC_QSPI instance. */
#define ALT_ECC_QSPI_ECC_WDCTL_ADDR  ALT_ECC_QSPI_WDCTL_ADDR(ALT_ECC_QSPI_ADDR)
/* The address of the ALT_ECC_QSPI_SERRLKUPA0 register for the ALT_ECC_QSPI instance. */
#define ALT_ECC_QSPI_SERRLKUPA0_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_QSPI_ADDR) + ALT_ECC_QSPI_SERRLKUPA0_OFST))
/* The base address byte offset for the start of the ALT_ECC_QSPI component. */
#define ALT_ECC_QSPI_OFST        0xff8c8400
/* The start address of the ALT_ECC_QSPI component. */
#define ALT_ECC_QSPI_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_ECC_QSPI_OFST))
/* The lower bound address range of the ALT_ECC_QSPI component. */
#define ALT_ECC_QSPI_LB_ADDR     ALT_ECC_QSPI_ADDR
/* The upper bound address range of the ALT_ECC_QSPI component. */
#define ALT_ECC_QSPI_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_ECC_QSPI_ADDR) + 0x400) - 1))


/*
 * Component Instance : ecc_otg0_ecc_registerBlock
 * 
 * Instance ecc_otg0_ecc_registerBlock of component ALT_ECC_OTG0_ECC.
 * 
 * 
 */
/* The address of the ALT_ECC_OTG0_ECC_IP_REV_ID register for the ALT_ECC_OTG0_ECC instance. */
#define ALT_ECC_OTG0_ECC_IP_REV_ID_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OTG0_ECC_ADDR) + ALT_ECC_OTG0_ECC_IP_REV_ID_OFST))
/* The address of the ALT_ECC_OTG0_ECC_CTL register for the ALT_ECC_OTG0_ECC instance. */
#define ALT_ECC_OTG0_ECC_CTL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OTG0_ECC_ADDR) + ALT_ECC_OTG0_ECC_CTL_OFST))
/* The address of the ALT_ECC_OTG0_ECC_INITSTAT register for the ALT_ECC_OTG0_ECC instance. */
#define ALT_ECC_OTG0_ECC_INITSTAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OTG0_ECC_ADDR) + ALT_ECC_OTG0_ECC_INITSTAT_OFST))
/* The address of the ALT_ECC_OTG0_ECC_ERRINTEN register for the ALT_ECC_OTG0_ECC instance. */
#define ALT_ECC_OTG0_ECC_ERRINTEN_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OTG0_ECC_ADDR) + ALT_ECC_OTG0_ECC_ERRINTEN_OFST))
/* The address of the ALT_ECC_OTG0_ECC_ERRINTENS register for the ALT_ECC_OTG0_ECC instance. */
#define ALT_ECC_OTG0_ECC_ERRINTENS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OTG0_ECC_ADDR) + ALT_ECC_OTG0_ECC_ERRINTENS_OFST))
/* The address of the ALT_ECC_OTG0_ECC_ERRINTENR register for the ALT_ECC_OTG0_ECC instance. */
#define ALT_ECC_OTG0_ECC_ERRINTENR_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OTG0_ECC_ADDR) + ALT_ECC_OTG0_ECC_ERRINTENR_OFST))
/* The address of the ALT_ECC_OTG0_ECC_INTMOD register for the ALT_ECC_OTG0_ECC instance. */
#define ALT_ECC_OTG0_ECC_INTMOD_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OTG0_ECC_ADDR) + ALT_ECC_OTG0_ECC_INTMOD_OFST))
/* The address of the ALT_ECC_OTG0_ECC_INTSTAT register for the ALT_ECC_OTG0_ECC instance. */
#define ALT_ECC_OTG0_ECC_INTSTAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OTG0_ECC_ADDR) + ALT_ECC_OTG0_ECC_INTSTAT_OFST))
/* The address of the ALT_ECC_OTG0_ECC_INTTEST register for the ALT_ECC_OTG0_ECC instance. */
#define ALT_ECC_OTG0_ECC_INTTEST_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OTG0_ECC_ADDR) + ALT_ECC_OTG0_ECC_INTTEST_OFST))
/* The address of the ALT_ECC_OTG0_ECC_MODSTAT register for the ALT_ECC_OTG0_ECC instance. */
#define ALT_ECC_OTG0_ECC_MODSTAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OTG0_ECC_ADDR) + ALT_ECC_OTG0_ECC_MODSTAT_OFST))
/* The address of the ALT_ECC_OTG0_ECC_DERRADDRA register for the ALT_ECC_OTG0_ECC instance. */
#define ALT_ECC_OTG0_ECC_DERRADDRA_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OTG0_ECC_ADDR) + ALT_ECC_OTG0_ECC_DERRADDRA_OFST))
/* The address of the ALT_ECC_OTG0_ECC_SERRADDRA register for the ALT_ECC_OTG0_ECC instance. */
#define ALT_ECC_OTG0_ECC_SERRADDRA_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OTG0_ECC_ADDR) + ALT_ECC_OTG0_ECC_SERRADDRA_OFST))
/* The address of the ALT_ECC_OTG0_ECC_SERRCNTREG register for the ALT_ECC_OTG0_ECC instance. */
#define ALT_ECC_OTG0_ECC_SERRCNTREG_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OTG0_ECC_ADDR) + ALT_ECC_OTG0_ECC_SERRCNTREG_OFST))
/* The address of the ALT_ECC_OTG0_ECC_ECC_ADDRBUS register for the ALT_ECC_OTG0_ECC instance. */
#define ALT_ECC_OTG0_ECC_ECC_ADDRBUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OTG0_ECC_ADDR) + ALT_ECC_OTG0_ECC_ECC_ADDRBUS_OFST))
/* The address of the ALT_ECC_OTG0_ECC_ECC_RDATA0BUS register for the ALT_ECC_OTG0_ECC instance. */
#define ALT_ECC_OTG0_ECC_ECC_RDATA0BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OTG0_ECC_ADDR) + ALT_ECC_OTG0_ECC_ECC_RDATA0BUS_OFST))
/* The address of the ALT_ECC_OTG0_ECC_ECC_RDATA1BUS register for the ALT_ECC_OTG0_ECC instance. */
#define ALT_ECC_OTG0_ECC_ECC_RDATA1BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OTG0_ECC_ADDR) + ALT_ECC_OTG0_ECC_ECC_RDATA1BUS_OFST))
/* The address of the ALT_ECC_OTG0_ECC_ECC_RDATA2BUS register for the ALT_ECC_OTG0_ECC instance. */
#define ALT_ECC_OTG0_ECC_ECC_RDATA2BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OTG0_ECC_ADDR) + ALT_ECC_OTG0_ECC_ECC_RDATA2BUS_OFST))
/* The address of the ALT_ECC_OTG0_ECC_ECC_RDATA3BUS register for the ALT_ECC_OTG0_ECC instance. */
#define ALT_ECC_OTG0_ECC_ECC_RDATA3BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OTG0_ECC_ADDR) + ALT_ECC_OTG0_ECC_ECC_RDATA3BUS_OFST))
/* The address of the ALT_ECC_OTG0_ECC_ECC_WDATA0BUS register for the ALT_ECC_OTG0_ECC instance. */
#define ALT_ECC_OTG0_ECC_ECC_WDATA0BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OTG0_ECC_ADDR) + ALT_ECC_OTG0_ECC_ECC_WDATA0BUS_OFST))
/* The address of the ALT_ECC_OTG0_ECC_ECC_WDATA1BUS register for the ALT_ECC_OTG0_ECC instance. */
#define ALT_ECC_OTG0_ECC_ECC_WDATA1BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OTG0_ECC_ADDR) + ALT_ECC_OTG0_ECC_ECC_WDATA1BUS_OFST))
/* The address of the ALT_ECC_OTG0_ECC_ECC_WDATA2BUS register for the ALT_ECC_OTG0_ECC instance. */
#define ALT_ECC_OTG0_ECC_ECC_WDATA2BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OTG0_ECC_ADDR) + ALT_ECC_OTG0_ECC_ECC_WDATA2BUS_OFST))
/* The address of the ALT_ECC_OTG0_ECC_ECC_WDATA3BUS register for the ALT_ECC_OTG0_ECC instance. */
#define ALT_ECC_OTG0_ECC_ECC_WDATA3BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OTG0_ECC_ADDR) + ALT_ECC_OTG0_ECC_ECC_WDATA3BUS_OFST))
/* The address of the ALT_ECC_OTG0_ECC_ECC_RDATAECC0BUS register for the ALT_ECC_OTG0_ECC instance. */
#define ALT_ECC_OTG0_ECC_ECC_RDATAECC0BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OTG0_ECC_ADDR) + ALT_ECC_OTG0_ECC_ECC_RDATAECC0BUS_OFST))
/* The address of the ALT_ECC_OTG0_ECC_ECC_RDATAECC1BUS register for the ALT_ECC_OTG0_ECC instance. */
#define ALT_ECC_OTG0_ECC_ECC_RDATAECC1BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OTG0_ECC_ADDR) + ALT_ECC_OTG0_ECC_ECC_RDATAECC1BUS_OFST))
/* The address of the ALT_ECC_OTG0_ECC_ECC_WDATAECC0BUS register for the ALT_ECC_OTG0_ECC instance. */
#define ALT_ECC_OTG0_ECC_ECC_WDATAECC0BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OTG0_ECC_ADDR) + ALT_ECC_OTG0_ECC_ECC_WDATAECC0BUS_OFST))
/* The address of the ALT_ECC_OTG0_ECC_ECC_WDATAECC1BUS register for the ALT_ECC_OTG0_ECC instance. */
#define ALT_ECC_OTG0_ECC_ECC_WDATAECC1BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OTG0_ECC_ADDR) + ALT_ECC_OTG0_ECC_ECC_WDATAECC1BUS_OFST))
/* The address of the ALT_ECC_OTG0_ECC_ECC_DBYTECTL register for the ALT_ECC_OTG0_ECC instance. */
#define ALT_ECC_OTG0_ECC_ECC_DBYTECTL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OTG0_ECC_ADDR) + ALT_ECC_OTG0_ECC_ECC_DBYTECTL_OFST))
/* The address of the ALT_ECC_OTG0_ECC_ECC_ACCCTL register for the ALT_ECC_OTG0_ECC instance. */
#define ALT_ECC_OTG0_ECC_ECC_ACCCTL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OTG0_ECC_ADDR) + ALT_ECC_OTG0_ECC_ECC_ACCCTL_OFST))
/* The address of the ALT_ECC_OTG0_ECC_ECC_STARTACC register for the ALT_ECC_OTG0_ECC instance. */
#define ALT_ECC_OTG0_ECC_ECC_STARTACC_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OTG0_ECC_ADDR) + ALT_ECC_OTG0_ECC_ECC_STARTACC_OFST))
/* The address of the ALT_ECC_OTG0_ECC_ECC_WDCTL register for the ALT_ECC_OTG0_ECC instance. */
#define ALT_ECC_OTG0_ECC_ECC_WDCTL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OTG0_ECC_ADDR) + ALT_ECC_OTG0_ECC_ECC_WDCTL_OFST))
/* The address of the ALT_ECC_OTG0_ECC_SERRLKUPA0 register for the ALT_ECC_OTG0_ECC instance. */
#define ALT_ECC_OTG0_ECC_SERRLKUPA0_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OTG0_ECC_ADDR) + ALT_ECC_OTG0_ECC_SERRLKUPA0_OFST))
/* The base address byte offset for the start of the ALT_ECC_OTG0_ECC component. */
#define ALT_ECC_OTG0_ECC_OFST        0xff8c8800
/* The start address of the ALT_ECC_OTG0_ECC component. */
#define ALT_ECC_OTG0_ECC_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_ECC_OTG0_ECC_OFST))
/* The lower bound address range of the ALT_ECC_OTG0_ECC component. */
#define ALT_ECC_OTG0_ECC_LB_ADDR     ALT_ECC_OTG0_ECC_ADDR
/* The upper bound address range of the ALT_ECC_OTG0_ECC component. */
#define ALT_ECC_OTG0_ECC_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_ECC_OTG0_ECC_ADDR) + 0x400) - 1))


/*
 * Component Instance : ecc_otg1_ecc_registerBlock
 * 
 * Instance ecc_otg1_ecc_registerBlock of component ALT_ECC_OTG1_ECC.
 * 
 * 
 */
/* The address of the ALT_ECC_OTG1_ECC_IP_REV_ID register for the ALT_ECC_OTG1_ECC instance. */
#define ALT_ECC_OTG1_ECC_IP_REV_ID_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OTG1_ECC_ADDR) + ALT_ECC_OTG1_ECC_IP_REV_ID_OFST))
/* The address of the ALT_ECC_OTG1_ECC_CTL register for the ALT_ECC_OTG1_ECC instance. */
#define ALT_ECC_OTG1_ECC_CTL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OTG1_ECC_ADDR) + ALT_ECC_OTG1_ECC_CTL_OFST))
/* The address of the ALT_ECC_OTG1_ECC_INITSTAT register for the ALT_ECC_OTG1_ECC instance. */
#define ALT_ECC_OTG1_ECC_INITSTAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OTG1_ECC_ADDR) + ALT_ECC_OTG1_ECC_INITSTAT_OFST))
/* The address of the ALT_ECC_OTG1_ECC_ERRINTEN register for the ALT_ECC_OTG1_ECC instance. */
#define ALT_ECC_OTG1_ECC_ERRINTEN_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OTG1_ECC_ADDR) + ALT_ECC_OTG1_ECC_ERRINTEN_OFST))
/* The address of the ALT_ECC_OTG1_ECC_ERRINTENS register for the ALT_ECC_OTG1_ECC instance. */
#define ALT_ECC_OTG1_ECC_ERRINTENS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OTG1_ECC_ADDR) + ALT_ECC_OTG1_ECC_ERRINTENS_OFST))
/* The address of the ALT_ECC_OTG1_ECC_ERRINTENR register for the ALT_ECC_OTG1_ECC instance. */
#define ALT_ECC_OTG1_ECC_ERRINTENR_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OTG1_ECC_ADDR) + ALT_ECC_OTG1_ECC_ERRINTENR_OFST))
/* The address of the ALT_ECC_OTG1_ECC_INTMOD register for the ALT_ECC_OTG1_ECC instance. */
#define ALT_ECC_OTG1_ECC_INTMOD_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OTG1_ECC_ADDR) + ALT_ECC_OTG1_ECC_INTMOD_OFST))
/* The address of the ALT_ECC_OTG1_ECC_INTSTAT register for the ALT_ECC_OTG1_ECC instance. */
#define ALT_ECC_OTG1_ECC_INTSTAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OTG1_ECC_ADDR) + ALT_ECC_OTG1_ECC_INTSTAT_OFST))
/* The address of the ALT_ECC_OTG1_ECC_INTTEST register for the ALT_ECC_OTG1_ECC instance. */
#define ALT_ECC_OTG1_ECC_INTTEST_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OTG1_ECC_ADDR) + ALT_ECC_OTG1_ECC_INTTEST_OFST))
/* The address of the ALT_ECC_OTG1_ECC_MODSTAT register for the ALT_ECC_OTG1_ECC instance. */
#define ALT_ECC_OTG1_ECC_MODSTAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OTG1_ECC_ADDR) + ALT_ECC_OTG1_ECC_MODSTAT_OFST))
/* The address of the ALT_ECC_OTG1_ECC_DERRADDRA register for the ALT_ECC_OTG1_ECC instance. */
#define ALT_ECC_OTG1_ECC_DERRADDRA_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OTG1_ECC_ADDR) + ALT_ECC_OTG1_ECC_DERRADDRA_OFST))
/* The address of the ALT_ECC_OTG1_ECC_SERRADDRA register for the ALT_ECC_OTG1_ECC instance. */
#define ALT_ECC_OTG1_ECC_SERRADDRA_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OTG1_ECC_ADDR) + ALT_ECC_OTG1_ECC_SERRADDRA_OFST))
/* The address of the ALT_ECC_OTG1_ECC_SERRCNTREG register for the ALT_ECC_OTG1_ECC instance. */
#define ALT_ECC_OTG1_ECC_SERRCNTREG_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OTG1_ECC_ADDR) + ALT_ECC_OTG1_ECC_SERRCNTREG_OFST))
/* The address of the ALT_ECC_OTG1_ECC_ECC_ADDRBUS register for the ALT_ECC_OTG1_ECC instance. */
#define ALT_ECC_OTG1_ECC_ECC_ADDRBUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OTG1_ECC_ADDR) + ALT_ECC_OTG1_ECC_ECC_ADDRBUS_OFST))
/* The address of the ALT_ECC_OTG1_ECC_ECC_RDATA0BUS register for the ALT_ECC_OTG1_ECC instance. */
#define ALT_ECC_OTG1_ECC_ECC_RDATA0BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OTG1_ECC_ADDR) + ALT_ECC_OTG1_ECC_ECC_RDATA0BUS_OFST))
/* The address of the ALT_ECC_OTG1_ECC_ECC_RDATA1BUS register for the ALT_ECC_OTG1_ECC instance. */
#define ALT_ECC_OTG1_ECC_ECC_RDATA1BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OTG1_ECC_ADDR) + ALT_ECC_OTG1_ECC_ECC_RDATA1BUS_OFST))
/* The address of the ALT_ECC_OTG1_ECC_ECC_RDATA2BUS register for the ALT_ECC_OTG1_ECC instance. */
#define ALT_ECC_OTG1_ECC_ECC_RDATA2BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OTG1_ECC_ADDR) + ALT_ECC_OTG1_ECC_ECC_RDATA2BUS_OFST))
/* The address of the ALT_ECC_OTG1_ECC_ECC_RDATA3BUS register for the ALT_ECC_OTG1_ECC instance. */
#define ALT_ECC_OTG1_ECC_ECC_RDATA3BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OTG1_ECC_ADDR) + ALT_ECC_OTG1_ECC_ECC_RDATA3BUS_OFST))
/* The address of the ALT_ECC_OTG1_ECC_ECC_WDATA0BUS register for the ALT_ECC_OTG1_ECC instance. */
#define ALT_ECC_OTG1_ECC_ECC_WDATA0BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OTG1_ECC_ADDR) + ALT_ECC_OTG1_ECC_ECC_WDATA0BUS_OFST))
/* The address of the ALT_ECC_OTG1_ECC_ECC_WDATA1BUS register for the ALT_ECC_OTG1_ECC instance. */
#define ALT_ECC_OTG1_ECC_ECC_WDATA1BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OTG1_ECC_ADDR) + ALT_ECC_OTG1_ECC_ECC_WDATA1BUS_OFST))
/* The address of the ALT_ECC_OTG1_ECC_ECC_WDATA2BUS register for the ALT_ECC_OTG1_ECC instance. */
#define ALT_ECC_OTG1_ECC_ECC_WDATA2BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OTG1_ECC_ADDR) + ALT_ECC_OTG1_ECC_ECC_WDATA2BUS_OFST))
/* The address of the ALT_ECC_OTG1_ECC_ECC_WDATA3BUS register for the ALT_ECC_OTG1_ECC instance. */
#define ALT_ECC_OTG1_ECC_ECC_WDATA3BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OTG1_ECC_ADDR) + ALT_ECC_OTG1_ECC_ECC_WDATA3BUS_OFST))
/* The address of the ALT_ECC_OTG1_ECC_ECC_RDATAECC0BUS register for the ALT_ECC_OTG1_ECC instance. */
#define ALT_ECC_OTG1_ECC_ECC_RDATAECC0BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OTG1_ECC_ADDR) + ALT_ECC_OTG1_ECC_ECC_RDATAECC0BUS_OFST))
/* The address of the ALT_ECC_OTG1_ECC_ECC_RDATAECC1BUS register for the ALT_ECC_OTG1_ECC instance. */
#define ALT_ECC_OTG1_ECC_ECC_RDATAECC1BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OTG1_ECC_ADDR) + ALT_ECC_OTG1_ECC_ECC_RDATAECC1BUS_OFST))
/* The address of the ALT_ECC_OTG1_ECC_ECC_WDATAECC0BUS register for the ALT_ECC_OTG1_ECC instance. */
#define ALT_ECC_OTG1_ECC_ECC_WDATAECC0BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OTG1_ECC_ADDR) + ALT_ECC_OTG1_ECC_ECC_WDATAECC0BUS_OFST))
/* The address of the ALT_ECC_OTG1_ECC_ECC_WDATAECC1BUS register for the ALT_ECC_OTG1_ECC instance. */
#define ALT_ECC_OTG1_ECC_ECC_WDATAECC1BUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OTG1_ECC_ADDR) + ALT_ECC_OTG1_ECC_ECC_WDATAECC1BUS_OFST))
/* The address of the ALT_ECC_OTG1_ECC_ECC_DBYTECTL register for the ALT_ECC_OTG1_ECC instance. */
#define ALT_ECC_OTG1_ECC_ECC_DBYTECTL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OTG1_ECC_ADDR) + ALT_ECC_OTG1_ECC_ECC_DBYTECTL_OFST))
/* The address of the ALT_ECC_OTG1_ECC_ECC_ACCCTL register for the ALT_ECC_OTG1_ECC instance. */
#define ALT_ECC_OTG1_ECC_ECC_ACCCTL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OTG1_ECC_ADDR) + ALT_ECC_OTG1_ECC_ECC_ACCCTL_OFST))
/* The address of the ALT_ECC_OTG1_ECC_ECC_STARTACC register for the ALT_ECC_OTG1_ECC instance. */
#define ALT_ECC_OTG1_ECC_ECC_STARTACC_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OTG1_ECC_ADDR) + ALT_ECC_OTG1_ECC_ECC_STARTACC_OFST))
/* The address of the ALT_ECC_OTG1_ECC_ECC_WDCTL register for the ALT_ECC_OTG1_ECC instance. */
#define ALT_ECC_OTG1_ECC_ECC_WDCTL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OTG1_ECC_ADDR) + ALT_ECC_OTG1_ECC_ECC_WDCTL_OFST))
/* The address of the ALT_ECC_OTG1_ECC_SERRLKUPA0 register for the ALT_ECC_OTG1_ECC instance. */
#define ALT_ECC_OTG1_ECC_SERRLKUPA0_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_OTG1_ECC_ADDR) + ALT_ECC_OTG1_ECC_SERRLKUPA0_OFST))
/* The base address byte offset for the start of the ALT_ECC_OTG1_ECC component. */
#define ALT_ECC_OTG1_ECC_OFST        0xff8c8c00
/* The start address of the ALT_ECC_OTG1_ECC component. */
#define ALT_ECC_OTG1_ECC_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_ECC_OTG1_ECC_OFST))
/* The lower bound address range of the ALT_ECC_OTG1_ECC component. */
#define ALT_ECC_OTG1_ECC_LB_ADDR     ALT_ECC_OTG1_ECC_ADDR
/* The upper bound address range of the ALT_ECC_OTG1_ECC component. */
#define ALT_ECC_OTG1_ECC_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_ECC_OTG1_ECC_ADDR) + 0x400) - 1))


/*
 * Component Instance : i_qspi_QSPIDATA
 * 
 * Instance i_qspi_QSPIDATA of component ALT_QSPIDATA.
 * 
 * 
 */
/* The base address byte offset for the start of the ALT_QSPIDATA component. */
#define ALT_QSPIDATA_OFST        0xffa00000
/* The start address of the ALT_QSPIDATA component. */
#define ALT_QSPIDATA_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_QSPIDATA_OFST))
/* The lower bound address range of the ALT_QSPIDATA component. */
#define ALT_QSPIDATA_LB_ADDR     ALT_QSPIDATA_ADDR
/* The upper bound address range of the ALT_QSPIDATA component. */
#define ALT_QSPIDATA_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_QSPIDATA_ADDR) + 0x100000) - 1))


/*
 * Component Instance : i_usbotg_0_globgrp
 * 
 * Instance i_usbotg_0_globgrp of component ALT_USB_GLOB.
 * 
 * 
 */
/* The address of the ALT_USB_GLOB_GOTGCTL register for the ALT_USB0_GLOBGRP instance. */
#define ALT_USB0_GLOB_GOTGCTL_ADDR  ALT_USB_GLOB_GOTGCTL_ADDR(ALT_USB0_GLOBGRP_ADDR)
/* The address of the ALT_USB_GLOB_GOTGINT register for the ALT_USB0_GLOBGRP instance. */
#define ALT_USB0_GLOB_GOTGINT_ADDR  ALT_USB_GLOB_GOTGINT_ADDR(ALT_USB0_GLOBGRP_ADDR)
/* The address of the ALT_USB_GLOB_GAHBCFG register for the ALT_USB0_GLOBGRP instance. */
#define ALT_USB0_GLOB_GAHBCFG_ADDR  ALT_USB_GLOB_GAHBCFG_ADDR(ALT_USB0_GLOBGRP_ADDR)
/* The address of the ALT_USB_GLOB_GUSBCFG register for the ALT_USB0_GLOBGRP instance. */
#define ALT_USB0_GLOB_GUSBCFG_ADDR  ALT_USB_GLOB_GUSBCFG_ADDR(ALT_USB0_GLOBGRP_ADDR)
/* The address of the ALT_USB_GLOB_GRSTCTL register for the ALT_USB0_GLOBGRP instance. */
#define ALT_USB0_GLOB_GRSTCTL_ADDR  ALT_USB_GLOB_GRSTCTL_ADDR(ALT_USB0_GLOBGRP_ADDR)
/* The address of the ALT_USB_GLOB_GINTSTS register for the ALT_USB0_GLOBGRP instance. */
#define ALT_USB0_GLOB_GINTSTS_ADDR  ALT_USB_GLOB_GINTSTS_ADDR(ALT_USB0_GLOBGRP_ADDR)
/* The address of the ALT_USB_GLOB_GINTMSK register for the ALT_USB0_GLOBGRP instance. */
#define ALT_USB0_GLOB_GINTMSK_ADDR  ALT_USB_GLOB_GINTMSK_ADDR(ALT_USB0_GLOBGRP_ADDR)
/* The address of the ALT_USB_GLOB_GRXSTSR register for the ALT_USB0_GLOBGRP instance. */
#define ALT_USB0_GLOB_GRXSTSR_ADDR  ALT_USB_GLOB_GRXSTSR_ADDR(ALT_USB0_GLOBGRP_ADDR)
/* The address of the ALT_USB_GLOB_GRXSTSP register for the ALT_USB0_GLOBGRP instance. */
#define ALT_USB0_GLOB_GRXSTSP_ADDR  ALT_USB_GLOB_GRXSTSP_ADDR(ALT_USB0_GLOBGRP_ADDR)
/* The address of the ALT_USB_GLOB_GRXFSIZ register for the ALT_USB0_GLOBGRP instance. */
#define ALT_USB0_GLOB_GRXFSIZ_ADDR  ALT_USB_GLOB_GRXFSIZ_ADDR(ALT_USB0_GLOBGRP_ADDR)
/* The address of the ALT_USB_GLOB_GNPTXFSIZ register for the ALT_USB0_GLOBGRP instance. */
#define ALT_USB0_GLOB_GNPTXFSIZ_ADDR  ALT_USB_GLOB_GNPTXFSIZ_ADDR(ALT_USB0_GLOBGRP_ADDR)
/* The address of the ALT_USB_GLOB_GNPTXSTS register for the ALT_USB0_GLOBGRP instance. */
#define ALT_USB0_GLOB_GNPTXSTS_ADDR  ALT_USB_GLOB_GNPTXSTS_ADDR(ALT_USB0_GLOBGRP_ADDR)
/* The address of the ALT_USB_GLOB_GPVNDCTL register for the ALT_USB0_GLOBGRP instance. */
#define ALT_USB0_GLOB_GPVNDCTL_ADDR  ALT_USB_GLOB_GPVNDCTL_ADDR(ALT_USB0_GLOBGRP_ADDR)
/* The address of the ALT_USB_GLOB_GGPIO register for the ALT_USB0_GLOBGRP instance. */
#define ALT_USB0_GLOB_GGPIO_ADDR  ALT_USB_GLOB_GGPIO_ADDR(ALT_USB0_GLOBGRP_ADDR)
/* The address of the ALT_USB_GLOB_GUID register for the ALT_USB0_GLOBGRP instance. */
#define ALT_USB0_GLOB_GUID_ADDR  ALT_USB_GLOB_GUID_ADDR(ALT_USB0_GLOBGRP_ADDR)
/* The address of the ALT_USB_GLOB_GSNPSID register for the ALT_USB0_GLOBGRP instance. */
#define ALT_USB0_GLOB_GSNPSID_ADDR  ALT_USB_GLOB_GSNPSID_ADDR(ALT_USB0_GLOBGRP_ADDR)
/* The address of the ALT_USB_GLOB_GHWCFG1 register for the ALT_USB0_GLOBGRP instance. */
#define ALT_USB0_GLOB_GHWCFG1_ADDR  ALT_USB_GLOB_GHWCFG1_ADDR(ALT_USB0_GLOBGRP_ADDR)
/* The address of the ALT_USB_GLOB_GHWCFG2 register for the ALT_USB0_GLOBGRP instance. */
#define ALT_USB0_GLOB_GHWCFG2_ADDR  ALT_USB_GLOB_GHWCFG2_ADDR(ALT_USB0_GLOBGRP_ADDR)
/* The address of the ALT_USB_GLOB_GHWCFG3 register for the ALT_USB0_GLOBGRP instance. */
#define ALT_USB0_GLOB_GHWCFG3_ADDR  ALT_USB_GLOB_GHWCFG3_ADDR(ALT_USB0_GLOBGRP_ADDR)
/* The address of the ALT_USB_GLOB_GHWCFG4 register for the ALT_USB0_GLOBGRP instance. */
#define ALT_USB0_GLOB_GHWCFG4_ADDR  ALT_USB_GLOB_GHWCFG4_ADDR(ALT_USB0_GLOBGRP_ADDR)
/* The address of the ALT_USB_GLOB_GDFIFOCFG register for the ALT_USB0_GLOBGRP instance. */
#define ALT_USB0_GLOB_GDFIFOCFG_ADDR  ALT_USB_GLOB_GDFIFOCFG_ADDR(ALT_USB0_GLOBGRP_ADDR)
/* The address of the ALT_USB_GLOB_HPTXFSIZ register for the ALT_USB0_GLOBGRP instance. */
#define ALT_USB0_GLOB_HPTXFSIZ_ADDR  ALT_USB_GLOB_HPTXFSIZ_ADDR(ALT_USB0_GLOBGRP_ADDR)
/* The address of the ALT_USB_GLOB_DIEPTXF1 register for the ALT_USB0_GLOBGRP instance. */
#define ALT_USB0_GLOB_DIEPTXF1_ADDR  ALT_USB_GLOB_DIEPTXF1_ADDR(ALT_USB0_GLOBGRP_ADDR)
/* The address of the ALT_USB_GLOB_DIEPTXF2 register for the ALT_USB0_GLOBGRP instance. */
#define ALT_USB0_GLOB_DIEPTXF2_ADDR  ALT_USB_GLOB_DIEPTXF2_ADDR(ALT_USB0_GLOBGRP_ADDR)
/* The address of the ALT_USB_GLOB_DIEPTXF3 register for the ALT_USB0_GLOBGRP instance. */
#define ALT_USB0_GLOB_DIEPTXF3_ADDR  ALT_USB_GLOB_DIEPTXF3_ADDR(ALT_USB0_GLOBGRP_ADDR)
/* The address of the ALT_USB_GLOB_DIEPTXF4 register for the ALT_USB0_GLOBGRP instance. */
#define ALT_USB0_GLOB_DIEPTXF4_ADDR  ALT_USB_GLOB_DIEPTXF4_ADDR(ALT_USB0_GLOBGRP_ADDR)
/* The address of the ALT_USB_GLOB_DIEPTXF5 register for the ALT_USB0_GLOBGRP instance. */
#define ALT_USB0_GLOB_DIEPTXF5_ADDR  ALT_USB_GLOB_DIEPTXF5_ADDR(ALT_USB0_GLOBGRP_ADDR)
/* The address of the ALT_USB_GLOB_DIEPTXF6 register for the ALT_USB0_GLOBGRP instance. */
#define ALT_USB0_GLOB_DIEPTXF6_ADDR  ALT_USB_GLOB_DIEPTXF6_ADDR(ALT_USB0_GLOBGRP_ADDR)
/* The address of the ALT_USB_GLOB_DIEPTXF7 register for the ALT_USB0_GLOBGRP instance. */
#define ALT_USB0_GLOB_DIEPTXF7_ADDR  ALT_USB_GLOB_DIEPTXF7_ADDR(ALT_USB0_GLOBGRP_ADDR)
/* The address of the ALT_USB_GLOB_DIEPTXF8 register for the ALT_USB0_GLOBGRP instance. */
#define ALT_USB0_GLOB_DIEPTXF8_ADDR  ALT_USB_GLOB_DIEPTXF8_ADDR(ALT_USB0_GLOBGRP_ADDR)
/* The address of the ALT_USB_GLOB_DIEPTXF9 register for the ALT_USB0_GLOBGRP instance. */
#define ALT_USB0_GLOB_DIEPTXF9_ADDR  ALT_USB_GLOB_DIEPTXF9_ADDR(ALT_USB0_GLOBGRP_ADDR)
/* The address of the ALT_USB_GLOB_DIEPTXF10 register for the ALT_USB0_GLOBGRP instance. */
#define ALT_USB0_GLOB_DIEPTXF10_ADDR  ALT_USB_GLOB_DIEPTXF10_ADDR(ALT_USB0_GLOBGRP_ADDR)
/* The address of the ALT_USB_GLOB_DIEPTXF11 register for the ALT_USB0_GLOBGRP instance. */
#define ALT_USB0_GLOB_DIEPTXF11_ADDR  ALT_USB_GLOB_DIEPTXF11_ADDR(ALT_USB0_GLOBGRP_ADDR)
/* The address of the ALT_USB_GLOB_DIEPTXF12 register for the ALT_USB0_GLOBGRP instance. */
#define ALT_USB0_GLOB_DIEPTXF12_ADDR  ALT_USB_GLOB_DIEPTXF12_ADDR(ALT_USB0_GLOBGRP_ADDR)
/* The address of the ALT_USB_GLOB_DIEPTXF13 register for the ALT_USB0_GLOBGRP instance. */
#define ALT_USB0_GLOB_DIEPTXF13_ADDR  ALT_USB_GLOB_DIEPTXF13_ADDR(ALT_USB0_GLOBGRP_ADDR)
/* The address of the ALT_USB_GLOB_DIEPTXF14 register for the ALT_USB0_GLOBGRP instance. */
#define ALT_USB0_GLOB_DIEPTXF14_ADDR  ALT_USB_GLOB_DIEPTXF14_ADDR(ALT_USB0_GLOBGRP_ADDR)
/* The address of the ALT_USB_GLOB_DIEPTXF15 register for the ALT_USB0_GLOBGRP instance. */
#define ALT_USB0_GLOB_DIEPTXF15_ADDR  ALT_USB_GLOB_DIEPTXF15_ADDR(ALT_USB0_GLOBGRP_ADDR)
/* The base address byte offset for the start of the ALT_USB0_GLOBGRP component. */
#define ALT_USB0_GLOBGRP_OFST        0xffb00000
/* The start address of the ALT_USB0_GLOBGRP component. */
#define ALT_USB0_GLOBGRP_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_USB0_GLOBGRP_OFST))
/* The lower bound address range of the ALT_USB0_GLOBGRP component. */
#define ALT_USB0_GLOBGRP_LB_ADDR     ALT_USB0_GLOBGRP_ADDR
/* The upper bound address range of the ALT_USB0_GLOBGRP component. */
#define ALT_USB0_GLOBGRP_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_USB0_GLOBGRP_ADDR) + 0x140) - 1))


/*
 * Component Instance : i_usbotg_0_hostgrp
 * 
 * Instance i_usbotg_0_hostgrp of component ALT_USB_HOST.
 * 
 * 
 */
/* The address of the ALT_USB_HOST_HCFG register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCFG_ADDR  ALT_USB_HOST_HCFG_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HFIR register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HFIR_ADDR  ALT_USB_HOST_HFIR_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HFNUM register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HFNUM_ADDR  ALT_USB_HOST_HFNUM_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HPTXSTS register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HPTXSTS_ADDR  ALT_USB_HOST_HPTXSTS_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HAINT register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HAINT_ADDR  ALT_USB_HOST_HAINT_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HAINTMSK register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HAINTMSK_ADDR  ALT_USB_HOST_HAINTMSK_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HFLBADDR register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HFLBADDR_ADDR  ALT_USB_HOST_HFLBADDR_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HPRT register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HPRT_ADDR  ALT_USB_HOST_HPRT_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCCHAR0 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCCHAR0_ADDR  ALT_USB_HOST_HCCHAR0_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCSPLT0 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCSPLT0_ADDR  ALT_USB_HOST_HCSPLT0_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCINT0 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCINT0_ADDR  ALT_USB_HOST_HCINT0_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCINTMSK0 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCINTMSK0_ADDR  ALT_USB_HOST_HCINTMSK0_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCTSIZ0 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCTSIZ0_ADDR  ALT_USB_HOST_HCTSIZ0_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCDMA0 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCDMA0_ADDR  ALT_USB_HOST_HCDMA0_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCDMAB0 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCDMAB0_ADDR  ALT_USB_HOST_HCDMAB0_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCCHAR1 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCCHAR1_ADDR  ALT_USB_HOST_HCCHAR1_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCSPLT1 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCSPLT1_ADDR  ALT_USB_HOST_HCSPLT1_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCINT1 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCINT1_ADDR  ALT_USB_HOST_HCINT1_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCINTMSK1 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCINTMSK1_ADDR  ALT_USB_HOST_HCINTMSK1_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCTSIZ1 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCTSIZ1_ADDR  ALT_USB_HOST_HCTSIZ1_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCDMA1 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCDMA1_ADDR  ALT_USB_HOST_HCDMA1_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCDMAB1 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCDMAB1_ADDR  ALT_USB_HOST_HCDMAB1_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCCHAR2 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCCHAR2_ADDR  ALT_USB_HOST_HCCHAR2_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCSPLT2 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCSPLT2_ADDR  ALT_USB_HOST_HCSPLT2_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCINT2 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCINT2_ADDR  ALT_USB_HOST_HCINT2_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCINTMSK2 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCINTMSK2_ADDR  ALT_USB_HOST_HCINTMSK2_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCTSIZ2 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCTSIZ2_ADDR  ALT_USB_HOST_HCTSIZ2_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCDMA2 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCDMA2_ADDR  ALT_USB_HOST_HCDMA2_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCDMAB2 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCDMAB2_ADDR  ALT_USB_HOST_HCDMAB2_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCCHAR3 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCCHAR3_ADDR  ALT_USB_HOST_HCCHAR3_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCSPLT3 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCSPLT3_ADDR  ALT_USB_HOST_HCSPLT3_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCINT3 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCINT3_ADDR  ALT_USB_HOST_HCINT3_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCINTMSK3 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCINTMSK3_ADDR  ALT_USB_HOST_HCINTMSK3_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCTSIZ3 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCTSIZ3_ADDR  ALT_USB_HOST_HCTSIZ3_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCDMA3 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCDMA3_ADDR  ALT_USB_HOST_HCDMA3_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCDMAB3 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCDMAB3_ADDR  ALT_USB_HOST_HCDMAB3_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCCHAR4 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCCHAR4_ADDR  ALT_USB_HOST_HCCHAR4_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCSPLT4 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCSPLT4_ADDR  ALT_USB_HOST_HCSPLT4_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCINT4 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCINT4_ADDR  ALT_USB_HOST_HCINT4_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCINTMSK4 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCINTMSK4_ADDR  ALT_USB_HOST_HCINTMSK4_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCTSIZ4 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCTSIZ4_ADDR  ALT_USB_HOST_HCTSIZ4_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCDMA4 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCDMA4_ADDR  ALT_USB_HOST_HCDMA4_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCDMAB4 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCDMAB4_ADDR  ALT_USB_HOST_HCDMAB4_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCCHAR5 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCCHAR5_ADDR  ALT_USB_HOST_HCCHAR5_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCSPLT5 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCSPLT5_ADDR  ALT_USB_HOST_HCSPLT5_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCINT5 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCINT5_ADDR  ALT_USB_HOST_HCINT5_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCINTMSK5 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCINTMSK5_ADDR  ALT_USB_HOST_HCINTMSK5_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCTSIZ5 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCTSIZ5_ADDR  ALT_USB_HOST_HCTSIZ5_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCDMA5 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCDMA5_ADDR  ALT_USB_HOST_HCDMA5_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCDMAB5 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCDMAB5_ADDR  ALT_USB_HOST_HCDMAB5_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCCHAR6 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCCHAR6_ADDR  ALT_USB_HOST_HCCHAR6_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCSPLT6 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCSPLT6_ADDR  ALT_USB_HOST_HCSPLT6_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCINT6 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCINT6_ADDR  ALT_USB_HOST_HCINT6_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCINTMSK6 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCINTMSK6_ADDR  ALT_USB_HOST_HCINTMSK6_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCTSIZ6 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCTSIZ6_ADDR  ALT_USB_HOST_HCTSIZ6_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCDMA6 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCDMA6_ADDR  ALT_USB_HOST_HCDMA6_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCDMAB6 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCDMAB6_ADDR  ALT_USB_HOST_HCDMAB6_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCCHAR7 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCCHAR7_ADDR  ALT_USB_HOST_HCCHAR7_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCSPLT7 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCSPLT7_ADDR  ALT_USB_HOST_HCSPLT7_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCINT7 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCINT7_ADDR  ALT_USB_HOST_HCINT7_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCINTMSK7 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCINTMSK7_ADDR  ALT_USB_HOST_HCINTMSK7_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCTSIZ7 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCTSIZ7_ADDR  ALT_USB_HOST_HCTSIZ7_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCDMA7 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCDMA7_ADDR  ALT_USB_HOST_HCDMA7_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCDMAB7 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCDMAB7_ADDR  ALT_USB_HOST_HCDMAB7_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCCHAR8 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCCHAR8_ADDR  ALT_USB_HOST_HCCHAR8_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCSPLT8 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCSPLT8_ADDR  ALT_USB_HOST_HCSPLT8_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCINT8 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCINT8_ADDR  ALT_USB_HOST_HCINT8_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCINTMSK8 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCINTMSK8_ADDR  ALT_USB_HOST_HCINTMSK8_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCTSIZ8 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCTSIZ8_ADDR  ALT_USB_HOST_HCTSIZ8_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCDMA8 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCDMA8_ADDR  ALT_USB_HOST_HCDMA8_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCDMAB8 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCDMAB8_ADDR  ALT_USB_HOST_HCDMAB8_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCCHAR9 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCCHAR9_ADDR  ALT_USB_HOST_HCCHAR9_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCSPLT9 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCSPLT9_ADDR  ALT_USB_HOST_HCSPLT9_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCINT9 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCINT9_ADDR  ALT_USB_HOST_HCINT9_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCINTMSK9 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCINTMSK9_ADDR  ALT_USB_HOST_HCINTMSK9_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCTSIZ9 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCTSIZ9_ADDR  ALT_USB_HOST_HCTSIZ9_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCDMA9 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCDMA9_ADDR  ALT_USB_HOST_HCDMA9_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCDMAB9 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCDMAB9_ADDR  ALT_USB_HOST_HCDMAB9_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCCHAR10 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCCHAR10_ADDR  ALT_USB_HOST_HCCHAR10_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCSPLT10 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCSPLT10_ADDR  ALT_USB_HOST_HCSPLT10_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCINT10 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCINT10_ADDR  ALT_USB_HOST_HCINT10_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCINTMSK10 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCINTMSK10_ADDR  ALT_USB_HOST_HCINTMSK10_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCTSIZ10 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCTSIZ10_ADDR  ALT_USB_HOST_HCTSIZ10_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCDMA10 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCDMA10_ADDR  ALT_USB_HOST_HCDMA10_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCDMAB10 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCDMAB10_ADDR  ALT_USB_HOST_HCDMAB10_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCCHAR11 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCCHAR11_ADDR  ALT_USB_HOST_HCCHAR11_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCSPLT11 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCSPLT11_ADDR  ALT_USB_HOST_HCSPLT11_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCINT11 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCINT11_ADDR  ALT_USB_HOST_HCINT11_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCINTMSK11 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCINTMSK11_ADDR  ALT_USB_HOST_HCINTMSK11_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCTSIZ11 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCTSIZ11_ADDR  ALT_USB_HOST_HCTSIZ11_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCDMA11 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCDMA11_ADDR  ALT_USB_HOST_HCDMA11_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCDMAB11 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCDMAB11_ADDR  ALT_USB_HOST_HCDMAB11_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCCHAR12 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCCHAR12_ADDR  ALT_USB_HOST_HCCHAR12_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCSPLT12 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCSPLT12_ADDR  ALT_USB_HOST_HCSPLT12_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCINT12 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCINT12_ADDR  ALT_USB_HOST_HCINT12_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCINTMSK12 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCINTMSK12_ADDR  ALT_USB_HOST_HCINTMSK12_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCTSIZ12 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCTSIZ12_ADDR  ALT_USB_HOST_HCTSIZ12_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCDMA12 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCDMA12_ADDR  ALT_USB_HOST_HCDMA12_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCDMAB12 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCDMAB12_ADDR  ALT_USB_HOST_HCDMAB12_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCCHAR13 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCCHAR13_ADDR  ALT_USB_HOST_HCCHAR13_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCSPLT13 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCSPLT13_ADDR  ALT_USB_HOST_HCSPLT13_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCINT13 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCINT13_ADDR  ALT_USB_HOST_HCINT13_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCINTMSK13 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCINTMSK13_ADDR  ALT_USB_HOST_HCINTMSK13_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCTSIZ13 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCTSIZ13_ADDR  ALT_USB_HOST_HCTSIZ13_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCDMA13 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCDMA13_ADDR  ALT_USB_HOST_HCDMA13_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCDMAB13 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCDMAB13_ADDR  ALT_USB_HOST_HCDMAB13_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCCHAR14 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCCHAR14_ADDR  ALT_USB_HOST_HCCHAR14_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCSPLT14 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCSPLT14_ADDR  ALT_USB_HOST_HCSPLT14_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCINT14 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCINT14_ADDR  ALT_USB_HOST_HCINT14_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCINTMSK14 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCINTMSK14_ADDR  ALT_USB_HOST_HCINTMSK14_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCTSIZ14 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCTSIZ14_ADDR  ALT_USB_HOST_HCTSIZ14_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCDMA14 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCDMA14_ADDR  ALT_USB_HOST_HCDMA14_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCDMAB14 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCDMAB14_ADDR  ALT_USB_HOST_HCDMAB14_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCCHAR15 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCCHAR15_ADDR  ALT_USB_HOST_HCCHAR15_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCSPLT15 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCSPLT15_ADDR  ALT_USB_HOST_HCSPLT15_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCINT15 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCINT15_ADDR  ALT_USB_HOST_HCINT15_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCINTMSK15 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCINTMSK15_ADDR  ALT_USB_HOST_HCINTMSK15_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCTSIZ15 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCTSIZ15_ADDR  ALT_USB_HOST_HCTSIZ15_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCDMA15 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCDMA15_ADDR  ALT_USB_HOST_HCDMA15_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCDMAB15 register for the ALT_USB0_HOSTGRP instance. */
#define ALT_USB0_HOST_HCDMAB15_ADDR  ALT_USB_HOST_HCDMAB15_ADDR(ALT_USB0_HOSTGRP_ADDR)
/* The base address byte offset for the start of the ALT_USB0_HOSTGRP component. */
#define ALT_USB0_HOSTGRP_OFST        0xffb00400
/* The start address of the ALT_USB0_HOSTGRP component. */
#define ALT_USB0_HOSTGRP_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_USB0_HOSTGRP_OFST))
/* The lower bound address range of the ALT_USB0_HOSTGRP component. */
#define ALT_USB0_HOSTGRP_LB_ADDR     ALT_USB0_HOSTGRP_ADDR
/* The upper bound address range of the ALT_USB0_HOSTGRP component. */
#define ALT_USB0_HOSTGRP_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_USB0_HOSTGRP_ADDR) + 0x300) - 1))


/*
 * Component Instance : i_usbotg_0_devgrp
 * 
 * Instance i_usbotg_0_devgrp of component ALT_USB_DEV.
 * 
 * 
 */
/* The address of the ALT_USB_DEV_DCFG register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DCFG_ADDR  ALT_USB_DEV_DCFG_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DCTL register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DCTL_ADDR  ALT_USB_DEV_DCTL_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DSTS register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DSTS_ADDR  ALT_USB_DEV_DSTS_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPMSK register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DIEPMSK_ADDR  ALT_USB_DEV_DIEPMSK_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPMSK register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DOEPMSK_ADDR  ALT_USB_DEV_DOEPMSK_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DAINT register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DAINT_ADDR  ALT_USB_DEV_DAINT_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DAINTMSK register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DAINTMSK_ADDR  ALT_USB_DEV_DAINTMSK_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DVBUSDIS register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DVBUSDIS_ADDR  ALT_USB_DEV_DVBUSDIS_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DVBUSPULSE register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DVBUSPULSE_ADDR  ALT_USB_DEV_DVBUSPULSE_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DTHRCTL register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DTHRCTL_ADDR  ALT_USB_DEV_DTHRCTL_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPEMPMSK register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DIEPEMPMSK_ADDR  ALT_USB_DEV_DIEPEMPMSK_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPCTL0 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DIEPCTL0_ADDR  ALT_USB_DEV_DIEPCTL0_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPINT0 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DIEPINT0_ADDR  ALT_USB_DEV_DIEPINT0_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPTSIZ0 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DIEPTSIZ0_ADDR  ALT_USB_DEV_DIEPTSIZ0_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPDMA0 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DIEPDMA0_ADDR  ALT_USB_DEV_DIEPDMA0_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DTXFSTS0 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DTXFSTS0_ADDR  ALT_USB_DEV_DTXFSTS0_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPDMAB0 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DIEPDMAB0_ADDR  ALT_USB_DEV_DIEPDMAB0_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPCTL1 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DIEPCTL1_ADDR  ALT_USB_DEV_DIEPCTL1_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPINT1 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DIEPINT1_ADDR  ALT_USB_DEV_DIEPINT1_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPTSIZ1 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DIEPTSIZ1_ADDR  ALT_USB_DEV_DIEPTSIZ1_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPDMA1 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DIEPDMA1_ADDR  ALT_USB_DEV_DIEPDMA1_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DTXFSTS1 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DTXFSTS1_ADDR  ALT_USB_DEV_DTXFSTS1_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPDMAB1 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DIEPDMAB1_ADDR  ALT_USB_DEV_DIEPDMAB1_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPCTL2 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DIEPCTL2_ADDR  ALT_USB_DEV_DIEPCTL2_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPINT2 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DIEPINT2_ADDR  ALT_USB_DEV_DIEPINT2_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPTSIZ2 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DIEPTSIZ2_ADDR  ALT_USB_DEV_DIEPTSIZ2_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPDMA2 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DIEPDMA2_ADDR  ALT_USB_DEV_DIEPDMA2_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DTXFSTS2 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DTXFSTS2_ADDR  ALT_USB_DEV_DTXFSTS2_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPDMAB2 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DIEPDMAB2_ADDR  ALT_USB_DEV_DIEPDMAB2_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPCTL3 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DIEPCTL3_ADDR  ALT_USB_DEV_DIEPCTL3_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPINT3 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DIEPINT3_ADDR  ALT_USB_DEV_DIEPINT3_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPTSIZ3 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DIEPTSIZ3_ADDR  ALT_USB_DEV_DIEPTSIZ3_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPDMA3 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DIEPDMA3_ADDR  ALT_USB_DEV_DIEPDMA3_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DTXFSTS3 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DTXFSTS3_ADDR  ALT_USB_DEV_DTXFSTS3_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPDMAB3 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DIEPDMAB3_ADDR  ALT_USB_DEV_DIEPDMAB3_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPCTL4 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DIEPCTL4_ADDR  ALT_USB_DEV_DIEPCTL4_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPINT4 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DIEPINT4_ADDR  ALT_USB_DEV_DIEPINT4_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPTSIZ4 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DIEPTSIZ4_ADDR  ALT_USB_DEV_DIEPTSIZ4_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPDMA4 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DIEPDMA4_ADDR  ALT_USB_DEV_DIEPDMA4_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DTXFSTS4 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DTXFSTS4_ADDR  ALT_USB_DEV_DTXFSTS4_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPDMAB4 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DIEPDMAB4_ADDR  ALT_USB_DEV_DIEPDMAB4_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPCTL5 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DIEPCTL5_ADDR  ALT_USB_DEV_DIEPCTL5_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPINT5 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DIEPINT5_ADDR  ALT_USB_DEV_DIEPINT5_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPTSIZ5 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DIEPTSIZ5_ADDR  ALT_USB_DEV_DIEPTSIZ5_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPDMA5 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DIEPDMA5_ADDR  ALT_USB_DEV_DIEPDMA5_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DTXFSTS5 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DTXFSTS5_ADDR  ALT_USB_DEV_DTXFSTS5_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPDMAB5 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DIEPDMAB5_ADDR  ALT_USB_DEV_DIEPDMAB5_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPCTL6 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DIEPCTL6_ADDR  ALT_USB_DEV_DIEPCTL6_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPINT6 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DIEPINT6_ADDR  ALT_USB_DEV_DIEPINT6_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPTSIZ6 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DIEPTSIZ6_ADDR  ALT_USB_DEV_DIEPTSIZ6_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPDMA6 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DIEPDMA6_ADDR  ALT_USB_DEV_DIEPDMA6_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DTXFSTS6 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DTXFSTS6_ADDR  ALT_USB_DEV_DTXFSTS6_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPDMAB6 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DIEPDMAB6_ADDR  ALT_USB_DEV_DIEPDMAB6_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPCTL7 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DIEPCTL7_ADDR  ALT_USB_DEV_DIEPCTL7_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPINT7 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DIEPINT7_ADDR  ALT_USB_DEV_DIEPINT7_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPTSIZ7 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DIEPTSIZ7_ADDR  ALT_USB_DEV_DIEPTSIZ7_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPDMA7 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DIEPDMA7_ADDR  ALT_USB_DEV_DIEPDMA7_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DTXFSTS7 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DTXFSTS7_ADDR  ALT_USB_DEV_DTXFSTS7_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPDMAB7 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DIEPDMAB7_ADDR  ALT_USB_DEV_DIEPDMAB7_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPCTL8 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DIEPCTL8_ADDR  ALT_USB_DEV_DIEPCTL8_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPINT8 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DIEPINT8_ADDR  ALT_USB_DEV_DIEPINT8_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPTSIZ8 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DIEPTSIZ8_ADDR  ALT_USB_DEV_DIEPTSIZ8_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPDMA8 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DIEPDMA8_ADDR  ALT_USB_DEV_DIEPDMA8_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DTXFSTS8 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DTXFSTS8_ADDR  ALT_USB_DEV_DTXFSTS8_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPDMAB8 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DIEPDMAB8_ADDR  ALT_USB_DEV_DIEPDMAB8_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPCTL9 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DIEPCTL9_ADDR  ALT_USB_DEV_DIEPCTL9_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPINT9 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DIEPINT9_ADDR  ALT_USB_DEV_DIEPINT9_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPTSIZ9 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DIEPTSIZ9_ADDR  ALT_USB_DEV_DIEPTSIZ9_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPDMA9 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DIEPDMA9_ADDR  ALT_USB_DEV_DIEPDMA9_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DTXFSTS9 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DTXFSTS9_ADDR  ALT_USB_DEV_DTXFSTS9_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPDMAB9 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DIEPDMAB9_ADDR  ALT_USB_DEV_DIEPDMAB9_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPCTL10 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DIEPCTL10_ADDR  ALT_USB_DEV_DIEPCTL10_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPINT10 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DIEPINT10_ADDR  ALT_USB_DEV_DIEPINT10_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPTSIZ10 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DIEPTSIZ10_ADDR  ALT_USB_DEV_DIEPTSIZ10_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPDMA10 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DIEPDMA10_ADDR  ALT_USB_DEV_DIEPDMA10_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DTXFSTS10 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DTXFSTS10_ADDR  ALT_USB_DEV_DTXFSTS10_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPDMAB10 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DIEPDMAB10_ADDR  ALT_USB_DEV_DIEPDMAB10_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPCTL11 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DIEPCTL11_ADDR  ALT_USB_DEV_DIEPCTL11_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPINT11 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DIEPINT11_ADDR  ALT_USB_DEV_DIEPINT11_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPTSIZ11 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DIEPTSIZ11_ADDR  ALT_USB_DEV_DIEPTSIZ11_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPDMA11 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DIEPDMA11_ADDR  ALT_USB_DEV_DIEPDMA11_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DTXFSTS11 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DTXFSTS11_ADDR  ALT_USB_DEV_DTXFSTS11_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPDMAB11 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DIEPDMAB11_ADDR  ALT_USB_DEV_DIEPDMAB11_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPCTL12 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DIEPCTL12_ADDR  ALT_USB_DEV_DIEPCTL12_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPINT12 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DIEPINT12_ADDR  ALT_USB_DEV_DIEPINT12_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPTSIZ12 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DIEPTSIZ12_ADDR  ALT_USB_DEV_DIEPTSIZ12_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPDMA12 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DIEPDMA12_ADDR  ALT_USB_DEV_DIEPDMA12_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DTXFSTS12 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DTXFSTS12_ADDR  ALT_USB_DEV_DTXFSTS12_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPDMAB12 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DIEPDMAB12_ADDR  ALT_USB_DEV_DIEPDMAB12_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPCTL13 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DIEPCTL13_ADDR  ALT_USB_DEV_DIEPCTL13_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPINT13 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DIEPINT13_ADDR  ALT_USB_DEV_DIEPINT13_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPTSIZ13 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DIEPTSIZ13_ADDR  ALT_USB_DEV_DIEPTSIZ13_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPDMA13 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DIEPDMA13_ADDR  ALT_USB_DEV_DIEPDMA13_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DTXFSTS13 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DTXFSTS13_ADDR  ALT_USB_DEV_DTXFSTS13_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPDMAB13 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DIEPDMAB13_ADDR  ALT_USB_DEV_DIEPDMAB13_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPCTL14 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DIEPCTL14_ADDR  ALT_USB_DEV_DIEPCTL14_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPINT14 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DIEPINT14_ADDR  ALT_USB_DEV_DIEPINT14_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPTSIZ14 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DIEPTSIZ14_ADDR  ALT_USB_DEV_DIEPTSIZ14_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPDMA14 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DIEPDMA14_ADDR  ALT_USB_DEV_DIEPDMA14_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DTXFSTS14 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DTXFSTS14_ADDR  ALT_USB_DEV_DTXFSTS14_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPDMAB14 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DIEPDMAB14_ADDR  ALT_USB_DEV_DIEPDMAB14_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPCTL15 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DIEPCTL15_ADDR  ALT_USB_DEV_DIEPCTL15_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPINT15 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DIEPINT15_ADDR  ALT_USB_DEV_DIEPINT15_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPTSIZ15 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DIEPTSIZ15_ADDR  ALT_USB_DEV_DIEPTSIZ15_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPDMA15 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DIEPDMA15_ADDR  ALT_USB_DEV_DIEPDMA15_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DTXFSTS15 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DTXFSTS15_ADDR  ALT_USB_DEV_DTXFSTS15_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPDMAB15 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DIEPDMAB15_ADDR  ALT_USB_DEV_DIEPDMAB15_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPCTL0 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DOEPCTL0_ADDR  ALT_USB_DEV_DOEPCTL0_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPINT0 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DOEPINT0_ADDR  ALT_USB_DEV_DOEPINT0_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPTSIZ0 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DOEPTSIZ0_ADDR  ALT_USB_DEV_DOEPTSIZ0_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPDMA0 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DOEPDMA0_ADDR  ALT_USB_DEV_DOEPDMA0_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPDMAB0 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DOEPDMAB0_ADDR  ALT_USB_DEV_DOEPDMAB0_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPCTL1 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DOEPCTL1_ADDR  ALT_USB_DEV_DOEPCTL1_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPINT1 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DOEPINT1_ADDR  ALT_USB_DEV_DOEPINT1_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPTSIZ1 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DOEPTSIZ1_ADDR  ALT_USB_DEV_DOEPTSIZ1_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPDMA1 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DOEPDMA1_ADDR  ALT_USB_DEV_DOEPDMA1_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPDMAB1 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DOEPDMAB1_ADDR  ALT_USB_DEV_DOEPDMAB1_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPCTL2 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DOEPCTL2_ADDR  ALT_USB_DEV_DOEPCTL2_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPINT2 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DOEPINT2_ADDR  ALT_USB_DEV_DOEPINT2_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPTSIZ2 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DOEPTSIZ2_ADDR  ALT_USB_DEV_DOEPTSIZ2_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPDMA2 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DOEPDMA2_ADDR  ALT_USB_DEV_DOEPDMA2_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPDMAB2 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DOEPDMAB2_ADDR  ALT_USB_DEV_DOEPDMAB2_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPCTL3 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DOEPCTL3_ADDR  ALT_USB_DEV_DOEPCTL3_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPINT3 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DOEPINT3_ADDR  ALT_USB_DEV_DOEPINT3_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPTSIZ3 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DOEPTSIZ3_ADDR  ALT_USB_DEV_DOEPTSIZ3_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPDMA3 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DOEPDMA3_ADDR  ALT_USB_DEV_DOEPDMA3_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPDMAB3 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DOEPDMAB3_ADDR  ALT_USB_DEV_DOEPDMAB3_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPCTL4 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DOEPCTL4_ADDR  ALT_USB_DEV_DOEPCTL4_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPINT4 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DOEPINT4_ADDR  ALT_USB_DEV_DOEPINT4_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPTSIZ4 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DOEPTSIZ4_ADDR  ALT_USB_DEV_DOEPTSIZ4_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPDMA4 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DOEPDMA4_ADDR  ALT_USB_DEV_DOEPDMA4_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPDMAB4 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DOEPDMAB4_ADDR  ALT_USB_DEV_DOEPDMAB4_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPCTL5 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DOEPCTL5_ADDR  ALT_USB_DEV_DOEPCTL5_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPINT5 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DOEPINT5_ADDR  ALT_USB_DEV_DOEPINT5_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPTSIZ5 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DOEPTSIZ5_ADDR  ALT_USB_DEV_DOEPTSIZ5_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPDMA5 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DOEPDMA5_ADDR  ALT_USB_DEV_DOEPDMA5_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPDMAB5 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DOEPDMAB5_ADDR  ALT_USB_DEV_DOEPDMAB5_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPCTL6 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DOEPCTL6_ADDR  ALT_USB_DEV_DOEPCTL6_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPINT6 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DOEPINT6_ADDR  ALT_USB_DEV_DOEPINT6_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPTSIZ6 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DOEPTSIZ6_ADDR  ALT_USB_DEV_DOEPTSIZ6_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPDMA6 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DOEPDMA6_ADDR  ALT_USB_DEV_DOEPDMA6_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPDMAB6 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DOEPDMAB6_ADDR  ALT_USB_DEV_DOEPDMAB6_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPCTL7 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DOEPCTL7_ADDR  ALT_USB_DEV_DOEPCTL7_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPINT7 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DOEPINT7_ADDR  ALT_USB_DEV_DOEPINT7_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPTSIZ7 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DOEPTSIZ7_ADDR  ALT_USB_DEV_DOEPTSIZ7_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPDMA7 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DOEPDMA7_ADDR  ALT_USB_DEV_DOEPDMA7_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPDMAB7 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DOEPDMAB7_ADDR  ALT_USB_DEV_DOEPDMAB7_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPCTL8 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DOEPCTL8_ADDR  ALT_USB_DEV_DOEPCTL8_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPINT8 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DOEPINT8_ADDR  ALT_USB_DEV_DOEPINT8_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPTSIZ8 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DOEPTSIZ8_ADDR  ALT_USB_DEV_DOEPTSIZ8_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPDMA8 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DOEPDMA8_ADDR  ALT_USB_DEV_DOEPDMA8_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPDMAB8 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DOEPDMAB8_ADDR  ALT_USB_DEV_DOEPDMAB8_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPCTL9 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DOEPCTL9_ADDR  ALT_USB_DEV_DOEPCTL9_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPINT9 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DOEPINT9_ADDR  ALT_USB_DEV_DOEPINT9_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPTSIZ9 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DOEPTSIZ9_ADDR  ALT_USB_DEV_DOEPTSIZ9_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPDMA9 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DOEPDMA9_ADDR  ALT_USB_DEV_DOEPDMA9_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPDMAB9 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DOEPDMAB9_ADDR  ALT_USB_DEV_DOEPDMAB9_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPCTL10 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DOEPCTL10_ADDR  ALT_USB_DEV_DOEPCTL10_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPINT10 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DOEPINT10_ADDR  ALT_USB_DEV_DOEPINT10_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPTSIZ10 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DOEPTSIZ10_ADDR  ALT_USB_DEV_DOEPTSIZ10_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPDMA10 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DOEPDMA10_ADDR  ALT_USB_DEV_DOEPDMA10_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPDMAB10 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DOEPDMAB10_ADDR  ALT_USB_DEV_DOEPDMAB10_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPCTL11 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DOEPCTL11_ADDR  ALT_USB_DEV_DOEPCTL11_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPINT11 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DOEPINT11_ADDR  ALT_USB_DEV_DOEPINT11_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPTSIZ11 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DOEPTSIZ11_ADDR  ALT_USB_DEV_DOEPTSIZ11_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPDMA11 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DOEPDMA11_ADDR  ALT_USB_DEV_DOEPDMA11_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPDMAB11 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DOEPDMAB11_ADDR  ALT_USB_DEV_DOEPDMAB11_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPCTL12 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DOEPCTL12_ADDR  ALT_USB_DEV_DOEPCTL12_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPINT12 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DOEPINT12_ADDR  ALT_USB_DEV_DOEPINT12_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPTSIZ12 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DOEPTSIZ12_ADDR  ALT_USB_DEV_DOEPTSIZ12_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPDMA12 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DOEPDMA12_ADDR  ALT_USB_DEV_DOEPDMA12_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPDMAB12 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DOEPDMAB12_ADDR  ALT_USB_DEV_DOEPDMAB12_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPCTL13 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DOEPCTL13_ADDR  ALT_USB_DEV_DOEPCTL13_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPINT13 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DOEPINT13_ADDR  ALT_USB_DEV_DOEPINT13_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPTSIZ13 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DOEPTSIZ13_ADDR  ALT_USB_DEV_DOEPTSIZ13_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPDMA13 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DOEPDMA13_ADDR  ALT_USB_DEV_DOEPDMA13_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPDMAB13 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DOEPDMAB13_ADDR  ALT_USB_DEV_DOEPDMAB13_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPCTL14 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DOEPCTL14_ADDR  ALT_USB_DEV_DOEPCTL14_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPINT14 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DOEPINT14_ADDR  ALT_USB_DEV_DOEPINT14_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPTSIZ14 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DOEPTSIZ14_ADDR  ALT_USB_DEV_DOEPTSIZ14_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPDMA14 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DOEPDMA14_ADDR  ALT_USB_DEV_DOEPDMA14_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPDMAB14 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DOEPDMAB14_ADDR  ALT_USB_DEV_DOEPDMAB14_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPCTL15 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DOEPCTL15_ADDR  ALT_USB_DEV_DOEPCTL15_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPINT15 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DOEPINT15_ADDR  ALT_USB_DEV_DOEPINT15_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPTSIZ15 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DOEPTSIZ15_ADDR  ALT_USB_DEV_DOEPTSIZ15_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPDMA15 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DOEPDMA15_ADDR  ALT_USB_DEV_DOEPDMA15_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPDMAB15 register for the ALT_USB0_DEVGRP instance. */
#define ALT_USB0_DEV_DOEPDMAB15_ADDR  ALT_USB_DEV_DOEPDMAB15_ADDR(ALT_USB0_DEVGRP_ADDR)
/* The base address byte offset for the start of the ALT_USB0_DEVGRP component. */
#define ALT_USB0_DEVGRP_OFST        0xffb00800
/* The start address of the ALT_USB0_DEVGRP component. */
#define ALT_USB0_DEVGRP_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_USB0_DEVGRP_OFST))
/* The lower bound address range of the ALT_USB0_DEVGRP component. */
#define ALT_USB0_DEVGRP_LB_ADDR     ALT_USB0_DEVGRP_ADDR
/* The upper bound address range of the ALT_USB0_DEVGRP component. */
#define ALT_USB0_DEVGRP_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_USB0_DEVGRP_ADDR) + 0x500) - 1))


/*
 * Component Instance : i_usbotg_0_pwrclkgrp
 * 
 * Instance i_usbotg_0_pwrclkgrp of component ALT_USB_PWRCLK.
 * 
 * 
 */
/* The address of the ALT_USB_PWRCLK_PCGCCTL register for the ALT_USB0_PWRCLKGRP instance. */
#define ALT_USB0_PWRCLK_PCGCCTL_ADDR  ALT_USB_PWRCLK_PCGCCTL_ADDR(ALT_USB0_PWRCLKGRP_ADDR)
/* The base address byte offset for the start of the ALT_USB0_PWRCLKGRP component. */
#define ALT_USB0_PWRCLKGRP_OFST        0xffb00e00
/* The start address of the ALT_USB0_PWRCLKGRP component. */
#define ALT_USB0_PWRCLKGRP_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_USB0_PWRCLKGRP_OFST))
/* The lower bound address range of the ALT_USB0_PWRCLKGRP component. */
#define ALT_USB0_PWRCLKGRP_LB_ADDR     ALT_USB0_PWRCLKGRP_ADDR
/* The upper bound address range of the ALT_USB0_PWRCLKGRP component. */
#define ALT_USB0_PWRCLKGRP_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_USB0_PWRCLKGRP_ADDR) + 0x4) - 1))


/*
 * Component Instance : i_usbotg_0_DWC_otg_DFIFO_0
 * 
 * Instance i_usbotg_0_DWC_otg_DFIFO_0 of component ALT_USB0_DWC_OTG_DFIFO_0.
 * 
 * 
 */
/* The base address byte offset for the start of the ALT_USB0_DWC_OTG_DFIFO_0 component. */
#define ALT_USB0_DWC_OTG_DFIFO_0_OFST        0xffb01000
/* The start address of the ALT_USB0_DWC_OTG_DFIFO_0 component. */
#define ALT_USB0_DWC_OTG_DFIFO_0_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_USB0_DWC_OTG_DFIFO_0_OFST))
/* The lower bound address range of the ALT_USB0_DWC_OTG_DFIFO_0 component. */
#define ALT_USB0_DWC_OTG_DFIFO_0_LB_ADDR     ALT_USB0_DWC_OTG_DFIFO_0_ADDR
/* The upper bound address range of the ALT_USB0_DWC_OTG_DFIFO_0 component. */
#define ALT_USB0_DWC_OTG_DFIFO_0_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_USB0_DWC_OTG_DFIFO_0_ADDR) + 0x1000) - 1))


/*
 * Component Instance : i_usbotg_0_DWC_otg_DFIFO_1
 * 
 * Instance i_usbotg_0_DWC_otg_DFIFO_1 of component ALT_USB0_DWC_OTG_DFIFO_1.
 * 
 * 
 */
/* The base address byte offset for the start of the ALT_USB0_DWC_OTG_DFIFO_1 component. */
#define ALT_USB0_DWC_OTG_DFIFO_1_OFST        0xffb02000
/* The start address of the ALT_USB0_DWC_OTG_DFIFO_1 component. */
#define ALT_USB0_DWC_OTG_DFIFO_1_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_USB0_DWC_OTG_DFIFO_1_OFST))
/* The lower bound address range of the ALT_USB0_DWC_OTG_DFIFO_1 component. */
#define ALT_USB0_DWC_OTG_DFIFO_1_LB_ADDR     ALT_USB0_DWC_OTG_DFIFO_1_ADDR
/* The upper bound address range of the ALT_USB0_DWC_OTG_DFIFO_1 component. */
#define ALT_USB0_DWC_OTG_DFIFO_1_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_USB0_DWC_OTG_DFIFO_1_ADDR) + 0x1000) - 1))


/*
 * Component Instance : i_usbotg_0_DWC_otg_DFIFO_2
 * 
 * Instance i_usbotg_0_DWC_otg_DFIFO_2 of component ALT_USB0_DWC_OTG_DFIFO_2.
 * 
 * 
 */
/* The base address byte offset for the start of the ALT_USB0_DWC_OTG_DFIFO_2 component. */
#define ALT_USB0_DWC_OTG_DFIFO_2_OFST        0xffb03000
/* The start address of the ALT_USB0_DWC_OTG_DFIFO_2 component. */
#define ALT_USB0_DWC_OTG_DFIFO_2_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_USB0_DWC_OTG_DFIFO_2_OFST))
/* The lower bound address range of the ALT_USB0_DWC_OTG_DFIFO_2 component. */
#define ALT_USB0_DWC_OTG_DFIFO_2_LB_ADDR     ALT_USB0_DWC_OTG_DFIFO_2_ADDR
/* The upper bound address range of the ALT_USB0_DWC_OTG_DFIFO_2 component. */
#define ALT_USB0_DWC_OTG_DFIFO_2_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_USB0_DWC_OTG_DFIFO_2_ADDR) + 0x1000) - 1))


/*
 * Component Instance : i_usbotg_0_DWC_otg_DFIFO_3
 * 
 * Instance i_usbotg_0_DWC_otg_DFIFO_3 of component ALT_USB0_DWC_OTG_DFIFO_3.
 * 
 * 
 */
/* The base address byte offset for the start of the ALT_USB0_DWC_OTG_DFIFO_3 component. */
#define ALT_USB0_DWC_OTG_DFIFO_3_OFST        0xffb04000
/* The start address of the ALT_USB0_DWC_OTG_DFIFO_3 component. */
#define ALT_USB0_DWC_OTG_DFIFO_3_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_USB0_DWC_OTG_DFIFO_3_OFST))
/* The lower bound address range of the ALT_USB0_DWC_OTG_DFIFO_3 component. */
#define ALT_USB0_DWC_OTG_DFIFO_3_LB_ADDR     ALT_USB0_DWC_OTG_DFIFO_3_ADDR
/* The upper bound address range of the ALT_USB0_DWC_OTG_DFIFO_3 component. */
#define ALT_USB0_DWC_OTG_DFIFO_3_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_USB0_DWC_OTG_DFIFO_3_ADDR) + 0x1000) - 1))


/*
 * Component Instance : i_usbotg_0_DWC_otg_DFIFO_4
 * 
 * Instance i_usbotg_0_DWC_otg_DFIFO_4 of component ALT_USB0_DWC_OTG_DFIFO_4.
 * 
 * 
 */
/* The base address byte offset for the start of the ALT_USB0_DWC_OTG_DFIFO_4 component. */
#define ALT_USB0_DWC_OTG_DFIFO_4_OFST        0xffb05000
/* The start address of the ALT_USB0_DWC_OTG_DFIFO_4 component. */
#define ALT_USB0_DWC_OTG_DFIFO_4_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_USB0_DWC_OTG_DFIFO_4_OFST))
/* The lower bound address range of the ALT_USB0_DWC_OTG_DFIFO_4 component. */
#define ALT_USB0_DWC_OTG_DFIFO_4_LB_ADDR     ALT_USB0_DWC_OTG_DFIFO_4_ADDR
/* The upper bound address range of the ALT_USB0_DWC_OTG_DFIFO_4 component. */
#define ALT_USB0_DWC_OTG_DFIFO_4_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_USB0_DWC_OTG_DFIFO_4_ADDR) + 0x1000) - 1))


/*
 * Component Instance : i_usbotg_0_DWC_otg_DFIFO_5
 * 
 * Instance i_usbotg_0_DWC_otg_DFIFO_5 of component ALT_USB0_DWC_OTG_DFIFO_5.
 * 
 * 
 */
/* The base address byte offset for the start of the ALT_USB0_DWC_OTG_DFIFO_5 component. */
#define ALT_USB0_DWC_OTG_DFIFO_5_OFST        0xffb06000
/* The start address of the ALT_USB0_DWC_OTG_DFIFO_5 component. */
#define ALT_USB0_DWC_OTG_DFIFO_5_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_USB0_DWC_OTG_DFIFO_5_OFST))
/* The lower bound address range of the ALT_USB0_DWC_OTG_DFIFO_5 component. */
#define ALT_USB0_DWC_OTG_DFIFO_5_LB_ADDR     ALT_USB0_DWC_OTG_DFIFO_5_ADDR
/* The upper bound address range of the ALT_USB0_DWC_OTG_DFIFO_5 component. */
#define ALT_USB0_DWC_OTG_DFIFO_5_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_USB0_DWC_OTG_DFIFO_5_ADDR) + 0x1000) - 1))


/*
 * Component Instance : i_usbotg_0_DWC_otg_DFIFO_6
 * 
 * Instance i_usbotg_0_DWC_otg_DFIFO_6 of component ALT_USB0_DWC_OTG_DFIFO_6.
 * 
 * 
 */
/* The base address byte offset for the start of the ALT_USB0_DWC_OTG_DFIFO_6 component. */
#define ALT_USB0_DWC_OTG_DFIFO_6_OFST        0xffb07000
/* The start address of the ALT_USB0_DWC_OTG_DFIFO_6 component. */
#define ALT_USB0_DWC_OTG_DFIFO_6_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_USB0_DWC_OTG_DFIFO_6_OFST))
/* The lower bound address range of the ALT_USB0_DWC_OTG_DFIFO_6 component. */
#define ALT_USB0_DWC_OTG_DFIFO_6_LB_ADDR     ALT_USB0_DWC_OTG_DFIFO_6_ADDR
/* The upper bound address range of the ALT_USB0_DWC_OTG_DFIFO_6 component. */
#define ALT_USB0_DWC_OTG_DFIFO_6_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_USB0_DWC_OTG_DFIFO_6_ADDR) + 0x1000) - 1))


/*
 * Component Instance : i_usbotg_0_DWC_otg_DFIFO_7
 * 
 * Instance i_usbotg_0_DWC_otg_DFIFO_7 of component ALT_USB0_DWC_OTG_DFIFO_7.
 * 
 * 
 */
/* The base address byte offset for the start of the ALT_USB0_DWC_OTG_DFIFO_7 component. */
#define ALT_USB0_DWC_OTG_DFIFO_7_OFST        0xffb08000
/* The start address of the ALT_USB0_DWC_OTG_DFIFO_7 component. */
#define ALT_USB0_DWC_OTG_DFIFO_7_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_USB0_DWC_OTG_DFIFO_7_OFST))
/* The lower bound address range of the ALT_USB0_DWC_OTG_DFIFO_7 component. */
#define ALT_USB0_DWC_OTG_DFIFO_7_LB_ADDR     ALT_USB0_DWC_OTG_DFIFO_7_ADDR
/* The upper bound address range of the ALT_USB0_DWC_OTG_DFIFO_7 component. */
#define ALT_USB0_DWC_OTG_DFIFO_7_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_USB0_DWC_OTG_DFIFO_7_ADDR) + 0x1000) - 1))


/*
 * Component Instance : i_usbotg_0_DWC_otg_DFIFO_8
 * 
 * Instance i_usbotg_0_DWC_otg_DFIFO_8 of component ALT_USB0_DWC_OTG_DFIFO_8.
 * 
 * 
 */
/* The base address byte offset for the start of the ALT_USB0_DWC_OTG_DFIFO_8 component. */
#define ALT_USB0_DWC_OTG_DFIFO_8_OFST        0xffb09000
/* The start address of the ALT_USB0_DWC_OTG_DFIFO_8 component. */
#define ALT_USB0_DWC_OTG_DFIFO_8_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_USB0_DWC_OTG_DFIFO_8_OFST))
/* The lower bound address range of the ALT_USB0_DWC_OTG_DFIFO_8 component. */
#define ALT_USB0_DWC_OTG_DFIFO_8_LB_ADDR     ALT_USB0_DWC_OTG_DFIFO_8_ADDR
/* The upper bound address range of the ALT_USB0_DWC_OTG_DFIFO_8 component. */
#define ALT_USB0_DWC_OTG_DFIFO_8_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_USB0_DWC_OTG_DFIFO_8_ADDR) + 0x1000) - 1))


/*
 * Component Instance : i_usbotg_0_DWC_otg_DFIFO_9
 * 
 * Instance i_usbotg_0_DWC_otg_DFIFO_9 of component ALT_USB0_DWC_OTG_DFIFO_9.
 * 
 * 
 */
/* The base address byte offset for the start of the ALT_USB0_DWC_OTG_DFIFO_9 component. */
#define ALT_USB0_DWC_OTG_DFIFO_9_OFST        0xffb0a000
/* The start address of the ALT_USB0_DWC_OTG_DFIFO_9 component. */
#define ALT_USB0_DWC_OTG_DFIFO_9_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_USB0_DWC_OTG_DFIFO_9_OFST))
/* The lower bound address range of the ALT_USB0_DWC_OTG_DFIFO_9 component. */
#define ALT_USB0_DWC_OTG_DFIFO_9_LB_ADDR     ALT_USB0_DWC_OTG_DFIFO_9_ADDR
/* The upper bound address range of the ALT_USB0_DWC_OTG_DFIFO_9 component. */
#define ALT_USB0_DWC_OTG_DFIFO_9_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_USB0_DWC_OTG_DFIFO_9_ADDR) + 0x1000) - 1))


/*
 * Component Instance : i_usbotg_0_DWC_otg_DFIFO_10
 * 
 * Instance i_usbotg_0_DWC_otg_DFIFO_10 of component ALT_USB0_DWC_OTG_DFIFO_10.
 * 
 * 
 */
/* The base address byte offset for the start of the ALT_USB0_DWC_OTG_DFIFO_10 component. */
#define ALT_USB0_DWC_OTG_DFIFO_10_OFST        0xffb0b000
/* The start address of the ALT_USB0_DWC_OTG_DFIFO_10 component. */
#define ALT_USB0_DWC_OTG_DFIFO_10_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_USB0_DWC_OTG_DFIFO_10_OFST))
/* The lower bound address range of the ALT_USB0_DWC_OTG_DFIFO_10 component. */
#define ALT_USB0_DWC_OTG_DFIFO_10_LB_ADDR     ALT_USB0_DWC_OTG_DFIFO_10_ADDR
/* The upper bound address range of the ALT_USB0_DWC_OTG_DFIFO_10 component. */
#define ALT_USB0_DWC_OTG_DFIFO_10_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_USB0_DWC_OTG_DFIFO_10_ADDR) + 0x1000) - 1))


/*
 * Component Instance : i_usbotg_0_DWC_otg_DFIFO_11
 * 
 * Instance i_usbotg_0_DWC_otg_DFIFO_11 of component ALT_USB0_DWC_OTG_DFIFO_11.
 * 
 * 
 */
/* The base address byte offset for the start of the ALT_USB0_DWC_OTG_DFIFO_11 component. */
#define ALT_USB0_DWC_OTG_DFIFO_11_OFST        0xffb0c000
/* The start address of the ALT_USB0_DWC_OTG_DFIFO_11 component. */
#define ALT_USB0_DWC_OTG_DFIFO_11_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_USB0_DWC_OTG_DFIFO_11_OFST))
/* The lower bound address range of the ALT_USB0_DWC_OTG_DFIFO_11 component. */
#define ALT_USB0_DWC_OTG_DFIFO_11_LB_ADDR     ALT_USB0_DWC_OTG_DFIFO_11_ADDR
/* The upper bound address range of the ALT_USB0_DWC_OTG_DFIFO_11 component. */
#define ALT_USB0_DWC_OTG_DFIFO_11_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_USB0_DWC_OTG_DFIFO_11_ADDR) + 0x1000) - 1))


/*
 * Component Instance : i_usbotg_0_DWC_otg_DFIFO_12
 * 
 * Instance i_usbotg_0_DWC_otg_DFIFO_12 of component ALT_USB0_DWC_OTG_DFIFO_12.
 * 
 * 
 */
/* The base address byte offset for the start of the ALT_USB0_DWC_OTG_DFIFO_12 component. */
#define ALT_USB0_DWC_OTG_DFIFO_12_OFST        0xffb0d000
/* The start address of the ALT_USB0_DWC_OTG_DFIFO_12 component. */
#define ALT_USB0_DWC_OTG_DFIFO_12_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_USB0_DWC_OTG_DFIFO_12_OFST))
/* The lower bound address range of the ALT_USB0_DWC_OTG_DFIFO_12 component. */
#define ALT_USB0_DWC_OTG_DFIFO_12_LB_ADDR     ALT_USB0_DWC_OTG_DFIFO_12_ADDR
/* The upper bound address range of the ALT_USB0_DWC_OTG_DFIFO_12 component. */
#define ALT_USB0_DWC_OTG_DFIFO_12_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_USB0_DWC_OTG_DFIFO_12_ADDR) + 0x1000) - 1))


/*
 * Component Instance : i_usbotg_0_DWC_otg_DFIFO_13
 * 
 * Instance i_usbotg_0_DWC_otg_DFIFO_13 of component ALT_USB0_DWC_OTG_DFIFO_13.
 * 
 * 
 */
/* The base address byte offset for the start of the ALT_USB0_DWC_OTG_DFIFO_13 component. */
#define ALT_USB0_DWC_OTG_DFIFO_13_OFST        0xffb0e000
/* The start address of the ALT_USB0_DWC_OTG_DFIFO_13 component. */
#define ALT_USB0_DWC_OTG_DFIFO_13_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_USB0_DWC_OTG_DFIFO_13_OFST))
/* The lower bound address range of the ALT_USB0_DWC_OTG_DFIFO_13 component. */
#define ALT_USB0_DWC_OTG_DFIFO_13_LB_ADDR     ALT_USB0_DWC_OTG_DFIFO_13_ADDR
/* The upper bound address range of the ALT_USB0_DWC_OTG_DFIFO_13 component. */
#define ALT_USB0_DWC_OTG_DFIFO_13_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_USB0_DWC_OTG_DFIFO_13_ADDR) + 0x1000) - 1))


/*
 * Component Instance : i_usbotg_0_DWC_otg_DFIFO_14
 * 
 * Instance i_usbotg_0_DWC_otg_DFIFO_14 of component ALT_USB0_DWC_OTG_DFIFO_14.
 * 
 * 
 */
/* The base address byte offset for the start of the ALT_USB0_DWC_OTG_DFIFO_14 component. */
#define ALT_USB0_DWC_OTG_DFIFO_14_OFST        0xffb0f000
/* The start address of the ALT_USB0_DWC_OTG_DFIFO_14 component. */
#define ALT_USB0_DWC_OTG_DFIFO_14_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_USB0_DWC_OTG_DFIFO_14_OFST))
/* The lower bound address range of the ALT_USB0_DWC_OTG_DFIFO_14 component. */
#define ALT_USB0_DWC_OTG_DFIFO_14_LB_ADDR     ALT_USB0_DWC_OTG_DFIFO_14_ADDR
/* The upper bound address range of the ALT_USB0_DWC_OTG_DFIFO_14 component. */
#define ALT_USB0_DWC_OTG_DFIFO_14_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_USB0_DWC_OTG_DFIFO_14_ADDR) + 0x1000) - 1))


/*
 * Component Instance : i_usbotg_0_DWC_otg_DFIFO_15
 * 
 * Instance i_usbotg_0_DWC_otg_DFIFO_15 of component ALT_USB0_DWC_OTG_DFIFO_15.
 * 
 * 
 */
/* The base address byte offset for the start of the ALT_USB0_DWC_OTG_DFIFO_15 component. */
#define ALT_USB0_DWC_OTG_DFIFO_15_OFST        0xffb10000
/* The start address of the ALT_USB0_DWC_OTG_DFIFO_15 component. */
#define ALT_USB0_DWC_OTG_DFIFO_15_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_USB0_DWC_OTG_DFIFO_15_OFST))
/* The lower bound address range of the ALT_USB0_DWC_OTG_DFIFO_15 component. */
#define ALT_USB0_DWC_OTG_DFIFO_15_LB_ADDR     ALT_USB0_DWC_OTG_DFIFO_15_ADDR
/* The upper bound address range of the ALT_USB0_DWC_OTG_DFIFO_15 component. */
#define ALT_USB0_DWC_OTG_DFIFO_15_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_USB0_DWC_OTG_DFIFO_15_ADDR) + 0x1000) - 1))


/*
 * Component Instance : i_usbotg_0_DWC_otg_DFIFO_Direct_access
 * 
 * Instance i_usbotg_0_DWC_otg_DFIFO_Direct_access of component ALT_USB0_DWC_OTG_DFIFO_DIRECT_ACCESS.
 * 
 * 
 */
/* The base address byte offset for the start of the ALT_USB0_DWC_OTG_DFIFO_DIRECT_ACCESS component. */
#define ALT_USB0_DWC_OTG_DFIFO_DIRECT_ACCESS_OFST        0xffb20000
/* The start address of the ALT_USB0_DWC_OTG_DFIFO_DIRECT_ACCESS component. */
#define ALT_USB0_DWC_OTG_DFIFO_DIRECT_ACCESS_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_USB0_DWC_OTG_DFIFO_DIRECT_ACCESS_OFST))
/* The lower bound address range of the ALT_USB0_DWC_OTG_DFIFO_DIRECT_ACCESS component. */
#define ALT_USB0_DWC_OTG_DFIFO_DIRECT_ACCESS_LB_ADDR     ALT_USB0_DWC_OTG_DFIFO_DIRECT_ACCESS_ADDR
/* The upper bound address range of the ALT_USB0_DWC_OTG_DFIFO_DIRECT_ACCESS component. */
#define ALT_USB0_DWC_OTG_DFIFO_DIRECT_ACCESS_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_USB0_DWC_OTG_DFIFO_DIRECT_ACCESS_ADDR) + 0x20000) - 1))


/*
 * Component Instance : i_usbotg_1_globgrp
 * 
 * Instance i_usbotg_1_globgrp of component ALT_USB_GLOB.
 * 
 * 
 */
/* The address of the ALT_USB_GLOB_GOTGCTL register for the ALT_USB1_GLOBGRP instance. */
#define ALT_USB1_GLOB_GOTGCTL_ADDR  ALT_USB_GLOB_GOTGCTL_ADDR(ALT_USB1_GLOBGRP_ADDR)
/* The address of the ALT_USB_GLOB_GOTGINT register for the ALT_USB1_GLOBGRP instance. */
#define ALT_USB1_GLOB_GOTGINT_ADDR  ALT_USB_GLOB_GOTGINT_ADDR(ALT_USB1_GLOBGRP_ADDR)
/* The address of the ALT_USB_GLOB_GAHBCFG register for the ALT_USB1_GLOBGRP instance. */
#define ALT_USB1_GLOB_GAHBCFG_ADDR  ALT_USB_GLOB_GAHBCFG_ADDR(ALT_USB1_GLOBGRP_ADDR)
/* The address of the ALT_USB_GLOB_GUSBCFG register for the ALT_USB1_GLOBGRP instance. */
#define ALT_USB1_GLOB_GUSBCFG_ADDR  ALT_USB_GLOB_GUSBCFG_ADDR(ALT_USB1_GLOBGRP_ADDR)
/* The address of the ALT_USB_GLOB_GRSTCTL register for the ALT_USB1_GLOBGRP instance. */
#define ALT_USB1_GLOB_GRSTCTL_ADDR  ALT_USB_GLOB_GRSTCTL_ADDR(ALT_USB1_GLOBGRP_ADDR)
/* The address of the ALT_USB_GLOB_GINTSTS register for the ALT_USB1_GLOBGRP instance. */
#define ALT_USB1_GLOB_GINTSTS_ADDR  ALT_USB_GLOB_GINTSTS_ADDR(ALT_USB1_GLOBGRP_ADDR)
/* The address of the ALT_USB_GLOB_GINTMSK register for the ALT_USB1_GLOBGRP instance. */
#define ALT_USB1_GLOB_GINTMSK_ADDR  ALT_USB_GLOB_GINTMSK_ADDR(ALT_USB1_GLOBGRP_ADDR)
/* The address of the ALT_USB_GLOB_GRXSTSR register for the ALT_USB1_GLOBGRP instance. */
#define ALT_USB1_GLOB_GRXSTSR_ADDR  ALT_USB_GLOB_GRXSTSR_ADDR(ALT_USB1_GLOBGRP_ADDR)
/* The address of the ALT_USB_GLOB_GRXSTSP register for the ALT_USB1_GLOBGRP instance. */
#define ALT_USB1_GLOB_GRXSTSP_ADDR  ALT_USB_GLOB_GRXSTSP_ADDR(ALT_USB1_GLOBGRP_ADDR)
/* The address of the ALT_USB_GLOB_GRXFSIZ register for the ALT_USB1_GLOBGRP instance. */
#define ALT_USB1_GLOB_GRXFSIZ_ADDR  ALT_USB_GLOB_GRXFSIZ_ADDR(ALT_USB1_GLOBGRP_ADDR)
/* The address of the ALT_USB_GLOB_GNPTXFSIZ register for the ALT_USB1_GLOBGRP instance. */
#define ALT_USB1_GLOB_GNPTXFSIZ_ADDR  ALT_USB_GLOB_GNPTXFSIZ_ADDR(ALT_USB1_GLOBGRP_ADDR)
/* The address of the ALT_USB_GLOB_GNPTXSTS register for the ALT_USB1_GLOBGRP instance. */
#define ALT_USB1_GLOB_GNPTXSTS_ADDR  ALT_USB_GLOB_GNPTXSTS_ADDR(ALT_USB1_GLOBGRP_ADDR)
/* The address of the ALT_USB_GLOB_GPVNDCTL register for the ALT_USB1_GLOBGRP instance. */
#define ALT_USB1_GLOB_GPVNDCTL_ADDR  ALT_USB_GLOB_GPVNDCTL_ADDR(ALT_USB1_GLOBGRP_ADDR)
/* The address of the ALT_USB_GLOB_GGPIO register for the ALT_USB1_GLOBGRP instance. */
#define ALT_USB1_GLOB_GGPIO_ADDR  ALT_USB_GLOB_GGPIO_ADDR(ALT_USB1_GLOBGRP_ADDR)
/* The address of the ALT_USB_GLOB_GUID register for the ALT_USB1_GLOBGRP instance. */
#define ALT_USB1_GLOB_GUID_ADDR  ALT_USB_GLOB_GUID_ADDR(ALT_USB1_GLOBGRP_ADDR)
/* The address of the ALT_USB_GLOB_GSNPSID register for the ALT_USB1_GLOBGRP instance. */
#define ALT_USB1_GLOB_GSNPSID_ADDR  ALT_USB_GLOB_GSNPSID_ADDR(ALT_USB1_GLOBGRP_ADDR)
/* The address of the ALT_USB_GLOB_GHWCFG1 register for the ALT_USB1_GLOBGRP instance. */
#define ALT_USB1_GLOB_GHWCFG1_ADDR  ALT_USB_GLOB_GHWCFG1_ADDR(ALT_USB1_GLOBGRP_ADDR)
/* The address of the ALT_USB_GLOB_GHWCFG2 register for the ALT_USB1_GLOBGRP instance. */
#define ALT_USB1_GLOB_GHWCFG2_ADDR  ALT_USB_GLOB_GHWCFG2_ADDR(ALT_USB1_GLOBGRP_ADDR)
/* The address of the ALT_USB_GLOB_GHWCFG3 register for the ALT_USB1_GLOBGRP instance. */
#define ALT_USB1_GLOB_GHWCFG3_ADDR  ALT_USB_GLOB_GHWCFG3_ADDR(ALT_USB1_GLOBGRP_ADDR)
/* The address of the ALT_USB_GLOB_GHWCFG4 register for the ALT_USB1_GLOBGRP instance. */
#define ALT_USB1_GLOB_GHWCFG4_ADDR  ALT_USB_GLOB_GHWCFG4_ADDR(ALT_USB1_GLOBGRP_ADDR)
/* The address of the ALT_USB_GLOB_GDFIFOCFG register for the ALT_USB1_GLOBGRP instance. */
#define ALT_USB1_GLOB_GDFIFOCFG_ADDR  ALT_USB_GLOB_GDFIFOCFG_ADDR(ALT_USB1_GLOBGRP_ADDR)
/* The address of the ALT_USB_GLOB_HPTXFSIZ register for the ALT_USB1_GLOBGRP instance. */
#define ALT_USB1_GLOB_HPTXFSIZ_ADDR  ALT_USB_GLOB_HPTXFSIZ_ADDR(ALT_USB1_GLOBGRP_ADDR)
/* The address of the ALT_USB_GLOB_DIEPTXF1 register for the ALT_USB1_GLOBGRP instance. */
#define ALT_USB1_GLOB_DIEPTXF1_ADDR  ALT_USB_GLOB_DIEPTXF1_ADDR(ALT_USB1_GLOBGRP_ADDR)
/* The address of the ALT_USB_GLOB_DIEPTXF2 register for the ALT_USB1_GLOBGRP instance. */
#define ALT_USB1_GLOB_DIEPTXF2_ADDR  ALT_USB_GLOB_DIEPTXF2_ADDR(ALT_USB1_GLOBGRP_ADDR)
/* The address of the ALT_USB_GLOB_DIEPTXF3 register for the ALT_USB1_GLOBGRP instance. */
#define ALT_USB1_GLOB_DIEPTXF3_ADDR  ALT_USB_GLOB_DIEPTXF3_ADDR(ALT_USB1_GLOBGRP_ADDR)
/* The address of the ALT_USB_GLOB_DIEPTXF4 register for the ALT_USB1_GLOBGRP instance. */
#define ALT_USB1_GLOB_DIEPTXF4_ADDR  ALT_USB_GLOB_DIEPTXF4_ADDR(ALT_USB1_GLOBGRP_ADDR)
/* The address of the ALT_USB_GLOB_DIEPTXF5 register for the ALT_USB1_GLOBGRP instance. */
#define ALT_USB1_GLOB_DIEPTXF5_ADDR  ALT_USB_GLOB_DIEPTXF5_ADDR(ALT_USB1_GLOBGRP_ADDR)
/* The address of the ALT_USB_GLOB_DIEPTXF6 register for the ALT_USB1_GLOBGRP instance. */
#define ALT_USB1_GLOB_DIEPTXF6_ADDR  ALT_USB_GLOB_DIEPTXF6_ADDR(ALT_USB1_GLOBGRP_ADDR)
/* The address of the ALT_USB_GLOB_DIEPTXF7 register for the ALT_USB1_GLOBGRP instance. */
#define ALT_USB1_GLOB_DIEPTXF7_ADDR  ALT_USB_GLOB_DIEPTXF7_ADDR(ALT_USB1_GLOBGRP_ADDR)
/* The address of the ALT_USB_GLOB_DIEPTXF8 register for the ALT_USB1_GLOBGRP instance. */
#define ALT_USB1_GLOB_DIEPTXF8_ADDR  ALT_USB_GLOB_DIEPTXF8_ADDR(ALT_USB1_GLOBGRP_ADDR)
/* The address of the ALT_USB_GLOB_DIEPTXF9 register for the ALT_USB1_GLOBGRP instance. */
#define ALT_USB1_GLOB_DIEPTXF9_ADDR  ALT_USB_GLOB_DIEPTXF9_ADDR(ALT_USB1_GLOBGRP_ADDR)
/* The address of the ALT_USB_GLOB_DIEPTXF10 register for the ALT_USB1_GLOBGRP instance. */
#define ALT_USB1_GLOB_DIEPTXF10_ADDR  ALT_USB_GLOB_DIEPTXF10_ADDR(ALT_USB1_GLOBGRP_ADDR)
/* The address of the ALT_USB_GLOB_DIEPTXF11 register for the ALT_USB1_GLOBGRP instance. */
#define ALT_USB1_GLOB_DIEPTXF11_ADDR  ALT_USB_GLOB_DIEPTXF11_ADDR(ALT_USB1_GLOBGRP_ADDR)
/* The address of the ALT_USB_GLOB_DIEPTXF12 register for the ALT_USB1_GLOBGRP instance. */
#define ALT_USB1_GLOB_DIEPTXF12_ADDR  ALT_USB_GLOB_DIEPTXF12_ADDR(ALT_USB1_GLOBGRP_ADDR)
/* The address of the ALT_USB_GLOB_DIEPTXF13 register for the ALT_USB1_GLOBGRP instance. */
#define ALT_USB1_GLOB_DIEPTXF13_ADDR  ALT_USB_GLOB_DIEPTXF13_ADDR(ALT_USB1_GLOBGRP_ADDR)
/* The address of the ALT_USB_GLOB_DIEPTXF14 register for the ALT_USB1_GLOBGRP instance. */
#define ALT_USB1_GLOB_DIEPTXF14_ADDR  ALT_USB_GLOB_DIEPTXF14_ADDR(ALT_USB1_GLOBGRP_ADDR)
/* The address of the ALT_USB_GLOB_DIEPTXF15 register for the ALT_USB1_GLOBGRP instance. */
#define ALT_USB1_GLOB_DIEPTXF15_ADDR  ALT_USB_GLOB_DIEPTXF15_ADDR(ALT_USB1_GLOBGRP_ADDR)
/* The base address byte offset for the start of the ALT_USB1_GLOBGRP component. */
#define ALT_USB1_GLOBGRP_OFST        0xffb40000
/* The start address of the ALT_USB1_GLOBGRP component. */
#define ALT_USB1_GLOBGRP_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_USB1_GLOBGRP_OFST))
/* The lower bound address range of the ALT_USB1_GLOBGRP component. */
#define ALT_USB1_GLOBGRP_LB_ADDR     ALT_USB1_GLOBGRP_ADDR
/* The upper bound address range of the ALT_USB1_GLOBGRP component. */
#define ALT_USB1_GLOBGRP_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_USB1_GLOBGRP_ADDR) + 0x140) - 1))


/*
 * Component Instance : i_usbotg_1_hostgrp
 * 
 * Instance i_usbotg_1_hostgrp of component ALT_USB_HOST.
 * 
 * 
 */
/* The address of the ALT_USB_HOST_HCFG register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCFG_ADDR  ALT_USB_HOST_HCFG_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HFIR register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HFIR_ADDR  ALT_USB_HOST_HFIR_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HFNUM register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HFNUM_ADDR  ALT_USB_HOST_HFNUM_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HPTXSTS register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HPTXSTS_ADDR  ALT_USB_HOST_HPTXSTS_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HAINT register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HAINT_ADDR  ALT_USB_HOST_HAINT_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HAINTMSK register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HAINTMSK_ADDR  ALT_USB_HOST_HAINTMSK_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HFLBADDR register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HFLBADDR_ADDR  ALT_USB_HOST_HFLBADDR_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HPRT register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HPRT_ADDR  ALT_USB_HOST_HPRT_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCCHAR0 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCCHAR0_ADDR  ALT_USB_HOST_HCCHAR0_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCSPLT0 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCSPLT0_ADDR  ALT_USB_HOST_HCSPLT0_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCINT0 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCINT0_ADDR  ALT_USB_HOST_HCINT0_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCINTMSK0 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCINTMSK0_ADDR  ALT_USB_HOST_HCINTMSK0_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCTSIZ0 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCTSIZ0_ADDR  ALT_USB_HOST_HCTSIZ0_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCDMA0 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCDMA0_ADDR  ALT_USB_HOST_HCDMA0_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCDMAB0 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCDMAB0_ADDR  ALT_USB_HOST_HCDMAB0_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCCHAR1 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCCHAR1_ADDR  ALT_USB_HOST_HCCHAR1_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCSPLT1 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCSPLT1_ADDR  ALT_USB_HOST_HCSPLT1_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCINT1 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCINT1_ADDR  ALT_USB_HOST_HCINT1_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCINTMSK1 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCINTMSK1_ADDR  ALT_USB_HOST_HCINTMSK1_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCTSIZ1 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCTSIZ1_ADDR  ALT_USB_HOST_HCTSIZ1_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCDMA1 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCDMA1_ADDR  ALT_USB_HOST_HCDMA1_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCDMAB1 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCDMAB1_ADDR  ALT_USB_HOST_HCDMAB1_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCCHAR2 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCCHAR2_ADDR  ALT_USB_HOST_HCCHAR2_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCSPLT2 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCSPLT2_ADDR  ALT_USB_HOST_HCSPLT2_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCINT2 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCINT2_ADDR  ALT_USB_HOST_HCINT2_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCINTMSK2 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCINTMSK2_ADDR  ALT_USB_HOST_HCINTMSK2_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCTSIZ2 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCTSIZ2_ADDR  ALT_USB_HOST_HCTSIZ2_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCDMA2 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCDMA2_ADDR  ALT_USB_HOST_HCDMA2_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCDMAB2 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCDMAB2_ADDR  ALT_USB_HOST_HCDMAB2_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCCHAR3 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCCHAR3_ADDR  ALT_USB_HOST_HCCHAR3_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCSPLT3 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCSPLT3_ADDR  ALT_USB_HOST_HCSPLT3_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCINT3 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCINT3_ADDR  ALT_USB_HOST_HCINT3_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCINTMSK3 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCINTMSK3_ADDR  ALT_USB_HOST_HCINTMSK3_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCTSIZ3 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCTSIZ3_ADDR  ALT_USB_HOST_HCTSIZ3_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCDMA3 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCDMA3_ADDR  ALT_USB_HOST_HCDMA3_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCDMAB3 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCDMAB3_ADDR  ALT_USB_HOST_HCDMAB3_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCCHAR4 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCCHAR4_ADDR  ALT_USB_HOST_HCCHAR4_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCSPLT4 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCSPLT4_ADDR  ALT_USB_HOST_HCSPLT4_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCINT4 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCINT4_ADDR  ALT_USB_HOST_HCINT4_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCINTMSK4 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCINTMSK4_ADDR  ALT_USB_HOST_HCINTMSK4_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCTSIZ4 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCTSIZ4_ADDR  ALT_USB_HOST_HCTSIZ4_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCDMA4 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCDMA4_ADDR  ALT_USB_HOST_HCDMA4_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCDMAB4 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCDMAB4_ADDR  ALT_USB_HOST_HCDMAB4_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCCHAR5 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCCHAR5_ADDR  ALT_USB_HOST_HCCHAR5_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCSPLT5 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCSPLT5_ADDR  ALT_USB_HOST_HCSPLT5_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCINT5 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCINT5_ADDR  ALT_USB_HOST_HCINT5_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCINTMSK5 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCINTMSK5_ADDR  ALT_USB_HOST_HCINTMSK5_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCTSIZ5 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCTSIZ5_ADDR  ALT_USB_HOST_HCTSIZ5_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCDMA5 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCDMA5_ADDR  ALT_USB_HOST_HCDMA5_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCDMAB5 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCDMAB5_ADDR  ALT_USB_HOST_HCDMAB5_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCCHAR6 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCCHAR6_ADDR  ALT_USB_HOST_HCCHAR6_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCSPLT6 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCSPLT6_ADDR  ALT_USB_HOST_HCSPLT6_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCINT6 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCINT6_ADDR  ALT_USB_HOST_HCINT6_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCINTMSK6 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCINTMSK6_ADDR  ALT_USB_HOST_HCINTMSK6_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCTSIZ6 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCTSIZ6_ADDR  ALT_USB_HOST_HCTSIZ6_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCDMA6 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCDMA6_ADDR  ALT_USB_HOST_HCDMA6_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCDMAB6 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCDMAB6_ADDR  ALT_USB_HOST_HCDMAB6_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCCHAR7 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCCHAR7_ADDR  ALT_USB_HOST_HCCHAR7_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCSPLT7 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCSPLT7_ADDR  ALT_USB_HOST_HCSPLT7_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCINT7 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCINT7_ADDR  ALT_USB_HOST_HCINT7_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCINTMSK7 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCINTMSK7_ADDR  ALT_USB_HOST_HCINTMSK7_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCTSIZ7 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCTSIZ7_ADDR  ALT_USB_HOST_HCTSIZ7_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCDMA7 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCDMA7_ADDR  ALT_USB_HOST_HCDMA7_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCDMAB7 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCDMAB7_ADDR  ALT_USB_HOST_HCDMAB7_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCCHAR8 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCCHAR8_ADDR  ALT_USB_HOST_HCCHAR8_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCSPLT8 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCSPLT8_ADDR  ALT_USB_HOST_HCSPLT8_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCINT8 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCINT8_ADDR  ALT_USB_HOST_HCINT8_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCINTMSK8 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCINTMSK8_ADDR  ALT_USB_HOST_HCINTMSK8_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCTSIZ8 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCTSIZ8_ADDR  ALT_USB_HOST_HCTSIZ8_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCDMA8 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCDMA8_ADDR  ALT_USB_HOST_HCDMA8_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCDMAB8 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCDMAB8_ADDR  ALT_USB_HOST_HCDMAB8_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCCHAR9 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCCHAR9_ADDR  ALT_USB_HOST_HCCHAR9_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCSPLT9 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCSPLT9_ADDR  ALT_USB_HOST_HCSPLT9_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCINT9 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCINT9_ADDR  ALT_USB_HOST_HCINT9_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCINTMSK9 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCINTMSK9_ADDR  ALT_USB_HOST_HCINTMSK9_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCTSIZ9 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCTSIZ9_ADDR  ALT_USB_HOST_HCTSIZ9_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCDMA9 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCDMA9_ADDR  ALT_USB_HOST_HCDMA9_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCDMAB9 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCDMAB9_ADDR  ALT_USB_HOST_HCDMAB9_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCCHAR10 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCCHAR10_ADDR  ALT_USB_HOST_HCCHAR10_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCSPLT10 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCSPLT10_ADDR  ALT_USB_HOST_HCSPLT10_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCINT10 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCINT10_ADDR  ALT_USB_HOST_HCINT10_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCINTMSK10 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCINTMSK10_ADDR  ALT_USB_HOST_HCINTMSK10_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCTSIZ10 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCTSIZ10_ADDR  ALT_USB_HOST_HCTSIZ10_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCDMA10 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCDMA10_ADDR  ALT_USB_HOST_HCDMA10_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCDMAB10 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCDMAB10_ADDR  ALT_USB_HOST_HCDMAB10_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCCHAR11 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCCHAR11_ADDR  ALT_USB_HOST_HCCHAR11_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCSPLT11 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCSPLT11_ADDR  ALT_USB_HOST_HCSPLT11_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCINT11 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCINT11_ADDR  ALT_USB_HOST_HCINT11_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCINTMSK11 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCINTMSK11_ADDR  ALT_USB_HOST_HCINTMSK11_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCTSIZ11 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCTSIZ11_ADDR  ALT_USB_HOST_HCTSIZ11_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCDMA11 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCDMA11_ADDR  ALT_USB_HOST_HCDMA11_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCDMAB11 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCDMAB11_ADDR  ALT_USB_HOST_HCDMAB11_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCCHAR12 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCCHAR12_ADDR  ALT_USB_HOST_HCCHAR12_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCSPLT12 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCSPLT12_ADDR  ALT_USB_HOST_HCSPLT12_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCINT12 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCINT12_ADDR  ALT_USB_HOST_HCINT12_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCINTMSK12 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCINTMSK12_ADDR  ALT_USB_HOST_HCINTMSK12_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCTSIZ12 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCTSIZ12_ADDR  ALT_USB_HOST_HCTSIZ12_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCDMA12 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCDMA12_ADDR  ALT_USB_HOST_HCDMA12_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCDMAB12 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCDMAB12_ADDR  ALT_USB_HOST_HCDMAB12_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCCHAR13 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCCHAR13_ADDR  ALT_USB_HOST_HCCHAR13_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCSPLT13 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCSPLT13_ADDR  ALT_USB_HOST_HCSPLT13_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCINT13 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCINT13_ADDR  ALT_USB_HOST_HCINT13_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCINTMSK13 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCINTMSK13_ADDR  ALT_USB_HOST_HCINTMSK13_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCTSIZ13 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCTSIZ13_ADDR  ALT_USB_HOST_HCTSIZ13_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCDMA13 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCDMA13_ADDR  ALT_USB_HOST_HCDMA13_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCDMAB13 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCDMAB13_ADDR  ALT_USB_HOST_HCDMAB13_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCCHAR14 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCCHAR14_ADDR  ALT_USB_HOST_HCCHAR14_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCSPLT14 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCSPLT14_ADDR  ALT_USB_HOST_HCSPLT14_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCINT14 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCINT14_ADDR  ALT_USB_HOST_HCINT14_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCINTMSK14 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCINTMSK14_ADDR  ALT_USB_HOST_HCINTMSK14_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCTSIZ14 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCTSIZ14_ADDR  ALT_USB_HOST_HCTSIZ14_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCDMA14 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCDMA14_ADDR  ALT_USB_HOST_HCDMA14_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCDMAB14 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCDMAB14_ADDR  ALT_USB_HOST_HCDMAB14_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCCHAR15 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCCHAR15_ADDR  ALT_USB_HOST_HCCHAR15_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCSPLT15 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCSPLT15_ADDR  ALT_USB_HOST_HCSPLT15_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCINT15 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCINT15_ADDR  ALT_USB_HOST_HCINT15_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCINTMSK15 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCINTMSK15_ADDR  ALT_USB_HOST_HCINTMSK15_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCTSIZ15 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCTSIZ15_ADDR  ALT_USB_HOST_HCTSIZ15_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCDMA15 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCDMA15_ADDR  ALT_USB_HOST_HCDMA15_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The address of the ALT_USB_HOST_HCDMAB15 register for the ALT_USB1_HOSTGRP instance. */
#define ALT_USB1_HOST_HCDMAB15_ADDR  ALT_USB_HOST_HCDMAB15_ADDR(ALT_USB1_HOSTGRP_ADDR)
/* The base address byte offset for the start of the ALT_USB1_HOSTGRP component. */
#define ALT_USB1_HOSTGRP_OFST        0xffb40400
/* The start address of the ALT_USB1_HOSTGRP component. */
#define ALT_USB1_HOSTGRP_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_USB1_HOSTGRP_OFST))
/* The lower bound address range of the ALT_USB1_HOSTGRP component. */
#define ALT_USB1_HOSTGRP_LB_ADDR     ALT_USB1_HOSTGRP_ADDR
/* The upper bound address range of the ALT_USB1_HOSTGRP component. */
#define ALT_USB1_HOSTGRP_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_USB1_HOSTGRP_ADDR) + 0x300) - 1))


/*
 * Component Instance : i_usbotg_1_devgrp
 * 
 * Instance i_usbotg_1_devgrp of component ALT_USB_DEV.
 * 
 * 
 */
/* The address of the ALT_USB_DEV_DCFG register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DCFG_ADDR  ALT_USB_DEV_DCFG_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DCTL register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DCTL_ADDR  ALT_USB_DEV_DCTL_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DSTS register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DSTS_ADDR  ALT_USB_DEV_DSTS_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPMSK register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DIEPMSK_ADDR  ALT_USB_DEV_DIEPMSK_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPMSK register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DOEPMSK_ADDR  ALT_USB_DEV_DOEPMSK_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DAINT register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DAINT_ADDR  ALT_USB_DEV_DAINT_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DAINTMSK register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DAINTMSK_ADDR  ALT_USB_DEV_DAINTMSK_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DVBUSDIS register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DVBUSDIS_ADDR  ALT_USB_DEV_DVBUSDIS_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DVBUSPULSE register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DVBUSPULSE_ADDR  ALT_USB_DEV_DVBUSPULSE_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DTHRCTL register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DTHRCTL_ADDR  ALT_USB_DEV_DTHRCTL_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPEMPMSK register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DIEPEMPMSK_ADDR  ALT_USB_DEV_DIEPEMPMSK_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPCTL0 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DIEPCTL0_ADDR  ALT_USB_DEV_DIEPCTL0_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPINT0 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DIEPINT0_ADDR  ALT_USB_DEV_DIEPINT0_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPTSIZ0 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DIEPTSIZ0_ADDR  ALT_USB_DEV_DIEPTSIZ0_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPDMA0 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DIEPDMA0_ADDR  ALT_USB_DEV_DIEPDMA0_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DTXFSTS0 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DTXFSTS0_ADDR  ALT_USB_DEV_DTXFSTS0_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPDMAB0 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DIEPDMAB0_ADDR  ALT_USB_DEV_DIEPDMAB0_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPCTL1 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DIEPCTL1_ADDR  ALT_USB_DEV_DIEPCTL1_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPINT1 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DIEPINT1_ADDR  ALT_USB_DEV_DIEPINT1_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPTSIZ1 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DIEPTSIZ1_ADDR  ALT_USB_DEV_DIEPTSIZ1_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPDMA1 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DIEPDMA1_ADDR  ALT_USB_DEV_DIEPDMA1_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DTXFSTS1 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DTXFSTS1_ADDR  ALT_USB_DEV_DTXFSTS1_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPDMAB1 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DIEPDMAB1_ADDR  ALT_USB_DEV_DIEPDMAB1_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPCTL2 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DIEPCTL2_ADDR  ALT_USB_DEV_DIEPCTL2_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPINT2 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DIEPINT2_ADDR  ALT_USB_DEV_DIEPINT2_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPTSIZ2 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DIEPTSIZ2_ADDR  ALT_USB_DEV_DIEPTSIZ2_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPDMA2 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DIEPDMA2_ADDR  ALT_USB_DEV_DIEPDMA2_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DTXFSTS2 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DTXFSTS2_ADDR  ALT_USB_DEV_DTXFSTS2_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPDMAB2 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DIEPDMAB2_ADDR  ALT_USB_DEV_DIEPDMAB2_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPCTL3 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DIEPCTL3_ADDR  ALT_USB_DEV_DIEPCTL3_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPINT3 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DIEPINT3_ADDR  ALT_USB_DEV_DIEPINT3_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPTSIZ3 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DIEPTSIZ3_ADDR  ALT_USB_DEV_DIEPTSIZ3_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPDMA3 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DIEPDMA3_ADDR  ALT_USB_DEV_DIEPDMA3_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DTXFSTS3 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DTXFSTS3_ADDR  ALT_USB_DEV_DTXFSTS3_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPDMAB3 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DIEPDMAB3_ADDR  ALT_USB_DEV_DIEPDMAB3_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPCTL4 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DIEPCTL4_ADDR  ALT_USB_DEV_DIEPCTL4_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPINT4 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DIEPINT4_ADDR  ALT_USB_DEV_DIEPINT4_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPTSIZ4 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DIEPTSIZ4_ADDR  ALT_USB_DEV_DIEPTSIZ4_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPDMA4 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DIEPDMA4_ADDR  ALT_USB_DEV_DIEPDMA4_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DTXFSTS4 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DTXFSTS4_ADDR  ALT_USB_DEV_DTXFSTS4_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPDMAB4 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DIEPDMAB4_ADDR  ALT_USB_DEV_DIEPDMAB4_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPCTL5 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DIEPCTL5_ADDR  ALT_USB_DEV_DIEPCTL5_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPINT5 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DIEPINT5_ADDR  ALT_USB_DEV_DIEPINT5_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPTSIZ5 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DIEPTSIZ5_ADDR  ALT_USB_DEV_DIEPTSIZ5_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPDMA5 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DIEPDMA5_ADDR  ALT_USB_DEV_DIEPDMA5_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DTXFSTS5 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DTXFSTS5_ADDR  ALT_USB_DEV_DTXFSTS5_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPDMAB5 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DIEPDMAB5_ADDR  ALT_USB_DEV_DIEPDMAB5_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPCTL6 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DIEPCTL6_ADDR  ALT_USB_DEV_DIEPCTL6_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPINT6 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DIEPINT6_ADDR  ALT_USB_DEV_DIEPINT6_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPTSIZ6 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DIEPTSIZ6_ADDR  ALT_USB_DEV_DIEPTSIZ6_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPDMA6 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DIEPDMA6_ADDR  ALT_USB_DEV_DIEPDMA6_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DTXFSTS6 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DTXFSTS6_ADDR  ALT_USB_DEV_DTXFSTS6_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPDMAB6 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DIEPDMAB6_ADDR  ALT_USB_DEV_DIEPDMAB6_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPCTL7 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DIEPCTL7_ADDR  ALT_USB_DEV_DIEPCTL7_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPINT7 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DIEPINT7_ADDR  ALT_USB_DEV_DIEPINT7_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPTSIZ7 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DIEPTSIZ7_ADDR  ALT_USB_DEV_DIEPTSIZ7_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPDMA7 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DIEPDMA7_ADDR  ALT_USB_DEV_DIEPDMA7_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DTXFSTS7 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DTXFSTS7_ADDR  ALT_USB_DEV_DTXFSTS7_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPDMAB7 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DIEPDMAB7_ADDR  ALT_USB_DEV_DIEPDMAB7_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPCTL8 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DIEPCTL8_ADDR  ALT_USB_DEV_DIEPCTL8_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPINT8 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DIEPINT8_ADDR  ALT_USB_DEV_DIEPINT8_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPTSIZ8 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DIEPTSIZ8_ADDR  ALT_USB_DEV_DIEPTSIZ8_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPDMA8 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DIEPDMA8_ADDR  ALT_USB_DEV_DIEPDMA8_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DTXFSTS8 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DTXFSTS8_ADDR  ALT_USB_DEV_DTXFSTS8_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPDMAB8 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DIEPDMAB8_ADDR  ALT_USB_DEV_DIEPDMAB8_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPCTL9 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DIEPCTL9_ADDR  ALT_USB_DEV_DIEPCTL9_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPINT9 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DIEPINT9_ADDR  ALT_USB_DEV_DIEPINT9_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPTSIZ9 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DIEPTSIZ9_ADDR  ALT_USB_DEV_DIEPTSIZ9_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPDMA9 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DIEPDMA9_ADDR  ALT_USB_DEV_DIEPDMA9_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DTXFSTS9 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DTXFSTS9_ADDR  ALT_USB_DEV_DTXFSTS9_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPDMAB9 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DIEPDMAB9_ADDR  ALT_USB_DEV_DIEPDMAB9_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPCTL10 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DIEPCTL10_ADDR  ALT_USB_DEV_DIEPCTL10_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPINT10 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DIEPINT10_ADDR  ALT_USB_DEV_DIEPINT10_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPTSIZ10 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DIEPTSIZ10_ADDR  ALT_USB_DEV_DIEPTSIZ10_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPDMA10 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DIEPDMA10_ADDR  ALT_USB_DEV_DIEPDMA10_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DTXFSTS10 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DTXFSTS10_ADDR  ALT_USB_DEV_DTXFSTS10_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPDMAB10 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DIEPDMAB10_ADDR  ALT_USB_DEV_DIEPDMAB10_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPCTL11 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DIEPCTL11_ADDR  ALT_USB_DEV_DIEPCTL11_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPINT11 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DIEPINT11_ADDR  ALT_USB_DEV_DIEPINT11_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPTSIZ11 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DIEPTSIZ11_ADDR  ALT_USB_DEV_DIEPTSIZ11_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPDMA11 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DIEPDMA11_ADDR  ALT_USB_DEV_DIEPDMA11_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DTXFSTS11 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DTXFSTS11_ADDR  ALT_USB_DEV_DTXFSTS11_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPDMAB11 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DIEPDMAB11_ADDR  ALT_USB_DEV_DIEPDMAB11_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPCTL12 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DIEPCTL12_ADDR  ALT_USB_DEV_DIEPCTL12_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPINT12 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DIEPINT12_ADDR  ALT_USB_DEV_DIEPINT12_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPTSIZ12 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DIEPTSIZ12_ADDR  ALT_USB_DEV_DIEPTSIZ12_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPDMA12 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DIEPDMA12_ADDR  ALT_USB_DEV_DIEPDMA12_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DTXFSTS12 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DTXFSTS12_ADDR  ALT_USB_DEV_DTXFSTS12_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPDMAB12 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DIEPDMAB12_ADDR  ALT_USB_DEV_DIEPDMAB12_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPCTL13 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DIEPCTL13_ADDR  ALT_USB_DEV_DIEPCTL13_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPINT13 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DIEPINT13_ADDR  ALT_USB_DEV_DIEPINT13_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPTSIZ13 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DIEPTSIZ13_ADDR  ALT_USB_DEV_DIEPTSIZ13_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPDMA13 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DIEPDMA13_ADDR  ALT_USB_DEV_DIEPDMA13_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DTXFSTS13 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DTXFSTS13_ADDR  ALT_USB_DEV_DTXFSTS13_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPDMAB13 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DIEPDMAB13_ADDR  ALT_USB_DEV_DIEPDMAB13_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPCTL14 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DIEPCTL14_ADDR  ALT_USB_DEV_DIEPCTL14_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPINT14 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DIEPINT14_ADDR  ALT_USB_DEV_DIEPINT14_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPTSIZ14 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DIEPTSIZ14_ADDR  ALT_USB_DEV_DIEPTSIZ14_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPDMA14 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DIEPDMA14_ADDR  ALT_USB_DEV_DIEPDMA14_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DTXFSTS14 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DTXFSTS14_ADDR  ALT_USB_DEV_DTXFSTS14_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPDMAB14 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DIEPDMAB14_ADDR  ALT_USB_DEV_DIEPDMAB14_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPCTL15 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DIEPCTL15_ADDR  ALT_USB_DEV_DIEPCTL15_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPINT15 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DIEPINT15_ADDR  ALT_USB_DEV_DIEPINT15_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPTSIZ15 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DIEPTSIZ15_ADDR  ALT_USB_DEV_DIEPTSIZ15_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPDMA15 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DIEPDMA15_ADDR  ALT_USB_DEV_DIEPDMA15_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DTXFSTS15 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DTXFSTS15_ADDR  ALT_USB_DEV_DTXFSTS15_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DIEPDMAB15 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DIEPDMAB15_ADDR  ALT_USB_DEV_DIEPDMAB15_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPCTL0 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DOEPCTL0_ADDR  ALT_USB_DEV_DOEPCTL0_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPINT0 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DOEPINT0_ADDR  ALT_USB_DEV_DOEPINT0_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPTSIZ0 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DOEPTSIZ0_ADDR  ALT_USB_DEV_DOEPTSIZ0_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPDMA0 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DOEPDMA0_ADDR  ALT_USB_DEV_DOEPDMA0_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPDMAB0 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DOEPDMAB0_ADDR  ALT_USB_DEV_DOEPDMAB0_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPCTL1 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DOEPCTL1_ADDR  ALT_USB_DEV_DOEPCTL1_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPINT1 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DOEPINT1_ADDR  ALT_USB_DEV_DOEPINT1_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPTSIZ1 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DOEPTSIZ1_ADDR  ALT_USB_DEV_DOEPTSIZ1_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPDMA1 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DOEPDMA1_ADDR  ALT_USB_DEV_DOEPDMA1_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPDMAB1 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DOEPDMAB1_ADDR  ALT_USB_DEV_DOEPDMAB1_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPCTL2 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DOEPCTL2_ADDR  ALT_USB_DEV_DOEPCTL2_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPINT2 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DOEPINT2_ADDR  ALT_USB_DEV_DOEPINT2_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPTSIZ2 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DOEPTSIZ2_ADDR  ALT_USB_DEV_DOEPTSIZ2_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPDMA2 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DOEPDMA2_ADDR  ALT_USB_DEV_DOEPDMA2_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPDMAB2 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DOEPDMAB2_ADDR  ALT_USB_DEV_DOEPDMAB2_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPCTL3 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DOEPCTL3_ADDR  ALT_USB_DEV_DOEPCTL3_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPINT3 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DOEPINT3_ADDR  ALT_USB_DEV_DOEPINT3_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPTSIZ3 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DOEPTSIZ3_ADDR  ALT_USB_DEV_DOEPTSIZ3_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPDMA3 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DOEPDMA3_ADDR  ALT_USB_DEV_DOEPDMA3_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPDMAB3 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DOEPDMAB3_ADDR  ALT_USB_DEV_DOEPDMAB3_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPCTL4 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DOEPCTL4_ADDR  ALT_USB_DEV_DOEPCTL4_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPINT4 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DOEPINT4_ADDR  ALT_USB_DEV_DOEPINT4_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPTSIZ4 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DOEPTSIZ4_ADDR  ALT_USB_DEV_DOEPTSIZ4_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPDMA4 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DOEPDMA4_ADDR  ALT_USB_DEV_DOEPDMA4_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPDMAB4 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DOEPDMAB4_ADDR  ALT_USB_DEV_DOEPDMAB4_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPCTL5 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DOEPCTL5_ADDR  ALT_USB_DEV_DOEPCTL5_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPINT5 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DOEPINT5_ADDR  ALT_USB_DEV_DOEPINT5_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPTSIZ5 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DOEPTSIZ5_ADDR  ALT_USB_DEV_DOEPTSIZ5_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPDMA5 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DOEPDMA5_ADDR  ALT_USB_DEV_DOEPDMA5_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPDMAB5 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DOEPDMAB5_ADDR  ALT_USB_DEV_DOEPDMAB5_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPCTL6 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DOEPCTL6_ADDR  ALT_USB_DEV_DOEPCTL6_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPINT6 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DOEPINT6_ADDR  ALT_USB_DEV_DOEPINT6_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPTSIZ6 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DOEPTSIZ6_ADDR  ALT_USB_DEV_DOEPTSIZ6_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPDMA6 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DOEPDMA6_ADDR  ALT_USB_DEV_DOEPDMA6_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPDMAB6 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DOEPDMAB6_ADDR  ALT_USB_DEV_DOEPDMAB6_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPCTL7 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DOEPCTL7_ADDR  ALT_USB_DEV_DOEPCTL7_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPINT7 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DOEPINT7_ADDR  ALT_USB_DEV_DOEPINT7_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPTSIZ7 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DOEPTSIZ7_ADDR  ALT_USB_DEV_DOEPTSIZ7_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPDMA7 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DOEPDMA7_ADDR  ALT_USB_DEV_DOEPDMA7_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPDMAB7 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DOEPDMAB7_ADDR  ALT_USB_DEV_DOEPDMAB7_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPCTL8 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DOEPCTL8_ADDR  ALT_USB_DEV_DOEPCTL8_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPINT8 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DOEPINT8_ADDR  ALT_USB_DEV_DOEPINT8_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPTSIZ8 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DOEPTSIZ8_ADDR  ALT_USB_DEV_DOEPTSIZ8_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPDMA8 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DOEPDMA8_ADDR  ALT_USB_DEV_DOEPDMA8_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPDMAB8 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DOEPDMAB8_ADDR  ALT_USB_DEV_DOEPDMAB8_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPCTL9 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DOEPCTL9_ADDR  ALT_USB_DEV_DOEPCTL9_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPINT9 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DOEPINT9_ADDR  ALT_USB_DEV_DOEPINT9_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPTSIZ9 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DOEPTSIZ9_ADDR  ALT_USB_DEV_DOEPTSIZ9_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPDMA9 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DOEPDMA9_ADDR  ALT_USB_DEV_DOEPDMA9_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPDMAB9 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DOEPDMAB9_ADDR  ALT_USB_DEV_DOEPDMAB9_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPCTL10 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DOEPCTL10_ADDR  ALT_USB_DEV_DOEPCTL10_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPINT10 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DOEPINT10_ADDR  ALT_USB_DEV_DOEPINT10_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPTSIZ10 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DOEPTSIZ10_ADDR  ALT_USB_DEV_DOEPTSIZ10_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPDMA10 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DOEPDMA10_ADDR  ALT_USB_DEV_DOEPDMA10_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPDMAB10 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DOEPDMAB10_ADDR  ALT_USB_DEV_DOEPDMAB10_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPCTL11 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DOEPCTL11_ADDR  ALT_USB_DEV_DOEPCTL11_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPINT11 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DOEPINT11_ADDR  ALT_USB_DEV_DOEPINT11_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPTSIZ11 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DOEPTSIZ11_ADDR  ALT_USB_DEV_DOEPTSIZ11_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPDMA11 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DOEPDMA11_ADDR  ALT_USB_DEV_DOEPDMA11_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPDMAB11 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DOEPDMAB11_ADDR  ALT_USB_DEV_DOEPDMAB11_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPCTL12 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DOEPCTL12_ADDR  ALT_USB_DEV_DOEPCTL12_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPINT12 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DOEPINT12_ADDR  ALT_USB_DEV_DOEPINT12_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPTSIZ12 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DOEPTSIZ12_ADDR  ALT_USB_DEV_DOEPTSIZ12_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPDMA12 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DOEPDMA12_ADDR  ALT_USB_DEV_DOEPDMA12_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPDMAB12 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DOEPDMAB12_ADDR  ALT_USB_DEV_DOEPDMAB12_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPCTL13 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DOEPCTL13_ADDR  ALT_USB_DEV_DOEPCTL13_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPINT13 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DOEPINT13_ADDR  ALT_USB_DEV_DOEPINT13_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPTSIZ13 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DOEPTSIZ13_ADDR  ALT_USB_DEV_DOEPTSIZ13_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPDMA13 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DOEPDMA13_ADDR  ALT_USB_DEV_DOEPDMA13_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPDMAB13 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DOEPDMAB13_ADDR  ALT_USB_DEV_DOEPDMAB13_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPCTL14 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DOEPCTL14_ADDR  ALT_USB_DEV_DOEPCTL14_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPINT14 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DOEPINT14_ADDR  ALT_USB_DEV_DOEPINT14_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPTSIZ14 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DOEPTSIZ14_ADDR  ALT_USB_DEV_DOEPTSIZ14_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPDMA14 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DOEPDMA14_ADDR  ALT_USB_DEV_DOEPDMA14_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPDMAB14 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DOEPDMAB14_ADDR  ALT_USB_DEV_DOEPDMAB14_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPCTL15 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DOEPCTL15_ADDR  ALT_USB_DEV_DOEPCTL15_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPINT15 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DOEPINT15_ADDR  ALT_USB_DEV_DOEPINT15_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPTSIZ15 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DOEPTSIZ15_ADDR  ALT_USB_DEV_DOEPTSIZ15_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPDMA15 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DOEPDMA15_ADDR  ALT_USB_DEV_DOEPDMA15_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The address of the ALT_USB_DEV_DOEPDMAB15 register for the ALT_USB1_DEVGRP instance. */
#define ALT_USB1_DEV_DOEPDMAB15_ADDR  ALT_USB_DEV_DOEPDMAB15_ADDR(ALT_USB1_DEVGRP_ADDR)
/* The base address byte offset for the start of the ALT_USB1_DEVGRP component. */
#define ALT_USB1_DEVGRP_OFST        0xffb40800
/* The start address of the ALT_USB1_DEVGRP component. */
#define ALT_USB1_DEVGRP_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_USB1_DEVGRP_OFST))
/* The lower bound address range of the ALT_USB1_DEVGRP component. */
#define ALT_USB1_DEVGRP_LB_ADDR     ALT_USB1_DEVGRP_ADDR
/* The upper bound address range of the ALT_USB1_DEVGRP component. */
#define ALT_USB1_DEVGRP_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_USB1_DEVGRP_ADDR) + 0x500) - 1))


/*
 * Component Instance : i_usbotg_1_pwrclkgrp
 * 
 * Instance i_usbotg_1_pwrclkgrp of component ALT_USB_PWRCLK.
 * 
 * 
 */
/* The address of the ALT_USB_PWRCLK_PCGCCTL register for the ALT_USB1_PWRCLKGRP instance. */
#define ALT_USB1_PWRCLK_PCGCCTL_ADDR  ALT_USB_PWRCLK_PCGCCTL_ADDR(ALT_USB1_PWRCLKGRP_ADDR)
/* The base address byte offset for the start of the ALT_USB1_PWRCLKGRP component. */
#define ALT_USB1_PWRCLKGRP_OFST        0xffb40e00
/* The start address of the ALT_USB1_PWRCLKGRP component. */
#define ALT_USB1_PWRCLKGRP_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_USB1_PWRCLKGRP_OFST))
/* The lower bound address range of the ALT_USB1_PWRCLKGRP component. */
#define ALT_USB1_PWRCLKGRP_LB_ADDR     ALT_USB1_PWRCLKGRP_ADDR
/* The upper bound address range of the ALT_USB1_PWRCLKGRP component. */
#define ALT_USB1_PWRCLKGRP_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_USB1_PWRCLKGRP_ADDR) + 0x4) - 1))


/*
 * Component Instance : i_usbotg_1_DWC_otg_DFIFO_0
 * 
 * Instance i_usbotg_1_DWC_otg_DFIFO_0 of component ALT_USB1_DWC_OTG_DFIFO_0.
 * 
 * 
 */
/* The base address byte offset for the start of the ALT_USB1_DWC_OTG_DFIFO_0 component. */
#define ALT_USB1_DWC_OTG_DFIFO_0_OFST        0xffb41000
/* The start address of the ALT_USB1_DWC_OTG_DFIFO_0 component. */
#define ALT_USB1_DWC_OTG_DFIFO_0_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_USB1_DWC_OTG_DFIFO_0_OFST))
/* The lower bound address range of the ALT_USB1_DWC_OTG_DFIFO_0 component. */
#define ALT_USB1_DWC_OTG_DFIFO_0_LB_ADDR     ALT_USB1_DWC_OTG_DFIFO_0_ADDR
/* The upper bound address range of the ALT_USB1_DWC_OTG_DFIFO_0 component. */
#define ALT_USB1_DWC_OTG_DFIFO_0_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_USB1_DWC_OTG_DFIFO_0_ADDR) + 0x1000) - 1))


/*
 * Component Instance : i_usbotg_1_DWC_otg_DFIFO_1
 * 
 * Instance i_usbotg_1_DWC_otg_DFIFO_1 of component ALT_USB1_DWC_OTG_DFIFO_1.
 * 
 * 
 */
/* The base address byte offset for the start of the ALT_USB1_DWC_OTG_DFIFO_1 component. */
#define ALT_USB1_DWC_OTG_DFIFO_1_OFST        0xffb42000
/* The start address of the ALT_USB1_DWC_OTG_DFIFO_1 component. */
#define ALT_USB1_DWC_OTG_DFIFO_1_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_USB1_DWC_OTG_DFIFO_1_OFST))
/* The lower bound address range of the ALT_USB1_DWC_OTG_DFIFO_1 component. */
#define ALT_USB1_DWC_OTG_DFIFO_1_LB_ADDR     ALT_USB1_DWC_OTG_DFIFO_1_ADDR
/* The upper bound address range of the ALT_USB1_DWC_OTG_DFIFO_1 component. */
#define ALT_USB1_DWC_OTG_DFIFO_1_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_USB1_DWC_OTG_DFIFO_1_ADDR) + 0x1000) - 1))


/*
 * Component Instance : i_usbotg_1_DWC_otg_DFIFO_2
 * 
 * Instance i_usbotg_1_DWC_otg_DFIFO_2 of component ALT_USB1_DWC_OTG_DFIFO_2.
 * 
 * 
 */
/* The base address byte offset for the start of the ALT_USB1_DWC_OTG_DFIFO_2 component. */
#define ALT_USB1_DWC_OTG_DFIFO_2_OFST        0xffb43000
/* The start address of the ALT_USB1_DWC_OTG_DFIFO_2 component. */
#define ALT_USB1_DWC_OTG_DFIFO_2_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_USB1_DWC_OTG_DFIFO_2_OFST))
/* The lower bound address range of the ALT_USB1_DWC_OTG_DFIFO_2 component. */
#define ALT_USB1_DWC_OTG_DFIFO_2_LB_ADDR     ALT_USB1_DWC_OTG_DFIFO_2_ADDR
/* The upper bound address range of the ALT_USB1_DWC_OTG_DFIFO_2 component. */
#define ALT_USB1_DWC_OTG_DFIFO_2_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_USB1_DWC_OTG_DFIFO_2_ADDR) + 0x1000) - 1))


/*
 * Component Instance : i_usbotg_1_DWC_otg_DFIFO_3
 * 
 * Instance i_usbotg_1_DWC_otg_DFIFO_3 of component ALT_USB1_DWC_OTG_DFIFO_3.
 * 
 * 
 */
/* The base address byte offset for the start of the ALT_USB1_DWC_OTG_DFIFO_3 component. */
#define ALT_USB1_DWC_OTG_DFIFO_3_OFST        0xffb44000
/* The start address of the ALT_USB1_DWC_OTG_DFIFO_3 component. */
#define ALT_USB1_DWC_OTG_DFIFO_3_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_USB1_DWC_OTG_DFIFO_3_OFST))
/* The lower bound address range of the ALT_USB1_DWC_OTG_DFIFO_3 component. */
#define ALT_USB1_DWC_OTG_DFIFO_3_LB_ADDR     ALT_USB1_DWC_OTG_DFIFO_3_ADDR
/* The upper bound address range of the ALT_USB1_DWC_OTG_DFIFO_3 component. */
#define ALT_USB1_DWC_OTG_DFIFO_3_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_USB1_DWC_OTG_DFIFO_3_ADDR) + 0x1000) - 1))


/*
 * Component Instance : i_usbotg_1_DWC_otg_DFIFO_4
 * 
 * Instance i_usbotg_1_DWC_otg_DFIFO_4 of component ALT_USB1_DWC_OTG_DFIFO_4.
 * 
 * 
 */
/* The base address byte offset for the start of the ALT_USB1_DWC_OTG_DFIFO_4 component. */
#define ALT_USB1_DWC_OTG_DFIFO_4_OFST        0xffb45000
/* The start address of the ALT_USB1_DWC_OTG_DFIFO_4 component. */
#define ALT_USB1_DWC_OTG_DFIFO_4_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_USB1_DWC_OTG_DFIFO_4_OFST))
/* The lower bound address range of the ALT_USB1_DWC_OTG_DFIFO_4 component. */
#define ALT_USB1_DWC_OTG_DFIFO_4_LB_ADDR     ALT_USB1_DWC_OTG_DFIFO_4_ADDR
/* The upper bound address range of the ALT_USB1_DWC_OTG_DFIFO_4 component. */
#define ALT_USB1_DWC_OTG_DFIFO_4_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_USB1_DWC_OTG_DFIFO_4_ADDR) + 0x1000) - 1))


/*
 * Component Instance : i_usbotg_1_DWC_otg_DFIFO_5
 * 
 * Instance i_usbotg_1_DWC_otg_DFIFO_5 of component ALT_USB1_DWC_OTG_DFIFO_5.
 * 
 * 
 */
/* The base address byte offset for the start of the ALT_USB1_DWC_OTG_DFIFO_5 component. */
#define ALT_USB1_DWC_OTG_DFIFO_5_OFST        0xffb46000
/* The start address of the ALT_USB1_DWC_OTG_DFIFO_5 component. */
#define ALT_USB1_DWC_OTG_DFIFO_5_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_USB1_DWC_OTG_DFIFO_5_OFST))
/* The lower bound address range of the ALT_USB1_DWC_OTG_DFIFO_5 component. */
#define ALT_USB1_DWC_OTG_DFIFO_5_LB_ADDR     ALT_USB1_DWC_OTG_DFIFO_5_ADDR
/* The upper bound address range of the ALT_USB1_DWC_OTG_DFIFO_5 component. */
#define ALT_USB1_DWC_OTG_DFIFO_5_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_USB1_DWC_OTG_DFIFO_5_ADDR) + 0x1000) - 1))


/*
 * Component Instance : i_usbotg_1_DWC_otg_DFIFO_6
 * 
 * Instance i_usbotg_1_DWC_otg_DFIFO_6 of component ALT_USB1_DWC_OTG_DFIFO_6.
 * 
 * 
 */
/* The base address byte offset for the start of the ALT_USB1_DWC_OTG_DFIFO_6 component. */
#define ALT_USB1_DWC_OTG_DFIFO_6_OFST        0xffb47000
/* The start address of the ALT_USB1_DWC_OTG_DFIFO_6 component. */
#define ALT_USB1_DWC_OTG_DFIFO_6_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_USB1_DWC_OTG_DFIFO_6_OFST))
/* The lower bound address range of the ALT_USB1_DWC_OTG_DFIFO_6 component. */
#define ALT_USB1_DWC_OTG_DFIFO_6_LB_ADDR     ALT_USB1_DWC_OTG_DFIFO_6_ADDR
/* The upper bound address range of the ALT_USB1_DWC_OTG_DFIFO_6 component. */
#define ALT_USB1_DWC_OTG_DFIFO_6_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_USB1_DWC_OTG_DFIFO_6_ADDR) + 0x1000) - 1))


/*
 * Component Instance : i_usbotg_1_DWC_otg_DFIFO_7
 * 
 * Instance i_usbotg_1_DWC_otg_DFIFO_7 of component ALT_USB1_DWC_OTG_DFIFO_7.
 * 
 * 
 */
/* The base address byte offset for the start of the ALT_USB1_DWC_OTG_DFIFO_7 component. */
#define ALT_USB1_DWC_OTG_DFIFO_7_OFST        0xffb48000
/* The start address of the ALT_USB1_DWC_OTG_DFIFO_7 component. */
#define ALT_USB1_DWC_OTG_DFIFO_7_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_USB1_DWC_OTG_DFIFO_7_OFST))
/* The lower bound address range of the ALT_USB1_DWC_OTG_DFIFO_7 component. */
#define ALT_USB1_DWC_OTG_DFIFO_7_LB_ADDR     ALT_USB1_DWC_OTG_DFIFO_7_ADDR
/* The upper bound address range of the ALT_USB1_DWC_OTG_DFIFO_7 component. */
#define ALT_USB1_DWC_OTG_DFIFO_7_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_USB1_DWC_OTG_DFIFO_7_ADDR) + 0x1000) - 1))


/*
 * Component Instance : i_usbotg_1_DWC_otg_DFIFO_8
 * 
 * Instance i_usbotg_1_DWC_otg_DFIFO_8 of component ALT_USB1_DWC_OTG_DFIFO_8.
 * 
 * 
 */
/* The base address byte offset for the start of the ALT_USB1_DWC_OTG_DFIFO_8 component. */
#define ALT_USB1_DWC_OTG_DFIFO_8_OFST        0xffb49000
/* The start address of the ALT_USB1_DWC_OTG_DFIFO_8 component. */
#define ALT_USB1_DWC_OTG_DFIFO_8_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_USB1_DWC_OTG_DFIFO_8_OFST))
/* The lower bound address range of the ALT_USB1_DWC_OTG_DFIFO_8 component. */
#define ALT_USB1_DWC_OTG_DFIFO_8_LB_ADDR     ALT_USB1_DWC_OTG_DFIFO_8_ADDR
/* The upper bound address range of the ALT_USB1_DWC_OTG_DFIFO_8 component. */
#define ALT_USB1_DWC_OTG_DFIFO_8_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_USB1_DWC_OTG_DFIFO_8_ADDR) + 0x1000) - 1))


/*
 * Component Instance : i_usbotg_1_DWC_otg_DFIFO_9
 * 
 * Instance i_usbotg_1_DWC_otg_DFIFO_9 of component ALT_USB1_DWC_OTG_DFIFO_9.
 * 
 * 
 */
/* The base address byte offset for the start of the ALT_USB1_DWC_OTG_DFIFO_9 component. */
#define ALT_USB1_DWC_OTG_DFIFO_9_OFST        0xffb4a000
/* The start address of the ALT_USB1_DWC_OTG_DFIFO_9 component. */
#define ALT_USB1_DWC_OTG_DFIFO_9_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_USB1_DWC_OTG_DFIFO_9_OFST))
/* The lower bound address range of the ALT_USB1_DWC_OTG_DFIFO_9 component. */
#define ALT_USB1_DWC_OTG_DFIFO_9_LB_ADDR     ALT_USB1_DWC_OTG_DFIFO_9_ADDR
/* The upper bound address range of the ALT_USB1_DWC_OTG_DFIFO_9 component. */
#define ALT_USB1_DWC_OTG_DFIFO_9_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_USB1_DWC_OTG_DFIFO_9_ADDR) + 0x1000) - 1))


/*
 * Component Instance : i_usbotg_1_DWC_otg_DFIFO_10
 * 
 * Instance i_usbotg_1_DWC_otg_DFIFO_10 of component ALT_USB1_DWC_OTG_DFIFO_10.
 * 
 * 
 */
/* The base address byte offset for the start of the ALT_USB1_DWC_OTG_DFIFO_10 component. */
#define ALT_USB1_DWC_OTG_DFIFO_10_OFST        0xffb4b000
/* The start address of the ALT_USB1_DWC_OTG_DFIFO_10 component. */
#define ALT_USB1_DWC_OTG_DFIFO_10_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_USB1_DWC_OTG_DFIFO_10_OFST))
/* The lower bound address range of the ALT_USB1_DWC_OTG_DFIFO_10 component. */
#define ALT_USB1_DWC_OTG_DFIFO_10_LB_ADDR     ALT_USB1_DWC_OTG_DFIFO_10_ADDR
/* The upper bound address range of the ALT_USB1_DWC_OTG_DFIFO_10 component. */
#define ALT_USB1_DWC_OTG_DFIFO_10_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_USB1_DWC_OTG_DFIFO_10_ADDR) + 0x1000) - 1))


/*
 * Component Instance : i_usbotg_1_DWC_otg_DFIFO_11
 * 
 * Instance i_usbotg_1_DWC_otg_DFIFO_11 of component ALT_USB1_DWC_OTG_DFIFO_11.
 * 
 * 
 */
/* The base address byte offset for the start of the ALT_USB1_DWC_OTG_DFIFO_11 component. */
#define ALT_USB1_DWC_OTG_DFIFO_11_OFST        0xffb4c000
/* The start address of the ALT_USB1_DWC_OTG_DFIFO_11 component. */
#define ALT_USB1_DWC_OTG_DFIFO_11_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_USB1_DWC_OTG_DFIFO_11_OFST))
/* The lower bound address range of the ALT_USB1_DWC_OTG_DFIFO_11 component. */
#define ALT_USB1_DWC_OTG_DFIFO_11_LB_ADDR     ALT_USB1_DWC_OTG_DFIFO_11_ADDR
/* The upper bound address range of the ALT_USB1_DWC_OTG_DFIFO_11 component. */
#define ALT_USB1_DWC_OTG_DFIFO_11_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_USB1_DWC_OTG_DFIFO_11_ADDR) + 0x1000) - 1))


/*
 * Component Instance : i_usbotg_1_DWC_otg_DFIFO_12
 * 
 * Instance i_usbotg_1_DWC_otg_DFIFO_12 of component ALT_USB1_DWC_OTG_DFIFO_12.
 * 
 * 
 */
/* The base address byte offset for the start of the ALT_USB1_DWC_OTG_DFIFO_12 component. */
#define ALT_USB1_DWC_OTG_DFIFO_12_OFST        0xffb4d000
/* The start address of the ALT_USB1_DWC_OTG_DFIFO_12 component. */
#define ALT_USB1_DWC_OTG_DFIFO_12_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_USB1_DWC_OTG_DFIFO_12_OFST))
/* The lower bound address range of the ALT_USB1_DWC_OTG_DFIFO_12 component. */
#define ALT_USB1_DWC_OTG_DFIFO_12_LB_ADDR     ALT_USB1_DWC_OTG_DFIFO_12_ADDR
/* The upper bound address range of the ALT_USB1_DWC_OTG_DFIFO_12 component. */
#define ALT_USB1_DWC_OTG_DFIFO_12_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_USB1_DWC_OTG_DFIFO_12_ADDR) + 0x1000) - 1))


/*
 * Component Instance : i_usbotg_1_DWC_otg_DFIFO_13
 * 
 * Instance i_usbotg_1_DWC_otg_DFIFO_13 of component ALT_USB1_DWC_OTG_DFIFO_13.
 * 
 * 
 */
/* The base address byte offset for the start of the ALT_USB1_DWC_OTG_DFIFO_13 component. */
#define ALT_USB1_DWC_OTG_DFIFO_13_OFST        0xffb4e000
/* The start address of the ALT_USB1_DWC_OTG_DFIFO_13 component. */
#define ALT_USB1_DWC_OTG_DFIFO_13_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_USB1_DWC_OTG_DFIFO_13_OFST))
/* The lower bound address range of the ALT_USB1_DWC_OTG_DFIFO_13 component. */
#define ALT_USB1_DWC_OTG_DFIFO_13_LB_ADDR     ALT_USB1_DWC_OTG_DFIFO_13_ADDR
/* The upper bound address range of the ALT_USB1_DWC_OTG_DFIFO_13 component. */
#define ALT_USB1_DWC_OTG_DFIFO_13_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_USB1_DWC_OTG_DFIFO_13_ADDR) + 0x1000) - 1))


/*
 * Component Instance : i_usbotg_1_DWC_otg_DFIFO_14
 * 
 * Instance i_usbotg_1_DWC_otg_DFIFO_14 of component ALT_USB1_DWC_OTG_DFIFO_14.
 * 
 * 
 */
/* The base address byte offset for the start of the ALT_USB1_DWC_OTG_DFIFO_14 component. */
#define ALT_USB1_DWC_OTG_DFIFO_14_OFST        0xffb4f000
/* The start address of the ALT_USB1_DWC_OTG_DFIFO_14 component. */
#define ALT_USB1_DWC_OTG_DFIFO_14_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_USB1_DWC_OTG_DFIFO_14_OFST))
/* The lower bound address range of the ALT_USB1_DWC_OTG_DFIFO_14 component. */
#define ALT_USB1_DWC_OTG_DFIFO_14_LB_ADDR     ALT_USB1_DWC_OTG_DFIFO_14_ADDR
/* The upper bound address range of the ALT_USB1_DWC_OTG_DFIFO_14 component. */
#define ALT_USB1_DWC_OTG_DFIFO_14_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_USB1_DWC_OTG_DFIFO_14_ADDR) + 0x1000) - 1))


/*
 * Component Instance : i_usbotg_1_DWC_otg_DFIFO_15
 * 
 * Instance i_usbotg_1_DWC_otg_DFIFO_15 of component ALT_USB1_DWC_OTG_DFIFO_15.
 * 
 * 
 */
/* The base address byte offset for the start of the ALT_USB1_DWC_OTG_DFIFO_15 component. */
#define ALT_USB1_DWC_OTG_DFIFO_15_OFST        0xffb50000
/* The start address of the ALT_USB1_DWC_OTG_DFIFO_15 component. */
#define ALT_USB1_DWC_OTG_DFIFO_15_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_USB1_DWC_OTG_DFIFO_15_OFST))
/* The lower bound address range of the ALT_USB1_DWC_OTG_DFIFO_15 component. */
#define ALT_USB1_DWC_OTG_DFIFO_15_LB_ADDR     ALT_USB1_DWC_OTG_DFIFO_15_ADDR
/* The upper bound address range of the ALT_USB1_DWC_OTG_DFIFO_15 component. */
#define ALT_USB1_DWC_OTG_DFIFO_15_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_USB1_DWC_OTG_DFIFO_15_ADDR) + 0x1000) - 1))


/*
 * Component Instance : i_usbotg_1_DWC_otg_DFIFO_Direct_access
 * 
 * Instance i_usbotg_1_DWC_otg_DFIFO_Direct_access of component ALT_USB1_DWC_OTG_DFIFO_DIRECT_ACCESS.
 * 
 * 
 */
/* The base address byte offset for the start of the ALT_USB1_DWC_OTG_DFIFO_DIRECT_ACCESS component. */
#define ALT_USB1_DWC_OTG_DFIFO_DIRECT_ACCESS_OFST        0xffb60000
/* The start address of the ALT_USB1_DWC_OTG_DFIFO_DIRECT_ACCESS component. */
#define ALT_USB1_DWC_OTG_DFIFO_DIRECT_ACCESS_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_USB1_DWC_OTG_DFIFO_DIRECT_ACCESS_OFST))
/* The lower bound address range of the ALT_USB1_DWC_OTG_DFIFO_DIRECT_ACCESS component. */
#define ALT_USB1_DWC_OTG_DFIFO_DIRECT_ACCESS_LB_ADDR     ALT_USB1_DWC_OTG_DFIFO_DIRECT_ACCESS_ADDR
/* The upper bound address range of the ALT_USB1_DWC_OTG_DFIFO_DIRECT_ACCESS component. */
#define ALT_USB1_DWC_OTG_DFIFO_DIRECT_ACCESS_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_USB1_DWC_OTG_DFIFO_DIRECT_ACCESS_ADDR) + 0x20000) - 1))


/*
 * Component Instance : i_nand_config
 * 
 * Instance i_nand_config of component ALT_NAND_CFG.
 * 
 * 
 */
/* The address of the ALT_NAND_CFG_DEVICE_RST register for the ALT_NAND_CFG instance. */
#define ALT_NAND_CFG_DEVICE_RST_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_CFG_ADDR) + ALT_NAND_CFG_DEVICE_RST_OFST))
/* The address of the ALT_NAND_CFG_TFR_SPARE_REG register for the ALT_NAND_CFG instance. */
#define ALT_NAND_CFG_TFR_SPARE_REG_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_CFG_ADDR) + ALT_NAND_CFG_TFR_SPARE_REG_OFST))
/* The address of the ALT_NAND_CFG_LD_WAIT_CNT register for the ALT_NAND_CFG instance. */
#define ALT_NAND_CFG_LD_WAIT_CNT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_CFG_ADDR) + ALT_NAND_CFG_LD_WAIT_CNT_OFST))
/* The address of the ALT_NAND_CFG_PROGRAM_WAIT_CNT register for the ALT_NAND_CFG instance. */
#define ALT_NAND_CFG_PROGRAM_WAIT_CNT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_CFG_ADDR) + ALT_NAND_CFG_PROGRAM_WAIT_CNT_OFST))
/* The address of the ALT_NAND_CFG_ERASE_WAIT_CNT register for the ALT_NAND_CFG instance. */
#define ALT_NAND_CFG_ERASE_WAIT_CNT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_CFG_ADDR) + ALT_NAND_CFG_ERASE_WAIT_CNT_OFST))
/* The address of the ALT_NAND_CFG_INT_MON_CYCCNT register for the ALT_NAND_CFG instance. */
#define ALT_NAND_CFG_INT_MON_CYCCNT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_CFG_ADDR) + ALT_NAND_CFG_INT_MON_CYCCNT_OFST))
/* The address of the ALT_NAND_CFG_RB_PIN_END register for the ALT_NAND_CFG instance. */
#define ALT_NAND_CFG_RB_PIN_END_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_CFG_ADDR) + ALT_NAND_CFG_RB_PIN_END_OFST))
/* The address of the ALT_NAND_CFG_MULTIPLANE_OP register for the ALT_NAND_CFG instance. */
#define ALT_NAND_CFG_MULTIPLANE_OP_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_CFG_ADDR) + ALT_NAND_CFG_MULTIPLANE_OP_OFST))
/* The address of the ALT_NAND_CFG_MULTIPLANE_RD_EN register for the ALT_NAND_CFG instance. */
#define ALT_NAND_CFG_MULTIPLANE_RD_EN_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_CFG_ADDR) + ALT_NAND_CFG_MULTIPLANE_RD_EN_OFST))
/* The address of the ALT_NAND_CFG_COPYBACK_DIS register for the ALT_NAND_CFG instance. */
#define ALT_NAND_CFG_COPYBACK_DIS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_CFG_ADDR) + ALT_NAND_CFG_COPYBACK_DIS_OFST))
/* The address of the ALT_NAND_CFG_CACHE_WR_EN register for the ALT_NAND_CFG instance. */
#define ALT_NAND_CFG_CACHE_WR_EN_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_CFG_ADDR) + ALT_NAND_CFG_CACHE_WR_EN_OFST))
/* The address of the ALT_NAND_CFG_CACHE_RD_EN register for the ALT_NAND_CFG instance. */
#define ALT_NAND_CFG_CACHE_RD_EN_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_CFG_ADDR) + ALT_NAND_CFG_CACHE_RD_EN_OFST))
/* The address of the ALT_NAND_CFG_PREFETCH_MOD register for the ALT_NAND_CFG instance. */
#define ALT_NAND_CFG_PREFETCH_MOD_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_CFG_ADDR) + ALT_NAND_CFG_PREFETCH_MOD_OFST))
/* The address of the ALT_NAND_CFG_CHIP_EN_DONT_CARE register for the ALT_NAND_CFG instance. */
#define ALT_NAND_CFG_CHIP_EN_DONT_CARE_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_CFG_ADDR) + ALT_NAND_CFG_CHIP_EN_DONT_CARE_OFST))
/* The address of the ALT_NAND_CFG_ECC_EN register for the ALT_NAND_CFG instance. */
#define ALT_NAND_CFG_ECC_EN_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_CFG_ADDR) + ALT_NAND_CFG_ECC_EN_OFST))
/* The address of the ALT_NAND_CFG_GLOB_INT_EN register for the ALT_NAND_CFG instance. */
#define ALT_NAND_CFG_GLOB_INT_EN_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_CFG_ADDR) + ALT_NAND_CFG_GLOB_INT_EN_OFST))
/* The address of the ALT_NAND_CFG_TWHR2_AND_WE_2_RE register for the ALT_NAND_CFG instance. */
#define ALT_NAND_CFG_TWHR2_AND_WE_2_RE_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_CFG_ADDR) + ALT_NAND_CFG_TWHR2_AND_WE_2_RE_OFST))
/* The address of the ALT_NAND_CFG_TCWAW_AND_ADDR_2_DATA register for the ALT_NAND_CFG instance. */
#define ALT_NAND_CFG_TCWAW_AND_ADDR_2_DATA_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_CFG_ADDR) + ALT_NAND_CFG_TCWAW_AND_ADDR_2_DATA_OFST))
/* The address of the ALT_NAND_CFG_RE_2_WE register for the ALT_NAND_CFG instance. */
#define ALT_NAND_CFG_RE_2_WE_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_CFG_ADDR) + ALT_NAND_CFG_RE_2_WE_OFST))
/* The address of the ALT_NAND_CFG_ACC_CLKS register for the ALT_NAND_CFG instance. */
#define ALT_NAND_CFG_ACC_CLKS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_CFG_ADDR) + ALT_NAND_CFG_ACC_CLKS_OFST))
/* The address of the ALT_NAND_CFG_NUMBER_OF_PLANES register for the ALT_NAND_CFG instance. */
#define ALT_NAND_CFG_NUMBER_OF_PLANES_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_CFG_ADDR) + ALT_NAND_CFG_NUMBER_OF_PLANES_OFST))
/* The address of the ALT_NAND_CFG_PAGES_PER_BLOCK register for the ALT_NAND_CFG instance. */
#define ALT_NAND_CFG_PAGES_PER_BLOCK_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_CFG_ADDR) + ALT_NAND_CFG_PAGES_PER_BLOCK_OFST))
/* The address of the ALT_NAND_CFG_DEVICE_WIDTH register for the ALT_NAND_CFG instance. */
#define ALT_NAND_CFG_DEVICE_WIDTH_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_CFG_ADDR) + ALT_NAND_CFG_DEVICE_WIDTH_OFST))
/* The address of the ALT_NAND_CFG_DEVICE_MAIN_AREA_SIZE register for the ALT_NAND_CFG instance. */
#define ALT_NAND_CFG_DEVICE_MAIN_AREA_SIZE_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_CFG_ADDR) + ALT_NAND_CFG_DEVICE_MAIN_AREA_SIZE_OFST))
/* The address of the ALT_NAND_CFG_DEVICE_SPARE_AREA_SIZE register for the ALT_NAND_CFG instance. */
#define ALT_NAND_CFG_DEVICE_SPARE_AREA_SIZE_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_CFG_ADDR) + ALT_NAND_CFG_DEVICE_SPARE_AREA_SIZE_OFST))
/* The address of the ALT_NAND_CFG_TWO_ROW_ADDR_CYCLES register for the ALT_NAND_CFG instance. */
#define ALT_NAND_CFG_TWO_ROW_ADDR_CYCLES_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_CFG_ADDR) + ALT_NAND_CFG_TWO_ROW_ADDR_CYCLES_OFST))
/* The address of the ALT_NAND_CFG_MULTIPLANE_ADDR_RESTRICT register for the ALT_NAND_CFG instance. */
#define ALT_NAND_CFG_MULTIPLANE_ADDR_RESTRICT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_CFG_ADDR) + ALT_NAND_CFG_MULTIPLANE_ADDR_RESTRICT_OFST))
/* The address of the ALT_NAND_CFG_ECC_CORRECTION register for the ALT_NAND_CFG instance. */
#define ALT_NAND_CFG_ECC_CORRECTION_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_CFG_ADDR) + ALT_NAND_CFG_ECC_CORRECTION_OFST))
/* The address of the ALT_NAND_CFG_RD_MOD register for the ALT_NAND_CFG instance. */
#define ALT_NAND_CFG_RD_MOD_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_CFG_ADDR) + ALT_NAND_CFG_RD_MOD_OFST))
/* The address of the ALT_NAND_CFG_WR_MOD register for the ALT_NAND_CFG instance. */
#define ALT_NAND_CFG_WR_MOD_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_CFG_ADDR) + ALT_NAND_CFG_WR_MOD_OFST))
/* The address of the ALT_NAND_CFG_COPYBACK_MOD register for the ALT_NAND_CFG instance. */
#define ALT_NAND_CFG_COPYBACK_MOD_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_CFG_ADDR) + ALT_NAND_CFG_COPYBACK_MOD_OFST))
/* The address of the ALT_NAND_CFG_RDWR_EN_LO_CNT register for the ALT_NAND_CFG instance. */
#define ALT_NAND_CFG_RDWR_EN_LO_CNT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_CFG_ADDR) + ALT_NAND_CFG_RDWR_EN_LO_CNT_OFST))
/* The address of the ALT_NAND_CFG_RDWR_EN_HI_CNT register for the ALT_NAND_CFG instance. */
#define ALT_NAND_CFG_RDWR_EN_HI_CNT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_CFG_ADDR) + ALT_NAND_CFG_RDWR_EN_HI_CNT_OFST))
/* The address of the ALT_NAND_CFG_MAX_RD_DELAY register for the ALT_NAND_CFG instance. */
#define ALT_NAND_CFG_MAX_RD_DELAY_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_CFG_ADDR) + ALT_NAND_CFG_MAX_RD_DELAY_OFST))
/* The address of the ALT_NAND_CFG_CS_SETUP_CNT register for the ALT_NAND_CFG instance. */
#define ALT_NAND_CFG_CS_SETUP_CNT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_CFG_ADDR) + ALT_NAND_CFG_CS_SETUP_CNT_OFST))
/* The address of the ALT_NAND_CFG_SPARE_AREA_SKIP_BYTES register for the ALT_NAND_CFG instance. */
#define ALT_NAND_CFG_SPARE_AREA_SKIP_BYTES_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_CFG_ADDR) + ALT_NAND_CFG_SPARE_AREA_SKIP_BYTES_OFST))
/* The address of the ALT_NAND_CFG_SPARE_AREA_MARKER register for the ALT_NAND_CFG instance. */
#define ALT_NAND_CFG_SPARE_AREA_MARKER_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_CFG_ADDR) + ALT_NAND_CFG_SPARE_AREA_MARKER_OFST))
/* The address of the ALT_NAND_CFG_DEVICES_CONNECTED register for the ALT_NAND_CFG instance. */
#define ALT_NAND_CFG_DEVICES_CONNECTED_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_CFG_ADDR) + ALT_NAND_CFG_DEVICES_CONNECTED_OFST))
/* The address of the ALT_NAND_CFG_DIE_MSK register for the ALT_NAND_CFG instance. */
#define ALT_NAND_CFG_DIE_MSK_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_CFG_ADDR) + ALT_NAND_CFG_DIE_MSK_OFST))
/* The address of the ALT_NAND_CFG_FIRST_BLOCK_OF_NEXT_PLANE register for the ALT_NAND_CFG instance. */
#define ALT_NAND_CFG_FIRST_BLOCK_OF_NEXT_PLANE_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_CFG_ADDR) + ALT_NAND_CFG_FIRST_BLOCK_OF_NEXT_PLANE_OFST))
/* The address of the ALT_NAND_CFG_WR_PROTECT register for the ALT_NAND_CFG instance. */
#define ALT_NAND_CFG_WR_PROTECT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_CFG_ADDR) + ALT_NAND_CFG_WR_PROTECT_OFST))
/* The address of the ALT_NAND_CFG_RE_2_RE register for the ALT_NAND_CFG instance. */
#define ALT_NAND_CFG_RE_2_RE_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_CFG_ADDR) + ALT_NAND_CFG_RE_2_RE_OFST))
/* The address of the ALT_NAND_CFG_POR_RST_COUNT register for the ALT_NAND_CFG instance. */
#define ALT_NAND_CFG_POR_RST_COUNT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_CFG_ADDR) + ALT_NAND_CFG_POR_RST_COUNT_OFST))
/* The address of the ALT_NAND_CFG_WD_RST_COUNT register for the ALT_NAND_CFG instance. */
#define ALT_NAND_CFG_WD_RST_COUNT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_CFG_ADDR) + ALT_NAND_CFG_WD_RST_COUNT_OFST))
/* The base address byte offset for the start of the ALT_NAND_CFG component. */
#define ALT_NAND_CFG_OFST        0xffb80000
/* The start address of the ALT_NAND_CFG component. */
#define ALT_NAND_CFG_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_NAND_CFG_OFST))
/* The lower bound address range of the ALT_NAND_CFG component. */
#define ALT_NAND_CFG_LB_ADDR     ALT_NAND_CFG_ADDR
/* The upper bound address range of the ALT_NAND_CFG component. */
#define ALT_NAND_CFG_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_NAND_CFG_ADDR) + 0x2b4) - 1))


/*
 * Component Instance : i_nand_param
 * 
 * Instance i_nand_param of component ALT_NAND_PARAM.
 * 
 * 
 */
/* The address of the ALT_NAND_PARAM_MANUFACTURER_ID register for the ALT_NAND_PARAM instance. */
#define ALT_NAND_PARAM_MANUFACTURER_ID_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_PARAM_ADDR) + ALT_NAND_PARAM_MANUFACTURER_ID_OFST))
/* The address of the ALT_NAND_PARAM_DEVICE_ID register for the ALT_NAND_PARAM instance. */
#define ALT_NAND_PARAM_DEVICE_ID_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_PARAM_ADDR) + ALT_NAND_PARAM_DEVICE_ID_OFST))
/* The address of the ALT_NAND_PARAM_DEVICE_PARAM_0 register for the ALT_NAND_PARAM instance. */
#define ALT_NAND_PARAM_DEVICE_PARAM_0_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_PARAM_ADDR) + ALT_NAND_PARAM_DEVICE_PARAM_0_OFST))
/* The address of the ALT_NAND_PARAM_DEVICE_PARAM_1 register for the ALT_NAND_PARAM instance. */
#define ALT_NAND_PARAM_DEVICE_PARAM_1_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_PARAM_ADDR) + ALT_NAND_PARAM_DEVICE_PARAM_1_OFST))
/* The address of the ALT_NAND_PARAM_DEVICE_PARAM_2 register for the ALT_NAND_PARAM instance. */
#define ALT_NAND_PARAM_DEVICE_PARAM_2_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_PARAM_ADDR) + ALT_NAND_PARAM_DEVICE_PARAM_2_OFST))
/* The address of the ALT_NAND_PARAM_LOGICAL_PAGE_DATA_SIZE register for the ALT_NAND_PARAM instance. */
#define ALT_NAND_PARAM_LOGICAL_PAGE_DATA_SIZE_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_PARAM_ADDR) + ALT_NAND_PARAM_LOGICAL_PAGE_DATA_SIZE_OFST))
/* The address of the ALT_NAND_PARAM_LOGICAL_PAGE_SPARE_SIZE register for the ALT_NAND_PARAM instance. */
#define ALT_NAND_PARAM_LOGICAL_PAGE_SPARE_SIZE_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_PARAM_ADDR) + ALT_NAND_PARAM_LOGICAL_PAGE_SPARE_SIZE_OFST))
/* The address of the ALT_NAND_PARAM_REVISION register for the ALT_NAND_PARAM instance. */
#define ALT_NAND_PARAM_REVISION_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_PARAM_ADDR) + ALT_NAND_PARAM_REVISION_OFST))
/* The address of the ALT_NAND_PARAM_ONFI_DEV_FEATURES register for the ALT_NAND_PARAM instance. */
#define ALT_NAND_PARAM_ONFI_DEV_FEATURES_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_PARAM_ADDR) + ALT_NAND_PARAM_ONFI_DEV_FEATURES_OFST))
/* The address of the ALT_NAND_PARAM_ONFI_OPTIONAL_CMDS register for the ALT_NAND_PARAM instance. */
#define ALT_NAND_PARAM_ONFI_OPTIONAL_CMDS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_PARAM_ADDR) + ALT_NAND_PARAM_ONFI_OPTIONAL_CMDS_OFST))
/* The address of the ALT_NAND_PARAM_ONFI_TIMING_MOD register for the ALT_NAND_PARAM instance. */
#define ALT_NAND_PARAM_ONFI_TIMING_MOD_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_PARAM_ADDR) + ALT_NAND_PARAM_ONFI_TIMING_MOD_OFST))
/* The address of the ALT_NAND_PARAM_ONFI_PGM_CACHE_TIMING_MOD register for the ALT_NAND_PARAM instance. */
#define ALT_NAND_PARAM_ONFI_PGM_CACHE_TIMING_MOD_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_PARAM_ADDR) + ALT_NAND_PARAM_ONFI_PGM_CACHE_TIMING_MOD_OFST))
/* The address of the ALT_NAND_PARAM_ONFI_DEV_NO_OF_LUNS register for the ALT_NAND_PARAM instance. */
#define ALT_NAND_PARAM_ONFI_DEV_NO_OF_LUNS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_PARAM_ADDR) + ALT_NAND_PARAM_ONFI_DEV_NO_OF_LUNS_OFST))
/* The address of the ALT_NAND_PARAM_ONFI_DEV_BLKS_PER_LUN_L register for the ALT_NAND_PARAM instance. */
#define ALT_NAND_PARAM_ONFI_DEV_BLKS_PER_LUN_L_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_PARAM_ADDR) + ALT_NAND_PARAM_ONFI_DEV_BLKS_PER_LUN_L_OFST))
/* The address of the ALT_NAND_PARAM_ONFI_DEV_BLKS_PER_LUN_U register for the ALT_NAND_PARAM instance. */
#define ALT_NAND_PARAM_ONFI_DEV_BLKS_PER_LUN_U_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_PARAM_ADDR) + ALT_NAND_PARAM_ONFI_DEV_BLKS_PER_LUN_U_OFST))
/* The address of the ALT_NAND_PARAM_FEATURES register for the ALT_NAND_PARAM instance. */
#define ALT_NAND_PARAM_FEATURES_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_PARAM_ADDR) + ALT_NAND_PARAM_FEATURES_OFST))
/* The base address byte offset for the start of the ALT_NAND_PARAM component. */
#define ALT_NAND_PARAM_OFST        0xffb80300
/* The start address of the ALT_NAND_PARAM component. */
#define ALT_NAND_PARAM_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_NAND_PARAM_OFST))
/* The lower bound address range of the ALT_NAND_PARAM component. */
#define ALT_NAND_PARAM_LB_ADDR     ALT_NAND_PARAM_ADDR
/* The upper bound address range of the ALT_NAND_PARAM component. */
#define ALT_NAND_PARAM_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_NAND_PARAM_ADDR) + 0xf4) - 1))


/*
 * Component Instance : i_nand_status
 * 
 * Instance i_nand_status of component ALT_NAND_STAT.
 * 
 * 
 */
/* The address of the ALT_NAND_STAT_TFR_MOD register for the ALT_NAND_STAT instance. */
#define ALT_NAND_STAT_TFR_MOD_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_STAT_ADDR) + ALT_NAND_STAT_TFR_MOD_OFST))
/* The address of the ALT_NAND_STAT_INTR_STAT0 register for the ALT_NAND_STAT instance. */
#define ALT_NAND_STAT_INTR_STAT0_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_STAT_ADDR) + ALT_NAND_STAT_INTR_STAT0_OFST))
/* The address of the ALT_NAND_STAT_INTR_EN0 register for the ALT_NAND_STAT instance. */
#define ALT_NAND_STAT_INTR_EN0_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_STAT_ADDR) + ALT_NAND_STAT_INTR_EN0_OFST))
/* The address of the ALT_NAND_STAT_PAGE_CNT0 register for the ALT_NAND_STAT instance. */
#define ALT_NAND_STAT_PAGE_CNT0_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_STAT_ADDR) + ALT_NAND_STAT_PAGE_CNT0_OFST))
/* The address of the ALT_NAND_STAT_ERR_PAGE_ADDR0 register for the ALT_NAND_STAT instance. */
#define ALT_NAND_STAT_ERR_PAGE_ADDR0_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_STAT_ADDR) + ALT_NAND_STAT_ERR_PAGE_ADDR0_OFST))
/* The address of the ALT_NAND_STAT_ERR_BLOCK_ADDR0 register for the ALT_NAND_STAT instance. */
#define ALT_NAND_STAT_ERR_BLOCK_ADDR0_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_STAT_ADDR) + ALT_NAND_STAT_ERR_BLOCK_ADDR0_OFST))
/* The address of the ALT_NAND_STAT_INTR_STAT1 register for the ALT_NAND_STAT instance. */
#define ALT_NAND_STAT_INTR_STAT1_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_STAT_ADDR) + ALT_NAND_STAT_INTR_STAT1_OFST))
/* The address of the ALT_NAND_STAT_INTR_EN1 register for the ALT_NAND_STAT instance. */
#define ALT_NAND_STAT_INTR_EN1_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_STAT_ADDR) + ALT_NAND_STAT_INTR_EN1_OFST))
/* The address of the ALT_NAND_STAT_PAGE_CNT1 register for the ALT_NAND_STAT instance. */
#define ALT_NAND_STAT_PAGE_CNT1_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_STAT_ADDR) + ALT_NAND_STAT_PAGE_CNT1_OFST))
/* The address of the ALT_NAND_STAT_ERR_PAGE_ADDR1 register for the ALT_NAND_STAT instance. */
#define ALT_NAND_STAT_ERR_PAGE_ADDR1_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_STAT_ADDR) + ALT_NAND_STAT_ERR_PAGE_ADDR1_OFST))
/* The address of the ALT_NAND_STAT_ERR_BLOCK_ADDR1 register for the ALT_NAND_STAT instance. */
#define ALT_NAND_STAT_ERR_BLOCK_ADDR1_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_STAT_ADDR) + ALT_NAND_STAT_ERR_BLOCK_ADDR1_OFST))
/* The address of the ALT_NAND_STAT_INTR_STAT2 register for the ALT_NAND_STAT instance. */
#define ALT_NAND_STAT_INTR_STAT2_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_STAT_ADDR) + ALT_NAND_STAT_INTR_STAT2_OFST))
/* The address of the ALT_NAND_STAT_INTR_EN2 register for the ALT_NAND_STAT instance. */
#define ALT_NAND_STAT_INTR_EN2_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_STAT_ADDR) + ALT_NAND_STAT_INTR_EN2_OFST))
/* The address of the ALT_NAND_STAT_PAGE_CNT2 register for the ALT_NAND_STAT instance. */
#define ALT_NAND_STAT_PAGE_CNT2_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_STAT_ADDR) + ALT_NAND_STAT_PAGE_CNT2_OFST))
/* The address of the ALT_NAND_STAT_ERR_PAGE_ADDR2 register for the ALT_NAND_STAT instance. */
#define ALT_NAND_STAT_ERR_PAGE_ADDR2_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_STAT_ADDR) + ALT_NAND_STAT_ERR_PAGE_ADDR2_OFST))
/* The address of the ALT_NAND_STAT_ERR_BLOCK_ADDR2 register for the ALT_NAND_STAT instance. */
#define ALT_NAND_STAT_ERR_BLOCK_ADDR2_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_STAT_ADDR) + ALT_NAND_STAT_ERR_BLOCK_ADDR2_OFST))
/* The address of the ALT_NAND_STAT_INTR_STAT3 register for the ALT_NAND_STAT instance. */
#define ALT_NAND_STAT_INTR_STAT3_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_STAT_ADDR) + ALT_NAND_STAT_INTR_STAT3_OFST))
/* The address of the ALT_NAND_STAT_INTR_EN3 register for the ALT_NAND_STAT instance. */
#define ALT_NAND_STAT_INTR_EN3_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_STAT_ADDR) + ALT_NAND_STAT_INTR_EN3_OFST))
/* The address of the ALT_NAND_STAT_PAGE_CNT3 register for the ALT_NAND_STAT instance. */
#define ALT_NAND_STAT_PAGE_CNT3_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_STAT_ADDR) + ALT_NAND_STAT_PAGE_CNT3_OFST))
/* The address of the ALT_NAND_STAT_ERR_PAGE_ADDR3 register for the ALT_NAND_STAT instance. */
#define ALT_NAND_STAT_ERR_PAGE_ADDR3_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_STAT_ADDR) + ALT_NAND_STAT_ERR_PAGE_ADDR3_OFST))
/* The address of the ALT_NAND_STAT_ERR_BLOCK_ADDR3 register for the ALT_NAND_STAT instance. */
#define ALT_NAND_STAT_ERR_BLOCK_ADDR3_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_STAT_ADDR) + ALT_NAND_STAT_ERR_BLOCK_ADDR3_OFST))
/* The base address byte offset for the start of the ALT_NAND_STAT component. */
#define ALT_NAND_STAT_OFST        0xffb80400
/* The start address of the ALT_NAND_STAT component. */
#define ALT_NAND_STAT_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_NAND_STAT_OFST))
/* The lower bound address range of the ALT_NAND_STAT component. */
#define ALT_NAND_STAT_LB_ADDR     ALT_NAND_STAT_ADDR
/* The upper bound address range of the ALT_NAND_STAT component. */
#define ALT_NAND_STAT_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_NAND_STAT_ADDR) + 0x144) - 1))


/*
 * Component Instance : i_nand_ecc
 * 
 * Instance i_nand_ecc of component ALT_NAND_ECC.
 * 
 * 
 */
/* The address of the ALT_NAND_ECC_ECCCORINFO_B01 register for the ALT_NAND_ECC instance. */
#define ALT_NAND_ECC_ECCCORINFO_B01_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_ECC_ADDR) + ALT_NAND_ECC_ECCCORINFO_B01_OFST))
/* The address of the ALT_NAND_ECC_ECCCORINFO_B23 register for the ALT_NAND_ECC instance. */
#define ALT_NAND_ECC_ECCCORINFO_B23_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_ECC_ADDR) + ALT_NAND_ECC_ECCCORINFO_B23_OFST))
/* The base address byte offset for the start of the ALT_NAND_ECC component. */
#define ALT_NAND_ECC_OFST        0xffb80650
/* The start address of the ALT_NAND_ECC component. */
#define ALT_NAND_ECC_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_NAND_ECC_OFST))
/* The lower bound address range of the ALT_NAND_ECC component. */
#define ALT_NAND_ECC_LB_ADDR     ALT_NAND_ECC_ADDR
/* The upper bound address range of the ALT_NAND_ECC component. */
#define ALT_NAND_ECC_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_NAND_ECC_ADDR) + 0x14) - 1))


/*
 * Component Instance : i_nand_dma
 * 
 * Instance i_nand_dma of component ALT_NAND_DMA.
 * 
 * 
 */
/* The address of the ALT_NAND_DMA_DMA_EN register for the ALT_NAND_DMA instance. */
#define ALT_NAND_DMA_DMA_EN_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_DMA_ADDR) + ALT_NAND_DMA_DMA_EN_OFST))
/* The address of the ALT_NAND_DMA_DMA_INTR register for the ALT_NAND_DMA instance. */
#define ALT_NAND_DMA_DMA_INTR_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_DMA_ADDR) + ALT_NAND_DMA_DMA_INTR_OFST))
/* The address of the ALT_NAND_DMA_DMA_INTR_EN register for the ALT_NAND_DMA instance. */
#define ALT_NAND_DMA_DMA_INTR_EN_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_DMA_ADDR) + ALT_NAND_DMA_DMA_INTR_EN_OFST))
/* The address of the ALT_NAND_DMA_TGT_ERR_ADDR_LO register for the ALT_NAND_DMA instance. */
#define ALT_NAND_DMA_TGT_ERR_ADDR_LO_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_DMA_ADDR) + ALT_NAND_DMA_TGT_ERR_ADDR_LO_OFST))
/* The address of the ALT_NAND_DMA_TGT_ERR_ADDR_HI register for the ALT_NAND_DMA instance. */
#define ALT_NAND_DMA_TGT_ERR_ADDR_HI_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_DMA_ADDR) + ALT_NAND_DMA_TGT_ERR_ADDR_HI_OFST))
/* The address of the ALT_NAND_DMA_CHNL_ACT register for the ALT_NAND_DMA instance. */
#define ALT_NAND_DMA_CHNL_ACT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_DMA_ADDR) + ALT_NAND_DMA_CHNL_ACT_OFST))
/* The address of the ALT_NAND_DMA_FLSH_BURST_LEN register for the ALT_NAND_DMA instance. */
#define ALT_NAND_DMA_FLSH_BURST_LEN_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_DMA_ADDR) + ALT_NAND_DMA_FLSH_BURST_LEN_OFST))
/* The address of the ALT_NAND_DMA_INTRLV register for the ALT_NAND_DMA instance. */
#define ALT_NAND_DMA_INTRLV_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_DMA_ADDR) + ALT_NAND_DMA_INTRLV_OFST))
/* The address of the ALT_NAND_DMA_RESCAN_BUF_FLAG register for the ALT_NAND_DMA instance. */
#define ALT_NAND_DMA_RESCAN_BUF_FLAG_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_DMA_ADDR) + ALT_NAND_DMA_RESCAN_BUF_FLAG_OFST))
/* The address of the ALT_NAND_DMA_NO_OF_BLOCKS_PER_LUN register for the ALT_NAND_DMA instance. */
#define ALT_NAND_DMA_NO_OF_BLOCKS_PER_LUN_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_DMA_ADDR) + ALT_NAND_DMA_NO_OF_BLOCKS_PER_LUN_OFST))
/* The address of the ALT_NAND_DMA_LUN_STAT_CMD register for the ALT_NAND_DMA instance. */
#define ALT_NAND_DMA_LUN_STAT_CMD_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_DMA_ADDR) + ALT_NAND_DMA_LUN_STAT_CMD_OFST))
/* The address of the ALT_NAND_DMA_CMD_DMA_CHANNEL_ERROR register for the ALT_NAND_DMA instance. */
#define ALT_NAND_DMA_CMD_DMA_CHANNEL_ERROR_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_DMA_ADDR) + ALT_NAND_DMA_CMD_DMA_CHANNEL_ERROR_OFST))
/* The address of the ALT_NAND_DMA_CMD_DMA_CHANNEL_ERROR_EN register for the ALT_NAND_DMA instance. */
#define ALT_NAND_DMA_CMD_DMA_CHANNEL_ERROR_EN_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NAND_DMA_ADDR) + ALT_NAND_DMA_CMD_DMA_CHANNEL_ERROR_EN_OFST))
/* The base address byte offset for the start of the ALT_NAND_DMA component. */
#define ALT_NAND_DMA_OFST        0xffb80700
/* The start address of the ALT_NAND_DMA component. */
#define ALT_NAND_DMA_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_NAND_DMA_OFST))
/* The lower bound address range of the ALT_NAND_DMA component. */
#define ALT_NAND_DMA_LB_ADDR     ALT_NAND_DMA_ADDR
/* The upper bound address range of the ALT_NAND_DMA component. */
#define ALT_NAND_DMA_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_NAND_DMA_ADDR) + 0xd4) - 1))


/*
 * Component Instance : i_nand_NANDDATA
 * 
 * Instance i_nand_NANDDATA of component ALT_NANDDATA.
 * 
 * 
 */
/* The base address byte offset for the start of the ALT_NANDDATA component. */
#define ALT_NANDDATA_OFST        0xffb90000
/* The start address of the ALT_NANDDATA component. */
#define ALT_NANDDATA_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_NANDDATA_OFST))
/* The lower bound address range of the ALT_NANDDATA component. */
#define ALT_NANDDATA_LB_ADDR     ALT_NANDDATA_ADDR
/* The upper bound address range of the ALT_NANDDATA component. */
#define ALT_NANDDATA_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_NANDDATA_ADDR) + 0x10000) - 1))


/*
 * Component Instance : i_uart_0_uart
 * 
 * Instance i_uart_0_uart of component ALT_UART.
 * 
 * 
 */
/* The address of the ALT_UART_RBR_THR_DLL register for the ALT_UART0 instance. */
#define ALT_UART0_RBR_THR_DLL_ADDR  ALT_UART_RBR_THR_DLL_ADDR(ALT_UART0_ADDR)
/* The address of the ALT_UART_IER_DLH register for the ALT_UART0 instance. */
#define ALT_UART0_IER_DLH_ADDR  ALT_UART_IER_DLH_ADDR(ALT_UART0_ADDR)
/* The address of the ALT_UART_IIR register for the ALT_UART0 instance. */
#define ALT_UART0_IIR_ADDR  ALT_UART_IIR_ADDR(ALT_UART0_ADDR)
/* The address of the ALT_UART_FCR register for the ALT_UART0 instance. */
#define ALT_UART0_FCR_ADDR  ALT_UART_FCR_ADDR(ALT_UART0_ADDR)
/* The address of the ALT_UART_LCR register for the ALT_UART0 instance. */
#define ALT_UART0_LCR_ADDR  ALT_UART_LCR_ADDR(ALT_UART0_ADDR)
/* The address of the ALT_UART_MCR register for the ALT_UART0 instance. */
#define ALT_UART0_MCR_ADDR  ALT_UART_MCR_ADDR(ALT_UART0_ADDR)
/* The address of the ALT_UART_LSR register for the ALT_UART0 instance. */
#define ALT_UART0_LSR_ADDR  ALT_UART_LSR_ADDR(ALT_UART0_ADDR)
/* The address of the ALT_UART_MSR register for the ALT_UART0 instance. */
#define ALT_UART0_MSR_ADDR  ALT_UART_MSR_ADDR(ALT_UART0_ADDR)
/* The address of the ALT_UART_SCR register for the ALT_UART0 instance. */
#define ALT_UART0_SCR_ADDR  ALT_UART_SCR_ADDR(ALT_UART0_ADDR)
/* The address of the ALT_UART_SRBR register for the ALT_UART0 instance. */
#define ALT_UART0_SRBR_STHR_0_ADDR  ALT_UART_SRBR_ADDR(ALT_UART0_ADDR)
/* The address of the ALT_UART_SRBR_STHR_1 register for the ALT_UART0 instance. */
#define ALT_UART0_SRBR_STHR_1_ADDR  ALT_UART_SRBR_STHR_1_ADDR(ALT_UART0_ADDR)
/* The address of the ALT_UART_SRBR_STHR_2 register for the ALT_UART0 instance. */
#define ALT_UART0_SRBR_STHR_2_ADDR  ALT_UART_SRBR_STHR_2_ADDR(ALT_UART0_ADDR)
/* The address of the ALT_UART_SRBR_STHR_3 register for the ALT_UART0 instance. */
#define ALT_UART0_SRBR_STHR_3_ADDR  ALT_UART_SRBR_STHR_3_ADDR(ALT_UART0_ADDR)
/* The address of the ALT_UART_SRBR_STHR_4 register for the ALT_UART0 instance. */
#define ALT_UART0_SRBR_STHR_4_ADDR  ALT_UART_SRBR_STHR_4_ADDR(ALT_UART0_ADDR)
/* The address of the ALT_UART_SRBR_STHR_5 register for the ALT_UART0 instance. */
#define ALT_UART0_SRBR_STHR_5_ADDR  ALT_UART_SRBR_STHR_5_ADDR(ALT_UART0_ADDR)
/* The address of the ALT_UART_SRBR_STHR_6 register for the ALT_UART0 instance. */
#define ALT_UART0_SRBR_STHR_6_ADDR  ALT_UART_SRBR_STHR_6_ADDR(ALT_UART0_ADDR)
/* The address of the ALT_UART_SRBR_STHR_7 register for the ALT_UART0 instance. */
#define ALT_UART0_SRBR_STHR_7_ADDR  ALT_UART_SRBR_STHR_7_ADDR(ALT_UART0_ADDR)
/* The address of the ALT_UART_SRBR_STHR_8 register for the ALT_UART0 instance. */
#define ALT_UART0_SRBR_STHR_8_ADDR  ALT_UART_SRBR_STHR_8_ADDR(ALT_UART0_ADDR)
/* The address of the ALT_UART_SRBR_STHR_9 register for the ALT_UART0 instance. */
#define ALT_UART0_SRBR_STHR_9_ADDR  ALT_UART_SRBR_STHR_9_ADDR(ALT_UART0_ADDR)
/* The address of the ALT_UART_SRBR_STHR_10 register for the ALT_UART0 instance. */
#define ALT_UART0_SRBR_STHR_10_ADDR  ALT_UART_SRBR_STHR_10_ADDR(ALT_UART0_ADDR)
/* The address of the ALT_UART_SRBR_STHR_11 register for the ALT_UART0 instance. */
#define ALT_UART0_SRBR_STHR_11_ADDR  ALT_UART_SRBR_STHR_11_ADDR(ALT_UART0_ADDR)
/* The address of the ALT_UART_SRBR_STHR_12 register for the ALT_UART0 instance. */
#define ALT_UART0_SRBR_STHR_12_ADDR  ALT_UART_SRBR_STHR_12_ADDR(ALT_UART0_ADDR)
/* The address of the ALT_UART_SRBR_STHR_13 register for the ALT_UART0 instance. */
#define ALT_UART0_SRBR_STHR_13_ADDR  ALT_UART_SRBR_STHR_13_ADDR(ALT_UART0_ADDR)
/* The address of the ALT_UART_SRBR_STHR_14 register for the ALT_UART0 instance. */
#define ALT_UART0_SRBR_STHR_14_ADDR  ALT_UART_SRBR_STHR_14_ADDR(ALT_UART0_ADDR)
/* The address of the ALT_UART_SRBR_STHR_15 register for the ALT_UART0 instance. */
#define ALT_UART0_SRBR_STHR_15_ADDR  ALT_UART_SRBR_STHR_15_ADDR(ALT_UART0_ADDR)
/* The address of the ALT_UART_FAR register for the ALT_UART0 instance. */
#define ALT_UART0_FAR_ADDR  ALT_UART_FAR_ADDR(ALT_UART0_ADDR)
/* The address of the ALT_UART_TFR register for the ALT_UART0 instance. */
#define ALT_UART0_TFR_ADDR  ALT_UART_TFR_ADDR(ALT_UART0_ADDR)
/* The address of the ALT_UART_RFW register for the ALT_UART0 instance. */
#define ALT_UART0_RFW_ADDR  ALT_UART_RFW_ADDR(ALT_UART0_ADDR)
/* The address of the ALT_UART_USR register for the ALT_UART0 instance. */
#define ALT_UART0_USR_ADDR  ALT_UART_USR_ADDR(ALT_UART0_ADDR)
/* The address of the ALT_UART_TFL register for the ALT_UART0 instance. */
#define ALT_UART0_TFL_ADDR  ALT_UART_TFL_ADDR(ALT_UART0_ADDR)
/* The address of the ALT_UART_RFL register for the ALT_UART0 instance. */
#define ALT_UART0_RFL_ADDR  ALT_UART_RFL_ADDR(ALT_UART0_ADDR)
/* The address of the ALT_UART_SRR register for the ALT_UART0 instance. */
#define ALT_UART0_SRR_ADDR  ALT_UART_SRR_ADDR(ALT_UART0_ADDR)
/* The address of the ALT_UART_SRTS register for the ALT_UART0 instance. */
#define ALT_UART0_SRTS_ADDR  ALT_UART_SRTS_ADDR(ALT_UART0_ADDR)
/* The address of the ALT_UART_SBCR register for the ALT_UART0 instance. */
#define ALT_UART0_SBCR_ADDR  ALT_UART_SBCR_ADDR(ALT_UART0_ADDR)
/* The address of the ALT_UART_SDMAM register for the ALT_UART0 instance. */
#define ALT_UART0_SDMAM_ADDR  ALT_UART_SDMAM_ADDR(ALT_UART0_ADDR)
/* The address of the ALT_UART_SFE register for the ALT_UART0 instance. */
#define ALT_UART0_SFE_ADDR  ALT_UART_SFE_ADDR(ALT_UART0_ADDR)
/* The address of the ALT_UART_SRT register for the ALT_UART0 instance. */
#define ALT_UART0_SRT_ADDR  ALT_UART_SRT_ADDR(ALT_UART0_ADDR)
/* The address of the ALT_UART_STET register for the ALT_UART0 instance. */
#define ALT_UART0_STET_ADDR  ALT_UART_STET_ADDR(ALT_UART0_ADDR)
/* The address of the ALT_UART_HTX register for the ALT_UART0 instance. */
#define ALT_UART0_HTX_ADDR  ALT_UART_HTX_ADDR(ALT_UART0_ADDR)
/* The address of the ALT_UART_DMASA register for the ALT_UART0 instance. */
#define ALT_UART0_DMASA_ADDR  ALT_UART_DMASA_ADDR(ALT_UART0_ADDR)
/* The address of the ALT_UART_CPR register for the ALT_UART0 instance. */
#define ALT_UART0_CPR_ADDR  ALT_UART_CPR_ADDR(ALT_UART0_ADDR)
/* The address of the ALT_UART_UCV register for the ALT_UART0 instance. */
#define ALT_UART0_UCV_ADDR  ALT_UART_UCV_ADDR(ALT_UART0_ADDR)
/* The address of the ALT_UART_CTR register for the ALT_UART0 instance. */
#define ALT_UART0_CTR_ADDR  ALT_UART_CTR_ADDR(ALT_UART0_ADDR)
/* The base address byte offset for the start of the ALT_UART0 component. */
#define ALT_UART0_OFST        0xffc02000
/* The start address of the ALT_UART0 component. */
#define ALT_UART0_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_UART0_OFST))
/* The lower bound address range of the ALT_UART0 component. */
#define ALT_UART0_LB_ADDR     ALT_UART0_ADDR
/* The upper bound address range of the ALT_UART0 component. */
#define ALT_UART0_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_UART0_ADDR) + 0x100) - 1))


/*
 * Component Instance : i_uart_1_uart
 * 
 * Instance i_uart_1_uart of component ALT_UART.
 * 
 * 
 */
/* The address of the ALT_UART_RBR_THR_DLL register for the ALT_UART1 instance. */
#define ALT_UART1_RBR_THR_DLL_ADDR  ALT_UART_RBR_THR_DLL_ADDR(ALT_UART1_ADDR)
/* The address of the ALT_UART_IER_DLH register for the ALT_UART1 instance. */
#define ALT_UART1_IER_DLH_ADDR  ALT_UART_IER_DLH_ADDR(ALT_UART1_ADDR)
/* The address of the ALT_UART_IIR register for the ALT_UART1 instance. */
#define ALT_UART1_IIR_ADDR  ALT_UART_IIR_ADDR(ALT_UART1_ADDR)
/* The address of the ALT_UART_FCR register for the ALT_UART1 instance. */
#define ALT_UART1_FCR_ADDR  ALT_UART_FCR_ADDR(ALT_UART1_ADDR)
/* The address of the ALT_UART_LCR register for the ALT_UART1 instance. */
#define ALT_UART1_LCR_ADDR  ALT_UART_LCR_ADDR(ALT_UART1_ADDR)
/* The address of the ALT_UART_MCR register for the ALT_UART1 instance. */
#define ALT_UART1_MCR_ADDR  ALT_UART_MCR_ADDR(ALT_UART1_ADDR)
/* The address of the ALT_UART_LSR register for the ALT_UART1 instance. */
#define ALT_UART1_LSR_ADDR  ALT_UART_LSR_ADDR(ALT_UART1_ADDR)
/* The address of the ALT_UART_MSR register for the ALT_UART1 instance. */
#define ALT_UART1_MSR_ADDR  ALT_UART_MSR_ADDR(ALT_UART1_ADDR)
/* The address of the ALT_UART_SCR register for the ALT_UART1 instance. */
#define ALT_UART1_SCR_ADDR  ALT_UART_SCR_ADDR(ALT_UART1_ADDR)
/* The address of the ALT_UART_SRBR register for the ALT_UART1 instance. */
#define ALT_UART1_SRBR_STHR_0_ADDR  ALT_UART_SRBR_ADDR(ALT_UART1_ADDR)
/* The address of the ALT_UART_SRBR_STHR_1 register for the ALT_UART1 instance. */
#define ALT_UART1_SRBR_STHR_1_ADDR  ALT_UART_SRBR_STHR_1_ADDR(ALT_UART1_ADDR)
/* The address of the ALT_UART_SRBR_STHR_2 register for the ALT_UART1 instance. */
#define ALT_UART1_SRBR_STHR_2_ADDR  ALT_UART_SRBR_STHR_2_ADDR(ALT_UART1_ADDR)
/* The address of the ALT_UART_SRBR_STHR_3 register for the ALT_UART1 instance. */
#define ALT_UART1_SRBR_STHR_3_ADDR  ALT_UART_SRBR_STHR_3_ADDR(ALT_UART1_ADDR)
/* The address of the ALT_UART_SRBR_STHR_4 register for the ALT_UART1 instance. */
#define ALT_UART1_SRBR_STHR_4_ADDR  ALT_UART_SRBR_STHR_4_ADDR(ALT_UART1_ADDR)
/* The address of the ALT_UART_SRBR_STHR_5 register for the ALT_UART1 instance. */
#define ALT_UART1_SRBR_STHR_5_ADDR  ALT_UART_SRBR_STHR_5_ADDR(ALT_UART1_ADDR)
/* The address of the ALT_UART_SRBR_STHR_6 register for the ALT_UART1 instance. */
#define ALT_UART1_SRBR_STHR_6_ADDR  ALT_UART_SRBR_STHR_6_ADDR(ALT_UART1_ADDR)
/* The address of the ALT_UART_SRBR_STHR_7 register for the ALT_UART1 instance. */
#define ALT_UART1_SRBR_STHR_7_ADDR  ALT_UART_SRBR_STHR_7_ADDR(ALT_UART1_ADDR)
/* The address of the ALT_UART_SRBR_STHR_8 register for the ALT_UART1 instance. */
#define ALT_UART1_SRBR_STHR_8_ADDR  ALT_UART_SRBR_STHR_8_ADDR(ALT_UART1_ADDR)
/* The address of the ALT_UART_SRBR_STHR_9 register for the ALT_UART1 instance. */
#define ALT_UART1_SRBR_STHR_9_ADDR  ALT_UART_SRBR_STHR_9_ADDR(ALT_UART1_ADDR)
/* The address of the ALT_UART_SRBR_STHR_10 register for the ALT_UART1 instance. */
#define ALT_UART1_SRBR_STHR_10_ADDR  ALT_UART_SRBR_STHR_10_ADDR(ALT_UART1_ADDR)
/* The address of the ALT_UART_SRBR_STHR_11 register for the ALT_UART1 instance. */
#define ALT_UART1_SRBR_STHR_11_ADDR  ALT_UART_SRBR_STHR_11_ADDR(ALT_UART1_ADDR)
/* The address of the ALT_UART_SRBR_STHR_12 register for the ALT_UART1 instance. */
#define ALT_UART1_SRBR_STHR_12_ADDR  ALT_UART_SRBR_STHR_12_ADDR(ALT_UART1_ADDR)
/* The address of the ALT_UART_SRBR_STHR_13 register for the ALT_UART1 instance. */
#define ALT_UART1_SRBR_STHR_13_ADDR  ALT_UART_SRBR_STHR_13_ADDR(ALT_UART1_ADDR)
/* The address of the ALT_UART_SRBR_STHR_14 register for the ALT_UART1 instance. */
#define ALT_UART1_SRBR_STHR_14_ADDR  ALT_UART_SRBR_STHR_14_ADDR(ALT_UART1_ADDR)
/* The address of the ALT_UART_SRBR_STHR_15 register for the ALT_UART1 instance. */
#define ALT_UART1_SRBR_STHR_15_ADDR  ALT_UART_SRBR_STHR_15_ADDR(ALT_UART1_ADDR)
/* The address of the ALT_UART_FAR register for the ALT_UART1 instance. */
#define ALT_UART1_FAR_ADDR  ALT_UART_FAR_ADDR(ALT_UART1_ADDR)
/* The address of the ALT_UART_TFR register for the ALT_UART1 instance. */
#define ALT_UART1_TFR_ADDR  ALT_UART_TFR_ADDR(ALT_UART1_ADDR)
/* The address of the ALT_UART_RFW register for the ALT_UART1 instance. */
#define ALT_UART1_RFW_ADDR  ALT_UART_RFW_ADDR(ALT_UART1_ADDR)
/* The address of the ALT_UART_USR register for the ALT_UART1 instance. */
#define ALT_UART1_USR_ADDR  ALT_UART_USR_ADDR(ALT_UART1_ADDR)
/* The address of the ALT_UART_TFL register for the ALT_UART1 instance. */
#define ALT_UART1_TFL_ADDR  ALT_UART_TFL_ADDR(ALT_UART1_ADDR)
/* The address of the ALT_UART_RFL register for the ALT_UART1 instance. */
#define ALT_UART1_RFL_ADDR  ALT_UART_RFL_ADDR(ALT_UART1_ADDR)
/* The address of the ALT_UART_SRR register for the ALT_UART1 instance. */
#define ALT_UART1_SRR_ADDR  ALT_UART_SRR_ADDR(ALT_UART1_ADDR)
/* The address of the ALT_UART_SRTS register for the ALT_UART1 instance. */
#define ALT_UART1_SRTS_ADDR  ALT_UART_SRTS_ADDR(ALT_UART1_ADDR)
/* The address of the ALT_UART_SBCR register for the ALT_UART1 instance. */
#define ALT_UART1_SBCR_ADDR  ALT_UART_SBCR_ADDR(ALT_UART1_ADDR)
/* The address of the ALT_UART_SDMAM register for the ALT_UART1 instance. */
#define ALT_UART1_SDMAM_ADDR  ALT_UART_SDMAM_ADDR(ALT_UART1_ADDR)
/* The address of the ALT_UART_SFE register for the ALT_UART1 instance. */
#define ALT_UART1_SFE_ADDR  ALT_UART_SFE_ADDR(ALT_UART1_ADDR)
/* The address of the ALT_UART_SRT register for the ALT_UART1 instance. */
#define ALT_UART1_SRT_ADDR  ALT_UART_SRT_ADDR(ALT_UART1_ADDR)
/* The address of the ALT_UART_STET register for the ALT_UART1 instance. */
#define ALT_UART1_STET_ADDR  ALT_UART_STET_ADDR(ALT_UART1_ADDR)
/* The address of the ALT_UART_HTX register for the ALT_UART1 instance. */
#define ALT_UART1_HTX_ADDR  ALT_UART_HTX_ADDR(ALT_UART1_ADDR)
/* The address of the ALT_UART_DMASA register for the ALT_UART1 instance. */
#define ALT_UART1_DMASA_ADDR  ALT_UART_DMASA_ADDR(ALT_UART1_ADDR)
/* The address of the ALT_UART_CPR register for the ALT_UART1 instance. */
#define ALT_UART1_CPR_ADDR  ALT_UART_CPR_ADDR(ALT_UART1_ADDR)
/* The address of the ALT_UART_UCV register for the ALT_UART1 instance. */
#define ALT_UART1_UCV_ADDR  ALT_UART_UCV_ADDR(ALT_UART1_ADDR)
/* The address of the ALT_UART_CTR register for the ALT_UART1 instance. */
#define ALT_UART1_CTR_ADDR  ALT_UART_CTR_ADDR(ALT_UART1_ADDR)
/* The base address byte offset for the start of the ALT_UART1 component. */
#define ALT_UART1_OFST        0xffc02100
/* The start address of the ALT_UART1 component. */
#define ALT_UART1_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_UART1_OFST))
/* The lower bound address range of the ALT_UART1 component. */
#define ALT_UART1_LB_ADDR     ALT_UART1_ADDR
/* The upper bound address range of the ALT_UART1 component. */
#define ALT_UART1_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_UART1_ADDR) + 0x100) - 1))


/*
 * Component Instance : i_i2c_0_i2c
 * 
 * Instance i_i2c_0_i2c of component ALT_I2C.
 * 
 * 
 */
/* The address of the ALT_I2C_CON register for the ALT_I2C0 instance. */
#define ALT_I2C0_CON_ADDR  ALT_I2C_CON_ADDR(ALT_I2C0_ADDR)
/* The address of the ALT_I2C_TAR register for the ALT_I2C0 instance. */
#define ALT_I2C0_TAR_ADDR  ALT_I2C_TAR_ADDR(ALT_I2C0_ADDR)
/* The address of the ALT_I2C_SAR register for the ALT_I2C0 instance. */
#define ALT_I2C0_SAR_ADDR  ALT_I2C_SAR_ADDR(ALT_I2C0_ADDR)
/* The address of the ALT_I2C_DATA_CMD register for the ALT_I2C0 instance. */
#define ALT_I2C0_DATA_CMD_ADDR  ALT_I2C_DATA_CMD_ADDR(ALT_I2C0_ADDR)
/* The address of the ALT_I2C_SS_SCL_HCNT register for the ALT_I2C0 instance. */
#define ALT_I2C0_SS_SCL_HCNT_ADDR  ALT_I2C_SS_SCL_HCNT_ADDR(ALT_I2C0_ADDR)
/* The address of the ALT_I2C_SS_SCL_LCNT register for the ALT_I2C0 instance. */
#define ALT_I2C0_SS_SCL_LCNT_ADDR  ALT_I2C_SS_SCL_LCNT_ADDR(ALT_I2C0_ADDR)
/* The address of the ALT_I2C_FS_SCL_HCNT register for the ALT_I2C0 instance. */
#define ALT_I2C0_FS_SCL_HCNT_ADDR  ALT_I2C_FS_SCL_HCNT_ADDR(ALT_I2C0_ADDR)
/* The address of the ALT_I2C_FS_SCL_LCNT register for the ALT_I2C0 instance. */
#define ALT_I2C0_FS_SCL_LCNT_ADDR  ALT_I2C_FS_SCL_LCNT_ADDR(ALT_I2C0_ADDR)
/* The address of the ALT_I2C_INTR_STAT register for the ALT_I2C0 instance. */
#define ALT_I2C0_INTR_STAT_ADDR  ALT_I2C_INTR_STAT_ADDR(ALT_I2C0_ADDR)
/* The address of the ALT_I2C_INTR_MSK register for the ALT_I2C0 instance. */
#define ALT_I2C0_INTR_MSK_ADDR  ALT_I2C_INTR_MSK_ADDR(ALT_I2C0_ADDR)
/* The address of the ALT_I2C_RAW_INTR_STAT register for the ALT_I2C0 instance. */
#define ALT_I2C0_RAW_INTR_STAT_ADDR  ALT_I2C_RAW_INTR_STAT_ADDR(ALT_I2C0_ADDR)
/* The address of the ALT_I2C_RX_TL register for the ALT_I2C0 instance. */
#define ALT_I2C0_RX_TL_ADDR  ALT_I2C_RX_TL_ADDR(ALT_I2C0_ADDR)
/* The address of the ALT_I2C_TX_TL register for the ALT_I2C0 instance. */
#define ALT_I2C0_TX_TL_ADDR  ALT_I2C_TX_TL_ADDR(ALT_I2C0_ADDR)
/* The address of the ALT_I2C_CLR_INTR register for the ALT_I2C0 instance. */
#define ALT_I2C0_CLR_INTR_ADDR  ALT_I2C_CLR_INTR_ADDR(ALT_I2C0_ADDR)
/* The address of the ALT_I2C_CLR_RX_UNDER register for the ALT_I2C0 instance. */
#define ALT_I2C0_CLR_RX_UNDER_ADDR  ALT_I2C_CLR_RX_UNDER_ADDR(ALT_I2C0_ADDR)
/* The address of the ALT_I2C_CLR_RX_OVER register for the ALT_I2C0 instance. */
#define ALT_I2C0_CLR_RX_OVER_ADDR  ALT_I2C_CLR_RX_OVER_ADDR(ALT_I2C0_ADDR)
/* The address of the ALT_I2C_CLR_TX_OVER register for the ALT_I2C0 instance. */
#define ALT_I2C0_CLR_TX_OVER_ADDR  ALT_I2C_CLR_TX_OVER_ADDR(ALT_I2C0_ADDR)
/* The address of the ALT_I2C_CLR_RD_REQ register for the ALT_I2C0 instance. */
#define ALT_I2C0_CLR_RD_REQ_ADDR  ALT_I2C_CLR_RD_REQ_ADDR(ALT_I2C0_ADDR)
/* The address of the ALT_I2C_CLR_TX_ABRT register for the ALT_I2C0 instance. */
#define ALT_I2C0_CLR_TX_ABRT_ADDR  ALT_I2C_CLR_TX_ABRT_ADDR(ALT_I2C0_ADDR)
/* The address of the ALT_I2C_CLR_RX_DONE register for the ALT_I2C0 instance. */
#define ALT_I2C0_CLR_RX_DONE_ADDR  ALT_I2C_CLR_RX_DONE_ADDR(ALT_I2C0_ADDR)
/* The address of the ALT_I2C_CLR_ACTIVITY register for the ALT_I2C0 instance. */
#define ALT_I2C0_CLR_ACTIVITY_ADDR  ALT_I2C_CLR_ACTIVITY_ADDR(ALT_I2C0_ADDR)
/* The address of the ALT_I2C_CLR_STOP_DET register for the ALT_I2C0 instance. */
#define ALT_I2C0_CLR_STOP_DET_ADDR  ALT_I2C_CLR_STOP_DET_ADDR(ALT_I2C0_ADDR)
/* The address of the ALT_I2C_CLR_START_DET register for the ALT_I2C0 instance. */
#define ALT_I2C0_CLR_START_DET_ADDR  ALT_I2C_CLR_START_DET_ADDR(ALT_I2C0_ADDR)
/* The address of the ALT_I2C_CLR_GEN_CALL register for the ALT_I2C0 instance. */
#define ALT_I2C0_CLR_GEN_CALL_ADDR  ALT_I2C_CLR_GEN_CALL_ADDR(ALT_I2C0_ADDR)
/* The address of the ALT_I2C_EN register for the ALT_I2C0 instance. */
#define ALT_I2C0_EN_ADDR  ALT_I2C_EN_ADDR(ALT_I2C0_ADDR)
/* The address of the ALT_I2C_STAT register for the ALT_I2C0 instance. */
#define ALT_I2C0_STAT_ADDR  ALT_I2C_STAT_ADDR(ALT_I2C0_ADDR)
/* The address of the ALT_I2C_TXFLR register for the ALT_I2C0 instance. */
#define ALT_I2C0_TXFLR_ADDR  ALT_I2C_TXFLR_ADDR(ALT_I2C0_ADDR)
/* The address of the ALT_I2C_RXFLR register for the ALT_I2C0 instance. */
#define ALT_I2C0_RXFLR_ADDR  ALT_I2C_RXFLR_ADDR(ALT_I2C0_ADDR)
/* The address of the ALT_I2C_SDA_HOLD register for the ALT_I2C0 instance. */
#define ALT_I2C0_SDA_HOLD_ADDR  ALT_I2C_SDA_HOLD_ADDR(ALT_I2C0_ADDR)
/* The address of the ALT_I2C_TX_ABRT_SRC register for the ALT_I2C0 instance. */
#define ALT_I2C0_TX_ABRT_SRC_ADDR  ALT_I2C_TX_ABRT_SRC_ADDR(ALT_I2C0_ADDR)
/* The address of the ALT_I2C_SLV_DATA_NACK_ONLY register for the ALT_I2C0 instance. */
#define ALT_I2C0_SLV_DATA_NACK_ONLY_ADDR  ALT_I2C_SLV_DATA_NACK_ONLY_ADDR(ALT_I2C0_ADDR)
/* The address of the ALT_I2C_DMA_CR register for the ALT_I2C0 instance. */
#define ALT_I2C0_DMA_CR_ADDR  ALT_I2C_DMA_CR_ADDR(ALT_I2C0_ADDR)
/* The address of the ALT_I2C_DMA_TDLR register for the ALT_I2C0 instance. */
#define ALT_I2C0_DMA_TDLR_ADDR  ALT_I2C_DMA_TDLR_ADDR(ALT_I2C0_ADDR)
/* The address of the ALT_I2C_DMA_RDLR register for the ALT_I2C0 instance. */
#define ALT_I2C0_DMA_RDLR_ADDR  ALT_I2C_DMA_RDLR_ADDR(ALT_I2C0_ADDR)
/* The address of the ALT_I2C_SDA_SETUP register for the ALT_I2C0 instance. */
#define ALT_I2C0_SDA_SETUP_ADDR  ALT_I2C_SDA_SETUP_ADDR(ALT_I2C0_ADDR)
/* The address of the ALT_I2C_ACK_GENERAL_CALL register for the ALT_I2C0 instance. */
#define ALT_I2C0_ACK_GENERAL_CALL_ADDR  ALT_I2C_ACK_GENERAL_CALL_ADDR(ALT_I2C0_ADDR)
/* The address of the ALT_I2C_EN_STAT register for the ALT_I2C0 instance. */
#define ALT_I2C0_EN_STAT_ADDR  ALT_I2C_EN_STAT_ADDR(ALT_I2C0_ADDR)
/* The address of the ALT_I2C_FS_SPKLEN register for the ALT_I2C0 instance. */
#define ALT_I2C0_FS_SPKLEN_ADDR  ALT_I2C_FS_SPKLEN_ADDR(ALT_I2C0_ADDR)
/* The address of the ALT_I2C_CLR_RESTART_DET register for the ALT_I2C0 instance. */
#define ALT_I2C0_CLR_RESTART_DET_ADDR  ALT_I2C_CLR_RESTART_DET_ADDR(ALT_I2C0_ADDR)
/* The address of the ALT_I2C_COMP_PARAM_1 register for the ALT_I2C0 instance. */
#define ALT_I2C0_COMP_PARAM_1_ADDR  ALT_I2C_COMP_PARAM_1_ADDR(ALT_I2C0_ADDR)
/* The address of the ALT_I2C_COMP_VER register for the ALT_I2C0 instance. */
#define ALT_I2C0_COMP_VER_ADDR  ALT_I2C_COMP_VER_ADDR(ALT_I2C0_ADDR)
/* The address of the ALT_I2C_COMP_TYPE register for the ALT_I2C0 instance. */
#define ALT_I2C0_COMP_TYPE_ADDR  ALT_I2C_COMP_TYPE_ADDR(ALT_I2C0_ADDR)
/* The base address byte offset for the start of the ALT_I2C0 component. */
#define ALT_I2C0_OFST        0xffc02200
/* The start address of the ALT_I2C0 component. */
#define ALT_I2C0_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_I2C0_OFST))
/* The lower bound address range of the ALT_I2C0 component. */
#define ALT_I2C0_LB_ADDR     ALT_I2C0_ADDR
/* The upper bound address range of the ALT_I2C0 component. */
#define ALT_I2C0_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_I2C0_ADDR) + 0x100) - 1))


/*
 * Component Instance : i_i2c_1_i2c
 * 
 * Instance i_i2c_1_i2c of component ALT_I2C.
 * 
 * 
 */
/* The address of the ALT_I2C_CON register for the ALT_I2C1 instance. */
#define ALT_I2C1_CON_ADDR  ALT_I2C_CON_ADDR(ALT_I2C1_ADDR)
/* The address of the ALT_I2C_TAR register for the ALT_I2C1 instance. */
#define ALT_I2C1_TAR_ADDR  ALT_I2C_TAR_ADDR(ALT_I2C1_ADDR)
/* The address of the ALT_I2C_SAR register for the ALT_I2C1 instance. */
#define ALT_I2C1_SAR_ADDR  ALT_I2C_SAR_ADDR(ALT_I2C1_ADDR)
/* The address of the ALT_I2C_DATA_CMD register for the ALT_I2C1 instance. */
#define ALT_I2C1_DATA_CMD_ADDR  ALT_I2C_DATA_CMD_ADDR(ALT_I2C1_ADDR)
/* The address of the ALT_I2C_SS_SCL_HCNT register for the ALT_I2C1 instance. */
#define ALT_I2C1_SS_SCL_HCNT_ADDR  ALT_I2C_SS_SCL_HCNT_ADDR(ALT_I2C1_ADDR)
/* The address of the ALT_I2C_SS_SCL_LCNT register for the ALT_I2C1 instance. */
#define ALT_I2C1_SS_SCL_LCNT_ADDR  ALT_I2C_SS_SCL_LCNT_ADDR(ALT_I2C1_ADDR)
/* The address of the ALT_I2C_FS_SCL_HCNT register for the ALT_I2C1 instance. */
#define ALT_I2C1_FS_SCL_HCNT_ADDR  ALT_I2C_FS_SCL_HCNT_ADDR(ALT_I2C1_ADDR)
/* The address of the ALT_I2C_FS_SCL_LCNT register for the ALT_I2C1 instance. */
#define ALT_I2C1_FS_SCL_LCNT_ADDR  ALT_I2C_FS_SCL_LCNT_ADDR(ALT_I2C1_ADDR)
/* The address of the ALT_I2C_INTR_STAT register for the ALT_I2C1 instance. */
#define ALT_I2C1_INTR_STAT_ADDR  ALT_I2C_INTR_STAT_ADDR(ALT_I2C1_ADDR)
/* The address of the ALT_I2C_INTR_MSK register for the ALT_I2C1 instance. */
#define ALT_I2C1_INTR_MSK_ADDR  ALT_I2C_INTR_MSK_ADDR(ALT_I2C1_ADDR)
/* The address of the ALT_I2C_RAW_INTR_STAT register for the ALT_I2C1 instance. */
#define ALT_I2C1_RAW_INTR_STAT_ADDR  ALT_I2C_RAW_INTR_STAT_ADDR(ALT_I2C1_ADDR)
/* The address of the ALT_I2C_RX_TL register for the ALT_I2C1 instance. */
#define ALT_I2C1_RX_TL_ADDR  ALT_I2C_RX_TL_ADDR(ALT_I2C1_ADDR)
/* The address of the ALT_I2C_TX_TL register for the ALT_I2C1 instance. */
#define ALT_I2C1_TX_TL_ADDR  ALT_I2C_TX_TL_ADDR(ALT_I2C1_ADDR)
/* The address of the ALT_I2C_CLR_INTR register for the ALT_I2C1 instance. */
#define ALT_I2C1_CLR_INTR_ADDR  ALT_I2C_CLR_INTR_ADDR(ALT_I2C1_ADDR)
/* The address of the ALT_I2C_CLR_RX_UNDER register for the ALT_I2C1 instance. */
#define ALT_I2C1_CLR_RX_UNDER_ADDR  ALT_I2C_CLR_RX_UNDER_ADDR(ALT_I2C1_ADDR)
/* The address of the ALT_I2C_CLR_RX_OVER register for the ALT_I2C1 instance. */
#define ALT_I2C1_CLR_RX_OVER_ADDR  ALT_I2C_CLR_RX_OVER_ADDR(ALT_I2C1_ADDR)
/* The address of the ALT_I2C_CLR_TX_OVER register for the ALT_I2C1 instance. */
#define ALT_I2C1_CLR_TX_OVER_ADDR  ALT_I2C_CLR_TX_OVER_ADDR(ALT_I2C1_ADDR)
/* The address of the ALT_I2C_CLR_RD_REQ register for the ALT_I2C1 instance. */
#define ALT_I2C1_CLR_RD_REQ_ADDR  ALT_I2C_CLR_RD_REQ_ADDR(ALT_I2C1_ADDR)
/* The address of the ALT_I2C_CLR_TX_ABRT register for the ALT_I2C1 instance. */
#define ALT_I2C1_CLR_TX_ABRT_ADDR  ALT_I2C_CLR_TX_ABRT_ADDR(ALT_I2C1_ADDR)
/* The address of the ALT_I2C_CLR_RX_DONE register for the ALT_I2C1 instance. */
#define ALT_I2C1_CLR_RX_DONE_ADDR  ALT_I2C_CLR_RX_DONE_ADDR(ALT_I2C1_ADDR)
/* The address of the ALT_I2C_CLR_ACTIVITY register for the ALT_I2C1 instance. */
#define ALT_I2C1_CLR_ACTIVITY_ADDR  ALT_I2C_CLR_ACTIVITY_ADDR(ALT_I2C1_ADDR)
/* The address of the ALT_I2C_CLR_STOP_DET register for the ALT_I2C1 instance. */
#define ALT_I2C1_CLR_STOP_DET_ADDR  ALT_I2C_CLR_STOP_DET_ADDR(ALT_I2C1_ADDR)
/* The address of the ALT_I2C_CLR_START_DET register for the ALT_I2C1 instance. */
#define ALT_I2C1_CLR_START_DET_ADDR  ALT_I2C_CLR_START_DET_ADDR(ALT_I2C1_ADDR)
/* The address of the ALT_I2C_CLR_GEN_CALL register for the ALT_I2C1 instance. */
#define ALT_I2C1_CLR_GEN_CALL_ADDR  ALT_I2C_CLR_GEN_CALL_ADDR(ALT_I2C1_ADDR)
/* The address of the ALT_I2C_EN register for the ALT_I2C1 instance. */
#define ALT_I2C1_EN_ADDR  ALT_I2C_EN_ADDR(ALT_I2C1_ADDR)
/* The address of the ALT_I2C_STAT register for the ALT_I2C1 instance. */
#define ALT_I2C1_STAT_ADDR  ALT_I2C_STAT_ADDR(ALT_I2C1_ADDR)
/* The address of the ALT_I2C_TXFLR register for the ALT_I2C1 instance. */
#define ALT_I2C1_TXFLR_ADDR  ALT_I2C_TXFLR_ADDR(ALT_I2C1_ADDR)
/* The address of the ALT_I2C_RXFLR register for the ALT_I2C1 instance. */
#define ALT_I2C1_RXFLR_ADDR  ALT_I2C_RXFLR_ADDR(ALT_I2C1_ADDR)
/* The address of the ALT_I2C_SDA_HOLD register for the ALT_I2C1 instance. */
#define ALT_I2C1_SDA_HOLD_ADDR  ALT_I2C_SDA_HOLD_ADDR(ALT_I2C1_ADDR)
/* The address of the ALT_I2C_TX_ABRT_SRC register for the ALT_I2C1 instance. */
#define ALT_I2C1_TX_ABRT_SRC_ADDR  ALT_I2C_TX_ABRT_SRC_ADDR(ALT_I2C1_ADDR)
/* The address of the ALT_I2C_SLV_DATA_NACK_ONLY register for the ALT_I2C1 instance. */
#define ALT_I2C1_SLV_DATA_NACK_ONLY_ADDR  ALT_I2C_SLV_DATA_NACK_ONLY_ADDR(ALT_I2C1_ADDR)
/* The address of the ALT_I2C_DMA_CR register for the ALT_I2C1 instance. */
#define ALT_I2C1_DMA_CR_ADDR  ALT_I2C_DMA_CR_ADDR(ALT_I2C1_ADDR)
/* The address of the ALT_I2C_DMA_TDLR register for the ALT_I2C1 instance. */
#define ALT_I2C1_DMA_TDLR_ADDR  ALT_I2C_DMA_TDLR_ADDR(ALT_I2C1_ADDR)
/* The address of the ALT_I2C_DMA_RDLR register for the ALT_I2C1 instance. */
#define ALT_I2C1_DMA_RDLR_ADDR  ALT_I2C_DMA_RDLR_ADDR(ALT_I2C1_ADDR)
/* The address of the ALT_I2C_SDA_SETUP register for the ALT_I2C1 instance. */
#define ALT_I2C1_SDA_SETUP_ADDR  ALT_I2C_SDA_SETUP_ADDR(ALT_I2C1_ADDR)
/* The address of the ALT_I2C_ACK_GENERAL_CALL register for the ALT_I2C1 instance. */
#define ALT_I2C1_ACK_GENERAL_CALL_ADDR  ALT_I2C_ACK_GENERAL_CALL_ADDR(ALT_I2C1_ADDR)
/* The address of the ALT_I2C_EN_STAT register for the ALT_I2C1 instance. */
#define ALT_I2C1_EN_STAT_ADDR  ALT_I2C_EN_STAT_ADDR(ALT_I2C1_ADDR)
/* The address of the ALT_I2C_FS_SPKLEN register for the ALT_I2C1 instance. */
#define ALT_I2C1_FS_SPKLEN_ADDR  ALT_I2C_FS_SPKLEN_ADDR(ALT_I2C1_ADDR)
/* The address of the ALT_I2C_CLR_RESTART_DET register for the ALT_I2C1 instance. */
#define ALT_I2C1_CLR_RESTART_DET_ADDR  ALT_I2C_CLR_RESTART_DET_ADDR(ALT_I2C1_ADDR)
/* The address of the ALT_I2C_COMP_PARAM_1 register for the ALT_I2C1 instance. */
#define ALT_I2C1_COMP_PARAM_1_ADDR  ALT_I2C_COMP_PARAM_1_ADDR(ALT_I2C1_ADDR)
/* The address of the ALT_I2C_COMP_VER register for the ALT_I2C1 instance. */
#define ALT_I2C1_COMP_VER_ADDR  ALT_I2C_COMP_VER_ADDR(ALT_I2C1_ADDR)
/* The address of the ALT_I2C_COMP_TYPE register for the ALT_I2C1 instance. */
#define ALT_I2C1_COMP_TYPE_ADDR  ALT_I2C_COMP_TYPE_ADDR(ALT_I2C1_ADDR)
/* The base address byte offset for the start of the ALT_I2C1 component. */
#define ALT_I2C1_OFST        0xffc02300
/* The start address of the ALT_I2C1 component. */
#define ALT_I2C1_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_I2C1_OFST))
/* The lower bound address range of the ALT_I2C1 component. */
#define ALT_I2C1_LB_ADDR     ALT_I2C1_ADDR
/* The upper bound address range of the ALT_I2C1 component. */
#define ALT_I2C1_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_I2C1_ADDR) + 0x100) - 1))


/*
 * Component Instance : i_i2c_emac_0_i2c
 * 
 * Instance i_i2c_emac_0_i2c of component ALT_I2C.
 * 
 * 
 */
/* The address of the ALT_I2C_CON register for the ALT_I2C_EMAC_0_I2C instance. */
#define ALT_I2C_EMAC_0_I2C_CON_ADDR  ALT_I2C_CON_ADDR(ALT_I2C_EMAC_0_I2C_ADDR)
/* The address of the ALT_I2C_TAR register for the ALT_I2C_EMAC_0_I2C instance. */
#define ALT_I2C_EMAC_0_I2C_TAR_ADDR  ALT_I2C_TAR_ADDR(ALT_I2C_EMAC_0_I2C_ADDR)
/* The address of the ALT_I2C_SAR register for the ALT_I2C_EMAC_0_I2C instance. */
#define ALT_I2C_EMAC_0_I2C_SAR_ADDR  ALT_I2C_SAR_ADDR(ALT_I2C_EMAC_0_I2C_ADDR)
/* The address of the ALT_I2C_DATA_CMD register for the ALT_I2C_EMAC_0_I2C instance. */
#define ALT_I2C_EMAC_0_I2C_DATA_CMD_ADDR  ALT_I2C_DATA_CMD_ADDR(ALT_I2C_EMAC_0_I2C_ADDR)
/* The address of the ALT_I2C_SS_SCL_HCNT register for the ALT_I2C_EMAC_0_I2C instance. */
#define ALT_I2C_EMAC_0_I2C_SS_SCL_HCNT_ADDR  ALT_I2C_SS_SCL_HCNT_ADDR(ALT_I2C_EMAC_0_I2C_ADDR)
/* The address of the ALT_I2C_SS_SCL_LCNT register for the ALT_I2C_EMAC_0_I2C instance. */
#define ALT_I2C_EMAC_0_I2C_SS_SCL_LCNT_ADDR  ALT_I2C_SS_SCL_LCNT_ADDR(ALT_I2C_EMAC_0_I2C_ADDR)
/* The address of the ALT_I2C_FS_SCL_HCNT register for the ALT_I2C_EMAC_0_I2C instance. */
#define ALT_I2C_EMAC_0_I2C_FS_SCL_HCNT_ADDR  ALT_I2C_FS_SCL_HCNT_ADDR(ALT_I2C_EMAC_0_I2C_ADDR)
/* The address of the ALT_I2C_FS_SCL_LCNT register for the ALT_I2C_EMAC_0_I2C instance. */
#define ALT_I2C_EMAC_0_I2C_FS_SCL_LCNT_ADDR  ALT_I2C_FS_SCL_LCNT_ADDR(ALT_I2C_EMAC_0_I2C_ADDR)
/* The address of the ALT_I2C_INTR_STAT register for the ALT_I2C_EMAC_0_I2C instance. */
#define ALT_I2C_EMAC_0_I2C_INTR_STAT_ADDR  ALT_I2C_INTR_STAT_ADDR(ALT_I2C_EMAC_0_I2C_ADDR)
/* The address of the ALT_I2C_INTR_MSK register for the ALT_I2C_EMAC_0_I2C instance. */
#define ALT_I2C_EMAC_0_I2C_INTR_MSK_ADDR  ALT_I2C_INTR_MSK_ADDR(ALT_I2C_EMAC_0_I2C_ADDR)
/* The address of the ALT_I2C_RAW_INTR_STAT register for the ALT_I2C_EMAC_0_I2C instance. */
#define ALT_I2C_EMAC_0_I2C_RAW_INTR_STAT_ADDR  ALT_I2C_RAW_INTR_STAT_ADDR(ALT_I2C_EMAC_0_I2C_ADDR)
/* The address of the ALT_I2C_RX_TL register for the ALT_I2C_EMAC_0_I2C instance. */
#define ALT_I2C_EMAC_0_I2C_RX_TL_ADDR  ALT_I2C_RX_TL_ADDR(ALT_I2C_EMAC_0_I2C_ADDR)
/* The address of the ALT_I2C_TX_TL register for the ALT_I2C_EMAC_0_I2C instance. */
#define ALT_I2C_EMAC_0_I2C_TX_TL_ADDR  ALT_I2C_TX_TL_ADDR(ALT_I2C_EMAC_0_I2C_ADDR)
/* The address of the ALT_I2C_CLR_INTR register for the ALT_I2C_EMAC_0_I2C instance. */
#define ALT_I2C_EMAC_0_I2C_CLR_INTR_ADDR  ALT_I2C_CLR_INTR_ADDR(ALT_I2C_EMAC_0_I2C_ADDR)
/* The address of the ALT_I2C_CLR_RX_UNDER register for the ALT_I2C_EMAC_0_I2C instance. */
#define ALT_I2C_EMAC_0_I2C_CLR_RX_UNDER_ADDR  ALT_I2C_CLR_RX_UNDER_ADDR(ALT_I2C_EMAC_0_I2C_ADDR)
/* The address of the ALT_I2C_CLR_RX_OVER register for the ALT_I2C_EMAC_0_I2C instance. */
#define ALT_I2C_EMAC_0_I2C_CLR_RX_OVER_ADDR  ALT_I2C_CLR_RX_OVER_ADDR(ALT_I2C_EMAC_0_I2C_ADDR)
/* The address of the ALT_I2C_CLR_TX_OVER register for the ALT_I2C_EMAC_0_I2C instance. */
#define ALT_I2C_EMAC_0_I2C_CLR_TX_OVER_ADDR  ALT_I2C_CLR_TX_OVER_ADDR(ALT_I2C_EMAC_0_I2C_ADDR)
/* The address of the ALT_I2C_CLR_RD_REQ register for the ALT_I2C_EMAC_0_I2C instance. */
#define ALT_I2C_EMAC_0_I2C_CLR_RD_REQ_ADDR  ALT_I2C_CLR_RD_REQ_ADDR(ALT_I2C_EMAC_0_I2C_ADDR)
/* The address of the ALT_I2C_CLR_TX_ABRT register for the ALT_I2C_EMAC_0_I2C instance. */
#define ALT_I2C_EMAC_0_I2C_CLR_TX_ABRT_ADDR  ALT_I2C_CLR_TX_ABRT_ADDR(ALT_I2C_EMAC_0_I2C_ADDR)
/* The address of the ALT_I2C_CLR_RX_DONE register for the ALT_I2C_EMAC_0_I2C instance. */
#define ALT_I2C_EMAC_0_I2C_CLR_RX_DONE_ADDR  ALT_I2C_CLR_RX_DONE_ADDR(ALT_I2C_EMAC_0_I2C_ADDR)
/* The address of the ALT_I2C_CLR_ACTIVITY register for the ALT_I2C_EMAC_0_I2C instance. */
#define ALT_I2C_EMAC_0_I2C_CLR_ACTIVITY_ADDR  ALT_I2C_CLR_ACTIVITY_ADDR(ALT_I2C_EMAC_0_I2C_ADDR)
/* The address of the ALT_I2C_CLR_STOP_DET register for the ALT_I2C_EMAC_0_I2C instance. */
#define ALT_I2C_EMAC_0_I2C_CLR_STOP_DET_ADDR  ALT_I2C_CLR_STOP_DET_ADDR(ALT_I2C_EMAC_0_I2C_ADDR)
/* The address of the ALT_I2C_CLR_START_DET register for the ALT_I2C_EMAC_0_I2C instance. */
#define ALT_I2C_EMAC_0_I2C_CLR_START_DET_ADDR  ALT_I2C_CLR_START_DET_ADDR(ALT_I2C_EMAC_0_I2C_ADDR)
/* The address of the ALT_I2C_CLR_GEN_CALL register for the ALT_I2C_EMAC_0_I2C instance. */
#define ALT_I2C_EMAC_0_I2C_CLR_GEN_CALL_ADDR  ALT_I2C_CLR_GEN_CALL_ADDR(ALT_I2C_EMAC_0_I2C_ADDR)
/* The address of the ALT_I2C_EN register for the ALT_I2C_EMAC_0_I2C instance. */
#define ALT_I2C_EMAC_0_I2C_EN_ADDR  ALT_I2C_EN_ADDR(ALT_I2C_EMAC_0_I2C_ADDR)
/* The address of the ALT_I2C_STAT register for the ALT_I2C_EMAC_0_I2C instance. */
#define ALT_I2C_EMAC_0_I2C_STAT_ADDR  ALT_I2C_STAT_ADDR(ALT_I2C_EMAC_0_I2C_ADDR)
/* The address of the ALT_I2C_TXFLR register for the ALT_I2C_EMAC_0_I2C instance. */
#define ALT_I2C_EMAC_0_I2C_TXFLR_ADDR  ALT_I2C_TXFLR_ADDR(ALT_I2C_EMAC_0_I2C_ADDR)
/* The address of the ALT_I2C_RXFLR register for the ALT_I2C_EMAC_0_I2C instance. */
#define ALT_I2C_EMAC_0_I2C_RXFLR_ADDR  ALT_I2C_RXFLR_ADDR(ALT_I2C_EMAC_0_I2C_ADDR)
/* The address of the ALT_I2C_SDA_HOLD register for the ALT_I2C_EMAC_0_I2C instance. */
#define ALT_I2C_EMAC_0_I2C_SDA_HOLD_ADDR  ALT_I2C_SDA_HOLD_ADDR(ALT_I2C_EMAC_0_I2C_ADDR)
/* The address of the ALT_I2C_TX_ABRT_SRC register for the ALT_I2C_EMAC_0_I2C instance. */
#define ALT_I2C_EMAC_0_I2C_TX_ABRT_SRC_ADDR  ALT_I2C_TX_ABRT_SRC_ADDR(ALT_I2C_EMAC_0_I2C_ADDR)
/* The address of the ALT_I2C_SLV_DATA_NACK_ONLY register for the ALT_I2C_EMAC_0_I2C instance. */
#define ALT_I2C_EMAC_0_I2C_SLV_DATA_NACK_ONLY_ADDR  ALT_I2C_SLV_DATA_NACK_ONLY_ADDR(ALT_I2C_EMAC_0_I2C_ADDR)
/* The address of the ALT_I2C_DMA_CR register for the ALT_I2C_EMAC_0_I2C instance. */
#define ALT_I2C_EMAC_0_I2C_DMA_CR_ADDR  ALT_I2C_DMA_CR_ADDR(ALT_I2C_EMAC_0_I2C_ADDR)
/* The address of the ALT_I2C_DMA_TDLR register for the ALT_I2C_EMAC_0_I2C instance. */
#define ALT_I2C_EMAC_0_I2C_DMA_TDLR_ADDR  ALT_I2C_DMA_TDLR_ADDR(ALT_I2C_EMAC_0_I2C_ADDR)
/* The address of the ALT_I2C_DMA_RDLR register for the ALT_I2C_EMAC_0_I2C instance. */
#define ALT_I2C_EMAC_0_I2C_DMA_RDLR_ADDR  ALT_I2C_DMA_RDLR_ADDR(ALT_I2C_EMAC_0_I2C_ADDR)
/* The address of the ALT_I2C_SDA_SETUP register for the ALT_I2C_EMAC_0_I2C instance. */
#define ALT_I2C_EMAC_0_I2C_SDA_SETUP_ADDR  ALT_I2C_SDA_SETUP_ADDR(ALT_I2C_EMAC_0_I2C_ADDR)
/* The address of the ALT_I2C_ACK_GENERAL_CALL register for the ALT_I2C_EMAC_0_I2C instance. */
#define ALT_I2C_EMAC_0_I2C_ACK_GENERAL_CALL_ADDR  ALT_I2C_ACK_GENERAL_CALL_ADDR(ALT_I2C_EMAC_0_I2C_ADDR)
/* The address of the ALT_I2C_EN_STAT register for the ALT_I2C_EMAC_0_I2C instance. */
#define ALT_I2C_EMAC_0_I2C_EN_STAT_ADDR  ALT_I2C_EN_STAT_ADDR(ALT_I2C_EMAC_0_I2C_ADDR)
/* The address of the ALT_I2C_FS_SPKLEN register for the ALT_I2C_EMAC_0_I2C instance. */
#define ALT_I2C_EMAC_0_I2C_FS_SPKLEN_ADDR  ALT_I2C_FS_SPKLEN_ADDR(ALT_I2C_EMAC_0_I2C_ADDR)
/* The address of the ALT_I2C_CLR_RESTART_DET register for the ALT_I2C_EMAC_0_I2C instance. */
#define ALT_I2C_EMAC_0_I2C_CLR_RESTART_DET_ADDR  ALT_I2C_CLR_RESTART_DET_ADDR(ALT_I2C_EMAC_0_I2C_ADDR)
/* The address of the ALT_I2C_COMP_PARAM_1 register for the ALT_I2C_EMAC_0_I2C instance. */
#define ALT_I2C_EMAC_0_I2C_COMP_PARAM_1_ADDR  ALT_I2C_COMP_PARAM_1_ADDR(ALT_I2C_EMAC_0_I2C_ADDR)
/* The address of the ALT_I2C_COMP_VER register for the ALT_I2C_EMAC_0_I2C instance. */
#define ALT_I2C_EMAC_0_I2C_COMP_VER_ADDR  ALT_I2C_COMP_VER_ADDR(ALT_I2C_EMAC_0_I2C_ADDR)
/* The address of the ALT_I2C_COMP_TYPE register for the ALT_I2C_EMAC_0_I2C instance. */
#define ALT_I2C_EMAC_0_I2C_COMP_TYPE_ADDR  ALT_I2C_COMP_TYPE_ADDR(ALT_I2C_EMAC_0_I2C_ADDR)
/* The base address byte offset for the start of the ALT_I2C_EMAC_0_I2C component. */
#define ALT_I2C_EMAC_0_I2C_OFST        0xffc02400
/* The start address of the ALT_I2C_EMAC_0_I2C component. */
#define ALT_I2C_EMAC_0_I2C_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_I2C_EMAC_0_I2C_OFST))
/* The lower bound address range of the ALT_I2C_EMAC_0_I2C component. */
#define ALT_I2C_EMAC_0_I2C_LB_ADDR     ALT_I2C_EMAC_0_I2C_ADDR
/* The upper bound address range of the ALT_I2C_EMAC_0_I2C component. */
#define ALT_I2C_EMAC_0_I2C_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_I2C_EMAC_0_I2C_ADDR) + 0x100) - 1))


/*
 * Component Instance : i_i2c_emac_1_i2c
 * 
 * Instance i_i2c_emac_1_i2c of component ALT_I2C.
 * 
 * 
 */
/* The address of the ALT_I2C_CON register for the ALT_I2C_EMAC_1_I2C instance. */
#define ALT_I2C_EMAC_1_I2C_CON_ADDR  ALT_I2C_CON_ADDR(ALT_I2C_EMAC_1_I2C_ADDR)
/* The address of the ALT_I2C_TAR register for the ALT_I2C_EMAC_1_I2C instance. */
#define ALT_I2C_EMAC_1_I2C_TAR_ADDR  ALT_I2C_TAR_ADDR(ALT_I2C_EMAC_1_I2C_ADDR)
/* The address of the ALT_I2C_SAR register for the ALT_I2C_EMAC_1_I2C instance. */
#define ALT_I2C_EMAC_1_I2C_SAR_ADDR  ALT_I2C_SAR_ADDR(ALT_I2C_EMAC_1_I2C_ADDR)
/* The address of the ALT_I2C_DATA_CMD register for the ALT_I2C_EMAC_1_I2C instance. */
#define ALT_I2C_EMAC_1_I2C_DATA_CMD_ADDR  ALT_I2C_DATA_CMD_ADDR(ALT_I2C_EMAC_1_I2C_ADDR)
/* The address of the ALT_I2C_SS_SCL_HCNT register for the ALT_I2C_EMAC_1_I2C instance. */
#define ALT_I2C_EMAC_1_I2C_SS_SCL_HCNT_ADDR  ALT_I2C_SS_SCL_HCNT_ADDR(ALT_I2C_EMAC_1_I2C_ADDR)
/* The address of the ALT_I2C_SS_SCL_LCNT register for the ALT_I2C_EMAC_1_I2C instance. */
#define ALT_I2C_EMAC_1_I2C_SS_SCL_LCNT_ADDR  ALT_I2C_SS_SCL_LCNT_ADDR(ALT_I2C_EMAC_1_I2C_ADDR)
/* The address of the ALT_I2C_FS_SCL_HCNT register for the ALT_I2C_EMAC_1_I2C instance. */
#define ALT_I2C_EMAC_1_I2C_FS_SCL_HCNT_ADDR  ALT_I2C_FS_SCL_HCNT_ADDR(ALT_I2C_EMAC_1_I2C_ADDR)
/* The address of the ALT_I2C_FS_SCL_LCNT register for the ALT_I2C_EMAC_1_I2C instance. */
#define ALT_I2C_EMAC_1_I2C_FS_SCL_LCNT_ADDR  ALT_I2C_FS_SCL_LCNT_ADDR(ALT_I2C_EMAC_1_I2C_ADDR)
/* The address of the ALT_I2C_INTR_STAT register for the ALT_I2C_EMAC_1_I2C instance. */
#define ALT_I2C_EMAC_1_I2C_INTR_STAT_ADDR  ALT_I2C_INTR_STAT_ADDR(ALT_I2C_EMAC_1_I2C_ADDR)
/* The address of the ALT_I2C_INTR_MSK register for the ALT_I2C_EMAC_1_I2C instance. */
#define ALT_I2C_EMAC_1_I2C_INTR_MSK_ADDR  ALT_I2C_INTR_MSK_ADDR(ALT_I2C_EMAC_1_I2C_ADDR)
/* The address of the ALT_I2C_RAW_INTR_STAT register for the ALT_I2C_EMAC_1_I2C instance. */
#define ALT_I2C_EMAC_1_I2C_RAW_INTR_STAT_ADDR  ALT_I2C_RAW_INTR_STAT_ADDR(ALT_I2C_EMAC_1_I2C_ADDR)
/* The address of the ALT_I2C_RX_TL register for the ALT_I2C_EMAC_1_I2C instance. */
#define ALT_I2C_EMAC_1_I2C_RX_TL_ADDR  ALT_I2C_RX_TL_ADDR(ALT_I2C_EMAC_1_I2C_ADDR)
/* The address of the ALT_I2C_TX_TL register for the ALT_I2C_EMAC_1_I2C instance. */
#define ALT_I2C_EMAC_1_I2C_TX_TL_ADDR  ALT_I2C_TX_TL_ADDR(ALT_I2C_EMAC_1_I2C_ADDR)
/* The address of the ALT_I2C_CLR_INTR register for the ALT_I2C_EMAC_1_I2C instance. */
#define ALT_I2C_EMAC_1_I2C_CLR_INTR_ADDR  ALT_I2C_CLR_INTR_ADDR(ALT_I2C_EMAC_1_I2C_ADDR)
/* The address of the ALT_I2C_CLR_RX_UNDER register for the ALT_I2C_EMAC_1_I2C instance. */
#define ALT_I2C_EMAC_1_I2C_CLR_RX_UNDER_ADDR  ALT_I2C_CLR_RX_UNDER_ADDR(ALT_I2C_EMAC_1_I2C_ADDR)
/* The address of the ALT_I2C_CLR_RX_OVER register for the ALT_I2C_EMAC_1_I2C instance. */
#define ALT_I2C_EMAC_1_I2C_CLR_RX_OVER_ADDR  ALT_I2C_CLR_RX_OVER_ADDR(ALT_I2C_EMAC_1_I2C_ADDR)
/* The address of the ALT_I2C_CLR_TX_OVER register for the ALT_I2C_EMAC_1_I2C instance. */
#define ALT_I2C_EMAC_1_I2C_CLR_TX_OVER_ADDR  ALT_I2C_CLR_TX_OVER_ADDR(ALT_I2C_EMAC_1_I2C_ADDR)
/* The address of the ALT_I2C_CLR_RD_REQ register for the ALT_I2C_EMAC_1_I2C instance. */
#define ALT_I2C_EMAC_1_I2C_CLR_RD_REQ_ADDR  ALT_I2C_CLR_RD_REQ_ADDR(ALT_I2C_EMAC_1_I2C_ADDR)
/* The address of the ALT_I2C_CLR_TX_ABRT register for the ALT_I2C_EMAC_1_I2C instance. */
#define ALT_I2C_EMAC_1_I2C_CLR_TX_ABRT_ADDR  ALT_I2C_CLR_TX_ABRT_ADDR(ALT_I2C_EMAC_1_I2C_ADDR)
/* The address of the ALT_I2C_CLR_RX_DONE register for the ALT_I2C_EMAC_1_I2C instance. */
#define ALT_I2C_EMAC_1_I2C_CLR_RX_DONE_ADDR  ALT_I2C_CLR_RX_DONE_ADDR(ALT_I2C_EMAC_1_I2C_ADDR)
/* The address of the ALT_I2C_CLR_ACTIVITY register for the ALT_I2C_EMAC_1_I2C instance. */
#define ALT_I2C_EMAC_1_I2C_CLR_ACTIVITY_ADDR  ALT_I2C_CLR_ACTIVITY_ADDR(ALT_I2C_EMAC_1_I2C_ADDR)
/* The address of the ALT_I2C_CLR_STOP_DET register for the ALT_I2C_EMAC_1_I2C instance. */
#define ALT_I2C_EMAC_1_I2C_CLR_STOP_DET_ADDR  ALT_I2C_CLR_STOP_DET_ADDR(ALT_I2C_EMAC_1_I2C_ADDR)
/* The address of the ALT_I2C_CLR_START_DET register for the ALT_I2C_EMAC_1_I2C instance. */
#define ALT_I2C_EMAC_1_I2C_CLR_START_DET_ADDR  ALT_I2C_CLR_START_DET_ADDR(ALT_I2C_EMAC_1_I2C_ADDR)
/* The address of the ALT_I2C_CLR_GEN_CALL register for the ALT_I2C_EMAC_1_I2C instance. */
#define ALT_I2C_EMAC_1_I2C_CLR_GEN_CALL_ADDR  ALT_I2C_CLR_GEN_CALL_ADDR(ALT_I2C_EMAC_1_I2C_ADDR)
/* The address of the ALT_I2C_EN register for the ALT_I2C_EMAC_1_I2C instance. */
#define ALT_I2C_EMAC_1_I2C_EN_ADDR  ALT_I2C_EN_ADDR(ALT_I2C_EMAC_1_I2C_ADDR)
/* The address of the ALT_I2C_STAT register for the ALT_I2C_EMAC_1_I2C instance. */
#define ALT_I2C_EMAC_1_I2C_STAT_ADDR  ALT_I2C_STAT_ADDR(ALT_I2C_EMAC_1_I2C_ADDR)
/* The address of the ALT_I2C_TXFLR register for the ALT_I2C_EMAC_1_I2C instance. */
#define ALT_I2C_EMAC_1_I2C_TXFLR_ADDR  ALT_I2C_TXFLR_ADDR(ALT_I2C_EMAC_1_I2C_ADDR)
/* The address of the ALT_I2C_RXFLR register for the ALT_I2C_EMAC_1_I2C instance. */
#define ALT_I2C_EMAC_1_I2C_RXFLR_ADDR  ALT_I2C_RXFLR_ADDR(ALT_I2C_EMAC_1_I2C_ADDR)
/* The address of the ALT_I2C_SDA_HOLD register for the ALT_I2C_EMAC_1_I2C instance. */
#define ALT_I2C_EMAC_1_I2C_SDA_HOLD_ADDR  ALT_I2C_SDA_HOLD_ADDR(ALT_I2C_EMAC_1_I2C_ADDR)
/* The address of the ALT_I2C_TX_ABRT_SRC register for the ALT_I2C_EMAC_1_I2C instance. */
#define ALT_I2C_EMAC_1_I2C_TX_ABRT_SRC_ADDR  ALT_I2C_TX_ABRT_SRC_ADDR(ALT_I2C_EMAC_1_I2C_ADDR)
/* The address of the ALT_I2C_SLV_DATA_NACK_ONLY register for the ALT_I2C_EMAC_1_I2C instance. */
#define ALT_I2C_EMAC_1_I2C_SLV_DATA_NACK_ONLY_ADDR  ALT_I2C_SLV_DATA_NACK_ONLY_ADDR(ALT_I2C_EMAC_1_I2C_ADDR)
/* The address of the ALT_I2C_DMA_CR register for the ALT_I2C_EMAC_1_I2C instance. */
#define ALT_I2C_EMAC_1_I2C_DMA_CR_ADDR  ALT_I2C_DMA_CR_ADDR(ALT_I2C_EMAC_1_I2C_ADDR)
/* The address of the ALT_I2C_DMA_TDLR register for the ALT_I2C_EMAC_1_I2C instance. */
#define ALT_I2C_EMAC_1_I2C_DMA_TDLR_ADDR  ALT_I2C_DMA_TDLR_ADDR(ALT_I2C_EMAC_1_I2C_ADDR)
/* The address of the ALT_I2C_DMA_RDLR register for the ALT_I2C_EMAC_1_I2C instance. */
#define ALT_I2C_EMAC_1_I2C_DMA_RDLR_ADDR  ALT_I2C_DMA_RDLR_ADDR(ALT_I2C_EMAC_1_I2C_ADDR)
/* The address of the ALT_I2C_SDA_SETUP register for the ALT_I2C_EMAC_1_I2C instance. */
#define ALT_I2C_EMAC_1_I2C_SDA_SETUP_ADDR  ALT_I2C_SDA_SETUP_ADDR(ALT_I2C_EMAC_1_I2C_ADDR)
/* The address of the ALT_I2C_ACK_GENERAL_CALL register for the ALT_I2C_EMAC_1_I2C instance. */
#define ALT_I2C_EMAC_1_I2C_ACK_GENERAL_CALL_ADDR  ALT_I2C_ACK_GENERAL_CALL_ADDR(ALT_I2C_EMAC_1_I2C_ADDR)
/* The address of the ALT_I2C_EN_STAT register for the ALT_I2C_EMAC_1_I2C instance. */
#define ALT_I2C_EMAC_1_I2C_EN_STAT_ADDR  ALT_I2C_EN_STAT_ADDR(ALT_I2C_EMAC_1_I2C_ADDR)
/* The address of the ALT_I2C_FS_SPKLEN register for the ALT_I2C_EMAC_1_I2C instance. */
#define ALT_I2C_EMAC_1_I2C_FS_SPKLEN_ADDR  ALT_I2C_FS_SPKLEN_ADDR(ALT_I2C_EMAC_1_I2C_ADDR)
/* The address of the ALT_I2C_CLR_RESTART_DET register for the ALT_I2C_EMAC_1_I2C instance. */
#define ALT_I2C_EMAC_1_I2C_CLR_RESTART_DET_ADDR  ALT_I2C_CLR_RESTART_DET_ADDR(ALT_I2C_EMAC_1_I2C_ADDR)
/* The address of the ALT_I2C_COMP_PARAM_1 register for the ALT_I2C_EMAC_1_I2C instance. */
#define ALT_I2C_EMAC_1_I2C_COMP_PARAM_1_ADDR  ALT_I2C_COMP_PARAM_1_ADDR(ALT_I2C_EMAC_1_I2C_ADDR)
/* The address of the ALT_I2C_COMP_VER register for the ALT_I2C_EMAC_1_I2C instance. */
#define ALT_I2C_EMAC_1_I2C_COMP_VER_ADDR  ALT_I2C_COMP_VER_ADDR(ALT_I2C_EMAC_1_I2C_ADDR)
/* The address of the ALT_I2C_COMP_TYPE register for the ALT_I2C_EMAC_1_I2C instance. */
#define ALT_I2C_EMAC_1_I2C_COMP_TYPE_ADDR  ALT_I2C_COMP_TYPE_ADDR(ALT_I2C_EMAC_1_I2C_ADDR)
/* The base address byte offset for the start of the ALT_I2C_EMAC_1_I2C component. */
#define ALT_I2C_EMAC_1_I2C_OFST        0xffc02500
/* The start address of the ALT_I2C_EMAC_1_I2C component. */
#define ALT_I2C_EMAC_1_I2C_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_I2C_EMAC_1_I2C_OFST))
/* The lower bound address range of the ALT_I2C_EMAC_1_I2C component. */
#define ALT_I2C_EMAC_1_I2C_LB_ADDR     ALT_I2C_EMAC_1_I2C_ADDR
/* The upper bound address range of the ALT_I2C_EMAC_1_I2C component. */
#define ALT_I2C_EMAC_1_I2C_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_I2C_EMAC_1_I2C_ADDR) + 0x100) - 1))


/*
 * Component Instance : i_i2c_emac_2_i2c
 * 
 * Instance i_i2c_emac_2_i2c of component ALT_I2C.
 * 
 * 
 */
/* The address of the ALT_I2C_CON register for the ALT_I2C_EMAC_2_I2C instance. */
#define ALT_I2C_EMAC_2_I2C_CON_ADDR  ALT_I2C_CON_ADDR(ALT_I2C_EMAC_2_I2C_ADDR)
/* The address of the ALT_I2C_TAR register for the ALT_I2C_EMAC_2_I2C instance. */
#define ALT_I2C_EMAC_2_I2C_TAR_ADDR  ALT_I2C_TAR_ADDR(ALT_I2C_EMAC_2_I2C_ADDR)
/* The address of the ALT_I2C_SAR register for the ALT_I2C_EMAC_2_I2C instance. */
#define ALT_I2C_EMAC_2_I2C_SAR_ADDR  ALT_I2C_SAR_ADDR(ALT_I2C_EMAC_2_I2C_ADDR)
/* The address of the ALT_I2C_DATA_CMD register for the ALT_I2C_EMAC_2_I2C instance. */
#define ALT_I2C_EMAC_2_I2C_DATA_CMD_ADDR  ALT_I2C_DATA_CMD_ADDR(ALT_I2C_EMAC_2_I2C_ADDR)
/* The address of the ALT_I2C_SS_SCL_HCNT register for the ALT_I2C_EMAC_2_I2C instance. */
#define ALT_I2C_EMAC_2_I2C_SS_SCL_HCNT_ADDR  ALT_I2C_SS_SCL_HCNT_ADDR(ALT_I2C_EMAC_2_I2C_ADDR)
/* The address of the ALT_I2C_SS_SCL_LCNT register for the ALT_I2C_EMAC_2_I2C instance. */
#define ALT_I2C_EMAC_2_I2C_SS_SCL_LCNT_ADDR  ALT_I2C_SS_SCL_LCNT_ADDR(ALT_I2C_EMAC_2_I2C_ADDR)
/* The address of the ALT_I2C_FS_SCL_HCNT register for the ALT_I2C_EMAC_2_I2C instance. */
#define ALT_I2C_EMAC_2_I2C_FS_SCL_HCNT_ADDR  ALT_I2C_FS_SCL_HCNT_ADDR(ALT_I2C_EMAC_2_I2C_ADDR)
/* The address of the ALT_I2C_FS_SCL_LCNT register for the ALT_I2C_EMAC_2_I2C instance. */
#define ALT_I2C_EMAC_2_I2C_FS_SCL_LCNT_ADDR  ALT_I2C_FS_SCL_LCNT_ADDR(ALT_I2C_EMAC_2_I2C_ADDR)
/* The address of the ALT_I2C_INTR_STAT register for the ALT_I2C_EMAC_2_I2C instance. */
#define ALT_I2C_EMAC_2_I2C_INTR_STAT_ADDR  ALT_I2C_INTR_STAT_ADDR(ALT_I2C_EMAC_2_I2C_ADDR)
/* The address of the ALT_I2C_INTR_MSK register for the ALT_I2C_EMAC_2_I2C instance. */
#define ALT_I2C_EMAC_2_I2C_INTR_MSK_ADDR  ALT_I2C_INTR_MSK_ADDR(ALT_I2C_EMAC_2_I2C_ADDR)
/* The address of the ALT_I2C_RAW_INTR_STAT register for the ALT_I2C_EMAC_2_I2C instance. */
#define ALT_I2C_EMAC_2_I2C_RAW_INTR_STAT_ADDR  ALT_I2C_RAW_INTR_STAT_ADDR(ALT_I2C_EMAC_2_I2C_ADDR)
/* The address of the ALT_I2C_RX_TL register for the ALT_I2C_EMAC_2_I2C instance. */
#define ALT_I2C_EMAC_2_I2C_RX_TL_ADDR  ALT_I2C_RX_TL_ADDR(ALT_I2C_EMAC_2_I2C_ADDR)
/* The address of the ALT_I2C_TX_TL register for the ALT_I2C_EMAC_2_I2C instance. */
#define ALT_I2C_EMAC_2_I2C_TX_TL_ADDR  ALT_I2C_TX_TL_ADDR(ALT_I2C_EMAC_2_I2C_ADDR)
/* The address of the ALT_I2C_CLR_INTR register for the ALT_I2C_EMAC_2_I2C instance. */
#define ALT_I2C_EMAC_2_I2C_CLR_INTR_ADDR  ALT_I2C_CLR_INTR_ADDR(ALT_I2C_EMAC_2_I2C_ADDR)
/* The address of the ALT_I2C_CLR_RX_UNDER register for the ALT_I2C_EMAC_2_I2C instance. */
#define ALT_I2C_EMAC_2_I2C_CLR_RX_UNDER_ADDR  ALT_I2C_CLR_RX_UNDER_ADDR(ALT_I2C_EMAC_2_I2C_ADDR)
/* The address of the ALT_I2C_CLR_RX_OVER register for the ALT_I2C_EMAC_2_I2C instance. */
#define ALT_I2C_EMAC_2_I2C_CLR_RX_OVER_ADDR  ALT_I2C_CLR_RX_OVER_ADDR(ALT_I2C_EMAC_2_I2C_ADDR)
/* The address of the ALT_I2C_CLR_TX_OVER register for the ALT_I2C_EMAC_2_I2C instance. */
#define ALT_I2C_EMAC_2_I2C_CLR_TX_OVER_ADDR  ALT_I2C_CLR_TX_OVER_ADDR(ALT_I2C_EMAC_2_I2C_ADDR)
/* The address of the ALT_I2C_CLR_RD_REQ register for the ALT_I2C_EMAC_2_I2C instance. */
#define ALT_I2C_EMAC_2_I2C_CLR_RD_REQ_ADDR  ALT_I2C_CLR_RD_REQ_ADDR(ALT_I2C_EMAC_2_I2C_ADDR)
/* The address of the ALT_I2C_CLR_TX_ABRT register for the ALT_I2C_EMAC_2_I2C instance. */
#define ALT_I2C_EMAC_2_I2C_CLR_TX_ABRT_ADDR  ALT_I2C_CLR_TX_ABRT_ADDR(ALT_I2C_EMAC_2_I2C_ADDR)
/* The address of the ALT_I2C_CLR_RX_DONE register for the ALT_I2C_EMAC_2_I2C instance. */
#define ALT_I2C_EMAC_2_I2C_CLR_RX_DONE_ADDR  ALT_I2C_CLR_RX_DONE_ADDR(ALT_I2C_EMAC_2_I2C_ADDR)
/* The address of the ALT_I2C_CLR_ACTIVITY register for the ALT_I2C_EMAC_2_I2C instance. */
#define ALT_I2C_EMAC_2_I2C_CLR_ACTIVITY_ADDR  ALT_I2C_CLR_ACTIVITY_ADDR(ALT_I2C_EMAC_2_I2C_ADDR)
/* The address of the ALT_I2C_CLR_STOP_DET register for the ALT_I2C_EMAC_2_I2C instance. */
#define ALT_I2C_EMAC_2_I2C_CLR_STOP_DET_ADDR  ALT_I2C_CLR_STOP_DET_ADDR(ALT_I2C_EMAC_2_I2C_ADDR)
/* The address of the ALT_I2C_CLR_START_DET register for the ALT_I2C_EMAC_2_I2C instance. */
#define ALT_I2C_EMAC_2_I2C_CLR_START_DET_ADDR  ALT_I2C_CLR_START_DET_ADDR(ALT_I2C_EMAC_2_I2C_ADDR)
/* The address of the ALT_I2C_CLR_GEN_CALL register for the ALT_I2C_EMAC_2_I2C instance. */
#define ALT_I2C_EMAC_2_I2C_CLR_GEN_CALL_ADDR  ALT_I2C_CLR_GEN_CALL_ADDR(ALT_I2C_EMAC_2_I2C_ADDR)
/* The address of the ALT_I2C_EN register for the ALT_I2C_EMAC_2_I2C instance. */
#define ALT_I2C_EMAC_2_I2C_EN_ADDR  ALT_I2C_EN_ADDR(ALT_I2C_EMAC_2_I2C_ADDR)
/* The address of the ALT_I2C_STAT register for the ALT_I2C_EMAC_2_I2C instance. */
#define ALT_I2C_EMAC_2_I2C_STAT_ADDR  ALT_I2C_STAT_ADDR(ALT_I2C_EMAC_2_I2C_ADDR)
/* The address of the ALT_I2C_TXFLR register for the ALT_I2C_EMAC_2_I2C instance. */
#define ALT_I2C_EMAC_2_I2C_TXFLR_ADDR  ALT_I2C_TXFLR_ADDR(ALT_I2C_EMAC_2_I2C_ADDR)
/* The address of the ALT_I2C_RXFLR register for the ALT_I2C_EMAC_2_I2C instance. */
#define ALT_I2C_EMAC_2_I2C_RXFLR_ADDR  ALT_I2C_RXFLR_ADDR(ALT_I2C_EMAC_2_I2C_ADDR)
/* The address of the ALT_I2C_SDA_HOLD register for the ALT_I2C_EMAC_2_I2C instance. */
#define ALT_I2C_EMAC_2_I2C_SDA_HOLD_ADDR  ALT_I2C_SDA_HOLD_ADDR(ALT_I2C_EMAC_2_I2C_ADDR)
/* The address of the ALT_I2C_TX_ABRT_SRC register for the ALT_I2C_EMAC_2_I2C instance. */
#define ALT_I2C_EMAC_2_I2C_TX_ABRT_SRC_ADDR  ALT_I2C_TX_ABRT_SRC_ADDR(ALT_I2C_EMAC_2_I2C_ADDR)
/* The address of the ALT_I2C_SLV_DATA_NACK_ONLY register for the ALT_I2C_EMAC_2_I2C instance. */
#define ALT_I2C_EMAC_2_I2C_SLV_DATA_NACK_ONLY_ADDR  ALT_I2C_SLV_DATA_NACK_ONLY_ADDR(ALT_I2C_EMAC_2_I2C_ADDR)
/* The address of the ALT_I2C_DMA_CR register for the ALT_I2C_EMAC_2_I2C instance. */
#define ALT_I2C_EMAC_2_I2C_DMA_CR_ADDR  ALT_I2C_DMA_CR_ADDR(ALT_I2C_EMAC_2_I2C_ADDR)
/* The address of the ALT_I2C_DMA_TDLR register for the ALT_I2C_EMAC_2_I2C instance. */
#define ALT_I2C_EMAC_2_I2C_DMA_TDLR_ADDR  ALT_I2C_DMA_TDLR_ADDR(ALT_I2C_EMAC_2_I2C_ADDR)
/* The address of the ALT_I2C_DMA_RDLR register for the ALT_I2C_EMAC_2_I2C instance. */
#define ALT_I2C_EMAC_2_I2C_DMA_RDLR_ADDR  ALT_I2C_DMA_RDLR_ADDR(ALT_I2C_EMAC_2_I2C_ADDR)
/* The address of the ALT_I2C_SDA_SETUP register for the ALT_I2C_EMAC_2_I2C instance. */
#define ALT_I2C_EMAC_2_I2C_SDA_SETUP_ADDR  ALT_I2C_SDA_SETUP_ADDR(ALT_I2C_EMAC_2_I2C_ADDR)
/* The address of the ALT_I2C_ACK_GENERAL_CALL register for the ALT_I2C_EMAC_2_I2C instance. */
#define ALT_I2C_EMAC_2_I2C_ACK_GENERAL_CALL_ADDR  ALT_I2C_ACK_GENERAL_CALL_ADDR(ALT_I2C_EMAC_2_I2C_ADDR)
/* The address of the ALT_I2C_EN_STAT register for the ALT_I2C_EMAC_2_I2C instance. */
#define ALT_I2C_EMAC_2_I2C_EN_STAT_ADDR  ALT_I2C_EN_STAT_ADDR(ALT_I2C_EMAC_2_I2C_ADDR)
/* The address of the ALT_I2C_FS_SPKLEN register for the ALT_I2C_EMAC_2_I2C instance. */
#define ALT_I2C_EMAC_2_I2C_FS_SPKLEN_ADDR  ALT_I2C_FS_SPKLEN_ADDR(ALT_I2C_EMAC_2_I2C_ADDR)
/* The address of the ALT_I2C_CLR_RESTART_DET register for the ALT_I2C_EMAC_2_I2C instance. */
#define ALT_I2C_EMAC_2_I2C_CLR_RESTART_DET_ADDR  ALT_I2C_CLR_RESTART_DET_ADDR(ALT_I2C_EMAC_2_I2C_ADDR)
/* The address of the ALT_I2C_COMP_PARAM_1 register for the ALT_I2C_EMAC_2_I2C instance. */
#define ALT_I2C_EMAC_2_I2C_COMP_PARAM_1_ADDR  ALT_I2C_COMP_PARAM_1_ADDR(ALT_I2C_EMAC_2_I2C_ADDR)
/* The address of the ALT_I2C_COMP_VER register for the ALT_I2C_EMAC_2_I2C instance. */
#define ALT_I2C_EMAC_2_I2C_COMP_VER_ADDR  ALT_I2C_COMP_VER_ADDR(ALT_I2C_EMAC_2_I2C_ADDR)
/* The address of the ALT_I2C_COMP_TYPE register for the ALT_I2C_EMAC_2_I2C instance. */
#define ALT_I2C_EMAC_2_I2C_COMP_TYPE_ADDR  ALT_I2C_COMP_TYPE_ADDR(ALT_I2C_EMAC_2_I2C_ADDR)
/* The base address byte offset for the start of the ALT_I2C_EMAC_2_I2C component. */
#define ALT_I2C_EMAC_2_I2C_OFST        0xffc02600
/* The start address of the ALT_I2C_EMAC_2_I2C component. */
#define ALT_I2C_EMAC_2_I2C_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_I2C_EMAC_2_I2C_OFST))
/* The lower bound address range of the ALT_I2C_EMAC_2_I2C component. */
#define ALT_I2C_EMAC_2_I2C_LB_ADDR     ALT_I2C_EMAC_2_I2C_ADDR
/* The upper bound address range of the ALT_I2C_EMAC_2_I2C component. */
#define ALT_I2C_EMAC_2_I2C_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_I2C_EMAC_2_I2C_ADDR) + 0x100) - 1))


/*
 * Component Instance : i_timer_sp_0_timer
 * 
 * Instance i_timer_sp_0_timer of component ALT_TMR.
 * 
 * 
 */
/* The address of the ALT_TMR_TMR1LDCOUNT register for the ALT_SPTMR0 instance. */
#define ALT_SPTMR0_TMR1LDCOUNT_ADDR  ALT_TMR_TMR1LDCOUNT_ADDR(ALT_SPTMR0_ADDR)
/* The address of the ALT_TMR_TMR1CURVAL register for the ALT_SPTMR0 instance. */
#define ALT_SPTMR0_TMR1CURVAL_ADDR  ALT_TMR_TMR1CURVAL_ADDR(ALT_SPTMR0_ADDR)
/* The address of the ALT_TMR_TMR1CTLREG register for the ALT_SPTMR0 instance. */
#define ALT_SPTMR0_TMR1CTLREG_ADDR  ALT_TMR_TMR1CTLREG_ADDR(ALT_SPTMR0_ADDR)
/* The address of the ALT_TMR_TMR1EOI register for the ALT_SPTMR0 instance. */
#define ALT_SPTMR0_TMR1EOI_ADDR  ALT_TMR_TMR1EOI_ADDR(ALT_SPTMR0_ADDR)
/* The address of the ALT_TMR_TMR1INTSTAT register for the ALT_SPTMR0 instance. */
#define ALT_SPTMR0_TMR1INTSTAT_ADDR  ALT_TMR_TMR1INTSTAT_ADDR(ALT_SPTMR0_ADDR)
/* The address of the ALT_TMR_TMRSINTSTAT register for the ALT_SPTMR0 instance. */
#define ALT_SPTMR0_TMRSINTSTAT_ADDR  ALT_TMR_TMRSINTSTAT_ADDR(ALT_SPTMR0_ADDR)
/* The address of the ALT_TMR_TMRSEOI register for the ALT_SPTMR0 instance. */
#define ALT_SPTMR0_TMRSEOI_ADDR  ALT_TMR_TMRSEOI_ADDR(ALT_SPTMR0_ADDR)
/* The address of the ALT_TMR_TMRSRAWINTSTAT register for the ALT_SPTMR0 instance. */
#define ALT_SPTMR0_TMRSRAWINTSTAT_ADDR  ALT_TMR_TMRSRAWINTSTAT_ADDR(ALT_SPTMR0_ADDR)
/* The address of the ALT_TMR_TMRSCOMPVER register for the ALT_SPTMR0 instance. */
#define ALT_SPTMR0_TMRSCOMPVER_ADDR  ALT_TMR_TMRSCOMPVER_ADDR(ALT_SPTMR0_ADDR)
/* The base address byte offset for the start of the ALT_SPTMR0 component. */
#define ALT_SPTMR0_OFST        0xffc02700
/* The start address of the ALT_SPTMR0 component. */
#define ALT_SPTMR0_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_SPTMR0_OFST))
/* The lower bound address range of the ALT_SPTMR0 component. */
#define ALT_SPTMR0_LB_ADDR     ALT_SPTMR0_ADDR
/* The upper bound address range of the ALT_SPTMR0 component. */
#define ALT_SPTMR0_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_SPTMR0_ADDR) + 0x100) - 1))


/*
 * Component Instance : i_timer_sp_1_timer
 * 
 * Instance i_timer_sp_1_timer of component ALT_TMR.
 * 
 * 
 */
/* The address of the ALT_TMR_TMR1LDCOUNT register for the ALT_SPTMR1 instance. */
#define ALT_SPTMR1_TMR1LDCOUNT_ADDR  ALT_TMR_TMR1LDCOUNT_ADDR(ALT_SPTMR1_ADDR)
/* The address of the ALT_TMR_TMR1CURVAL register for the ALT_SPTMR1 instance. */
#define ALT_SPTMR1_TMR1CURVAL_ADDR  ALT_TMR_TMR1CURVAL_ADDR(ALT_SPTMR1_ADDR)
/* The address of the ALT_TMR_TMR1CTLREG register for the ALT_SPTMR1 instance. */
#define ALT_SPTMR1_TMR1CTLREG_ADDR  ALT_TMR_TMR1CTLREG_ADDR(ALT_SPTMR1_ADDR)
/* The address of the ALT_TMR_TMR1EOI register for the ALT_SPTMR1 instance. */
#define ALT_SPTMR1_TMR1EOI_ADDR  ALT_TMR_TMR1EOI_ADDR(ALT_SPTMR1_ADDR)
/* The address of the ALT_TMR_TMR1INTSTAT register for the ALT_SPTMR1 instance. */
#define ALT_SPTMR1_TMR1INTSTAT_ADDR  ALT_TMR_TMR1INTSTAT_ADDR(ALT_SPTMR1_ADDR)
/* The address of the ALT_TMR_TMRSINTSTAT register for the ALT_SPTMR1 instance. */
#define ALT_SPTMR1_TMRSINTSTAT_ADDR  ALT_TMR_TMRSINTSTAT_ADDR(ALT_SPTMR1_ADDR)
/* The address of the ALT_TMR_TMRSEOI register for the ALT_SPTMR1 instance. */
#define ALT_SPTMR1_TMRSEOI_ADDR  ALT_TMR_TMRSEOI_ADDR(ALT_SPTMR1_ADDR)
/* The address of the ALT_TMR_TMRSRAWINTSTAT register for the ALT_SPTMR1 instance. */
#define ALT_SPTMR1_TMRSRAWINTSTAT_ADDR  ALT_TMR_TMRSRAWINTSTAT_ADDR(ALT_SPTMR1_ADDR)
/* The address of the ALT_TMR_TMRSCOMPVER register for the ALT_SPTMR1 instance. */
#define ALT_SPTMR1_TMRSCOMPVER_ADDR  ALT_TMR_TMRSCOMPVER_ADDR(ALT_SPTMR1_ADDR)
/* The base address byte offset for the start of the ALT_SPTMR1 component. */
#define ALT_SPTMR1_OFST        0xffc02800
/* The start address of the ALT_SPTMR1 component. */
#define ALT_SPTMR1_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_SPTMR1_OFST))
/* The lower bound address range of the ALT_SPTMR1 component. */
#define ALT_SPTMR1_LB_ADDR     ALT_SPTMR1_ADDR
/* The upper bound address range of the ALT_SPTMR1 component. */
#define ALT_SPTMR1_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_SPTMR1_ADDR) + 0x100) - 1))


/*
 * Component Instance : i_gpio_0_gpio
 * 
 * Instance i_gpio_0_gpio of component ALT_GPIO.
 * 
 * 
 */
/* The address of the ALT_GPIO_SWPORTA_DR register for the ALT_GPIO0 instance. */
#define ALT_GPIO0_SWPORTA_DR_ADDR  ALT_GPIO_SWPORTA_DR_ADDR(ALT_GPIO0_ADDR)
/* The address of the ALT_GPIO_SWPORTA_DDR register for the ALT_GPIO0 instance. */
#define ALT_GPIO0_SWPORTA_DDR_ADDR  ALT_GPIO_SWPORTA_DDR_ADDR(ALT_GPIO0_ADDR)
/* The address of the ALT_GPIO_INTEN register for the ALT_GPIO0 instance. */
#define ALT_GPIO0_INTEN_ADDR  ALT_GPIO_INTEN_ADDR(ALT_GPIO0_ADDR)
/* The address of the ALT_GPIO_INTMSK register for the ALT_GPIO0 instance. */
#define ALT_GPIO0_INTMSK_ADDR  ALT_GPIO_INTMSK_ADDR(ALT_GPIO0_ADDR)
/* The address of the ALT_GPIO_INTTYPE_LEVEL register for the ALT_GPIO0 instance. */
#define ALT_GPIO0_INTTYPE_LEVEL_ADDR  ALT_GPIO_INTTYPE_LEVEL_ADDR(ALT_GPIO0_ADDR)
/* The address of the ALT_GPIO_INT_POL register for the ALT_GPIO0 instance. */
#define ALT_GPIO0_INT_POL_ADDR  ALT_GPIO_INT_POL_ADDR(ALT_GPIO0_ADDR)
/* The address of the ALT_GPIO_INTSTAT register for the ALT_GPIO0 instance. */
#define ALT_GPIO0_INTSTAT_ADDR  ALT_GPIO_INTSTAT_ADDR(ALT_GPIO0_ADDR)
/* The address of the ALT_GPIO_RAW_INTSTAT register for the ALT_GPIO0 instance. */
#define ALT_GPIO0_RAW_INTSTAT_ADDR  ALT_GPIO_RAW_INTSTAT_ADDR(ALT_GPIO0_ADDR)
/* The address of the ALT_GPIO_DEBOUNCE register for the ALT_GPIO0 instance. */
#define ALT_GPIO0_DEBOUNCE_ADDR  ALT_GPIO_DEBOUNCE_ADDR(ALT_GPIO0_ADDR)
/* The address of the ALT_GPIO_PORTA_EOI register for the ALT_GPIO0 instance. */
#define ALT_GPIO0_PORTA_EOI_ADDR  ALT_GPIO_PORTA_EOI_ADDR(ALT_GPIO0_ADDR)
/* The address of the ALT_GPIO_EXT_PORTA register for the ALT_GPIO0 instance. */
#define ALT_GPIO0_EXT_PORTA_ADDR  ALT_GPIO_EXT_PORTA_ADDR(ALT_GPIO0_ADDR)
/* The address of the ALT_GPIO_LS_SYNC register for the ALT_GPIO0 instance. */
#define ALT_GPIO0_LS_SYNC_ADDR  ALT_GPIO_LS_SYNC_ADDR(ALT_GPIO0_ADDR)
/* The address of the ALT_GPIO_ID_CODE register for the ALT_GPIO0 instance. */
#define ALT_GPIO0_ID_CODE_ADDR  ALT_GPIO_ID_CODE_ADDR(ALT_GPIO0_ADDR)
/* The address of the ALT_GPIO_VER_ID_CODE register for the ALT_GPIO0 instance. */
#define ALT_GPIO0_VER_ID_CODE_ADDR  ALT_GPIO_VER_ID_CODE_ADDR(ALT_GPIO0_ADDR)
/* The address of the ALT_GPIO_CFG_REG2 register for the ALT_GPIO0 instance. */
#define ALT_GPIO0_CFG_REG2_ADDR  ALT_GPIO_CFG_REG2_ADDR(ALT_GPIO0_ADDR)
/* The address of the ALT_GPIO_CFG_REG1 register for the ALT_GPIO0 instance. */
#define ALT_GPIO0_CFG_REG1_ADDR  ALT_GPIO_CFG_REG1_ADDR(ALT_GPIO0_ADDR)
/* The base address byte offset for the start of the ALT_GPIO0 component. */
#define ALT_GPIO0_OFST        0xffc02900
/* The start address of the ALT_GPIO0 component. */
#define ALT_GPIO0_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_GPIO0_OFST))
/* The lower bound address range of the ALT_GPIO0 component. */
#define ALT_GPIO0_LB_ADDR     ALT_GPIO0_ADDR
/* The upper bound address range of the ALT_GPIO0 component. */
#define ALT_GPIO0_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_GPIO0_ADDR) + 0x80) - 1))


/*
 * Component Instance : i_gpio_1_gpio
 * 
 * Instance i_gpio_1_gpio of component ALT_GPIO.
 * 
 * 
 */
/* The address of the ALT_GPIO_SWPORTA_DR register for the ALT_GPIO1 instance. */
#define ALT_GPIO1_SWPORTA_DR_ADDR  ALT_GPIO_SWPORTA_DR_ADDR(ALT_GPIO1_ADDR)
/* The address of the ALT_GPIO_SWPORTA_DDR register for the ALT_GPIO1 instance. */
#define ALT_GPIO1_SWPORTA_DDR_ADDR  ALT_GPIO_SWPORTA_DDR_ADDR(ALT_GPIO1_ADDR)
/* The address of the ALT_GPIO_INTEN register for the ALT_GPIO1 instance. */
#define ALT_GPIO1_INTEN_ADDR  ALT_GPIO_INTEN_ADDR(ALT_GPIO1_ADDR)
/* The address of the ALT_GPIO_INTMSK register for the ALT_GPIO1 instance. */
#define ALT_GPIO1_INTMSK_ADDR  ALT_GPIO_INTMSK_ADDR(ALT_GPIO1_ADDR)
/* The address of the ALT_GPIO_INTTYPE_LEVEL register for the ALT_GPIO1 instance. */
#define ALT_GPIO1_INTTYPE_LEVEL_ADDR  ALT_GPIO_INTTYPE_LEVEL_ADDR(ALT_GPIO1_ADDR)
/* The address of the ALT_GPIO_INT_POL register for the ALT_GPIO1 instance. */
#define ALT_GPIO1_INT_POL_ADDR  ALT_GPIO_INT_POL_ADDR(ALT_GPIO1_ADDR)
/* The address of the ALT_GPIO_INTSTAT register for the ALT_GPIO1 instance. */
#define ALT_GPIO1_INTSTAT_ADDR  ALT_GPIO_INTSTAT_ADDR(ALT_GPIO1_ADDR)
/* The address of the ALT_GPIO_RAW_INTSTAT register for the ALT_GPIO1 instance. */
#define ALT_GPIO1_RAW_INTSTAT_ADDR  ALT_GPIO_RAW_INTSTAT_ADDR(ALT_GPIO1_ADDR)
/* The address of the ALT_GPIO_DEBOUNCE register for the ALT_GPIO1 instance. */
#define ALT_GPIO1_DEBOUNCE_ADDR  ALT_GPIO_DEBOUNCE_ADDR(ALT_GPIO1_ADDR)
/* The address of the ALT_GPIO_PORTA_EOI register for the ALT_GPIO1 instance. */
#define ALT_GPIO1_PORTA_EOI_ADDR  ALT_GPIO_PORTA_EOI_ADDR(ALT_GPIO1_ADDR)
/* The address of the ALT_GPIO_EXT_PORTA register for the ALT_GPIO1 instance. */
#define ALT_GPIO1_EXT_PORTA_ADDR  ALT_GPIO_EXT_PORTA_ADDR(ALT_GPIO1_ADDR)
/* The address of the ALT_GPIO_LS_SYNC register for the ALT_GPIO1 instance. */
#define ALT_GPIO1_LS_SYNC_ADDR  ALT_GPIO_LS_SYNC_ADDR(ALT_GPIO1_ADDR)
/* The address of the ALT_GPIO_ID_CODE register for the ALT_GPIO1 instance. */
#define ALT_GPIO1_ID_CODE_ADDR  ALT_GPIO_ID_CODE_ADDR(ALT_GPIO1_ADDR)
/* The address of the ALT_GPIO_VER_ID_CODE register for the ALT_GPIO1 instance. */
#define ALT_GPIO1_VER_ID_CODE_ADDR  ALT_GPIO_VER_ID_CODE_ADDR(ALT_GPIO1_ADDR)
/* The address of the ALT_GPIO_CFG_REG2 register for the ALT_GPIO1 instance. */
#define ALT_GPIO1_CFG_REG2_ADDR  ALT_GPIO_CFG_REG2_ADDR(ALT_GPIO1_ADDR)
/* The address of the ALT_GPIO_CFG_REG1 register for the ALT_GPIO1 instance. */
#define ALT_GPIO1_CFG_REG1_ADDR  ALT_GPIO_CFG_REG1_ADDR(ALT_GPIO1_ADDR)
/* The base address byte offset for the start of the ALT_GPIO1 component. */
#define ALT_GPIO1_OFST        0xffc02a00
/* The start address of the ALT_GPIO1 component. */
#define ALT_GPIO1_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_GPIO1_OFST))
/* The lower bound address range of the ALT_GPIO1 component. */
#define ALT_GPIO1_LB_ADDR     ALT_GPIO1_ADDR
/* The upper bound address range of the ALT_GPIO1 component. */
#define ALT_GPIO1_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_GPIO1_ADDR) + 0x80) - 1))


/*
 * Component Instance : i_gpio_2_gpio
 * 
 * Instance i_gpio_2_gpio of component ALT_GPIO.
 * 
 * 
 */
/* The address of the ALT_GPIO_SWPORTA_DR register for the ALT_GPIO_2_GPIO instance. */
#define ALT_GPIO_2_GPIO_SWPORTA_DR_ADDR  ALT_GPIO_SWPORTA_DR_ADDR(ALT_GPIO_2_GPIO_ADDR)
/* The address of the ALT_GPIO_SWPORTA_DDR register for the ALT_GPIO_2_GPIO instance. */
#define ALT_GPIO_2_GPIO_SWPORTA_DDR_ADDR  ALT_GPIO_SWPORTA_DDR_ADDR(ALT_GPIO_2_GPIO_ADDR)
/* The address of the ALT_GPIO_INTEN register for the ALT_GPIO_2_GPIO instance. */
#define ALT_GPIO_2_GPIO_INTEN_ADDR  ALT_GPIO_INTEN_ADDR(ALT_GPIO_2_GPIO_ADDR)
/* The address of the ALT_GPIO_INTMSK register for the ALT_GPIO_2_GPIO instance. */
#define ALT_GPIO_2_GPIO_INTMSK_ADDR  ALT_GPIO_INTMSK_ADDR(ALT_GPIO_2_GPIO_ADDR)
/* The address of the ALT_GPIO_INTTYPE_LEVEL register for the ALT_GPIO_2_GPIO instance. */
#define ALT_GPIO_2_GPIO_INTTYPE_LEVEL_ADDR  ALT_GPIO_INTTYPE_LEVEL_ADDR(ALT_GPIO_2_GPIO_ADDR)
/* The address of the ALT_GPIO_INT_POL register for the ALT_GPIO_2_GPIO instance. */
#define ALT_GPIO_2_GPIO_INT_POL_ADDR  ALT_GPIO_INT_POL_ADDR(ALT_GPIO_2_GPIO_ADDR)
/* The address of the ALT_GPIO_INTSTAT register for the ALT_GPIO_2_GPIO instance. */
#define ALT_GPIO_2_GPIO_INTSTAT_ADDR  ALT_GPIO_INTSTAT_ADDR(ALT_GPIO_2_GPIO_ADDR)
/* The address of the ALT_GPIO_RAW_INTSTAT register for the ALT_GPIO_2_GPIO instance. */
#define ALT_GPIO_2_GPIO_RAW_INTSTAT_ADDR  ALT_GPIO_RAW_INTSTAT_ADDR(ALT_GPIO_2_GPIO_ADDR)
/* The address of the ALT_GPIO_DEBOUNCE register for the ALT_GPIO_2_GPIO instance. */
#define ALT_GPIO_2_GPIO_DEBOUNCE_ADDR  ALT_GPIO_DEBOUNCE_ADDR(ALT_GPIO_2_GPIO_ADDR)
/* The address of the ALT_GPIO_PORTA_EOI register for the ALT_GPIO_2_GPIO instance. */
#define ALT_GPIO_2_GPIO_PORTA_EOI_ADDR  ALT_GPIO_PORTA_EOI_ADDR(ALT_GPIO_2_GPIO_ADDR)
/* The address of the ALT_GPIO_EXT_PORTA register for the ALT_GPIO_2_GPIO instance. */
#define ALT_GPIO_2_GPIO_EXT_PORTA_ADDR  ALT_GPIO_EXT_PORTA_ADDR(ALT_GPIO_2_GPIO_ADDR)
/* The address of the ALT_GPIO_LS_SYNC register for the ALT_GPIO_2_GPIO instance. */
#define ALT_GPIO_2_GPIO_LS_SYNC_ADDR  ALT_GPIO_LS_SYNC_ADDR(ALT_GPIO_2_GPIO_ADDR)
/* The address of the ALT_GPIO_ID_CODE register for the ALT_GPIO_2_GPIO instance. */
#define ALT_GPIO_2_GPIO_ID_CODE_ADDR  ALT_GPIO_ID_CODE_ADDR(ALT_GPIO_2_GPIO_ADDR)
/* The address of the ALT_GPIO_VER_ID_CODE register for the ALT_GPIO_2_GPIO instance. */
#define ALT_GPIO_2_GPIO_VER_ID_CODE_ADDR  ALT_GPIO_VER_ID_CODE_ADDR(ALT_GPIO_2_GPIO_ADDR)
/* The address of the ALT_GPIO_CFG_REG2 register for the ALT_GPIO_2_GPIO instance. */
#define ALT_GPIO_2_GPIO_CFG_REG2_ADDR  ALT_GPIO_CFG_REG2_ADDR(ALT_GPIO_2_GPIO_ADDR)
/* The address of the ALT_GPIO_CFG_REG1 register for the ALT_GPIO_2_GPIO instance. */
#define ALT_GPIO_2_GPIO_CFG_REG1_ADDR  ALT_GPIO_CFG_REG1_ADDR(ALT_GPIO_2_GPIO_ADDR)
/* The base address byte offset for the start of the ALT_GPIO_2_GPIO component. */
#define ALT_GPIO_2_GPIO_OFST        0xffc02b00
/* The start address of the ALT_GPIO_2_GPIO component. */
#define ALT_GPIO_2_GPIO_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_GPIO_2_GPIO_OFST))
/* The lower bound address range of the ALT_GPIO_2_GPIO component. */
#define ALT_GPIO_2_GPIO_LB_ADDR     ALT_GPIO_2_GPIO_ADDR
/* The upper bound address range of the ALT_GPIO_2_GPIO component. */
#define ALT_GPIO_2_GPIO_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_GPIO_2_GPIO_ADDR) + 0x80) - 1))


/*
 * Component Instance : i_io48_hmc_mmr_io48_mmr
 * 
 * Instance i_io48_hmc_mmr_io48_mmr of component ALT_IO48_HMC_MMR.
 * 
 * 
 */
/* The address of the ALT_IO48_HMC_MMR_DBGCFG0 register for the ALT_IO48_HMC_MMR instance. */
#define ALT_IO48_HMC_MMR_DBGCFG0_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_IO48_HMC_MMR_ADDR) + ALT_IO48_HMC_MMR_DBGCFG0_OFST))
/* The address of the ALT_IO48_HMC_MMR_DBGCFG1 register for the ALT_IO48_HMC_MMR instance. */
#define ALT_IO48_HMC_MMR_DBGCFG1_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_IO48_HMC_MMR_ADDR) + ALT_IO48_HMC_MMR_DBGCFG1_OFST))
/* The address of the ALT_IO48_HMC_MMR_DBGCFG2 register for the ALT_IO48_HMC_MMR instance. */
#define ALT_IO48_HMC_MMR_DBGCFG2_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_IO48_HMC_MMR_ADDR) + ALT_IO48_HMC_MMR_DBGCFG2_OFST))
/* The address of the ALT_IO48_HMC_MMR_DBGCFG3 register for the ALT_IO48_HMC_MMR instance. */
#define ALT_IO48_HMC_MMR_DBGCFG3_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_IO48_HMC_MMR_ADDR) + ALT_IO48_HMC_MMR_DBGCFG3_OFST))
/* The address of the ALT_IO48_HMC_MMR_DBGCFG4 register for the ALT_IO48_HMC_MMR instance. */
#define ALT_IO48_HMC_MMR_DBGCFG4_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_IO48_HMC_MMR_ADDR) + ALT_IO48_HMC_MMR_DBGCFG4_OFST))
/* The address of the ALT_IO48_HMC_MMR_DBGCFG5 register for the ALT_IO48_HMC_MMR instance. */
#define ALT_IO48_HMC_MMR_DBGCFG5_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_IO48_HMC_MMR_ADDR) + ALT_IO48_HMC_MMR_DBGCFG5_OFST))
/* The address of the ALT_IO48_HMC_MMR_DBGCFG6 register for the ALT_IO48_HMC_MMR instance. */
#define ALT_IO48_HMC_MMR_DBGCFG6_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_IO48_HMC_MMR_ADDR) + ALT_IO48_HMC_MMR_DBGCFG6_OFST))
/* The address of the ALT_IO48_HMC_MMR_RESERVE0 register for the ALT_IO48_HMC_MMR instance. */
#define ALT_IO48_HMC_MMR_RESERVE0_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_IO48_HMC_MMR_ADDR) + ALT_IO48_HMC_MMR_RESERVE0_OFST))
/* The address of the ALT_IO48_HMC_MMR_RESERVE1 register for the ALT_IO48_HMC_MMR instance. */
#define ALT_IO48_HMC_MMR_RESERVE1_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_IO48_HMC_MMR_ADDR) + ALT_IO48_HMC_MMR_RESERVE1_OFST))
/* The address of the ALT_IO48_HMC_MMR_RESERVE2 register for the ALT_IO48_HMC_MMR instance. */
#define ALT_IO48_HMC_MMR_RESERVE2_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_IO48_HMC_MMR_ADDR) + ALT_IO48_HMC_MMR_RESERVE2_OFST))
/* The address of the ALT_IO48_HMC_MMR_CTLCFG0 register for the ALT_IO48_HMC_MMR instance. */
#define ALT_IO48_HMC_MMR_CTLCFG0_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_IO48_HMC_MMR_ADDR) + ALT_IO48_HMC_MMR_CTLCFG0_OFST))
/* The address of the ALT_IO48_HMC_MMR_CTLCFG1 register for the ALT_IO48_HMC_MMR instance. */
#define ALT_IO48_HMC_MMR_CTLCFG1_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_IO48_HMC_MMR_ADDR) + ALT_IO48_HMC_MMR_CTLCFG1_OFST))
/* The address of the ALT_IO48_HMC_MMR_CTLCFG2 register for the ALT_IO48_HMC_MMR instance. */
#define ALT_IO48_HMC_MMR_CTLCFG2_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_IO48_HMC_MMR_ADDR) + ALT_IO48_HMC_MMR_CTLCFG2_OFST))
/* The address of the ALT_IO48_HMC_MMR_CTLCFG3 register for the ALT_IO48_HMC_MMR instance. */
#define ALT_IO48_HMC_MMR_CTLCFG3_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_IO48_HMC_MMR_ADDR) + ALT_IO48_HMC_MMR_CTLCFG3_OFST))
/* The address of the ALT_IO48_HMC_MMR_CTLCFG4 register for the ALT_IO48_HMC_MMR instance. */
#define ALT_IO48_HMC_MMR_CTLCFG4_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_IO48_HMC_MMR_ADDR) + ALT_IO48_HMC_MMR_CTLCFG4_OFST))
/* The address of the ALT_IO48_HMC_MMR_CTLCFG5 register for the ALT_IO48_HMC_MMR instance. */
#define ALT_IO48_HMC_MMR_CTLCFG5_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_IO48_HMC_MMR_ADDR) + ALT_IO48_HMC_MMR_CTLCFG5_OFST))
/* The address of the ALT_IO48_HMC_MMR_CTLCFG6 register for the ALT_IO48_HMC_MMR instance. */
#define ALT_IO48_HMC_MMR_CTLCFG6_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_IO48_HMC_MMR_ADDR) + ALT_IO48_HMC_MMR_CTLCFG6_OFST))
/* The address of the ALT_IO48_HMC_MMR_CTLCFG7 register for the ALT_IO48_HMC_MMR instance. */
#define ALT_IO48_HMC_MMR_CTLCFG7_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_IO48_HMC_MMR_ADDR) + ALT_IO48_HMC_MMR_CTLCFG7_OFST))
/* The address of the ALT_IO48_HMC_MMR_CTLCFG8 register for the ALT_IO48_HMC_MMR instance. */
#define ALT_IO48_HMC_MMR_CTLCFG8_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_IO48_HMC_MMR_ADDR) + ALT_IO48_HMC_MMR_CTLCFG8_OFST))
/* The address of the ALT_IO48_HMC_MMR_CTLCFG9 register for the ALT_IO48_HMC_MMR instance. */
#define ALT_IO48_HMC_MMR_CTLCFG9_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_IO48_HMC_MMR_ADDR) + ALT_IO48_HMC_MMR_CTLCFG9_OFST))
/* The address of the ALT_IO48_HMC_MMR_DRAMTIMING0 register for the ALT_IO48_HMC_MMR instance. */
#define ALT_IO48_HMC_MMR_DRAMTIMING0_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_IO48_HMC_MMR_ADDR) + ALT_IO48_HMC_MMR_DRAMTIMING0_OFST))
/* The address of the ALT_IO48_HMC_MMR_DRAMODT0 register for the ALT_IO48_HMC_MMR instance. */
#define ALT_IO48_HMC_MMR_DRAMODT0_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_IO48_HMC_MMR_ADDR) + ALT_IO48_HMC_MMR_DRAMODT0_OFST))
/* The address of the ALT_IO48_HMC_MMR_DRAMODT1 register for the ALT_IO48_HMC_MMR instance. */
#define ALT_IO48_HMC_MMR_DRAMODT1_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_IO48_HMC_MMR_ADDR) + ALT_IO48_HMC_MMR_DRAMODT1_OFST))
/* The address of the ALT_IO48_HMC_MMR_SBCFG0 register for the ALT_IO48_HMC_MMR instance. */
#define ALT_IO48_HMC_MMR_SBCFG0_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_IO48_HMC_MMR_ADDR) + ALT_IO48_HMC_MMR_SBCFG0_OFST))
/* The address of the ALT_IO48_HMC_MMR_SBCFG1 register for the ALT_IO48_HMC_MMR instance. */
#define ALT_IO48_HMC_MMR_SBCFG1_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_IO48_HMC_MMR_ADDR) + ALT_IO48_HMC_MMR_SBCFG1_OFST))
/* The address of the ALT_IO48_HMC_MMR_SBCFG2 register for the ALT_IO48_HMC_MMR instance. */
#define ALT_IO48_HMC_MMR_SBCFG2_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_IO48_HMC_MMR_ADDR) + ALT_IO48_HMC_MMR_SBCFG2_OFST))
/* The address of the ALT_IO48_HMC_MMR_SBCFG3 register for the ALT_IO48_HMC_MMR instance. */
#define ALT_IO48_HMC_MMR_SBCFG3_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_IO48_HMC_MMR_ADDR) + ALT_IO48_HMC_MMR_SBCFG3_OFST))
/* The address of the ALT_IO48_HMC_MMR_SBCFG4 register for the ALT_IO48_HMC_MMR instance. */
#define ALT_IO48_HMC_MMR_SBCFG4_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_IO48_HMC_MMR_ADDR) + ALT_IO48_HMC_MMR_SBCFG4_OFST))
/* The address of the ALT_IO48_HMC_MMR_SBCFG5 register for the ALT_IO48_HMC_MMR instance. */
#define ALT_IO48_HMC_MMR_SBCFG5_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_IO48_HMC_MMR_ADDR) + ALT_IO48_HMC_MMR_SBCFG5_OFST))
/* The address of the ALT_IO48_HMC_MMR_SBCFG6 register for the ALT_IO48_HMC_MMR instance. */
#define ALT_IO48_HMC_MMR_SBCFG6_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_IO48_HMC_MMR_ADDR) + ALT_IO48_HMC_MMR_SBCFG6_OFST))
/* The address of the ALT_IO48_HMC_MMR_SBCFG7 register for the ALT_IO48_HMC_MMR instance. */
#define ALT_IO48_HMC_MMR_SBCFG7_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_IO48_HMC_MMR_ADDR) + ALT_IO48_HMC_MMR_SBCFG7_OFST))
/* The address of the ALT_IO48_HMC_MMR_CALTIMING0 register for the ALT_IO48_HMC_MMR instance. */
#define ALT_IO48_HMC_MMR_CALTIMING0_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_IO48_HMC_MMR_ADDR) + ALT_IO48_HMC_MMR_CALTIMING0_OFST))
/* The address of the ALT_IO48_HMC_MMR_CALTIMING1 register for the ALT_IO48_HMC_MMR instance. */
#define ALT_IO48_HMC_MMR_CALTIMING1_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_IO48_HMC_MMR_ADDR) + ALT_IO48_HMC_MMR_CALTIMING1_OFST))
/* The address of the ALT_IO48_HMC_MMR_CALTIMING2 register for the ALT_IO48_HMC_MMR instance. */
#define ALT_IO48_HMC_MMR_CALTIMING2_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_IO48_HMC_MMR_ADDR) + ALT_IO48_HMC_MMR_CALTIMING2_OFST))
/* The address of the ALT_IO48_HMC_MMR_CALTIMING3 register for the ALT_IO48_HMC_MMR instance. */
#define ALT_IO48_HMC_MMR_CALTIMING3_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_IO48_HMC_MMR_ADDR) + ALT_IO48_HMC_MMR_CALTIMING3_OFST))
/* The address of the ALT_IO48_HMC_MMR_CALTIMING4 register for the ALT_IO48_HMC_MMR instance. */
#define ALT_IO48_HMC_MMR_CALTIMING4_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_IO48_HMC_MMR_ADDR) + ALT_IO48_HMC_MMR_CALTIMING4_OFST))
/* The address of the ALT_IO48_HMC_MMR_CALTIMING5 register for the ALT_IO48_HMC_MMR instance. */
#define ALT_IO48_HMC_MMR_CALTIMING5_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_IO48_HMC_MMR_ADDR) + ALT_IO48_HMC_MMR_CALTIMING5_OFST))
/* The address of the ALT_IO48_HMC_MMR_CALTIMING6 register for the ALT_IO48_HMC_MMR instance. */
#define ALT_IO48_HMC_MMR_CALTIMING6_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_IO48_HMC_MMR_ADDR) + ALT_IO48_HMC_MMR_CALTIMING6_OFST))
/* The address of the ALT_IO48_HMC_MMR_CALTIMING7 register for the ALT_IO48_HMC_MMR instance. */
#define ALT_IO48_HMC_MMR_CALTIMING7_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_IO48_HMC_MMR_ADDR) + ALT_IO48_HMC_MMR_CALTIMING7_OFST))
/* The address of the ALT_IO48_HMC_MMR_CALTIMING8 register for the ALT_IO48_HMC_MMR instance. */
#define ALT_IO48_HMC_MMR_CALTIMING8_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_IO48_HMC_MMR_ADDR) + ALT_IO48_HMC_MMR_CALTIMING8_OFST))
/* The address of the ALT_IO48_HMC_MMR_CALTIMING9 register for the ALT_IO48_HMC_MMR instance. */
#define ALT_IO48_HMC_MMR_CALTIMING9_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_IO48_HMC_MMR_ADDR) + ALT_IO48_HMC_MMR_CALTIMING9_OFST))
/* The address of the ALT_IO48_HMC_MMR_CALTIMING10 register for the ALT_IO48_HMC_MMR instance. */
#define ALT_IO48_HMC_MMR_CALTIMING10_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_IO48_HMC_MMR_ADDR) + ALT_IO48_HMC_MMR_CALTIMING10_OFST))
/* The address of the ALT_IO48_HMC_MMR_DRAMADDRW register for the ALT_IO48_HMC_MMR instance. */
#define ALT_IO48_HMC_MMR_DRAMADDRW_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_IO48_HMC_MMR_ADDR) + ALT_IO48_HMC_MMR_DRAMADDRW_OFST))
/* The address of the ALT_IO48_HMC_MMR_SIDEBAND0 register for the ALT_IO48_HMC_MMR instance. */
#define ALT_IO48_HMC_MMR_SIDEBAND0_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_IO48_HMC_MMR_ADDR) + ALT_IO48_HMC_MMR_SIDEBAND0_OFST))
/* The address of the ALT_IO48_HMC_MMR_SIDEBAND1 register for the ALT_IO48_HMC_MMR instance. */
#define ALT_IO48_HMC_MMR_SIDEBAND1_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_IO48_HMC_MMR_ADDR) + ALT_IO48_HMC_MMR_SIDEBAND1_OFST))
/* The address of the ALT_IO48_HMC_MMR_SIDEBAND2 register for the ALT_IO48_HMC_MMR instance. */
#define ALT_IO48_HMC_MMR_SIDEBAND2_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_IO48_HMC_MMR_ADDR) + ALT_IO48_HMC_MMR_SIDEBAND2_OFST))
/* The address of the ALT_IO48_HMC_MMR_SIDEBAND3 register for the ALT_IO48_HMC_MMR instance. */
#define ALT_IO48_HMC_MMR_SIDEBAND3_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_IO48_HMC_MMR_ADDR) + ALT_IO48_HMC_MMR_SIDEBAND3_OFST))
/* The address of the ALT_IO48_HMC_MMR_SIDEBAND4 register for the ALT_IO48_HMC_MMR instance. */
#define ALT_IO48_HMC_MMR_SIDEBAND4_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_IO48_HMC_MMR_ADDR) + ALT_IO48_HMC_MMR_SIDEBAND4_OFST))
/* The address of the ALT_IO48_HMC_MMR_SIDEBAND5 register for the ALT_IO48_HMC_MMR instance. */
#define ALT_IO48_HMC_MMR_SIDEBAND5_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_IO48_HMC_MMR_ADDR) + ALT_IO48_HMC_MMR_SIDEBAND5_OFST))
/* The address of the ALT_IO48_HMC_MMR_SIDEBAND6 register for the ALT_IO48_HMC_MMR instance. */
#define ALT_IO48_HMC_MMR_SIDEBAND6_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_IO48_HMC_MMR_ADDR) + ALT_IO48_HMC_MMR_SIDEBAND6_OFST))
/* The address of the ALT_IO48_HMC_MMR_SIDEBAND7 register for the ALT_IO48_HMC_MMR instance. */
#define ALT_IO48_HMC_MMR_SIDEBAND7_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_IO48_HMC_MMR_ADDR) + ALT_IO48_HMC_MMR_SIDEBAND7_OFST))
/* The address of the ALT_IO48_HMC_MMR_SIDEBAND8 register for the ALT_IO48_HMC_MMR instance. */
#define ALT_IO48_HMC_MMR_SIDEBAND8_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_IO48_HMC_MMR_ADDR) + ALT_IO48_HMC_MMR_SIDEBAND8_OFST))
/* The address of the ALT_IO48_HMC_MMR_SIDEBAND9 register for the ALT_IO48_HMC_MMR instance. */
#define ALT_IO48_HMC_MMR_SIDEBAND9_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_IO48_HMC_MMR_ADDR) + ALT_IO48_HMC_MMR_SIDEBAND9_OFST))
/* The address of the ALT_IO48_HMC_MMR_SIDEBAND10 register for the ALT_IO48_HMC_MMR instance. */
#define ALT_IO48_HMC_MMR_SIDEBAND10_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_IO48_HMC_MMR_ADDR) + ALT_IO48_HMC_MMR_SIDEBAND10_OFST))
/* The address of the ALT_IO48_HMC_MMR_SIDEBAND11 register for the ALT_IO48_HMC_MMR instance. */
#define ALT_IO48_HMC_MMR_SIDEBAND11_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_IO48_HMC_MMR_ADDR) + ALT_IO48_HMC_MMR_SIDEBAND11_OFST))
/* The address of the ALT_IO48_HMC_MMR_SIDEBAND12 register for the ALT_IO48_HMC_MMR instance. */
#define ALT_IO48_HMC_MMR_SIDEBAND12_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_IO48_HMC_MMR_ADDR) + ALT_IO48_HMC_MMR_SIDEBAND12_OFST))
/* The address of the ALT_IO48_HMC_MMR_SIDEBAND13 register for the ALT_IO48_HMC_MMR instance. */
#define ALT_IO48_HMC_MMR_SIDEBAND13_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_IO48_HMC_MMR_ADDR) + ALT_IO48_HMC_MMR_SIDEBAND13_OFST))
/* The address of the ALT_IO48_HMC_MMR_SIDEBAND14 register for the ALT_IO48_HMC_MMR instance. */
#define ALT_IO48_HMC_MMR_SIDEBAND14_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_IO48_HMC_MMR_ADDR) + ALT_IO48_HMC_MMR_SIDEBAND14_OFST))
/* The address of the ALT_IO48_HMC_MMR_SIDEBAND15 register for the ALT_IO48_HMC_MMR instance. */
#define ALT_IO48_HMC_MMR_SIDEBAND15_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_IO48_HMC_MMR_ADDR) + ALT_IO48_HMC_MMR_SIDEBAND15_OFST))
/* The address of the ALT_IO48_HMC_MMR_DRAMSTS register for the ALT_IO48_HMC_MMR instance. */
#define ALT_IO48_HMC_MMR_DRAMSTS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_IO48_HMC_MMR_ADDR) + ALT_IO48_HMC_MMR_DRAMSTS_OFST))
/* The address of the ALT_IO48_HMC_MMR_DBGDONE register for the ALT_IO48_HMC_MMR instance. */
#define ALT_IO48_HMC_MMR_DBGDONE_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_IO48_HMC_MMR_ADDR) + ALT_IO48_HMC_MMR_DBGDONE_OFST))
/* The address of the ALT_IO48_HMC_MMR_DBGSIGNALS register for the ALT_IO48_HMC_MMR instance. */
#define ALT_IO48_HMC_MMR_DBGSIGNALS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_IO48_HMC_MMR_ADDR) + ALT_IO48_HMC_MMR_DBGSIGNALS_OFST))
/* The address of the ALT_IO48_HMC_MMR_DBGRST register for the ALT_IO48_HMC_MMR instance. */
#define ALT_IO48_HMC_MMR_DBGRST_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_IO48_HMC_MMR_ADDR) + ALT_IO48_HMC_MMR_DBGRST_OFST))
/* The address of the ALT_IO48_HMC_MMR_DBGMATCH register for the ALT_IO48_HMC_MMR instance. */
#define ALT_IO48_HMC_MMR_DBGMATCH_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_IO48_HMC_MMR_ADDR) + ALT_IO48_HMC_MMR_DBGMATCH_OFST))
/* The address of the ALT_IO48_HMC_MMR_CNTR0MSK register for the ALT_IO48_HMC_MMR instance. */
#define ALT_IO48_HMC_MMR_CNTR0MSK_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_IO48_HMC_MMR_ADDR) + ALT_IO48_HMC_MMR_CNTR0MSK_OFST))
/* The address of the ALT_IO48_HMC_MMR_CNTR1MSK register for the ALT_IO48_HMC_MMR instance. */
#define ALT_IO48_HMC_MMR_CNTR1MSK_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_IO48_HMC_MMR_ADDR) + ALT_IO48_HMC_MMR_CNTR1MSK_OFST))
/* The address of the ALT_IO48_HMC_MMR_CNTR0MATCH register for the ALT_IO48_HMC_MMR instance. */
#define ALT_IO48_HMC_MMR_CNTR0MATCH_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_IO48_HMC_MMR_ADDR) + ALT_IO48_HMC_MMR_CNTR0MATCH_OFST))
/* The address of the ALT_IO48_HMC_MMR_CNTR1MATCH register for the ALT_IO48_HMC_MMR instance. */
#define ALT_IO48_HMC_MMR_CNTR1MATCH_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_IO48_HMC_MMR_ADDR) + ALT_IO48_HMC_MMR_CNTR1MATCH_OFST))
/* The address of the ALT_IO48_HMC_MMR_NIOSRESERVE0 register for the ALT_IO48_HMC_MMR instance. */
#define ALT_IO48_HMC_MMR_NIOSRESERVE0_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_IO48_HMC_MMR_ADDR) + ALT_IO48_HMC_MMR_NIOSRESERVE0_OFST))
/* The address of the ALT_IO48_HMC_MMR_NIOSRESERVE1 register for the ALT_IO48_HMC_MMR instance. */
#define ALT_IO48_HMC_MMR_NIOSRESERVE1_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_IO48_HMC_MMR_ADDR) + ALT_IO48_HMC_MMR_NIOSRESERVE1_OFST))
/* The address of the ALT_IO48_HMC_MMR_NIOSRESERVE2 register for the ALT_IO48_HMC_MMR instance. */
#define ALT_IO48_HMC_MMR_NIOSRESERVE2_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_IO48_HMC_MMR_ADDR) + ALT_IO48_HMC_MMR_NIOSRESERVE2_OFST))
/* The base address byte offset for the start of the ALT_IO48_HMC_MMR component. */
#define ALT_IO48_HMC_MMR_OFST        0xffcfa000
/* The start address of the ALT_IO48_HMC_MMR component. */
#define ALT_IO48_HMC_MMR_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_IO48_HMC_MMR_OFST))
/* The lower bound address range of the ALT_IO48_HMC_MMR component. */
#define ALT_IO48_HMC_MMR_LB_ADDR     ALT_IO48_HMC_MMR_ADDR
/* The upper bound address range of the ALT_IO48_HMC_MMR component. */
#define ALT_IO48_HMC_MMR_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_IO48_HMC_MMR_ADDR) + 0x1000) - 1))


/*
 * Component Instance : ecc_hmc_ocp_slv_block
 * 
 * Instance ecc_hmc_ocp_slv_block of component ALT_ECC_HMC_OCP.
 * 
 * 
 */
/* The address of the ALT_ECC_HMC_OCP_IP_REV_ID register for the ALT_ECC_HMC_OCP instance. */
#define ALT_ECC_HMC_OCP_IP_REV_ID_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_HMC_OCP_ADDR) + ALT_ECC_HMC_OCP_IP_REV_ID_OFST))
/* The address of the ALT_ECC_HMC_OCP_DDRIOCTL register for the ALT_ECC_HMC_OCP instance. */
#define ALT_ECC_HMC_OCP_DDRIOCTL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_HMC_OCP_ADDR) + ALT_ECC_HMC_OCP_DDRIOCTL_OFST))
/* The address of the ALT_ECC_HMC_OCP_DDRCALSTAT register for the ALT_ECC_HMC_OCP instance. */
#define ALT_ECC_HMC_OCP_DDRCALSTAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_HMC_OCP_ADDR) + ALT_ECC_HMC_OCP_DDRCALSTAT_OFST))
/* The address of the ALT_ECC_HMC_OCP_MPR_0BEAT1 register for the ALT_ECC_HMC_OCP instance. */
#define ALT_ECC_HMC_OCP_MPR_0BEAT1_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_HMC_OCP_ADDR) + ALT_ECC_HMC_OCP_MPR_0BEAT1_OFST))
/* The address of the ALT_ECC_HMC_OCP_MPR_1BEAT1 register for the ALT_ECC_HMC_OCP instance. */
#define ALT_ECC_HMC_OCP_MPR_1BEAT1_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_HMC_OCP_ADDR) + ALT_ECC_HMC_OCP_MPR_1BEAT1_OFST))
/* The address of the ALT_ECC_HMC_OCP_MPR_2BEAT1 register for the ALT_ECC_HMC_OCP instance. */
#define ALT_ECC_HMC_OCP_MPR_2BEAT1_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_HMC_OCP_ADDR) + ALT_ECC_HMC_OCP_MPR_2BEAT1_OFST))
/* The address of the ALT_ECC_HMC_OCP_MPR_3BEAT1 register for the ALT_ECC_HMC_OCP instance. */
#define ALT_ECC_HMC_OCP_MPR_3BEAT1_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_HMC_OCP_ADDR) + ALT_ECC_HMC_OCP_MPR_3BEAT1_OFST))
/* The address of the ALT_ECC_HMC_OCP_MPR_4BEAT1 register for the ALT_ECC_HMC_OCP instance. */
#define ALT_ECC_HMC_OCP_MPR_4BEAT1_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_HMC_OCP_ADDR) + ALT_ECC_HMC_OCP_MPR_4BEAT1_OFST))
/* The address of the ALT_ECC_HMC_OCP_MPR_5BEAT1 register for the ALT_ECC_HMC_OCP instance. */
#define ALT_ECC_HMC_OCP_MPR_5BEAT1_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_HMC_OCP_ADDR) + ALT_ECC_HMC_OCP_MPR_5BEAT1_OFST))
/* The address of the ALT_ECC_HMC_OCP_MPR_6BEAT1 register for the ALT_ECC_HMC_OCP instance. */
#define ALT_ECC_HMC_OCP_MPR_6BEAT1_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_HMC_OCP_ADDR) + ALT_ECC_HMC_OCP_MPR_6BEAT1_OFST))
/* The address of the ALT_ECC_HMC_OCP_MPR_7BEAT1 register for the ALT_ECC_HMC_OCP instance. */
#define ALT_ECC_HMC_OCP_MPR_7BEAT1_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_HMC_OCP_ADDR) + ALT_ECC_HMC_OCP_MPR_7BEAT1_OFST))
/* The address of the ALT_ECC_HMC_OCP_MPR_8BEAT1 register for the ALT_ECC_HMC_OCP instance. */
#define ALT_ECC_HMC_OCP_MPR_8BEAT1_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_HMC_OCP_ADDR) + ALT_ECC_HMC_OCP_MPR_8BEAT1_OFST))
/* The address of the ALT_ECC_HMC_OCP_MPR_0BEAT2 register for the ALT_ECC_HMC_OCP instance. */
#define ALT_ECC_HMC_OCP_MPR_0BEAT2_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_HMC_OCP_ADDR) + ALT_ECC_HMC_OCP_MPR_0BEAT2_OFST))
/* The address of the ALT_ECC_HMC_OCP_MPR_1BEAT2 register for the ALT_ECC_HMC_OCP instance. */
#define ALT_ECC_HMC_OCP_MPR_1BEAT2_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_HMC_OCP_ADDR) + ALT_ECC_HMC_OCP_MPR_1BEAT2_OFST))
/* The address of the ALT_ECC_HMC_OCP_MPR_2BEAT2 register for the ALT_ECC_HMC_OCP instance. */
#define ALT_ECC_HMC_OCP_MPR_2BEAT2_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_HMC_OCP_ADDR) + ALT_ECC_HMC_OCP_MPR_2BEAT2_OFST))
/* The address of the ALT_ECC_HMC_OCP_MPR_3BEAT2 register for the ALT_ECC_HMC_OCP instance. */
#define ALT_ECC_HMC_OCP_MPR_3BEAT2_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_HMC_OCP_ADDR) + ALT_ECC_HMC_OCP_MPR_3BEAT2_OFST))
/* The address of the ALT_ECC_HMC_OCP_MPR_4BEAT2 register for the ALT_ECC_HMC_OCP instance. */
#define ALT_ECC_HMC_OCP_MPR_4BEAT2_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_HMC_OCP_ADDR) + ALT_ECC_HMC_OCP_MPR_4BEAT2_OFST))
/* The address of the ALT_ECC_HMC_OCP_MPR_5BEAT2 register for the ALT_ECC_HMC_OCP instance. */
#define ALT_ECC_HMC_OCP_MPR_5BEAT2_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_HMC_OCP_ADDR) + ALT_ECC_HMC_OCP_MPR_5BEAT2_OFST))
/* The address of the ALT_ECC_HMC_OCP_MPR_6BEAT2 register for the ALT_ECC_HMC_OCP instance. */
#define ALT_ECC_HMC_OCP_MPR_6BEAT2_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_HMC_OCP_ADDR) + ALT_ECC_HMC_OCP_MPR_6BEAT2_OFST))
/* The address of the ALT_ECC_HMC_OCP_MPR_7BEAT2 register for the ALT_ECC_HMC_OCP instance. */
#define ALT_ECC_HMC_OCP_MPR_7BEAT2_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_HMC_OCP_ADDR) + ALT_ECC_HMC_OCP_MPR_7BEAT2_OFST))
/* The address of the ALT_ECC_HMC_OCP_MPR_8BEAT2 register for the ALT_ECC_HMC_OCP instance. */
#define ALT_ECC_HMC_OCP_MPR_8BEAT2_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_HMC_OCP_ADDR) + ALT_ECC_HMC_OCP_MPR_8BEAT2_OFST))
/* The address of the ALT_ECC_HMC_OCP_AUTO_PRECHARGE register for the ALT_ECC_HMC_OCP instance. */
#define ALT_ECC_HMC_OCP_AUTO_PRECHARGE_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_HMC_OCP_ADDR) + ALT_ECC_HMC_OCP_AUTO_PRECHARGE_OFST))
/* The address of the ALT_ECC_HMC_OCP_ECCCTL1 register for the ALT_ECC_HMC_OCP instance. */
#define ALT_ECC_HMC_OCP_ECCCTL1_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_HMC_OCP_ADDR) + ALT_ECC_HMC_OCP_ECCCTL1_OFST))
/* The address of the ALT_ECC_HMC_OCP_ECCCTL2 register for the ALT_ECC_HMC_OCP instance. */
#define ALT_ECC_HMC_OCP_ECCCTL2_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_HMC_OCP_ADDR) + ALT_ECC_HMC_OCP_ECCCTL2_OFST))
/* The address of the ALT_ECC_HMC_OCP_ERRINTEN register for the ALT_ECC_HMC_OCP instance. */
#define ALT_ECC_HMC_OCP_ERRINTEN_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_HMC_OCP_ADDR) + ALT_ECC_HMC_OCP_ERRINTEN_OFST))
/* The address of the ALT_ECC_HMC_OCP_ERRINTENS register for the ALT_ECC_HMC_OCP instance. */
#define ALT_ECC_HMC_OCP_ERRINTENS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_HMC_OCP_ADDR) + ALT_ECC_HMC_OCP_ERRINTENS_OFST))
/* The address of the ALT_ECC_HMC_OCP_ERRINTENR register for the ALT_ECC_HMC_OCP instance. */
#define ALT_ECC_HMC_OCP_ERRINTENR_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_HMC_OCP_ADDR) + ALT_ECC_HMC_OCP_ERRINTENR_OFST))
/* The address of the ALT_ECC_HMC_OCP_INTMOD register for the ALT_ECC_HMC_OCP instance. */
#define ALT_ECC_HMC_OCP_INTMOD_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_HMC_OCP_ADDR) + ALT_ECC_HMC_OCP_INTMOD_OFST))
/* The address of the ALT_ECC_HMC_OCP_INTSTAT register for the ALT_ECC_HMC_OCP instance. */
#define ALT_ECC_HMC_OCP_INTSTAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_HMC_OCP_ADDR) + ALT_ECC_HMC_OCP_INTSTAT_OFST))
/* The address of the ALT_ECC_HMC_OCP_DIAGINTTEST register for the ALT_ECC_HMC_OCP instance. */
#define ALT_ECC_HMC_OCP_DIAGINTTEST_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_HMC_OCP_ADDR) + ALT_ECC_HMC_OCP_DIAGINTTEST_OFST))
/* The address of the ALT_ECC_HMC_OCP_MODSTAT register for the ALT_ECC_HMC_OCP instance. */
#define ALT_ECC_HMC_OCP_MODSTAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_HMC_OCP_ADDR) + ALT_ECC_HMC_OCP_MODSTAT_OFST))
/* The address of the ALT_ECC_HMC_OCP_DERRADDRA register for the ALT_ECC_HMC_OCP instance. */
#define ALT_ECC_HMC_OCP_DERRADDRA_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_HMC_OCP_ADDR) + ALT_ECC_HMC_OCP_DERRADDRA_OFST))
/* The address of the ALT_ECC_HMC_OCP_SERRADDRA register for the ALT_ECC_HMC_OCP instance. */
#define ALT_ECC_HMC_OCP_SERRADDRA_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_HMC_OCP_ADDR) + ALT_ECC_HMC_OCP_SERRADDRA_OFST))
/* The address of the ALT_ECC_HMC_OCP_AUTOWB_CORRADDR register for the ALT_ECC_HMC_OCP instance. */
#define ALT_ECC_HMC_OCP_AUTOWB_CORRADDR_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_HMC_OCP_ADDR) + ALT_ECC_HMC_OCP_AUTOWB_CORRADDR_OFST))
/* The address of the ALT_ECC_HMC_OCP_SERRCNTREG register for the ALT_ECC_HMC_OCP instance. */
#define ALT_ECC_HMC_OCP_SERRCNTREG_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_HMC_OCP_ADDR) + ALT_ECC_HMC_OCP_SERRCNTREG_OFST))
/* The address of the ALT_ECC_HMC_OCP_AUTOWB_DROP_CNTREG register for the ALT_ECC_HMC_OCP instance. */
#define ALT_ECC_HMC_OCP_AUTOWB_DROP_CNTREG_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_HMC_OCP_ADDR) + ALT_ECC_HMC_OCP_AUTOWB_DROP_CNTREG_OFST))
/* The address of the ALT_ECC_HMC_OCP_ECC_REG2WRECCDATABUS register for the ALT_ECC_HMC_OCP instance. */
#define ALT_ECC_HMC_OCP_ECC_REG2WRECCDATABUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_HMC_OCP_ADDR) + ALT_ECC_HMC_OCP_ECC_REG2WRECCDATABUS_OFST))
/* The address of the ALT_ECC_HMC_OCP_ECC_RDECCDATA2REGBUS register for the ALT_ECC_HMC_OCP instance. */
#define ALT_ECC_HMC_OCP_ECC_RDECCDATA2REGBUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_HMC_OCP_ADDR) + ALT_ECC_HMC_OCP_ECC_RDECCDATA2REGBUS_OFST))
/* The address of the ALT_ECC_HMC_OCP_ECC_REG2RDECCDATABUS register for the ALT_ECC_HMC_OCP instance. */
#define ALT_ECC_HMC_OCP_ECC_REG2RDECCDATABUS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_HMC_OCP_ADDR) + ALT_ECC_HMC_OCP_ECC_REG2RDECCDATABUS_OFST))
/* The address of the ALT_ECC_HMC_OCP_ECC_DIAGON register for the ALT_ECC_HMC_OCP instance. */
#define ALT_ECC_HMC_OCP_ECC_DIAGON_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_HMC_OCP_ADDR) + ALT_ECC_HMC_OCP_ECC_DIAGON_OFST))
/* The address of the ALT_ECC_HMC_OCP_ECC_DECSTAT register for the ALT_ECC_HMC_OCP instance. */
#define ALT_ECC_HMC_OCP_ECC_DECSTAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_HMC_OCP_ADDR) + ALT_ECC_HMC_OCP_ECC_DECSTAT_OFST))
/* The address of the ALT_ECC_HMC_OCP_ECC_ERRGENADDR_0 register for the ALT_ECC_HMC_OCP instance. */
#define ALT_ECC_HMC_OCP_ECC_ERRGENADDR_0_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_HMC_OCP_ADDR) + ALT_ECC_HMC_OCP_ECC_ERRGENADDR_0_OFST))
/* The address of the ALT_ECC_HMC_OCP_ECC_ERRGENADDR_1 register for the ALT_ECC_HMC_OCP instance. */
#define ALT_ECC_HMC_OCP_ECC_ERRGENADDR_1_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_HMC_OCP_ADDR) + ALT_ECC_HMC_OCP_ECC_ERRGENADDR_1_OFST))
/* The address of the ALT_ECC_HMC_OCP_ECC_ERRGENADDR_2 register for the ALT_ECC_HMC_OCP instance. */
#define ALT_ECC_HMC_OCP_ECC_ERRGENADDR_2_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_HMC_OCP_ADDR) + ALT_ECC_HMC_OCP_ECC_ERRGENADDR_2_OFST))
/* The address of the ALT_ECC_HMC_OCP_ECC_ERRGENADDR_3 register for the ALT_ECC_HMC_OCP instance. */
#define ALT_ECC_HMC_OCP_ECC_ERRGENADDR_3_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_HMC_OCP_ADDR) + ALT_ECC_HMC_OCP_ECC_ERRGENADDR_3_OFST))
/* The address of the ALT_ECC_HMC_OCP_ECC_REG2RDDATABUS_BEAT0 register for the ALT_ECC_HMC_OCP instance. */
#define ALT_ECC_HMC_OCP_ECC_REG2RDDATABUS_BEAT0_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_HMC_OCP_ADDR) + ALT_ECC_HMC_OCP_ECC_REG2RDDATABUS_BEAT0_OFST))
/* The address of the ALT_ECC_HMC_OCP_ECC_REG2RDDATABUS_BEAT1 register for the ALT_ECC_HMC_OCP instance. */
#define ALT_ECC_HMC_OCP_ECC_REG2RDDATABUS_BEAT1_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_HMC_OCP_ADDR) + ALT_ECC_HMC_OCP_ECC_REG2RDDATABUS_BEAT1_OFST))
/* The address of the ALT_ECC_HMC_OCP_ECC_REG2RDDATABUS_BEAT2 register for the ALT_ECC_HMC_OCP instance. */
#define ALT_ECC_HMC_OCP_ECC_REG2RDDATABUS_BEAT2_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_HMC_OCP_ADDR) + ALT_ECC_HMC_OCP_ECC_REG2RDDATABUS_BEAT2_OFST))
/* The address of the ALT_ECC_HMC_OCP_ECC_REG2RDDATABUS_BEAT3 register for the ALT_ECC_HMC_OCP instance. */
#define ALT_ECC_HMC_OCP_ECC_REG2RDDATABUS_BEAT3_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_ECC_HMC_OCP_ADDR) + ALT_ECC_HMC_OCP_ECC_REG2RDDATABUS_BEAT3_OFST))
/* The base address byte offset for the start of the ALT_ECC_HMC_OCP component. */
#define ALT_ECC_HMC_OCP_OFST        0xffcfb000
/* The start address of the ALT_ECC_HMC_OCP component. */
#define ALT_ECC_HMC_OCP_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_ECC_HMC_OCP_OFST))
/* The lower bound address range of the ALT_ECC_HMC_OCP component. */
#define ALT_ECC_HMC_OCP_LB_ADDR     ALT_ECC_HMC_OCP_ADDR
/* The upper bound address range of the ALT_ECC_HMC_OCP component. */
#define ALT_ECC_HMC_OCP_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_ECC_HMC_OCP_ADDR) + 0x500) - 1))


/*
 * Component Instance : i_sec_mgr_aesfifo
 * 
 * Instance i_sec_mgr_aesfifo of component ALT_SEC_MGR_AESFIFO.
 * 
 * 
 */
/* The base address byte offset for the start of the ALT_SEC_MGR_AESFIFO component. */
#define ALT_SEC_MGR_AESFIFO_OFST        0xffcfe000
/* The start address of the ALT_SEC_MGR_AESFIFO component. */
#define ALT_SEC_MGR_AESFIFO_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_SEC_MGR_AESFIFO_OFST))
/* The lower bound address range of the ALT_SEC_MGR_AESFIFO component. */
#define ALT_SEC_MGR_AESFIFO_LB_ADDR     ALT_SEC_MGR_AESFIFO_ADDR
/* The upper bound address range of the ALT_SEC_MGR_AESFIFO component. */
#define ALT_SEC_MGR_AESFIFO_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_SEC_MGR_AESFIFO_ADDR) + 0x400) - 1))


/*
 * Component Instance : i_fpga_mgr_fpgamgrdata
 * 
 * Instance i_fpga_mgr_fpgamgrdata of component ALT_FPGAMGRDATA.
 * 
 * 
 */
/* The address of the ALT_FPGAMGRDATA_DATA register for the ALT_FPGAMGRDATA instance. */
#define ALT_FPGAMGRDATA_DATA_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_FPGAMGRDATA_ADDR) + ALT_FPGAMGRDATA_DATA_OFST))
/* The base address byte offset for the start of the ALT_FPGAMGRDATA component. */
#define ALT_FPGAMGRDATA_OFST        0xffcfe400

#ifdef LINUX_TASK_MODE 
#define VIRTUAL_PPGAMGRDATA_OFSET (uint32_t)  __hps_virtualAdreess_FPGAMFRDATA
#else 
#define VIRTUAL_PPGAMGRDATA_OFSET  ALT_FPGAMGRDATA_OFST
#endif

/* The start address of the ALT_FPGAMGRDATA component. */
#define ALT_FPGAMGRDATA_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + VIRTUAL_PPGAMGRDATA_OFSET))
/* The lower bound address range of the ALT_FPGAMGRDATA component. */
#define ALT_FPGAMGRDATA_LB_ADDR     ALT_FPGAMGRDATA_ADDR
/* The upper bound address range of the ALT_FPGAMGRDATA component. */
#define ALT_FPGAMGRDATA_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_FPGAMGRDATA_ADDR) + 0x400) - 1))

/*
 * Component Instance : i_timer_sys_0_timer
 * 
 * Instance i_timer_sys_0_timer of component ALT_TMR.
 * 
 * 
 */
/* The address of the ALT_TMR_TMR1LDCOUNT register for the ALT_TMR_SYS_0_TMR instance. */
#define ALT_TMR_SYS_0_TMR_TMR1LDCOUNT_ADDR  ALT_TMR_TMR1LDCOUNT_ADDR(ALT_TMR_SYS_0_TMR_ADDR)
/* The address of the ALT_TMR_TMR1CURVAL register for the ALT_TMR_SYS_0_TMR instance. */
#define ALT_TMR_SYS_0_TMR_TMR1CURVAL_ADDR  ALT_TMR_TMR1CURVAL_ADDR(ALT_TMR_SYS_0_TMR_ADDR)
/* The address of the ALT_TMR_TMR1CTLREG register for the ALT_TMR_SYS_0_TMR instance. */
#define ALT_TMR_SYS_0_TMR_TMR1CTLREG_ADDR  ALT_TMR_TMR1CTLREG_ADDR(ALT_TMR_SYS_0_TMR_ADDR)
/* The address of the ALT_TMR_TMR1EOI register for the ALT_TMR_SYS_0_TMR instance. */
#define ALT_TMR_SYS_0_TMR_TMR1EOI_ADDR  ALT_TMR_TMR1EOI_ADDR(ALT_TMR_SYS_0_TMR_ADDR)
/* The address of the ALT_TMR_TMR1INTSTAT register for the ALT_TMR_SYS_0_TMR instance. */
#define ALT_TMR_SYS_0_TMR_TMR1INTSTAT_ADDR  ALT_TMR_TMR1INTSTAT_ADDR(ALT_TMR_SYS_0_TMR_ADDR)
/* The address of the ALT_TMR_TMRSINTSTAT register for the ALT_TMR_SYS_0_TMR instance. */
#define ALT_TMR_SYS_0_TMR_TMRSINTSTAT_ADDR  ALT_TMR_TMRSINTSTAT_ADDR(ALT_TMR_SYS_0_TMR_ADDR)
/* The address of the ALT_TMR_TMRSEOI register for the ALT_TMR_SYS_0_TMR instance. */
#define ALT_TMR_SYS_0_TMR_TMRSEOI_ADDR  ALT_TMR_TMRSEOI_ADDR(ALT_TMR_SYS_0_TMR_ADDR)
/* The address of the ALT_TMR_TMRSRAWINTSTAT register for the ALT_TMR_SYS_0_TMR instance. */
#define ALT_TMR_SYS_0_TMR_TMRSRAWINTSTAT_ADDR  ALT_TMR_TMRSRAWINTSTAT_ADDR(ALT_TMR_SYS_0_TMR_ADDR)
/* The address of the ALT_TMR_TMRSCOMPVER register for the ALT_TMR_SYS_0_TMR instance. */
#define ALT_TMR_SYS_0_TMR_TMRSCOMPVER_ADDR  ALT_TMR_TMRSCOMPVER_ADDR(ALT_TMR_SYS_0_TMR_ADDR)
/* The base address byte offset for the start of the ALT_TMR_SYS_0_TMR component. */
#define ALT_TMR_SYS_0_TMR_OFST        0xffd00000
/* The start address of the ALT_TMR_SYS_0_TMR component. */
#define ALT_TMR_SYS_0_TMR_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_TMR_SYS_0_TMR_OFST))
/* The lower bound address range of the ALT_TMR_SYS_0_TMR component. */
#define ALT_TMR_SYS_0_TMR_LB_ADDR     ALT_TMR_SYS_0_TMR_ADDR
/* The upper bound address range of the ALT_TMR_SYS_0_TMR component. */
#define ALT_TMR_SYS_0_TMR_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_TMR_SYS_0_TMR_ADDR) + 0x100) - 1))


/*
 * Component Instance : i_timer_sys_1_timer
 * 
 * Instance i_timer_sys_1_timer of component ALT_TMR.
 * 
 * 
 */
/* The address of the ALT_TMR_TMR1LDCOUNT register for the ALT_TMR_SYS_1_TMR instance. */
#define ALT_TMR_SYS_1_TMR_TMR1LDCOUNT_ADDR  ALT_TMR_TMR1LDCOUNT_ADDR(ALT_TMR_SYS_1_TMR_ADDR)
/* The address of the ALT_TMR_TMR1CURVAL register for the ALT_TMR_SYS_1_TMR instance. */
#define ALT_TMR_SYS_1_TMR_TMR1CURVAL_ADDR  ALT_TMR_TMR1CURVAL_ADDR(ALT_TMR_SYS_1_TMR_ADDR)
/* The address of the ALT_TMR_TMR1CTLREG register for the ALT_TMR_SYS_1_TMR instance. */
#define ALT_TMR_SYS_1_TMR_TMR1CTLREG_ADDR  ALT_TMR_TMR1CTLREG_ADDR(ALT_TMR_SYS_1_TMR_ADDR)
/* The address of the ALT_TMR_TMR1EOI register for the ALT_TMR_SYS_1_TMR instance. */
#define ALT_TMR_SYS_1_TMR_TMR1EOI_ADDR  ALT_TMR_TMR1EOI_ADDR(ALT_TMR_SYS_1_TMR_ADDR)
/* The address of the ALT_TMR_TMR1INTSTAT register for the ALT_TMR_SYS_1_TMR instance. */
#define ALT_TMR_SYS_1_TMR_TMR1INTSTAT_ADDR  ALT_TMR_TMR1INTSTAT_ADDR(ALT_TMR_SYS_1_TMR_ADDR)
/* The address of the ALT_TMR_TMRSINTSTAT register for the ALT_TMR_SYS_1_TMR instance. */
#define ALT_TMR_SYS_1_TMR_TMRSINTSTAT_ADDR  ALT_TMR_TMRSINTSTAT_ADDR(ALT_TMR_SYS_1_TMR_ADDR)
/* The address of the ALT_TMR_TMRSEOI register for the ALT_TMR_SYS_1_TMR instance. */
#define ALT_TMR_SYS_1_TMR_TMRSEOI_ADDR  ALT_TMR_TMRSEOI_ADDR(ALT_TMR_SYS_1_TMR_ADDR)
/* The address of the ALT_TMR_TMRSRAWINTSTAT register for the ALT_TMR_SYS_1_TMR instance. */
#define ALT_TMR_SYS_1_TMR_TMRSRAWINTSTAT_ADDR  ALT_TMR_TMRSRAWINTSTAT_ADDR(ALT_TMR_SYS_1_TMR_ADDR)
/* The address of the ALT_TMR_TMRSCOMPVER register for the ALT_TMR_SYS_1_TMR instance. */
#define ALT_TMR_SYS_1_TMR_TMRSCOMPVER_ADDR  ALT_TMR_TMRSCOMPVER_ADDR(ALT_TMR_SYS_1_TMR_ADDR)
/* The base address byte offset for the start of the ALT_TMR_SYS_1_TMR component. */
#define ALT_TMR_SYS_1_TMR_OFST        0xffd00100
/* The start address of the ALT_TMR_SYS_1_TMR component. */
#define ALT_TMR_SYS_1_TMR_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_TMR_SYS_1_TMR_OFST))
/* The lower bound address range of the ALT_TMR_SYS_1_TMR component. */
#define ALT_TMR_SYS_1_TMR_LB_ADDR     ALT_TMR_SYS_1_TMR_ADDR
/* The upper bound address range of the ALT_TMR_SYS_1_TMR component. */
#define ALT_TMR_SYS_1_TMR_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_TMR_SYS_1_TMR_ADDR) + 0x100) - 1))


/*
 * Component Instance : i_watchdog_0_l4wd
 * 
 * Instance i_watchdog_0_l4wd of component ALT_L4WD.
 * 
 * 
 */
/* The address of the ALT_L4WD_CR register for the ALT_L4WD0 instance. */
#define ALT_L4WD0_WDT_CR_ADDR  ALT_L4WD_CR_ADDR(ALT_L4WD0_ADDR)
/* The address of the ALT_L4WD_TORR register for the ALT_L4WD0 instance. */
#define ALT_L4WD0_WDT_TORR_ADDR  ALT_L4WD_TORR_ADDR(ALT_L4WD0_ADDR)
/* The address of the ALT_L4WD_CCVR register for the ALT_L4WD0 instance. */
#define ALT_L4WD0_WDT_CCVR_ADDR  ALT_L4WD_CCVR_ADDR(ALT_L4WD0_ADDR)
/* The address of the ALT_L4WD_CRR register for the ALT_L4WD0 instance. */
#define ALT_L4WD0_WDT_CRR_ADDR  ALT_L4WD_CRR_ADDR(ALT_L4WD0_ADDR)
/* The address of the ALT_L4WD_STAT register for the ALT_L4WD0 instance. */
#define ALT_L4WD0_WDT_STAT_ADDR  ALT_L4WD_STAT_ADDR(ALT_L4WD0_ADDR)
/* The address of the ALT_L4WD_EOI register for the ALT_L4WD0 instance. */
#define ALT_L4WD0_WDT_EOI_ADDR  ALT_L4WD_EOI_ADDR(ALT_L4WD0_ADDR)
/* The address of the ALT_L4WD_CP_WDT_USER_TOP_MAX register for the ALT_L4WD0 instance. */
#define ALT_L4WD0_CP_WDT_USER_TOP_MAX_ADDR  ALT_L4WD_CP_WDT_USER_TOP_MAX_ADDR(ALT_L4WD0_ADDR)
/* The address of the ALT_L4WD_CP_WDT_USER_TOP_INIT_MAX register for the ALT_L4WD0 instance. */
#define ALT_L4WD0_CP_WDT_USER_TOP_INIT_MAX_ADDR  ALT_L4WD_CP_WDT_USER_TOP_INIT_MAX_ADDR(ALT_L4WD0_ADDR)
/* The address of the ALT_L4WD_CD_WDT_TOP_RST register for the ALT_L4WD0 instance. */
#define ALT_L4WD0_CD_WDT_TOP_RST_ADDR  ALT_L4WD_CD_WDT_TOP_RST_ADDR(ALT_L4WD0_ADDR)
/* The address of the ALT_L4WD_CP_WDT_CNT_RST register for the ALT_L4WD0 instance. */
#define ALT_L4WD0_CP_WDT_CNT_RST_ADDR  ALT_L4WD_CP_WDT_CNT_RST_ADDR(ALT_L4WD0_ADDR)
/* The address of the ALT_L4WD_COMP_PARAM_1 register for the ALT_L4WD0 instance. */
#define ALT_L4WD0_WDT_COMP_PARAM_1_ADDR  ALT_L4WD_COMP_PARAM_1_ADDR(ALT_L4WD0_ADDR)
/* The address of the ALT_L4WD_COMP_VER register for the ALT_L4WD0 instance. */
#define ALT_L4WD0_WDT_COMP_VER_ADDR  ALT_L4WD_COMP_VER_ADDR(ALT_L4WD0_ADDR)
/* The address of the ALT_L4WD_COMP_TYPE register for the ALT_L4WD0 instance. */
#define ALT_L4WD0_WDT_COMP_TYPE_ADDR  ALT_L4WD_COMP_TYPE_ADDR(ALT_L4WD0_ADDR)
/* The base address byte offset for the start of the ALT_L4WD0 component. */
#define ALT_L4WD0_OFST        0xffd00200
/* The start address of the ALT_L4WD0 component. */
#define ALT_L4WD0_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_L4WD0_OFST))
/* The lower bound address range of the ALT_L4WD0 component. */
#define ALT_L4WD0_LB_ADDR     ALT_L4WD0_ADDR
/* The upper bound address range of the ALT_L4WD0 component. */
#define ALT_L4WD0_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_L4WD0_ADDR) + 0x100) - 1))


/*
 * Component Instance : i_watchdog_1_l4wd
 * 
 * Instance i_watchdog_1_l4wd of component ALT_L4WD.
 * 
 * 
 */
/* The address of the ALT_L4WD_CR register for the ALT_L4WD1 instance. */
#define ALT_L4WD1_WDT_CR_ADDR  ALT_L4WD_CR_ADDR(ALT_L4WD1_ADDR)
/* The address of the ALT_L4WD_TORR register for the ALT_L4WD1 instance. */
#define ALT_L4WD1_WDT_TORR_ADDR  ALT_L4WD_TORR_ADDR(ALT_L4WD1_ADDR)
/* The address of the ALT_L4WD_CCVR register for the ALT_L4WD1 instance. */
#define ALT_L4WD1_WDT_CCVR_ADDR  ALT_L4WD_CCVR_ADDR(ALT_L4WD1_ADDR)
/* The address of the ALT_L4WD_CRR register for the ALT_L4WD1 instance. */
#define ALT_L4WD1_WDT_CRR_ADDR  ALT_L4WD_CRR_ADDR(ALT_L4WD1_ADDR)
/* The address of the ALT_L4WD_STAT register for the ALT_L4WD1 instance. */
#define ALT_L4WD1_WDT_STAT_ADDR  ALT_L4WD_STAT_ADDR(ALT_L4WD1_ADDR)
/* The address of the ALT_L4WD_EOI register for the ALT_L4WD1 instance. */
#define ALT_L4WD1_WDT_EOI_ADDR  ALT_L4WD_EOI_ADDR(ALT_L4WD1_ADDR)
/* The address of the ALT_L4WD_CP_WDT_USER_TOP_MAX register for the ALT_L4WD1 instance. */
#define ALT_L4WD1_CP_WDT_USER_TOP_MAX_ADDR  ALT_L4WD_CP_WDT_USER_TOP_MAX_ADDR(ALT_L4WD1_ADDR)
/* The address of the ALT_L4WD_CP_WDT_USER_TOP_INIT_MAX register for the ALT_L4WD1 instance. */
#define ALT_L4WD1_CP_WDT_USER_TOP_INIT_MAX_ADDR  ALT_L4WD_CP_WDT_USER_TOP_INIT_MAX_ADDR(ALT_L4WD1_ADDR)
/* The address of the ALT_L4WD_CD_WDT_TOP_RST register for the ALT_L4WD1 instance. */
#define ALT_L4WD1_CD_WDT_TOP_RST_ADDR  ALT_L4WD_CD_WDT_TOP_RST_ADDR(ALT_L4WD1_ADDR)
/* The address of the ALT_L4WD_CP_WDT_CNT_RST register for the ALT_L4WD1 instance. */
#define ALT_L4WD1_CP_WDT_CNT_RST_ADDR  ALT_L4WD_CP_WDT_CNT_RST_ADDR(ALT_L4WD1_ADDR)
/* The address of the ALT_L4WD_COMP_PARAM_1 register for the ALT_L4WD1 instance. */
#define ALT_L4WD1_WDT_COMP_PARAM_1_ADDR  ALT_L4WD_COMP_PARAM_1_ADDR(ALT_L4WD1_ADDR)
/* The address of the ALT_L4WD_COMP_VER register for the ALT_L4WD1 instance. */
#define ALT_L4WD1_WDT_COMP_VER_ADDR  ALT_L4WD_COMP_VER_ADDR(ALT_L4WD1_ADDR)
/* The address of the ALT_L4WD_COMP_TYPE register for the ALT_L4WD1 instance. */
#define ALT_L4WD1_WDT_COMP_TYPE_ADDR  ALT_L4WD_COMP_TYPE_ADDR(ALT_L4WD1_ADDR)
/* The base address byte offset for the start of the ALT_L4WD1 component. */
#define ALT_L4WD1_OFST        0xffd00300
/* The start address of the ALT_L4WD1 component. */
#define ALT_L4WD1_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_L4WD1_OFST))
/* The lower bound address range of the ALT_L4WD1 component. */
#define ALT_L4WD1_LB_ADDR     ALT_L4WD1_ADDR
/* The upper bound address range of the ALT_L4WD1 component. */
#define ALT_L4WD1_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_L4WD1_ADDR) + 0x100) - 1))


/*
 * Component Instance : i_fpga_mgr_fpgamgrregs
 * 
 * Instance i_fpga_mgr_fpgamgrregs of component ALT_FPGAMGR.
 * 
 * 
 */
/* The address of the ALT_FPGAMGR_DCLKCNT register for the ALT_FPGAMGR instance. */
#define ALT_FPGAMGR_DCLKCNT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_FPGAMGR_ADDR) + ALT_FPGAMGR_DCLKCNT_OFST))
/* The address of the ALT_FPGAMGR_DCLKSTAT register for the ALT_FPGAMGR instance. */
#define ALT_FPGAMGR_DCLKSTAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_FPGAMGR_ADDR) + ALT_FPGAMGR_DCLKSTAT_OFST))
/* The address of the ALT_FPGAMGR_GPO register for the ALT_FPGAMGR instance. */
#define ALT_FPGAMGR_GPO_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_FPGAMGR_ADDR) + ALT_FPGAMGR_GPO_OFST))
/* The address of the ALT_FPGAMGR_GPI register for the ALT_FPGAMGR instance. */
#define ALT_FPGAMGR_GPI_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_FPGAMGR_ADDR) + ALT_FPGAMGR_GPI_OFST))
/* The address of the ALT_FPGAMGR_MISCI register for the ALT_FPGAMGR instance. */
#define ALT_FPGAMGR_MISCI_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_FPGAMGR_ADDR) + ALT_FPGAMGR_MISCI_OFST))
/* The address of the ALT_FPGAMGR_EMR_DATA0 register for the ALT_FPGAMGR instance. */
#define ALT_FPGAMGR_EMR_DATA0_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_FPGAMGR_ADDR) + ALT_FPGAMGR_EMR_DATA0_OFST))
/* The address of the ALT_FPGAMGR_EMR_DATA1 register for the ALT_FPGAMGR instance. */
#define ALT_FPGAMGR_EMR_DATA1_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_FPGAMGR_ADDR) + ALT_FPGAMGR_EMR_DATA1_OFST))
/* The address of the ALT_FPGAMGR_EMR_DATA2 register for the ALT_FPGAMGR instance. */
#define ALT_FPGAMGR_EMR_DATA2_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_FPGAMGR_ADDR) + ALT_FPGAMGR_EMR_DATA2_OFST))
/* The address of the ALT_FPGAMGR_EMR_DATA3 register for the ALT_FPGAMGR instance. */
#define ALT_FPGAMGR_EMR_DATA3_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_FPGAMGR_ADDR) + ALT_FPGAMGR_EMR_DATA3_OFST))
/* The address of the ALT_FPGAMGR_EMR_DATA4 register for the ALT_FPGAMGR instance. */
#define ALT_FPGAMGR_EMR_DATA4_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_FPGAMGR_ADDR) + ALT_FPGAMGR_EMR_DATA4_OFST))
/* The address of the ALT_FPGAMGR_EMR_DATA5 register for the ALT_FPGAMGR instance. */
#define ALT_FPGAMGR_EMR_DATA5_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_FPGAMGR_ADDR) + ALT_FPGAMGR_EMR_DATA5_OFST))
/* The address of the ALT_FPGAMGR_EMR_VALID register for the ALT_FPGAMGR instance. */
#define ALT_FPGAMGR_EMR_VALID_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_FPGAMGR_ADDR) + ALT_FPGAMGR_EMR_VALID_OFST))
/* The address of the ALT_FPGAMGR_EMR_EN register for the ALT_FPGAMGR instance. */
#define ALT_FPGAMGR_EMR_EN_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_FPGAMGR_ADDR) + ALT_FPGAMGR_EMR_EN_OFST))
/* The address of the ALT_FPGAMGR_JTAG_CFG register for the ALT_FPGAMGR instance. */
#define ALT_FPGAMGR_JTAG_CFG_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_FPGAMGR_ADDR) + ALT_FPGAMGR_JTAG_CFG_OFST))
/* The address of the ALT_FPGAMGR_JTAG_STAT register for the ALT_FPGAMGR instance. */
#define ALT_FPGAMGR_JTAG_STAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_FPGAMGR_ADDR) + ALT_FPGAMGR_JTAG_STAT_OFST))
/* The address of the ALT_FPGAMGR_JTAG_KICK register for the ALT_FPGAMGR instance. */
#define ALT_FPGAMGR_JTAG_KICK_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_FPGAMGR_ADDR) + ALT_FPGAMGR_JTAG_KICK_OFST))
/* The address of the ALT_FPGAMGR_JTAG_DATA_W register for the ALT_FPGAMGR instance. */
#define ALT_FPGAMGR_JTAG_DATA_W_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_FPGAMGR_ADDR) + ALT_FPGAMGR_JTAG_DATA_W_OFST))
/* The address of the ALT_FPGAMGR_JTAG_DATA_R register for the ALT_FPGAMGR instance. */
#define ALT_FPGAMGR_JTAG_DATA_R_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_FPGAMGR_ADDR) + ALT_FPGAMGR_JTAG_DATA_R_OFST))
/* The address of the ALT_FPGAMGR_IMGCFG_CTL_00 register for the ALT_FPGAMGR instance. */
#define ALT_FPGAMGR_IMGCFG_CTL_00_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_FPGAMGR_ADDR) + ALT_FPGAMGR_IMGCFG_CTL_00_OFST))
/* The address of the ALT_FPGAMGR_IMGCFG_CTL_01 register for the ALT_FPGAMGR instance. */
#define ALT_FPGAMGR_IMGCFG_CTL_01_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_FPGAMGR_ADDR) + ALT_FPGAMGR_IMGCFG_CTL_01_OFST))
/* The address of the ALT_FPGAMGR_IMGCFG_CTL_02 register for the ALT_FPGAMGR instance. */
#define ALT_FPGAMGR_IMGCFG_CTL_02_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_FPGAMGR_ADDR) + ALT_FPGAMGR_IMGCFG_CTL_02_OFST))
/* The address of the ALT_FPGAMGR_IMGCFG_STAT register for the ALT_FPGAMGR instance. */
#define ALT_FPGAMGR_IMGCFG_STAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_FPGAMGR_ADDR) + ALT_FPGAMGR_IMGCFG_STAT_OFST))
/* The address of the ALT_FPGAMGR_INTR_MSKED_STAT register for the ALT_FPGAMGR instance. */
#define ALT_FPGAMGR_INTR_MSKED_STAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_FPGAMGR_ADDR) + ALT_FPGAMGR_INTR_MSKED_STAT_OFST))
/* The address of the ALT_FPGAMGR_INTR_MSK register for the ALT_FPGAMGR instance. */
#define ALT_FPGAMGR_INTR_MSK_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_FPGAMGR_ADDR) + ALT_FPGAMGR_INTR_MSK_OFST))
/* The address of the ALT_FPGAMGR_INTR_POL register for the ALT_FPGAMGR instance. */
#define ALT_FPGAMGR_INTR_POL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_FPGAMGR_ADDR) + ALT_FPGAMGR_INTR_POL_OFST))
/* The address of the ALT_FPGAMGR_DMA_CFG register for the ALT_FPGAMGR instance. */
#define ALT_FPGAMGR_DMA_CFG_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_FPGAMGR_ADDR) + ALT_FPGAMGR_DMA_CFG_OFST))
/* The address of the ALT_FPGAMGR_IMGCFG_FIFO_STAT register for the ALT_FPGAMGR instance. */
#define ALT_FPGAMGR_IMGCFG_FIFO_STAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_FPGAMGR_ADDR) + ALT_FPGAMGR_IMGCFG_FIFO_STAT_OFST))
/* The base address byte offset for the start of the ALT_FPGAMGR component. */
#define ALT_FPGAMGR_OFST        0xffd03000

#ifdef LINUX_TASK_MODE 
#define VIRTUAL_FPGAMGR_OFSET (uint32_t) __hps_virtualAdreess_FPGAMGR
#else 
#define VIRTUAL_FPGAMGR_OFSET ALT_FPGAMGR_OFST
#endif


/* The start address of the ALT_FPGAMGR component. */
#define ALT_FPGAMGR_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + VIRTUAL_FPGAMGR_OFSET))
/* The lower bound address range of the ALT_FPGAMGR component. */
#define ALT_FPGAMGR_LB_ADDR     ALT_FPGAMGR_ADDR
/* The upper bound address range of the ALT_FPGAMGR component. */
#define ALT_FPGAMGR_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_FPGAMGR_ADDR) + 0x1000) - 1))


/*
 * Component Instance : i_clk_mgr_clkmgr
 * 
 * Instance i_clk_mgr_clkmgr of component ALT_CLKMGR_CLKMGR.
 * 
 * 
 */
/* The address of the ALT_CLKMGR_CLKMGR_CTL register for the ALT_CLKMGR_CLKMGR instance. */
#define ALT_CLKMGR_CLKMGR_CTL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_CLKMGR_CLKMGR_ADDR) + ALT_CLKMGR_CLKMGR_CTL_OFST))
/* The address of the ALT_CLKMGR_CLKMGR_INTR register for the ALT_CLKMGR_CLKMGR instance. */
#define ALT_CLKMGR_CLKMGR_INTR_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_CLKMGR_CLKMGR_ADDR) + ALT_CLKMGR_CLKMGR_INTR_OFST))
/* The address of the ALT_CLKMGR_CLKMGR_INTRS register for the ALT_CLKMGR_CLKMGR instance. */
#define ALT_CLKMGR_CLKMGR_INTRS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_CLKMGR_CLKMGR_ADDR) + ALT_CLKMGR_CLKMGR_INTRS_OFST))
/* The address of the ALT_CLKMGR_CLKMGR_INTRR register for the ALT_CLKMGR_CLKMGR instance. */
#define ALT_CLKMGR_CLKMGR_INTRR_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_CLKMGR_CLKMGR_ADDR) + ALT_CLKMGR_CLKMGR_INTRR_OFST))
/* The address of the ALT_CLKMGR_CLKMGR_INTREN register for the ALT_CLKMGR_CLKMGR instance. */
#define ALT_CLKMGR_CLKMGR_INTREN_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_CLKMGR_CLKMGR_ADDR) + ALT_CLKMGR_CLKMGR_INTREN_OFST))
/* The address of the ALT_CLKMGR_CLKMGR_INTRENS register for the ALT_CLKMGR_CLKMGR instance. */
#define ALT_CLKMGR_CLKMGR_INTRENS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_CLKMGR_CLKMGR_ADDR) + ALT_CLKMGR_CLKMGR_INTRENS_OFST))
/* The address of the ALT_CLKMGR_CLKMGR_INTRENR register for the ALT_CLKMGR_CLKMGR instance. */
#define ALT_CLKMGR_CLKMGR_INTRENR_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_CLKMGR_CLKMGR_ADDR) + ALT_CLKMGR_CLKMGR_INTRENR_OFST))
/* The address of the ALT_CLKMGR_CLKMGR_STAT register for the ALT_CLKMGR_CLKMGR instance. */
#define ALT_CLKMGR_CLKMGR_STAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_CLKMGR_CLKMGR_ADDR) + ALT_CLKMGR_CLKMGR_STAT_OFST))
/* The address of the ALT_CLKMGR_CLKMGR_TESTIOCTL register for the ALT_CLKMGR_CLKMGR instance. */
#define ALT_CLKMGR_CLKMGR_TESTIOCTL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_CLKMGR_CLKMGR_ADDR) + ALT_CLKMGR_CLKMGR_TESTIOCTL_OFST))
/* The base address byte offset for the start of the ALT_CLKMGR_CLKMGR component. */
#define ALT_CLKMGR_CLKMGR_OFST        0xffd04000
/* The start address of the ALT_CLKMGR_CLKMGR component. */
#define ALT_CLKMGR_CLKMGR_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_CLKMGR_CLKMGR_OFST))
/* The lower bound address range of the ALT_CLKMGR_CLKMGR component. */
#define ALT_CLKMGR_CLKMGR_LB_ADDR     ALT_CLKMGR_CLKMGR_ADDR
/* The upper bound address range of the ALT_CLKMGR_CLKMGR component. */
#define ALT_CLKMGR_CLKMGR_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_CLKMGR_CLKMGR_ADDR) + 0x40) - 1))


/*
 * Component Instance : i_clk_mgr_mainpllgrp
 * 
 * Instance i_clk_mgr_mainpllgrp of component ALT_CLKMGR_MAINPLL.
 * 
 * 
 */
/* The address of the ALT_CLKMGR_MAINPLL_VCO0 register for the ALT_CLKMGR_MAINPLL instance. */
#define ALT_CLKMGR_MAINPLL_VCO0_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_CLKMGR_MAINPLL_ADDR) + ALT_CLKMGR_MAINPLL_VCO0_OFST))
/* The address of the ALT_CLKMGR_MAINPLL_VCO1 register for the ALT_CLKMGR_MAINPLL instance. */
#define ALT_CLKMGR_MAINPLL_VCO1_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_CLKMGR_MAINPLL_ADDR) + ALT_CLKMGR_MAINPLL_VCO1_OFST))
/* The address of the ALT_CLKMGR_MAINPLL_EN register for the ALT_CLKMGR_MAINPLL instance. */
#define ALT_CLKMGR_MAINPLL_EN_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_CLKMGR_MAINPLL_ADDR) + ALT_CLKMGR_MAINPLL_EN_OFST))
/* The address of the ALT_CLKMGR_MAINPLL_ENS register for the ALT_CLKMGR_MAINPLL instance. */
#define ALT_CLKMGR_MAINPLL_ENS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_CLKMGR_MAINPLL_ADDR) + ALT_CLKMGR_MAINPLL_ENS_OFST))
/* The address of the ALT_CLKMGR_MAINPLL_ENR register for the ALT_CLKMGR_MAINPLL instance. */
#define ALT_CLKMGR_MAINPLL_ENR_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_CLKMGR_MAINPLL_ADDR) + ALT_CLKMGR_MAINPLL_ENR_OFST))
/* The address of the ALT_CLKMGR_MAINPLL_BYPASS register for the ALT_CLKMGR_MAINPLL instance. */
#define ALT_CLKMGR_MAINPLL_BYPASS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_CLKMGR_MAINPLL_ADDR) + ALT_CLKMGR_MAINPLL_BYPASS_OFST))
/* The address of the ALT_CLKMGR_MAINPLL_BYPASSS register for the ALT_CLKMGR_MAINPLL instance. */
#define ALT_CLKMGR_MAINPLL_BYPASSS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_CLKMGR_MAINPLL_ADDR) + ALT_CLKMGR_MAINPLL_BYPASSS_OFST))
/* The address of the ALT_CLKMGR_MAINPLL_BYPASSR register for the ALT_CLKMGR_MAINPLL instance. */
#define ALT_CLKMGR_MAINPLL_BYPASSR_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_CLKMGR_MAINPLL_ADDR) + ALT_CLKMGR_MAINPLL_BYPASSR_OFST))
/* The address of the ALT_CLKMGR_MAINPLL_MPUCLK register for the ALT_CLKMGR_MAINPLL instance. */
#define ALT_CLKMGR_MAINPLL_MPUCLK_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_CLKMGR_MAINPLL_ADDR) + ALT_CLKMGR_MAINPLL_MPUCLK_OFST))
/* The address of the ALT_CLKMGR_MAINPLL_NOCCLK register for the ALT_CLKMGR_MAINPLL instance. */
#define ALT_CLKMGR_MAINPLL_NOCCLK_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_CLKMGR_MAINPLL_ADDR) + ALT_CLKMGR_MAINPLL_NOCCLK_OFST))
/* The address of the ALT_CLKMGR_MAINPLL_CNTR2CLK register for the ALT_CLKMGR_MAINPLL instance. */
#define ALT_CLKMGR_MAINPLL_CNTR2CLK_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_CLKMGR_MAINPLL_ADDR) + ALT_CLKMGR_MAINPLL_CNTR2CLK_OFST))
/* The address of the ALT_CLKMGR_MAINPLL_CNTR3CLK register for the ALT_CLKMGR_MAINPLL instance. */
#define ALT_CLKMGR_MAINPLL_CNTR3CLK_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_CLKMGR_MAINPLL_ADDR) + ALT_CLKMGR_MAINPLL_CNTR3CLK_OFST))
/* The address of the ALT_CLKMGR_MAINPLL_CNTR4CLK register for the ALT_CLKMGR_MAINPLL instance. */
#define ALT_CLKMGR_MAINPLL_CNTR4CLK_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_CLKMGR_MAINPLL_ADDR) + ALT_CLKMGR_MAINPLL_CNTR4CLK_OFST))
/* The address of the ALT_CLKMGR_MAINPLL_CNTR5CLK register for the ALT_CLKMGR_MAINPLL instance. */
#define ALT_CLKMGR_MAINPLL_CNTR5CLK_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_CLKMGR_MAINPLL_ADDR) + ALT_CLKMGR_MAINPLL_CNTR5CLK_OFST))
/* The address of the ALT_CLKMGR_MAINPLL_CNTR6CLK register for the ALT_CLKMGR_MAINPLL instance. */
#define ALT_CLKMGR_MAINPLL_CNTR6CLK_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_CLKMGR_MAINPLL_ADDR) + ALT_CLKMGR_MAINPLL_CNTR6CLK_OFST))
/* The address of the ALT_CLKMGR_MAINPLL_CNTR7CLK register for the ALT_CLKMGR_MAINPLL instance. */
#define ALT_CLKMGR_MAINPLL_CNTR7CLK_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_CLKMGR_MAINPLL_ADDR) + ALT_CLKMGR_MAINPLL_CNTR7CLK_OFST))
/* The address of the ALT_CLKMGR_MAINPLL_CNTR8CLK register for the ALT_CLKMGR_MAINPLL instance. */
#define ALT_CLKMGR_MAINPLL_CNTR8CLK_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_CLKMGR_MAINPLL_ADDR) + ALT_CLKMGR_MAINPLL_CNTR8CLK_OFST))
/* The address of the ALT_CLKMGR_MAINPLL_CNTR9CLK register for the ALT_CLKMGR_MAINPLL instance. */
#define ALT_CLKMGR_MAINPLL_CNTR9CLK_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_CLKMGR_MAINPLL_ADDR) + ALT_CLKMGR_MAINPLL_CNTR9CLK_OFST))
/* The address of the ALT_CLKMGR_MAINPLL_CNTR15CLK register for the ALT_CLKMGR_MAINPLL instance. */
#define ALT_CLKMGR_MAINPLL_CNTR15CLK_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_CLKMGR_MAINPLL_ADDR) + ALT_CLKMGR_MAINPLL_CNTR15CLK_OFST))
/* The address of the ALT_CLKMGR_MAINPLL_OUTRST register for the ALT_CLKMGR_MAINPLL instance. */
#define ALT_CLKMGR_MAINPLL_OUTRST_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_CLKMGR_MAINPLL_ADDR) + ALT_CLKMGR_MAINPLL_OUTRST_OFST))
/* The address of the ALT_CLKMGR_MAINPLL_OUTRSTSTAT register for the ALT_CLKMGR_MAINPLL instance. */
#define ALT_CLKMGR_MAINPLL_OUTRSTSTAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_CLKMGR_MAINPLL_ADDR) + ALT_CLKMGR_MAINPLL_OUTRSTSTAT_OFST))
/* The address of the ALT_CLKMGR_MAINPLL_NOCDIV register for the ALT_CLKMGR_MAINPLL instance. */
#define ALT_CLKMGR_MAINPLL_NOCDIV_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_CLKMGR_MAINPLL_ADDR) + ALT_CLKMGR_MAINPLL_NOCDIV_OFST))
/* The base address byte offset for the start of the ALT_CLKMGR_MAINPLL component. */
#define ALT_CLKMGR_MAINPLL_OFST        0xffd04040
/* The start address of the ALT_CLKMGR_MAINPLL component. */
#define ALT_CLKMGR_MAINPLL_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_CLKMGR_MAINPLL_OFST))
/* The lower bound address range of the ALT_CLKMGR_MAINPLL component. */
#define ALT_CLKMGR_MAINPLL_LB_ADDR     ALT_CLKMGR_MAINPLL_ADDR
/* The upper bound address range of the ALT_CLKMGR_MAINPLL component. */
#define ALT_CLKMGR_MAINPLL_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_CLKMGR_MAINPLL_ADDR) + 0x80) - 1))


/*
 * Component Instance : i_clk_mgr_perpllgrp
 * 
 * Instance i_clk_mgr_perpllgrp of component ALT_CLKMGR_PERPLL.
 * 
 * 
 */
/* The address of the ALT_CLKMGR_PERPLL_VCO0 register for the ALT_CLKMGR_PERPLL instance. */
#define ALT_CLKMGR_PERPLL_VCO0_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_CLKMGR_PERPLL_ADDR) + ALT_CLKMGR_PERPLL_VCO0_OFST))
/* The address of the ALT_CLKMGR_PERPLL_VCO1 register for the ALT_CLKMGR_PERPLL instance. */
#define ALT_CLKMGR_PERPLL_VCO1_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_CLKMGR_PERPLL_ADDR) + ALT_CLKMGR_PERPLL_VCO1_OFST))
/* The address of the ALT_CLKMGR_PERPLL_EN register for the ALT_CLKMGR_PERPLL instance. */
#define ALT_CLKMGR_PERPLL_EN_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_CLKMGR_PERPLL_ADDR) + ALT_CLKMGR_PERPLL_EN_OFST))
/* The address of the ALT_CLKMGR_PERPLL_ENS register for the ALT_CLKMGR_PERPLL instance. */
#define ALT_CLKMGR_PERPLL_ENS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_CLKMGR_PERPLL_ADDR) + ALT_CLKMGR_PERPLL_ENS_OFST))
/* The address of the ALT_CLKMGR_PERPLL_ENR register for the ALT_CLKMGR_PERPLL instance. */
#define ALT_CLKMGR_PERPLL_ENR_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_CLKMGR_PERPLL_ADDR) + ALT_CLKMGR_PERPLL_ENR_OFST))
/* The address of the ALT_CLKMGR_PERPLL_BYPASS register for the ALT_CLKMGR_PERPLL instance. */
#define ALT_CLKMGR_PERPLL_BYPASS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_CLKMGR_PERPLL_ADDR) + ALT_CLKMGR_PERPLL_BYPASS_OFST))
/* The address of the ALT_CLKMGR_PERPLL_BYPASSS register for the ALT_CLKMGR_PERPLL instance. */
#define ALT_CLKMGR_PERPLL_BYPASSS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_CLKMGR_PERPLL_ADDR) + ALT_CLKMGR_PERPLL_BYPASSS_OFST))
/* The address of the ALT_CLKMGR_PERPLL_BYPASSR register for the ALT_CLKMGR_PERPLL instance. */
#define ALT_CLKMGR_PERPLL_BYPASSR_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_CLKMGR_PERPLL_ADDR) + ALT_CLKMGR_PERPLL_BYPASSR_OFST))
/* The address of the ALT_CLKMGR_PERPLL_CNTR2CLK register for the ALT_CLKMGR_PERPLL instance. */
#define ALT_CLKMGR_PERPLL_CNTR2CLK_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_CLKMGR_PERPLL_ADDR) + ALT_CLKMGR_PERPLL_CNTR2CLK_OFST))
/* The address of the ALT_CLKMGR_PERPLL_CNTR3CLK register for the ALT_CLKMGR_PERPLL instance. */
#define ALT_CLKMGR_PERPLL_CNTR3CLK_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_CLKMGR_PERPLL_ADDR) + ALT_CLKMGR_PERPLL_CNTR3CLK_OFST))
/* The address of the ALT_CLKMGR_PERPLL_CNTR4CLK register for the ALT_CLKMGR_PERPLL instance. */
#define ALT_CLKMGR_PERPLL_CNTR4CLK_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_CLKMGR_PERPLL_ADDR) + ALT_CLKMGR_PERPLL_CNTR4CLK_OFST))
/* The address of the ALT_CLKMGR_PERPLL_CNTR5CLK register for the ALT_CLKMGR_PERPLL instance. */
#define ALT_CLKMGR_PERPLL_CNTR5CLK_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_CLKMGR_PERPLL_ADDR) + ALT_CLKMGR_PERPLL_CNTR5CLK_OFST))
/* The address of the ALT_CLKMGR_PERPLL_CNTR6CLK register for the ALT_CLKMGR_PERPLL instance. */
#define ALT_CLKMGR_PERPLL_CNTR6CLK_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_CLKMGR_PERPLL_ADDR) + ALT_CLKMGR_PERPLL_CNTR6CLK_OFST))
/* The address of the ALT_CLKMGR_PERPLL_CNTR7CLK register for the ALT_CLKMGR_PERPLL instance. */
#define ALT_CLKMGR_PERPLL_CNTR7CLK_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_CLKMGR_PERPLL_ADDR) + ALT_CLKMGR_PERPLL_CNTR7CLK_OFST))
/* The address of the ALT_CLKMGR_PERPLL_CNTR8CLK register for the ALT_CLKMGR_PERPLL instance. */
#define ALT_CLKMGR_PERPLL_CNTR8CLK_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_CLKMGR_PERPLL_ADDR) + ALT_CLKMGR_PERPLL_CNTR8CLK_OFST))
/* The address of the ALT_CLKMGR_PERPLL_CNTR9CLK register for the ALT_CLKMGR_PERPLL instance. */
#define ALT_CLKMGR_PERPLL_CNTR9CLK_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_CLKMGR_PERPLL_ADDR) + ALT_CLKMGR_PERPLL_CNTR9CLK_OFST))
/* The address of the ALT_CLKMGR_PERPLL_OUTRST register for the ALT_CLKMGR_PERPLL instance. */
#define ALT_CLKMGR_PERPLL_OUTRST_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_CLKMGR_PERPLL_ADDR) + ALT_CLKMGR_PERPLL_OUTRST_OFST))
/* The address of the ALT_CLKMGR_PERPLL_OUTRSTSTAT register for the ALT_CLKMGR_PERPLL instance. */
#define ALT_CLKMGR_PERPLL_OUTRSTSTAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_CLKMGR_PERPLL_ADDR) + ALT_CLKMGR_PERPLL_OUTRSTSTAT_OFST))
/* The address of the ALT_CLKMGR_PERPLL_EMACCTL register for the ALT_CLKMGR_PERPLL instance. */
#define ALT_CLKMGR_PERPLL_EMACCTL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_CLKMGR_PERPLL_ADDR) + ALT_CLKMGR_PERPLL_EMACCTL_OFST))
/* The address of the ALT_CLKMGR_PERPLL_GPIODIV register for the ALT_CLKMGR_PERPLL instance. */
#define ALT_CLKMGR_PERPLL_GPIODIV_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_CLKMGR_PERPLL_ADDR) + ALT_CLKMGR_PERPLL_GPIODIV_OFST))
/* The base address byte offset for the start of the ALT_CLKMGR_PERPLL component. */
#define ALT_CLKMGR_PERPLL_OFST        0xffd040c0
/* The start address of the ALT_CLKMGR_PERPLL component. */
#define ALT_CLKMGR_PERPLL_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_CLKMGR_PERPLL_OFST))
/* The lower bound address range of the ALT_CLKMGR_PERPLL component. */
#define ALT_CLKMGR_PERPLL_LB_ADDR     ALT_CLKMGR_PERPLL_ADDR
/* The upper bound address range of the ALT_CLKMGR_PERPLL component. */
#define ALT_CLKMGR_PERPLL_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_CLKMGR_PERPLL_ADDR) + 0x80) - 1))


/*
 * Component Instance : i_clk_mgr_alteragrp
 * 
 * Instance i_clk_mgr_alteragrp of component ALT_CLKMGR_ALTERA.
 * 
 * 
 */
/* The address of the ALT_CLKMGR_NOCCLK register for the ALT_CLKMGR_ALTERA instance. */
#define ALT_CLKMGR_NOCCLK_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_CLKMGR_ALTERA_ADDR) + ALT_CLKMGR_NOCCLK_OFST))
/* The base address byte offset for the start of the ALT_CLKMGR_ALTERA component. */
#define ALT_CLKMGR_ALTERA_OFST        0xffd04140
/* The start address of the ALT_CLKMGR_ALTERA component. */
#define ALT_CLKMGR_ALTERA_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_CLKMGR_ALTERA_OFST))
/* The lower bound address range of the ALT_CLKMGR_ALTERA component. */
#define ALT_CLKMGR_ALTERA_LB_ADDR     ALT_CLKMGR_ALTERA_ADDR
/* The upper bound address range of the ALT_CLKMGR_ALTERA component. */
#define ALT_CLKMGR_ALTERA_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_CLKMGR_ALTERA_ADDR) + 0x40) - 1))


/*
 * Component Instance : i_rst_mgr_rstmgr
 * 
 * Instance i_rst_mgr_rstmgr of component ALT_RSTMGR.
 * 
 * 
 */
/* The address of the ALT_RSTMGR_STAT register for the ALT_RSTMGR instance. */
#define ALT_RSTMGR_STAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_RSTMGR_ADDR) + ALT_RSTMGR_STAT_OFST))
/* The address of the ALT_RSTMGR_RAMSTAT register for the ALT_RSTMGR instance. */
#define ALT_RSTMGR_RAMSTAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_RSTMGR_ADDR) + ALT_RSTMGR_RAMSTAT_OFST))
/* The address of the ALT_RSTMGR_MISCSTAT register for the ALT_RSTMGR instance. */
#define ALT_RSTMGR_MISCSTAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_RSTMGR_ADDR) + ALT_RSTMGR_MISCSTAT_OFST))
/* The address of the ALT_RSTMGR_CTL register for the ALT_RSTMGR instance. */
#define ALT_RSTMGR_CTL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_RSTMGR_ADDR) + ALT_RSTMGR_CTL_OFST))
/* The address of the ALT_RSTMGR_HDSKEN register for the ALT_RSTMGR instance. */
#define ALT_RSTMGR_HDSKEN_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_RSTMGR_ADDR) + ALT_RSTMGR_HDSKEN_OFST))
/* The address of the ALT_RSTMGR_HDSKREQ register for the ALT_RSTMGR instance. */
#define ALT_RSTMGR_HDSKREQ_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_RSTMGR_ADDR) + ALT_RSTMGR_HDSKREQ_OFST))
/* The address of the ALT_RSTMGR_HDSKACK register for the ALT_RSTMGR instance. */
#define ALT_RSTMGR_HDSKACK_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_RSTMGR_ADDR) + ALT_RSTMGR_HDSKACK_OFST))
/* The address of the ALT_RSTMGR_COUNTS register for the ALT_RSTMGR instance. */
#define ALT_RSTMGR_COUNTS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_RSTMGR_ADDR) + ALT_RSTMGR_COUNTS_OFST))
/* The address of the ALT_RSTMGR_MPUMODRST register for the ALT_RSTMGR instance. */
#define ALT_RSTMGR_MPUMODRST_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_RSTMGR_ADDR) + ALT_RSTMGR_MPUMODRST_OFST))
/* The address of the ALT_RSTMGR_PER0MODRST register for the ALT_RSTMGR instance. */
#define ALT_RSTMGR_PER0MODRST_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_RSTMGR_ADDR) + ALT_RSTMGR_PER0MODRST_OFST))
/* The address of the ALT_RSTMGR_PER1MODRST register for the ALT_RSTMGR instance. */
#define ALT_RSTMGR_PER1MODRST_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_RSTMGR_ADDR) + ALT_RSTMGR_PER1MODRST_OFST))
/* The address of the ALT_RSTMGR_BRGMODRST register for the ALT_RSTMGR instance. */
#define ALT_RSTMGR_BRGMODRST_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_RSTMGR_ADDR) + ALT_RSTMGR_BRGMODRST_OFST))
/* The address of the ALT_RSTMGR_SYSMODRST register for the ALT_RSTMGR instance. */
#define ALT_RSTMGR_SYSMODRST_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_RSTMGR_ADDR) + ALT_RSTMGR_SYSMODRST_OFST))
/* The address of the ALT_RSTMGR_COLDMODRST register for the ALT_RSTMGR instance. */
#define ALT_RSTMGR_COLDMODRST_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_RSTMGR_ADDR) + ALT_RSTMGR_COLDMODRST_OFST))
/* The address of the ALT_RSTMGR_NRSTMODRST register for the ALT_RSTMGR instance. */
#define ALT_RSTMGR_NRSTMODRST_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_RSTMGR_ADDR) + ALT_RSTMGR_NRSTMODRST_OFST))
/* The address of the ALT_RSTMGR_DBGMODRST register for the ALT_RSTMGR instance. */
#define ALT_RSTMGR_DBGMODRST_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_RSTMGR_ADDR) + ALT_RSTMGR_DBGMODRST_OFST))
/* The address of the ALT_RSTMGR_MPUWARMMSK register for the ALT_RSTMGR instance. */
#define ALT_RSTMGR_MPUWARMMSK_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_RSTMGR_ADDR) + ALT_RSTMGR_MPUWARMMSK_OFST))
/* The address of the ALT_RSTMGR_PER0WARMMSK register for the ALT_RSTMGR instance. */
#define ALT_RSTMGR_PER0WARMMSK_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_RSTMGR_ADDR) + ALT_RSTMGR_PER0WARMMSK_OFST))
/* The address of the ALT_RSTMGR_PER1WARMMSK register for the ALT_RSTMGR instance. */
#define ALT_RSTMGR_PER1WARMMSK_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_RSTMGR_ADDR) + ALT_RSTMGR_PER1WARMMSK_OFST))
/* The address of the ALT_RSTMGR_BRGWARMMSK register for the ALT_RSTMGR instance. */
#define ALT_RSTMGR_BRGWARMMSK_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_RSTMGR_ADDR) + ALT_RSTMGR_BRGWARMMSK_OFST))
/* The address of the ALT_RSTMGR_SYSWARMMSK register for the ALT_RSTMGR instance. */
#define ALT_RSTMGR_SYSWARMMSK_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_RSTMGR_ADDR) + ALT_RSTMGR_SYSWARMMSK_OFST))
/* The address of the ALT_RSTMGR_NRSTWARMMSK register for the ALT_RSTMGR instance. */
#define ALT_RSTMGR_NRSTWARMMSK_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_RSTMGR_ADDR) + ALT_RSTMGR_NRSTWARMMSK_OFST))
/* The address of the ALT_RSTMGR_L3WARMMSK register for the ALT_RSTMGR instance. */
#define ALT_RSTMGR_L3WARMMSK_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_RSTMGR_ADDR) + ALT_RSTMGR_L3WARMMSK_OFST))
/* The address of the ALT_RSTMGR_TSTSTA register for the ALT_RSTMGR instance. */
#define ALT_RSTMGR_TSTSTA_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_RSTMGR_ADDR) + ALT_RSTMGR_TSTSTA_OFST))
/* The address of the ALT_RSTMGR_TSTSCRATCH register for the ALT_RSTMGR instance. */
#define ALT_RSTMGR_TSTSCRATCH_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_RSTMGR_ADDR) + ALT_RSTMGR_TSTSCRATCH_OFST))
/* The address of the ALT_RSTMGR_HDSKTMO register for the ALT_RSTMGR instance. */
#define ALT_RSTMGR_HDSKTMO_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_RSTMGR_ADDR) + ALT_RSTMGR_HDSKTMO_OFST))
/* The address of the ALT_RSTMGR_HMCINTR register for the ALT_RSTMGR instance. */
#define ALT_RSTMGR_HMCINTR_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_RSTMGR_ADDR) + ALT_RSTMGR_HMCINTR_OFST))
/* The address of the ALT_RSTMGR_HMCINTREN register for the ALT_RSTMGR instance. */
#define ALT_RSTMGR_HMCINTREN_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_RSTMGR_ADDR) + ALT_RSTMGR_HMCINTREN_OFST))
/* The address of the ALT_RSTMGR_HMCINTRENS register for the ALT_RSTMGR instance. */
#define ALT_RSTMGR_HMCINTRENS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_RSTMGR_ADDR) + ALT_RSTMGR_HMCINTRENS_OFST))
/* The address of the ALT_RSTMGR_HMCINTRENR register for the ALT_RSTMGR instance. */
#define ALT_RSTMGR_HMCINTRENR_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_RSTMGR_ADDR) + ALT_RSTMGR_HMCINTRENR_OFST))
/* The address of the ALT_RSTMGR_HMCGPOUT register for the ALT_RSTMGR instance. */
#define ALT_RSTMGR_HMCGPOUT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_RSTMGR_ADDR) + ALT_RSTMGR_HMCGPOUT_OFST))
/* The address of the ALT_RSTMGR_HMCGPIN register for the ALT_RSTMGR instance. */
#define ALT_RSTMGR_HMCGPIN_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_RSTMGR_ADDR) + ALT_RSTMGR_HMCGPIN_OFST))
/* The base address byte offset for the start of the ALT_RSTMGR component. */
#define ALT_RSTMGR_OFST        0xffd05000
/* The start address of the ALT_RSTMGR component. */
#define ALT_RSTMGR_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_RSTMGR_OFST))
/* The lower bound address range of the ALT_RSTMGR component. */
#define ALT_RSTMGR_LB_ADDR     ALT_RSTMGR_ADDR
/* The upper bound address range of the ALT_RSTMGR component. */
#define ALT_RSTMGR_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_RSTMGR_ADDR) + 0x100) - 1))


/*
 * Component Instance : i_sys_mgr_core
 * 
 * Instance i_sys_mgr_core of component ALT_SYSMGR.
 * 
 * 
 */
/* The address of the ALT_SYSMGR_SILICONID1 register for the ALT_SYSMGR instance. */
#define ALT_SYSMGR_SILICONID1_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SYSMGR_ADDR) + ALT_SYSMGR_SILICONID1_OFST))
/* The address of the ALT_SYSMGR_SILICONID2 register for the ALT_SYSMGR instance. */
#define ALT_SYSMGR_SILICONID2_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SYSMGR_ADDR) + ALT_SYSMGR_SILICONID2_OFST))
/* The address of the ALT_SYSMGR_WDDBG register for the ALT_SYSMGR instance. */
#define ALT_SYSMGR_WDDBG_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SYSMGR_ADDR) + ALT_SYSMGR_WDDBG_OFST))
/* The address of the ALT_SYSMGR_BOOT register for the ALT_SYSMGR instance. */
#define ALT_SYSMGR_BOOT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SYSMGR_ADDR) + ALT_SYSMGR_BOOT_OFST))
/* The address of the ALT_SYSMGR_MPU_CTL_L2_ECC register for the ALT_SYSMGR instance. */
#define ALT_SYSMGR_MPU_CTL_L2_ECC_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SYSMGR_ADDR) + ALT_SYSMGR_MPU_CTL_L2_ECC_OFST))
/* The address of the ALT_SYSMGR_DMA register for the ALT_SYSMGR instance. */
#define ALT_SYSMGR_DMA_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SYSMGR_ADDR) + ALT_SYSMGR_DMA_OFST))
/* The address of the ALT_SYSMGR_DMA_PERIPH register for the ALT_SYSMGR instance. */
#define ALT_SYSMGR_DMA_PERIPH_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SYSMGR_ADDR) + ALT_SYSMGR_DMA_PERIPH_OFST))
/* The address of the ALT_SYSMGR_SDMMC register for the ALT_SYSMGR instance. */
#define ALT_SYSMGR_SDMMC_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SYSMGR_ADDR) + ALT_SYSMGR_SDMMC_OFST))
/* The address of the ALT_SYSMGR_SDMMC_L3MST register for the ALT_SYSMGR instance. */
#define ALT_SYSMGR_SDMMC_L3MST_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SYSMGR_ADDR) + ALT_SYSMGR_SDMMC_L3MST_OFST))
/* The address of the ALT_SYSMGR_NAND_BOOTSTRAP register for the ALT_SYSMGR instance. */
#define ALT_SYSMGR_NAND_BOOTSTRAP_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SYSMGR_ADDR) + ALT_SYSMGR_NAND_BOOTSTRAP_OFST))
/* The address of the ALT_SYSMGR_NAND_L3MST register for the ALT_SYSMGR instance. */
#define ALT_SYSMGR_NAND_L3MST_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SYSMGR_ADDR) + ALT_SYSMGR_NAND_L3MST_OFST))
/* The address of the ALT_SYSMGR_USB0_L3MST register for the ALT_SYSMGR instance. */
#define ALT_SYSMGR_USB0_L3MST_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SYSMGR_ADDR) + ALT_SYSMGR_USB0_L3MST_OFST))
/* The address of the ALT_SYSMGR_USB1_L3MST register for the ALT_SYSMGR instance. */
#define ALT_SYSMGR_USB1_L3MST_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SYSMGR_ADDR) + ALT_SYSMGR_USB1_L3MST_OFST))
/* The address of the ALT_SYSMGR_EMAC_GLOB register for the ALT_SYSMGR instance. */
#define ALT_SYSMGR_EMAC_GLOB_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SYSMGR_ADDR) + ALT_SYSMGR_EMAC_GLOB_OFST))
/* The address of the ALT_SYSMGR_EMAC0 register for the ALT_SYSMGR instance. */
#define ALT_SYSMGR_EMAC0_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SYSMGR_ADDR) + ALT_SYSMGR_EMAC0_OFST))
/* The address of the ALT_SYSMGR_EMAC1 register for the ALT_SYSMGR instance. */
#define ALT_SYSMGR_EMAC1_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SYSMGR_ADDR) + ALT_SYSMGR_EMAC1_OFST))
/* The address of the ALT_SYSMGR_EMAC2 register for the ALT_SYSMGR instance. */
#define ALT_SYSMGR_EMAC2_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SYSMGR_ADDR) + ALT_SYSMGR_EMAC2_OFST))
/* The address of the ALT_SYSMGR_FPGAINTF_EN_GLOB register for the ALT_SYSMGR instance. */
#define ALT_SYSMGR_FPGAINTF_EN_GLOB_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SYSMGR_ADDR) + ALT_SYSMGR_FPGAINTF_EN_GLOB_OFST))
/* The address of the ALT_SYSMGR_FPGAINTF_EN_0 register for the ALT_SYSMGR instance. */
#define ALT_SYSMGR_FPGAINTF_EN_0_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SYSMGR_ADDR) + ALT_SYSMGR_FPGAINTF_EN_0_OFST))
/* The address of the ALT_SYSMGR_FPGAINTF_EN_1 register for the ALT_SYSMGR instance. */
#define ALT_SYSMGR_FPGAINTF_EN_1_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SYSMGR_ADDR) + ALT_SYSMGR_FPGAINTF_EN_1_OFST))
/* The address of the ALT_SYSMGR_FPGAINTF_EN_2 register for the ALT_SYSMGR instance. */
#define ALT_SYSMGR_FPGAINTF_EN_2_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SYSMGR_ADDR) + ALT_SYSMGR_FPGAINTF_EN_2_OFST))
/* The address of the ALT_SYSMGR_FPGAINTF_EN_3 register for the ALT_SYSMGR instance. */
#define ALT_SYSMGR_FPGAINTF_EN_3_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SYSMGR_ADDR) + ALT_SYSMGR_FPGAINTF_EN_3_OFST))
/* The address of the ALT_SYSMGR_NOC_ADDR_REMAP_VALUE register for the ALT_SYSMGR instance. */
#define ALT_SYSMGR_NOC_ADDR_REMAP_VALUE_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SYSMGR_ADDR) + ALT_SYSMGR_NOC_ADDR_REMAP_VALUE_OFST))
/* The address of the ALT_SYSMGR_NOC_ADDR_REMAP_SET register for the ALT_SYSMGR instance. */
#define ALT_SYSMGR_NOC_ADDR_REMAP_SET_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SYSMGR_ADDR) + ALT_SYSMGR_NOC_ADDR_REMAP_SET_OFST))
/* The address of the ALT_SYSMGR_NOC_ADDR_REMAP_CLR register for the ALT_SYSMGR instance. */
#define ALT_SYSMGR_NOC_ADDR_REMAP_CLR_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SYSMGR_ADDR) + ALT_SYSMGR_NOC_ADDR_REMAP_CLR_OFST))
/* The address of the ALT_SYSMGR_ECC_INTMSK_VALUE register for the ALT_SYSMGR instance. */
#define ALT_SYSMGR_ECC_INTMSK_VALUE_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SYSMGR_ADDR) + ALT_SYSMGR_ECC_INTMSK_VALUE_OFST))
/* The address of the ALT_SYSMGR_ECC_INTMSK_SET register for the ALT_SYSMGR instance. */
#define ALT_SYSMGR_ECC_INTMSK_SET_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SYSMGR_ADDR) + ALT_SYSMGR_ECC_INTMSK_SET_OFST))
/* The address of the ALT_SYSMGR_ECC_INTMSK_CLR register for the ALT_SYSMGR instance. */
#define ALT_SYSMGR_ECC_INTMSK_CLR_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SYSMGR_ADDR) + ALT_SYSMGR_ECC_INTMSK_CLR_OFST))
/* The address of the ALT_SYSMGR_ECC_INTSTAT_SERR register for the ALT_SYSMGR instance. */
#define ALT_SYSMGR_ECC_INTSTAT_SERR_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SYSMGR_ADDR) + ALT_SYSMGR_ECC_INTSTAT_SERR_OFST))
/* The address of the ALT_SYSMGR_ECC_INTSTAT_DERR register for the ALT_SYSMGR instance. */
#define ALT_SYSMGR_ECC_INTSTAT_DERR_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SYSMGR_ADDR) + ALT_SYSMGR_ECC_INTSTAT_DERR_OFST))
/* The address of the ALT_SYSMGR_MPU_STAT_L2_ECC register for the ALT_SYSMGR instance. */
#define ALT_SYSMGR_MPU_STAT_L2_ECC_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SYSMGR_ADDR) + ALT_SYSMGR_MPU_STAT_L2_ECC_OFST))
/* The address of the ALT_SYSMGR_MPU_CLR_L2_ECC register for the ALT_SYSMGR instance. */
#define ALT_SYSMGR_MPU_CLR_L2_ECC_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SYSMGR_ADDR) + ALT_SYSMGR_MPU_CLR_L2_ECC_OFST))
/* The address of the ALT_SYSMGR_MPU_STAT_L1_PARITY register for the ALT_SYSMGR instance. */
#define ALT_SYSMGR_MPU_STAT_L1_PARITY_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SYSMGR_ADDR) + ALT_SYSMGR_MPU_STAT_L1_PARITY_OFST))
/* The address of the ALT_SYSMGR_MPU_CLR_L1_PARITY register for the ALT_SYSMGR instance. */
#define ALT_SYSMGR_MPU_CLR_L1_PARITY_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SYSMGR_ADDR) + ALT_SYSMGR_MPU_CLR_L1_PARITY_OFST))
/* The address of the ALT_SYSMGR_MPU_SET_L1_PARITY register for the ALT_SYSMGR instance. */
#define ALT_SYSMGR_MPU_SET_L1_PARITY_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SYSMGR_ADDR) + ALT_SYSMGR_MPU_SET_L1_PARITY_OFST))
/* The address of the ALT_SYSMGR_NOC_TMO register for the ALT_SYSMGR instance. */
#define ALT_SYSMGR_NOC_TMO_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SYSMGR_ADDR) + ALT_SYSMGR_NOC_TMO_OFST))
/* The address of the ALT_SYSMGR_NOC_IDLEREQ_SET register for the ALT_SYSMGR instance. */
#define ALT_SYSMGR_NOC_IDLEREQ_SET_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SYSMGR_ADDR) + ALT_SYSMGR_NOC_IDLEREQ_SET_OFST))
/* The address of the ALT_SYSMGR_NOC_IDLEREQ_CLR register for the ALT_SYSMGR instance. */
#define ALT_SYSMGR_NOC_IDLEREQ_CLR_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SYSMGR_ADDR) + ALT_SYSMGR_NOC_IDLEREQ_CLR_OFST))
/* The address of the ALT_SYSMGR_NOC_IDLEREQ_VALUE register for the ALT_SYSMGR instance. */
#define ALT_SYSMGR_NOC_IDLEREQ_VALUE_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SYSMGR_ADDR) + ALT_SYSMGR_NOC_IDLEREQ_VALUE_OFST))
/* The address of the ALT_SYSMGR_NOC_IDLEACK register for the ALT_SYSMGR instance. */
#define ALT_SYSMGR_NOC_IDLEACK_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SYSMGR_ADDR) + ALT_SYSMGR_NOC_IDLEACK_OFST))
/* The address of the ALT_SYSMGR_NOC_IDLESTAT register for the ALT_SYSMGR instance. */
#define ALT_SYSMGR_NOC_IDLESTAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SYSMGR_ADDR) + ALT_SYSMGR_NOC_IDLESTAT_OFST))
/* The address of the ALT_SYSMGR_F2H_CTL register for the ALT_SYSMGR instance. */
#define ALT_SYSMGR_F2H_CTL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SYSMGR_ADDR) + ALT_SYSMGR_F2H_CTL_OFST))
/* The address of the ALT_SYSMGR_TSMC_TSEL_0 register for the ALT_SYSMGR instance. */
#define ALT_SYSMGR_TSMC_TSEL_0_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SYSMGR_ADDR) + ALT_SYSMGR_TSMC_TSEL_0_OFST))
/* The address of the ALT_SYSMGR_TSMC_TSEL_1 register for the ALT_SYSMGR instance. */
#define ALT_SYSMGR_TSMC_TSEL_1_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SYSMGR_ADDR) + ALT_SYSMGR_TSMC_TSEL_1_OFST))
/* The address of the ALT_SYSMGR_TSMC_TSEL_2 register for the ALT_SYSMGR instance. */
#define ALT_SYSMGR_TSMC_TSEL_2_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SYSMGR_ADDR) + ALT_SYSMGR_TSMC_TSEL_2_OFST))
/* The address of the ALT_SYSMGR_TSMC_TSEL_3 register for the ALT_SYSMGR instance. */
#define ALT_SYSMGR_TSMC_TSEL_3_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SYSMGR_ADDR) + ALT_SYSMGR_TSMC_TSEL_3_OFST))
/* The base address byte offset for the start of the ALT_SYSMGR component. */
#define ALT_SYSMGR_OFST        0xffd06000
/* The start address of the ALT_SYSMGR component. */
#define ALT_SYSMGR_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_SYSMGR_OFST))
/* The lower bound address range of the ALT_SYSMGR component. */
#define ALT_SYSMGR_LB_ADDR     ALT_SYSMGR_ADDR
/* The upper bound address range of the ALT_SYSMGR component. */
#define ALT_SYSMGR_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_SYSMGR_ADDR) + 0x200) - 1))


/*
 * Component Instance : i_sys_mgr_rom
 * 
 * Instance i_sys_mgr_rom of component ALT_SYSMGR_ROM.
 * 
 * 
 */
/* The address of the ALT_SYSMGR_ROM_ROMHW_CTL register for the ALT_SYSMGR_ROM instance. */
#define ALT_SYSMGR_ROM_ROMHW_CTL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SYSMGR_ROM_ADDR) + ALT_SYSMGR_ROM_ROMHW_CTL_OFST))
/* The address of the ALT_SYSMGR_ROM_ROMCODE_CTL register for the ALT_SYSMGR_ROM instance. */
#define ALT_SYSMGR_ROM_ROMCODE_CTL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SYSMGR_ROM_ADDR) + ALT_SYSMGR_ROM_ROMCODE_CTL_OFST))
/* The address of the ALT_SYSMGR_ROM_ROMCODE_QSPI_RST_CMD register for the ALT_SYSMGR_ROM instance. */
#define ALT_SYSMGR_ROM_ROMCODE_QSPI_RST_CMD_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SYSMGR_ROM_ADDR) + ALT_SYSMGR_ROM_ROMCODE_QSPI_RST_CMD_OFST))
/* The address of the ALT_SYSMGR_ROM_ROMCODE_INITSWSTATE register for the ALT_SYSMGR_ROM instance. */
#define ALT_SYSMGR_ROM_ROMCODE_INITSWSTATE_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SYSMGR_ROM_ADDR) + ALT_SYSMGR_ROM_ROMCODE_INITSWSTATE_OFST))
/* The address of the ALT_SYSMGR_ROM_ROMCODE_INITSWLASTLD register for the ALT_SYSMGR_ROM instance. */
#define ALT_SYSMGR_ROM_ROMCODE_INITSWLASTLD_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SYSMGR_ROM_ADDR) + ALT_SYSMGR_ROM_ROMCODE_INITSWLASTLD_OFST))
/* The address of the ALT_SYSMGR_ROM_WARMRAM_EN register for the ALT_SYSMGR_ROM instance. */
#define ALT_SYSMGR_ROM_WARMRAM_EN_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SYSMGR_ROM_ADDR) + ALT_SYSMGR_ROM_WARMRAM_EN_OFST))
/* The address of the ALT_SYSMGR_ROM_WARMRAM_DATASTART register for the ALT_SYSMGR_ROM instance. */
#define ALT_SYSMGR_ROM_WARMRAM_DATASTART_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SYSMGR_ROM_ADDR) + ALT_SYSMGR_ROM_WARMRAM_DATASTART_OFST))
/* The address of the ALT_SYSMGR_ROM_WARMRAM_LEN register for the ALT_SYSMGR_ROM instance. */
#define ALT_SYSMGR_ROM_WARMRAM_LEN_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SYSMGR_ROM_ADDR) + ALT_SYSMGR_ROM_WARMRAM_LEN_OFST))
/* The address of the ALT_SYSMGR_ROM_WARMRAM_EXECUTION register for the ALT_SYSMGR_ROM instance. */
#define ALT_SYSMGR_ROM_WARMRAM_EXECUTION_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SYSMGR_ROM_ADDR) + ALT_SYSMGR_ROM_WARMRAM_EXECUTION_OFST))
/* The address of the ALT_SYSMGR_ROM_WARMRAM_CRC register for the ALT_SYSMGR_ROM instance. */
#define ALT_SYSMGR_ROM_WARMRAM_CRC_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SYSMGR_ROM_ADDR) + ALT_SYSMGR_ROM_WARMRAM_CRC_OFST))
/* The address of the ALT_SYSMGR_ROM_ISW_HANDOFF register for the ALT_SYSMGR_ROM instance. */
#define ALT_SYSMGR_ROM_ISW_HANDOFF_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SYSMGR_ROM_ADDR) + ALT_SYSMGR_ROM_ISW_HANDOFF_OFST))
/* The address of the ALT_SYSMGR_ROM_ROMCODE_BOOTROMSWSTATE register for the ALT_SYSMGR_ROM instance. */
#define ALT_SYSMGR_ROM_ROMCODE_BOOTROMSWSTATE_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SYSMGR_ROM_ADDR) + ALT_SYSMGR_ROM_ROMCODE_BOOTROMSWSTATE_OFST))
/* The address of the ALT_SYSMGR_ROM_ROMCODE_STICKYSET_WARMCLR register for the ALT_SYSMGR_ROM instance. */
#define ALT_SYSMGR_ROM_ROMCODE_STICKYSET_WARMCLR_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SYSMGR_ROM_ADDR) + ALT_SYSMGR_ROM_ROMCODE_STICKYSET_WARMCLR_OFST))
/* The address of the ALT_SYSMGR_ROM_ROMCODE_STICKYSET_COLDCLR register for the ALT_SYSMGR_ROM instance. */
#define ALT_SYSMGR_ROM_ROMCODE_STICKYSET_COLDCLR_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_SYSMGR_ROM_ADDR) + ALT_SYSMGR_ROM_ROMCODE_STICKYSET_COLDCLR_OFST))
/* The base address byte offset for the start of the ALT_SYSMGR_ROM component. */
#define ALT_SYSMGR_ROM_OFST        0xffd06200
/* The start address of the ALT_SYSMGR_ROM component. */
#define ALT_SYSMGR_ROM_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_SYSMGR_ROM_OFST))
/* The lower bound address range of the ALT_SYSMGR_ROM component. */
#define ALT_SYSMGR_ROM_LB_ADDR     ALT_SYSMGR_ROM_ADDR
/* The upper bound address range of the ALT_SYSMGR_ROM component. */
#define ALT_SYSMGR_ROM_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_SYSMGR_ROM_ADDR) + 0x100) - 1))


/*
 * Component Instance : i_io48_pin_mux_shared_3v_io_grp
 * 
 * Instance i_io48_pin_mux_shared_3v_io_grp of component ALT_PINMUX_SHARED_3V_IO_GRP.
 * 
 * 
 */
/* The address of the ALT_PINMUX_SHARED_3V_IO_Q1_1 register for the ALT_PINMUX_SHARED_3V_IO_GRP instance. */
#define ALT_PINMUX_SHARED_3V_IO_Q1_1_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_SHARED_3V_IO_GRP_ADDR) + ALT_PINMUX_SHARED_3V_IO_Q1_1_OFST))
/* The address of the ALT_PINMUX_SHARED_3V_IO_Q1_2 register for the ALT_PINMUX_SHARED_3V_IO_GRP instance. */
#define ALT_PINMUX_SHARED_3V_IO_Q1_2_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_SHARED_3V_IO_GRP_ADDR) + ALT_PINMUX_SHARED_3V_IO_Q1_2_OFST))
/* The address of the ALT_PINMUX_SHARED_3V_IO_Q1_3 register for the ALT_PINMUX_SHARED_3V_IO_GRP instance. */
#define ALT_PINMUX_SHARED_3V_IO_Q1_3_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_SHARED_3V_IO_GRP_ADDR) + ALT_PINMUX_SHARED_3V_IO_Q1_3_OFST))
/* The address of the ALT_PINMUX_SHARED_3V_IO_Q1_4 register for the ALT_PINMUX_SHARED_3V_IO_GRP instance. */
#define ALT_PINMUX_SHARED_3V_IO_Q1_4_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_SHARED_3V_IO_GRP_ADDR) + ALT_PINMUX_SHARED_3V_IO_Q1_4_OFST))
/* The address of the ALT_PINMUX_SHARED_3V_IO_Q1_5 register for the ALT_PINMUX_SHARED_3V_IO_GRP instance. */
#define ALT_PINMUX_SHARED_3V_IO_Q1_5_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_SHARED_3V_IO_GRP_ADDR) + ALT_PINMUX_SHARED_3V_IO_Q1_5_OFST))
/* The address of the ALT_PINMUX_SHARED_3V_IO_Q1_6 register for the ALT_PINMUX_SHARED_3V_IO_GRP instance. */
#define ALT_PINMUX_SHARED_3V_IO_Q1_6_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_SHARED_3V_IO_GRP_ADDR) + ALT_PINMUX_SHARED_3V_IO_Q1_6_OFST))
/* The address of the ALT_PINMUX_SHARED_3V_IO_Q1_7 register for the ALT_PINMUX_SHARED_3V_IO_GRP instance. */
#define ALT_PINMUX_SHARED_3V_IO_Q1_7_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_SHARED_3V_IO_GRP_ADDR) + ALT_PINMUX_SHARED_3V_IO_Q1_7_OFST))
/* The address of the ALT_PINMUX_SHARED_3V_IO_Q1_8 register for the ALT_PINMUX_SHARED_3V_IO_GRP instance. */
#define ALT_PINMUX_SHARED_3V_IO_Q1_8_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_SHARED_3V_IO_GRP_ADDR) + ALT_PINMUX_SHARED_3V_IO_Q1_8_OFST))
/* The address of the ALT_PINMUX_SHARED_3V_IO_Q1_9 register for the ALT_PINMUX_SHARED_3V_IO_GRP instance. */
#define ALT_PINMUX_SHARED_3V_IO_Q1_9_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_SHARED_3V_IO_GRP_ADDR) + ALT_PINMUX_SHARED_3V_IO_Q1_9_OFST))
/* The address of the ALT_PINMUX_SHARED_3V_IO_Q1_10 register for the ALT_PINMUX_SHARED_3V_IO_GRP instance. */
#define ALT_PINMUX_SHARED_3V_IO_Q1_10_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_SHARED_3V_IO_GRP_ADDR) + ALT_PINMUX_SHARED_3V_IO_Q1_10_OFST))
/* The address of the ALT_PINMUX_SHARED_3V_IO_Q1_11 register for the ALT_PINMUX_SHARED_3V_IO_GRP instance. */
#define ALT_PINMUX_SHARED_3V_IO_Q1_11_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_SHARED_3V_IO_GRP_ADDR) + ALT_PINMUX_SHARED_3V_IO_Q1_11_OFST))
/* The address of the ALT_PINMUX_SHARED_3V_IO_Q1_12 register for the ALT_PINMUX_SHARED_3V_IO_GRP instance. */
#define ALT_PINMUX_SHARED_3V_IO_Q1_12_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_SHARED_3V_IO_GRP_ADDR) + ALT_PINMUX_SHARED_3V_IO_Q1_12_OFST))
/* The address of the ALT_PINMUX_SHARED_3V_IO_Q2_1 register for the ALT_PINMUX_SHARED_3V_IO_GRP instance. */
#define ALT_PINMUX_SHARED_3V_IO_Q2_1_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_SHARED_3V_IO_GRP_ADDR) + ALT_PINMUX_SHARED_3V_IO_Q2_1_OFST))
/* The address of the ALT_PINMUX_SHARED_3V_IO_Q2_2 register for the ALT_PINMUX_SHARED_3V_IO_GRP instance. */
#define ALT_PINMUX_SHARED_3V_IO_Q2_2_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_SHARED_3V_IO_GRP_ADDR) + ALT_PINMUX_SHARED_3V_IO_Q2_2_OFST))
/* The address of the ALT_PINMUX_SHARED_3V_IO_Q2_3 register for the ALT_PINMUX_SHARED_3V_IO_GRP instance. */
#define ALT_PINMUX_SHARED_3V_IO_Q2_3_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_SHARED_3V_IO_GRP_ADDR) + ALT_PINMUX_SHARED_3V_IO_Q2_3_OFST))
/* The address of the ALT_PINMUX_SHARED_3V_IO_Q2_4 register for the ALT_PINMUX_SHARED_3V_IO_GRP instance. */
#define ALT_PINMUX_SHARED_3V_IO_Q2_4_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_SHARED_3V_IO_GRP_ADDR) + ALT_PINMUX_SHARED_3V_IO_Q2_4_OFST))
/* The address of the ALT_PINMUX_SHARED_3V_IO_Q2_5 register for the ALT_PINMUX_SHARED_3V_IO_GRP instance. */
#define ALT_PINMUX_SHARED_3V_IO_Q2_5_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_SHARED_3V_IO_GRP_ADDR) + ALT_PINMUX_SHARED_3V_IO_Q2_5_OFST))
/* The address of the ALT_PINMUX_SHARED_3V_IO_Q2_6 register for the ALT_PINMUX_SHARED_3V_IO_GRP instance. */
#define ALT_PINMUX_SHARED_3V_IO_Q2_6_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_SHARED_3V_IO_GRP_ADDR) + ALT_PINMUX_SHARED_3V_IO_Q2_6_OFST))
/* The address of the ALT_PINMUX_SHARED_3V_IO_Q2_7 register for the ALT_PINMUX_SHARED_3V_IO_GRP instance. */
#define ALT_PINMUX_SHARED_3V_IO_Q2_7_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_SHARED_3V_IO_GRP_ADDR) + ALT_PINMUX_SHARED_3V_IO_Q2_7_OFST))
/* The address of the ALT_PINMUX_SHARED_3V_IO_Q2_8 register for the ALT_PINMUX_SHARED_3V_IO_GRP instance. */
#define ALT_PINMUX_SHARED_3V_IO_Q2_8_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_SHARED_3V_IO_GRP_ADDR) + ALT_PINMUX_SHARED_3V_IO_Q2_8_OFST))
/* The address of the ALT_PINMUX_SHARED_3V_IO_Q2_9 register for the ALT_PINMUX_SHARED_3V_IO_GRP instance. */
#define ALT_PINMUX_SHARED_3V_IO_Q2_9_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_SHARED_3V_IO_GRP_ADDR) + ALT_PINMUX_SHARED_3V_IO_Q2_9_OFST))
/* The address of the ALT_PINMUX_SHARED_3V_IO_Q2_10 register for the ALT_PINMUX_SHARED_3V_IO_GRP instance. */
#define ALT_PINMUX_SHARED_3V_IO_Q2_10_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_SHARED_3V_IO_GRP_ADDR) + ALT_PINMUX_SHARED_3V_IO_Q2_10_OFST))
/* The address of the ALT_PINMUX_SHARED_3V_IO_Q2_11 register for the ALT_PINMUX_SHARED_3V_IO_GRP instance. */
#define ALT_PINMUX_SHARED_3V_IO_Q2_11_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_SHARED_3V_IO_GRP_ADDR) + ALT_PINMUX_SHARED_3V_IO_Q2_11_OFST))
/* The address of the ALT_PINMUX_SHARED_3V_IO_Q2_12 register for the ALT_PINMUX_SHARED_3V_IO_GRP instance. */
#define ALT_PINMUX_SHARED_3V_IO_Q2_12_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_SHARED_3V_IO_GRP_ADDR) + ALT_PINMUX_SHARED_3V_IO_Q2_12_OFST))
/* The address of the ALT_PINMUX_SHARED_3V_IO_Q3_1 register for the ALT_PINMUX_SHARED_3V_IO_GRP instance. */
#define ALT_PINMUX_SHARED_3V_IO_Q3_1_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_SHARED_3V_IO_GRP_ADDR) + ALT_PINMUX_SHARED_3V_IO_Q3_1_OFST))
/* The address of the ALT_PINMUX_SHARED_3V_IO_Q3_2 register for the ALT_PINMUX_SHARED_3V_IO_GRP instance. */
#define ALT_PINMUX_SHARED_3V_IO_Q3_2_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_SHARED_3V_IO_GRP_ADDR) + ALT_PINMUX_SHARED_3V_IO_Q3_2_OFST))
/* The address of the ALT_PINMUX_SHARED_3V_IO_Q3_3 register for the ALT_PINMUX_SHARED_3V_IO_GRP instance. */
#define ALT_PINMUX_SHARED_3V_IO_Q3_3_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_SHARED_3V_IO_GRP_ADDR) + ALT_PINMUX_SHARED_3V_IO_Q3_3_OFST))
/* The address of the ALT_PINMUX_SHARED_3V_IO_Q3_4 register for the ALT_PINMUX_SHARED_3V_IO_GRP instance. */
#define ALT_PINMUX_SHARED_3V_IO_Q3_4_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_SHARED_3V_IO_GRP_ADDR) + ALT_PINMUX_SHARED_3V_IO_Q3_4_OFST))
/* The address of the ALT_PINMUX_SHARED_3V_IO_Q3_5 register for the ALT_PINMUX_SHARED_3V_IO_GRP instance. */
#define ALT_PINMUX_SHARED_3V_IO_Q3_5_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_SHARED_3V_IO_GRP_ADDR) + ALT_PINMUX_SHARED_3V_IO_Q3_5_OFST))
/* The address of the ALT_PINMUX_SHARED_3V_IO_Q3_6 register for the ALT_PINMUX_SHARED_3V_IO_GRP instance. */
#define ALT_PINMUX_SHARED_3V_IO_Q3_6_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_SHARED_3V_IO_GRP_ADDR) + ALT_PINMUX_SHARED_3V_IO_Q3_6_OFST))
/* The address of the ALT_PINMUX_SHARED_3V_IO_Q3_7 register for the ALT_PINMUX_SHARED_3V_IO_GRP instance. */
#define ALT_PINMUX_SHARED_3V_IO_Q3_7_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_SHARED_3V_IO_GRP_ADDR) + ALT_PINMUX_SHARED_3V_IO_Q3_7_OFST))
/* The address of the ALT_PINMUX_SHARED_3V_IO_Q3_8 register for the ALT_PINMUX_SHARED_3V_IO_GRP instance. */
#define ALT_PINMUX_SHARED_3V_IO_Q3_8_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_SHARED_3V_IO_GRP_ADDR) + ALT_PINMUX_SHARED_3V_IO_Q3_8_OFST))
/* The address of the ALT_PINMUX_SHARED_3V_IO_Q3_9 register for the ALT_PINMUX_SHARED_3V_IO_GRP instance. */
#define ALT_PINMUX_SHARED_3V_IO_Q3_9_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_SHARED_3V_IO_GRP_ADDR) + ALT_PINMUX_SHARED_3V_IO_Q3_9_OFST))
/* The address of the ALT_PINMUX_SHARED_3V_IO_Q3_10 register for the ALT_PINMUX_SHARED_3V_IO_GRP instance. */
#define ALT_PINMUX_SHARED_3V_IO_Q3_10_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_SHARED_3V_IO_GRP_ADDR) + ALT_PINMUX_SHARED_3V_IO_Q3_10_OFST))
/* The address of the ALT_PINMUX_SHARED_3V_IO_Q3_11 register for the ALT_PINMUX_SHARED_3V_IO_GRP instance. */
#define ALT_PINMUX_SHARED_3V_IO_Q3_11_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_SHARED_3V_IO_GRP_ADDR) + ALT_PINMUX_SHARED_3V_IO_Q3_11_OFST))
/* The address of the ALT_PINMUX_SHARED_3V_IO_Q3_12 register for the ALT_PINMUX_SHARED_3V_IO_GRP instance. */
#define ALT_PINMUX_SHARED_3V_IO_Q3_12_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_SHARED_3V_IO_GRP_ADDR) + ALT_PINMUX_SHARED_3V_IO_Q3_12_OFST))
/* The address of the ALT_PINMUX_SHARED_3V_IO_Q4_1 register for the ALT_PINMUX_SHARED_3V_IO_GRP instance. */
#define ALT_PINMUX_SHARED_3V_IO_Q4_1_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_SHARED_3V_IO_GRP_ADDR) + ALT_PINMUX_SHARED_3V_IO_Q4_1_OFST))
/* The address of the ALT_PINMUX_SHARED_3V_IO_Q4_2 register for the ALT_PINMUX_SHARED_3V_IO_GRP instance. */
#define ALT_PINMUX_SHARED_3V_IO_Q4_2_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_SHARED_3V_IO_GRP_ADDR) + ALT_PINMUX_SHARED_3V_IO_Q4_2_OFST))
/* The address of the ALT_PINMUX_SHARED_3V_IO_Q4_3 register for the ALT_PINMUX_SHARED_3V_IO_GRP instance. */
#define ALT_PINMUX_SHARED_3V_IO_Q4_3_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_SHARED_3V_IO_GRP_ADDR) + ALT_PINMUX_SHARED_3V_IO_Q4_3_OFST))
/* The address of the ALT_PINMUX_SHARED_3V_IO_Q4_4 register for the ALT_PINMUX_SHARED_3V_IO_GRP instance. */
#define ALT_PINMUX_SHARED_3V_IO_Q4_4_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_SHARED_3V_IO_GRP_ADDR) + ALT_PINMUX_SHARED_3V_IO_Q4_4_OFST))
/* The address of the ALT_PINMUX_SHARED_3V_IO_Q4_5 register for the ALT_PINMUX_SHARED_3V_IO_GRP instance. */
#define ALT_PINMUX_SHARED_3V_IO_Q4_5_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_SHARED_3V_IO_GRP_ADDR) + ALT_PINMUX_SHARED_3V_IO_Q4_5_OFST))
/* The address of the ALT_PINMUX_SHARED_3V_IO_Q4_6 register for the ALT_PINMUX_SHARED_3V_IO_GRP instance. */
#define ALT_PINMUX_SHARED_3V_IO_Q4_6_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_SHARED_3V_IO_GRP_ADDR) + ALT_PINMUX_SHARED_3V_IO_Q4_6_OFST))
/* The address of the ALT_PINMUX_SHARED_3V_IO_Q4_7 register for the ALT_PINMUX_SHARED_3V_IO_GRP instance. */
#define ALT_PINMUX_SHARED_3V_IO_Q4_7_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_SHARED_3V_IO_GRP_ADDR) + ALT_PINMUX_SHARED_3V_IO_Q4_7_OFST))
/* The address of the ALT_PINMUX_SHARED_3V_IO_Q4_8 register for the ALT_PINMUX_SHARED_3V_IO_GRP instance. */
#define ALT_PINMUX_SHARED_3V_IO_Q4_8_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_SHARED_3V_IO_GRP_ADDR) + ALT_PINMUX_SHARED_3V_IO_Q4_8_OFST))
/* The address of the ALT_PINMUX_SHARED_3V_IO_Q4_9 register for the ALT_PINMUX_SHARED_3V_IO_GRP instance. */
#define ALT_PINMUX_SHARED_3V_IO_Q4_9_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_SHARED_3V_IO_GRP_ADDR) + ALT_PINMUX_SHARED_3V_IO_Q4_9_OFST))
/* The address of the ALT_PINMUX_SHARED_3V_IO_Q4_10 register for the ALT_PINMUX_SHARED_3V_IO_GRP instance. */
#define ALT_PINMUX_SHARED_3V_IO_Q4_10_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_SHARED_3V_IO_GRP_ADDR) + ALT_PINMUX_SHARED_3V_IO_Q4_10_OFST))
/* The address of the ALT_PINMUX_SHARED_3V_IO_Q4_11 register for the ALT_PINMUX_SHARED_3V_IO_GRP instance. */
#define ALT_PINMUX_SHARED_3V_IO_Q4_11_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_SHARED_3V_IO_GRP_ADDR) + ALT_PINMUX_SHARED_3V_IO_Q4_11_OFST))
/* The address of the ALT_PINMUX_SHARED_3V_IO_Q4_12 register for the ALT_PINMUX_SHARED_3V_IO_GRP instance. */
#define ALT_PINMUX_SHARED_3V_IO_Q4_12_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_SHARED_3V_IO_GRP_ADDR) + ALT_PINMUX_SHARED_3V_IO_Q4_12_OFST))
/* The base address byte offset for the start of the ALT_PINMUX_SHARED_3V_IO_GRP component. */
#define ALT_PINMUX_SHARED_3V_IO_GRP_OFST        0xffd07000
/* The start address of the ALT_PINMUX_SHARED_3V_IO_GRP component. */
#define ALT_PINMUX_SHARED_3V_IO_GRP_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_PINMUX_SHARED_3V_IO_GRP_OFST))
/* The lower bound address range of the ALT_PINMUX_SHARED_3V_IO_GRP component. */
#define ALT_PINMUX_SHARED_3V_IO_GRP_LB_ADDR     ALT_PINMUX_SHARED_3V_IO_GRP_ADDR
/* The upper bound address range of the ALT_PINMUX_SHARED_3V_IO_GRP component. */
#define ALT_PINMUX_SHARED_3V_IO_GRP_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_PINMUX_SHARED_3V_IO_GRP_ADDR) + 0x200) - 1))


/*
 * Component Instance : i_io48_pin_mux_dedicated_io_grp
 * 
 * Instance i_io48_pin_mux_dedicated_io_grp of component ALT_PINMUX_DCTD_IO_GRP.
 * 
 * 
 */
/* The address of the ALT_PINMUX_DCTD_IO_1 register for the ALT_PINMUX_DCTD_IO_GRP instance. */
#define ALT_PINMUX_DCTD_IO_1_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_DCTD_IO_GRP_ADDR) + ALT_PINMUX_DCTD_IO_1_OFST))
/* The address of the ALT_PINMUX_DCTD_IO_2 register for the ALT_PINMUX_DCTD_IO_GRP instance. */
#define ALT_PINMUX_DCTD_IO_2_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_DCTD_IO_GRP_ADDR) + ALT_PINMUX_DCTD_IO_2_OFST))
/* The address of the ALT_PINMUX_DCTD_IO_3 register for the ALT_PINMUX_DCTD_IO_GRP instance. */
#define ALT_PINMUX_DCTD_IO_3_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_DCTD_IO_GRP_ADDR) + ALT_PINMUX_DCTD_IO_3_OFST))
/* The address of the ALT_PINMUX_DCTD_IO_4 register for the ALT_PINMUX_DCTD_IO_GRP instance. */
#define ALT_PINMUX_DCTD_IO_4_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_DCTD_IO_GRP_ADDR) + ALT_PINMUX_DCTD_IO_4_OFST))
/* The address of the ALT_PINMUX_DCTD_IO_5 register for the ALT_PINMUX_DCTD_IO_GRP instance. */
#define ALT_PINMUX_DCTD_IO_5_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_DCTD_IO_GRP_ADDR) + ALT_PINMUX_DCTD_IO_5_OFST))
/* The address of the ALT_PINMUX_DCTD_IO_6 register for the ALT_PINMUX_DCTD_IO_GRP instance. */
#define ALT_PINMUX_DCTD_IO_6_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_DCTD_IO_GRP_ADDR) + ALT_PINMUX_DCTD_IO_6_OFST))
/* The address of the ALT_PINMUX_DCTD_IO_7 register for the ALT_PINMUX_DCTD_IO_GRP instance. */
#define ALT_PINMUX_DCTD_IO_7_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_DCTD_IO_GRP_ADDR) + ALT_PINMUX_DCTD_IO_7_OFST))
/* The address of the ALT_PINMUX_DCTD_IO_8 register for the ALT_PINMUX_DCTD_IO_GRP instance. */
#define ALT_PINMUX_DCTD_IO_8_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_DCTD_IO_GRP_ADDR) + ALT_PINMUX_DCTD_IO_8_OFST))
/* The address of the ALT_PINMUX_DCTD_IO_9 register for the ALT_PINMUX_DCTD_IO_GRP instance. */
#define ALT_PINMUX_DCTD_IO_9_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_DCTD_IO_GRP_ADDR) + ALT_PINMUX_DCTD_IO_9_OFST))
/* The address of the ALT_PINMUX_DCTD_IO_10 register for the ALT_PINMUX_DCTD_IO_GRP instance. */
#define ALT_PINMUX_DCTD_IO_10_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_DCTD_IO_GRP_ADDR) + ALT_PINMUX_DCTD_IO_10_OFST))
/* The address of the ALT_PINMUX_DCTD_IO_11 register for the ALT_PINMUX_DCTD_IO_GRP instance. */
#define ALT_PINMUX_DCTD_IO_11_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_DCTD_IO_GRP_ADDR) + ALT_PINMUX_DCTD_IO_11_OFST))
/* The address of the ALT_PINMUX_DCTD_IO_12 register for the ALT_PINMUX_DCTD_IO_GRP instance. */
#define ALT_PINMUX_DCTD_IO_12_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_DCTD_IO_GRP_ADDR) + ALT_PINMUX_DCTD_IO_12_OFST))
/* The address of the ALT_PINMUX_DCTD_IO_13 register for the ALT_PINMUX_DCTD_IO_GRP instance. */
#define ALT_PINMUX_DCTD_IO_13_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_DCTD_IO_GRP_ADDR) + ALT_PINMUX_DCTD_IO_13_OFST))
/* The address of the ALT_PINMUX_DCTD_IO_14 register for the ALT_PINMUX_DCTD_IO_GRP instance. */
#define ALT_PINMUX_DCTD_IO_14_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_DCTD_IO_GRP_ADDR) + ALT_PINMUX_DCTD_IO_14_OFST))
/* The address of the ALT_PINMUX_DCTD_IO_15 register for the ALT_PINMUX_DCTD_IO_GRP instance. */
#define ALT_PINMUX_DCTD_IO_15_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_DCTD_IO_GRP_ADDR) + ALT_PINMUX_DCTD_IO_15_OFST))
/* The address of the ALT_PINMUX_DCTD_IO_16 register for the ALT_PINMUX_DCTD_IO_GRP instance. */
#define ALT_PINMUX_DCTD_IO_16_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_DCTD_IO_GRP_ADDR) + ALT_PINMUX_DCTD_IO_16_OFST))
/* The address of the ALT_PINMUX_DCTD_IO_17 register for the ALT_PINMUX_DCTD_IO_GRP instance. */
#define ALT_PINMUX_DCTD_IO_17_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_DCTD_IO_GRP_ADDR) + ALT_PINMUX_DCTD_IO_17_OFST))
/* The address of the ALT_PINMUX_DCTD_IO_CFG_BANK register for the ALT_PINMUX_DCTD_IO_GRP instance. */
#define ALT_PINMUX_DCTD_IO_CFG_BANK_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_DCTD_IO_GRP_ADDR) + ALT_PINMUX_DCTD_IO_CFG_BANK_OFST))
/* The address of the ALT_PINMUX_DCTD_IO_CFG_1 register for the ALT_PINMUX_DCTD_IO_GRP instance. */
#define ALT_PINMUX_DCTD_IO_CFG_1_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_DCTD_IO_GRP_ADDR) + ALT_PINMUX_DCTD_IO_CFG_1_OFST))
/* The address of the ALT_PINMUX_DCTD_IO_CFG_2 register for the ALT_PINMUX_DCTD_IO_GRP instance. */
#define ALT_PINMUX_DCTD_IO_CFG_2_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_DCTD_IO_GRP_ADDR) + ALT_PINMUX_DCTD_IO_CFG_2_OFST))
/* The address of the ALT_PINMUX_DCTD_IO_CFG_3 register for the ALT_PINMUX_DCTD_IO_GRP instance. */
#define ALT_PINMUX_DCTD_IO_CFG_3_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_DCTD_IO_GRP_ADDR) + ALT_PINMUX_DCTD_IO_CFG_3_OFST))
/* The address of the ALT_PINMUX_DCTD_IO_CFG_4 register for the ALT_PINMUX_DCTD_IO_GRP instance. */
#define ALT_PINMUX_DCTD_IO_CFG_4_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_DCTD_IO_GRP_ADDR) + ALT_PINMUX_DCTD_IO_CFG_4_OFST))
/* The address of the ALT_PINMUX_DCTD_IO_CFG_5 register for the ALT_PINMUX_DCTD_IO_GRP instance. */
#define ALT_PINMUX_DCTD_IO_CFG_5_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_DCTD_IO_GRP_ADDR) + ALT_PINMUX_DCTD_IO_CFG_5_OFST))
/* The address of the ALT_PINMUX_DCTD_IO_CFG_6 register for the ALT_PINMUX_DCTD_IO_GRP instance. */
#define ALT_PINMUX_DCTD_IO_CFG_6_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_DCTD_IO_GRP_ADDR) + ALT_PINMUX_DCTD_IO_CFG_6_OFST))
/* The address of the ALT_PINMUX_DCTD_IO_CFG_7 register for the ALT_PINMUX_DCTD_IO_GRP instance. */
#define ALT_PINMUX_DCTD_IO_CFG_7_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_DCTD_IO_GRP_ADDR) + ALT_PINMUX_DCTD_IO_CFG_7_OFST))
/* The address of the ALT_PINMUX_DCTD_IO_CFG_8 register for the ALT_PINMUX_DCTD_IO_GRP instance. */
#define ALT_PINMUX_DCTD_IO_CFG_8_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_DCTD_IO_GRP_ADDR) + ALT_PINMUX_DCTD_IO_CFG_8_OFST))
/* The address of the ALT_PINMUX_DCTD_IO_CFG_9 register for the ALT_PINMUX_DCTD_IO_GRP instance. */
#define ALT_PINMUX_DCTD_IO_CFG_9_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_DCTD_IO_GRP_ADDR) + ALT_PINMUX_DCTD_IO_CFG_9_OFST))
/* The address of the ALT_PINMUX_DCTD_IO_CFG_10 register for the ALT_PINMUX_DCTD_IO_GRP instance. */
#define ALT_PINMUX_DCTD_IO_CFG_10_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_DCTD_IO_GRP_ADDR) + ALT_PINMUX_DCTD_IO_CFG_10_OFST))
/* The address of the ALT_PINMUX_DCTD_IO_CFG_11 register for the ALT_PINMUX_DCTD_IO_GRP instance. */
#define ALT_PINMUX_DCTD_IO_CFG_11_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_DCTD_IO_GRP_ADDR) + ALT_PINMUX_DCTD_IO_CFG_11_OFST))
/* The address of the ALT_PINMUX_DCTD_IO_CFG_12 register for the ALT_PINMUX_DCTD_IO_GRP instance. */
#define ALT_PINMUX_DCTD_IO_CFG_12_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_DCTD_IO_GRP_ADDR) + ALT_PINMUX_DCTD_IO_CFG_12_OFST))
/* The address of the ALT_PINMUX_DCTD_IO_CFG_13 register for the ALT_PINMUX_DCTD_IO_GRP instance. */
#define ALT_PINMUX_DCTD_IO_CFG_13_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_DCTD_IO_GRP_ADDR) + ALT_PINMUX_DCTD_IO_CFG_13_OFST))
/* The address of the ALT_PINMUX_DCTD_IO_CFG_14 register for the ALT_PINMUX_DCTD_IO_GRP instance. */
#define ALT_PINMUX_DCTD_IO_CFG_14_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_DCTD_IO_GRP_ADDR) + ALT_PINMUX_DCTD_IO_CFG_14_OFST))
/* The address of the ALT_PINMUX_DCTD_IO_CFG_15 register for the ALT_PINMUX_DCTD_IO_GRP instance. */
#define ALT_PINMUX_DCTD_IO_CFG_15_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_DCTD_IO_GRP_ADDR) + ALT_PINMUX_DCTD_IO_CFG_15_OFST))
/* The address of the ALT_PINMUX_DCTD_IO_CFG_16 register for the ALT_PINMUX_DCTD_IO_GRP instance. */
#define ALT_PINMUX_DCTD_IO_CFG_16_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_DCTD_IO_GRP_ADDR) + ALT_PINMUX_DCTD_IO_CFG_16_OFST))
/* The address of the ALT_PINMUX_DCTD_IO_CFG_17 register for the ALT_PINMUX_DCTD_IO_GRP instance. */
#define ALT_PINMUX_DCTD_IO_CFG_17_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_DCTD_IO_GRP_ADDR) + ALT_PINMUX_DCTD_IO_CFG_17_OFST))
/* The base address byte offset for the start of the ALT_PINMUX_DCTD_IO_GRP component. */
#define ALT_PINMUX_DCTD_IO_GRP_OFST        0xffd07200
/* The start address of the ALT_PINMUX_DCTD_IO_GRP component. */
#define ALT_PINMUX_DCTD_IO_GRP_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_PINMUX_DCTD_IO_GRP_OFST))
/* The lower bound address range of the ALT_PINMUX_DCTD_IO_GRP component. */
#define ALT_PINMUX_DCTD_IO_GRP_LB_ADDR     ALT_PINMUX_DCTD_IO_GRP_ADDR
/* The upper bound address range of the ALT_PINMUX_DCTD_IO_GRP component. */
#define ALT_PINMUX_DCTD_IO_GRP_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_PINMUX_DCTD_IO_GRP_ADDR) + 0x200) - 1))


/*
 * Component Instance : i_io48_pin_mux_fpga_interface_grp
 * 
 * Instance i_io48_pin_mux_fpga_interface_grp of component ALT_PINMUX_FPGA_INTERFACE_GRP.
 * 
 * 
 */
/* The address of the ALT_PINMUX_FPGA_EMAC0_USEFPGA register for the ALT_PINMUX_FPGA_INTERFACE_GRP instance. */
#define ALT_PINMUX_FPGA_EMAC0_USEFPGA_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_FPGA_INTERFACE_GRP_ADDR) + ALT_PINMUX_FPGA_EMAC0_USEFPGA_OFST))
/* The address of the ALT_PINMUX_FPGA_EMAC1_USEFPGA register for the ALT_PINMUX_FPGA_INTERFACE_GRP instance. */
#define ALT_PINMUX_FPGA_EMAC1_USEFPGA_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_FPGA_INTERFACE_GRP_ADDR) + ALT_PINMUX_FPGA_EMAC1_USEFPGA_OFST))
/* The address of the ALT_PINMUX_FPGA_EMAC2_USEFPGA register for the ALT_PINMUX_FPGA_INTERFACE_GRP instance. */
#define ALT_PINMUX_FPGA_EMAC2_USEFPGA_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_FPGA_INTERFACE_GRP_ADDR) + ALT_PINMUX_FPGA_EMAC2_USEFPGA_OFST))
/* The address of the ALT_PINMUX_FPGA_I2C0_USEFPGA register for the ALT_PINMUX_FPGA_INTERFACE_GRP instance. */
#define ALT_PINMUX_FPGA_I2C0_USEFPGA_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_FPGA_INTERFACE_GRP_ADDR) + ALT_PINMUX_FPGA_I2C0_USEFPGA_OFST))
/* The address of the ALT_PINMUX_FPGA_I2C1_USEFPGA register for the ALT_PINMUX_FPGA_INTERFACE_GRP instance. */
#define ALT_PINMUX_FPGA_I2C1_USEFPGA_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_FPGA_INTERFACE_GRP_ADDR) + ALT_PINMUX_FPGA_I2C1_USEFPGA_OFST))
/* The address of the ALT_PINMUX_FPGA_I2C_EMAC0_USEFPGA register for the ALT_PINMUX_FPGA_INTERFACE_GRP instance. */
#define ALT_PINMUX_FPGA_I2C_EMAC0_USEFPGA_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_FPGA_INTERFACE_GRP_ADDR) + ALT_PINMUX_FPGA_I2C_EMAC0_USEFPGA_OFST))
/* The address of the ALT_PINMUX_FPGA_I2C_EMAC1_USEFPGA register for the ALT_PINMUX_FPGA_INTERFACE_GRP instance. */
#define ALT_PINMUX_FPGA_I2C_EMAC1_USEFPGA_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_FPGA_INTERFACE_GRP_ADDR) + ALT_PINMUX_FPGA_I2C_EMAC1_USEFPGA_OFST))
/* The address of the ALT_PINMUX_FPGA_I2C_EMAC2_USEFPGA register for the ALT_PINMUX_FPGA_INTERFACE_GRP instance. */
#define ALT_PINMUX_FPGA_I2C_EMAC2_USEFPGA_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_FPGA_INTERFACE_GRP_ADDR) + ALT_PINMUX_FPGA_I2C_EMAC2_USEFPGA_OFST))
/* The address of the ALT_PINMUX_FPGA_NAND_USEFPGA register for the ALT_PINMUX_FPGA_INTERFACE_GRP instance. */
#define ALT_PINMUX_FPGA_NAND_USEFPGA_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_FPGA_INTERFACE_GRP_ADDR) + ALT_PINMUX_FPGA_NAND_USEFPGA_OFST))
/* The address of the ALT_PINMUX_FPGA_QSPI_USEFPGA register for the ALT_PINMUX_FPGA_INTERFACE_GRP instance. */
#define ALT_PINMUX_FPGA_QSPI_USEFPGA_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_FPGA_INTERFACE_GRP_ADDR) + ALT_PINMUX_FPGA_QSPI_USEFPGA_OFST))
/* The address of the ALT_PINMUX_FPGA_SDMMC_USEFPGA register for the ALT_PINMUX_FPGA_INTERFACE_GRP instance. */
#define ALT_PINMUX_FPGA_SDMMC_USEFPGA_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_FPGA_INTERFACE_GRP_ADDR) + ALT_PINMUX_FPGA_SDMMC_USEFPGA_OFST))
/* The address of the ALT_PINMUX_FPGA_SPIM0_USEFPGA register for the ALT_PINMUX_FPGA_INTERFACE_GRP instance. */
#define ALT_PINMUX_FPGA_SPIM0_USEFPGA_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_FPGA_INTERFACE_GRP_ADDR) + ALT_PINMUX_FPGA_SPIM0_USEFPGA_OFST))
/* The address of the ALT_PINMUX_FPGA_SPIM1_USEFPGA register for the ALT_PINMUX_FPGA_INTERFACE_GRP instance. */
#define ALT_PINMUX_FPGA_SPIM1_USEFPGA_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_FPGA_INTERFACE_GRP_ADDR) + ALT_PINMUX_FPGA_SPIM1_USEFPGA_OFST))
/* The address of the ALT_PINMUX_FPGA_SPIS0_USEFPGA register for the ALT_PINMUX_FPGA_INTERFACE_GRP instance. */
#define ALT_PINMUX_FPGA_SPIS0_USEFPGA_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_FPGA_INTERFACE_GRP_ADDR) + ALT_PINMUX_FPGA_SPIS0_USEFPGA_OFST))
/* The address of the ALT_PINMUX_FPGA_SPIS1_USEFPGA register for the ALT_PINMUX_FPGA_INTERFACE_GRP instance. */
#define ALT_PINMUX_FPGA_SPIS1_USEFPGA_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_FPGA_INTERFACE_GRP_ADDR) + ALT_PINMUX_FPGA_SPIS1_USEFPGA_OFST))
/* The address of the ALT_PINMUX_FPGA_UART0_USEFPGA register for the ALT_PINMUX_FPGA_INTERFACE_GRP instance. */
#define ALT_PINMUX_FPGA_UART0_USEFPGA_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_FPGA_INTERFACE_GRP_ADDR) + ALT_PINMUX_FPGA_UART0_USEFPGA_OFST))
/* The address of the ALT_PINMUX_FPGA_UART1_USEFPGA register for the ALT_PINMUX_FPGA_INTERFACE_GRP instance. */
#define ALT_PINMUX_FPGA_UART1_USEFPGA_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_PINMUX_FPGA_INTERFACE_GRP_ADDR) + ALT_PINMUX_FPGA_UART1_USEFPGA_OFST))
/* The base address byte offset for the start of the ALT_PINMUX_FPGA_INTERFACE_GRP component. */
#define ALT_PINMUX_FPGA_INTERFACE_GRP_OFST        0xffd07400
/* The start address of the ALT_PINMUX_FPGA_INTERFACE_GRP component. */
#define ALT_PINMUX_FPGA_INTERFACE_GRP_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_PINMUX_FPGA_INTERFACE_GRP_OFST))
/* The lower bound address range of the ALT_PINMUX_FPGA_INTERFACE_GRP component. */
#define ALT_PINMUX_FPGA_INTERFACE_GRP_LB_ADDR     ALT_PINMUX_FPGA_INTERFACE_GRP_ADDR
/* The upper bound address range of the ALT_PINMUX_FPGA_INTERFACE_GRP component. */
#define ALT_PINMUX_FPGA_INTERFACE_GRP_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_PINMUX_FPGA_INTERFACE_GRP_ADDR) + 0x100) - 1))


/*
 * Component Instance : noc_l4_priv_l4_priv_filter
 * 
 * Instance noc_l4_priv_l4_priv_filter of component ALT_NOC_L4_PRIV_FLT.
 * 
 * 
 */
/* The address of the ALT_NOC_L4_PRIV_FLT_L4_PRIV register for the ALT_NOC_L4_PRIV_FLT instance. */
#define ALT_NOC_L4_PRIV_FLT_L4_PRIV_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_L4_PRIV_FLT_ADDR) + ALT_NOC_L4_PRIV_FLT_L4_PRIV_OFST))
/* The address of the ALT_NOC_L4_PRIV_FLT_L4_PRIV_SET register for the ALT_NOC_L4_PRIV_FLT instance. */
#define ALT_NOC_L4_PRIV_FLT_L4_PRIV_SET_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_L4_PRIV_FLT_ADDR) + ALT_NOC_L4_PRIV_FLT_L4_PRIV_SET_OFST))
/* The address of the ALT_NOC_L4_PRIV_FLT_L4_PRIV_CLR register for the ALT_NOC_L4_PRIV_FLT instance. */
#define ALT_NOC_L4_PRIV_FLT_L4_PRIV_CLR_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_L4_PRIV_FLT_ADDR) + ALT_NOC_L4_PRIV_FLT_L4_PRIV_CLR_OFST))
/* The base address byte offset for the start of the ALT_NOC_L4_PRIV_FLT component. */
#define ALT_NOC_L4_PRIV_FLT_OFST        0xffd11000
/* The start address of the ALT_NOC_L4_PRIV_FLT component. */
#define ALT_NOC_L4_PRIV_FLT_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_NOC_L4_PRIV_FLT_OFST))
/* The lower bound address range of the ALT_NOC_L4_PRIV_FLT component. */
#define ALT_NOC_L4_PRIV_FLT_LB_ADDR     ALT_NOC_L4_PRIV_FLT_ADDR
/* The upper bound address range of the ALT_NOC_L4_PRIV_FLT component. */
#define ALT_NOC_L4_PRIV_FLT_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_NOC_L4_PRIV_FLT_ADDR) + 0x100) - 1))


/*
 * Component Instance : i_noc_mpu_m0_MPU_M1toDDRResp_main_RateAdapter
 * 
 * Instance i_noc_mpu_m0_MPU_M1toDDRResp_main_RateAdapter of component ALT_NOC_MPU_M1TODDRRESP_MAIN_RATE.
 * 
 * 
 */
/* The address of the ALT_NOC_MPU_M1TODDRRESP_MAIN_RATE_MPU_M1TODDRRESP_MAIN_RATE_COREID register for the ALT_NOC_MPU_M1TODDRRESP_MAIN_RATE instance. */
#define ALT_NOC_MPU_M1TODDRRESP_MAIN_RATE_MPU_M1TODDRRESP_MAIN_RATE_COREID_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_M1TODDRRESP_MAIN_RATE_ADDR) + ALT_NOC_MPU_M1TODDRRESP_MAIN_RATE_MPU_M1TODDRRESP_MAIN_RATE_COREID_OFST))
/* The address of the ALT_NOC_MPU_M1TODDRRESP_MAIN_RATE_MPU_M1TODDRRESP_MAIN_RATE_REVID register for the ALT_NOC_MPU_M1TODDRRESP_MAIN_RATE instance. */
#define ALT_NOC_MPU_M1TODDRRESP_MAIN_RATE_MPU_M1TODDRRESP_MAIN_RATE_REVID_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_M1TODDRRESP_MAIN_RATE_ADDR) + ALT_NOC_MPU_M1TODDRRESP_MAIN_RATE_MPU_M1TODDRRESP_MAIN_RATE_REVID_OFST))
/* The address of the ALT_NOC_MPU_M1TODDRRESP_MAIN_RATE_MPU_M1TODDRRESP_MAIN_RATE_RATE register for the ALT_NOC_MPU_M1TODDRRESP_MAIN_RATE instance. */
#define ALT_NOC_MPU_M1TODDRRESP_MAIN_RATE_MPU_M1TODDRRESP_MAIN_RATE_RATE_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_M1TODDRRESP_MAIN_RATE_ADDR) + ALT_NOC_MPU_M1TODDRRESP_MAIN_RATE_MPU_M1TODDRRESP_MAIN_RATE_RATE_OFST))
/* The address of the ALT_NOC_MPU_M1TODDRRESP_MAIN_RATE_MPU_M1TODDRRESP_MAIN_RATE_BYPASS register for the ALT_NOC_MPU_M1TODDRRESP_MAIN_RATE instance. */
#define ALT_NOC_MPU_M1TODDRRESP_MAIN_RATE_MPU_M1TODDRRESP_MAIN_RATE_BYPASS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_M1TODDRRESP_MAIN_RATE_ADDR) + ALT_NOC_MPU_M1TODDRRESP_MAIN_RATE_MPU_M1TODDRRESP_MAIN_RATE_BYPASS_OFST))
/* The base address byte offset for the start of the ALT_NOC_MPU_M1TODDRRESP_MAIN_RATE component. */
#define ALT_NOC_MPU_M1TODDRRESP_MAIN_RATE_OFST        0xffd11100
/* The start address of the ALT_NOC_MPU_M1TODDRRESP_MAIN_RATE component. */
#define ALT_NOC_MPU_M1TODDRRESP_MAIN_RATE_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_NOC_MPU_M1TODDRRESP_MAIN_RATE_OFST))
/* The lower bound address range of the ALT_NOC_MPU_M1TODDRRESP_MAIN_RATE component. */
#define ALT_NOC_MPU_M1TODDRRESP_MAIN_RATE_LB_ADDR     ALT_NOC_MPU_M1TODDRRESP_MAIN_RATE_ADDR
/* The upper bound address range of the ALT_NOC_MPU_M1TODDRRESP_MAIN_RATE component. */
#define ALT_NOC_MPU_M1TODDRRESP_MAIN_RATE_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_NOC_MPU_M1TODDRRESP_MAIN_RATE_ADDR) + 0x80) - 1))


/*
 * Component Instance : i_noc_mpu_m0_MPU_M0_rate_adResp_main_RateAdapter
 * 
 * Instance i_noc_mpu_m0_MPU_M0_rate_adResp_main_RateAdapter of component ALT_NOC_MPU_M0_RATE_ADRESP_MAIN_RATE.
 * 
 * 
 */
/* The address of the ALT_NOC_MPU_RATE_ADRESP_MAIN_RATE_MPU_M0_RATE_ADRESP_MAIN_RATE_COREID register for the ALT_NOC_MPU_M0_RATE_ADRESP_MAIN_RATE instance. */
#define ALT_NOC_MPU_M0_RATE_ADRESP_MAIN_RATE_MPU_M0_RATE_ADRESP_MAIN_RATE_COREID_ADDR  ALT_NOC_MPU_RATE_ADRESP_MAIN_RATE_MPU_M0_RATE_ADRESP_MAIN_RATE_COREID_ADDR(ALT_NOC_MPU_M0_RATE_ADRESP_MAIN_RATE_ADDR)
/* The address of the ALT_NOC_MPU_RATE_ADRESP_MAIN_RATE_MPU_M0_RATE_ADRESP_MAIN_RATE_REVID register for the ALT_NOC_MPU_M0_RATE_ADRESP_MAIN_RATE instance. */
#define ALT_NOC_MPU_M0_RATE_ADRESP_MAIN_RATE_MPU_M0_RATE_ADRESP_MAIN_RATE_REVID_ADDR  ALT_NOC_MPU_RATE_ADRESP_MAIN_RATE_MPU_M0_RATE_ADRESP_MAIN_RATE_REVID_ADDR(ALT_NOC_MPU_M0_RATE_ADRESP_MAIN_RATE_ADDR)
/* The address of the ALT_NOC_MPU_RATE_ADRESP_MAIN_RATE_MPU_M0_RATE_ADRESP_MAIN_RATE_RATE register for the ALT_NOC_MPU_M0_RATE_ADRESP_MAIN_RATE instance. */
#define ALT_NOC_MPU_M0_RATE_ADRESP_MAIN_RATE_MPU_M0_RATE_ADRESP_MAIN_RATE_RATE_ADDR  ALT_NOC_MPU_RATE_ADRESP_MAIN_RATE_MPU_M0_RATE_ADRESP_MAIN_RATE_RATE_ADDR(ALT_NOC_MPU_M0_RATE_ADRESP_MAIN_RATE_ADDR)
/* The address of the ALT_NOC_MPU_RATE_ADRESP_MAIN_RATE_MPU_M0_RATE_ADRESP_MAIN_RATE_BYPASS register for the ALT_NOC_MPU_M0_RATE_ADRESP_MAIN_RATE instance. */
#define ALT_NOC_MPU_M0_RATE_ADRESP_MAIN_RATE_MPU_M0_RATE_ADRESP_MAIN_RATE_BYPASS_ADDR  ALT_NOC_MPU_RATE_ADRESP_MAIN_RATE_MPU_M0_RATE_ADRESP_MAIN_RATE_BYPASS_ADDR(ALT_NOC_MPU_M0_RATE_ADRESP_MAIN_RATE_ADDR)
/* The base address byte offset for the start of the ALT_NOC_MPU_M0_RATE_ADRESP_MAIN_RATE component. */
#define ALT_NOC_MPU_M0_RATE_ADRESP_MAIN_RATE_OFST        0xffd11200
/* The start address of the ALT_NOC_MPU_M0_RATE_ADRESP_MAIN_RATE component. */
#define ALT_NOC_MPU_M0_RATE_ADRESP_MAIN_RATE_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_NOC_MPU_M0_RATE_ADRESP_MAIN_RATE_OFST))
/* The lower bound address range of the ALT_NOC_MPU_M0_RATE_ADRESP_MAIN_RATE component. */
#define ALT_NOC_MPU_M0_RATE_ADRESP_MAIN_RATE_LB_ADDR     ALT_NOC_MPU_M0_RATE_ADRESP_MAIN_RATE_ADDR
/* The upper bound address range of the ALT_NOC_MPU_M0_RATE_ADRESP_MAIN_RATE component. */
#define ALT_NOC_MPU_M0_RATE_ADRESP_MAIN_RATE_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_NOC_MPU_M0_RATE_ADRESP_MAIN_RATE_ADDR) + 0x80) - 1))


/*
 * Component Instance : i_noc_mpu_m0_L4_MP_rate_ad_main_RateAdapter
 * 
 * Instance i_noc_mpu_m0_L4_MP_rate_ad_main_RateAdapter of component ALT_NOC_MPU_L4_MP_RATE_AD_MAIN_RATE.
 * 
 * 
 */
/* The address of the ALT_NOC_MPU_L4_MP_AD_MAIN_RATE_COREID register for the ALT_NOC_MPU_L4_MP_RATE_AD_MAIN_RATE instance. */
#define ALT_NOC_MPU_L4_MP_AD_MAIN_RATE_COREID_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_L4_MP_RATE_AD_MAIN_RATE_ADDR) + ALT_NOC_MPU_L4_MP_AD_MAIN_RATE_COREID_OFST))
/* The address of the ALT_NOC_MPU_L4_MP_AD_MAIN_RATE_REVID register for the ALT_NOC_MPU_L4_MP_RATE_AD_MAIN_RATE instance. */
#define ALT_NOC_MPU_L4_MP_AD_MAIN_RATE_REVID_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_L4_MP_RATE_AD_MAIN_RATE_ADDR) + ALT_NOC_MPU_L4_MP_AD_MAIN_RATE_REVID_OFST))
/* The address of the ALT_NOC_MPU_L4_MP_AD_MAIN_RATE_RATE register for the ALT_NOC_MPU_L4_MP_RATE_AD_MAIN_RATE instance. */
#define ALT_NOC_MPU_L4_MP_AD_MAIN_RATE_RATE_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_L4_MP_RATE_AD_MAIN_RATE_ADDR) + ALT_NOC_MPU_L4_MP_AD_MAIN_RATE_RATE_OFST))
/* The address of the ALT_NOC_MPU_L4_MP_AD_MAIN_RATE_BYPASS register for the ALT_NOC_MPU_L4_MP_RATE_AD_MAIN_RATE instance. */
#define ALT_NOC_MPU_L4_MP_AD_MAIN_RATE_BYPASS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_L4_MP_RATE_AD_MAIN_RATE_ADDR) + ALT_NOC_MPU_L4_MP_AD_MAIN_RATE_BYPASS_OFST))
/* The base address byte offset for the start of the ALT_NOC_MPU_L4_MP_RATE_AD_MAIN_RATE component. */
#define ALT_NOC_MPU_L4_MP_RATE_AD_MAIN_RATE_OFST        0xffd11300
/* The start address of the ALT_NOC_MPU_L4_MP_RATE_AD_MAIN_RATE component. */
#define ALT_NOC_MPU_L4_MP_RATE_AD_MAIN_RATE_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_NOC_MPU_L4_MP_RATE_AD_MAIN_RATE_OFST))
/* The lower bound address range of the ALT_NOC_MPU_L4_MP_RATE_AD_MAIN_RATE component. */
#define ALT_NOC_MPU_L4_MP_RATE_AD_MAIN_RATE_LB_ADDR     ALT_NOC_MPU_L4_MP_RATE_AD_MAIN_RATE_ADDR
/* The upper bound address range of the ALT_NOC_MPU_L4_MP_RATE_AD_MAIN_RATE component. */
#define ALT_NOC_MPU_L4_MP_RATE_AD_MAIN_RATE_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_NOC_MPU_L4_MP_RATE_AD_MAIN_RATE_ADDR) + 0x80) - 1))


/*
 * Component Instance : i_noc_mpu_m0_fpga2soc_rate_ad_main_RateAdapter
 * 
 * Instance i_noc_mpu_m0_fpga2soc_rate_ad_main_RateAdapter of component ALT_NOC_MPU_F2H_RATE_AD_MAIN_RATE.
 * 
 * 
 */
/* The address of the ALT_NOC_MPU_F2H_RATE_AD_MAIN_RATE_F2H_RATE_AD_MAIN_RATE_COREID register for the ALT_NOC_MPU_F2H_RATE_AD_MAIN_RATE instance. */
#define ALT_NOC_MPU_F2H_RATE_AD_MAIN_RATE_F2H_RATE_AD_MAIN_RATE_COREID_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_F2H_RATE_AD_MAIN_RATE_ADDR) + ALT_NOC_MPU_F2H_RATE_AD_MAIN_RATE_F2H_RATE_AD_MAIN_RATE_COREID_OFST))
/* The address of the ALT_NOC_MPU_F2H_RATE_AD_MAIN_RATE_F2H_RATE_AD_MAIN_RATE_REVID register for the ALT_NOC_MPU_F2H_RATE_AD_MAIN_RATE instance. */
#define ALT_NOC_MPU_F2H_RATE_AD_MAIN_RATE_F2H_RATE_AD_MAIN_RATE_REVID_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_F2H_RATE_AD_MAIN_RATE_ADDR) + ALT_NOC_MPU_F2H_RATE_AD_MAIN_RATE_F2H_RATE_AD_MAIN_RATE_REVID_OFST))
/* The address of the ALT_NOC_MPU_F2H_RATE_AD_MAIN_RATE_F2H_RATE_AD_MAIN_RATE_RATE register for the ALT_NOC_MPU_F2H_RATE_AD_MAIN_RATE instance. */
#define ALT_NOC_MPU_F2H_RATE_AD_MAIN_RATE_F2H_RATE_AD_MAIN_RATE_RATE_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_F2H_RATE_AD_MAIN_RATE_ADDR) + ALT_NOC_MPU_F2H_RATE_AD_MAIN_RATE_F2H_RATE_AD_MAIN_RATE_RATE_OFST))
/* The address of the ALT_NOC_MPU_F2H_RATE_AD_MAIN_RATE_F2H_RATE_AD_MAIN_RATE_BYPASS register for the ALT_NOC_MPU_F2H_RATE_AD_MAIN_RATE instance. */
#define ALT_NOC_MPU_F2H_RATE_AD_MAIN_RATE_F2H_RATE_AD_MAIN_RATE_BYPASS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_F2H_RATE_AD_MAIN_RATE_ADDR) + ALT_NOC_MPU_F2H_RATE_AD_MAIN_RATE_F2H_RATE_AD_MAIN_RATE_BYPASS_OFST))
/* The base address byte offset for the start of the ALT_NOC_MPU_F2H_RATE_AD_MAIN_RATE component. */
#define ALT_NOC_MPU_F2H_RATE_AD_MAIN_RATE_OFST        0xffd11400
/* The start address of the ALT_NOC_MPU_F2H_RATE_AD_MAIN_RATE component. */
#define ALT_NOC_MPU_F2H_RATE_AD_MAIN_RATE_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_NOC_MPU_F2H_RATE_AD_MAIN_RATE_OFST))
/* The lower bound address range of the ALT_NOC_MPU_F2H_RATE_AD_MAIN_RATE component. */
#define ALT_NOC_MPU_F2H_RATE_AD_MAIN_RATE_LB_ADDR     ALT_NOC_MPU_F2H_RATE_AD_MAIN_RATE_ADDR
/* The upper bound address range of the ALT_NOC_MPU_F2H_RATE_AD_MAIN_RATE component. */
#define ALT_NOC_MPU_F2H_RATE_AD_MAIN_RATE_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_NOC_MPU_F2H_RATE_AD_MAIN_RATE_ADDR) + 0x80) - 1))


/*
 * Component Instance : i_noc_mpu_m0_L3Tosoc2fpgaResp_main_RateAdapter
 * 
 * Instance i_noc_mpu_m0_L3Tosoc2fpgaResp_main_RateAdapter of component ALT_NOC_MPU_L3TOH2FRESP_MAIN_RATE.
 * 
 * 
 */
/* The address of the ALT_NOC_MPU_L3TOH2FRESP_MAIN_RATE_L3TOH2FRESP_MAIN_RATE_COREID register for the ALT_NOC_MPU_L3TOH2FRESP_MAIN_RATE instance. */
#define ALT_NOC_MPU_L3TOH2FRESP_MAIN_RATE_L3TOH2FRESP_MAIN_RATE_COREID_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_L3TOH2FRESP_MAIN_RATE_ADDR) + ALT_NOC_MPU_L3TOH2FRESP_MAIN_RATE_L3TOH2FRESP_MAIN_RATE_COREID_OFST))
/* The address of the ALT_NOC_MPU_L3TOH2FRESP_MAIN_RATE_L3TOH2FRESP_MAIN_RATE_REVID register for the ALT_NOC_MPU_L3TOH2FRESP_MAIN_RATE instance. */
#define ALT_NOC_MPU_L3TOH2FRESP_MAIN_RATE_L3TOH2FRESP_MAIN_RATE_REVID_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_L3TOH2FRESP_MAIN_RATE_ADDR) + ALT_NOC_MPU_L3TOH2FRESP_MAIN_RATE_L3TOH2FRESP_MAIN_RATE_REVID_OFST))
/* The address of the ALT_NOC_MPU_L3TOH2FRESP_MAIN_RATE_L3TOH2FRESP_MAIN_RATE_RATE register for the ALT_NOC_MPU_L3TOH2FRESP_MAIN_RATE instance. */
#define ALT_NOC_MPU_L3TOH2FRESP_MAIN_RATE_L3TOH2FRESP_MAIN_RATE_RATE_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_L3TOH2FRESP_MAIN_RATE_ADDR) + ALT_NOC_MPU_L3TOH2FRESP_MAIN_RATE_L3TOH2FRESP_MAIN_RATE_RATE_OFST))
/* The address of the ALT_NOC_MPU_L3TOH2FRESP_MAIN_RATE_L3TOH2FRESP_MAIN_RATE_BYPASS register for the ALT_NOC_MPU_L3TOH2FRESP_MAIN_RATE instance. */
#define ALT_NOC_MPU_L3TOH2FRESP_MAIN_RATE_L3TOH2FRESP_MAIN_RATE_BYPASS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_L3TOH2FRESP_MAIN_RATE_ADDR) + ALT_NOC_MPU_L3TOH2FRESP_MAIN_RATE_L3TOH2FRESP_MAIN_RATE_BYPASS_OFST))
/* The base address byte offset for the start of the ALT_NOC_MPU_L3TOH2FRESP_MAIN_RATE component. */
#define ALT_NOC_MPU_L3TOH2FRESP_MAIN_RATE_OFST        0xffd11500
/* The start address of the ALT_NOC_MPU_L3TOH2FRESP_MAIN_RATE component. */
#define ALT_NOC_MPU_L3TOH2FRESP_MAIN_RATE_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_NOC_MPU_L3TOH2FRESP_MAIN_RATE_OFST))
/* The lower bound address range of the ALT_NOC_MPU_L3TOH2FRESP_MAIN_RATE component. */
#define ALT_NOC_MPU_L3TOH2FRESP_MAIN_RATE_LB_ADDR     ALT_NOC_MPU_L3TOH2FRESP_MAIN_RATE_ADDR
/* The upper bound address range of the ALT_NOC_MPU_L3TOH2FRESP_MAIN_RATE component. */
#define ALT_NOC_MPU_L3TOH2FRESP_MAIN_RATE_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_NOC_MPU_L3TOH2FRESP_MAIN_RATE_ADDR) + 0x80) - 1))


/*
 * Component Instance : i_noc_mpu_m0_acp_rate_ad_main_RateAdapter
 * 
 * Instance i_noc_mpu_m0_acp_rate_ad_main_RateAdapter of component ALT_NOC_MPU_ACP_RATE_AD_MAIN_RATE.
 * 
 * 
 */
/* The address of the ALT_NOC_MPU_ACP_RATE_AD_MAIN_RATE_ACP_RATE_AD_MAIN_RATE_COREID register for the ALT_NOC_MPU_ACP_RATE_AD_MAIN_RATE instance. */
#define ALT_NOC_MPU_ACP_RATE_AD_MAIN_RATE_ACP_RATE_AD_MAIN_RATE_COREID_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_ACP_RATE_AD_MAIN_RATE_ADDR) + ALT_NOC_MPU_ACP_RATE_AD_MAIN_RATE_ACP_RATE_AD_MAIN_RATE_COREID_OFST))
/* The address of the ALT_NOC_MPU_ACP_RATE_AD_MAIN_RATE_ACP_RATE_AD_MAIN_RATE_REVID register for the ALT_NOC_MPU_ACP_RATE_AD_MAIN_RATE instance. */
#define ALT_NOC_MPU_ACP_RATE_AD_MAIN_RATE_ACP_RATE_AD_MAIN_RATE_REVID_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_ACP_RATE_AD_MAIN_RATE_ADDR) + ALT_NOC_MPU_ACP_RATE_AD_MAIN_RATE_ACP_RATE_AD_MAIN_RATE_REVID_OFST))
/* The address of the ALT_NOC_MPU_ACP_RATE_AD_MAIN_RATE_ACP_RATE_AD_MAIN_RATE_RATE register for the ALT_NOC_MPU_ACP_RATE_AD_MAIN_RATE instance. */
#define ALT_NOC_MPU_ACP_RATE_AD_MAIN_RATE_ACP_RATE_AD_MAIN_RATE_RATE_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_ACP_RATE_AD_MAIN_RATE_ADDR) + ALT_NOC_MPU_ACP_RATE_AD_MAIN_RATE_ACP_RATE_AD_MAIN_RATE_RATE_OFST))
/* The address of the ALT_NOC_MPU_ACP_RATE_AD_MAIN_RATE_ACP_RATE_AD_MAIN_RATE_BYPASS register for the ALT_NOC_MPU_ACP_RATE_AD_MAIN_RATE instance. */
#define ALT_NOC_MPU_ACP_RATE_AD_MAIN_RATE_ACP_RATE_AD_MAIN_RATE_BYPASS_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_ACP_RATE_AD_MAIN_RATE_ADDR) + ALT_NOC_MPU_ACP_RATE_AD_MAIN_RATE_ACP_RATE_AD_MAIN_RATE_BYPASS_OFST))
/* The base address byte offset for the start of the ALT_NOC_MPU_ACP_RATE_AD_MAIN_RATE component. */
#define ALT_NOC_MPU_ACP_RATE_AD_MAIN_RATE_OFST        0xffd11600
/* The start address of the ALT_NOC_MPU_ACP_RATE_AD_MAIN_RATE component. */
#define ALT_NOC_MPU_ACP_RATE_AD_MAIN_RATE_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_NOC_MPU_ACP_RATE_AD_MAIN_RATE_OFST))
/* The lower bound address range of the ALT_NOC_MPU_ACP_RATE_AD_MAIN_RATE component. */
#define ALT_NOC_MPU_ACP_RATE_AD_MAIN_RATE_LB_ADDR     ALT_NOC_MPU_ACP_RATE_AD_MAIN_RATE_ADDR
/* The upper bound address range of the ALT_NOC_MPU_ACP_RATE_AD_MAIN_RATE component. */
#define ALT_NOC_MPU_ACP_RATE_AD_MAIN_RATE_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_NOC_MPU_ACP_RATE_AD_MAIN_RATE_ADDR) + 0x80) - 1))


/*
 * Component Instance : i_noc_mpu_m0_ddr_T_main_Probe
 * 
 * Instance i_noc_mpu_m0_ddr_T_main_Probe of component ALT_NOC_MPU_DDR_T_PRB.
 * 
 * 
 */
/* The address of the ALT_NOC_MPU_DDR_T_PRB_COREID register for the ALT_NOC_MPU_DDR_T_PRB instance. */
#define ALT_NOC_MPU_DDR_T_PRB_COREID_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_DDR_T_PRB_ADDR) + ALT_NOC_MPU_DDR_T_PRB_COREID_OFST))
/* The address of the ALT_NOC_MPU_DDR_T_PRB_REVID register for the ALT_NOC_MPU_DDR_T_PRB instance. */
#define ALT_NOC_MPU_DDR_T_PRB_REVID_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_DDR_T_PRB_ADDR) + ALT_NOC_MPU_DDR_T_PRB_REVID_OFST))
/* The address of the ALT_NOC_MPU_DDR_T_PRB_MAINCTL register for the ALT_NOC_MPU_DDR_T_PRB instance. */
#define ALT_NOC_MPU_DDR_T_PRB_MAINCTL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_DDR_T_PRB_ADDR) + ALT_NOC_MPU_DDR_T_PRB_MAINCTL_OFST))
/* The address of the ALT_NOC_MPU_DDR_T_PRB_CFGCTL register for the ALT_NOC_MPU_DDR_T_PRB instance. */
#define ALT_NOC_MPU_DDR_T_PRB_CFGCTL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_DDR_T_PRB_ADDR) + ALT_NOC_MPU_DDR_T_PRB_CFGCTL_OFST))
/* The address of the ALT_NOC_MPU_DDR_T_PRB_FLTLUT register for the ALT_NOC_MPU_DDR_T_PRB instance. */
#define ALT_NOC_MPU_DDR_T_PRB_FLTLUT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_DDR_T_PRB_ADDR) + ALT_NOC_MPU_DDR_T_PRB_FLTLUT_OFST))
/* The address of the ALT_NOC_MPU_DDR_T_PRB_TRACEALARMEN register for the ALT_NOC_MPU_DDR_T_PRB instance. */
#define ALT_NOC_MPU_DDR_T_PRB_TRACEALARMEN_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_DDR_T_PRB_ADDR) + ALT_NOC_MPU_DDR_T_PRB_TRACEALARMEN_OFST))
/* The address of the ALT_NOC_MPU_DDR_T_PRB_TRACEALARMSTAT register for the ALT_NOC_MPU_DDR_T_PRB instance. */
#define ALT_NOC_MPU_DDR_T_PRB_TRACEALARMSTAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_DDR_T_PRB_ADDR) + ALT_NOC_MPU_DDR_T_PRB_TRACEALARMSTAT_OFST))
/* The address of the ALT_NOC_MPU_DDR_T_PRB_TRACEALARMCLR register for the ALT_NOC_MPU_DDR_T_PRB instance. */
#define ALT_NOC_MPU_DDR_T_PRB_TRACEALARMCLR_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_DDR_T_PRB_ADDR) + ALT_NOC_MPU_DDR_T_PRB_TRACEALARMCLR_OFST))
/* The address of the ALT_NOC_MPU_DDR_T_PRB_STATPERIOD register for the ALT_NOC_MPU_DDR_T_PRB instance. */
#define ALT_NOC_MPU_DDR_T_PRB_STATPERIOD_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_DDR_T_PRB_ADDR) + ALT_NOC_MPU_DDR_T_PRB_STATPERIOD_OFST))
/* The address of the ALT_NOC_MPU_DDR_T_PRB_STATGO register for the ALT_NOC_MPU_DDR_T_PRB instance. */
#define ALT_NOC_MPU_DDR_T_PRB_STATGO_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_DDR_T_PRB_ADDR) + ALT_NOC_MPU_DDR_T_PRB_STATGO_OFST))
/* The address of the ALT_NOC_MPU_DDR_T_PRB_STATALARMMIN register for the ALT_NOC_MPU_DDR_T_PRB instance. */
#define ALT_NOC_MPU_DDR_T_PRB_STATALARMMIN_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_DDR_T_PRB_ADDR) + ALT_NOC_MPU_DDR_T_PRB_STATALARMMIN_OFST))
/* The address of the ALT_NOC_MPU_DDR_T_PRB_STATALARMMAX register for the ALT_NOC_MPU_DDR_T_PRB instance. */
#define ALT_NOC_MPU_DDR_T_PRB_STATALARMMAX_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_DDR_T_PRB_ADDR) + ALT_NOC_MPU_DDR_T_PRB_STATALARMMAX_OFST))
/* The address of the ALT_NOC_MPU_DDR_T_PRB_STATALARMSTAT register for the ALT_NOC_MPU_DDR_T_PRB instance. */
#define ALT_NOC_MPU_DDR_T_PRB_STATALARMSTAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_DDR_T_PRB_ADDR) + ALT_NOC_MPU_DDR_T_PRB_STATALARMSTAT_OFST))
/* The address of the ALT_NOC_MPU_DDR_T_PRB_STATALARMCLR register for the ALT_NOC_MPU_DDR_T_PRB instance. */
#define ALT_NOC_MPU_DDR_T_PRB_STATALARMCLR_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_DDR_T_PRB_ADDR) + ALT_NOC_MPU_DDR_T_PRB_STATALARMCLR_OFST))
/* The address of the ALT_NOC_MPU_DDR_T_PRB_STATALARMEN register for the ALT_NOC_MPU_DDR_T_PRB instance. */
#define ALT_NOC_MPU_DDR_T_PRB_STATALARMEN_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_DDR_T_PRB_ADDR) + ALT_NOC_MPU_DDR_T_PRB_STATALARMEN_OFST))
/* The address of the ALT_NOC_MPU_DDR_T_PRB_FLTS_0_ROUTEIDBASE register for the ALT_NOC_MPU_DDR_T_PRB instance. */
#define ALT_NOC_MPU_DDR_T_PRB_FLTS_0_ROUTEIDBASE_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_DDR_T_PRB_ADDR) + ALT_NOC_MPU_DDR_T_PRB_FLTS_0_ROUTEIDBASE_OFST))
/* The address of the ALT_NOC_MPU_DDR_T_PRB_FLTS_0_ROUTEIDMSK register for the ALT_NOC_MPU_DDR_T_PRB instance. */
#define ALT_NOC_MPU_DDR_T_PRB_FLTS_0_ROUTEIDMSK_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_DDR_T_PRB_ADDR) + ALT_NOC_MPU_DDR_T_PRB_FLTS_0_ROUTEIDMSK_OFST))
/* The address of the ALT_NOC_MPU_DDR_T_PRB_FLTS_0_ADDRBASE_LOW register for the ALT_NOC_MPU_DDR_T_PRB instance. */
#define ALT_NOC_MPU_DDR_T_PRB_FLTS_0_ADDRBASE_LOW_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_DDR_T_PRB_ADDR) + ALT_NOC_MPU_DDR_T_PRB_FLTS_0_ADDRBASE_LOW_OFST))
/* The address of the ALT_NOC_MPU_DDR_T_PRB_FLTS_0_WINDOWSIZE register for the ALT_NOC_MPU_DDR_T_PRB instance. */
#define ALT_NOC_MPU_DDR_T_PRB_FLTS_0_WINDOWSIZE_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_DDR_T_PRB_ADDR) + ALT_NOC_MPU_DDR_T_PRB_FLTS_0_WINDOWSIZE_OFST))
/* The address of the ALT_NOC_MPU_DDR_T_PRB_FLTS_0_SECURITYBASE register for the ALT_NOC_MPU_DDR_T_PRB instance. */
#define ALT_NOC_MPU_DDR_T_PRB_FLTS_0_SECURITYBASE_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_DDR_T_PRB_ADDR) + ALT_NOC_MPU_DDR_T_PRB_FLTS_0_SECURITYBASE_OFST))
/* The address of the ALT_NOC_MPU_DDR_T_PRB_FLTS_0_SECURITYMSK register for the ALT_NOC_MPU_DDR_T_PRB instance. */
#define ALT_NOC_MPU_DDR_T_PRB_FLTS_0_SECURITYMSK_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_DDR_T_PRB_ADDR) + ALT_NOC_MPU_DDR_T_PRB_FLTS_0_SECURITYMSK_OFST))
/* The address of the ALT_NOC_MPU_DDR_T_PRB_FLTS_0_OPCODE register for the ALT_NOC_MPU_DDR_T_PRB instance. */
#define ALT_NOC_MPU_DDR_T_PRB_FLTS_0_OPCODE_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_DDR_T_PRB_ADDR) + ALT_NOC_MPU_DDR_T_PRB_FLTS_0_OPCODE_OFST))
/* The address of the ALT_NOC_MPU_DDR_T_PRB_FLTS_0_STAT register for the ALT_NOC_MPU_DDR_T_PRB instance. */
#define ALT_NOC_MPU_DDR_T_PRB_FLTS_0_STAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_DDR_T_PRB_ADDR) + ALT_NOC_MPU_DDR_T_PRB_FLTS_0_STAT_OFST))
/* The address of the ALT_NOC_MPU_DDR_T_PRB_FLTS_0_LEN register for the ALT_NOC_MPU_DDR_T_PRB instance. */
#define ALT_NOC_MPU_DDR_T_PRB_FLTS_0_LEN_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_DDR_T_PRB_ADDR) + ALT_NOC_MPU_DDR_T_PRB_FLTS_0_LEN_OFST))
/* The address of the ALT_NOC_MPU_DDR_T_PRB_FLTS_0_URGENCY register for the ALT_NOC_MPU_DDR_T_PRB instance. */
#define ALT_NOC_MPU_DDR_T_PRB_FLTS_0_URGENCY_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_DDR_T_PRB_ADDR) + ALT_NOC_MPU_DDR_T_PRB_FLTS_0_URGENCY_OFST))
/* The address of the ALT_NOC_MPU_DDR_T_PRB_FLTS_1_ROUTEIDBASE register for the ALT_NOC_MPU_DDR_T_PRB instance. */
#define ALT_NOC_MPU_DDR_T_PRB_FLTS_1_ROUTEIDBASE_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_DDR_T_PRB_ADDR) + ALT_NOC_MPU_DDR_T_PRB_FLTS_1_ROUTEIDBASE_OFST))
/* The address of the ALT_NOC_MPU_DDR_T_PRB_FLTS_1_ROUTEIDMSK register for the ALT_NOC_MPU_DDR_T_PRB instance. */
#define ALT_NOC_MPU_DDR_T_PRB_FLTS_1_ROUTEIDMSK_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_DDR_T_PRB_ADDR) + ALT_NOC_MPU_DDR_T_PRB_FLTS_1_ROUTEIDMSK_OFST))
/* The address of the ALT_NOC_MPU_DDR_T_PRB_FLTS_1_ADDRBASE_LOW register for the ALT_NOC_MPU_DDR_T_PRB instance. */
#define ALT_NOC_MPU_DDR_T_PRB_FLTS_1_ADDRBASE_LOW_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_DDR_T_PRB_ADDR) + ALT_NOC_MPU_DDR_T_PRB_FLTS_1_ADDRBASE_LOW_OFST))
/* The address of the ALT_NOC_MPU_DDR_T_PRB_FLTS_1_WINDOWSIZE register for the ALT_NOC_MPU_DDR_T_PRB instance. */
#define ALT_NOC_MPU_DDR_T_PRB_FLTS_1_WINDOWSIZE_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_DDR_T_PRB_ADDR) + ALT_NOC_MPU_DDR_T_PRB_FLTS_1_WINDOWSIZE_OFST))
/* The address of the ALT_NOC_MPU_DDR_T_PRB_FLTS_1_SECURITYBASE register for the ALT_NOC_MPU_DDR_T_PRB instance. */
#define ALT_NOC_MPU_DDR_T_PRB_FLTS_1_SECURITYBASE_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_DDR_T_PRB_ADDR) + ALT_NOC_MPU_DDR_T_PRB_FLTS_1_SECURITYBASE_OFST))
/* The address of the ALT_NOC_MPU_DDR_T_PRB_FLTS_1_SECURITYMSK register for the ALT_NOC_MPU_DDR_T_PRB instance. */
#define ALT_NOC_MPU_DDR_T_PRB_FLTS_1_SECURITYMSK_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_DDR_T_PRB_ADDR) + ALT_NOC_MPU_DDR_T_PRB_FLTS_1_SECURITYMSK_OFST))
/* The address of the ALT_NOC_MPU_DDR_T_PRB_FLTS_1_OPCODE register for the ALT_NOC_MPU_DDR_T_PRB instance. */
#define ALT_NOC_MPU_DDR_T_PRB_FLTS_1_OPCODE_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_DDR_T_PRB_ADDR) + ALT_NOC_MPU_DDR_T_PRB_FLTS_1_OPCODE_OFST))
/* The address of the ALT_NOC_MPU_DDR_T_PRB_FLTS_1_STAT register for the ALT_NOC_MPU_DDR_T_PRB instance. */
#define ALT_NOC_MPU_DDR_T_PRB_FLTS_1_STAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_DDR_T_PRB_ADDR) + ALT_NOC_MPU_DDR_T_PRB_FLTS_1_STAT_OFST))
/* The address of the ALT_NOC_MPU_DDR_T_PRB_FLTS_1_LEN register for the ALT_NOC_MPU_DDR_T_PRB instance. */
#define ALT_NOC_MPU_DDR_T_PRB_FLTS_1_LEN_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_DDR_T_PRB_ADDR) + ALT_NOC_MPU_DDR_T_PRB_FLTS_1_LEN_OFST))
/* The address of the ALT_NOC_MPU_DDR_T_PRB_FLTS_1_URGENCY register for the ALT_NOC_MPU_DDR_T_PRB instance. */
#define ALT_NOC_MPU_DDR_T_PRB_FLTS_1_URGENCY_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_DDR_T_PRB_ADDR) + ALT_NOC_MPU_DDR_T_PRB_FLTS_1_URGENCY_OFST))
/* The address of the ALT_NOC_MPU_DDR_T_PRB_FLTS_2_ROUTEIDBASE register for the ALT_NOC_MPU_DDR_T_PRB instance. */
#define ALT_NOC_MPU_DDR_T_PRB_FLTS_2_ROUTEIDBASE_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_DDR_T_PRB_ADDR) + ALT_NOC_MPU_DDR_T_PRB_FLTS_2_ROUTEIDBASE_OFST))
/* The address of the ALT_NOC_MPU_DDR_T_PRB_FLTS_2_ROUTEIDMSK register for the ALT_NOC_MPU_DDR_T_PRB instance. */
#define ALT_NOC_MPU_DDR_T_PRB_FLTS_2_ROUTEIDMSK_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_DDR_T_PRB_ADDR) + ALT_NOC_MPU_DDR_T_PRB_FLTS_2_ROUTEIDMSK_OFST))
/* The address of the ALT_NOC_MPU_DDR_T_PRB_FLTS_2_ADDRBASE_LOW register for the ALT_NOC_MPU_DDR_T_PRB instance. */
#define ALT_NOC_MPU_DDR_T_PRB_FLTS_2_ADDRBASE_LOW_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_DDR_T_PRB_ADDR) + ALT_NOC_MPU_DDR_T_PRB_FLTS_2_ADDRBASE_LOW_OFST))
/* The address of the ALT_NOC_MPU_DDR_T_PRB_FLTS_2_WINDOWSIZE register for the ALT_NOC_MPU_DDR_T_PRB instance. */
#define ALT_NOC_MPU_DDR_T_PRB_FLTS_2_WINDOWSIZE_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_DDR_T_PRB_ADDR) + ALT_NOC_MPU_DDR_T_PRB_FLTS_2_WINDOWSIZE_OFST))
/* The address of the ALT_NOC_MPU_DDR_T_PRB_FLTS_2_SECURITYBASE register for the ALT_NOC_MPU_DDR_T_PRB instance. */
#define ALT_NOC_MPU_DDR_T_PRB_FLTS_2_SECURITYBASE_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_DDR_T_PRB_ADDR) + ALT_NOC_MPU_DDR_T_PRB_FLTS_2_SECURITYBASE_OFST))
/* The address of the ALT_NOC_MPU_DDR_T_PRB_FLTS_2_SECURITYMSK register for the ALT_NOC_MPU_DDR_T_PRB instance. */
#define ALT_NOC_MPU_DDR_T_PRB_FLTS_2_SECURITYMSK_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_DDR_T_PRB_ADDR) + ALT_NOC_MPU_DDR_T_PRB_FLTS_2_SECURITYMSK_OFST))
/* The address of the ALT_NOC_MPU_DDR_T_PRB_FLTS_2_OPCODE register for the ALT_NOC_MPU_DDR_T_PRB instance. */
#define ALT_NOC_MPU_DDR_T_PRB_FLTS_2_OPCODE_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_DDR_T_PRB_ADDR) + ALT_NOC_MPU_DDR_T_PRB_FLTS_2_OPCODE_OFST))
/* The address of the ALT_NOC_MPU_DDR_T_PRB_FLTS_2_STAT register for the ALT_NOC_MPU_DDR_T_PRB instance. */
#define ALT_NOC_MPU_DDR_T_PRB_FLTS_2_STAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_DDR_T_PRB_ADDR) + ALT_NOC_MPU_DDR_T_PRB_FLTS_2_STAT_OFST))
/* The address of the ALT_NOC_MPU_DDR_T_PRB_FLTS_2_LEN register for the ALT_NOC_MPU_DDR_T_PRB instance. */
#define ALT_NOC_MPU_DDR_T_PRB_FLTS_2_LEN_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_DDR_T_PRB_ADDR) + ALT_NOC_MPU_DDR_T_PRB_FLTS_2_LEN_OFST))
/* The address of the ALT_NOC_MPU_DDR_T_PRB_FLTS_2_URGENCY register for the ALT_NOC_MPU_DDR_T_PRB instance. */
#define ALT_NOC_MPU_DDR_T_PRB_FLTS_2_URGENCY_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_DDR_T_PRB_ADDR) + ALT_NOC_MPU_DDR_T_PRB_FLTS_2_URGENCY_OFST))
/* The address of the ALT_NOC_MPU_DDR_T_PRB_FLTS_3_ROUTEIDBASE register for the ALT_NOC_MPU_DDR_T_PRB instance. */
#define ALT_NOC_MPU_DDR_T_PRB_FLTS_3_ROUTEIDBASE_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_DDR_T_PRB_ADDR) + ALT_NOC_MPU_DDR_T_PRB_FLTS_3_ROUTEIDBASE_OFST))
/* The address of the ALT_NOC_MPU_DDR_T_PRB_FLTS_3_ROUTEIDMSK register for the ALT_NOC_MPU_DDR_T_PRB instance. */
#define ALT_NOC_MPU_DDR_T_PRB_FLTS_3_ROUTEIDMSK_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_DDR_T_PRB_ADDR) + ALT_NOC_MPU_DDR_T_PRB_FLTS_3_ROUTEIDMSK_OFST))
/* The address of the ALT_NOC_MPU_DDR_T_PRB_FLTS_3_ADDRBASE_LOW register for the ALT_NOC_MPU_DDR_T_PRB instance. */
#define ALT_NOC_MPU_DDR_T_PRB_FLTS_3_ADDRBASE_LOW_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_DDR_T_PRB_ADDR) + ALT_NOC_MPU_DDR_T_PRB_FLTS_3_ADDRBASE_LOW_OFST))
/* The address of the ALT_NOC_MPU_DDR_T_PRB_FLTS_3_WINDOWSIZE register for the ALT_NOC_MPU_DDR_T_PRB instance. */
#define ALT_NOC_MPU_DDR_T_PRB_FLTS_3_WINDOWSIZE_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_DDR_T_PRB_ADDR) + ALT_NOC_MPU_DDR_T_PRB_FLTS_3_WINDOWSIZE_OFST))
/* The address of the ALT_NOC_MPU_DDR_T_PRB_FLTS_3_SECURITYBASE register for the ALT_NOC_MPU_DDR_T_PRB instance. */
#define ALT_NOC_MPU_DDR_T_PRB_FLTS_3_SECURITYBASE_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_DDR_T_PRB_ADDR) + ALT_NOC_MPU_DDR_T_PRB_FLTS_3_SECURITYBASE_OFST))
/* The address of the ALT_NOC_MPU_DDR_T_PRB_FLTS_3_SECURITYMSK register for the ALT_NOC_MPU_DDR_T_PRB instance. */
#define ALT_NOC_MPU_DDR_T_PRB_FLTS_3_SECURITYMSK_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_DDR_T_PRB_ADDR) + ALT_NOC_MPU_DDR_T_PRB_FLTS_3_SECURITYMSK_OFST))
/* The address of the ALT_NOC_MPU_DDR_T_PRB_FLTS_3_OPCODE register for the ALT_NOC_MPU_DDR_T_PRB instance. */
#define ALT_NOC_MPU_DDR_T_PRB_FLTS_3_OPCODE_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_DDR_T_PRB_ADDR) + ALT_NOC_MPU_DDR_T_PRB_FLTS_3_OPCODE_OFST))
/* The address of the ALT_NOC_MPU_DDR_T_PRB_FLTS_3_STAT register for the ALT_NOC_MPU_DDR_T_PRB instance. */
#define ALT_NOC_MPU_DDR_T_PRB_FLTS_3_STAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_DDR_T_PRB_ADDR) + ALT_NOC_MPU_DDR_T_PRB_FLTS_3_STAT_OFST))
/* The address of the ALT_NOC_MPU_DDR_T_PRB_FLTS_3_LEN register for the ALT_NOC_MPU_DDR_T_PRB instance. */
#define ALT_NOC_MPU_DDR_T_PRB_FLTS_3_LEN_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_DDR_T_PRB_ADDR) + ALT_NOC_MPU_DDR_T_PRB_FLTS_3_LEN_OFST))
/* The address of the ALT_NOC_MPU_DDR_T_PRB_FLTS_3_URGENCY register for the ALT_NOC_MPU_DDR_T_PRB instance. */
#define ALT_NOC_MPU_DDR_T_PRB_FLTS_3_URGENCY_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_DDR_T_PRB_ADDR) + ALT_NOC_MPU_DDR_T_PRB_FLTS_3_URGENCY_OFST))
/* The address of the ALT_NOC_MPU_DDR_T_PRB_CNTRS_0_SRC register for the ALT_NOC_MPU_DDR_T_PRB instance. */
#define ALT_NOC_MPU_DDR_T_PRB_CNTRS_0_SRC_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_DDR_T_PRB_ADDR) + ALT_NOC_MPU_DDR_T_PRB_CNTRS_0_SRC_OFST))
/* The address of the ALT_NOC_MPU_DDR_T_PRB_CNTRS_0_ALARMMOD register for the ALT_NOC_MPU_DDR_T_PRB instance. */
#define ALT_NOC_MPU_DDR_T_PRB_CNTRS_0_ALARMMOD_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_DDR_T_PRB_ADDR) + ALT_NOC_MPU_DDR_T_PRB_CNTRS_0_ALARMMOD_OFST))
/* The address of the ALT_NOC_MPU_DDR_T_PRB_CNTRS_0_VAL register for the ALT_NOC_MPU_DDR_T_PRB instance. */
#define ALT_NOC_MPU_DDR_T_PRB_CNTRS_0_VAL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_DDR_T_PRB_ADDR) + ALT_NOC_MPU_DDR_T_PRB_CNTRS_0_VAL_OFST))
/* The address of the ALT_NOC_MPU_DDR_T_PRB_CNTRS_1_SRC register for the ALT_NOC_MPU_DDR_T_PRB instance. */
#define ALT_NOC_MPU_DDR_T_PRB_CNTRS_1_SRC_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_DDR_T_PRB_ADDR) + ALT_NOC_MPU_DDR_T_PRB_CNTRS_1_SRC_OFST))
/* The address of the ALT_NOC_MPU_DDR_T_PRB_CNTRS_1_ALARMMOD register for the ALT_NOC_MPU_DDR_T_PRB instance. */
#define ALT_NOC_MPU_DDR_T_PRB_CNTRS_1_ALARMMOD_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_DDR_T_PRB_ADDR) + ALT_NOC_MPU_DDR_T_PRB_CNTRS_1_ALARMMOD_OFST))
/* The address of the ALT_NOC_MPU_DDR_T_PRB_CNTRS_1_VAL register for the ALT_NOC_MPU_DDR_T_PRB instance. */
#define ALT_NOC_MPU_DDR_T_PRB_CNTRS_1_VAL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_DDR_T_PRB_ADDR) + ALT_NOC_MPU_DDR_T_PRB_CNTRS_1_VAL_OFST))
/* The base address byte offset for the start of the ALT_NOC_MPU_DDR_T_PRB component. */
#define ALT_NOC_MPU_DDR_T_PRB_OFST        0xffd12000
/* The start address of the ALT_NOC_MPU_DDR_T_PRB component. */
#define ALT_NOC_MPU_DDR_T_PRB_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_NOC_MPU_DDR_T_PRB_OFST))
/* The lower bound address range of the ALT_NOC_MPU_DDR_T_PRB component. */
#define ALT_NOC_MPU_DDR_T_PRB_LB_ADDR     ALT_NOC_MPU_DDR_T_PRB_ADDR
/* The upper bound address range of the ALT_NOC_MPU_DDR_T_PRB component. */
#define ALT_NOC_MPU_DDR_T_PRB_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_NOC_MPU_DDR_T_PRB_ADDR) + 0x400) - 1))


/*
 * Component Instance : i_noc_mpu_m0_ddr_T_main_Scheduler
 * 
 * Instance i_noc_mpu_m0_ddr_T_main_Scheduler of component ALT_NOC_MPU_DDR_T_SCHED.
 * 
 * 
 */
/* The address of the ALT_NOC_MPU_DDR_T_SCHED_COREID register for the ALT_NOC_MPU_DDR_T_SCHED instance. */
#define ALT_NOC_MPU_DDR_T_SCHED_COREID_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_DDR_T_SCHED_ADDR) + ALT_NOC_MPU_DDR_T_SCHED_COREID_OFST))
/* The address of the ALT_NOC_MPU_DDR_T_SCHED_REVID register for the ALT_NOC_MPU_DDR_T_SCHED instance. */
#define ALT_NOC_MPU_DDR_T_SCHED_REVID_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_DDR_T_SCHED_ADDR) + ALT_NOC_MPU_DDR_T_SCHED_REVID_OFST))
/* The address of the ALT_NOC_MPU_DDR_T_SCHED_DDRCONF register for the ALT_NOC_MPU_DDR_T_SCHED instance. */
#define ALT_NOC_MPU_DDR_T_SCHED_DDRCONF_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_DDR_T_SCHED_ADDR) + ALT_NOC_MPU_DDR_T_SCHED_DDRCONF_OFST))
/* The address of the ALT_NOC_MPU_DDR_T_SCHED_DDRTIMING register for the ALT_NOC_MPU_DDR_T_SCHED instance. */
#define ALT_NOC_MPU_DDR_T_SCHED_DDRTIMING_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_DDR_T_SCHED_ADDR) + ALT_NOC_MPU_DDR_T_SCHED_DDRTIMING_OFST))
/* The address of the ALT_NOC_MPU_DDR_T_SCHED_DDRMOD register for the ALT_NOC_MPU_DDR_T_SCHED instance. */
#define ALT_NOC_MPU_DDR_T_SCHED_DDRMOD_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_DDR_T_SCHED_ADDR) + ALT_NOC_MPU_DDR_T_SCHED_DDRMOD_OFST))
/* The address of the ALT_NOC_MPU_DDR_T_SCHED_RDLATENCY register for the ALT_NOC_MPU_DDR_T_SCHED instance. */
#define ALT_NOC_MPU_DDR_T_SCHED_RDLATENCY_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_DDR_T_SCHED_ADDR) + ALT_NOC_MPU_DDR_T_SCHED_RDLATENCY_OFST))
/* The address of the ALT_NOC_MPU_DDR_T_SCHED_ACTIVATE register for the ALT_NOC_MPU_DDR_T_SCHED instance. */
#define ALT_NOC_MPU_DDR_T_SCHED_ACTIVATE_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_DDR_T_SCHED_ADDR) + ALT_NOC_MPU_DDR_T_SCHED_ACTIVATE_OFST))
/* The address of the ALT_NOC_MPU_DDR_T_SCHED_DEVTODEV register for the ALT_NOC_MPU_DDR_T_SCHED instance. */
#define ALT_NOC_MPU_DDR_T_SCHED_DEVTODEV_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_DDR_T_SCHED_ADDR) + ALT_NOC_MPU_DDR_T_SCHED_DEVTODEV_OFST))
/* The base address byte offset for the start of the ALT_NOC_MPU_DDR_T_SCHED component. */
#define ALT_NOC_MPU_DDR_T_SCHED_OFST        0xffd12400
/* The start address of the ALT_NOC_MPU_DDR_T_SCHED component. */
#define ALT_NOC_MPU_DDR_T_SCHED_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_NOC_MPU_DDR_T_SCHED_OFST))
/* The lower bound address range of the ALT_NOC_MPU_DDR_T_SCHED component. */
#define ALT_NOC_MPU_DDR_T_SCHED_LB_ADDR     ALT_NOC_MPU_DDR_T_SCHED_ADDR
/* The upper bound address range of the ALT_NOC_MPU_DDR_T_SCHED component. */
#define ALT_NOC_MPU_DDR_T_SCHED_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_NOC_MPU_DDR_T_SCHED_ADDR) + 0x80) - 1))


/*
 * Component Instance : noc_fw_l4_per_l4_per_scr
 * 
 * Instance noc_fw_l4_per_l4_per_scr of component ALT_NOC_FW_L4_PER_SCR.
 * 
 * 
 */
/* The address of the ALT_NOC_FW_L4_PER_SCR_NAND_REG register for the ALT_NOC_FW_L4_PER_SCR instance. */
#define ALT_NOC_FW_L4_PER_SCR_NAND_REG_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_L4_PER_SCR_ADDR) + ALT_NOC_FW_L4_PER_SCR_NAND_REG_OFST))
/* The address of the ALT_NOC_FW_L4_PER_SCR_NAND_DATA register for the ALT_NOC_FW_L4_PER_SCR instance. */
#define ALT_NOC_FW_L4_PER_SCR_NAND_DATA_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_L4_PER_SCR_ADDR) + ALT_NOC_FW_L4_PER_SCR_NAND_DATA_OFST))
/* The address of the ALT_NOC_FW_L4_PER_SCR_QSPI_DATA register for the ALT_NOC_FW_L4_PER_SCR instance. */
#define ALT_NOC_FW_L4_PER_SCR_QSPI_DATA_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_L4_PER_SCR_ADDR) + ALT_NOC_FW_L4_PER_SCR_QSPI_DATA_OFST))
/* The address of the ALT_NOC_FW_L4_PER_SCR_USB0_REG register for the ALT_NOC_FW_L4_PER_SCR instance. */
#define ALT_NOC_FW_L4_PER_SCR_USB0_REG_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_L4_PER_SCR_ADDR) + ALT_NOC_FW_L4_PER_SCR_USB0_REG_OFST))
/* The address of the ALT_NOC_FW_L4_PER_SCR_USB1_REG register for the ALT_NOC_FW_L4_PER_SCR instance. */
#define ALT_NOC_FW_L4_PER_SCR_USB1_REG_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_L4_PER_SCR_ADDR) + ALT_NOC_FW_L4_PER_SCR_USB1_REG_OFST))
/* The address of the ALT_NOC_FW_L4_PER_SCR_DMA_NONSECURE register for the ALT_NOC_FW_L4_PER_SCR instance. */
#define ALT_NOC_FW_L4_PER_SCR_DMA_NONSECURE_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_L4_PER_SCR_ADDR) + ALT_NOC_FW_L4_PER_SCR_DMA_NONSECURE_OFST))
/* The address of the ALT_NOC_FW_L4_PER_SCR_DMA_SECURE register for the ALT_NOC_FW_L4_PER_SCR instance. */
#define ALT_NOC_FW_L4_PER_SCR_DMA_SECURE_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_L4_PER_SCR_ADDR) + ALT_NOC_FW_L4_PER_SCR_DMA_SECURE_OFST))
/* The address of the ALT_NOC_FW_L4_PER_SCR_SPI_MST0 register for the ALT_NOC_FW_L4_PER_SCR instance. */
#define ALT_NOC_FW_L4_PER_SCR_SPI_MST0_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_L4_PER_SCR_ADDR) + ALT_NOC_FW_L4_PER_SCR_SPI_MST0_OFST))
/* The address of the ALT_NOC_FW_L4_PER_SCR_SPI_MST1 register for the ALT_NOC_FW_L4_PER_SCR instance. */
#define ALT_NOC_FW_L4_PER_SCR_SPI_MST1_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_L4_PER_SCR_ADDR) + ALT_NOC_FW_L4_PER_SCR_SPI_MST1_OFST))
/* The address of the ALT_NOC_FW_L4_PER_SCR_SPI_SLV0 register for the ALT_NOC_FW_L4_PER_SCR instance. */
#define ALT_NOC_FW_L4_PER_SCR_SPI_SLV0_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_L4_PER_SCR_ADDR) + ALT_NOC_FW_L4_PER_SCR_SPI_SLV0_OFST))
/* The address of the ALT_NOC_FW_L4_PER_SCR_SPI_SLV1 register for the ALT_NOC_FW_L4_PER_SCR instance. */
#define ALT_NOC_FW_L4_PER_SCR_SPI_SLV1_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_L4_PER_SCR_ADDR) + ALT_NOC_FW_L4_PER_SCR_SPI_SLV1_OFST))
/* The address of the ALT_NOC_FW_L4_PER_SCR_EMAC0 register for the ALT_NOC_FW_L4_PER_SCR instance. */
#define ALT_NOC_FW_L4_PER_SCR_EMAC0_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_L4_PER_SCR_ADDR) + ALT_NOC_FW_L4_PER_SCR_EMAC0_OFST))
/* The address of the ALT_NOC_FW_L4_PER_SCR_EMAC1 register for the ALT_NOC_FW_L4_PER_SCR instance. */
#define ALT_NOC_FW_L4_PER_SCR_EMAC1_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_L4_PER_SCR_ADDR) + ALT_NOC_FW_L4_PER_SCR_EMAC1_OFST))
/* The address of the ALT_NOC_FW_L4_PER_SCR_EMAC2 register for the ALT_NOC_FW_L4_PER_SCR instance. */
#define ALT_NOC_FW_L4_PER_SCR_EMAC2_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_L4_PER_SCR_ADDR) + ALT_NOC_FW_L4_PER_SCR_EMAC2_OFST))
/* The address of the ALT_NOC_FW_L4_PER_SCR_EMAC3 register for the ALT_NOC_FW_L4_PER_SCR instance. */
#define ALT_NOC_FW_L4_PER_SCR_EMAC3_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_L4_PER_SCR_ADDR) + ALT_NOC_FW_L4_PER_SCR_EMAC3_OFST))
/* The address of the ALT_NOC_FW_L4_PER_SCR_QSPI register for the ALT_NOC_FW_L4_PER_SCR instance. */
#define ALT_NOC_FW_L4_PER_SCR_QSPI_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_L4_PER_SCR_ADDR) + ALT_NOC_FW_L4_PER_SCR_QSPI_OFST))
/* The address of the ALT_NOC_FW_L4_PER_SCR_SDMMC register for the ALT_NOC_FW_L4_PER_SCR instance. */
#define ALT_NOC_FW_L4_PER_SCR_SDMMC_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_L4_PER_SCR_ADDR) + ALT_NOC_FW_L4_PER_SCR_SDMMC_OFST))
/* The address of the ALT_NOC_FW_L4_PER_SCR_GPIO0 register for the ALT_NOC_FW_L4_PER_SCR instance. */
#define ALT_NOC_FW_L4_PER_SCR_GPIO0_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_L4_PER_SCR_ADDR) + ALT_NOC_FW_L4_PER_SCR_GPIO0_OFST))
/* The address of the ALT_NOC_FW_L4_PER_SCR_GPIO1 register for the ALT_NOC_FW_L4_PER_SCR instance. */
#define ALT_NOC_FW_L4_PER_SCR_GPIO1_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_L4_PER_SCR_ADDR) + ALT_NOC_FW_L4_PER_SCR_GPIO1_OFST))
/* The address of the ALT_NOC_FW_L4_PER_SCR_GPIO2 register for the ALT_NOC_FW_L4_PER_SCR instance. */
#define ALT_NOC_FW_L4_PER_SCR_GPIO2_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_L4_PER_SCR_ADDR) + ALT_NOC_FW_L4_PER_SCR_GPIO2_OFST))
/* The address of the ALT_NOC_FW_L4_PER_SCR_I2C0 register for the ALT_NOC_FW_L4_PER_SCR instance. */
#define ALT_NOC_FW_L4_PER_SCR_I2C0_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_L4_PER_SCR_ADDR) + ALT_NOC_FW_L4_PER_SCR_I2C0_OFST))
/* The address of the ALT_NOC_FW_L4_PER_SCR_I2C1 register for the ALT_NOC_FW_L4_PER_SCR instance. */
#define ALT_NOC_FW_L4_PER_SCR_I2C1_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_L4_PER_SCR_ADDR) + ALT_NOC_FW_L4_PER_SCR_I2C1_OFST))
/* The address of the ALT_NOC_FW_L4_PER_SCR_I2C2 register for the ALT_NOC_FW_L4_PER_SCR instance. */
#define ALT_NOC_FW_L4_PER_SCR_I2C2_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_L4_PER_SCR_ADDR) + ALT_NOC_FW_L4_PER_SCR_I2C2_OFST))
/* The address of the ALT_NOC_FW_L4_PER_SCR_I2C3 register for the ALT_NOC_FW_L4_PER_SCR instance. */
#define ALT_NOC_FW_L4_PER_SCR_I2C3_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_L4_PER_SCR_ADDR) + ALT_NOC_FW_L4_PER_SCR_I2C3_OFST))
/* The address of the ALT_NOC_FW_L4_PER_SCR_I2C4 register for the ALT_NOC_FW_L4_PER_SCR instance. */
#define ALT_NOC_FW_L4_PER_SCR_I2C4_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_L4_PER_SCR_ADDR) + ALT_NOC_FW_L4_PER_SCR_I2C4_OFST))
/* The address of the ALT_NOC_FW_L4_PER_SCR_SP_TMR0 register for the ALT_NOC_FW_L4_PER_SCR instance. */
#define ALT_NOC_FW_L4_PER_SCR_SP_TMR0_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_L4_PER_SCR_ADDR) + ALT_NOC_FW_L4_PER_SCR_SP_TMR0_OFST))
/* The address of the ALT_NOC_FW_L4_PER_SCR_SP_TMR1 register for the ALT_NOC_FW_L4_PER_SCR instance. */
#define ALT_NOC_FW_L4_PER_SCR_SP_TMR1_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_L4_PER_SCR_ADDR) + ALT_NOC_FW_L4_PER_SCR_SP_TMR1_OFST))
/* The address of the ALT_NOC_FW_L4_PER_SCR_UART0 register for the ALT_NOC_FW_L4_PER_SCR instance. */
#define ALT_NOC_FW_L4_PER_SCR_UART0_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_L4_PER_SCR_ADDR) + ALT_NOC_FW_L4_PER_SCR_UART0_OFST))
/* The address of the ALT_NOC_FW_L4_PER_SCR_UART1 register for the ALT_NOC_FW_L4_PER_SCR instance. */
#define ALT_NOC_FW_L4_PER_SCR_UART1_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_L4_PER_SCR_ADDR) + ALT_NOC_FW_L4_PER_SCR_UART1_OFST))
/* The base address byte offset for the start of the ALT_NOC_FW_L4_PER_SCR component. */
#define ALT_NOC_FW_L4_PER_SCR_OFST        0xffd13000
/* The start address of the ALT_NOC_FW_L4_PER_SCR component. */
#define ALT_NOC_FW_L4_PER_SCR_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_NOC_FW_L4_PER_SCR_OFST))
/* The lower bound address range of the ALT_NOC_FW_L4_PER_SCR component. */
#define ALT_NOC_FW_L4_PER_SCR_LB_ADDR     ALT_NOC_FW_L4_PER_SCR_ADDR
/* The upper bound address range of the ALT_NOC_FW_L4_PER_SCR component. */
#define ALT_NOC_FW_L4_PER_SCR_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_NOC_FW_L4_PER_SCR_ADDR) + 0x100) - 1))


/*
 * Component Instance : noc_fw_l4_sys_l4_sys_scr
 * 
 * Instance noc_fw_l4_sys_l4_sys_scr of component ALT_NOC_FW_L4_SYS_SCR.
 * 
 * 
 */
/* The address of the ALT_NOC_FW_L4_SYS_SCR_CAN0_ECC register for the ALT_NOC_FW_L4_SYS_SCR instance. */
#define ALT_NOC_FW_L4_SYS_SCR_CAN0_ECC_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_L4_SYS_SCR_ADDR) + ALT_NOC_FW_L4_SYS_SCR_CAN0_ECC_OFST))
/* The address of the ALT_NOC_FW_L4_SYS_SCR_CAN1_ECC register for the ALT_NOC_FW_L4_SYS_SCR instance. */
#define ALT_NOC_FW_L4_SYS_SCR_CAN1_ECC_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_L4_SYS_SCR_ADDR) + ALT_NOC_FW_L4_SYS_SCR_CAN1_ECC_OFST))
/* The address of the ALT_NOC_FW_L4_SYS_SCR_DMA_ECC register for the ALT_NOC_FW_L4_SYS_SCR instance. */
#define ALT_NOC_FW_L4_SYS_SCR_DMA_ECC_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_L4_SYS_SCR_ADDR) + ALT_NOC_FW_L4_SYS_SCR_DMA_ECC_OFST))
/* The address of the ALT_NOC_FW_L4_SYS_SCR_EMAC0RX_ECC register for the ALT_NOC_FW_L4_SYS_SCR instance. */
#define ALT_NOC_FW_L4_SYS_SCR_EMAC0RX_ECC_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_L4_SYS_SCR_ADDR) + ALT_NOC_FW_L4_SYS_SCR_EMAC0RX_ECC_OFST))
/* The address of the ALT_NOC_FW_L4_SYS_SCR_EMAC0TX_ECC register for the ALT_NOC_FW_L4_SYS_SCR instance. */
#define ALT_NOC_FW_L4_SYS_SCR_EMAC0TX_ECC_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_L4_SYS_SCR_ADDR) + ALT_NOC_FW_L4_SYS_SCR_EMAC0TX_ECC_OFST))
/* The address of the ALT_NOC_FW_L4_SYS_SCR_EMAC1RX_ECC register for the ALT_NOC_FW_L4_SYS_SCR instance. */
#define ALT_NOC_FW_L4_SYS_SCR_EMAC1RX_ECC_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_L4_SYS_SCR_ADDR) + ALT_NOC_FW_L4_SYS_SCR_EMAC1RX_ECC_OFST))
/* The address of the ALT_NOC_FW_L4_SYS_SCR_EMAC1TX_ECC register for the ALT_NOC_FW_L4_SYS_SCR instance. */
#define ALT_NOC_FW_L4_SYS_SCR_EMAC1TX_ECC_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_L4_SYS_SCR_ADDR) + ALT_NOC_FW_L4_SYS_SCR_EMAC1TX_ECC_OFST))
/* The address of the ALT_NOC_FW_L4_SYS_SCR_EMAC2RX_ECC register for the ALT_NOC_FW_L4_SYS_SCR instance. */
#define ALT_NOC_FW_L4_SYS_SCR_EMAC2RX_ECC_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_L4_SYS_SCR_ADDR) + ALT_NOC_FW_L4_SYS_SCR_EMAC2RX_ECC_OFST))
/* The address of the ALT_NOC_FW_L4_SYS_SCR_EMAC2TX_ECC register for the ALT_NOC_FW_L4_SYS_SCR instance. */
#define ALT_NOC_FW_L4_SYS_SCR_EMAC2TX_ECC_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_L4_SYS_SCR_ADDR) + ALT_NOC_FW_L4_SYS_SCR_EMAC2TX_ECC_OFST))
/* The address of the ALT_NOC_FW_L4_SYS_SCR_EMAC3RX_ECC register for the ALT_NOC_FW_L4_SYS_SCR instance. */
#define ALT_NOC_FW_L4_SYS_SCR_EMAC3RX_ECC_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_L4_SYS_SCR_ADDR) + ALT_NOC_FW_L4_SYS_SCR_EMAC3RX_ECC_OFST))
/* The address of the ALT_NOC_FW_L4_SYS_SCR_EMAC3TX_ECC register for the ALT_NOC_FW_L4_SYS_SCR instance. */
#define ALT_NOC_FW_L4_SYS_SCR_EMAC3TX_ECC_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_L4_SYS_SCR_ADDR) + ALT_NOC_FW_L4_SYS_SCR_EMAC3TX_ECC_OFST))
/* The address of the ALT_NOC_FW_L4_SYS_SCR_NAND_ECC register for the ALT_NOC_FW_L4_SYS_SCR instance. */
#define ALT_NOC_FW_L4_SYS_SCR_NAND_ECC_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_L4_SYS_SCR_ADDR) + ALT_NOC_FW_L4_SYS_SCR_NAND_ECC_OFST))
/* The address of the ALT_NOC_FW_L4_SYS_SCR_NAND_RD_ECC register for the ALT_NOC_FW_L4_SYS_SCR instance. */
#define ALT_NOC_FW_L4_SYS_SCR_NAND_RD_ECC_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_L4_SYS_SCR_ADDR) + ALT_NOC_FW_L4_SYS_SCR_NAND_RD_ECC_OFST))
/* The address of the ALT_NOC_FW_L4_SYS_SCR_NAND_WR_ECC register for the ALT_NOC_FW_L4_SYS_SCR instance. */
#define ALT_NOC_FW_L4_SYS_SCR_NAND_WR_ECC_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_L4_SYS_SCR_ADDR) + ALT_NOC_FW_L4_SYS_SCR_NAND_WR_ECC_OFST))
/* The address of the ALT_NOC_FW_L4_SYS_SCR_ONCHIPRAM_ECC register for the ALT_NOC_FW_L4_SYS_SCR instance. */
#define ALT_NOC_FW_L4_SYS_SCR_ONCHIPRAM_ECC_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_L4_SYS_SCR_ADDR) + ALT_NOC_FW_L4_SYS_SCR_ONCHIPRAM_ECC_OFST))
/* The address of the ALT_NOC_FW_L4_SYS_SCR_QSPI_ECC register for the ALT_NOC_FW_L4_SYS_SCR instance. */
#define ALT_NOC_FW_L4_SYS_SCR_QSPI_ECC_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_L4_SYS_SCR_ADDR) + ALT_NOC_FW_L4_SYS_SCR_QSPI_ECC_OFST))
/* The address of the ALT_NOC_FW_L4_SYS_SCR_SDMMC_ECC register for the ALT_NOC_FW_L4_SYS_SCR instance. */
#define ALT_NOC_FW_L4_SYS_SCR_SDMMC_ECC_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_L4_SYS_SCR_ADDR) + ALT_NOC_FW_L4_SYS_SCR_SDMMC_ECC_OFST))
/* The address of the ALT_NOC_FW_L4_SYS_SCR_USB0_ECC register for the ALT_NOC_FW_L4_SYS_SCR instance. */
#define ALT_NOC_FW_L4_SYS_SCR_USB0_ECC_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_L4_SYS_SCR_ADDR) + ALT_NOC_FW_L4_SYS_SCR_USB0_ECC_OFST))
/* The address of the ALT_NOC_FW_L4_SYS_SCR_USB1_ECC register for the ALT_NOC_FW_L4_SYS_SCR instance. */
#define ALT_NOC_FW_L4_SYS_SCR_USB1_ECC_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_L4_SYS_SCR_ADDR) + ALT_NOC_FW_L4_SYS_SCR_USB1_ECC_OFST))
/* The address of the ALT_NOC_FW_L4_SYS_SCR_CLK_MANAGER register for the ALT_NOC_FW_L4_SYS_SCR instance. */
#define ALT_NOC_FW_L4_SYS_SCR_CLK_MANAGER_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_L4_SYS_SCR_ADDR) + ALT_NOC_FW_L4_SYS_SCR_CLK_MANAGER_OFST))
/* The address of the ALT_NOC_FW_L4_SYS_SCR_FPGA_MANAGER_REG register for the ALT_NOC_FW_L4_SYS_SCR instance. */
#define ALT_NOC_FW_L4_SYS_SCR_FPGA_MANAGER_REG_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_L4_SYS_SCR_ADDR) + ALT_NOC_FW_L4_SYS_SCR_FPGA_MANAGER_REG_OFST))
/* The address of the ALT_NOC_FW_L4_SYS_SCR_PIN_MUX_REG register for the ALT_NOC_FW_L4_SYS_SCR instance. */
#define ALT_NOC_FW_L4_SYS_SCR_PIN_MUX_REG_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_L4_SYS_SCR_ADDR) + ALT_NOC_FW_L4_SYS_SCR_PIN_MUX_REG_OFST))
/* The address of the ALT_NOC_FW_L4_SYS_SCR_RST_MANAGER register for the ALT_NOC_FW_L4_SYS_SCR instance. */
#define ALT_NOC_FW_L4_SYS_SCR_RST_MANAGER_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_L4_SYS_SCR_ADDR) + ALT_NOC_FW_L4_SYS_SCR_RST_MANAGER_OFST))
/* The address of the ALT_NOC_FW_L4_SYS_SCR_SYS_MANAGER register for the ALT_NOC_FW_L4_SYS_SCR instance. */
#define ALT_NOC_FW_L4_SYS_SCR_SYS_MANAGER_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_L4_SYS_SCR_ADDR) + ALT_NOC_FW_L4_SYS_SCR_SYS_MANAGER_OFST))
/* The address of the ALT_NOC_FW_L4_SYS_SCR_OSC0_TMR register for the ALT_NOC_FW_L4_SYS_SCR instance. */
#define ALT_NOC_FW_L4_SYS_SCR_OSC0_TMR_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_L4_SYS_SCR_ADDR) + ALT_NOC_FW_L4_SYS_SCR_OSC0_TMR_OFST))
/* The address of the ALT_NOC_FW_L4_SYS_SCR_OSC1_TMR register for the ALT_NOC_FW_L4_SYS_SCR instance. */
#define ALT_NOC_FW_L4_SYS_SCR_OSC1_TMR_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_L4_SYS_SCR_ADDR) + ALT_NOC_FW_L4_SYS_SCR_OSC1_TMR_OFST))
/* The address of the ALT_NOC_FW_L4_SYS_SCR_WD0 register for the ALT_NOC_FW_L4_SYS_SCR instance. */
#define ALT_NOC_FW_L4_SYS_SCR_WD0_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_L4_SYS_SCR_ADDR) + ALT_NOC_FW_L4_SYS_SCR_WD0_OFST))
/* The address of the ALT_NOC_FW_L4_SYS_SCR_WD1 register for the ALT_NOC_FW_L4_SYS_SCR instance. */
#define ALT_NOC_FW_L4_SYS_SCR_WD1_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_L4_SYS_SCR_ADDR) + ALT_NOC_FW_L4_SYS_SCR_WD1_OFST))
/* The address of the ALT_NOC_FW_L4_SYS_SCR_DAP register for the ALT_NOC_FW_L4_SYS_SCR instance. */
#define ALT_NOC_FW_L4_SYS_SCR_DAP_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_L4_SYS_SCR_ADDR) + ALT_NOC_FW_L4_SYS_SCR_DAP_OFST))
/* The address of the ALT_NOC_FW_L4_SYS_SCR_FPGA_MANAGER_STREAMING register for the ALT_NOC_FW_L4_SYS_SCR instance. */
#define ALT_NOC_FW_L4_SYS_SCR_FPGA_MANAGER_STREAMING_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_L4_SYS_SCR_ADDR) + ALT_NOC_FW_L4_SYS_SCR_FPGA_MANAGER_STREAMING_OFST))
/* The address of the ALT_NOC_FW_L4_SYS_SCR_SEC_MGR_STREAMING register for the ALT_NOC_FW_L4_SYS_SCR instance. */
#define ALT_NOC_FW_L4_SYS_SCR_SECURITY_MANAGER_STREAMING_ADDR  ALT_NOC_FW_L4_SYS_SCR_SEC_MGR_STREAMING_ADDR(ALT_NOC_FW_L4_SYS_SCR_ADDR)
/* The address of the ALT_NOC_FW_L4_SYS_SCR_HMC_REG register for the ALT_NOC_FW_L4_SYS_SCR instance. */
#define ALT_NOC_FW_L4_SYS_SCR_HMC_REG_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_L4_SYS_SCR_ADDR) + ALT_NOC_FW_L4_SYS_SCR_HMC_REG_OFST))
/* The address of the ALT_NOC_FW_L4_SYS_SCR_HMC_ADAPTOR_REG register for the ALT_NOC_FW_L4_SYS_SCR instance. */
#define ALT_NOC_FW_L4_SYS_SCR_HMC_ADAPTOR_REG_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_L4_SYS_SCR_ADDR) + ALT_NOC_FW_L4_SYS_SCR_HMC_ADAPTOR_REG_OFST))
/* The address of the ALT_NOC_FW_L4_SYS_SCR_L3_INTERCONNECT_REG register for the ALT_NOC_FW_L4_SYS_SCR instance. */
#define ALT_NOC_FW_L4_SYS_SCR_L3_INTERCONNECT_REG_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_L4_SYS_SCR_ADDR) + ALT_NOC_FW_L4_SYS_SCR_L3_INTERCONNECT_REG_OFST))
/* The address of the ALT_NOC_FW_L4_SYS_SCR_DDR_SCHED_REG register for the ALT_NOC_FW_L4_SYS_SCR instance. */
#define ALT_NOC_FW_L4_SYS_SCR_DDR_SCHED_REG_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_L4_SYS_SCR_ADDR) + ALT_NOC_FW_L4_SYS_SCR_DDR_SCHED_REG_OFST))
/* The address of the ALT_NOC_FW_L4_SYS_SCR_L4_INTERCONNECT_FW_CSR register for the ALT_NOC_FW_L4_SYS_SCR instance. */
#define ALT_NOC_FW_L4_SYS_SCR_L4_INTERCONNECT_FW_CSR_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_L4_SYS_SCR_ADDR) + ALT_NOC_FW_L4_SYS_SCR_L4_INTERCONNECT_FW_CSR_OFST))
/* The address of the ALT_NOC_FW_L4_SYS_SCR_L4_INTERCONNECT_PRBS_CSR register for the ALT_NOC_FW_L4_SYS_SCR instance. */
#define ALT_NOC_FW_L4_SYS_SCR_L4_INTERCONNECT_PRBS_CSR_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_L4_SYS_SCR_ADDR) + ALT_NOC_FW_L4_SYS_SCR_L4_INTERCONNECT_PRBS_CSR_OFST))
/* The address of the ALT_NOC_FW_L4_SYS_SCR_L4_QOS_CSR register for the ALT_NOC_FW_L4_SYS_SCR instance. */
#define ALT_NOC_FW_L4_SYS_SCR_L4_QOS_CSR_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_L4_SYS_SCR_ADDR) + ALT_NOC_FW_L4_SYS_SCR_L4_QOS_CSR_OFST))
/* The base address byte offset for the start of the ALT_NOC_FW_L4_SYS_SCR component. */
#define ALT_NOC_FW_L4_SYS_SCR_OFST        0xffd13100
/* The start address of the ALT_NOC_FW_L4_SYS_SCR component. */
#define ALT_NOC_FW_L4_SYS_SCR_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_NOC_FW_L4_SYS_SCR_OFST))
/* The lower bound address range of the ALT_NOC_FW_L4_SYS_SCR component. */
#define ALT_NOC_FW_L4_SYS_SCR_LB_ADDR     ALT_NOC_FW_L4_SYS_SCR_ADDR
/* The upper bound address range of the ALT_NOC_FW_L4_SYS_SCR component. */
#define ALT_NOC_FW_L4_SYS_SCR_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_NOC_FW_L4_SYS_SCR_ADDR) + 0x100) - 1))


/*
 * Component Instance : noc_fw_ocram_ocram_scr
 * 
 * Instance noc_fw_ocram_ocram_scr of component ALT_NOC_FW_OCRAM_SCR.
 * 
 * 
 */
/* The address of the ALT_NOC_FW_OCRAM_SCR_EN register for the ALT_NOC_FW_OCRAM_SCR instance. */
#define ALT_NOC_FW_OCRAM_SCR_EN_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_OCRAM_SCR_ADDR) + ALT_NOC_FW_OCRAM_SCR_EN_OFST))
/* The address of the ALT_NOC_FW_OCRAM_SCR_EN_SET register for the ALT_NOC_FW_OCRAM_SCR instance. */
#define ALT_NOC_FW_OCRAM_SCR_EN_SET_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_OCRAM_SCR_ADDR) + ALT_NOC_FW_OCRAM_SCR_EN_SET_OFST))
/* The address of the ALT_NOC_FW_OCRAM_SCR_EN_CLR register for the ALT_NOC_FW_OCRAM_SCR instance. */
#define ALT_NOC_FW_OCRAM_SCR_EN_CLR_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_OCRAM_SCR_ADDR) + ALT_NOC_FW_OCRAM_SCR_EN_CLR_OFST))
/* The address of the ALT_NOC_FW_OCRAM_SCR_REG0ADDR register for the ALT_NOC_FW_OCRAM_SCR instance. */
#define ALT_NOC_FW_OCRAM_SCR_REG0ADDR_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_OCRAM_SCR_ADDR) + ALT_NOC_FW_OCRAM_SCR_REG0ADDR_OFST))
/* The address of the ALT_NOC_FW_OCRAM_SCR_REG1ADDR register for the ALT_NOC_FW_OCRAM_SCR instance. */
#define ALT_NOC_FW_OCRAM_SCR_REG1ADDR_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_OCRAM_SCR_ADDR) + ALT_NOC_FW_OCRAM_SCR_REG1ADDR_OFST))
/* The address of the ALT_NOC_FW_OCRAM_SCR_REG2ADDR register for the ALT_NOC_FW_OCRAM_SCR instance. */
#define ALT_NOC_FW_OCRAM_SCR_REG2ADDR_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_OCRAM_SCR_ADDR) + ALT_NOC_FW_OCRAM_SCR_REG2ADDR_OFST))
/* The address of the ALT_NOC_FW_OCRAM_SCR_REG3ADDR register for the ALT_NOC_FW_OCRAM_SCR instance. */
#define ALT_NOC_FW_OCRAM_SCR_REG3ADDR_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_OCRAM_SCR_ADDR) + ALT_NOC_FW_OCRAM_SCR_REG3ADDR_OFST))
/* The address of the ALT_NOC_FW_OCRAM_SCR_REG4ADDR register for the ALT_NOC_FW_OCRAM_SCR instance. */
#define ALT_NOC_FW_OCRAM_SCR_REG4ADDR_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_OCRAM_SCR_ADDR) + ALT_NOC_FW_OCRAM_SCR_REG4ADDR_OFST))
/* The address of the ALT_NOC_FW_OCRAM_SCR_REG5ADDR register for the ALT_NOC_FW_OCRAM_SCR instance. */
#define ALT_NOC_FW_OCRAM_SCR_REG5ADDR_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_OCRAM_SCR_ADDR) + ALT_NOC_FW_OCRAM_SCR_REG5ADDR_OFST))
/* The base address byte offset for the start of the ALT_NOC_FW_OCRAM_SCR component. */
#define ALT_NOC_FW_OCRAM_SCR_OFST        0xffd13200
/* The start address of the ALT_NOC_FW_OCRAM_SCR component. */
#define ALT_NOC_FW_OCRAM_SCR_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_NOC_FW_OCRAM_SCR_OFST))
/* The lower bound address range of the ALT_NOC_FW_OCRAM_SCR component. */
#define ALT_NOC_FW_OCRAM_SCR_LB_ADDR     ALT_NOC_FW_OCRAM_SCR_ADDR
/* The upper bound address range of the ALT_NOC_FW_OCRAM_SCR component. */
#define ALT_NOC_FW_OCRAM_SCR_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_NOC_FW_OCRAM_SCR_ADDR) + 0x100) - 1))


/*
 * Component Instance : noc_fw_ddr_mpu_fpga2sdram_ddr_scr
 * 
 * Instance noc_fw_ddr_mpu_fpga2sdram_ddr_scr of component ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR.
 * 
 * 
 */
/* The address of the ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR_EN register for the ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR instance. */
#define ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR_EN_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR_ADDR) + ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR_EN_OFST))
/* The address of the ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR_EN_SET register for the ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR instance. */
#define ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR_EN_SET_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR_ADDR) + ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR_EN_SET_OFST))
/* The address of the ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR_EN_CLR register for the ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR instance. */
#define ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR_EN_CLR_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR_ADDR) + ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR_EN_CLR_OFST))
/* The address of the ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR_MPUREG0ADDR register for the ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR instance. */
#define ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR_MPUREG0ADDR_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR_ADDR) + ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR_MPUREG0ADDR_OFST))
/* The address of the ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR_MPUREG1ADDR register for the ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR instance. */
#define ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR_MPUREG1ADDR_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR_ADDR) + ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR_MPUREG1ADDR_OFST))
/* The address of the ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR_MPUREG2ADDR register for the ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR instance. */
#define ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR_MPUREG2ADDR_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR_ADDR) + ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR_MPUREG2ADDR_OFST))
/* The address of the ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR_MPUREG3ADDR register for the ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR instance. */
#define ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR_MPUREG3ADDR_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR_ADDR) + ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR_MPUREG3ADDR_OFST))
/* The address of the ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR_F2SDR0REG0ADDR register for the ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR instance. */
#define ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR_F2SDR0REG0ADDR_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR_ADDR) + ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR_F2SDR0REG0ADDR_OFST))
/* The address of the ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR_F2SDR0REG1ADDR register for the ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR instance. */
#define ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR_F2SDR0REG1ADDR_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR_ADDR) + ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR_F2SDR0REG1ADDR_OFST))
/* The address of the ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR_F2SDR0REG2ADDR register for the ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR instance. */
#define ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR_F2SDR0REG2ADDR_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR_ADDR) + ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR_F2SDR0REG2ADDR_OFST))
/* The address of the ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR_F2SDR0REG3ADDR register for the ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR instance. */
#define ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR_F2SDR0REG3ADDR_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR_ADDR) + ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR_F2SDR0REG3ADDR_OFST))
/* The address of the ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR_F2SDR1REG0ADDR register for the ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR instance. */
#define ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR_F2SDR1REG0ADDR_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR_ADDR) + ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR_F2SDR1REG0ADDR_OFST))
/* The address of the ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR_F2SDR1REG1ADDR register for the ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR instance. */
#define ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR_F2SDR1REG1ADDR_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR_ADDR) + ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR_F2SDR1REG1ADDR_OFST))
/* The address of the ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR_F2SDR1REG2ADDR register for the ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR instance. */
#define ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR_F2SDR1REG2ADDR_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR_ADDR) + ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR_F2SDR1REG2ADDR_OFST))
/* The address of the ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR_F2SDR1REG3ADDR register for the ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR instance. */
#define ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR_F2SDR1REG3ADDR_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR_ADDR) + ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR_F2SDR1REG3ADDR_OFST))
/* The address of the ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR_F2SDR2REG0ADDR register for the ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR instance. */
#define ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR_F2SDR2REG0ADDR_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR_ADDR) + ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR_F2SDR2REG0ADDR_OFST))
/* The address of the ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR_F2SDR2REG1ADDR register for the ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR instance. */
#define ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR_F2SDR2REG1ADDR_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR_ADDR) + ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR_F2SDR2REG1ADDR_OFST))
/* The address of the ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR_F2SDR2REG2ADDR register for the ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR instance. */
#define ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR_F2SDR2REG2ADDR_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR_ADDR) + ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR_F2SDR2REG2ADDR_OFST))
/* The address of the ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR_F2SDR2REG3ADDR register for the ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR instance. */
#define ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR_F2SDR2REG3ADDR_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR_ADDR) + ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR_F2SDR2REG3ADDR_OFST))
/* The base address byte offset for the start of the ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR component. */
#define ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR_OFST        0xffd13300
/* The start address of the ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR component. */
#define ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR_OFST))
/* The lower bound address range of the ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR component. */
#define ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR_LB_ADDR     ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR_ADDR
/* The upper bound address range of the ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR component. */
#define ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR_ADDR) + 0x100) - 1))


/*
 * Component Instance : noc_fw_ddr_l3_ddr_scr
 * 
 * Instance noc_fw_ddr_l3_ddr_scr of component ALT_NOC_FW_DDR_L3_SCR.
 * 
 * 
 */
/* The address of the ALT_NOC_FW_DDR_L3_SCR_EN register for the ALT_NOC_FW_DDR_L3_SCR instance. */
#define ALT_NOC_FW_DDR_L3_SCR_EN_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_DDR_L3_SCR_ADDR) + ALT_NOC_FW_DDR_L3_SCR_EN_OFST))
/* The address of the ALT_NOC_FW_DDR_L3_SCR_EN_SET register for the ALT_NOC_FW_DDR_L3_SCR instance. */
#define ALT_NOC_FW_DDR_L3_SCR_EN_SET_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_DDR_L3_SCR_ADDR) + ALT_NOC_FW_DDR_L3_SCR_EN_SET_OFST))
/* The address of the ALT_NOC_FW_DDR_L3_SCR_EN_CLR register for the ALT_NOC_FW_DDR_L3_SCR instance. */
#define ALT_NOC_FW_DDR_L3_SCR_EN_CLR_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_DDR_L3_SCR_ADDR) + ALT_NOC_FW_DDR_L3_SCR_EN_CLR_OFST))
/* The address of the ALT_NOC_FW_DDR_L3_SCR_HPSREG0ADDR register for the ALT_NOC_FW_DDR_L3_SCR instance. */
#define ALT_NOC_FW_DDR_L3_SCR_HPSREG0ADDR_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_DDR_L3_SCR_ADDR) + ALT_NOC_FW_DDR_L3_SCR_HPSREG0ADDR_OFST))
/* The address of the ALT_NOC_FW_DDR_L3_SCR_HPSREG1ADDR register for the ALT_NOC_FW_DDR_L3_SCR instance. */
#define ALT_NOC_FW_DDR_L3_SCR_HPSREG1ADDR_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_DDR_L3_SCR_ADDR) + ALT_NOC_FW_DDR_L3_SCR_HPSREG1ADDR_OFST))
/* The address of the ALT_NOC_FW_DDR_L3_SCR_HPSREG2ADDR register for the ALT_NOC_FW_DDR_L3_SCR instance. */
#define ALT_NOC_FW_DDR_L3_SCR_HPSREG2ADDR_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_DDR_L3_SCR_ADDR) + ALT_NOC_FW_DDR_L3_SCR_HPSREG2ADDR_OFST))
/* The address of the ALT_NOC_FW_DDR_L3_SCR_HPSREG3ADDR register for the ALT_NOC_FW_DDR_L3_SCR instance. */
#define ALT_NOC_FW_DDR_L3_SCR_HPSREG3ADDR_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_DDR_L3_SCR_ADDR) + ALT_NOC_FW_DDR_L3_SCR_HPSREG3ADDR_OFST))
/* The address of the ALT_NOC_FW_DDR_L3_SCR_HPSREG4ADDR register for the ALT_NOC_FW_DDR_L3_SCR instance. */
#define ALT_NOC_FW_DDR_L3_SCR_HPSREG4ADDR_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_DDR_L3_SCR_ADDR) + ALT_NOC_FW_DDR_L3_SCR_HPSREG4ADDR_OFST))
/* The address of the ALT_NOC_FW_DDR_L3_SCR_HPSREG5ADDR register for the ALT_NOC_FW_DDR_L3_SCR instance. */
#define ALT_NOC_FW_DDR_L3_SCR_HPSREG5ADDR_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_DDR_L3_SCR_ADDR) + ALT_NOC_FW_DDR_L3_SCR_HPSREG5ADDR_OFST))
/* The address of the ALT_NOC_FW_DDR_L3_SCR_HPSREG6ADDR register for the ALT_NOC_FW_DDR_L3_SCR instance. */
#define ALT_NOC_FW_DDR_L3_SCR_HPSREG6ADDR_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_DDR_L3_SCR_ADDR) + ALT_NOC_FW_DDR_L3_SCR_HPSREG6ADDR_OFST))
/* The address of the ALT_NOC_FW_DDR_L3_SCR_HPSREG7ADDR register for the ALT_NOC_FW_DDR_L3_SCR instance. */
#define ALT_NOC_FW_DDR_L3_SCR_HPSREG7ADDR_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_DDR_L3_SCR_ADDR) + ALT_NOC_FW_DDR_L3_SCR_HPSREG7ADDR_OFST))
/* The address of the ALT_NOC_FW_DDR_L3_SCR_GLOB register for the ALT_NOC_FW_DDR_L3_SCR instance. */
#define ALT_NOC_FW_DDR_L3_SCR_GLOB_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_DDR_L3_SCR_ADDR) + ALT_NOC_FW_DDR_L3_SCR_GLOB_OFST))
/* The base address byte offset for the start of the ALT_NOC_FW_DDR_L3_SCR component. */
#define ALT_NOC_FW_DDR_L3_SCR_OFST        0xffd13400
/* The start address of the ALT_NOC_FW_DDR_L3_SCR component. */
#define ALT_NOC_FW_DDR_L3_SCR_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_NOC_FW_DDR_L3_SCR_OFST))
/* The lower bound address range of the ALT_NOC_FW_DDR_L3_SCR component. */
#define ALT_NOC_FW_DDR_L3_SCR_LB_ADDR     ALT_NOC_FW_DDR_L3_SCR_ADDR
/* The upper bound address range of the ALT_NOC_FW_DDR_L3_SCR component. */
#define ALT_NOC_FW_DDR_L3_SCR_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_NOC_FW_DDR_L3_SCR_ADDR) + 0x100) - 1))


/*
 * Component Instance : noc_fw_soc2fpga_soc2fpga_scr
 * 
 * Instance noc_fw_soc2fpga_soc2fpga_scr of component ALT_NOC_FW_H2F_SCR.
 * 
 * 
 */
/* The address of the ALT_NOC_FW_H2F_SCR_LWH2F register for the ALT_NOC_FW_H2F_SCR instance. */
#define ALT_NOC_FW_H2F_SCR_LWH2F_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_H2F_SCR_ADDR) + ALT_NOC_FW_H2F_SCR_LWH2F_OFST))
/* The address of the ALT_NOC_FW_H2F_SCR_H2F register for the ALT_NOC_FW_H2F_SCR instance. */
#define ALT_NOC_FW_H2F_SCR_H2F_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_FW_H2F_SCR_ADDR) + ALT_NOC_FW_H2F_SCR_H2F_OFST))
/* The base address byte offset for the start of the ALT_NOC_FW_H2F_SCR component. */
#define ALT_NOC_FW_H2F_SCR_OFST        0xffd13500
/* The start address of the ALT_NOC_FW_H2F_SCR component. */
#define ALT_NOC_FW_H2F_SCR_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_NOC_FW_H2F_SCR_OFST))
/* The lower bound address range of the ALT_NOC_FW_H2F_SCR component. */
#define ALT_NOC_FW_H2F_SCR_LB_ADDR     ALT_NOC_FW_H2F_SCR_ADDR
/* The upper bound address range of the ALT_NOC_FW_H2F_SCR component. */
#define ALT_NOC_FW_H2F_SCR_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_NOC_FW_H2F_SCR_ADDR) + 0x100) - 1))


/*
 * Component Instance : i_noc_mpu_m0_Probe_SoC2FPGA_main_Probe
 * 
 * Instance i_noc_mpu_m0_Probe_SoC2FPGA_main_Probe of component ALT_NOC_MPU_PRB_H2F_MAIN_PRB.
 * 
 * 
 */
/* The address of the ALT_NOC_MPU_PRB_H2F_MAIN_COREID register for the ALT_NOC_MPU_PRB_H2F_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_H2F_MAIN_COREID_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_H2F_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_H2F_MAIN_COREID_OFST))
/* The address of the ALT_NOC_MPU_PRB_H2F_MAIN_REVID register for the ALT_NOC_MPU_PRB_H2F_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_H2F_MAIN_REVID_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_H2F_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_H2F_MAIN_REVID_OFST))
/* The address of the ALT_NOC_MPU_PRB_H2F_MAIN_MAINCTL register for the ALT_NOC_MPU_PRB_H2F_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_H2F_MAIN_MAINCTL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_H2F_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_H2F_MAIN_MAINCTL_OFST))
/* The address of the ALT_NOC_MPU_PRB_H2F_MAIN_CFGCTL register for the ALT_NOC_MPU_PRB_H2F_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_H2F_MAIN_CFGCTL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_H2F_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_H2F_MAIN_CFGCTL_OFST))
/* The address of the ALT_NOC_MPU_PRB_H2F_MAIN_TRACEPORTSEL register for the ALT_NOC_MPU_PRB_H2F_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_H2F_MAIN_TRACEPORTSEL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_H2F_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_H2F_MAIN_TRACEPORTSEL_OFST))
/* The address of the ALT_NOC_MPU_PRB_H2F_MAIN_FLTLUT register for the ALT_NOC_MPU_PRB_H2F_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_H2F_MAIN_FLTLUT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_H2F_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_H2F_MAIN_FLTLUT_OFST))
/* The address of the ALT_NOC_MPU_PRB_H2F_MAIN_TRACEALARMEN register for the ALT_NOC_MPU_PRB_H2F_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_H2F_MAIN_TRACEALARMEN_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_H2F_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_H2F_MAIN_TRACEALARMEN_OFST))
/* The address of the ALT_NOC_MPU_PRB_H2F_MAIN_TRACEALARMSTAT register for the ALT_NOC_MPU_PRB_H2F_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_H2F_MAIN_TRACEALARMSTAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_H2F_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_H2F_MAIN_TRACEALARMSTAT_OFST))
/* The address of the ALT_NOC_MPU_PRB_H2F_MAIN_TRACEALARMCLR register for the ALT_NOC_MPU_PRB_H2F_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_H2F_MAIN_TRACEALARMCLR_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_H2F_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_H2F_MAIN_TRACEALARMCLR_OFST))
/* The address of the ALT_NOC_MPU_PRB_H2F_MAIN_STATPERIOD register for the ALT_NOC_MPU_PRB_H2F_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_H2F_MAIN_STATPERIOD_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_H2F_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_H2F_MAIN_STATPERIOD_OFST))
/* The address of the ALT_NOC_MPU_PRB_H2F_MAIN_STATGO register for the ALT_NOC_MPU_PRB_H2F_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_H2F_MAIN_STATGO_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_H2F_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_H2F_MAIN_STATGO_OFST))
/* The address of the ALT_NOC_MPU_PRB_H2F_MAIN_STATALARMMIN register for the ALT_NOC_MPU_PRB_H2F_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_H2F_MAIN_STATALARMMIN_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_H2F_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_H2F_MAIN_STATALARMMIN_OFST))
/* The address of the ALT_NOC_MPU_PRB_H2F_MAIN_STATALARMMAX register for the ALT_NOC_MPU_PRB_H2F_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_H2F_MAIN_STATALARMMAX_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_H2F_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_H2F_MAIN_STATALARMMAX_OFST))
/* The address of the ALT_NOC_MPU_PRB_H2F_MAIN_STATALARMSTAT register for the ALT_NOC_MPU_PRB_H2F_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_H2F_MAIN_STATALARMSTAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_H2F_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_H2F_MAIN_STATALARMSTAT_OFST))
/* The address of the ALT_NOC_MPU_PRB_H2F_MAIN_STATALARMCLR register for the ALT_NOC_MPU_PRB_H2F_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_H2F_MAIN_STATALARMCLR_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_H2F_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_H2F_MAIN_STATALARMCLR_OFST))
/* The address of the ALT_NOC_MPU_PRB_H2F_MAIN_STATALARMEN register for the ALT_NOC_MPU_PRB_H2F_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_H2F_MAIN_STATALARMEN_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_H2F_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_H2F_MAIN_STATALARMEN_OFST))
/* The address of the ALT_NOC_MPU_PRB_H2F_MAIN_FLTS_0_ROUTEIDBASE register for the ALT_NOC_MPU_PRB_H2F_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_H2F_MAIN_FLTS_0_ROUTEIDBASE_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_H2F_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_H2F_MAIN_FLTS_0_ROUTEIDBASE_OFST))
/* The address of the ALT_NOC_MPU_PRB_H2F_MAIN_FLTS_0_ROUTEIDMSK register for the ALT_NOC_MPU_PRB_H2F_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_H2F_MAIN_FLTS_0_ROUTEIDMSK_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_H2F_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_H2F_MAIN_FLTS_0_ROUTEIDMSK_OFST))
/* The address of the ALT_NOC_MPU_PRB_H2F_MAIN_FLTS_0_ADDRBASE_LOW register for the ALT_NOC_MPU_PRB_H2F_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_H2F_MAIN_FLTS_0_ADDRBASE_LOW_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_H2F_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_H2F_MAIN_FLTS_0_ADDRBASE_LOW_OFST))
/* The address of the ALT_NOC_MPU_PRB_H2F_MAIN_FLTS_0_WINDOWSIZE register for the ALT_NOC_MPU_PRB_H2F_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_H2F_MAIN_FLTS_0_WINDOWSIZE_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_H2F_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_H2F_MAIN_FLTS_0_WINDOWSIZE_OFST))
/* The address of the ALT_NOC_MPU_PRB_H2F_MAIN_FLTS_0_SECURITYBASE register for the ALT_NOC_MPU_PRB_H2F_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_H2F_MAIN_FLTS_0_SECURITYBASE_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_H2F_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_H2F_MAIN_FLTS_0_SECURITYBASE_OFST))
/* The address of the ALT_NOC_MPU_PRB_H2F_MAIN_FLTS_0_SECURITYMSK register for the ALT_NOC_MPU_PRB_H2F_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_H2F_MAIN_FLTS_0_SECURITYMSK_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_H2F_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_H2F_MAIN_FLTS_0_SECURITYMSK_OFST))
/* The address of the ALT_NOC_MPU_PRB_H2F_MAIN_FLTS_0_OPCODE register for the ALT_NOC_MPU_PRB_H2F_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_H2F_MAIN_FLTS_0_OPCODE_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_H2F_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_H2F_MAIN_FLTS_0_OPCODE_OFST))
/* The address of the ALT_NOC_MPU_PRB_H2F_MAIN_FLTS_0_STAT register for the ALT_NOC_MPU_PRB_H2F_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_H2F_MAIN_FLTS_0_STAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_H2F_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_H2F_MAIN_FLTS_0_STAT_OFST))
/* The address of the ALT_NOC_MPU_PRB_H2F_MAIN_FLTS_0_LEN register for the ALT_NOC_MPU_PRB_H2F_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_H2F_MAIN_FLTS_0_LEN_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_H2F_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_H2F_MAIN_FLTS_0_LEN_OFST))
/* The address of the ALT_NOC_MPU_PRB_H2F_MAIN_FLTS_0_URGENCY register for the ALT_NOC_MPU_PRB_H2F_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_H2F_MAIN_FLTS_0_URGENCY_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_H2F_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_H2F_MAIN_FLTS_0_URGENCY_OFST))
/* The address of the ALT_NOC_MPU_PRB_H2F_MAIN_FLTS_1_ROUTEIDBASE register for the ALT_NOC_MPU_PRB_H2F_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_H2F_MAIN_FLTS_1_ROUTEIDBASE_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_H2F_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_H2F_MAIN_FLTS_1_ROUTEIDBASE_OFST))
/* The address of the ALT_NOC_MPU_PRB_H2F_MAIN_FLTS_1_ROUTEIDMSK register for the ALT_NOC_MPU_PRB_H2F_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_H2F_MAIN_FLTS_1_ROUTEIDMSK_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_H2F_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_H2F_MAIN_FLTS_1_ROUTEIDMSK_OFST))
/* The address of the ALT_NOC_MPU_PRB_H2F_MAIN_FLTS_1_ADDRBASE_LOW register for the ALT_NOC_MPU_PRB_H2F_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_H2F_MAIN_FLTS_1_ADDRBASE_LOW_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_H2F_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_H2F_MAIN_FLTS_1_ADDRBASE_LOW_OFST))
/* The address of the ALT_NOC_MPU_PRB_H2F_MAIN_FLTS_1_WINDOWSIZE register for the ALT_NOC_MPU_PRB_H2F_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_H2F_MAIN_FLTS_1_WINDOWSIZE_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_H2F_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_H2F_MAIN_FLTS_1_WINDOWSIZE_OFST))
/* The address of the ALT_NOC_MPU_PRB_H2F_MAIN_FLTS_1_SECURITYBASE register for the ALT_NOC_MPU_PRB_H2F_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_H2F_MAIN_FLTS_1_SECURITYBASE_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_H2F_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_H2F_MAIN_FLTS_1_SECURITYBASE_OFST))
/* The address of the ALT_NOC_MPU_PRB_H2F_MAIN_FLTS_1_SECURITYMSK register for the ALT_NOC_MPU_PRB_H2F_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_H2F_MAIN_FLTS_1_SECURITYMSK_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_H2F_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_H2F_MAIN_FLTS_1_SECURITYMSK_OFST))
/* The address of the ALT_NOC_MPU_PRB_H2F_MAIN_FLTS_1_OPCODE register for the ALT_NOC_MPU_PRB_H2F_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_H2F_MAIN_FLTS_1_OPCODE_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_H2F_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_H2F_MAIN_FLTS_1_OPCODE_OFST))
/* The address of the ALT_NOC_MPU_PRB_H2F_MAIN_FLTS_1_STAT register for the ALT_NOC_MPU_PRB_H2F_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_H2F_MAIN_FLTS_1_STAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_H2F_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_H2F_MAIN_FLTS_1_STAT_OFST))
/* The address of the ALT_NOC_MPU_PRB_H2F_MAIN_FLTS_1_LEN register for the ALT_NOC_MPU_PRB_H2F_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_H2F_MAIN_FLTS_1_LEN_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_H2F_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_H2F_MAIN_FLTS_1_LEN_OFST))
/* The address of the ALT_NOC_MPU_PRB_H2F_MAIN_FLTS_1_URGENCY register for the ALT_NOC_MPU_PRB_H2F_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_H2F_MAIN_FLTS_1_URGENCY_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_H2F_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_H2F_MAIN_FLTS_1_URGENCY_OFST))
/* The address of the ALT_NOC_MPU_PRB_H2F_MAIN_CNTRS_0_PORTSEL register for the ALT_NOC_MPU_PRB_H2F_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_H2F_MAIN_CNTRS_0_PORTSEL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_H2F_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_H2F_MAIN_CNTRS_0_PORTSEL_OFST))
/* The address of the ALT_NOC_MPU_PRB_H2F_MAIN_CNTRS_0_SRC register for the ALT_NOC_MPU_PRB_H2F_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_H2F_MAIN_CNTRS_0_SRC_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_H2F_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_H2F_MAIN_CNTRS_0_SRC_OFST))
/* The address of the ALT_NOC_MPU_PRB_H2F_MAIN_CNTRS_0_ALARMMOD register for the ALT_NOC_MPU_PRB_H2F_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_H2F_MAIN_CNTRS_0_ALARMMOD_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_H2F_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_H2F_MAIN_CNTRS_0_ALARMMOD_OFST))
/* The address of the ALT_NOC_MPU_PRB_H2F_MAIN_CNTRS_0_VAL register for the ALT_NOC_MPU_PRB_H2F_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_H2F_MAIN_CNTRS_0_VAL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_H2F_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_H2F_MAIN_CNTRS_0_VAL_OFST))
/* The address of the ALT_NOC_MPU_PRB_H2F_MAIN_CNTRS_1_PORTSEL register for the ALT_NOC_MPU_PRB_H2F_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_H2F_MAIN_CNTRS_1_PORTSEL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_H2F_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_H2F_MAIN_CNTRS_1_PORTSEL_OFST))
/* The address of the ALT_NOC_MPU_PRB_H2F_MAIN_CNTRS_1_SRC register for the ALT_NOC_MPU_PRB_H2F_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_H2F_MAIN_CNTRS_1_SRC_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_H2F_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_H2F_MAIN_CNTRS_1_SRC_OFST))
/* The address of the ALT_NOC_MPU_PRB_H2F_MAIN_CNTRS_1_ALARMMOD register for the ALT_NOC_MPU_PRB_H2F_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_H2F_MAIN_CNTRS_1_ALARMMOD_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_H2F_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_H2F_MAIN_CNTRS_1_ALARMMOD_OFST))
/* The address of the ALT_NOC_MPU_PRB_H2F_MAIN_CNTRS_1_VAL register for the ALT_NOC_MPU_PRB_H2F_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_H2F_MAIN_CNTRS_1_VAL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_H2F_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_H2F_MAIN_CNTRS_1_VAL_OFST))
/* The address of the ALT_NOC_MPU_PRB_H2F_MAIN_CNTRS_2_PORTSEL register for the ALT_NOC_MPU_PRB_H2F_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_H2F_MAIN_CNTRS_2_PORTSEL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_H2F_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_H2F_MAIN_CNTRS_2_PORTSEL_OFST))
/* The address of the ALT_NOC_MPU_PRB_H2F_MAIN_CNTRS_2_SRC register for the ALT_NOC_MPU_PRB_H2F_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_H2F_MAIN_CNTRS_2_SRC_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_H2F_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_H2F_MAIN_CNTRS_2_SRC_OFST))
/* The address of the ALT_NOC_MPU_PRB_H2F_MAIN_CNTRS_2_ALARMMOD register for the ALT_NOC_MPU_PRB_H2F_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_H2F_MAIN_CNTRS_2_ALARMMOD_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_H2F_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_H2F_MAIN_CNTRS_2_ALARMMOD_OFST))
/* The address of the ALT_NOC_MPU_PRB_H2F_MAIN_CNTRS_2_VAL register for the ALT_NOC_MPU_PRB_H2F_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_H2F_MAIN_CNTRS_2_VAL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_H2F_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_H2F_MAIN_CNTRS_2_VAL_OFST))
/* The address of the ALT_NOC_MPU_PRB_H2F_MAIN_CNTRS_3_PORTSEL register for the ALT_NOC_MPU_PRB_H2F_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_H2F_MAIN_CNTRS_3_PORTSEL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_H2F_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_H2F_MAIN_CNTRS_3_PORTSEL_OFST))
/* The address of the ALT_NOC_MPU_PRB_H2F_MAIN_CNTRS_3_SRC register for the ALT_NOC_MPU_PRB_H2F_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_H2F_MAIN_CNTRS_3_SRC_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_H2F_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_H2F_MAIN_CNTRS_3_SRC_OFST))
/* The address of the ALT_NOC_MPU_PRB_H2F_MAIN_CNTRS_3_ALARMMOD register for the ALT_NOC_MPU_PRB_H2F_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_H2F_MAIN_CNTRS_3_ALARMMOD_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_H2F_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_H2F_MAIN_CNTRS_3_ALARMMOD_OFST))
/* The address of the ALT_NOC_MPU_PRB_H2F_MAIN_CNTRS_3_VAL register for the ALT_NOC_MPU_PRB_H2F_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_H2F_MAIN_CNTRS_3_VAL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_H2F_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_H2F_MAIN_CNTRS_3_VAL_OFST))
/* The base address byte offset for the start of the ALT_NOC_MPU_PRB_H2F_MAIN_PRB component. */
#define ALT_NOC_MPU_PRB_H2F_MAIN_PRB_OFST        0xffd14000
/* The start address of the ALT_NOC_MPU_PRB_H2F_MAIN_PRB component. */
#define ALT_NOC_MPU_PRB_H2F_MAIN_PRB_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_NOC_MPU_PRB_H2F_MAIN_PRB_OFST))
/* The lower bound address range of the ALT_NOC_MPU_PRB_H2F_MAIN_PRB component. */
#define ALT_NOC_MPU_PRB_H2F_MAIN_PRB_LB_ADDR     ALT_NOC_MPU_PRB_H2F_MAIN_PRB_ADDR
/* The upper bound address range of the ALT_NOC_MPU_PRB_H2F_MAIN_PRB component. */
#define ALT_NOC_MPU_PRB_H2F_MAIN_PRB_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_NOC_MPU_PRB_H2F_MAIN_PRB_ADDR) + 0x400) - 1))


/*
 * Component Instance : i_noc_mpu_m0_Probe_emacs_main_Probe
 * 
 * Instance i_noc_mpu_m0_Probe_emacs_main_Probe of component ALT_NOC_MPU_PRB_EMACS_MAIN_PRB.
 * 
 * 
 */
/* The address of the ALT_NOC_MPU_PRB_EMACS_MAIN_COREID register for the ALT_NOC_MPU_PRB_EMACS_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_EMACS_MAIN_COREID_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_EMACS_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_EMACS_MAIN_COREID_OFST))
/* The address of the ALT_NOC_MPU_PRB_EMACS_MAIN_REVID register for the ALT_NOC_MPU_PRB_EMACS_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_EMACS_MAIN_REVID_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_EMACS_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_EMACS_MAIN_REVID_OFST))
/* The address of the ALT_NOC_MPU_PRB_EMACS_MAIN_MAINCTL register for the ALT_NOC_MPU_PRB_EMACS_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_EMACS_MAIN_MAINCTL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_EMACS_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_EMACS_MAIN_MAINCTL_OFST))
/* The address of the ALT_NOC_MPU_PRB_EMACS_MAIN_CFGCTL register for the ALT_NOC_MPU_PRB_EMACS_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_EMACS_MAIN_CFGCTL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_EMACS_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_EMACS_MAIN_CFGCTL_OFST))
/* The address of the ALT_NOC_MPU_PRB_EMACS_MAIN_TRACEPORTSEL register for the ALT_NOC_MPU_PRB_EMACS_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_EMACS_MAIN_TRACEPORTSEL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_EMACS_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_EMACS_MAIN_TRACEPORTSEL_OFST))
/* The address of the ALT_NOC_MPU_PRB_EMACS_MAIN_FLTLUT register for the ALT_NOC_MPU_PRB_EMACS_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_EMACS_MAIN_FLTLUT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_EMACS_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_EMACS_MAIN_FLTLUT_OFST))
/* The address of the ALT_NOC_MPU_PRB_EMACS_MAIN_TRACEALARMEN register for the ALT_NOC_MPU_PRB_EMACS_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_EMACS_MAIN_TRACEALARMEN_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_EMACS_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_EMACS_MAIN_TRACEALARMEN_OFST))
/* The address of the ALT_NOC_MPU_PRB_EMACS_MAIN_TRACEALARMSTAT register for the ALT_NOC_MPU_PRB_EMACS_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_EMACS_MAIN_TRACEALARMSTAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_EMACS_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_EMACS_MAIN_TRACEALARMSTAT_OFST))
/* The address of the ALT_NOC_MPU_PRB_EMACS_MAIN_TRACEALARMCLR register for the ALT_NOC_MPU_PRB_EMACS_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_EMACS_MAIN_TRACEALARMCLR_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_EMACS_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_EMACS_MAIN_TRACEALARMCLR_OFST))
/* The address of the ALT_NOC_MPU_PRB_EMACS_MAIN_STATPERIOD register for the ALT_NOC_MPU_PRB_EMACS_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_EMACS_MAIN_STATPERIOD_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_EMACS_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_EMACS_MAIN_STATPERIOD_OFST))
/* The address of the ALT_NOC_MPU_PRB_EMACS_MAIN_STATGO register for the ALT_NOC_MPU_PRB_EMACS_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_EMACS_MAIN_STATGO_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_EMACS_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_EMACS_MAIN_STATGO_OFST))
/* The address of the ALT_NOC_MPU_PRB_EMACS_MAIN_STATALARMMIN register for the ALT_NOC_MPU_PRB_EMACS_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_EMACS_MAIN_STATALARMMIN_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_EMACS_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_EMACS_MAIN_STATALARMMIN_OFST))
/* The address of the ALT_NOC_MPU_PRB_EMACS_MAIN_STATALARMMAX register for the ALT_NOC_MPU_PRB_EMACS_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_EMACS_MAIN_STATALARMMAX_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_EMACS_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_EMACS_MAIN_STATALARMMAX_OFST))
/* The address of the ALT_NOC_MPU_PRB_EMACS_MAIN_STATALARMSTAT register for the ALT_NOC_MPU_PRB_EMACS_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_EMACS_MAIN_STATALARMSTAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_EMACS_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_EMACS_MAIN_STATALARMSTAT_OFST))
/* The address of the ALT_NOC_MPU_PRB_EMACS_MAIN_STATALARMCLR register for the ALT_NOC_MPU_PRB_EMACS_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_EMACS_MAIN_STATALARMCLR_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_EMACS_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_EMACS_MAIN_STATALARMCLR_OFST))
/* The address of the ALT_NOC_MPU_PRB_EMACS_MAIN_STATALARMEN register for the ALT_NOC_MPU_PRB_EMACS_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_EMACS_MAIN_STATALARMEN_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_EMACS_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_EMACS_MAIN_STATALARMEN_OFST))
/* The address of the ALT_NOC_MPU_PRB_EMACS_MAIN_FLTS_0_ROUTEIDBASE register for the ALT_NOC_MPU_PRB_EMACS_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_EMACS_MAIN_FLTS_0_ROUTEIDBASE_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_EMACS_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_EMACS_MAIN_FLTS_0_ROUTEIDBASE_OFST))
/* The address of the ALT_NOC_MPU_PRB_EMACS_MAIN_FLTS_0_ROUTEIDMSK register for the ALT_NOC_MPU_PRB_EMACS_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_EMACS_MAIN_FLTS_0_ROUTEIDMSK_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_EMACS_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_EMACS_MAIN_FLTS_0_ROUTEIDMSK_OFST))
/* The address of the ALT_NOC_MPU_PRB_EMACS_MAIN_FLTS_0_ADDRBASE_LOW register for the ALT_NOC_MPU_PRB_EMACS_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_EMACS_MAIN_FLTS_0_ADDRBASE_LOW_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_EMACS_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_EMACS_MAIN_FLTS_0_ADDRBASE_LOW_OFST))
/* The address of the ALT_NOC_MPU_PRB_EMACS_MAIN_FLTS_0_WINDOWSIZE register for the ALT_NOC_MPU_PRB_EMACS_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_EMACS_MAIN_FLTS_0_WINDOWSIZE_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_EMACS_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_EMACS_MAIN_FLTS_0_WINDOWSIZE_OFST))
/* The address of the ALT_NOC_MPU_PRB_EMACS_MAIN_FLTS_0_SECURITYBASE register for the ALT_NOC_MPU_PRB_EMACS_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_EMACS_MAIN_FLTS_0_SECURITYBASE_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_EMACS_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_EMACS_MAIN_FLTS_0_SECURITYBASE_OFST))
/* The address of the ALT_NOC_MPU_PRB_EMACS_MAIN_FLTS_0_SECURITYMSK register for the ALT_NOC_MPU_PRB_EMACS_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_EMACS_MAIN_FLTS_0_SECURITYMSK_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_EMACS_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_EMACS_MAIN_FLTS_0_SECURITYMSK_OFST))
/* The address of the ALT_NOC_MPU_PRB_EMACS_MAIN_FLTS_0_OPCODE register for the ALT_NOC_MPU_PRB_EMACS_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_EMACS_MAIN_FLTS_0_OPCODE_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_EMACS_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_EMACS_MAIN_FLTS_0_OPCODE_OFST))
/* The address of the ALT_NOC_MPU_PRB_EMACS_MAIN_FLTS_0_STAT register for the ALT_NOC_MPU_PRB_EMACS_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_EMACS_MAIN_FLTS_0_STAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_EMACS_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_EMACS_MAIN_FLTS_0_STAT_OFST))
/* The address of the ALT_NOC_MPU_PRB_EMACS_MAIN_FLTS_0_LEN register for the ALT_NOC_MPU_PRB_EMACS_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_EMACS_MAIN_FLTS_0_LEN_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_EMACS_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_EMACS_MAIN_FLTS_0_LEN_OFST))
/* The address of the ALT_NOC_MPU_PRB_EMACS_MAIN_FLTS_0_URGENCY register for the ALT_NOC_MPU_PRB_EMACS_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_EMACS_MAIN_FLTS_0_URGENCY_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_EMACS_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_EMACS_MAIN_FLTS_0_URGENCY_OFST))
/* The address of the ALT_NOC_MPU_PRB_EMACS_MAIN_FLTS_1_ROUTEIDBASE register for the ALT_NOC_MPU_PRB_EMACS_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_EMACS_MAIN_FLTS_1_ROUTEIDBASE_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_EMACS_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_EMACS_MAIN_FLTS_1_ROUTEIDBASE_OFST))
/* The address of the ALT_NOC_MPU_PRB_EMACS_MAIN_FLTS_1_ROUTEIDMSK register for the ALT_NOC_MPU_PRB_EMACS_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_EMACS_MAIN_FLTS_1_ROUTEIDMSK_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_EMACS_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_EMACS_MAIN_FLTS_1_ROUTEIDMSK_OFST))
/* The address of the ALT_NOC_MPU_PRB_EMACS_MAIN_FLTS_1_ADDRBASE_LOW register for the ALT_NOC_MPU_PRB_EMACS_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_EMACS_MAIN_FLTS_1_ADDRBASE_LOW_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_EMACS_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_EMACS_MAIN_FLTS_1_ADDRBASE_LOW_OFST))
/* The address of the ALT_NOC_MPU_PRB_EMACS_MAIN_FLTS_1_WINDOWSIZE register for the ALT_NOC_MPU_PRB_EMACS_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_EMACS_MAIN_FLTS_1_WINDOWSIZE_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_EMACS_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_EMACS_MAIN_FLTS_1_WINDOWSIZE_OFST))
/* The address of the ALT_NOC_MPU_PRB_EMACS_MAIN_FLTS_1_SECURITYBASE register for the ALT_NOC_MPU_PRB_EMACS_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_EMACS_MAIN_FLTS_1_SECURITYBASE_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_EMACS_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_EMACS_MAIN_FLTS_1_SECURITYBASE_OFST))
/* The address of the ALT_NOC_MPU_PRB_EMACS_MAIN_FLTS_1_SECURITYMSK register for the ALT_NOC_MPU_PRB_EMACS_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_EMACS_MAIN_FLTS_1_SECURITYMSK_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_EMACS_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_EMACS_MAIN_FLTS_1_SECURITYMSK_OFST))
/* The address of the ALT_NOC_MPU_PRB_EMACS_MAIN_FLTS_1_OPCODE register for the ALT_NOC_MPU_PRB_EMACS_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_EMACS_MAIN_FLTS_1_OPCODE_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_EMACS_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_EMACS_MAIN_FLTS_1_OPCODE_OFST))
/* The address of the ALT_NOC_MPU_PRB_EMACS_MAIN_FLTS_1_STAT register for the ALT_NOC_MPU_PRB_EMACS_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_EMACS_MAIN_FLTS_1_STAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_EMACS_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_EMACS_MAIN_FLTS_1_STAT_OFST))
/* The address of the ALT_NOC_MPU_PRB_EMACS_MAIN_FLTS_1_LEN register for the ALT_NOC_MPU_PRB_EMACS_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_EMACS_MAIN_FLTS_1_LEN_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_EMACS_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_EMACS_MAIN_FLTS_1_LEN_OFST))
/* The address of the ALT_NOC_MPU_PRB_EMACS_MAIN_FLTS_1_URGENCY register for the ALT_NOC_MPU_PRB_EMACS_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_EMACS_MAIN_FLTS_1_URGENCY_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_EMACS_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_EMACS_MAIN_FLTS_1_URGENCY_OFST))
/* The address of the ALT_NOC_MPU_PRB_EMACS_MAIN_CNTRS_0_PORTSEL register for the ALT_NOC_MPU_PRB_EMACS_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_EMACS_MAIN_CNTRS_0_PORTSEL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_EMACS_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_EMACS_MAIN_CNTRS_0_PORTSEL_OFST))
/* The address of the ALT_NOC_MPU_PRB_EMACS_MAIN_CNTRS_0_SRC register for the ALT_NOC_MPU_PRB_EMACS_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_EMACS_MAIN_CNTRS_0_SRC_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_EMACS_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_EMACS_MAIN_CNTRS_0_SRC_OFST))
/* The address of the ALT_NOC_MPU_PRB_EMACS_MAIN_CNTRS_0_ALARMMOD register for the ALT_NOC_MPU_PRB_EMACS_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_EMACS_MAIN_CNTRS_0_ALARMMOD_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_EMACS_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_EMACS_MAIN_CNTRS_0_ALARMMOD_OFST))
/* The address of the ALT_NOC_MPU_PRB_EMACS_MAIN_CNTRS_0_VAL register for the ALT_NOC_MPU_PRB_EMACS_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_EMACS_MAIN_CNTRS_0_VAL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_EMACS_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_EMACS_MAIN_CNTRS_0_VAL_OFST))
/* The address of the ALT_NOC_MPU_PRB_EMACS_MAIN_CNTRS_1_PORTSEL register for the ALT_NOC_MPU_PRB_EMACS_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_EMACS_MAIN_CNTRS_1_PORTSEL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_EMACS_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_EMACS_MAIN_CNTRS_1_PORTSEL_OFST))
/* The address of the ALT_NOC_MPU_PRB_EMACS_MAIN_CNTRS_1_SRC register for the ALT_NOC_MPU_PRB_EMACS_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_EMACS_MAIN_CNTRS_1_SRC_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_EMACS_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_EMACS_MAIN_CNTRS_1_SRC_OFST))
/* The address of the ALT_NOC_MPU_PRB_EMACS_MAIN_CNTRS_1_ALARMMOD register for the ALT_NOC_MPU_PRB_EMACS_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_EMACS_MAIN_CNTRS_1_ALARMMOD_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_EMACS_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_EMACS_MAIN_CNTRS_1_ALARMMOD_OFST))
/* The address of the ALT_NOC_MPU_PRB_EMACS_MAIN_CNTRS_1_VAL register for the ALT_NOC_MPU_PRB_EMACS_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_EMACS_MAIN_CNTRS_1_VAL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_EMACS_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_EMACS_MAIN_CNTRS_1_VAL_OFST))
/* The address of the ALT_NOC_MPU_PRB_EMACS_MAIN_CNTRS_2_PORTSEL register for the ALT_NOC_MPU_PRB_EMACS_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_EMACS_MAIN_CNTRS_2_PORTSEL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_EMACS_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_EMACS_MAIN_CNTRS_2_PORTSEL_OFST))
/* The address of the ALT_NOC_MPU_PRB_EMACS_MAIN_CNTRS_2_SRC register for the ALT_NOC_MPU_PRB_EMACS_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_EMACS_MAIN_CNTRS_2_SRC_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_EMACS_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_EMACS_MAIN_CNTRS_2_SRC_OFST))
/* The address of the ALT_NOC_MPU_PRB_EMACS_MAIN_CNTRS_2_ALARMMOD register for the ALT_NOC_MPU_PRB_EMACS_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_EMACS_MAIN_CNTRS_2_ALARMMOD_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_EMACS_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_EMACS_MAIN_CNTRS_2_ALARMMOD_OFST))
/* The address of the ALT_NOC_MPU_PRB_EMACS_MAIN_CNTRS_2_VAL register for the ALT_NOC_MPU_PRB_EMACS_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_EMACS_MAIN_CNTRS_2_VAL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_EMACS_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_EMACS_MAIN_CNTRS_2_VAL_OFST))
/* The address of the ALT_NOC_MPU_PRB_EMACS_MAIN_CNTRS_3_PORTSEL register for the ALT_NOC_MPU_PRB_EMACS_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_EMACS_MAIN_CNTRS_3_PORTSEL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_EMACS_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_EMACS_MAIN_CNTRS_3_PORTSEL_OFST))
/* The address of the ALT_NOC_MPU_PRB_EMACS_MAIN_CNTRS_3_SRC register for the ALT_NOC_MPU_PRB_EMACS_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_EMACS_MAIN_CNTRS_3_SRC_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_EMACS_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_EMACS_MAIN_CNTRS_3_SRC_OFST))
/* The address of the ALT_NOC_MPU_PRB_EMACS_MAIN_CNTRS_3_ALARMMOD register for the ALT_NOC_MPU_PRB_EMACS_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_EMACS_MAIN_CNTRS_3_ALARMMOD_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_EMACS_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_EMACS_MAIN_CNTRS_3_ALARMMOD_OFST))
/* The address of the ALT_NOC_MPU_PRB_EMACS_MAIN_CNTRS_3_VAL register for the ALT_NOC_MPU_PRB_EMACS_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_EMACS_MAIN_CNTRS_3_VAL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_EMACS_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_EMACS_MAIN_CNTRS_3_VAL_OFST))
/* The base address byte offset for the start of the ALT_NOC_MPU_PRB_EMACS_MAIN_PRB component. */
#define ALT_NOC_MPU_PRB_EMACS_MAIN_PRB_OFST        0xffd14400
/* The start address of the ALT_NOC_MPU_PRB_EMACS_MAIN_PRB component. */
#define ALT_NOC_MPU_PRB_EMACS_MAIN_PRB_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_NOC_MPU_PRB_EMACS_MAIN_PRB_OFST))
/* The lower bound address range of the ALT_NOC_MPU_PRB_EMACS_MAIN_PRB component. */
#define ALT_NOC_MPU_PRB_EMACS_MAIN_PRB_LB_ADDR     ALT_NOC_MPU_PRB_EMACS_MAIN_PRB_ADDR
/* The upper bound address range of the ALT_NOC_MPU_PRB_EMACS_MAIN_PRB component. */
#define ALT_NOC_MPU_PRB_EMACS_MAIN_PRB_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_NOC_MPU_PRB_EMACS_MAIN_PRB_ADDR) + 0x400) - 1))


/*
 * Component Instance : i_noc_mpu_m0_Probe_emacs_main_TransactionStatProfiler
 * 
 * Instance i_noc_mpu_m0_Probe_emacs_main_TransactionStatProfiler of component ALT_NOC_MPU_PRB_EMACS_MAIN_XACTSTATPROFILER.
 * 
 * 
 */
/* The address of the ALT_NOC_MPU_PRB_EMACS_MAIN_XACTSTATPROFILER_COREID register for the ALT_NOC_MPU_PRB_EMACS_MAIN_XACTSTATPROFILER instance. */
#define ALT_NOC_MPU_PRB_EMACS_MAIN_XACTSTATPROFILER_COREID_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_EMACS_MAIN_XACTSTATPROFILER_ADDR) + ALT_NOC_MPU_PRB_EMACS_MAIN_XACTSTATPROFILER_COREID_OFST))
/* The address of the ALT_NOC_MPU_PRB_EMACS_MAIN_XACTSTATPROFILER_REVID register for the ALT_NOC_MPU_PRB_EMACS_MAIN_XACTSTATPROFILER instance. */
#define ALT_NOC_MPU_PRB_EMACS_MAIN_XACTSTATPROFILER_REVID_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_EMACS_MAIN_XACTSTATPROFILER_ADDR) + ALT_NOC_MPU_PRB_EMACS_MAIN_XACTSTATPROFILER_REVID_OFST))
/* The address of the ALT_NOC_MPU_PRB_EMACS_MAIN_XACTSTATPROFILER_EN register for the ALT_NOC_MPU_PRB_EMACS_MAIN_XACTSTATPROFILER instance. */
#define ALT_NOC_MPU_PRB_EMACS_MAIN_XACTSTATPROFILER_EN_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_EMACS_MAIN_XACTSTATPROFILER_ADDR) + ALT_NOC_MPU_PRB_EMACS_MAIN_XACTSTATPROFILER_EN_OFST))
/* The address of the ALT_NOC_MPU_PRB_EMACS_MAIN_XACTSTATPROFILER_MOD register for the ALT_NOC_MPU_PRB_EMACS_MAIN_XACTSTATPROFILER instance. */
#define ALT_NOC_MPU_PRB_EMACS_MAIN_XACTSTATPROFILER_MOD_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_EMACS_MAIN_XACTSTATPROFILER_ADDR) + ALT_NOC_MPU_PRB_EMACS_MAIN_XACTSTATPROFILER_MOD_OFST))
/* The address of the ALT_NOC_MPU_PRB_EMACS_MAIN_XACTSTATPROFILER_THRESHOLDS_0_0 register for the ALT_NOC_MPU_PRB_EMACS_MAIN_XACTSTATPROFILER instance. */
#define ALT_NOC_MPU_PRB_EMACS_MAIN_XACTSTATPROFILER_THRESHOLDS_0_0_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_EMACS_MAIN_XACTSTATPROFILER_ADDR) + ALT_NOC_MPU_PRB_EMACS_MAIN_XACTSTATPROFILER_THRESHOLDS_0_0_OFST))
/* The address of the ALT_NOC_MPU_PRB_EMACS_MAIN_XACTSTATPROFILER_THRESHOLDS_0_1 register for the ALT_NOC_MPU_PRB_EMACS_MAIN_XACTSTATPROFILER instance. */
#define ALT_NOC_MPU_PRB_EMACS_MAIN_XACTSTATPROFILER_THRESHOLDS_0_1_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_EMACS_MAIN_XACTSTATPROFILER_ADDR) + ALT_NOC_MPU_PRB_EMACS_MAIN_XACTSTATPROFILER_THRESHOLDS_0_1_OFST))
/* The address of the ALT_NOC_MPU_PRB_EMACS_MAIN_XACTSTATPROFILER_THRESHOLDS_0_2 register for the ALT_NOC_MPU_PRB_EMACS_MAIN_XACTSTATPROFILER instance. */
#define ALT_NOC_MPU_PRB_EMACS_MAIN_XACTSTATPROFILER_THRESHOLDS_0_2_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_EMACS_MAIN_XACTSTATPROFILER_ADDR) + ALT_NOC_MPU_PRB_EMACS_MAIN_XACTSTATPROFILER_THRESHOLDS_0_2_OFST))
/* The address of the ALT_NOC_MPU_PRB_EMACS_MAIN_XACTSTATPROFILER_OVFSTAT register for the ALT_NOC_MPU_PRB_EMACS_MAIN_XACTSTATPROFILER instance. */
#define ALT_NOC_MPU_PRB_EMACS_MAIN_XACTSTATPROFILER_OVFSTAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_EMACS_MAIN_XACTSTATPROFILER_ADDR) + ALT_NOC_MPU_PRB_EMACS_MAIN_XACTSTATPROFILER_OVFSTAT_OFST))
/* The address of the ALT_NOC_MPU_PRB_EMACS_MAIN_XACTSTATPROFILER_OVFRST register for the ALT_NOC_MPU_PRB_EMACS_MAIN_XACTSTATPROFILER instance. */
#define ALT_NOC_MPU_PRB_EMACS_MAIN_XACTSTATPROFILER_OVFRST_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_EMACS_MAIN_XACTSTATPROFILER_ADDR) + ALT_NOC_MPU_PRB_EMACS_MAIN_XACTSTATPROFILER_OVFRST_OFST))
/* The address of the ALT_NOC_MPU_PRB_EMACS_MAIN_XACTSTATPROFILER_PENDINGEVENTMOD register for the ALT_NOC_MPU_PRB_EMACS_MAIN_XACTSTATPROFILER instance. */
#define ALT_NOC_MPU_PRB_EMACS_MAIN_XACTSTATPROFILER_PENDINGEVENTMOD_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_EMACS_MAIN_XACTSTATPROFILER_ADDR) + ALT_NOC_MPU_PRB_EMACS_MAIN_XACTSTATPROFILER_PENDINGEVENTMOD_OFST))
/* The address of the ALT_NOC_MPU_PRB_EMACS_MAIN_XACTSTATPROFILER_PRESCALER register for the ALT_NOC_MPU_PRB_EMACS_MAIN_XACTSTATPROFILER instance. */
#define ALT_NOC_MPU_PRB_EMACS_MAIN_XACTSTATPROFILER_PRESCALER_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_EMACS_MAIN_XACTSTATPROFILER_ADDR) + ALT_NOC_MPU_PRB_EMACS_MAIN_XACTSTATPROFILER_PRESCALER_OFST))
/* The base address byte offset for the start of the ALT_NOC_MPU_PRB_EMACS_MAIN_XACTSTATPROFILER component. */
#define ALT_NOC_MPU_PRB_EMACS_MAIN_XACTSTATPROFILER_OFST        0xffd14800
/* The start address of the ALT_NOC_MPU_PRB_EMACS_MAIN_XACTSTATPROFILER component. */
#define ALT_NOC_MPU_PRB_EMACS_MAIN_XACTSTATPROFILER_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_NOC_MPU_PRB_EMACS_MAIN_XACTSTATPROFILER_OFST))
/* The lower bound address range of the ALT_NOC_MPU_PRB_EMACS_MAIN_XACTSTATPROFILER component. */
#define ALT_NOC_MPU_PRB_EMACS_MAIN_XACTSTATPROFILER_LB_ADDR     ALT_NOC_MPU_PRB_EMACS_MAIN_XACTSTATPROFILER_ADDR
/* The upper bound address range of the ALT_NOC_MPU_PRB_EMACS_MAIN_XACTSTATPROFILER component. */
#define ALT_NOC_MPU_PRB_EMACS_MAIN_XACTSTATPROFILER_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_NOC_MPU_PRB_EMACS_MAIN_XACTSTATPROFILER_ADDR) + 0x80) - 1))


/*
 * Component Instance : i_noc_mpu_m0_cs_obs_at_main_AtbEndPoint
 * 
 * Instance i_noc_mpu_m0_cs_obs_at_main_AtbEndPoint of component ALT_NOC_MPU_CS_OBS_AT_ATBENDPT.
 * 
 * 
 */
/* The address of the ALT_NOC_MPU_CS_OBS_AT_ATBENDPT_COREID register for the ALT_NOC_MPU_CS_OBS_AT_ATBENDPT instance. */
#define ALT_NOC_MPU_CS_OBS_AT_ATBENDPT_COREID_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_CS_OBS_AT_ATBENDPT_ADDR) + ALT_NOC_MPU_CS_OBS_AT_ATBENDPT_COREID_OFST))
/* The address of the ALT_NOC_MPU_CS_OBS_AT_ATBENDPT_REVID register for the ALT_NOC_MPU_CS_OBS_AT_ATBENDPT instance. */
#define ALT_NOC_MPU_CS_OBS_AT_ATBENDPT_REVID_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_CS_OBS_AT_ATBENDPT_ADDR) + ALT_NOC_MPU_CS_OBS_AT_ATBENDPT_REVID_OFST))
/* The address of the ALT_NOC_MPU_CS_OBS_AT_ATBENDPT_ATBID register for the ALT_NOC_MPU_CS_OBS_AT_ATBENDPT instance. */
#define ALT_NOC_MPU_CS_OBS_AT_ATBENDPT_ATBID_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_CS_OBS_AT_ATBENDPT_ADDR) + ALT_NOC_MPU_CS_OBS_AT_ATBENDPT_ATBID_OFST))
/* The address of the ALT_NOC_MPU_CS_OBS_AT_ATBENDPT_ATBEN register for the ALT_NOC_MPU_CS_OBS_AT_ATBENDPT instance. */
#define ALT_NOC_MPU_CS_OBS_AT_ATBENDPT_ATBEN_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_CS_OBS_AT_ATBENDPT_ADDR) + ALT_NOC_MPU_CS_OBS_AT_ATBENDPT_ATBEN_OFST))
/* The address of the ALT_NOC_MPU_CS_OBS_AT_ATBENDPT_SYNCPERIOD register for the ALT_NOC_MPU_CS_OBS_AT_ATBENDPT instance. */
#define ALT_NOC_MPU_CS_OBS_AT_ATBENDPT_SYNCPERIOD_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_CS_OBS_AT_ATBENDPT_ADDR) + ALT_NOC_MPU_CS_OBS_AT_ATBENDPT_SYNCPERIOD_OFST))
/* The base address byte offset for the start of the ALT_NOC_MPU_CS_OBS_AT_ATBENDPT component. */
#define ALT_NOC_MPU_CS_OBS_AT_ATBENDPT_OFST        0xffd14900
/* The start address of the ALT_NOC_MPU_CS_OBS_AT_ATBENDPT component. */
#define ALT_NOC_MPU_CS_OBS_AT_ATBENDPT_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_NOC_MPU_CS_OBS_AT_ATBENDPT_OFST))
/* The lower bound address range of the ALT_NOC_MPU_CS_OBS_AT_ATBENDPT component. */
#define ALT_NOC_MPU_CS_OBS_AT_ATBENDPT_LB_ADDR     ALT_NOC_MPU_CS_OBS_AT_ATBENDPT_ADDR
/* The upper bound address range of the ALT_NOC_MPU_CS_OBS_AT_ATBENDPT component. */
#define ALT_NOC_MPU_CS_OBS_AT_ATBENDPT_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_NOC_MPU_CS_OBS_AT_ATBENDPT_ADDR) + 0x80) - 1))


/*
 * Component Instance : i_noc_mpu_m0_cs_obs_at_main_ErrorLogger_0
 * 
 * Instance i_noc_mpu_m0_cs_obs_at_main_ErrorLogger_0 of component ALT_NOC_MPU_CS_OBS_AT_ERRLOG_0.
 * 
 * 
 */
/* The address of the ALT_NOC_MPU_CS_OBS_AT_ERRLOG_0_COREID register for the ALT_NOC_MPU_CS_OBS_AT_ERRLOG_0 instance. */
#define ALT_NOC_MPU_CS_OBS_AT_ERRLOG_0_COREID_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_CS_OBS_AT_ERRLOG_0_ADDR) + ALT_NOC_MPU_CS_OBS_AT_ERRLOG_0_COREID_OFST))
/* The address of the ALT_NOC_MPU_CS_OBS_AT_ERRLOG_0_REVID register for the ALT_NOC_MPU_CS_OBS_AT_ERRLOG_0 instance. */
#define ALT_NOC_MPU_CS_OBS_AT_ERRLOG_0_REVID_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_CS_OBS_AT_ERRLOG_0_ADDR) + ALT_NOC_MPU_CS_OBS_AT_ERRLOG_0_REVID_OFST))
/* The address of the ALT_NOC_MPU_CS_OBS_AT_ERRLOG_0_FAULTEN register for the ALT_NOC_MPU_CS_OBS_AT_ERRLOG_0 instance. */
#define ALT_NOC_MPU_CS_OBS_AT_ERRLOG_0_FAULTEN_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_CS_OBS_AT_ERRLOG_0_ADDR) + ALT_NOC_MPU_CS_OBS_AT_ERRLOG_0_FAULTEN_OFST))
/* The address of the ALT_NOC_MPU_CS_OBS_AT_ERRLOG_0_ERRVLD register for the ALT_NOC_MPU_CS_OBS_AT_ERRLOG_0 instance. */
#define ALT_NOC_MPU_CS_OBS_AT_ERRLOG_0_ERRVLD_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_CS_OBS_AT_ERRLOG_0_ADDR) + ALT_NOC_MPU_CS_OBS_AT_ERRLOG_0_ERRVLD_OFST))
/* The address of the ALT_NOC_MPU_CS_OBS_AT_ERRLOG_0_ERRCLR register for the ALT_NOC_MPU_CS_OBS_AT_ERRLOG_0 instance. */
#define ALT_NOC_MPU_CS_OBS_AT_ERRLOG_0_ERRCLR_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_CS_OBS_AT_ERRLOG_0_ADDR) + ALT_NOC_MPU_CS_OBS_AT_ERRLOG_0_ERRCLR_OFST))
/* The address of the ALT_NOC_MPU_CS_OBS_AT_ERRLOG_0_ERRLOG0 register for the ALT_NOC_MPU_CS_OBS_AT_ERRLOG_0 instance. */
#define ALT_NOC_MPU_CS_OBS_AT_ERRLOG_0_ERRLOG0_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_CS_OBS_AT_ERRLOG_0_ADDR) + ALT_NOC_MPU_CS_OBS_AT_ERRLOG_0_ERRLOG0_OFST))
/* The address of the ALT_NOC_MPU_CS_OBS_AT_ERRLOG_0_ERRLOG1 register for the ALT_NOC_MPU_CS_OBS_AT_ERRLOG_0 instance. */
#define ALT_NOC_MPU_CS_OBS_AT_ERRLOG_0_ERRLOG1_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_CS_OBS_AT_ERRLOG_0_ADDR) + ALT_NOC_MPU_CS_OBS_AT_ERRLOG_0_ERRLOG1_OFST))
/* The address of the ALT_NOC_MPU_CS_OBS_AT_ERRLOG_0_ERRLOG3 register for the ALT_NOC_MPU_CS_OBS_AT_ERRLOG_0 instance. */
#define ALT_NOC_MPU_CS_OBS_AT_ERRLOG_0_ERRLOG3_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_CS_OBS_AT_ERRLOG_0_ADDR) + ALT_NOC_MPU_CS_OBS_AT_ERRLOG_0_ERRLOG3_OFST))
/* The address of the ALT_NOC_MPU_CS_OBS_AT_ERRLOG_0_ERRLOG5 register for the ALT_NOC_MPU_CS_OBS_AT_ERRLOG_0 instance. */
#define ALT_NOC_MPU_CS_OBS_AT_ERRLOG_0_ERRLOG5_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_CS_OBS_AT_ERRLOG_0_ADDR) + ALT_NOC_MPU_CS_OBS_AT_ERRLOG_0_ERRLOG5_OFST))
/* The address of the ALT_NOC_MPU_CS_OBS_AT_ERRLOG_0_ERRLOG7 register for the ALT_NOC_MPU_CS_OBS_AT_ERRLOG_0 instance. */
#define ALT_NOC_MPU_CS_OBS_AT_ERRLOG_0_ERRLOG7_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_CS_OBS_AT_ERRLOG_0_ADDR) + ALT_NOC_MPU_CS_OBS_AT_ERRLOG_0_ERRLOG7_OFST))
/* The base address byte offset for the start of the ALT_NOC_MPU_CS_OBS_AT_ERRLOG_0 component. */
#define ALT_NOC_MPU_CS_OBS_AT_ERRLOG_0_OFST        0xffd14980
/* The start address of the ALT_NOC_MPU_CS_OBS_AT_ERRLOG_0 component. */
#define ALT_NOC_MPU_CS_OBS_AT_ERRLOG_0_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_NOC_MPU_CS_OBS_AT_ERRLOG_0_OFST))
/* The lower bound address range of the ALT_NOC_MPU_CS_OBS_AT_ERRLOG_0 component. */
#define ALT_NOC_MPU_CS_OBS_AT_ERRLOG_0_LB_ADDR     ALT_NOC_MPU_CS_OBS_AT_ERRLOG_0_ADDR
/* The upper bound address range of the ALT_NOC_MPU_CS_OBS_AT_ERRLOG_0 component. */
#define ALT_NOC_MPU_CS_OBS_AT_ERRLOG_0_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_NOC_MPU_CS_OBS_AT_ERRLOG_0_ADDR) + 0x80) - 1))


/*
 * Component Instance : i_noc_mpu_m0_Probe_MPU_main_Probe
 * 
 * Instance i_noc_mpu_m0_Probe_MPU_main_Probe of component ALT_NOC_MPU_PRB_MPU_MAIN_PRB.
 * 
 * 
 */
/* The address of the ALT_NOC_MPU_PRB_MPU_MAIN_COREID register for the ALT_NOC_MPU_PRB_MPU_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_MPU_MAIN_COREID_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_MPU_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_MPU_MAIN_COREID_OFST))
/* The address of the ALT_NOC_MPU_PRB_MPU_MAIN_REVID register for the ALT_NOC_MPU_PRB_MPU_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_MPU_MAIN_REVID_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_MPU_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_MPU_MAIN_REVID_OFST))
/* The address of the ALT_NOC_MPU_PRB_MPU_MAIN_MAINCTL register for the ALT_NOC_MPU_PRB_MPU_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_MPU_MAIN_MAINCTL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_MPU_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_MPU_MAIN_MAINCTL_OFST))
/* The address of the ALT_NOC_MPU_PRB_MPU_MAIN_CFGCTL register for the ALT_NOC_MPU_PRB_MPU_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_MPU_MAIN_CFGCTL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_MPU_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_MPU_MAIN_CFGCTL_OFST))
/* The address of the ALT_NOC_MPU_PRB_MPU_MAIN_FLTLUT register for the ALT_NOC_MPU_PRB_MPU_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_MPU_MAIN_FLTLUT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_MPU_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_MPU_MAIN_FLTLUT_OFST))
/* The address of the ALT_NOC_MPU_PRB_MPU_MAIN_TRACEALARMEN register for the ALT_NOC_MPU_PRB_MPU_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_MPU_MAIN_TRACEALARMEN_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_MPU_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_MPU_MAIN_TRACEALARMEN_OFST))
/* The address of the ALT_NOC_MPU_PRB_MPU_MAIN_TRACEALARMSTAT register for the ALT_NOC_MPU_PRB_MPU_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_MPU_MAIN_TRACEALARMSTAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_MPU_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_MPU_MAIN_TRACEALARMSTAT_OFST))
/* The address of the ALT_NOC_MPU_PRB_MPU_MAIN_TRACEALARMCLR register for the ALT_NOC_MPU_PRB_MPU_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_MPU_MAIN_TRACEALARMCLR_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_MPU_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_MPU_MAIN_TRACEALARMCLR_OFST))
/* The address of the ALT_NOC_MPU_PRB_MPU_MAIN_STATPERIOD register for the ALT_NOC_MPU_PRB_MPU_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_MPU_MAIN_STATPERIOD_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_MPU_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_MPU_MAIN_STATPERIOD_OFST))
/* The address of the ALT_NOC_MPU_PRB_MPU_MAIN_STATGO register for the ALT_NOC_MPU_PRB_MPU_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_MPU_MAIN_STATGO_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_MPU_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_MPU_MAIN_STATGO_OFST))
/* The address of the ALT_NOC_MPU_PRB_MPU_MAIN_STATALARMMIN register for the ALT_NOC_MPU_PRB_MPU_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_MPU_MAIN_STATALARMMIN_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_MPU_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_MPU_MAIN_STATALARMMIN_OFST))
/* The address of the ALT_NOC_MPU_PRB_MPU_MAIN_STATALARMMAX register for the ALT_NOC_MPU_PRB_MPU_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_MPU_MAIN_STATALARMMAX_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_MPU_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_MPU_MAIN_STATALARMMAX_OFST))
/* The address of the ALT_NOC_MPU_PRB_MPU_MAIN_STATALARMSTAT register for the ALT_NOC_MPU_PRB_MPU_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_MPU_MAIN_STATALARMSTAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_MPU_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_MPU_MAIN_STATALARMSTAT_OFST))
/* The address of the ALT_NOC_MPU_PRB_MPU_MAIN_STATALARMCLR register for the ALT_NOC_MPU_PRB_MPU_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_MPU_MAIN_STATALARMCLR_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_MPU_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_MPU_MAIN_STATALARMCLR_OFST))
/* The address of the ALT_NOC_MPU_PRB_MPU_MAIN_STATALARMEN register for the ALT_NOC_MPU_PRB_MPU_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_MPU_MAIN_STATALARMEN_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_MPU_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_MPU_MAIN_STATALARMEN_OFST))
/* The address of the ALT_NOC_MPU_PRB_MPU_MAIN_FLTS_0_ROUTEIDBASE register for the ALT_NOC_MPU_PRB_MPU_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_MPU_MAIN_FLTS_0_ROUTEIDBASE_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_MPU_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_MPU_MAIN_FLTS_0_ROUTEIDBASE_OFST))
/* The address of the ALT_NOC_MPU_PRB_MPU_MAIN_FLTS_0_ROUTEIDMSK register for the ALT_NOC_MPU_PRB_MPU_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_MPU_MAIN_FLTS_0_ROUTEIDMSK_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_MPU_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_MPU_MAIN_FLTS_0_ROUTEIDMSK_OFST))
/* The address of the ALT_NOC_MPU_PRB_MPU_MAIN_FLTS_0_ADDRBASE_LOW register for the ALT_NOC_MPU_PRB_MPU_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_MPU_MAIN_FLTS_0_ADDRBASE_LOW_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_MPU_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_MPU_MAIN_FLTS_0_ADDRBASE_LOW_OFST))
/* The address of the ALT_NOC_MPU_PRB_MPU_MAIN_FLTS_0_WINDOWSIZE register for the ALT_NOC_MPU_PRB_MPU_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_MPU_MAIN_FLTS_0_WINDOWSIZE_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_MPU_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_MPU_MAIN_FLTS_0_WINDOWSIZE_OFST))
/* The address of the ALT_NOC_MPU_PRB_MPU_MAIN_FLTS_0_SECURITYBASE register for the ALT_NOC_MPU_PRB_MPU_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_MPU_MAIN_FLTS_0_SECURITYBASE_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_MPU_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_MPU_MAIN_FLTS_0_SECURITYBASE_OFST))
/* The address of the ALT_NOC_MPU_PRB_MPU_MAIN_FLTS_0_SECURITYMSK register for the ALT_NOC_MPU_PRB_MPU_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_MPU_MAIN_FLTS_0_SECURITYMSK_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_MPU_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_MPU_MAIN_FLTS_0_SECURITYMSK_OFST))
/* The address of the ALT_NOC_MPU_PRB_MPU_MAIN_FLTS_0_OPCODE register for the ALT_NOC_MPU_PRB_MPU_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_MPU_MAIN_FLTS_0_OPCODE_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_MPU_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_MPU_MAIN_FLTS_0_OPCODE_OFST))
/* The address of the ALT_NOC_MPU_PRB_MPU_MAIN_FLTS_0_STAT register for the ALT_NOC_MPU_PRB_MPU_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_MPU_MAIN_FLTS_0_STAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_MPU_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_MPU_MAIN_FLTS_0_STAT_OFST))
/* The address of the ALT_NOC_MPU_PRB_MPU_MAIN_FLTS_0_LEN register for the ALT_NOC_MPU_PRB_MPU_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_MPU_MAIN_FLTS_0_LEN_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_MPU_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_MPU_MAIN_FLTS_0_LEN_OFST))
/* The address of the ALT_NOC_MPU_PRB_MPU_MAIN_FLTS_0_URGENCY register for the ALT_NOC_MPU_PRB_MPU_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_MPU_MAIN_FLTS_0_URGENCY_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_MPU_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_MPU_MAIN_FLTS_0_URGENCY_OFST))
/* The address of the ALT_NOC_MPU_PRB_MPU_MAIN_CNTRS_0_SRC register for the ALT_NOC_MPU_PRB_MPU_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_MPU_MAIN_CNTRS_0_SRC_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_MPU_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_MPU_MAIN_CNTRS_0_SRC_OFST))
/* The address of the ALT_NOC_MPU_PRB_MPU_MAIN_CNTRS_0_ALARMMOD register for the ALT_NOC_MPU_PRB_MPU_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_MPU_MAIN_CNTRS_0_ALARMMOD_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_MPU_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_MPU_MAIN_CNTRS_0_ALARMMOD_OFST))
/* The address of the ALT_NOC_MPU_PRB_MPU_MAIN_CNTRS_0_VAL register for the ALT_NOC_MPU_PRB_MPU_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_MPU_MAIN_CNTRS_0_VAL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_MPU_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_MPU_MAIN_CNTRS_0_VAL_OFST))
/* The address of the ALT_NOC_MPU_PRB_MPU_MAIN_CNTRS_1_SRC register for the ALT_NOC_MPU_PRB_MPU_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_MPU_MAIN_CNTRS_1_SRC_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_MPU_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_MPU_MAIN_CNTRS_1_SRC_OFST))
/* The address of the ALT_NOC_MPU_PRB_MPU_MAIN_CNTRS_1_ALARMMOD register for the ALT_NOC_MPU_PRB_MPU_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_MPU_MAIN_CNTRS_1_ALARMMOD_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_MPU_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_MPU_MAIN_CNTRS_1_ALARMMOD_OFST))
/* The address of the ALT_NOC_MPU_PRB_MPU_MAIN_CNTRS_1_VAL register for the ALT_NOC_MPU_PRB_MPU_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_MPU_MAIN_CNTRS_1_VAL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_MPU_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_MPU_MAIN_CNTRS_1_VAL_OFST))
/* The address of the ALT_NOC_MPU_PRB_MPU_MAIN_CNTRS_2_SRC register for the ALT_NOC_MPU_PRB_MPU_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_MPU_MAIN_CNTRS_2_SRC_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_MPU_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_MPU_MAIN_CNTRS_2_SRC_OFST))
/* The address of the ALT_NOC_MPU_PRB_MPU_MAIN_CNTRS_2_ALARMMOD register for the ALT_NOC_MPU_PRB_MPU_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_MPU_MAIN_CNTRS_2_ALARMMOD_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_MPU_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_MPU_MAIN_CNTRS_2_ALARMMOD_OFST))
/* The address of the ALT_NOC_MPU_PRB_MPU_MAIN_CNTRS_2_VAL register for the ALT_NOC_MPU_PRB_MPU_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_MPU_MAIN_CNTRS_2_VAL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_MPU_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_MPU_MAIN_CNTRS_2_VAL_OFST))
/* The address of the ALT_NOC_MPU_PRB_MPU_MAIN_CNTRS_3_SRC register for the ALT_NOC_MPU_PRB_MPU_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_MPU_MAIN_CNTRS_3_SRC_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_MPU_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_MPU_MAIN_CNTRS_3_SRC_OFST))
/* The address of the ALT_NOC_MPU_PRB_MPU_MAIN_CNTRS_3_ALARMMOD register for the ALT_NOC_MPU_PRB_MPU_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_MPU_MAIN_CNTRS_3_ALARMMOD_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_MPU_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_MPU_MAIN_CNTRS_3_ALARMMOD_OFST))
/* The address of the ALT_NOC_MPU_PRB_MPU_MAIN_CNTRS_3_VAL register for the ALT_NOC_MPU_PRB_MPU_MAIN_PRB instance. */
#define ALT_NOC_MPU_PRB_MPU_MAIN_CNTRS_3_VAL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_PRB_MPU_MAIN_PRB_ADDR) + ALT_NOC_MPU_PRB_MPU_MAIN_CNTRS_3_VAL_OFST))
/* The base address byte offset for the start of the ALT_NOC_MPU_PRB_MPU_MAIN_PRB component. */
#define ALT_NOC_MPU_PRB_MPU_MAIN_PRB_OFST        0xffd15000
/* The start address of the ALT_NOC_MPU_PRB_MPU_MAIN_PRB component. */
#define ALT_NOC_MPU_PRB_MPU_MAIN_PRB_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_NOC_MPU_PRB_MPU_MAIN_PRB_OFST))
/* The lower bound address range of the ALT_NOC_MPU_PRB_MPU_MAIN_PRB component. */
#define ALT_NOC_MPU_PRB_MPU_MAIN_PRB_LB_ADDR     ALT_NOC_MPU_PRB_MPU_MAIN_PRB_ADDR
/* The upper bound address range of the ALT_NOC_MPU_PRB_MPU_MAIN_PRB component. */
#define ALT_NOC_MPU_PRB_MPU_MAIN_PRB_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_NOC_MPU_PRB_MPU_MAIN_PRB_ADDR) + 0x400) - 1))


/*
 * Component Instance : i_noc_mpu_m0_mpu_m0_I_main_QosGenerator
 * 
 * Instance i_noc_mpu_m0_mpu_m0_I_main_QosGenerator of component ALT_NOC_MPU_M0_MAIN_QOS.
 * 
 * 
 */
/* The address of the ALT_NOC_MPU_MAIN_QOS_COREID register for the ALT_NOC_MPU_M0_MAIN_QOS instance. */
#define ALT_NOC_MPU_M0_MAIN_QOS_COREID_ADDR  ALT_NOC_MPU_MAIN_QOS_COREID_ADDR(ALT_NOC_MPU_M0_MAIN_QOS_ADDR)
/* The address of the ALT_NOC_MPU_MAIN_QOS_REVID register for the ALT_NOC_MPU_M0_MAIN_QOS instance. */
#define ALT_NOC_MPU_M0_MAIN_QOS_REVID_ADDR  ALT_NOC_MPU_MAIN_QOS_REVID_ADDR(ALT_NOC_MPU_M0_MAIN_QOS_ADDR)
/* The address of the ALT_NOC_MPU_MAIN_QOS_PRI register for the ALT_NOC_MPU_M0_MAIN_QOS instance. */
#define ALT_NOC_MPU_M0_MAIN_QOS_PRI_ADDR  ALT_NOC_MPU_MAIN_QOS_PRI_ADDR(ALT_NOC_MPU_M0_MAIN_QOS_ADDR)
/* The address of the ALT_NOC_MPU_MAIN_QOS_MOD register for the ALT_NOC_MPU_M0_MAIN_QOS instance. */
#define ALT_NOC_MPU_M0_MAIN_QOS_MOD_ADDR  ALT_NOC_MPU_MAIN_QOS_MOD_ADDR(ALT_NOC_MPU_M0_MAIN_QOS_ADDR)
/* The address of the ALT_NOC_MPU_MAIN_QOS_BWDTH register for the ALT_NOC_MPU_M0_MAIN_QOS instance. */
#define ALT_NOC_MPU_M0_MAIN_QOS_BWDTH_ADDR  ALT_NOC_MPU_MAIN_QOS_BWDTH_ADDR(ALT_NOC_MPU_M0_MAIN_QOS_ADDR)
/* The address of the ALT_NOC_MPU_MAIN_QOS_SAT register for the ALT_NOC_MPU_M0_MAIN_QOS instance. */
#define ALT_NOC_MPU_M0_MAIN_QOS_SAT_ADDR  ALT_NOC_MPU_MAIN_QOS_SAT_ADDR(ALT_NOC_MPU_M0_MAIN_QOS_ADDR)
/* The address of the ALT_NOC_MPU_MAIN_QOS_EXTCTL register for the ALT_NOC_MPU_M0_MAIN_QOS instance. */
#define ALT_NOC_MPU_M0_MAIN_QOS_EXTCTL_ADDR  ALT_NOC_MPU_MAIN_QOS_EXTCTL_ADDR(ALT_NOC_MPU_M0_MAIN_QOS_ADDR)
/* The base address byte offset for the start of the ALT_NOC_MPU_M0_MAIN_QOS component. */
#define ALT_NOC_MPU_M0_MAIN_QOS_OFST        0xffd16000
/* The start address of the ALT_NOC_MPU_M0_MAIN_QOS component. */
#define ALT_NOC_MPU_M0_MAIN_QOS_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_NOC_MPU_M0_MAIN_QOS_OFST))
/* The lower bound address range of the ALT_NOC_MPU_M0_MAIN_QOS component. */
#define ALT_NOC_MPU_M0_MAIN_QOS_LB_ADDR     ALT_NOC_MPU_M0_MAIN_QOS_ADDR
/* The upper bound address range of the ALT_NOC_MPU_M0_MAIN_QOS component. */
#define ALT_NOC_MPU_M0_MAIN_QOS_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_NOC_MPU_M0_MAIN_QOS_ADDR) + 0x80) - 1))


/*
 * Component Instance : i_noc_mpu_m0_mpu_m1_I_main_QosGenerator
 * 
 * Instance i_noc_mpu_m0_mpu_m1_I_main_QosGenerator of component ALT_NOC_MPU_M1_MAIN_QOS.
 * 
 * 
 */
/* The address of the ALT_NOC_MPU_M1_MAIN_QOS_COREID register for the ALT_NOC_MPU_M1_MAIN_QOS instance. */
#define ALT_NOC_MPU_M1_MAIN_QOS_COREID_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_M1_MAIN_QOS_ADDR) + ALT_NOC_MPU_M1_MAIN_QOS_COREID_OFST))
/* The address of the ALT_NOC_MPU_M1_MAIN_QOS_REVID register for the ALT_NOC_MPU_M1_MAIN_QOS instance. */
#define ALT_NOC_MPU_M1_MAIN_QOS_REVID_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_M1_MAIN_QOS_ADDR) + ALT_NOC_MPU_M1_MAIN_QOS_REVID_OFST))
/* The address of the ALT_NOC_MPU_M1_MAIN_QOS_PRI register for the ALT_NOC_MPU_M1_MAIN_QOS instance. */
#define ALT_NOC_MPU_M1_MAIN_QOS_PRI_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_M1_MAIN_QOS_ADDR) + ALT_NOC_MPU_M1_MAIN_QOS_PRI_OFST))
/* The address of the ALT_NOC_MPU_M1_MAIN_QOS_MOD register for the ALT_NOC_MPU_M1_MAIN_QOS instance. */
#define ALT_NOC_MPU_M1_MAIN_QOS_MOD_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_M1_MAIN_QOS_ADDR) + ALT_NOC_MPU_M1_MAIN_QOS_MOD_OFST))
/* The address of the ALT_NOC_MPU_M1_MAIN_QOS_BWDTH register for the ALT_NOC_MPU_M1_MAIN_QOS instance. */
#define ALT_NOC_MPU_M1_MAIN_QOS_BWDTH_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_M1_MAIN_QOS_ADDR) + ALT_NOC_MPU_M1_MAIN_QOS_BWDTH_OFST))
/* The address of the ALT_NOC_MPU_M1_MAIN_QOS_SAT register for the ALT_NOC_MPU_M1_MAIN_QOS instance. */
#define ALT_NOC_MPU_M1_MAIN_QOS_SAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_M1_MAIN_QOS_ADDR) + ALT_NOC_MPU_M1_MAIN_QOS_SAT_OFST))
/* The address of the ALT_NOC_MPU_M1_MAIN_QOS_EXTCTL register for the ALT_NOC_MPU_M1_MAIN_QOS instance. */
#define ALT_NOC_MPU_M1_MAIN_QOS_EXTCTL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_M1_MAIN_QOS_ADDR) + ALT_NOC_MPU_M1_MAIN_QOS_EXTCTL_OFST))
/* The base address byte offset for the start of the ALT_NOC_MPU_M1_MAIN_QOS component. */
#define ALT_NOC_MPU_M1_MAIN_QOS_OFST        0xffd16080
/* The start address of the ALT_NOC_MPU_M1_MAIN_QOS component. */
#define ALT_NOC_MPU_M1_MAIN_QOS_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_NOC_MPU_M1_MAIN_QOS_OFST))
/* The lower bound address range of the ALT_NOC_MPU_M1_MAIN_QOS component. */
#define ALT_NOC_MPU_M1_MAIN_QOS_LB_ADDR     ALT_NOC_MPU_M1_MAIN_QOS_ADDR
/* The upper bound address range of the ALT_NOC_MPU_M1_MAIN_QOS component. */
#define ALT_NOC_MPU_M1_MAIN_QOS_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_NOC_MPU_M1_MAIN_QOS_ADDR) + 0x80) - 1))


/*
 * Component Instance : i_noc_mpu_m0_fpga2soc_axi32_I_main_QosGenerator
 * 
 * Instance i_noc_mpu_m0_fpga2soc_axi32_I_main_QosGenerator of component ALT_NOC_MPU_F2H_AXI32_QOS.
 * 
 * 
 */
/* The address of the ALT_NOC_MPU_F2H_AXI32_QOS_COREID register for the ALT_NOC_MPU_F2H_AXI32_QOS instance. */
#define ALT_NOC_MPU_F2H_AXI32_QOS_COREID_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_F2H_AXI32_QOS_ADDR) + ALT_NOC_MPU_F2H_AXI32_QOS_COREID_OFST))
/* The address of the ALT_NOC_MPU_F2H_AXI32_QOS_REVID register for the ALT_NOC_MPU_F2H_AXI32_QOS instance. */
#define ALT_NOC_MPU_F2H_AXI32_QOS_REVID_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_F2H_AXI32_QOS_ADDR) + ALT_NOC_MPU_F2H_AXI32_QOS_REVID_OFST))
/* The address of the ALT_NOC_MPU_F2H_AXI32_QOS_PRI register for the ALT_NOC_MPU_F2H_AXI32_QOS instance. */
#define ALT_NOC_MPU_F2H_AXI32_QOS_PRI_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_F2H_AXI32_QOS_ADDR) + ALT_NOC_MPU_F2H_AXI32_QOS_PRI_OFST))
/* The address of the ALT_NOC_MPU_F2H_AXI32_QOS_MOD register for the ALT_NOC_MPU_F2H_AXI32_QOS instance. */
#define ALT_NOC_MPU_F2H_AXI32_QOS_MOD_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_F2H_AXI32_QOS_ADDR) + ALT_NOC_MPU_F2H_AXI32_QOS_MOD_OFST))
/* The address of the ALT_NOC_MPU_F2H_AXI32_QOS_BWDTH register for the ALT_NOC_MPU_F2H_AXI32_QOS instance. */
#define ALT_NOC_MPU_F2H_AXI32_QOS_BWDTH_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_F2H_AXI32_QOS_ADDR) + ALT_NOC_MPU_F2H_AXI32_QOS_BWDTH_OFST))
/* The address of the ALT_NOC_MPU_F2H_AXI32_QOS_SAT register for the ALT_NOC_MPU_F2H_AXI32_QOS instance. */
#define ALT_NOC_MPU_F2H_AXI32_QOS_SAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_F2H_AXI32_QOS_ADDR) + ALT_NOC_MPU_F2H_AXI32_QOS_SAT_OFST))
/* The address of the ALT_NOC_MPU_F2H_AXI32_QOS_EXTCTL register for the ALT_NOC_MPU_F2H_AXI32_QOS instance. */
#define ALT_NOC_MPU_F2H_AXI32_QOS_EXTCTL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_F2H_AXI32_QOS_ADDR) + ALT_NOC_MPU_F2H_AXI32_QOS_EXTCTL_OFST))
/* The base address byte offset for the start of the ALT_NOC_MPU_F2H_AXI32_QOS component. */
#define ALT_NOC_MPU_F2H_AXI32_QOS_OFST        0xffd16100
/* The start address of the ALT_NOC_MPU_F2H_AXI32_QOS component. */
#define ALT_NOC_MPU_F2H_AXI32_QOS_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_NOC_MPU_F2H_AXI32_QOS_OFST))
/* The lower bound address range of the ALT_NOC_MPU_F2H_AXI32_QOS component. */
#define ALT_NOC_MPU_F2H_AXI32_QOS_LB_ADDR     ALT_NOC_MPU_F2H_AXI32_QOS_ADDR
/* The upper bound address range of the ALT_NOC_MPU_F2H_AXI32_QOS component. */
#define ALT_NOC_MPU_F2H_AXI32_QOS_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_NOC_MPU_F2H_AXI32_QOS_ADDR) + 0x80) - 1))


/*
 * Component Instance : i_noc_mpu_m0_fpga2soc_axi64_I_main_QosGenerator
 * 
 * Instance i_noc_mpu_m0_fpga2soc_axi64_I_main_QosGenerator of component ALT_NOC_MPU_F2H_AXI64_QOS.
 * 
 * 
 */
/* The address of the ALT_NOC_MPU_F2H_AXI64_QOS_COREID register for the ALT_NOC_MPU_F2H_AXI64_QOS instance. */
#define ALT_NOC_MPU_F2H_AXI64_QOS_COREID_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_F2H_AXI64_QOS_ADDR) + ALT_NOC_MPU_F2H_AXI64_QOS_COREID_OFST))
/* The address of the ALT_NOC_MPU_F2H_AXI64_QOS_REVID register for the ALT_NOC_MPU_F2H_AXI64_QOS instance. */
#define ALT_NOC_MPU_F2H_AXI64_QOS_REVID_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_F2H_AXI64_QOS_ADDR) + ALT_NOC_MPU_F2H_AXI64_QOS_REVID_OFST))
/* The address of the ALT_NOC_MPU_F2H_AXI64_QOS_PRI register for the ALT_NOC_MPU_F2H_AXI64_QOS instance. */
#define ALT_NOC_MPU_F2H_AXI64_QOS_PRI_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_F2H_AXI64_QOS_ADDR) + ALT_NOC_MPU_F2H_AXI64_QOS_PRI_OFST))
/* The address of the ALT_NOC_MPU_F2H_AXI64_QOS_MOD register for the ALT_NOC_MPU_F2H_AXI64_QOS instance. */
#define ALT_NOC_MPU_F2H_AXI64_QOS_MOD_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_F2H_AXI64_QOS_ADDR) + ALT_NOC_MPU_F2H_AXI64_QOS_MOD_OFST))
/* The address of the ALT_NOC_MPU_F2H_AXI64_QOS_BWDTH register for the ALT_NOC_MPU_F2H_AXI64_QOS instance. */
#define ALT_NOC_MPU_F2H_AXI64_QOS_BWDTH_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_F2H_AXI64_QOS_ADDR) + ALT_NOC_MPU_F2H_AXI64_QOS_BWDTH_OFST))
/* The address of the ALT_NOC_MPU_F2H_AXI64_QOS_SAT register for the ALT_NOC_MPU_F2H_AXI64_QOS instance. */
#define ALT_NOC_MPU_F2H_AXI64_QOS_SAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_F2H_AXI64_QOS_ADDR) + ALT_NOC_MPU_F2H_AXI64_QOS_SAT_OFST))
/* The address of the ALT_NOC_MPU_F2H_AXI64_QOS_EXTCTL register for the ALT_NOC_MPU_F2H_AXI64_QOS instance. */
#define ALT_NOC_MPU_F2H_AXI64_QOS_EXTCTL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_F2H_AXI64_QOS_ADDR) + ALT_NOC_MPU_F2H_AXI64_QOS_EXTCTL_OFST))
/* The base address byte offset for the start of the ALT_NOC_MPU_F2H_AXI64_QOS component. */
#define ALT_NOC_MPU_F2H_AXI64_QOS_OFST        0xffd16180
/* The start address of the ALT_NOC_MPU_F2H_AXI64_QOS component. */
#define ALT_NOC_MPU_F2H_AXI64_QOS_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_NOC_MPU_F2H_AXI64_QOS_OFST))
/* The lower bound address range of the ALT_NOC_MPU_F2H_AXI64_QOS component. */
#define ALT_NOC_MPU_F2H_AXI64_QOS_LB_ADDR     ALT_NOC_MPU_F2H_AXI64_QOS_ADDR
/* The upper bound address range of the ALT_NOC_MPU_F2H_AXI64_QOS component. */
#define ALT_NOC_MPU_F2H_AXI64_QOS_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_NOC_MPU_F2H_AXI64_QOS_ADDR) + 0x80) - 1))


/*
 * Component Instance : i_noc_mpu_m0_fpga2soc_axi128_I_main_QosGenerator
 * 
 * Instance i_noc_mpu_m0_fpga2soc_axi128_I_main_QosGenerator of component ALT_NOC_MPU_F2H_AXI128_QOS.
 * 
 * 
 */
/* The address of the ALT_NOC_MPU_F2H_AXI128_QOS_COREID register for the ALT_NOC_MPU_F2H_AXI128_QOS instance. */
#define ALT_NOC_MPU_F2H_AXI128_QOS_COREID_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_F2H_AXI128_QOS_ADDR) + ALT_NOC_MPU_F2H_AXI128_QOS_COREID_OFST))
/* The address of the ALT_NOC_MPU_F2H_AXI128_QOS_REVID register for the ALT_NOC_MPU_F2H_AXI128_QOS instance. */
#define ALT_NOC_MPU_F2H_AXI128_QOS_REVID_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_F2H_AXI128_QOS_ADDR) + ALT_NOC_MPU_F2H_AXI128_QOS_REVID_OFST))
/* The address of the ALT_NOC_MPU_F2H_AXI128_QOS_PRI register for the ALT_NOC_MPU_F2H_AXI128_QOS instance. */
#define ALT_NOC_MPU_F2H_AXI128_QOS_PRI_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_F2H_AXI128_QOS_ADDR) + ALT_NOC_MPU_F2H_AXI128_QOS_PRI_OFST))
/* The address of the ALT_NOC_MPU_F2H_AXI128_QOS_MOD register for the ALT_NOC_MPU_F2H_AXI128_QOS instance. */
#define ALT_NOC_MPU_F2H_AXI128_QOS_MOD_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_F2H_AXI128_QOS_ADDR) + ALT_NOC_MPU_F2H_AXI128_QOS_MOD_OFST))
/* The address of the ALT_NOC_MPU_F2H_AXI128_QOS_BWDTH register for the ALT_NOC_MPU_F2H_AXI128_QOS instance. */
#define ALT_NOC_MPU_F2H_AXI128_QOS_BWDTH_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_F2H_AXI128_QOS_ADDR) + ALT_NOC_MPU_F2H_AXI128_QOS_BWDTH_OFST))
/* The address of the ALT_NOC_MPU_F2H_AXI128_QOS_SAT register for the ALT_NOC_MPU_F2H_AXI128_QOS instance. */
#define ALT_NOC_MPU_F2H_AXI128_QOS_SAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_F2H_AXI128_QOS_ADDR) + ALT_NOC_MPU_F2H_AXI128_QOS_SAT_OFST))
/* The address of the ALT_NOC_MPU_F2H_AXI128_QOS_EXTCTL register for the ALT_NOC_MPU_F2H_AXI128_QOS instance. */
#define ALT_NOC_MPU_F2H_AXI128_QOS_EXTCTL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_F2H_AXI128_QOS_ADDR) + ALT_NOC_MPU_F2H_AXI128_QOS_EXTCTL_OFST))
/* The base address byte offset for the start of the ALT_NOC_MPU_F2H_AXI128_QOS component. */
#define ALT_NOC_MPU_F2H_AXI128_QOS_OFST        0xffd16200
/* The start address of the ALT_NOC_MPU_F2H_AXI128_QOS component. */
#define ALT_NOC_MPU_F2H_AXI128_QOS_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_NOC_MPU_F2H_AXI128_QOS_OFST))
/* The lower bound address range of the ALT_NOC_MPU_F2H_AXI128_QOS component. */
#define ALT_NOC_MPU_F2H_AXI128_QOS_LB_ADDR     ALT_NOC_MPU_F2H_AXI128_QOS_ADDR
/* The upper bound address range of the ALT_NOC_MPU_F2H_AXI128_QOS component. */
#define ALT_NOC_MPU_F2H_AXI128_QOS_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_NOC_MPU_F2H_AXI128_QOS_ADDR) + 0x80) - 1))


/*
 * Component Instance : i_noc_mpu_m0_dma_m0_I_main_QosGenerator
 * 
 * Instance i_noc_mpu_m0_dma_m0_I_main_QosGenerator of component ALT_NOC_MPU_DMA_M0_QOS.
 * 
 * 
 */
/* The address of the ALT_NOC_MPU_DMA_M0_QOS_COREID register for the ALT_NOC_MPU_DMA_M0_QOS instance. */
#define ALT_NOC_MPU_DMA_M0_QOS_COREID_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_DMA_M0_QOS_ADDR) + ALT_NOC_MPU_DMA_M0_QOS_COREID_OFST))
/* The address of the ALT_NOC_MPU_DMA_M0_QOS_REVID register for the ALT_NOC_MPU_DMA_M0_QOS instance. */
#define ALT_NOC_MPU_DMA_M0_QOS_REVID_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_DMA_M0_QOS_ADDR) + ALT_NOC_MPU_DMA_M0_QOS_REVID_OFST))
/* The address of the ALT_NOC_MPU_DMA_M0_QOS_PRI register for the ALT_NOC_MPU_DMA_M0_QOS instance. */
#define ALT_NOC_MPU_DMA_M0_QOS_PRI_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_DMA_M0_QOS_ADDR) + ALT_NOC_MPU_DMA_M0_QOS_PRI_OFST))
/* The address of the ALT_NOC_MPU_DMA_M0_QOS_MOD register for the ALT_NOC_MPU_DMA_M0_QOS instance. */
#define ALT_NOC_MPU_DMA_M0_QOS_MOD_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_DMA_M0_QOS_ADDR) + ALT_NOC_MPU_DMA_M0_QOS_MOD_OFST))
/* The address of the ALT_NOC_MPU_DMA_M0_QOS_BWDTH register for the ALT_NOC_MPU_DMA_M0_QOS instance. */
#define ALT_NOC_MPU_DMA_M0_QOS_BWDTH_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_DMA_M0_QOS_ADDR) + ALT_NOC_MPU_DMA_M0_QOS_BWDTH_OFST))
/* The address of the ALT_NOC_MPU_DMA_M0_QOS_SAT register for the ALT_NOC_MPU_DMA_M0_QOS instance. */
#define ALT_NOC_MPU_DMA_M0_QOS_SAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_DMA_M0_QOS_ADDR) + ALT_NOC_MPU_DMA_M0_QOS_SAT_OFST))
/* The address of the ALT_NOC_MPU_DMA_M0_QOS_EXTCTL register for the ALT_NOC_MPU_DMA_M0_QOS instance. */
#define ALT_NOC_MPU_DMA_M0_QOS_EXTCTL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_DMA_M0_QOS_ADDR) + ALT_NOC_MPU_DMA_M0_QOS_EXTCTL_OFST))
/* The base address byte offset for the start of the ALT_NOC_MPU_DMA_M0_QOS component. */
#define ALT_NOC_MPU_DMA_M0_QOS_OFST        0xffd16280
/* The start address of the ALT_NOC_MPU_DMA_M0_QOS component. */
#define ALT_NOC_MPU_DMA_M0_QOS_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_NOC_MPU_DMA_M0_QOS_OFST))
/* The lower bound address range of the ALT_NOC_MPU_DMA_M0_QOS component. */
#define ALT_NOC_MPU_DMA_M0_QOS_LB_ADDR     ALT_NOC_MPU_DMA_M0_QOS_ADDR
/* The upper bound address range of the ALT_NOC_MPU_DMA_M0_QOS component. */
#define ALT_NOC_MPU_DMA_M0_QOS_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_NOC_MPU_DMA_M0_QOS_ADDR) + 0x80) - 1))


/*
 * Component Instance : i_noc_mpu_m0_emac0_m_I_main_QosGenerator
 * 
 * Instance i_noc_mpu_m0_emac0_m_I_main_QosGenerator of component ALT_NOC_MPU_EMAC0_M_QOS.
 * 
 * 
 */
/* The address of the ALT_NOC_MPU_EMAC0_M_QOS_COREID register for the ALT_NOC_MPU_EMAC0_M_QOS instance. */
#define ALT_NOC_MPU_EMAC0_M_QOS_COREID_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_EMAC0_M_QOS_ADDR) + ALT_NOC_MPU_EMAC0_M_QOS_COREID_OFST))
/* The address of the ALT_NOC_MPU_EMAC0_M_QOS_REVID register for the ALT_NOC_MPU_EMAC0_M_QOS instance. */
#define ALT_NOC_MPU_EMAC0_M_QOS_REVID_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_EMAC0_M_QOS_ADDR) + ALT_NOC_MPU_EMAC0_M_QOS_REVID_OFST))
/* The address of the ALT_NOC_MPU_EMAC0_M_QOS_PRI register for the ALT_NOC_MPU_EMAC0_M_QOS instance. */
#define ALT_NOC_MPU_EMAC0_M_QOS_PRI_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_EMAC0_M_QOS_ADDR) + ALT_NOC_MPU_EMAC0_M_QOS_PRI_OFST))
/* The address of the ALT_NOC_MPU_EMAC0_M_QOS_MOD register for the ALT_NOC_MPU_EMAC0_M_QOS instance. */
#define ALT_NOC_MPU_EMAC0_M_QOS_MOD_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_EMAC0_M_QOS_ADDR) + ALT_NOC_MPU_EMAC0_M_QOS_MOD_OFST))
/* The address of the ALT_NOC_MPU_EMAC0_M_QOS_BWDTH register for the ALT_NOC_MPU_EMAC0_M_QOS instance. */
#define ALT_NOC_MPU_EMAC0_M_QOS_BWDTH_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_EMAC0_M_QOS_ADDR) + ALT_NOC_MPU_EMAC0_M_QOS_BWDTH_OFST))
/* The address of the ALT_NOC_MPU_EMAC0_M_QOS_SAT register for the ALT_NOC_MPU_EMAC0_M_QOS instance. */
#define ALT_NOC_MPU_EMAC0_M_QOS_SAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_EMAC0_M_QOS_ADDR) + ALT_NOC_MPU_EMAC0_M_QOS_SAT_OFST))
/* The address of the ALT_NOC_MPU_EMAC0_M_QOS_EXTCTL register for the ALT_NOC_MPU_EMAC0_M_QOS instance. */
#define ALT_NOC_MPU_EMAC0_M_QOS_EXTCTL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_EMAC0_M_QOS_ADDR) + ALT_NOC_MPU_EMAC0_M_QOS_EXTCTL_OFST))
/* The base address byte offset for the start of the ALT_NOC_MPU_EMAC0_M_QOS component. */
#define ALT_NOC_MPU_EMAC0_M_QOS_OFST        0xffd16300
/* The start address of the ALT_NOC_MPU_EMAC0_M_QOS component. */
#define ALT_NOC_MPU_EMAC0_M_QOS_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_NOC_MPU_EMAC0_M_QOS_OFST))
/* The lower bound address range of the ALT_NOC_MPU_EMAC0_M_QOS component. */
#define ALT_NOC_MPU_EMAC0_M_QOS_LB_ADDR     ALT_NOC_MPU_EMAC0_M_QOS_ADDR
/* The upper bound address range of the ALT_NOC_MPU_EMAC0_M_QOS component. */
#define ALT_NOC_MPU_EMAC0_M_QOS_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_NOC_MPU_EMAC0_M_QOS_ADDR) + 0x80) - 1))


/*
 * Component Instance : i_noc_mpu_m0_emac1_m_I_main_QosGenerator
 * 
 * Instance i_noc_mpu_m0_emac1_m_I_main_QosGenerator of component ALT_NOC_MPU_EMAC1_M_QOS.
 * 
 * 
 */
/* The address of the ALT_NOC_MPU_EMAC1_M_QOS_COREID register for the ALT_NOC_MPU_EMAC1_M_QOS instance. */
#define ALT_NOC_MPU_EMAC1_M_QOS_COREID_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_EMAC1_M_QOS_ADDR) + ALT_NOC_MPU_EMAC1_M_QOS_COREID_OFST))
/* The address of the ALT_NOC_MPU_EMAC1_M_QOS_REVID register for the ALT_NOC_MPU_EMAC1_M_QOS instance. */
#define ALT_NOC_MPU_EMAC1_M_QOS_REVID_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_EMAC1_M_QOS_ADDR) + ALT_NOC_MPU_EMAC1_M_QOS_REVID_OFST))
/* The address of the ALT_NOC_MPU_EMAC1_M_QOS_PRI register for the ALT_NOC_MPU_EMAC1_M_QOS instance. */
#define ALT_NOC_MPU_EMAC1_M_QOS_PRI_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_EMAC1_M_QOS_ADDR) + ALT_NOC_MPU_EMAC1_M_QOS_PRI_OFST))
/* The address of the ALT_NOC_MPU_EMAC1_M_QOS_MOD register for the ALT_NOC_MPU_EMAC1_M_QOS instance. */
#define ALT_NOC_MPU_EMAC1_M_QOS_MOD_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_EMAC1_M_QOS_ADDR) + ALT_NOC_MPU_EMAC1_M_QOS_MOD_OFST))
/* The address of the ALT_NOC_MPU_EMAC1_M_QOS_BWDTH register for the ALT_NOC_MPU_EMAC1_M_QOS instance. */
#define ALT_NOC_MPU_EMAC1_M_QOS_BWDTH_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_EMAC1_M_QOS_ADDR) + ALT_NOC_MPU_EMAC1_M_QOS_BWDTH_OFST))
/* The address of the ALT_NOC_MPU_EMAC1_M_QOS_SAT register for the ALT_NOC_MPU_EMAC1_M_QOS instance. */
#define ALT_NOC_MPU_EMAC1_M_QOS_SAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_EMAC1_M_QOS_ADDR) + ALT_NOC_MPU_EMAC1_M_QOS_SAT_OFST))
/* The address of the ALT_NOC_MPU_EMAC1_M_QOS_EXTCTL register for the ALT_NOC_MPU_EMAC1_M_QOS instance. */
#define ALT_NOC_MPU_EMAC1_M_QOS_EXTCTL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_EMAC1_M_QOS_ADDR) + ALT_NOC_MPU_EMAC1_M_QOS_EXTCTL_OFST))
/* The base address byte offset for the start of the ALT_NOC_MPU_EMAC1_M_QOS component. */
#define ALT_NOC_MPU_EMAC1_M_QOS_OFST        0xffd16380
/* The start address of the ALT_NOC_MPU_EMAC1_M_QOS component. */
#define ALT_NOC_MPU_EMAC1_M_QOS_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_NOC_MPU_EMAC1_M_QOS_OFST))
/* The lower bound address range of the ALT_NOC_MPU_EMAC1_M_QOS component. */
#define ALT_NOC_MPU_EMAC1_M_QOS_LB_ADDR     ALT_NOC_MPU_EMAC1_M_QOS_ADDR
/* The upper bound address range of the ALT_NOC_MPU_EMAC1_M_QOS component. */
#define ALT_NOC_MPU_EMAC1_M_QOS_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_NOC_MPU_EMAC1_M_QOS_ADDR) + 0x80) - 1))


/*
 * Component Instance : i_noc_mpu_m0_emac2_m_I_main_QosGenerator
 * 
 * Instance i_noc_mpu_m0_emac2_m_I_main_QosGenerator of component ALT_NOC_MPU_EMAC2_M_QOS.
 * 
 * 
 */
/* The address of the ALT_NOC_MPU_EMAC2_M_QOS_COREID register for the ALT_NOC_MPU_EMAC2_M_QOS instance. */
#define ALT_NOC_MPU_EMAC2_M_QOS_COREID_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_EMAC2_M_QOS_ADDR) + ALT_NOC_MPU_EMAC2_M_QOS_COREID_OFST))
/* The address of the ALT_NOC_MPU_EMAC2_M_QOS_REVID register for the ALT_NOC_MPU_EMAC2_M_QOS instance. */
#define ALT_NOC_MPU_EMAC2_M_QOS_REVID_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_EMAC2_M_QOS_ADDR) + ALT_NOC_MPU_EMAC2_M_QOS_REVID_OFST))
/* The address of the ALT_NOC_MPU_EMAC2_M_QOS_PRI register for the ALT_NOC_MPU_EMAC2_M_QOS instance. */
#define ALT_NOC_MPU_EMAC2_M_QOS_PRI_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_EMAC2_M_QOS_ADDR) + ALT_NOC_MPU_EMAC2_M_QOS_PRI_OFST))
/* The address of the ALT_NOC_MPU_EMAC2_M_QOS_MOD register for the ALT_NOC_MPU_EMAC2_M_QOS instance. */
#define ALT_NOC_MPU_EMAC2_M_QOS_MOD_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_EMAC2_M_QOS_ADDR) + ALT_NOC_MPU_EMAC2_M_QOS_MOD_OFST))
/* The address of the ALT_NOC_MPU_EMAC2_M_QOS_BWDTH register for the ALT_NOC_MPU_EMAC2_M_QOS instance. */
#define ALT_NOC_MPU_EMAC2_M_QOS_BWDTH_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_EMAC2_M_QOS_ADDR) + ALT_NOC_MPU_EMAC2_M_QOS_BWDTH_OFST))
/* The address of the ALT_NOC_MPU_EMAC2_M_QOS_SAT register for the ALT_NOC_MPU_EMAC2_M_QOS instance. */
#define ALT_NOC_MPU_EMAC2_M_QOS_SAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_EMAC2_M_QOS_ADDR) + ALT_NOC_MPU_EMAC2_M_QOS_SAT_OFST))
/* The address of the ALT_NOC_MPU_EMAC2_M_QOS_EXTCTL register for the ALT_NOC_MPU_EMAC2_M_QOS instance. */
#define ALT_NOC_MPU_EMAC2_M_QOS_EXTCTL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_EMAC2_M_QOS_ADDR) + ALT_NOC_MPU_EMAC2_M_QOS_EXTCTL_OFST))
/* The base address byte offset for the start of the ALT_NOC_MPU_EMAC2_M_QOS component. */
#define ALT_NOC_MPU_EMAC2_M_QOS_OFST        0xffd16400
/* The start address of the ALT_NOC_MPU_EMAC2_M_QOS component. */
#define ALT_NOC_MPU_EMAC2_M_QOS_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_NOC_MPU_EMAC2_M_QOS_OFST))
/* The lower bound address range of the ALT_NOC_MPU_EMAC2_M_QOS component. */
#define ALT_NOC_MPU_EMAC2_M_QOS_LB_ADDR     ALT_NOC_MPU_EMAC2_M_QOS_ADDR
/* The upper bound address range of the ALT_NOC_MPU_EMAC2_M_QOS component. */
#define ALT_NOC_MPU_EMAC2_M_QOS_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_NOC_MPU_EMAC2_M_QOS_ADDR) + 0x80) - 1))


/*
 * Component Instance : i_noc_mpu_m0_usb0_m_I_main_QosGenerator
 * 
 * Instance i_noc_mpu_m0_usb0_m_I_main_QosGenerator of component ALT_NOC_MPU_USB0_M_MAIN_QOS.
 * 
 * 
 */
/* The address of the ALT_NOC_MPU_USB0_M_MAIN_QOS_COREID register for the ALT_NOC_MPU_USB0_M_MAIN_QOS instance. */
#define ALT_NOC_MPU_USB0_M_MAIN_QOS_COREID_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_USB0_M_MAIN_QOS_ADDR) + ALT_NOC_MPU_USB0_M_MAIN_QOS_COREID_OFST))
/* The address of the ALT_NOC_MPU_USB0_M_MAIN_QOS_REVID register for the ALT_NOC_MPU_USB0_M_MAIN_QOS instance. */
#define ALT_NOC_MPU_USB0_M_MAIN_QOS_REVID_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_USB0_M_MAIN_QOS_ADDR) + ALT_NOC_MPU_USB0_M_MAIN_QOS_REVID_OFST))
/* The address of the ALT_NOC_MPU_USB0_M_MAIN_QOS_PRI register for the ALT_NOC_MPU_USB0_M_MAIN_QOS instance. */
#define ALT_NOC_MPU_USB0_M_MAIN_QOS_PRI_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_USB0_M_MAIN_QOS_ADDR) + ALT_NOC_MPU_USB0_M_MAIN_QOS_PRI_OFST))
/* The address of the ALT_NOC_MPU_USB0_M_MAIN_QOS_MOD register for the ALT_NOC_MPU_USB0_M_MAIN_QOS instance. */
#define ALT_NOC_MPU_USB0_M_MAIN_QOS_MOD_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_USB0_M_MAIN_QOS_ADDR) + ALT_NOC_MPU_USB0_M_MAIN_QOS_MOD_OFST))
/* The address of the ALT_NOC_MPU_USB0_M_MAIN_QOS_BWDTH register for the ALT_NOC_MPU_USB0_M_MAIN_QOS instance. */
#define ALT_NOC_MPU_USB0_M_MAIN_QOS_BWDTH_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_USB0_M_MAIN_QOS_ADDR) + ALT_NOC_MPU_USB0_M_MAIN_QOS_BWDTH_OFST))
/* The address of the ALT_NOC_MPU_USB0_M_MAIN_QOS_SAT register for the ALT_NOC_MPU_USB0_M_MAIN_QOS instance. */
#define ALT_NOC_MPU_USB0_M_MAIN_QOS_SAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_USB0_M_MAIN_QOS_ADDR) + ALT_NOC_MPU_USB0_M_MAIN_QOS_SAT_OFST))
/* The address of the ALT_NOC_MPU_USB0_M_MAIN_QOS_EXTCTL register for the ALT_NOC_MPU_USB0_M_MAIN_QOS instance. */
#define ALT_NOC_MPU_USB0_M_MAIN_QOS_EXTCTL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_USB0_M_MAIN_QOS_ADDR) + ALT_NOC_MPU_USB0_M_MAIN_QOS_EXTCTL_OFST))
/* The base address byte offset for the start of the ALT_NOC_MPU_USB0_M_MAIN_QOS component. */
#define ALT_NOC_MPU_USB0_M_MAIN_QOS_OFST        0xffd16480
/* The start address of the ALT_NOC_MPU_USB0_M_MAIN_QOS component. */
#define ALT_NOC_MPU_USB0_M_MAIN_QOS_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_NOC_MPU_USB0_M_MAIN_QOS_OFST))
/* The lower bound address range of the ALT_NOC_MPU_USB0_M_MAIN_QOS component. */
#define ALT_NOC_MPU_USB0_M_MAIN_QOS_LB_ADDR     ALT_NOC_MPU_USB0_M_MAIN_QOS_ADDR
/* The upper bound address range of the ALT_NOC_MPU_USB0_M_MAIN_QOS component. */
#define ALT_NOC_MPU_USB0_M_MAIN_QOS_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_NOC_MPU_USB0_M_MAIN_QOS_ADDR) + 0x80) - 1))


/*
 * Component Instance : i_noc_mpu_m0_usb1_m_I_main_QosGenerator
 * 
 * Instance i_noc_mpu_m0_usb1_m_I_main_QosGenerator of component ALT_NOC_MPU_USB1_M_MAIN_QOS.
 * 
 * 
 */
/* The address of the ALT_NOC_MPU_USB1_M_MAIN_QOS_COREID register for the ALT_NOC_MPU_USB1_M_MAIN_QOS instance. */
#define ALT_NOC_MPU_USB1_M_MAIN_QOS_COREID_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_USB1_M_MAIN_QOS_ADDR) + ALT_NOC_MPU_USB1_M_MAIN_QOS_COREID_OFST))
/* The address of the ALT_NOC_MPU_USB1_M_MAIN_QOS_REVID register for the ALT_NOC_MPU_USB1_M_MAIN_QOS instance. */
#define ALT_NOC_MPU_USB1_M_MAIN_QOS_REVID_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_USB1_M_MAIN_QOS_ADDR) + ALT_NOC_MPU_USB1_M_MAIN_QOS_REVID_OFST))
/* The address of the ALT_NOC_MPU_USB1_M_MAIN_QOS_PRI register for the ALT_NOC_MPU_USB1_M_MAIN_QOS instance. */
#define ALT_NOC_MPU_USB1_M_MAIN_QOS_PRI_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_USB1_M_MAIN_QOS_ADDR) + ALT_NOC_MPU_USB1_M_MAIN_QOS_PRI_OFST))
/* The address of the ALT_NOC_MPU_USB1_M_MAIN_QOS_MOD register for the ALT_NOC_MPU_USB1_M_MAIN_QOS instance. */
#define ALT_NOC_MPU_USB1_M_MAIN_QOS_MOD_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_USB1_M_MAIN_QOS_ADDR) + ALT_NOC_MPU_USB1_M_MAIN_QOS_MOD_OFST))
/* The address of the ALT_NOC_MPU_USB1_M_MAIN_QOS_BWDTH register for the ALT_NOC_MPU_USB1_M_MAIN_QOS instance. */
#define ALT_NOC_MPU_USB1_M_MAIN_QOS_BWDTH_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_USB1_M_MAIN_QOS_ADDR) + ALT_NOC_MPU_USB1_M_MAIN_QOS_BWDTH_OFST))
/* The address of the ALT_NOC_MPU_USB1_M_MAIN_QOS_SAT register for the ALT_NOC_MPU_USB1_M_MAIN_QOS instance. */
#define ALT_NOC_MPU_USB1_M_MAIN_QOS_SAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_USB1_M_MAIN_QOS_ADDR) + ALT_NOC_MPU_USB1_M_MAIN_QOS_SAT_OFST))
/* The address of the ALT_NOC_MPU_USB1_M_MAIN_QOS_EXTCTL register for the ALT_NOC_MPU_USB1_M_MAIN_QOS instance. */
#define ALT_NOC_MPU_USB1_M_MAIN_QOS_EXTCTL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_USB1_M_MAIN_QOS_ADDR) + ALT_NOC_MPU_USB1_M_MAIN_QOS_EXTCTL_OFST))
/* The base address byte offset for the start of the ALT_NOC_MPU_USB1_M_MAIN_QOS component. */
#define ALT_NOC_MPU_USB1_M_MAIN_QOS_OFST        0xffd16500
/* The start address of the ALT_NOC_MPU_USB1_M_MAIN_QOS component. */
#define ALT_NOC_MPU_USB1_M_MAIN_QOS_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_NOC_MPU_USB1_M_MAIN_QOS_OFST))
/* The lower bound address range of the ALT_NOC_MPU_USB1_M_MAIN_QOS component. */
#define ALT_NOC_MPU_USB1_M_MAIN_QOS_LB_ADDR     ALT_NOC_MPU_USB1_M_MAIN_QOS_ADDR
/* The upper bound address range of the ALT_NOC_MPU_USB1_M_MAIN_QOS component. */
#define ALT_NOC_MPU_USB1_M_MAIN_QOS_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_NOC_MPU_USB1_M_MAIN_QOS_ADDR) + 0x80) - 1))


/*
 * Component Instance : i_noc_mpu_m0_nand_m_I_main_QosGenerator
 * 
 * Instance i_noc_mpu_m0_nand_m_I_main_QosGenerator of component ALT_NOC_MPU_NAND_M_MAIN_QOS.
 * 
 * 
 */
/* The address of the ALT_NOC_MPU_NAND_M_MAIN_QOS_COREID register for the ALT_NOC_MPU_NAND_M_MAIN_QOS instance. */
#define ALT_NOC_MPU_NAND_M_MAIN_QOS_COREID_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_NAND_M_MAIN_QOS_ADDR) + ALT_NOC_MPU_NAND_M_MAIN_QOS_COREID_OFST))
/* The address of the ALT_NOC_MPU_NAND_M_MAIN_QOS_REVID register for the ALT_NOC_MPU_NAND_M_MAIN_QOS instance. */
#define ALT_NOC_MPU_NAND_M_MAIN_QOS_REVID_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_NAND_M_MAIN_QOS_ADDR) + ALT_NOC_MPU_NAND_M_MAIN_QOS_REVID_OFST))
/* The address of the ALT_NOC_MPU_NAND_M_MAIN_QOS_PRI register for the ALT_NOC_MPU_NAND_M_MAIN_QOS instance. */
#define ALT_NOC_MPU_NAND_M_MAIN_QOS_PRI_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_NAND_M_MAIN_QOS_ADDR) + ALT_NOC_MPU_NAND_M_MAIN_QOS_PRI_OFST))
/* The address of the ALT_NOC_MPU_NAND_M_MAIN_QOS_MOD register for the ALT_NOC_MPU_NAND_M_MAIN_QOS instance. */
#define ALT_NOC_MPU_NAND_M_MAIN_QOS_MOD_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_NAND_M_MAIN_QOS_ADDR) + ALT_NOC_MPU_NAND_M_MAIN_QOS_MOD_OFST))
/* The address of the ALT_NOC_MPU_NAND_M_MAIN_QOS_BWDTH register for the ALT_NOC_MPU_NAND_M_MAIN_QOS instance. */
#define ALT_NOC_MPU_NAND_M_MAIN_QOS_BWDTH_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_NAND_M_MAIN_QOS_ADDR) + ALT_NOC_MPU_NAND_M_MAIN_QOS_BWDTH_OFST))
/* The address of the ALT_NOC_MPU_NAND_M_MAIN_QOS_SAT register for the ALT_NOC_MPU_NAND_M_MAIN_QOS instance. */
#define ALT_NOC_MPU_NAND_M_MAIN_QOS_SAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_NAND_M_MAIN_QOS_ADDR) + ALT_NOC_MPU_NAND_M_MAIN_QOS_SAT_OFST))
/* The address of the ALT_NOC_MPU_NAND_M_MAIN_QOS_EXTCTL register for the ALT_NOC_MPU_NAND_M_MAIN_QOS instance. */
#define ALT_NOC_MPU_NAND_M_MAIN_QOS_EXTCTL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_NAND_M_MAIN_QOS_ADDR) + ALT_NOC_MPU_NAND_M_MAIN_QOS_EXTCTL_OFST))
/* The base address byte offset for the start of the ALT_NOC_MPU_NAND_M_MAIN_QOS component. */
#define ALT_NOC_MPU_NAND_M_MAIN_QOS_OFST        0xffd16580
/* The start address of the ALT_NOC_MPU_NAND_M_MAIN_QOS component. */
#define ALT_NOC_MPU_NAND_M_MAIN_QOS_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_NOC_MPU_NAND_M_MAIN_QOS_OFST))
/* The lower bound address range of the ALT_NOC_MPU_NAND_M_MAIN_QOS component. */
#define ALT_NOC_MPU_NAND_M_MAIN_QOS_LB_ADDR     ALT_NOC_MPU_NAND_M_MAIN_QOS_ADDR
/* The upper bound address range of the ALT_NOC_MPU_NAND_M_MAIN_QOS component. */
#define ALT_NOC_MPU_NAND_M_MAIN_QOS_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_NOC_MPU_NAND_M_MAIN_QOS_ADDR) + 0x80) - 1))


/*
 * Component Instance : i_noc_mpu_m0_sdmmc_m_I_main_QosGenerator
 * 
 * Instance i_noc_mpu_m0_sdmmc_m_I_main_QosGenerator of component ALT_NOC_MPU_SDMMC_M_MAIN_QOS.
 * 
 * 
 */
/* The address of the ALT_NOC_MPU_SDMMC_M_MAIN_QOS_COREID register for the ALT_NOC_MPU_SDMMC_M_MAIN_QOS instance. */
#define ALT_NOC_MPU_SDMMC_M_MAIN_QOS_COREID_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_SDMMC_M_MAIN_QOS_ADDR) + ALT_NOC_MPU_SDMMC_M_MAIN_QOS_COREID_OFST))
/* The address of the ALT_NOC_MPU_SDMMC_M_MAIN_QOS_REVID register for the ALT_NOC_MPU_SDMMC_M_MAIN_QOS instance. */
#define ALT_NOC_MPU_SDMMC_M_MAIN_QOS_REVID_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_SDMMC_M_MAIN_QOS_ADDR) + ALT_NOC_MPU_SDMMC_M_MAIN_QOS_REVID_OFST))
/* The address of the ALT_NOC_MPU_SDMMC_M_MAIN_QOS_PRI register for the ALT_NOC_MPU_SDMMC_M_MAIN_QOS instance. */
#define ALT_NOC_MPU_SDMMC_M_MAIN_QOS_PRI_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_SDMMC_M_MAIN_QOS_ADDR) + ALT_NOC_MPU_SDMMC_M_MAIN_QOS_PRI_OFST))
/* The address of the ALT_NOC_MPU_SDMMC_M_MAIN_QOS_MOD register for the ALT_NOC_MPU_SDMMC_M_MAIN_QOS instance. */
#define ALT_NOC_MPU_SDMMC_M_MAIN_QOS_MOD_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_SDMMC_M_MAIN_QOS_ADDR) + ALT_NOC_MPU_SDMMC_M_MAIN_QOS_MOD_OFST))
/* The address of the ALT_NOC_MPU_SDMMC_M_MAIN_QOS_BWDTH register for the ALT_NOC_MPU_SDMMC_M_MAIN_QOS instance. */
#define ALT_NOC_MPU_SDMMC_M_MAIN_QOS_BWDTH_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_SDMMC_M_MAIN_QOS_ADDR) + ALT_NOC_MPU_SDMMC_M_MAIN_QOS_BWDTH_OFST))
/* The address of the ALT_NOC_MPU_SDMMC_M_MAIN_QOS_SAT register for the ALT_NOC_MPU_SDMMC_M_MAIN_QOS instance. */
#define ALT_NOC_MPU_SDMMC_M_MAIN_QOS_SAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_SDMMC_M_MAIN_QOS_ADDR) + ALT_NOC_MPU_SDMMC_M_MAIN_QOS_SAT_OFST))
/* The address of the ALT_NOC_MPU_SDMMC_M_MAIN_QOS_EXTCTL register for the ALT_NOC_MPU_SDMMC_M_MAIN_QOS instance. */
#define ALT_NOC_MPU_SDMMC_M_MAIN_QOS_EXTCTL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_SDMMC_M_MAIN_QOS_ADDR) + ALT_NOC_MPU_SDMMC_M_MAIN_QOS_EXTCTL_OFST))
/* The base address byte offset for the start of the ALT_NOC_MPU_SDMMC_M_MAIN_QOS component. */
#define ALT_NOC_MPU_SDMMC_M_MAIN_QOS_OFST        0xffd16600
/* The start address of the ALT_NOC_MPU_SDMMC_M_MAIN_QOS component. */
#define ALT_NOC_MPU_SDMMC_M_MAIN_QOS_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_NOC_MPU_SDMMC_M_MAIN_QOS_OFST))
/* The lower bound address range of the ALT_NOC_MPU_SDMMC_M_MAIN_QOS component. */
#define ALT_NOC_MPU_SDMMC_M_MAIN_QOS_LB_ADDR     ALT_NOC_MPU_SDMMC_M_MAIN_QOS_ADDR
/* The upper bound address range of the ALT_NOC_MPU_SDMMC_M_MAIN_QOS component. */
#define ALT_NOC_MPU_SDMMC_M_MAIN_QOS_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_NOC_MPU_SDMMC_M_MAIN_QOS_ADDR) + 0x80) - 1))


/*
 * Component Instance : i_noc_mpu_m0_fpga2sdram0_axi32_I_main_QosGenerator
 * 
 * Instance i_noc_mpu_m0_fpga2sdram0_axi32_I_main_QosGenerator of component ALT_NOC_MPU_F2SDR0_AXI32_QOS.
 * 
 * 
 */
/* The address of the ALT_NOC_MPU_F2SDR0_AXI32_QOS_COREID register for the ALT_NOC_MPU_F2SDR0_AXI32_QOS instance. */
#define ALT_NOC_MPU_F2SDR0_AXI32_QOS_COREID_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_F2SDR0_AXI32_QOS_ADDR) + ALT_NOC_MPU_F2SDR0_AXI32_QOS_COREID_OFST))
/* The address of the ALT_NOC_MPU_F2SDR0_AXI32_QOS_REVID register for the ALT_NOC_MPU_F2SDR0_AXI32_QOS instance. */
#define ALT_NOC_MPU_F2SDR0_AXI32_QOS_REVID_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_F2SDR0_AXI32_QOS_ADDR) + ALT_NOC_MPU_F2SDR0_AXI32_QOS_REVID_OFST))
/* The address of the ALT_NOC_MPU_F2SDR0_AXI32_QOS_PRI register for the ALT_NOC_MPU_F2SDR0_AXI32_QOS instance. */
#define ALT_NOC_MPU_F2SDR0_AXI32_QOS_PRI_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_F2SDR0_AXI32_QOS_ADDR) + ALT_NOC_MPU_F2SDR0_AXI32_QOS_PRI_OFST))
/* The address of the ALT_NOC_MPU_F2SDR0_AXI32_QOS_MOD register for the ALT_NOC_MPU_F2SDR0_AXI32_QOS instance. */
#define ALT_NOC_MPU_F2SDR0_AXI32_QOS_MOD_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_F2SDR0_AXI32_QOS_ADDR) + ALT_NOC_MPU_F2SDR0_AXI32_QOS_MOD_OFST))
/* The address of the ALT_NOC_MPU_F2SDR0_AXI32_QOS_BWDTH register for the ALT_NOC_MPU_F2SDR0_AXI32_QOS instance. */
#define ALT_NOC_MPU_F2SDR0_AXI32_QOS_BWDTH_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_F2SDR0_AXI32_QOS_ADDR) + ALT_NOC_MPU_F2SDR0_AXI32_QOS_BWDTH_OFST))
/* The address of the ALT_NOC_MPU_F2SDR0_AXI32_QOS_SAT register for the ALT_NOC_MPU_F2SDR0_AXI32_QOS instance. */
#define ALT_NOC_MPU_F2SDR0_AXI32_QOS_SAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_F2SDR0_AXI32_QOS_ADDR) + ALT_NOC_MPU_F2SDR0_AXI32_QOS_SAT_OFST))
/* The address of the ALT_NOC_MPU_F2SDR0_AXI32_QOS_EXTCTL register for the ALT_NOC_MPU_F2SDR0_AXI32_QOS instance. */
#define ALT_NOC_MPU_F2SDR0_AXI32_QOS_EXTCTL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_F2SDR0_AXI32_QOS_ADDR) + ALT_NOC_MPU_F2SDR0_AXI32_QOS_EXTCTL_OFST))
/* The base address byte offset for the start of the ALT_NOC_MPU_F2SDR0_AXI32_QOS component. */
#define ALT_NOC_MPU_F2SDR0_AXI32_QOS_OFST        0xffd16680
/* The start address of the ALT_NOC_MPU_F2SDR0_AXI32_QOS component. */
#define ALT_NOC_MPU_F2SDR0_AXI32_QOS_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_NOC_MPU_F2SDR0_AXI32_QOS_OFST))
/* The lower bound address range of the ALT_NOC_MPU_F2SDR0_AXI32_QOS component. */
#define ALT_NOC_MPU_F2SDR0_AXI32_QOS_LB_ADDR     ALT_NOC_MPU_F2SDR0_AXI32_QOS_ADDR
/* The upper bound address range of the ALT_NOC_MPU_F2SDR0_AXI32_QOS component. */
#define ALT_NOC_MPU_F2SDR0_AXI32_QOS_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_NOC_MPU_F2SDR0_AXI32_QOS_ADDR) + 0x80) - 1))


/*
 * Component Instance : i_noc_mpu_m0_fpga2sdram0_axi64_I_main_QosGenerator
 * 
 * Instance i_noc_mpu_m0_fpga2sdram0_axi64_I_main_QosGenerator of component ALT_NOC_MPU_F2SDR0_AXI64_QOS.
 * 
 * 
 */
/* The address of the ALT_NOC_MPU_F2SDR0_AXI64_QOS_COREID register for the ALT_NOC_MPU_F2SDR0_AXI64_QOS instance. */
#define ALT_NOC_MPU_F2SDR0_AXI64_QOS_COREID_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_F2SDR0_AXI64_QOS_ADDR) + ALT_NOC_MPU_F2SDR0_AXI64_QOS_COREID_OFST))
/* The address of the ALT_NOC_MPU_F2SDR0_AXI64_QOS_REVID register for the ALT_NOC_MPU_F2SDR0_AXI64_QOS instance. */
#define ALT_NOC_MPU_F2SDR0_AXI64_QOS_REVID_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_F2SDR0_AXI64_QOS_ADDR) + ALT_NOC_MPU_F2SDR0_AXI64_QOS_REVID_OFST))
/* The address of the ALT_NOC_MPU_F2SDR0_AXI64_QOS_PRI register for the ALT_NOC_MPU_F2SDR0_AXI64_QOS instance. */
#define ALT_NOC_MPU_F2SDR0_AXI64_QOS_PRI_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_F2SDR0_AXI64_QOS_ADDR) + ALT_NOC_MPU_F2SDR0_AXI64_QOS_PRI_OFST))
/* The address of the ALT_NOC_MPU_F2SDR0_AXI64_QOS_MOD register for the ALT_NOC_MPU_F2SDR0_AXI64_QOS instance. */
#define ALT_NOC_MPU_F2SDR0_AXI64_QOS_MOD_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_F2SDR0_AXI64_QOS_ADDR) + ALT_NOC_MPU_F2SDR0_AXI64_QOS_MOD_OFST))
/* The address of the ALT_NOC_MPU_F2SDR0_AXI64_QOS_BWDTH register for the ALT_NOC_MPU_F2SDR0_AXI64_QOS instance. */
#define ALT_NOC_MPU_F2SDR0_AXI64_QOS_BWDTH_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_F2SDR0_AXI64_QOS_ADDR) + ALT_NOC_MPU_F2SDR0_AXI64_QOS_BWDTH_OFST))
/* The address of the ALT_NOC_MPU_F2SDR0_AXI64_QOS_SAT register for the ALT_NOC_MPU_F2SDR0_AXI64_QOS instance. */
#define ALT_NOC_MPU_F2SDR0_AXI64_QOS_SAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_F2SDR0_AXI64_QOS_ADDR) + ALT_NOC_MPU_F2SDR0_AXI64_QOS_SAT_OFST))
/* The address of the ALT_NOC_MPU_F2SDR0_AXI64_QOS_EXTCTL register for the ALT_NOC_MPU_F2SDR0_AXI64_QOS instance. */
#define ALT_NOC_MPU_F2SDR0_AXI64_QOS_EXTCTL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_F2SDR0_AXI64_QOS_ADDR) + ALT_NOC_MPU_F2SDR0_AXI64_QOS_EXTCTL_OFST))
/* The base address byte offset for the start of the ALT_NOC_MPU_F2SDR0_AXI64_QOS component. */
#define ALT_NOC_MPU_F2SDR0_AXI64_QOS_OFST        0xffd16700
/* The start address of the ALT_NOC_MPU_F2SDR0_AXI64_QOS component. */
#define ALT_NOC_MPU_F2SDR0_AXI64_QOS_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_NOC_MPU_F2SDR0_AXI64_QOS_OFST))
/* The lower bound address range of the ALT_NOC_MPU_F2SDR0_AXI64_QOS component. */
#define ALT_NOC_MPU_F2SDR0_AXI64_QOS_LB_ADDR     ALT_NOC_MPU_F2SDR0_AXI64_QOS_ADDR
/* The upper bound address range of the ALT_NOC_MPU_F2SDR0_AXI64_QOS component. */
#define ALT_NOC_MPU_F2SDR0_AXI64_QOS_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_NOC_MPU_F2SDR0_AXI64_QOS_ADDR) + 0x80) - 1))


/*
 * Component Instance : i_noc_mpu_m0_fpga2sdram0_axi128_I_main_QosGenerator
 * 
 * Instance i_noc_mpu_m0_fpga2sdram0_axi128_I_main_QosGenerator of component ALT_NOC_MPU_F2SDR0_AXI128_QOS.
 * 
 * 
 */
/* The address of the ALT_NOC_MPU_F2SDR0_AXI128_QOS_COREID register for the ALT_NOC_MPU_F2SDR0_AXI128_QOS instance. */
#define ALT_NOC_MPU_F2SDR0_AXI128_QOS_COREID_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_F2SDR0_AXI128_QOS_ADDR) + ALT_NOC_MPU_F2SDR0_AXI128_QOS_COREID_OFST))
/* The address of the ALT_NOC_MPU_F2SDR0_AXI128_QOS_REVID register for the ALT_NOC_MPU_F2SDR0_AXI128_QOS instance. */
#define ALT_NOC_MPU_F2SDR0_AXI128_QOS_REVID_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_F2SDR0_AXI128_QOS_ADDR) + ALT_NOC_MPU_F2SDR0_AXI128_QOS_REVID_OFST))
/* The address of the ALT_NOC_MPU_F2SDR0_AXI128_QOS_PRI register for the ALT_NOC_MPU_F2SDR0_AXI128_QOS instance. */
#define ALT_NOC_MPU_F2SDR0_AXI128_QOS_PRI_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_F2SDR0_AXI128_QOS_ADDR) + ALT_NOC_MPU_F2SDR0_AXI128_QOS_PRI_OFST))
/* The address of the ALT_NOC_MPU_F2SDR0_AXI128_QOS_MOD register for the ALT_NOC_MPU_F2SDR0_AXI128_QOS instance. */
#define ALT_NOC_MPU_F2SDR0_AXI128_QOS_MOD_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_F2SDR0_AXI128_QOS_ADDR) + ALT_NOC_MPU_F2SDR0_AXI128_QOS_MOD_OFST))
/* The address of the ALT_NOC_MPU_F2SDR0_AXI128_QOS_BWDTH register for the ALT_NOC_MPU_F2SDR0_AXI128_QOS instance. */
#define ALT_NOC_MPU_F2SDR0_AXI128_QOS_BWDTH_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_F2SDR0_AXI128_QOS_ADDR) + ALT_NOC_MPU_F2SDR0_AXI128_QOS_BWDTH_OFST))
/* The address of the ALT_NOC_MPU_F2SDR0_AXI128_QOS_SAT register for the ALT_NOC_MPU_F2SDR0_AXI128_QOS instance. */
#define ALT_NOC_MPU_F2SDR0_AXI128_QOS_SAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_F2SDR0_AXI128_QOS_ADDR) + ALT_NOC_MPU_F2SDR0_AXI128_QOS_SAT_OFST))
/* The address of the ALT_NOC_MPU_F2SDR0_AXI128_QOS_EXTCTL register for the ALT_NOC_MPU_F2SDR0_AXI128_QOS instance. */
#define ALT_NOC_MPU_F2SDR0_AXI128_QOS_EXTCTL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_F2SDR0_AXI128_QOS_ADDR) + ALT_NOC_MPU_F2SDR0_AXI128_QOS_EXTCTL_OFST))
/* The base address byte offset for the start of the ALT_NOC_MPU_F2SDR0_AXI128_QOS component. */
#define ALT_NOC_MPU_F2SDR0_AXI128_QOS_OFST        0xffd16780
/* The start address of the ALT_NOC_MPU_F2SDR0_AXI128_QOS component. */
#define ALT_NOC_MPU_F2SDR0_AXI128_QOS_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_NOC_MPU_F2SDR0_AXI128_QOS_OFST))
/* The lower bound address range of the ALT_NOC_MPU_F2SDR0_AXI128_QOS component. */
#define ALT_NOC_MPU_F2SDR0_AXI128_QOS_LB_ADDR     ALT_NOC_MPU_F2SDR0_AXI128_QOS_ADDR
/* The upper bound address range of the ALT_NOC_MPU_F2SDR0_AXI128_QOS component. */
#define ALT_NOC_MPU_F2SDR0_AXI128_QOS_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_NOC_MPU_F2SDR0_AXI128_QOS_ADDR) + 0x80) - 1))


/*
 * Component Instance : i_noc_mpu_m0_fpga2sdram1_axi32_I_main_QosGenerator
 * 
 * Instance i_noc_mpu_m0_fpga2sdram1_axi32_I_main_QosGenerator of component ALT_NOC_MPU_F2SDR1_AXI32_QOS.
 * 
 * 
 */
/* The address of the ALT_NOC_MPU_F2SDR1_AXI32_QOS_COREID register for the ALT_NOC_MPU_F2SDR1_AXI32_QOS instance. */
#define ALT_NOC_MPU_F2SDR1_AXI32_QOS_COREID_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_F2SDR1_AXI32_QOS_ADDR) + ALT_NOC_MPU_F2SDR1_AXI32_QOS_COREID_OFST))
/* The address of the ALT_NOC_MPU_F2SDR1_AXI32_QOS_REVID register for the ALT_NOC_MPU_F2SDR1_AXI32_QOS instance. */
#define ALT_NOC_MPU_F2SDR1_AXI32_QOS_REVID_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_F2SDR1_AXI32_QOS_ADDR) + ALT_NOC_MPU_F2SDR1_AXI32_QOS_REVID_OFST))
/* The address of the ALT_NOC_MPU_F2SDR1_AXI32_QOS_PRI register for the ALT_NOC_MPU_F2SDR1_AXI32_QOS instance. */
#define ALT_NOC_MPU_F2SDR1_AXI32_QOS_PRI_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_F2SDR1_AXI32_QOS_ADDR) + ALT_NOC_MPU_F2SDR1_AXI32_QOS_PRI_OFST))
/* The address of the ALT_NOC_MPU_F2SDR1_AXI32_QOS_MOD register for the ALT_NOC_MPU_F2SDR1_AXI32_QOS instance. */
#define ALT_NOC_MPU_F2SDR1_AXI32_QOS_MOD_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_F2SDR1_AXI32_QOS_ADDR) + ALT_NOC_MPU_F2SDR1_AXI32_QOS_MOD_OFST))
/* The address of the ALT_NOC_MPU_F2SDR1_AXI32_QOS_BWDTH register for the ALT_NOC_MPU_F2SDR1_AXI32_QOS instance. */
#define ALT_NOC_MPU_F2SDR1_AXI32_QOS_BWDTH_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_F2SDR1_AXI32_QOS_ADDR) + ALT_NOC_MPU_F2SDR1_AXI32_QOS_BWDTH_OFST))
/* The address of the ALT_NOC_MPU_F2SDR1_AXI32_QOS_SAT register for the ALT_NOC_MPU_F2SDR1_AXI32_QOS instance. */
#define ALT_NOC_MPU_F2SDR1_AXI32_QOS_SAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_F2SDR1_AXI32_QOS_ADDR) + ALT_NOC_MPU_F2SDR1_AXI32_QOS_SAT_OFST))
/* The address of the ALT_NOC_MPU_F2SDR1_AXI32_QOS_EXTCTL register for the ALT_NOC_MPU_F2SDR1_AXI32_QOS instance. */
#define ALT_NOC_MPU_F2SDR1_AXI32_QOS_EXTCTL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_F2SDR1_AXI32_QOS_ADDR) + ALT_NOC_MPU_F2SDR1_AXI32_QOS_EXTCTL_OFST))
/* The base address byte offset for the start of the ALT_NOC_MPU_F2SDR1_AXI32_QOS component. */
#define ALT_NOC_MPU_F2SDR1_AXI32_QOS_OFST        0xffd16800
/* The start address of the ALT_NOC_MPU_F2SDR1_AXI32_QOS component. */
#define ALT_NOC_MPU_F2SDR1_AXI32_QOS_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_NOC_MPU_F2SDR1_AXI32_QOS_OFST))
/* The lower bound address range of the ALT_NOC_MPU_F2SDR1_AXI32_QOS component. */
#define ALT_NOC_MPU_F2SDR1_AXI32_QOS_LB_ADDR     ALT_NOC_MPU_F2SDR1_AXI32_QOS_ADDR
/* The upper bound address range of the ALT_NOC_MPU_F2SDR1_AXI32_QOS component. */
#define ALT_NOC_MPU_F2SDR1_AXI32_QOS_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_NOC_MPU_F2SDR1_AXI32_QOS_ADDR) + 0x80) - 1))


/*
 * Component Instance : i_noc_mpu_m0_fpga2sdram1_axi64_I_main_QosGenerator
 * 
 * Instance i_noc_mpu_m0_fpga2sdram1_axi64_I_main_QosGenerator of component ALT_NOC_MPU_F2SDR1_AXI64_QOS.
 * 
 * 
 */
/* The address of the ALT_NOC_MPU_F2SDR1_AXI64_QOS_COREID register for the ALT_NOC_MPU_F2SDR1_AXI64_QOS instance. */
#define ALT_NOC_MPU_F2SDR1_AXI64_QOS_COREID_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_F2SDR1_AXI64_QOS_ADDR) + ALT_NOC_MPU_F2SDR1_AXI64_QOS_COREID_OFST))
/* The address of the ALT_NOC_MPU_F2SDR1_AXI64_QOS_REVID register for the ALT_NOC_MPU_F2SDR1_AXI64_QOS instance. */
#define ALT_NOC_MPU_F2SDR1_AXI64_QOS_REVID_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_F2SDR1_AXI64_QOS_ADDR) + ALT_NOC_MPU_F2SDR1_AXI64_QOS_REVID_OFST))
/* The address of the ALT_NOC_MPU_F2SDR1_AXI64_QOS_PRI register for the ALT_NOC_MPU_F2SDR1_AXI64_QOS instance. */
#define ALT_NOC_MPU_F2SDR1_AXI64_QOS_PRI_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_F2SDR1_AXI64_QOS_ADDR) + ALT_NOC_MPU_F2SDR1_AXI64_QOS_PRI_OFST))
/* The address of the ALT_NOC_MPU_F2SDR1_AXI64_QOS_MOD register for the ALT_NOC_MPU_F2SDR1_AXI64_QOS instance. */
#define ALT_NOC_MPU_F2SDR1_AXI64_QOS_MOD_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_F2SDR1_AXI64_QOS_ADDR) + ALT_NOC_MPU_F2SDR1_AXI64_QOS_MOD_OFST))
/* The address of the ALT_NOC_MPU_F2SDR1_AXI64_QOS_BWDTH register for the ALT_NOC_MPU_F2SDR1_AXI64_QOS instance. */
#define ALT_NOC_MPU_F2SDR1_AXI64_QOS_BWDTH_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_F2SDR1_AXI64_QOS_ADDR) + ALT_NOC_MPU_F2SDR1_AXI64_QOS_BWDTH_OFST))
/* The address of the ALT_NOC_MPU_F2SDR1_AXI64_QOS_SAT register for the ALT_NOC_MPU_F2SDR1_AXI64_QOS instance. */
#define ALT_NOC_MPU_F2SDR1_AXI64_QOS_SAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_F2SDR1_AXI64_QOS_ADDR) + ALT_NOC_MPU_F2SDR1_AXI64_QOS_SAT_OFST))
/* The address of the ALT_NOC_MPU_F2SDR1_AXI64_QOS_EXTCTL register for the ALT_NOC_MPU_F2SDR1_AXI64_QOS instance. */
#define ALT_NOC_MPU_F2SDR1_AXI64_QOS_EXTCTL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_F2SDR1_AXI64_QOS_ADDR) + ALT_NOC_MPU_F2SDR1_AXI64_QOS_EXTCTL_OFST))
/* The base address byte offset for the start of the ALT_NOC_MPU_F2SDR1_AXI64_QOS component. */
#define ALT_NOC_MPU_F2SDR1_AXI64_QOS_OFST        0xffd16880
/* The start address of the ALT_NOC_MPU_F2SDR1_AXI64_QOS component. */
#define ALT_NOC_MPU_F2SDR1_AXI64_QOS_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_NOC_MPU_F2SDR1_AXI64_QOS_OFST))
/* The lower bound address range of the ALT_NOC_MPU_F2SDR1_AXI64_QOS component. */
#define ALT_NOC_MPU_F2SDR1_AXI64_QOS_LB_ADDR     ALT_NOC_MPU_F2SDR1_AXI64_QOS_ADDR
/* The upper bound address range of the ALT_NOC_MPU_F2SDR1_AXI64_QOS component. */
#define ALT_NOC_MPU_F2SDR1_AXI64_QOS_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_NOC_MPU_F2SDR1_AXI64_QOS_ADDR) + 0x80) - 1))


/*
 * Component Instance : i_noc_mpu_m0_fpga2sdram2_axi32_I_main_QosGenerator
 * 
 * Instance i_noc_mpu_m0_fpga2sdram2_axi32_I_main_QosGenerator of component ALT_NOC_MPU_F2SDR2_AXI32_QOS.
 * 
 * 
 */
/* The address of the ALT_NOC_MPU_F2SDR2_AXI32_QOS_COREID register for the ALT_NOC_MPU_F2SDR2_AXI32_QOS instance. */
#define ALT_NOC_MPU_F2SDR2_AXI32_QOS_COREID_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_F2SDR2_AXI32_QOS_ADDR) + ALT_NOC_MPU_F2SDR2_AXI32_QOS_COREID_OFST))
/* The address of the ALT_NOC_MPU_F2SDR2_AXI32_QOS_REVID register for the ALT_NOC_MPU_F2SDR2_AXI32_QOS instance. */
#define ALT_NOC_MPU_F2SDR2_AXI32_QOS_REVID_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_F2SDR2_AXI32_QOS_ADDR) + ALT_NOC_MPU_F2SDR2_AXI32_QOS_REVID_OFST))
/* The address of the ALT_NOC_MPU_F2SDR2_AXI32_QOS_PRI register for the ALT_NOC_MPU_F2SDR2_AXI32_QOS instance. */
#define ALT_NOC_MPU_F2SDR2_AXI32_QOS_PRI_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_F2SDR2_AXI32_QOS_ADDR) + ALT_NOC_MPU_F2SDR2_AXI32_QOS_PRI_OFST))
/* The address of the ALT_NOC_MPU_F2SDR2_AXI32_QOS_MOD register for the ALT_NOC_MPU_F2SDR2_AXI32_QOS instance. */
#define ALT_NOC_MPU_F2SDR2_AXI32_QOS_MOD_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_F2SDR2_AXI32_QOS_ADDR) + ALT_NOC_MPU_F2SDR2_AXI32_QOS_MOD_OFST))
/* The address of the ALT_NOC_MPU_F2SDR2_AXI32_QOS_BWDTH register for the ALT_NOC_MPU_F2SDR2_AXI32_QOS instance. */
#define ALT_NOC_MPU_F2SDR2_AXI32_QOS_BWDTH_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_F2SDR2_AXI32_QOS_ADDR) + ALT_NOC_MPU_F2SDR2_AXI32_QOS_BWDTH_OFST))
/* The address of the ALT_NOC_MPU_F2SDR2_AXI32_QOS_SAT register for the ALT_NOC_MPU_F2SDR2_AXI32_QOS instance. */
#define ALT_NOC_MPU_F2SDR2_AXI32_QOS_SAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_F2SDR2_AXI32_QOS_ADDR) + ALT_NOC_MPU_F2SDR2_AXI32_QOS_SAT_OFST))
/* The address of the ALT_NOC_MPU_F2SDR2_AXI32_QOS_EXTCTL register for the ALT_NOC_MPU_F2SDR2_AXI32_QOS instance. */
#define ALT_NOC_MPU_F2SDR2_AXI32_QOS_EXTCTL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_F2SDR2_AXI32_QOS_ADDR) + ALT_NOC_MPU_F2SDR2_AXI32_QOS_EXTCTL_OFST))
/* The base address byte offset for the start of the ALT_NOC_MPU_F2SDR2_AXI32_QOS component. */
#define ALT_NOC_MPU_F2SDR2_AXI32_QOS_OFST        0xffd16900
/* The start address of the ALT_NOC_MPU_F2SDR2_AXI32_QOS component. */
#define ALT_NOC_MPU_F2SDR2_AXI32_QOS_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_NOC_MPU_F2SDR2_AXI32_QOS_OFST))
/* The lower bound address range of the ALT_NOC_MPU_F2SDR2_AXI32_QOS component. */
#define ALT_NOC_MPU_F2SDR2_AXI32_QOS_LB_ADDR     ALT_NOC_MPU_F2SDR2_AXI32_QOS_ADDR
/* The upper bound address range of the ALT_NOC_MPU_F2SDR2_AXI32_QOS component. */
#define ALT_NOC_MPU_F2SDR2_AXI32_QOS_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_NOC_MPU_F2SDR2_AXI32_QOS_ADDR) + 0x80) - 1))


/*
 * Component Instance : i_noc_mpu_m0_fpga2sdram2_axi64_I_main_QosGenerator
 * 
 * Instance i_noc_mpu_m0_fpga2sdram2_axi64_I_main_QosGenerator of component ALT_NOC_MPU_F2SDR2_AXI64_QOS.
 * 
 * 
 */
/* The address of the ALT_NOC_MPU_F2SDR2_AXI64_QOS_COREID register for the ALT_NOC_MPU_F2SDR2_AXI64_QOS instance. */
#define ALT_NOC_MPU_F2SDR2_AXI64_QOS_COREID_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_F2SDR2_AXI64_QOS_ADDR) + ALT_NOC_MPU_F2SDR2_AXI64_QOS_COREID_OFST))
/* The address of the ALT_NOC_MPU_F2SDR2_AXI64_QOS_REVID register for the ALT_NOC_MPU_F2SDR2_AXI64_QOS instance. */
#define ALT_NOC_MPU_F2SDR2_AXI64_QOS_REVID_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_F2SDR2_AXI64_QOS_ADDR) + ALT_NOC_MPU_F2SDR2_AXI64_QOS_REVID_OFST))
/* The address of the ALT_NOC_MPU_F2SDR2_AXI64_QOS_PRI register for the ALT_NOC_MPU_F2SDR2_AXI64_QOS instance. */
#define ALT_NOC_MPU_F2SDR2_AXI64_QOS_PRI_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_F2SDR2_AXI64_QOS_ADDR) + ALT_NOC_MPU_F2SDR2_AXI64_QOS_PRI_OFST))
/* The address of the ALT_NOC_MPU_F2SDR2_AXI64_QOS_MOD register for the ALT_NOC_MPU_F2SDR2_AXI64_QOS instance. */
#define ALT_NOC_MPU_F2SDR2_AXI64_QOS_MOD_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_F2SDR2_AXI64_QOS_ADDR) + ALT_NOC_MPU_F2SDR2_AXI64_QOS_MOD_OFST))
/* The address of the ALT_NOC_MPU_F2SDR2_AXI64_QOS_BWDTH register for the ALT_NOC_MPU_F2SDR2_AXI64_QOS instance. */
#define ALT_NOC_MPU_F2SDR2_AXI64_QOS_BWDTH_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_F2SDR2_AXI64_QOS_ADDR) + ALT_NOC_MPU_F2SDR2_AXI64_QOS_BWDTH_OFST))
/* The address of the ALT_NOC_MPU_F2SDR2_AXI64_QOS_SAT register for the ALT_NOC_MPU_F2SDR2_AXI64_QOS instance. */
#define ALT_NOC_MPU_F2SDR2_AXI64_QOS_SAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_F2SDR2_AXI64_QOS_ADDR) + ALT_NOC_MPU_F2SDR2_AXI64_QOS_SAT_OFST))
/* The address of the ALT_NOC_MPU_F2SDR2_AXI64_QOS_EXTCTL register for the ALT_NOC_MPU_F2SDR2_AXI64_QOS instance. */
#define ALT_NOC_MPU_F2SDR2_AXI64_QOS_EXTCTL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_F2SDR2_AXI64_QOS_ADDR) + ALT_NOC_MPU_F2SDR2_AXI64_QOS_EXTCTL_OFST))
/* The base address byte offset for the start of the ALT_NOC_MPU_F2SDR2_AXI64_QOS component. */
#define ALT_NOC_MPU_F2SDR2_AXI64_QOS_OFST        0xffd16980
/* The start address of the ALT_NOC_MPU_F2SDR2_AXI64_QOS component. */
#define ALT_NOC_MPU_F2SDR2_AXI64_QOS_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_NOC_MPU_F2SDR2_AXI64_QOS_OFST))
/* The lower bound address range of the ALT_NOC_MPU_F2SDR2_AXI64_QOS component. */
#define ALT_NOC_MPU_F2SDR2_AXI64_QOS_LB_ADDR     ALT_NOC_MPU_F2SDR2_AXI64_QOS_ADDR
/* The upper bound address range of the ALT_NOC_MPU_F2SDR2_AXI64_QOS component. */
#define ALT_NOC_MPU_F2SDR2_AXI64_QOS_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_NOC_MPU_F2SDR2_AXI64_QOS_ADDR) + 0x80) - 1))


/*
 * Component Instance : i_noc_mpu_m0_fpga2sdram2_axi128_I_main_QosGenerator
 * 
 * Instance i_noc_mpu_m0_fpga2sdram2_axi128_I_main_QosGenerator of component ALT_NOC_MPU_F2SDR2_AXI128_QOS.
 * 
 * 
 */
/* The address of the ALT_NOC_MPU_F2SDR2_AXI128_QOS_COREID register for the ALT_NOC_MPU_F2SDR2_AXI128_QOS instance. */
#define ALT_NOC_MPU_F2SDR2_AXI128_QOS_COREID_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_F2SDR2_AXI128_QOS_ADDR) + ALT_NOC_MPU_F2SDR2_AXI128_QOS_COREID_OFST))
/* The address of the ALT_NOC_MPU_F2SDR2_AXI128_QOS_REVID register for the ALT_NOC_MPU_F2SDR2_AXI128_QOS instance. */
#define ALT_NOC_MPU_F2SDR2_AXI128_QOS_REVID_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_F2SDR2_AXI128_QOS_ADDR) + ALT_NOC_MPU_F2SDR2_AXI128_QOS_REVID_OFST))
/* The address of the ALT_NOC_MPU_F2SDR2_AXI128_QOS_PRI register for the ALT_NOC_MPU_F2SDR2_AXI128_QOS instance. */
#define ALT_NOC_MPU_F2SDR2_AXI128_QOS_PRI_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_F2SDR2_AXI128_QOS_ADDR) + ALT_NOC_MPU_F2SDR2_AXI128_QOS_PRI_OFST))
/* The address of the ALT_NOC_MPU_F2SDR2_AXI128_QOS_MOD register for the ALT_NOC_MPU_F2SDR2_AXI128_QOS instance. */
#define ALT_NOC_MPU_F2SDR2_AXI128_QOS_MOD_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_F2SDR2_AXI128_QOS_ADDR) + ALT_NOC_MPU_F2SDR2_AXI128_QOS_MOD_OFST))
/* The address of the ALT_NOC_MPU_F2SDR2_AXI128_QOS_BWDTH register for the ALT_NOC_MPU_F2SDR2_AXI128_QOS instance. */
#define ALT_NOC_MPU_F2SDR2_AXI128_QOS_BWDTH_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_F2SDR2_AXI128_QOS_ADDR) + ALT_NOC_MPU_F2SDR2_AXI128_QOS_BWDTH_OFST))
/* The address of the ALT_NOC_MPU_F2SDR2_AXI128_QOS_SAT register for the ALT_NOC_MPU_F2SDR2_AXI128_QOS instance. */
#define ALT_NOC_MPU_F2SDR2_AXI128_QOS_SAT_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_F2SDR2_AXI128_QOS_ADDR) + ALT_NOC_MPU_F2SDR2_AXI128_QOS_SAT_OFST))
/* The address of the ALT_NOC_MPU_F2SDR2_AXI128_QOS_EXTCTL register for the ALT_NOC_MPU_F2SDR2_AXI128_QOS instance. */
#define ALT_NOC_MPU_F2SDR2_AXI128_QOS_EXTCTL_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_F2SDR2_AXI128_QOS_ADDR) + ALT_NOC_MPU_F2SDR2_AXI128_QOS_EXTCTL_OFST))
/* The base address byte offset for the start of the ALT_NOC_MPU_F2SDR2_AXI128_QOS component. */
#define ALT_NOC_MPU_F2SDR2_AXI128_QOS_OFST        0xffd17000
/* The start address of the ALT_NOC_MPU_F2SDR2_AXI128_QOS component. */
#define ALT_NOC_MPU_F2SDR2_AXI128_QOS_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_NOC_MPU_F2SDR2_AXI128_QOS_OFST))
/* The lower bound address range of the ALT_NOC_MPU_F2SDR2_AXI128_QOS component. */
#define ALT_NOC_MPU_F2SDR2_AXI128_QOS_LB_ADDR     ALT_NOC_MPU_F2SDR2_AXI128_QOS_ADDR
/* The upper bound address range of the ALT_NOC_MPU_F2SDR2_AXI128_QOS component. */
#define ALT_NOC_MPU_F2SDR2_AXI128_QOS_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_NOC_MPU_F2SDR2_AXI128_QOS_ADDR) + 0x80) - 1))


/*
 * Component Instance : i_noc_mpu_m0_emac0_m_I_main_TransactionStatFilter
 * 
 * Instance i_noc_mpu_m0_emac0_m_I_main_TransactionStatFilter of component ALT_NOC_MPU_EMAC0_M_XACTSTATFLT.
 * 
 * 
 */
/* The address of the ALT_NOC_MPU_EMAC0_M_XACTSTATFLT_COREID register for the ALT_NOC_MPU_EMAC0_M_XACTSTATFLT instance. */
#define ALT_NOC_MPU_EMAC0_M_XACTSTATFLT_COREID_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_EMAC0_M_XACTSTATFLT_ADDR) + ALT_NOC_MPU_EMAC0_M_XACTSTATFLT_COREID_OFST))
/* The address of the ALT_NOC_MPU_EMAC0_M_XACTSTATFLT_REVID register for the ALT_NOC_MPU_EMAC0_M_XACTSTATFLT instance. */
#define ALT_NOC_MPU_EMAC0_M_XACTSTATFLT_REVID_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_EMAC0_M_XACTSTATFLT_ADDR) + ALT_NOC_MPU_EMAC0_M_XACTSTATFLT_REVID_OFST))
/* The address of the ALT_NOC_MPU_EMAC0_M_XACTSTATFLT_MOD register for the ALT_NOC_MPU_EMAC0_M_XACTSTATFLT instance. */
#define ALT_NOC_MPU_EMAC0_M_XACTSTATFLT_MOD_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_EMAC0_M_XACTSTATFLT_ADDR) + ALT_NOC_MPU_EMAC0_M_XACTSTATFLT_MOD_OFST))
/* The address of the ALT_NOC_MPU_EMAC0_M_XACTSTATFLT_ADDRBASE_LOW register for the ALT_NOC_MPU_EMAC0_M_XACTSTATFLT instance. */
#define ALT_NOC_MPU_EMAC0_M_XACTSTATFLT_ADDRBASE_LOW_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_EMAC0_M_XACTSTATFLT_ADDR) + ALT_NOC_MPU_EMAC0_M_XACTSTATFLT_ADDRBASE_LOW_OFST))
/* The address of the ALT_NOC_MPU_EMAC0_M_XACTSTATFLT_ADDRBASE_HIGH register for the ALT_NOC_MPU_EMAC0_M_XACTSTATFLT instance. */
#define ALT_NOC_MPU_EMAC0_M_XACTSTATFLT_ADDRBASE_HIGH_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_EMAC0_M_XACTSTATFLT_ADDR) + ALT_NOC_MPU_EMAC0_M_XACTSTATFLT_ADDRBASE_HIGH_OFST))
/* The address of the ALT_NOC_MPU_EMAC0_M_XACTSTATFLT_ADDRWINDOWSIZE register for the ALT_NOC_MPU_EMAC0_M_XACTSTATFLT instance. */
#define ALT_NOC_MPU_EMAC0_M_XACTSTATFLT_ADDRWINDOWSIZE_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_EMAC0_M_XACTSTATFLT_ADDR) + ALT_NOC_MPU_EMAC0_M_XACTSTATFLT_ADDRWINDOWSIZE_OFST))
/* The address of the ALT_NOC_MPU_EMAC0_M_XACTSTATFLT_OPCODE register for the ALT_NOC_MPU_EMAC0_M_XACTSTATFLT instance. */
#define ALT_NOC_MPU_EMAC0_M_XACTSTATFLT_OPCODE_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_EMAC0_M_XACTSTATFLT_ADDR) + ALT_NOC_MPU_EMAC0_M_XACTSTATFLT_OPCODE_OFST))
/* The address of the ALT_NOC_MPU_EMAC0_M_XACTSTATFLT_USERBASE register for the ALT_NOC_MPU_EMAC0_M_XACTSTATFLT instance. */
#define ALT_NOC_MPU_EMAC0_M_XACTSTATFLT_USERBASE_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_EMAC0_M_XACTSTATFLT_ADDR) + ALT_NOC_MPU_EMAC0_M_XACTSTATFLT_USERBASE_OFST))
/* The address of the ALT_NOC_MPU_EMAC0_M_XACTSTATFLT_USERMSK register for the ALT_NOC_MPU_EMAC0_M_XACTSTATFLT instance. */
#define ALT_NOC_MPU_EMAC0_M_XACTSTATFLT_USERMSK_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_EMAC0_M_XACTSTATFLT_ADDR) + ALT_NOC_MPU_EMAC0_M_XACTSTATFLT_USERMSK_OFST))
/* The address of the ALT_NOC_MPU_EMAC0_M_XACTSTATFLT_SECURITYBASE register for the ALT_NOC_MPU_EMAC0_M_XACTSTATFLT instance. */
#define ALT_NOC_MPU_EMAC0_M_XACTSTATFLT_SECURITYBASE_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_EMAC0_M_XACTSTATFLT_ADDR) + ALT_NOC_MPU_EMAC0_M_XACTSTATFLT_SECURITYBASE_OFST))
/* The address of the ALT_NOC_MPU_EMAC0_M_XACTSTATFLT_SECURITYMSK register for the ALT_NOC_MPU_EMAC0_M_XACTSTATFLT instance. */
#define ALT_NOC_MPU_EMAC0_M_XACTSTATFLT_SECURITYMSK_ADDR  ALT_CAST(void *, (ALT_CAST(char *, ALT_NOC_MPU_EMAC0_M_XACTSTATFLT_ADDR) + ALT_NOC_MPU_EMAC0_M_XACTSTATFLT_SECURITYMSK_OFST))
/* The base address byte offset for the start of the ALT_NOC_MPU_EMAC0_M_XACTSTATFLT component. */
#define ALT_NOC_MPU_EMAC0_M_XACTSTATFLT_OFST        0xffd17080
/* The start address of the ALT_NOC_MPU_EMAC0_M_XACTSTATFLT component. */
#define ALT_NOC_MPU_EMAC0_M_XACTSTATFLT_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_NOC_MPU_EMAC0_M_XACTSTATFLT_OFST))
/* The lower bound address range of the ALT_NOC_MPU_EMAC0_M_XACTSTATFLT component. */
#define ALT_NOC_MPU_EMAC0_M_XACTSTATFLT_LB_ADDR     ALT_NOC_MPU_EMAC0_M_XACTSTATFLT_ADDR
/* The upper bound address range of the ALT_NOC_MPU_EMAC0_M_XACTSTATFLT component. */
#define ALT_NOC_MPU_EMAC0_M_XACTSTATFLT_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_NOC_MPU_EMAC0_M_XACTSTATFLT_ADDR) + 0x80) - 1))


/*
 * Component Instance : i_dma_NSCONTROL
 * 
 * Instance i_dma_NSCONTROL of component ALT_DMA_NSCTL.
 * 
 * 
 */
/* The base address byte offset for the start of the ALT_DMA_NSCTL component. */
#define ALT_DMA_NSCTL_OFST        0xffda0000
/* The start address of the ALT_DMA_NSCTL component. */
#define ALT_DMA_NSCTL_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_DMA_NSCTL_OFST))
/* The lower bound address range of the ALT_DMA_NSCTL component. */
#define ALT_DMA_NSCTL_LB_ADDR     ALT_DMA_NSCTL_ADDR
/* The upper bound address range of the ALT_DMA_NSCTL component. */
#define ALT_DMA_NSCTL_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_DMA_NSCTL_ADDR) + 0x60) - 1))


/*
 * Component Instance : i_dma_NSCHANNELSTATUS
 * 
 * Instance i_dma_NSCHANNELSTATUS of component ALT_DMA_NSCHANNELSTAT.
 * 
 * 
 */
/* The base address byte offset for the start of the ALT_DMA_NSCHANNELSTAT component. */
#define ALT_DMA_NSCHANNELSTAT_OFST        0xffda0100
/* The start address of the ALT_DMA_NSCHANNELSTAT component. */
#define ALT_DMA_NSCHANNELSTAT_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_DMA_NSCHANNELSTAT_OFST))
/* The lower bound address range of the ALT_DMA_NSCHANNELSTAT component. */
#define ALT_DMA_NSCHANNELSTAT_LB_ADDR     ALT_DMA_NSCHANNELSTAT_ADDR
/* The upper bound address range of the ALT_DMA_NSCHANNELSTAT component. */
#define ALT_DMA_NSCHANNELSTAT_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_DMA_NSCHANNELSTAT_ADDR) + 0x40) - 1))


/*
 * Component Instance : i_dma_NSAXISTATUS
 * 
 * Instance i_dma_NSAXISTATUS of component ALT_DMA_NSAXISTAT.
 * 
 * 
 */
/* The base address byte offset for the start of the ALT_DMA_NSAXISTAT component. */
#define ALT_DMA_NSAXISTAT_OFST        0xffda0400
/* The start address of the ALT_DMA_NSAXISTAT component. */
#define ALT_DMA_NSAXISTAT_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_DMA_NSAXISTAT_OFST))
/* The lower bound address range of the ALT_DMA_NSAXISTAT component. */
#define ALT_DMA_NSAXISTAT_LB_ADDR     ALT_DMA_NSAXISTAT_ADDR
/* The upper bound address range of the ALT_DMA_NSAXISTAT component. */
#define ALT_DMA_NSAXISTAT_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_DMA_NSAXISTAT_ADDR) + 0x100) - 1))


/*
 * Component Instance : i_dma_NSDEBUG
 * 
 * Instance i_dma_NSDEBUG of component ALT_DMA_NSDBG.
 * 
 * 
 */
/* The base address byte offset for the start of the ALT_DMA_NSDBG component. */
#define ALT_DMA_NSDBG_OFST        0xffda0d00
/* The start address of the ALT_DMA_NSDBG component. */
#define ALT_DMA_NSDBG_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_DMA_NSDBG_OFST))
/* The lower bound address range of the ALT_DMA_NSDBG component. */
#define ALT_DMA_NSDBG_LB_ADDR     ALT_DMA_NSDBG_ADDR
/* The upper bound address range of the ALT_DMA_NSDBG component. */
#define ALT_DMA_NSDBG_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_DMA_NSDBG_ADDR) + 0x10) - 1))


/*
 * Component Instance : i_dma_NSCONFIG
 * 
 * Instance i_dma_NSCONFIG of component ALT_DMA_NSCFG.
 * 
 * 
 */
/* The base address byte offset for the start of the ALT_DMA_NSCFG component. */
#define ALT_DMA_NSCFG_OFST        0xffda0e00
/* The start address of the ALT_DMA_NSCFG component. */
#define ALT_DMA_NSCFG_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_DMA_NSCFG_OFST))
/* The lower bound address range of the ALT_DMA_NSCFG component. */
#define ALT_DMA_NSCFG_LB_ADDR     ALT_DMA_NSCFG_ADDR
/* The upper bound address range of the ALT_DMA_NSCFG component. */
#define ALT_DMA_NSCFG_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_DMA_NSCFG_ADDR) + 0x20) - 1))


/*
 * Component Instance : i_dma_NSCOMPID
 * 
 * Instance i_dma_NSCOMPID of component ALT_DMA_NSCOMPID.
 * 
 * 
 */
/* The base address byte offset for the start of the ALT_DMA_NSCOMPID component. */
#define ALT_DMA_NSCOMPID_OFST        0xffda0fe0
/* The start address of the ALT_DMA_NSCOMPID component. */
#define ALT_DMA_NSCOMPID_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_DMA_NSCOMPID_OFST))
/* The lower bound address range of the ALT_DMA_NSCOMPID component. */
#define ALT_DMA_NSCOMPID_LB_ADDR     ALT_DMA_NSCOMPID_ADDR
/* The upper bound address range of the ALT_DMA_NSCOMPID component. */
#define ALT_DMA_NSCOMPID_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_DMA_NSCOMPID_ADDR) + 0x20) - 1))


/*
 * Component Instance : i_dma_SCONTROL
 * 
 * Instance i_dma_SCONTROL of component ALT_DMA_SCTL.
 * 
 * 
 */
/* The base address byte offset for the start of the ALT_DMA_SCTL component. */
#define ALT_DMA_SCTL_OFST        0xffda1000
/* The start address of the ALT_DMA_SCTL component. */
#define ALT_DMA_SCTL_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_DMA_SCTL_OFST))
/* The lower bound address range of the ALT_DMA_SCTL component. */
#define ALT_DMA_SCTL_LB_ADDR     ALT_DMA_SCTL_ADDR
/* The upper bound address range of the ALT_DMA_SCTL component. */
#define ALT_DMA_SCTL_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_DMA_SCTL_ADDR) + 0x60) - 1))


/*
 * Component Instance : i_dma_SCHANNELSTATUS
 * 
 * Instance i_dma_SCHANNELSTATUS of component ALT_DMA_SCHANNELSTAT.
 * 
 * 
 */
/* The base address byte offset for the start of the ALT_DMA_SCHANNELSTAT component. */
#define ALT_DMA_SCHANNELSTAT_OFST        0xffda1100
/* The start address of the ALT_DMA_SCHANNELSTAT component. */
#define ALT_DMA_SCHANNELSTAT_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_DMA_SCHANNELSTAT_OFST))
/* The lower bound address range of the ALT_DMA_SCHANNELSTAT component. */
#define ALT_DMA_SCHANNELSTAT_LB_ADDR     ALT_DMA_SCHANNELSTAT_ADDR
/* The upper bound address range of the ALT_DMA_SCHANNELSTAT component. */
#define ALT_DMA_SCHANNELSTAT_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_DMA_SCHANNELSTAT_ADDR) + 0x40) - 1))


/*
 * Component Instance : i_dma_SAXISTATUS
 * 
 * Instance i_dma_SAXISTATUS of component ALT_DMA_SAXISTAT.
 * 
 * 
 */
/* The base address byte offset for the start of the ALT_DMA_SAXISTAT component. */
#define ALT_DMA_SAXISTAT_OFST        0xffda1400
/* The start address of the ALT_DMA_SAXISTAT component. */
#define ALT_DMA_SAXISTAT_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_DMA_SAXISTAT_OFST))
/* The lower bound address range of the ALT_DMA_SAXISTAT component. */
#define ALT_DMA_SAXISTAT_LB_ADDR     ALT_DMA_SAXISTAT_ADDR
/* The upper bound address range of the ALT_DMA_SAXISTAT component. */
#define ALT_DMA_SAXISTAT_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_DMA_SAXISTAT_ADDR) + 0x100) - 1))


/*
 * Component Instance : i_dma_SDEBUG
 * 
 * Instance i_dma_SDEBUG of component ALT_DMA_SDBG.
 * 
 * 
 */
/* The base address byte offset for the start of the ALT_DMA_SDBG component. */
#define ALT_DMA_SDBG_OFST        0xffda1d00
/* The start address of the ALT_DMA_SDBG component. */
#define ALT_DMA_SDBG_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_DMA_SDBG_OFST))
/* The lower bound address range of the ALT_DMA_SDBG component. */
#define ALT_DMA_SDBG_LB_ADDR     ALT_DMA_SDBG_ADDR
/* The upper bound address range of the ALT_DMA_SDBG component. */
#define ALT_DMA_SDBG_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_DMA_SDBG_ADDR) + 0x10) - 1))


/*
 * Component Instance : i_dma_SCONFIG
 * 
 * Instance i_dma_SCONFIG of component ALT_DMA_SCFG.
 * 
 * 
 */
/* The base address byte offset for the start of the ALT_DMA_SCFG component. */
#define ALT_DMA_SCFG_OFST        0xffda1e00
/* The start address of the ALT_DMA_SCFG component. */
#define ALT_DMA_SCFG_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_DMA_SCFG_OFST))
/* The lower bound address range of the ALT_DMA_SCFG component. */
#define ALT_DMA_SCFG_LB_ADDR     ALT_DMA_SCFG_ADDR
/* The upper bound address range of the ALT_DMA_SCFG component. */
#define ALT_DMA_SCFG_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_DMA_SCFG_ADDR) + 0x20) - 1))


/*
 * Component Instance : i_dma_SCOMPID
 * 
 * Instance i_dma_SCOMPID of component ALT_DMA_SCOMPID.
 * 
 * 
 */
/* The base address byte offset for the start of the ALT_DMA_SCOMPID component. */
#define ALT_DMA_SCOMPID_OFST        0xffda1fe0
/* The start address of the ALT_DMA_SCOMPID component. */
#define ALT_DMA_SCOMPID_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_DMA_SCOMPID_OFST))
/* The lower bound address range of the ALT_DMA_SCOMPID component. */
#define ALT_DMA_SCOMPID_LB_ADDR     ALT_DMA_SCOMPID_ADDR
/* The upper bound address range of the ALT_DMA_SCOMPID component. */
#define ALT_DMA_SCOMPID_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_DMA_SCOMPID_ADDR) + 0x20) - 1))


/*
 * Component Instance : i_spis_0_spis
 * 
 * Instance i_spis_0_spis of component ALT_SPIS.
 * 
 * 
 */
/* The address of the ALT_SPIS_CTLR0 register for the ALT_SPIS0 instance. */
#define ALT_SPIS0_CTLR0_ADDR  ALT_SPIS_CTLR0_ADDR(ALT_SPIS0_ADDR)
/* The address of the ALT_SPIS_SPIENR register for the ALT_SPIS0 instance. */
#define ALT_SPIS0_SPIENR_ADDR  ALT_SPIS_SPIENR_ADDR(ALT_SPIS0_ADDR)
/* The address of the ALT_SPIS_MWCR register for the ALT_SPIS0 instance. */
#define ALT_SPIS0_MWCR_ADDR  ALT_SPIS_MWCR_ADDR(ALT_SPIS0_ADDR)
/* The address of the ALT_SPIS_TXFTLR register for the ALT_SPIS0 instance. */
#define ALT_SPIS0_TXFTLR_ADDR  ALT_SPIS_TXFTLR_ADDR(ALT_SPIS0_ADDR)
/* The address of the ALT_SPIS_RXFTLR register for the ALT_SPIS0 instance. */
#define ALT_SPIS0_RXFTLR_ADDR  ALT_SPIS_RXFTLR_ADDR(ALT_SPIS0_ADDR)
/* The address of the ALT_SPIS_TXFLR register for the ALT_SPIS0 instance. */
#define ALT_SPIS0_TXFLR_ADDR  ALT_SPIS_TXFLR_ADDR(ALT_SPIS0_ADDR)
/* The address of the ALT_SPIS_RXFLR register for the ALT_SPIS0 instance. */
#define ALT_SPIS0_RXFLR_ADDR  ALT_SPIS_RXFLR_ADDR(ALT_SPIS0_ADDR)
/* The address of the ALT_SPIS_SR register for the ALT_SPIS0 instance. */
#define ALT_SPIS0_SR_ADDR  ALT_SPIS_SR_ADDR(ALT_SPIS0_ADDR)
/* The address of the ALT_SPIS_IMR register for the ALT_SPIS0 instance. */
#define ALT_SPIS0_IMR_ADDR  ALT_SPIS_IMR_ADDR(ALT_SPIS0_ADDR)
/* The address of the ALT_SPIS_ISR register for the ALT_SPIS0 instance. */
#define ALT_SPIS0_ISR_ADDR  ALT_SPIS_ISR_ADDR(ALT_SPIS0_ADDR)
/* The address of the ALT_SPIS_RISR register for the ALT_SPIS0 instance. */
#define ALT_SPIS0_RISR_ADDR  ALT_SPIS_RISR_ADDR(ALT_SPIS0_ADDR)
/* The address of the ALT_SPIS_TXOICR register for the ALT_SPIS0 instance. */
#define ALT_SPIS0_TXOICR_ADDR  ALT_SPIS_TXOICR_ADDR(ALT_SPIS0_ADDR)
/* The address of the ALT_SPIS_RXOICR register for the ALT_SPIS0 instance. */
#define ALT_SPIS0_RXOICR_ADDR  ALT_SPIS_RXOICR_ADDR(ALT_SPIS0_ADDR)
/* The address of the ALT_SPIS_RXUICR register for the ALT_SPIS0 instance. */
#define ALT_SPIS0_RXUICR_ADDR  ALT_SPIS_RXUICR_ADDR(ALT_SPIS0_ADDR)
/* The address of the ALT_SPIS_MSTICR register for the ALT_SPIS0 instance. */
#define ALT_SPIS0_MSTICR_ADDR  ALT_SPIS_MSTICR_ADDR(ALT_SPIS0_ADDR)
/* The address of the ALT_SPIS_ICR register for the ALT_SPIS0 instance. */
#define ALT_SPIS0_ICR_ADDR  ALT_SPIS_ICR_ADDR(ALT_SPIS0_ADDR)
/* The address of the ALT_SPIS_DMACR register for the ALT_SPIS0 instance. */
#define ALT_SPIS0_DMACR_ADDR  ALT_SPIS_DMACR_ADDR(ALT_SPIS0_ADDR)
/* The address of the ALT_SPIS_DMATDLR register for the ALT_SPIS0 instance. */
#define ALT_SPIS0_DMATDLR_ADDR  ALT_SPIS_DMATDLR_ADDR(ALT_SPIS0_ADDR)
/* The address of the ALT_SPIS_DMARDLR register for the ALT_SPIS0 instance. */
#define ALT_SPIS0_DMARDLR_ADDR  ALT_SPIS_DMARDLR_ADDR(ALT_SPIS0_ADDR)
/* The address of the ALT_SPIS_IDR register for the ALT_SPIS0 instance. */
#define ALT_SPIS0_IDR_ADDR  ALT_SPIS_IDR_ADDR(ALT_SPIS0_ADDR)
/* The address of the ALT_SPIS_SPI_VER_ID register for the ALT_SPIS0 instance. */
#define ALT_SPIS0_SPI_VER_ID_ADDR  ALT_SPIS_SPI_VER_ID_ADDR(ALT_SPIS0_ADDR)
/* The address of the ALT_SPIS_DR register for the ALT_SPIS0 instance. */
#define ALT_SPIS0_DR_ADDR  ALT_SPIS_DR_ADDR(ALT_SPIS0_ADDR)
/* The base address byte offset for the start of the ALT_SPIS0 component. */
#define ALT_SPIS0_OFST        0xffda2000
/* The start address of the ALT_SPIS0 component. */
#define ALT_SPIS0_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_SPIS0_OFST))
/* The lower bound address range of the ALT_SPIS0 component. */
#define ALT_SPIS0_LB_ADDR     ALT_SPIS0_ADDR
/* The upper bound address range of the ALT_SPIS0 component. */
#define ALT_SPIS0_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_SPIS0_ADDR) + 0x80) - 1))


/*
 * Component Instance : i_spis_1_spis
 * 
 * Instance i_spis_1_spis of component ALT_SPIS.
 * 
 * 
 */
/* The address of the ALT_SPIS_CTLR0 register for the ALT_SPIS1 instance. */
#define ALT_SPIS1_CTLR0_ADDR  ALT_SPIS_CTLR0_ADDR(ALT_SPIS1_ADDR)
/* The address of the ALT_SPIS_SPIENR register for the ALT_SPIS1 instance. */
#define ALT_SPIS1_SPIENR_ADDR  ALT_SPIS_SPIENR_ADDR(ALT_SPIS1_ADDR)
/* The address of the ALT_SPIS_MWCR register for the ALT_SPIS1 instance. */
#define ALT_SPIS1_MWCR_ADDR  ALT_SPIS_MWCR_ADDR(ALT_SPIS1_ADDR)
/* The address of the ALT_SPIS_TXFTLR register for the ALT_SPIS1 instance. */
#define ALT_SPIS1_TXFTLR_ADDR  ALT_SPIS_TXFTLR_ADDR(ALT_SPIS1_ADDR)
/* The address of the ALT_SPIS_RXFTLR register for the ALT_SPIS1 instance. */
#define ALT_SPIS1_RXFTLR_ADDR  ALT_SPIS_RXFTLR_ADDR(ALT_SPIS1_ADDR)
/* The address of the ALT_SPIS_TXFLR register for the ALT_SPIS1 instance. */
#define ALT_SPIS1_TXFLR_ADDR  ALT_SPIS_TXFLR_ADDR(ALT_SPIS1_ADDR)
/* The address of the ALT_SPIS_RXFLR register for the ALT_SPIS1 instance. */
#define ALT_SPIS1_RXFLR_ADDR  ALT_SPIS_RXFLR_ADDR(ALT_SPIS1_ADDR)
/* The address of the ALT_SPIS_SR register for the ALT_SPIS1 instance. */
#define ALT_SPIS1_SR_ADDR  ALT_SPIS_SR_ADDR(ALT_SPIS1_ADDR)
/* The address of the ALT_SPIS_IMR register for the ALT_SPIS1 instance. */
#define ALT_SPIS1_IMR_ADDR  ALT_SPIS_IMR_ADDR(ALT_SPIS1_ADDR)
/* The address of the ALT_SPIS_ISR register for the ALT_SPIS1 instance. */
#define ALT_SPIS1_ISR_ADDR  ALT_SPIS_ISR_ADDR(ALT_SPIS1_ADDR)
/* The address of the ALT_SPIS_RISR register for the ALT_SPIS1 instance. */
#define ALT_SPIS1_RISR_ADDR  ALT_SPIS_RISR_ADDR(ALT_SPIS1_ADDR)
/* The address of the ALT_SPIS_TXOICR register for the ALT_SPIS1 instance. */
#define ALT_SPIS1_TXOICR_ADDR  ALT_SPIS_TXOICR_ADDR(ALT_SPIS1_ADDR)
/* The address of the ALT_SPIS_RXOICR register for the ALT_SPIS1 instance. */
#define ALT_SPIS1_RXOICR_ADDR  ALT_SPIS_RXOICR_ADDR(ALT_SPIS1_ADDR)
/* The address of the ALT_SPIS_RXUICR register for the ALT_SPIS1 instance. */
#define ALT_SPIS1_RXUICR_ADDR  ALT_SPIS_RXUICR_ADDR(ALT_SPIS1_ADDR)
/* The address of the ALT_SPIS_MSTICR register for the ALT_SPIS1 instance. */
#define ALT_SPIS1_MSTICR_ADDR  ALT_SPIS_MSTICR_ADDR(ALT_SPIS1_ADDR)
/* The address of the ALT_SPIS_ICR register for the ALT_SPIS1 instance. */
#define ALT_SPIS1_ICR_ADDR  ALT_SPIS_ICR_ADDR(ALT_SPIS1_ADDR)
/* The address of the ALT_SPIS_DMACR register for the ALT_SPIS1 instance. */
#define ALT_SPIS1_DMACR_ADDR  ALT_SPIS_DMACR_ADDR(ALT_SPIS1_ADDR)
/* The address of the ALT_SPIS_DMATDLR register for the ALT_SPIS1 instance. */
#define ALT_SPIS1_DMATDLR_ADDR  ALT_SPIS_DMATDLR_ADDR(ALT_SPIS1_ADDR)
/* The address of the ALT_SPIS_DMARDLR register for the ALT_SPIS1 instance. */
#define ALT_SPIS1_DMARDLR_ADDR  ALT_SPIS_DMARDLR_ADDR(ALT_SPIS1_ADDR)
/* The address of the ALT_SPIS_IDR register for the ALT_SPIS1 instance. */
#define ALT_SPIS1_IDR_ADDR  ALT_SPIS_IDR_ADDR(ALT_SPIS1_ADDR)
/* The address of the ALT_SPIS_SPI_VER_ID register for the ALT_SPIS1 instance. */
#define ALT_SPIS1_SPI_VER_ID_ADDR  ALT_SPIS_SPI_VER_ID_ADDR(ALT_SPIS1_ADDR)
/* The address of the ALT_SPIS_DR register for the ALT_SPIS1 instance. */
#define ALT_SPIS1_DR_ADDR  ALT_SPIS_DR_ADDR(ALT_SPIS1_ADDR)
/* The base address byte offset for the start of the ALT_SPIS1 component. */
#define ALT_SPIS1_OFST        0xffda3000
/* The start address of the ALT_SPIS1 component. */
#define ALT_SPIS1_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_SPIS1_OFST))
/* The lower bound address range of the ALT_SPIS1 component. */
#define ALT_SPIS1_LB_ADDR     ALT_SPIS1_ADDR
/* The upper bound address range of the ALT_SPIS1 component. */
#define ALT_SPIS1_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_SPIS1_ADDR) + 0x80) - 1))


/*
 * Component Instance : i_spim_0_spim
 * 
 * Instance i_spim_0_spim of component ALT_SPIM.
 * 
 * 
 */
/* The address of the ALT_SPIM_CTLR0 register for the ALT_SPIM0 instance. */
#define ALT_SPIM0_CTLR0_ADDR  ALT_SPIM_CTLR0_ADDR(ALT_SPIM0_ADDR)
/* The address of the ALT_SPIM_CTLR1 register for the ALT_SPIM0 instance. */
#define ALT_SPIM0_CTLR1_ADDR  ALT_SPIM_CTLR1_ADDR(ALT_SPIM0_ADDR)
/* The address of the ALT_SPIM_SPIENR register for the ALT_SPIM0 instance. */
#define ALT_SPIM0_SPIENR_ADDR  ALT_SPIM_SPIENR_ADDR(ALT_SPIM0_ADDR)
/* The address of the ALT_SPIM_MWCR register for the ALT_SPIM0 instance. */
#define ALT_SPIM0_MWCR_ADDR  ALT_SPIM_MWCR_ADDR(ALT_SPIM0_ADDR)
/* The address of the ALT_SPIM_SER register for the ALT_SPIM0 instance. */
#define ALT_SPIM0_SER_ADDR  ALT_SPIM_SER_ADDR(ALT_SPIM0_ADDR)
/* The address of the ALT_SPIM_BAUDR register for the ALT_SPIM0 instance. */
#define ALT_SPIM0_BAUDR_ADDR  ALT_SPIM_BAUDR_ADDR(ALT_SPIM0_ADDR)
/* The address of the ALT_SPIM_TXFTLR register for the ALT_SPIM0 instance. */
#define ALT_SPIM0_TXFTLR_ADDR  ALT_SPIM_TXFTLR_ADDR(ALT_SPIM0_ADDR)
/* The address of the ALT_SPIM_RXFTLR register for the ALT_SPIM0 instance. */
#define ALT_SPIM0_RXFTLR_ADDR  ALT_SPIM_RXFTLR_ADDR(ALT_SPIM0_ADDR)
/* The address of the ALT_SPIM_TXFLR register for the ALT_SPIM0 instance. */
#define ALT_SPIM0_TXFLR_ADDR  ALT_SPIM_TXFLR_ADDR(ALT_SPIM0_ADDR)
/* The address of the ALT_SPIM_RXFLR register for the ALT_SPIM0 instance. */
#define ALT_SPIM0_RXFLR_ADDR  ALT_SPIM_RXFLR_ADDR(ALT_SPIM0_ADDR)
/* The address of the ALT_SPIM_SR register for the ALT_SPIM0 instance. */
#define ALT_SPIM0_SR_ADDR  ALT_SPIM_SR_ADDR(ALT_SPIM0_ADDR)
/* The address of the ALT_SPIM_IMR register for the ALT_SPIM0 instance. */
#define ALT_SPIM0_IMR_ADDR  ALT_SPIM_IMR_ADDR(ALT_SPIM0_ADDR)
/* The address of the ALT_SPIM_ISR register for the ALT_SPIM0 instance. */
#define ALT_SPIM0_ISR_ADDR  ALT_SPIM_ISR_ADDR(ALT_SPIM0_ADDR)
/* The address of the ALT_SPIM_RISR register for the ALT_SPIM0 instance. */
#define ALT_SPIM0_RISR_ADDR  ALT_SPIM_RISR_ADDR(ALT_SPIM0_ADDR)
/* The address of the ALT_SPIM_TXOICR register for the ALT_SPIM0 instance. */
#define ALT_SPIM0_TXOICR_ADDR  ALT_SPIM_TXOICR_ADDR(ALT_SPIM0_ADDR)
/* The address of the ALT_SPIM_RXOICR register for the ALT_SPIM0 instance. */
#define ALT_SPIM0_RXOICR_ADDR  ALT_SPIM_RXOICR_ADDR(ALT_SPIM0_ADDR)
/* The address of the ALT_SPIM_RXUICR register for the ALT_SPIM0 instance. */
#define ALT_SPIM0_RXUICR_ADDR  ALT_SPIM_RXUICR_ADDR(ALT_SPIM0_ADDR)
/* The address of the ALT_SPIM_MSTICR register for the ALT_SPIM0 instance. */
#define ALT_SPIM0_MSTICR_ADDR  ALT_SPIM_MSTICR_ADDR(ALT_SPIM0_ADDR)
/* The address of the ALT_SPIM_ICR register for the ALT_SPIM0 instance. */
#define ALT_SPIM0_ICR_ADDR  ALT_SPIM_ICR_ADDR(ALT_SPIM0_ADDR)
/* The address of the ALT_SPIM_DMACR register for the ALT_SPIM0 instance. */
#define ALT_SPIM0_DMACR_ADDR  ALT_SPIM_DMACR_ADDR(ALT_SPIM0_ADDR)
/* The address of the ALT_SPIM_DMATDLR register for the ALT_SPIM0 instance. */
#define ALT_SPIM0_DMATDLR_ADDR  ALT_SPIM_DMATDLR_ADDR(ALT_SPIM0_ADDR)
/* The address of the ALT_SPIM_DMARDLR register for the ALT_SPIM0 instance. */
#define ALT_SPIM0_DMARDLR_ADDR  ALT_SPIM_DMARDLR_ADDR(ALT_SPIM0_ADDR)
/* The address of the ALT_SPIM_IDR register for the ALT_SPIM0 instance. */
#define ALT_SPIM0_IDR_ADDR  ALT_SPIM_IDR_ADDR(ALT_SPIM0_ADDR)
/* The address of the ALT_SPIM_SPI_VER_ID register for the ALT_SPIM0 instance. */
#define ALT_SPIM0_SPI_VER_ID_ADDR  ALT_SPIM_SPI_VER_ID_ADDR(ALT_SPIM0_ADDR)
/* The address of the ALT_SPIM_DR register for the ALT_SPIM0 instance. */
#define ALT_SPIM0_DR_ADDR  ALT_SPIM_DR_ADDR(ALT_SPIM0_ADDR)
/* The address of the ALT_SPIM_RX_SMPL_DLY register for the ALT_SPIM0 instance. */
#define ALT_SPIM0_RX_SMPL_DLY_ADDR  ALT_SPIM_RX_SMPL_DLY_ADDR(ALT_SPIM0_ADDR)
/* The address of the ALT_SPIM_RSVD_0 register for the ALT_SPIM0 instance. */
#define ALT_SPIM0_RSVD_0_ADDR  ALT_SPIM_RSVD_0_ADDR(ALT_SPIM0_ADDR)
/* The address of the ALT_SPIM_RSVD_1 register for the ALT_SPIM0 instance. */
#define ALT_SPIM0_RSVD_1_ADDR  ALT_SPIM_RSVD_1_ADDR(ALT_SPIM0_ADDR)
/* The address of the ALT_SPIM_RSVD_2 register for the ALT_SPIM0 instance. */
#define ALT_SPIM0_RSVD_2_ADDR  ALT_SPIM_RSVD_2_ADDR(ALT_SPIM0_ADDR)
/* The base address byte offset for the start of the ALT_SPIM0 component. */
#define ALT_SPIM0_OFST        0xffda4000
/* The start address of the ALT_SPIM0 component. */
#define ALT_SPIM0_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_SPIM0_OFST))
/* The lower bound address range of the ALT_SPIM0 component. */
#define ALT_SPIM0_LB_ADDR     ALT_SPIM0_ADDR
/* The upper bound address range of the ALT_SPIM0 component. */
#define ALT_SPIM0_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_SPIM0_ADDR) + 0x100) - 1))


/*
 * Component Instance : i_spim_1_spim
 * 
 * Instance i_spim_1_spim of component ALT_SPIM.
 * 
 * 
 */
/* The address of the ALT_SPIM_CTLR0 register for the ALT_SPIM1 instance. */
#define ALT_SPIM1_CTLR0_ADDR  ALT_SPIM_CTLR0_ADDR(ALT_SPIM1_ADDR)
/* The address of the ALT_SPIM_CTLR1 register for the ALT_SPIM1 instance. */
#define ALT_SPIM1_CTLR1_ADDR  ALT_SPIM_CTLR1_ADDR(ALT_SPIM1_ADDR)
/* The address of the ALT_SPIM_SPIENR register for the ALT_SPIM1 instance. */
#define ALT_SPIM1_SPIENR_ADDR  ALT_SPIM_SPIENR_ADDR(ALT_SPIM1_ADDR)
/* The address of the ALT_SPIM_MWCR register for the ALT_SPIM1 instance. */
#define ALT_SPIM1_MWCR_ADDR  ALT_SPIM_MWCR_ADDR(ALT_SPIM1_ADDR)
/* The address of the ALT_SPIM_SER register for the ALT_SPIM1 instance. */
#define ALT_SPIM1_SER_ADDR  ALT_SPIM_SER_ADDR(ALT_SPIM1_ADDR)
/* The address of the ALT_SPIM_BAUDR register for the ALT_SPIM1 instance. */
#define ALT_SPIM1_BAUDR_ADDR  ALT_SPIM_BAUDR_ADDR(ALT_SPIM1_ADDR)
/* The address of the ALT_SPIM_TXFTLR register for the ALT_SPIM1 instance. */
#define ALT_SPIM1_TXFTLR_ADDR  ALT_SPIM_TXFTLR_ADDR(ALT_SPIM1_ADDR)
/* The address of the ALT_SPIM_RXFTLR register for the ALT_SPIM1 instance. */
#define ALT_SPIM1_RXFTLR_ADDR  ALT_SPIM_RXFTLR_ADDR(ALT_SPIM1_ADDR)
/* The address of the ALT_SPIM_TXFLR register for the ALT_SPIM1 instance. */
#define ALT_SPIM1_TXFLR_ADDR  ALT_SPIM_TXFLR_ADDR(ALT_SPIM1_ADDR)
/* The address of the ALT_SPIM_RXFLR register for the ALT_SPIM1 instance. */
#define ALT_SPIM1_RXFLR_ADDR  ALT_SPIM_RXFLR_ADDR(ALT_SPIM1_ADDR)
/* The address of the ALT_SPIM_SR register for the ALT_SPIM1 instance. */
#define ALT_SPIM1_SR_ADDR  ALT_SPIM_SR_ADDR(ALT_SPIM1_ADDR)
/* The address of the ALT_SPIM_IMR register for the ALT_SPIM1 instance. */
#define ALT_SPIM1_IMR_ADDR  ALT_SPIM_IMR_ADDR(ALT_SPIM1_ADDR)
/* The address of the ALT_SPIM_ISR register for the ALT_SPIM1 instance. */
#define ALT_SPIM1_ISR_ADDR  ALT_SPIM_ISR_ADDR(ALT_SPIM1_ADDR)
/* The address of the ALT_SPIM_RISR register for the ALT_SPIM1 instance. */
#define ALT_SPIM1_RISR_ADDR  ALT_SPIM_RISR_ADDR(ALT_SPIM1_ADDR)
/* The address of the ALT_SPIM_TXOICR register for the ALT_SPIM1 instance. */
#define ALT_SPIM1_TXOICR_ADDR  ALT_SPIM_TXOICR_ADDR(ALT_SPIM1_ADDR)
/* The address of the ALT_SPIM_RXOICR register for the ALT_SPIM1 instance. */
#define ALT_SPIM1_RXOICR_ADDR  ALT_SPIM_RXOICR_ADDR(ALT_SPIM1_ADDR)
/* The address of the ALT_SPIM_RXUICR register for the ALT_SPIM1 instance. */
#define ALT_SPIM1_RXUICR_ADDR  ALT_SPIM_RXUICR_ADDR(ALT_SPIM1_ADDR)
/* The address of the ALT_SPIM_MSTICR register for the ALT_SPIM1 instance. */
#define ALT_SPIM1_MSTICR_ADDR  ALT_SPIM_MSTICR_ADDR(ALT_SPIM1_ADDR)
/* The address of the ALT_SPIM_ICR register for the ALT_SPIM1 instance. */
#define ALT_SPIM1_ICR_ADDR  ALT_SPIM_ICR_ADDR(ALT_SPIM1_ADDR)
/* The address of the ALT_SPIM_DMACR register for the ALT_SPIM1 instance. */
#define ALT_SPIM1_DMACR_ADDR  ALT_SPIM_DMACR_ADDR(ALT_SPIM1_ADDR)
/* The address of the ALT_SPIM_DMATDLR register for the ALT_SPIM1 instance. */
#define ALT_SPIM1_DMATDLR_ADDR  ALT_SPIM_DMATDLR_ADDR(ALT_SPIM1_ADDR)
/* The address of the ALT_SPIM_DMARDLR register for the ALT_SPIM1 instance. */
#define ALT_SPIM1_DMARDLR_ADDR  ALT_SPIM_DMARDLR_ADDR(ALT_SPIM1_ADDR)
/* The address of the ALT_SPIM_IDR register for the ALT_SPIM1 instance. */
#define ALT_SPIM1_IDR_ADDR  ALT_SPIM_IDR_ADDR(ALT_SPIM1_ADDR)
/* The address of the ALT_SPIM_SPI_VER_ID register for the ALT_SPIM1 instance. */
#define ALT_SPIM1_SPI_VER_ID_ADDR  ALT_SPIM_SPI_VER_ID_ADDR(ALT_SPIM1_ADDR)
/* The address of the ALT_SPIM_DR register for the ALT_SPIM1 instance. */
#define ALT_SPIM1_DR_ADDR  ALT_SPIM_DR_ADDR(ALT_SPIM1_ADDR)
/* The address of the ALT_SPIM_RX_SMPL_DLY register for the ALT_SPIM1 instance. */
#define ALT_SPIM1_RX_SMPL_DLY_ADDR  ALT_SPIM_RX_SMPL_DLY_ADDR(ALT_SPIM1_ADDR)
/* The address of the ALT_SPIM_RSVD_0 register for the ALT_SPIM1 instance. */
#define ALT_SPIM1_RSVD_0_ADDR  ALT_SPIM_RSVD_0_ADDR(ALT_SPIM1_ADDR)
/* The address of the ALT_SPIM_RSVD_1 register for the ALT_SPIM1 instance. */
#define ALT_SPIM1_RSVD_1_ADDR  ALT_SPIM_RSVD_1_ADDR(ALT_SPIM1_ADDR)
/* The address of the ALT_SPIM_RSVD_2 register for the ALT_SPIM1 instance. */
#define ALT_SPIM1_RSVD_2_ADDR  ALT_SPIM_RSVD_2_ADDR(ALT_SPIM1_ADDR)
/* The base address byte offset for the start of the ALT_SPIM1 component. */
#define ALT_SPIM1_OFST        0xffda5000
/* The start address of the ALT_SPIM1 component. */
#define ALT_SPIM1_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_SPIM1_OFST))
/* The lower bound address range of the ALT_SPIM1 component. */
#define ALT_SPIM1_LB_ADDR     ALT_SPIM1_ADDR
/* The upper bound address range of the ALT_SPIM1 component. */
#define ALT_SPIM1_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_SPIM1_ADDR) + 0x100) - 1))


/*
 * Component Instance : i_ram_onchip_ram_block
 * 
 * Instance i_ram_onchip_ram_block of component ALT_OCRAM.
 * 
 * 
 */
/* The base address byte offset for the start of the ALT_OCRAM component. */
#define ALT_OCRAM_OFST        0xffe00000
/* The start address of the ALT_OCRAM component. */
#define ALT_OCRAM_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_OCRAM_OFST))
/* The lower bound address range of the ALT_OCRAM component. */
#define ALT_OCRAM_LB_ADDR     ALT_OCRAM_ADDR
/* The upper bound address range of the ALT_OCRAM component. */
#define ALT_OCRAM_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_OCRAM_ADDR) + 0x40000) - 1))


/*
 * Component Instance : i_rom_onchip_rom_block
 * 
 * Instance i_rom_onchip_rom_block of component ALT_ROM.
 * 
 * 
 */
/* The base address byte offset for the start of the ALT_ROM component. */
#define ALT_ROM_OFST        0xfffc0000
/* The start address of the ALT_ROM component. */
#define ALT_ROM_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_ROM_OFST))
/* The lower bound address range of the ALT_ROM component. */
#define ALT_ROM_LB_ADDR     ALT_ROM_ADDR
/* The upper bound address range of the ALT_ROM component. */
#define ALT_ROM_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_ROM_ADDR) + 0x20000) - 1))


/*
 * Component Instance : mpu_regs_MPUSCU
 * 
 * Instance mpu_regs_MPUSCU of component ALT_MPU_REGS_MPUSCU.
 * 
 * 
 */
/* The base address byte offset for the start of the ALT_MPU_REGS_MPUSCU component. */
#define ALT_MPU_REGS_MPUSCU_OFST        0xffffc000
/* The start address of the ALT_MPU_REGS_MPUSCU component. */
#define ALT_MPU_REGS_MPUSCU_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_MPU_REGS_MPUSCU_OFST))
/* The lower bound address range of the ALT_MPU_REGS_MPUSCU component. */
#define ALT_MPU_REGS_MPUSCU_LB_ADDR     ALT_MPU_REGS_MPUSCU_ADDR
/* The upper bound address range of the ALT_MPU_REGS_MPUSCU component. */
#define ALT_MPU_REGS_MPUSCU_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_MPU_REGS_MPUSCU_ADDR) + 0x100) - 1))


/*
 * Component Instance : mpu_regs_MPUGIC
 * 
 * Instance mpu_regs_MPUGIC of component ALT_MPU_REGS_MPUGIC.
 * 
 * 
 */
/* The base address byte offset for the start of the ALT_MPU_REGS_MPUGIC component. */
#define ALT_MPU_REGS_MPUGIC_OFST        0xffffc100
/* The start address of the ALT_MPU_REGS_MPUGIC component. */
#define ALT_MPU_REGS_MPUGIC_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_MPU_REGS_MPUGIC_OFST))
/* The lower bound address range of the ALT_MPU_REGS_MPUGIC component. */
#define ALT_MPU_REGS_MPUGIC_LB_ADDR     ALT_MPU_REGS_MPUGIC_ADDR
/* The upper bound address range of the ALT_MPU_REGS_MPUGIC component. */
#define ALT_MPU_REGS_MPUGIC_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_MPU_REGS_MPUGIC_ADDR) + 0x100) - 1))


/*
 * Component Instance : mpu_regs_MPUGLOBALTIMER
 * 
 * Instance mpu_regs_MPUGLOBALTIMER of component ALT_MPU_REGS_MPUGLOBTMR.
 * 
 * 
 */
/* The base address byte offset for the start of the ALT_MPU_REGS_MPUGLOBTMR component. */
#define ALT_MPU_REGS_MPUGLOBTMR_OFST        0xffffc200
/* The start address of the ALT_MPU_REGS_MPUGLOBTMR component. */
#define ALT_MPU_REGS_MPUGLOBTMR_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_MPU_REGS_MPUGLOBTMR_OFST))
/* The lower bound address range of the ALT_MPU_REGS_MPUGLOBTMR component. */
#define ALT_MPU_REGS_MPUGLOBTMR_LB_ADDR     ALT_MPU_REGS_MPUGLOBTMR_ADDR
/* The upper bound address range of the ALT_MPU_REGS_MPUGLOBTMR component. */
#define ALT_MPU_REGS_MPUGLOBTMR_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_MPU_REGS_MPUGLOBTMR_ADDR) + 0x100) - 1))


/*
 * Component Instance : mpu_regs_MPUPRIVATETIMER
 * 
 * Instance mpu_regs_MPUPRIVATETIMER of component ALT_MPU_REGS_MPUPRIVATETMR.
 * 
 * 
 */
/* The base address byte offset for the start of the ALT_MPU_REGS_MPUPRIVATETMR component. */
#define ALT_MPU_REGS_MPUPRIVATETMR_OFST        0xffffc600
/* The start address of the ALT_MPU_REGS_MPUPRIVATETMR component. */
#define ALT_MPU_REGS_MPUPRIVATETMR_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_MPU_REGS_MPUPRIVATETMR_OFST))
/* The lower bound address range of the ALT_MPU_REGS_MPUPRIVATETMR component. */
#define ALT_MPU_REGS_MPUPRIVATETMR_LB_ADDR     ALT_MPU_REGS_MPUPRIVATETMR_ADDR
/* The upper bound address range of the ALT_MPU_REGS_MPUPRIVATETMR component. */
#define ALT_MPU_REGS_MPUPRIVATETMR_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_MPU_REGS_MPUPRIVATETMR_ADDR) + 0x100) - 1))


/*
 * Component Instance : mpu_regs_MPUINTRDIST
 * 
 * Instance mpu_regs_MPUINTRDIST of component ALT_MPU_REGS_MPUINTRDIST.
 * 
 * 
 */
/* The base address byte offset for the start of the ALT_MPU_REGS_MPUINTRDIST component. */
#define ALT_MPU_REGS_MPUINTRDIST_OFST        0xffffd000
/* The start address of the ALT_MPU_REGS_MPUINTRDIST component. */
#define ALT_MPU_REGS_MPUINTRDIST_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_MPU_REGS_MPUINTRDIST_OFST))
/* The lower bound address range of the ALT_MPU_REGS_MPUINTRDIST component. */
#define ALT_MPU_REGS_MPUINTRDIST_LB_ADDR     ALT_MPU_REGS_MPUINTRDIST_ADDR
/* The upper bound address range of the ALT_MPU_REGS_MPUINTRDIST component. */
#define ALT_MPU_REGS_MPUINTRDIST_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_MPU_REGS_MPUINTRDIST_ADDR) + 0x1000) - 1))


/*
 * Component Instance : l2_regs_L2TYPE
 * 
 * Instance l2_regs_L2TYPE of component ALT_L2_REGS_L2TYPE.
 * 
 * 
 */
/* The base address byte offset for the start of the ALT_L2_REGS_L2TYPE component. */
#define ALT_L2_REGS_L2TYPE_OFST        0xfffff000
/* The start address of the ALT_L2_REGS_L2TYPE component. */
#define ALT_L2_REGS_L2TYPE_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_L2_REGS_L2TYPE_OFST))
/* The lower bound address range of the ALT_L2_REGS_L2TYPE component. */
#define ALT_L2_REGS_L2TYPE_LB_ADDR     ALT_L2_REGS_L2TYPE_ADDR
/* The upper bound address range of the ALT_L2_REGS_L2TYPE component. */
#define ALT_L2_REGS_L2TYPE_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_L2_REGS_L2TYPE_ADDR) + 0x100) - 1))


/*
 * Component Instance : l2_regs_L2CONTROL
 * 
 * Instance l2_regs_L2CONTROL of component ALT_L2_REGS_L2CTL.
 * 
 * 
 */
/* The base address byte offset for the start of the ALT_L2_REGS_L2CTL component. */
#define ALT_L2_REGS_L2CTL_OFST        0xfffff100
/* The start address of the ALT_L2_REGS_L2CTL component. */
#define ALT_L2_REGS_L2CTL_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_L2_REGS_L2CTL_OFST))
/* The lower bound address range of the ALT_L2_REGS_L2CTL component. */
#define ALT_L2_REGS_L2CTL_LB_ADDR     ALT_L2_REGS_L2CTL_ADDR
/* The upper bound address range of the ALT_L2_REGS_L2CTL component. */
#define ALT_L2_REGS_L2CTL_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_L2_REGS_L2CTL_ADDR) + 0x100) - 1))


/*
 * Component Instance : l2_regs_L2INTERRUPT
 * 
 * Instance l2_regs_L2INTERRUPT of component ALT_L2_REGS_L2INT.
 * 
 * 
 */
/* The base address byte offset for the start of the ALT_L2_REGS_L2INT component. */
#define ALT_L2_REGS_L2INT_OFST        0xfffff200
/* The start address of the ALT_L2_REGS_L2INT component. */
#define ALT_L2_REGS_L2INT_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_L2_REGS_L2INT_OFST))
/* The lower bound address range of the ALT_L2_REGS_L2INT component. */
#define ALT_L2_REGS_L2INT_LB_ADDR     ALT_L2_REGS_L2INT_ADDR
/* The upper bound address range of the ALT_L2_REGS_L2INT component. */
#define ALT_L2_REGS_L2INT_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_L2_REGS_L2INT_ADDR) + 0x100) - 1))


/*
 * Component Instance : l2_regs_L2MAINTENANCE
 * 
 * Instance l2_regs_L2MAINTENANCE of component ALT_L2_REGS_L2MAINTENANCE.
 * 
 * 
 */
/* The base address byte offset for the start of the ALT_L2_REGS_L2MAINTENANCE component. */
#define ALT_L2_REGS_L2MAINTENANCE_OFST        0xfffff700
/* The start address of the ALT_L2_REGS_L2MAINTENANCE component. */
#define ALT_L2_REGS_L2MAINTENANCE_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_L2_REGS_L2MAINTENANCE_OFST))
/* The lower bound address range of the ALT_L2_REGS_L2MAINTENANCE component. */
#define ALT_L2_REGS_L2MAINTENANCE_LB_ADDR     ALT_L2_REGS_L2MAINTENANCE_ADDR
/* The upper bound address range of the ALT_L2_REGS_L2MAINTENANCE component. */
#define ALT_L2_REGS_L2MAINTENANCE_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_L2_REGS_L2MAINTENANCE_ADDR) + 0x100) - 1))


/*
 * Component Instance : l2_regs_L2LOCKDOWN
 * 
 * Instance l2_regs_L2LOCKDOWN of component ALT_L2_REGS_L2LOCKDOWN.
 * 
 * 
 */
/* The base address byte offset for the start of the ALT_L2_REGS_L2LOCKDOWN component. */
#define ALT_L2_REGS_L2LOCKDOWN_OFST        0xfffff900
/* The start address of the ALT_L2_REGS_L2LOCKDOWN component. */
#define ALT_L2_REGS_L2LOCKDOWN_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_L2_REGS_L2LOCKDOWN_OFST))
/* The lower bound address range of the ALT_L2_REGS_L2LOCKDOWN component. */
#define ALT_L2_REGS_L2LOCKDOWN_LB_ADDR     ALT_L2_REGS_L2LOCKDOWN_ADDR
/* The upper bound address range of the ALT_L2_REGS_L2LOCKDOWN component. */
#define ALT_L2_REGS_L2LOCKDOWN_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_L2_REGS_L2LOCKDOWN_ADDR) + 0x100) - 1))


/*
 * Component Instance : l2_regs_L2ADDRESSFILTER
 * 
 * Instance l2_regs_L2ADDRESSFILTER of component ALT_L2_REGS_L2ADDRFLT.
 * 
 * 
 */
/* The base address byte offset for the start of the ALT_L2_REGS_L2ADDRFLT component. */
#define ALT_L2_REGS_L2ADDRFLT_OFST        0xfffffc00
/* The start address of the ALT_L2_REGS_L2ADDRFLT component. */
#define ALT_L2_REGS_L2ADDRFLT_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_L2_REGS_L2ADDRFLT_OFST))
/* The lower bound address range of the ALT_L2_REGS_L2ADDRFLT component. */
#define ALT_L2_REGS_L2ADDRFLT_LB_ADDR     ALT_L2_REGS_L2ADDRFLT_ADDR
/* The upper bound address range of the ALT_L2_REGS_L2ADDRFLT component. */
#define ALT_L2_REGS_L2ADDRFLT_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_L2_REGS_L2ADDRFLT_ADDR) + 0x100) - 1))


/*
 * Component Instance : l2_regs_L2DEBUG
 * 
 * Instance l2_regs_L2DEBUG of component ALT_L2_REGS_L2DBG.
 * 
 * 
 */
/* The base address byte offset for the start of the ALT_L2_REGS_L2DBG component. */
#define ALT_L2_REGS_L2DBG_OFST        0xffffff00
/* The start address of the ALT_L2_REGS_L2DBG component. */
#define ALT_L2_REGS_L2DBG_ADDR        ALT_CAST(void *, (ALT_CAST(char *, ALT_HPS_ADDR) + ALT_L2_REGS_L2DBG_OFST))
/* The lower bound address range of the ALT_L2_REGS_L2DBG component. */
#define ALT_L2_REGS_L2DBG_LB_ADDR     ALT_L2_REGS_L2DBG_ADDR
/* The upper bound address range of the ALT_L2_REGS_L2DBG component. */
#define ALT_L2_REGS_L2DBG_UB_ADDR     ALT_CAST(void *, ((ALT_CAST(char *, ALT_L2_REGS_L2DBG_ADDR) + 0x100) - 1))


#ifdef __ASSEMBLY__
#define ALT_CAST(type, ptr)  ptr
#else   /* __ASSEMBLY__ */
#define ALT_CAST(type, ptr)  ((type) (ptr))
#endif  /* __ASSEMBLY__ */
/*
 * Address Space : ALT_HPS
 * 
 * Address Map
 * 
 *  Address Range           | Component                                  
 * :------------------------|:--------------------------------------------
 *  0x00000000 - 0xbfffffff | Undefined                                  
 *  0xc0000000 - 0xfbffffff | ALT_FPGA_BRIDGE_H2F128                     
 *  0xfc000000 - 0xff1fffff | Undefined                                  
 *  0xff200000 - 0xff3fffff | ALT_FPGA_BRIDGE_LWH2F                      
 *  0xff400000 - 0xff7fffff | Undefined                                  
 *  0xff800000 - 0xff80105b | ALT_EMAC0                                  
 *  0xff80105c - 0xff801fff | Undefined                                  
 *  0xff802000 - 0xff80305b | ALT_EMAC1                                  
 *  0xff80305c - 0xff803fff | Undefined                                  
 *  0xff804000 - 0xff80505b | ALT_EMAC2                                  
 *  0xff80505c - 0xff807fff | Undefined                                  
 *  0xff808000 - 0xff8083ff | ALT_SDMMC                                  
 *  0xff808400 - 0xff808fff | Undefined                                  
 *  0xff809000 - 0xff8090ff | ALT_QSPI                                   
 *  0xff809100 - 0xff8c07ff | Undefined                                  
 *  0xff8c0800 - 0xff8c0bff | ALT_ECC_EMAC0_RX_ECC                       
 *  0xff8c0c00 - 0xff8c0fff | ALT_ECC_EMAC0_TX_ECC                       
 *  0xff8c1000 - 0xff8c13ff | ALT_ECC_EMAC1_RX_ECC                       
 *  0xff8c1400 - 0xff8c17ff | ALT_ECC_EMAC1_TX_ECC                       
 *  0xff8c1800 - 0xff8c1bff | ALT_ECC_EMAC2_RX_ECC                       
 *  0xff8c1c00 - 0xff8c1fff | ALT_ECC_EMAC2_TX_ECC                       
 *  0xff8c2000 - 0xff8c23ff | ALT_ECC_NAND                               
 *  0xff8c2400 - 0xff8c27ff | ALT_ECC_NANDR                              
 *  0xff8c2800 - 0xff8c2bff | ALT_ECC_NANDW                              
 *  0xff8c2c00 - 0xff8c2fff | ALT_ECC_SDMMC                              
 *  0xff8c3000 - 0xff8c33ff | ALT_ECC_OCRAM_ECC                          
 *  0xff8c3400 - 0xff8c7fff | Undefined                                  
 *  0xff8c8000 - 0xff8c83ff | ALT_ECC_DMAC                               
 *  0xff8c8400 - 0xff8c87ff | ALT_ECC_QSPI                               
 *  0xff8c8800 - 0xff8c8bff | ALT_ECC_OTG0_ECC                           
 *  0xff8c8c00 - 0xff8c8fff | ALT_ECC_OTG1_ECC                           
 *  0xff8c9000 - 0xff9fffff | Undefined                                  
 *  0xffa00000 - 0xffafffff | ALT_QSPIDATA                               
 *  0xffb00000 - 0xffb0013f | ALT_USB0_GLOBGRP                           
 *  0xffb00140 - 0xffb003ff | Undefined                                  
 *  0xffb00400 - 0xffb006ff | ALT_USB0_HOSTGRP                           
 *  0xffb00700 - 0xffb007ff | Undefined                                  
 *  0xffb00800 - 0xffb00cff | ALT_USB0_DEVGRP                            
 *  0xffb00d00 - 0xffb00dff | Undefined                                  
 *  0xffb00e00 - 0xffb00e03 | ALT_USB0_PWRCLKGRP                         
 *  0xffb00e04 - 0xffb00fff | Undefined                                  
 *  0xffb01000 - 0xffb01fff | ALT_USB0_DWC_OTG_DFIFO_0                   
 *  0xffb02000 - 0xffb02fff | ALT_USB0_DWC_OTG_DFIFO_1                   
 *  0xffb03000 - 0xffb03fff | ALT_USB0_DWC_OTG_DFIFO_2                   
 *  0xffb04000 - 0xffb04fff | ALT_USB0_DWC_OTG_DFIFO_3                   
 *  0xffb05000 - 0xffb05fff | ALT_USB0_DWC_OTG_DFIFO_4                   
 *  0xffb06000 - 0xffb06fff | ALT_USB0_DWC_OTG_DFIFO_5                   
 *  0xffb07000 - 0xffb07fff | ALT_USB0_DWC_OTG_DFIFO_6                   
 *  0xffb08000 - 0xffb08fff | ALT_USB0_DWC_OTG_DFIFO_7                   
 *  0xffb09000 - 0xffb09fff | ALT_USB0_DWC_OTG_DFIFO_8                   
 *  0xffb0a000 - 0xffb0afff | ALT_USB0_DWC_OTG_DFIFO_9                   
 *  0xffb0b000 - 0xffb0bfff | ALT_USB0_DWC_OTG_DFIFO_10                  
 *  0xffb0c000 - 0xffb0cfff | ALT_USB0_DWC_OTG_DFIFO_11                  
 *  0xffb0d000 - 0xffb0dfff | ALT_USB0_DWC_OTG_DFIFO_12                  
 *  0xffb0e000 - 0xffb0efff | ALT_USB0_DWC_OTG_DFIFO_13                  
 *  0xffb0f000 - 0xffb0ffff | ALT_USB0_DWC_OTG_DFIFO_14                  
 *  0xffb10000 - 0xffb10fff | ALT_USB0_DWC_OTG_DFIFO_15                  
 *  0xffb11000 - 0xffb1ffff | Undefined                                  
 *  0xffb20000 - 0xffb3ffff | ALT_USB0_DWC_OTG_DFIFO_DIRECT_ACCESS       
 *  0xffb40000 - 0xffb4013f | ALT_USB1_GLOBGRP                           
 *  0xffb40140 - 0xffb403ff | Undefined                                  
 *  0xffb40400 - 0xffb406ff | ALT_USB1_HOSTGRP                           
 *  0xffb40700 - 0xffb407ff | Undefined                                  
 *  0xffb40800 - 0xffb40cff | ALT_USB1_DEVGRP                            
 *  0xffb40d00 - 0xffb40dff | Undefined                                  
 *  0xffb40e00 - 0xffb40e03 | ALT_USB1_PWRCLKGRP                         
 *  0xffb40e04 - 0xffb40fff | Undefined                                  
 *  0xffb41000 - 0xffb41fff | ALT_USB1_DWC_OTG_DFIFO_0                   
 *  0xffb42000 - 0xffb42fff | ALT_USB1_DWC_OTG_DFIFO_1                   
 *  0xffb43000 - 0xffb43fff | ALT_USB1_DWC_OTG_DFIFO_2                   
 *  0xffb44000 - 0xffb44fff | ALT_USB1_DWC_OTG_DFIFO_3                   
 *  0xffb45000 - 0xffb45fff | ALT_USB1_DWC_OTG_DFIFO_4                   
 *  0xffb46000 - 0xffb46fff | ALT_USB1_DWC_OTG_DFIFO_5                   
 *  0xffb47000 - 0xffb47fff | ALT_USB1_DWC_OTG_DFIFO_6                   
 *  0xffb48000 - 0xffb48fff | ALT_USB1_DWC_OTG_DFIFO_7                   
 *  0xffb49000 - 0xffb49fff | ALT_USB1_DWC_OTG_DFIFO_8                   
 *  0xffb4a000 - 0xffb4afff | ALT_USB1_DWC_OTG_DFIFO_9                   
 *  0xffb4b000 - 0xffb4bfff | ALT_USB1_DWC_OTG_DFIFO_10                  
 *  0xffb4c000 - 0xffb4cfff | ALT_USB1_DWC_OTG_DFIFO_11                  
 *  0xffb4d000 - 0xffb4dfff | ALT_USB1_DWC_OTG_DFIFO_12                  
 *  0xffb4e000 - 0xffb4efff | ALT_USB1_DWC_OTG_DFIFO_13                  
 *  0xffb4f000 - 0xffb4ffff | ALT_USB1_DWC_OTG_DFIFO_14                  
 *  0xffb50000 - 0xffb50fff | ALT_USB1_DWC_OTG_DFIFO_15                  
 *  0xffb51000 - 0xffb5ffff | Undefined                                  
 *  0xffb60000 - 0xffb7ffff | ALT_USB1_DWC_OTG_DFIFO_DIRECT_ACCESS       
 *  0xffb80000 - 0xffb802b3 | ALT_NAND_CFG                               
 *  0xffb802b4 - 0xffb802ff | Undefined                                  
 *  0xffb80300 - 0xffb803f3 | ALT_NAND_PARAM                             
 *  0xffb803f4 - 0xffb803ff | Undefined                                  
 *  0xffb80400 - 0xffb80543 | ALT_NAND_STAT                              
 *  0xffb80544 - 0xffb8064f | Undefined                                  
 *  0xffb80650 - 0xffb80663 | ALT_NAND_ECC                               
 *  0xffb80664 - 0xffb806ff | Undefined                                  
 *  0xffb80700 - 0xffb807d3 | ALT_NAND_DMA                               
 *  0xffb807d4 - 0xffb8ffff | Undefined                                  
 *  0xffb90000 - 0xffb9ffff | ALT_NANDDATA                               
 *  0xffba0000 - 0xffc01fff | Undefined                                  
 *  0xffc02000 - 0xffc020ff | ALT_UART0                                  
 *  0xffc02100 - 0xffc021ff | ALT_UART1                                  
 *  0xffc02200 - 0xffc022ff | ALT_I2C0                                   
 *  0xffc02300 - 0xffc023ff | ALT_I2C1                                   
 *  0xffc02400 - 0xffc024ff | ALT_I2C_EMAC_0_I2C                         
 *  0xffc02500 - 0xffc025ff | ALT_I2C_EMAC_1_I2C                         
 *  0xffc02600 - 0xffc026ff | ALT_I2C_EMAC_2_I2C                         
 *  0xffc02700 - 0xffc027ff | ALT_SPTMR0                                 
 *  0xffc02800 - 0xffc028ff | ALT_SPTMR1                                 
 *  0xffc02900 - 0xffc0297f | ALT_GPIO0                                  
 *  0xffc02980 - 0xffc029ff | Undefined                                  
 *  0xffc02a00 - 0xffc02a7f | ALT_GPIO1                                  
 *  0xffc02a80 - 0xffc02aff | Undefined                                  
 *  0xffc02b00 - 0xffc02b7f | ALT_GPIO_2_GPIO                            
 *  0xffc02b80 - 0xffcf9fff | Undefined                                  
 *  0xffcfa000 - 0xffcfafff | ALT_IO48_HMC_MMR                           
 *  0xffcfb000 - 0xffcfb4ff | ALT_ECC_HMC_OCP                            
 *  0xffcfb500 - 0xffcfdfff | Undefined                                  
 *  0xffcfe000 - 0xffcfe3ff | ALT_SEC_MGR_AESFIFO                        
 *  0xffcfe400 - 0xffcfe7ff | ALT_FPGAMGRDATA                            
 *  0xffcfe800 - 0xffcfffff | Undefined                                  
 *  0xffd00000 - 0xffd000ff | ALT_TMR_SYS_0_TMR                          
 *  0xffd00100 - 0xffd001ff | ALT_TMR_SYS_1_TMR                          
 *  0xffd00200 - 0xffd002ff | ALT_L4WD0                                  
 *  0xffd00300 - 0xffd003ff | ALT_L4WD1                                  
 *  0xffd00400 - 0xffd02fff | Undefined                                  
 *  0xffd03000 - 0xffd03fff | ALT_FPGAMGR                                
 *  0xffd04000 - 0xffd0403f | ALT_CLKMGR_CLKMGR                          
 *  0xffd04040 - 0xffd040bf | ALT_CLKMGR_MAINPLL                         
 *  0xffd040c0 - 0xffd0413f | ALT_CLKMGR_PERPLL                          
 *  0xffd04140 - 0xffd0417f | ALT_CLKMGR_ALTERA                          
 *  0xffd04180 - 0xffd04fff | Undefined                                  
 *  0xffd05000 - 0xffd050ff | ALT_RSTMGR                                 
 *  0xffd05100 - 0xffd05fff | Undefined                                  
 *  0xffd06000 - 0xffd061ff | ALT_SYSMGR                                 
 *  0xffd06200 - 0xffd062ff | ALT_SYSMGR_ROM                             
 *  0xffd06300 - 0xffd06fff | Undefined                                  
 *  0xffd07000 - 0xffd071ff | ALT_PINMUX_SHARED_3V_IO_GRP                
 *  0xffd07200 - 0xffd073ff | ALT_PINMUX_DCTD_IO_GRP                     
 *  0xffd07400 - 0xffd074ff | ALT_PINMUX_FPGA_INTERFACE_GRP              
 *  0xffd07500 - 0xffd10fff | Undefined                                  
 *  0xffd11000 - 0xffd110ff | ALT_NOC_L4_PRIV_FLT                        
 *  0xffd11100 - 0xffd1117f | ALT_NOC_MPU_M1TODDRRESP_MAIN_RATE          
 *  0xffd11180 - 0xffd111ff | Undefined                                  
 *  0xffd11200 - 0xffd1127f | ALT_NOC_MPU_M0_RATE_ADRESP_MAIN_RATE       
 *  0xffd11280 - 0xffd112ff | Undefined                                  
 *  0xffd11300 - 0xffd1137f | ALT_NOC_MPU_L4_MP_RATE_AD_MAIN_RATE        
 *  0xffd11380 - 0xffd113ff | Undefined                                  
 *  0xffd11400 - 0xffd1147f | ALT_NOC_MPU_F2H_RATE_AD_MAIN_RATE          
 *  0xffd11480 - 0xffd114ff | Undefined                                  
 *  0xffd11500 - 0xffd1157f | ALT_NOC_MPU_L3TOH2FRESP_MAIN_RATE          
 *  0xffd11580 - 0xffd115ff | Undefined                                  
 *  0xffd11600 - 0xffd1167f | ALT_NOC_MPU_ACP_RATE_AD_MAIN_RATE          
 *  0xffd11680 - 0xffd11fff | Undefined                                  
 *  0xffd12000 - 0xffd123ff | ALT_NOC_MPU_DDR_T_PRB                      
 *  0xffd12400 - 0xffd1247f | ALT_NOC_MPU_DDR_T_SCHED                    
 *  0xffd12480 - 0xffd12fff | Undefined                                  
 *  0xffd13000 - 0xffd130ff | ALT_NOC_FW_L4_PER_SCR                      
 *  0xffd13100 - 0xffd131ff | ALT_NOC_FW_L4_SYS_SCR                      
 *  0xffd13200 - 0xffd132ff | ALT_NOC_FW_OCRAM_SCR                       
 *  0xffd13300 - 0xffd133ff | ALT_NOC_FW_DDR_MPU_F2SDR_DDR_SCR           
 *  0xffd13400 - 0xffd134ff | ALT_NOC_FW_DDR_L3_SCR                      
 *  0xffd13500 - 0xffd135ff | ALT_NOC_FW_H2F_SCR                         
 *  0xffd13600 - 0xffd13fff | Undefined                                  
 *  0xffd14000 - 0xffd143ff | ALT_NOC_MPU_PRB_H2F_MAIN_PRB               
 *  0xffd14400 - 0xffd147ff | ALT_NOC_MPU_PRB_EMACS_MAIN_PRB             
 *  0xffd14800 - 0xffd1487f | ALT_NOC_MPU_PRB_EMACS_MAIN_XACTSTATPROFILER
 *  0xffd14880 - 0xffd148ff | Undefined                                  
 *  0xffd14900 - 0xffd1497f | ALT_NOC_MPU_CS_OBS_AT_ATBENDPT             
 *  0xffd14980 - 0xffd149ff | ALT_NOC_MPU_CS_OBS_AT_ERRLOG_0             
 *  0xffd14a00 - 0xffd14fff | Undefined                                  
 *  0xffd15000 - 0xffd153ff | ALT_NOC_MPU_PRB_MPU_MAIN_PRB               
 *  0xffd15400 - 0xffd15fff | Undefined                                  
 *  0xffd16000 - 0xffd1607f | ALT_NOC_MPU_M0_MAIN_QOS                    
 *  0xffd16080 - 0xffd160ff | ALT_NOC_MPU_M1_MAIN_QOS                    
 *  0xffd16100 - 0xffd1617f | ALT_NOC_MPU_F2H_AXI32_QOS                  
 *  0xffd16180 - 0xffd161ff | ALT_NOC_MPU_F2H_AXI64_QOS                  
 *  0xffd16200 - 0xffd1627f | ALT_NOC_MPU_F2H_AXI128_QOS                 
 *  0xffd16280 - 0xffd162ff | ALT_NOC_MPU_DMA_M0_QOS                     
 *  0xffd16300 - 0xffd1637f | ALT_NOC_MPU_EMAC0_M_QOS                    
 *  0xffd16380 - 0xffd163ff | ALT_NOC_MPU_EMAC1_M_QOS                    
 *  0xffd16400 - 0xffd1647f | ALT_NOC_MPU_EMAC2_M_QOS                    
 *  0xffd16480 - 0xffd164ff | ALT_NOC_MPU_USB0_M_MAIN_QOS                
 *  0xffd16500 - 0xffd1657f | ALT_NOC_MPU_USB1_M_MAIN_QOS                
 *  0xffd16580 - 0xffd165ff | ALT_NOC_MPU_NAND_M_MAIN_QOS                
 *  0xffd16600 - 0xffd1667f | ALT_NOC_MPU_SDMMC_M_MAIN_QOS               
 *  0xffd16680 - 0xffd166ff | ALT_NOC_MPU_F2SDR0_AXI32_QOS               
 *  0xffd16700 - 0xffd1677f | ALT_NOC_MPU_F2SDR0_AXI64_QOS               
 *  0xffd16780 - 0xffd167ff | ALT_NOC_MPU_F2SDR0_AXI128_QOS              
 *  0xffd16800 - 0xffd1687f | ALT_NOC_MPU_F2SDR1_AXI32_QOS               
 *  0xffd16880 - 0xffd168ff | ALT_NOC_MPU_F2SDR1_AXI64_QOS               
 *  0xffd16900 - 0xffd1697f | ALT_NOC_MPU_F2SDR2_AXI32_QOS               
 *  0xffd16980 - 0xffd169ff | ALT_NOC_MPU_F2SDR2_AXI64_QOS               
 *  0xffd16a00 - 0xffd16fff | Undefined                                  
 *  0xffd17000 - 0xffd1707f | ALT_NOC_MPU_F2SDR2_AXI128_QOS              
 *  0xffd17080 - 0xffd170ff | ALT_NOC_MPU_EMAC0_M_XACTSTATFLT            
 *  0xffd17100 - 0xffd9ffff | Undefined                                  
 *  0xffda0000 - 0xffda005f | ALT_DMA_NSCTL                              
 *  0xffda0060 - 0xffda00ff | Undefined                                  
 *  0xffda0100 - 0xffda013f | ALT_DMA_NSCHANNELSTAT                      
 *  0xffda0140 - 0xffda03ff | Undefined                                  
 *  0xffda0400 - 0xffda04ff | ALT_DMA_NSAXISTAT                          
 *  0xffda0500 - 0xffda0cff | Undefined                                  
 *  0xffda0d00 - 0xffda0d0f | ALT_DMA_NSDBG                              
 *  0xffda0d10 - 0xffda0dff | Undefined                                  
 *  0xffda0e00 - 0xffda0e1f | ALT_DMA_NSCFG                              
 *  0xffda0e20 - 0xffda0fdf | Undefined                                  
 *  0xffda0fe0 - 0xffda0fff | ALT_DMA_NSCOMPID                           
 *  0xffda1000 - 0xffda105f | ALT_DMA_SCTL                               
 *  0xffda1060 - 0xffda10ff | Undefined                                  
 *  0xffda1100 - 0xffda113f | ALT_DMA_SCHANNELSTAT                       
 *  0xffda1140 - 0xffda13ff | Undefined                                  
 *  0xffda1400 - 0xffda14ff | ALT_DMA_SAXISTAT                           
 *  0xffda1500 - 0xffda1cff | Undefined                                  
 *  0xffda1d00 - 0xffda1d0f | ALT_DMA_SDBG                               
 *  0xffda1d10 - 0xffda1dff | Undefined                                  
 *  0xffda1e00 - 0xffda1e1f | ALT_DMA_SCFG                               
 *  0xffda1e20 - 0xffda1fdf | Undefined                                  
 *  0xffda1fe0 - 0xffda1fff | ALT_DMA_SCOMPID                            
 *  0xffda2000 - 0xffda207f | ALT_SPIS0                                  
 *  0xffda2080 - 0xffda2fff | Undefined                                  
 *  0xffda3000 - 0xffda307f | ALT_SPIS1                                  
 *  0xffda3080 - 0xffda3fff | Undefined                                  
 *  0xffda4000 - 0xffda40ff | ALT_SPIM0                                  
 *  0xffda4100 - 0xffda4fff | Undefined                                  
 *  0xffda5000 - 0xffda50ff | ALT_SPIM1                                  
 *  0xffda5100 - 0xffdfffff | Undefined                                  
 *  0xffe00000 - 0xffe3ffff | ALT_OCRAM                                  
 *  0xffe40000 - 0xfffbffff | Undefined                                  
 *  0xfffc0000 - 0xfffdffff | ALT_ROM                                    
 *  0xfffe0000 - 0xffffbfff | Undefined                                  
 *  0xffffc000 - 0xffffc0ff | ALT_MPU_REGS_MPUSCU                        
 *  0xffffc100 - 0xffffc1ff | ALT_MPU_REGS_MPUGIC                        
 *  0xffffc200 - 0xffffc2ff | ALT_MPU_REGS_MPUGLOBTMR                    
 *  0xffffc300 - 0xffffc5ff | Undefined                                  
 *  0xffffc600 - 0xffffc6ff | ALT_MPU_REGS_MPUPRIVATETMR                 
 *  0xffffc700 - 0xffffcfff | Undefined                                  
 *  0xffffd000 - 0xffffdfff | ALT_MPU_REGS_MPUINTRDIST                   
 *  0xffffe000 - 0xffffefff | Undefined                                  
 *  0xfffff000 - 0xfffff0ff | ALT_L2_REGS_L2TYPE                         
 *  0xfffff100 - 0xfffff1ff | ALT_L2_REGS_L2CTL                          
 *  0xfffff200 - 0xfffff2ff | ALT_L2_REGS_L2INT                          
 *  0xfffff300 - 0xfffff6ff | Undefined                                  
 *  0xfffff700 - 0xfffff7ff | ALT_L2_REGS_L2MAINTENANCE                  
 *  0xfffff800 - 0xfffff8ff | Undefined                                  
 *  0xfffff900 - 0xfffff9ff | ALT_L2_REGS_L2LOCKDOWN                     
 *  0xfffffa00 - 0xfffffbff | Undefined                                  
 *  0xfffffc00 - 0xfffffcff | ALT_L2_REGS_L2ADDRFLT                      
 *  0xfffffd00 - 0xfffffeff | Undefined                                  
 *  0xffffff00 - 0xffffffff | ALT_L2_REGS_L2DBG                          
 */

#ifdef __cplusplus
}
#endif  /* __cplusplus */
#endif  /* __ALT_SOCAL_HPS_H__ */

