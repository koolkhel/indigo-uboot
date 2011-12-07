/*
 * (C) Copyright 2007-2008
 * Stelian Pop <stelian.pop@leadtechdesign.com>
 * Lead Tech Design <www.leadtechdesign.com>
 *
 * Configuation settings for the AT91SAM9M10G45EK board(and AT91SAM9G45EKES).
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#ifndef __CONFIG_H
#define __CONFIG_H

#define CONFIG_AT91_LEGACY

/* ARM asynchronous clock */
#define CONFIG_SYS_AT91_MAIN_CLOCK	12000000	/* from 12 MHz crystal */
#define CONFIG_SYS_HZ		1000

#define CONFIG_ARM926EJS	1	/* This is an ARM926EJS Core	*/
#ifdef CONFIG_AT91SAM9M10G45EK
#define CONFIG_AT91SAM9M10G45	1	/* It's an Atmel AT91SAM9M10G45 SoC*/
#else
#define CONFIG_AT91SAM9G45	1	/* It's an Atmel AT91SAM9G45 SoC*/
#endif
#define CONFIG_ARCH_CPU_INIT
#undef CONFIG_USE_IRQ			/* we don't need IRQ/FIQ stuff	*/

#define CONFIG_CMDLINE_TAG	1	/* enable passing of ATAGs	*/
#define CONFIG_SETUP_MEMORY_TAGS 1
#define CONFIG_INITRD_TAG	1

#define CONFIG_SKIP_LOWLEVEL_INIT
#define CONFIG_SKIP_RELOCATE_UBOOT

/*
 * Hardware drivers
 */
#define CONFIG_AT91_GPIO	1
#define CONFIG_ATMEL_USART	1
#undef CONFIG_USART0
#undef CONFIG_USART1
#undef CONFIG_USART2
#define CONFIG_USART3		1	/* USART 3 is DBGU */

/* LCD */
//#define CONFIG_LCD			1
#undef CONFIG_LCD
#define LCD_BPP				LCD_COLOR8
#undef CONFIG_LCD_LOGO
//#define CONFIG_LCD_INFO_BELOW_LOGO	1
#undef LCD_TEST_PATTERN
//#define CONFIG_LCD_INFO			1
//#define CONFIG_SYS_WHITE_ON_BLACK		1
//#define CONFIG_ATMEL_LCD		1
//#define CONFIG_ATMEL_LCD_RGB565		1
//#define CONFIG_SYS_CONSOLE_IS_IN_ENV		1
/* board specific(not enough SRAM) */
//#define CONFIG_AT91SAM9G45_LCD_BASE		0x73E00000 /* DDR2 */
#define CONFIG_AT91SAM9G45_LCD_BASE		0x20000000 /* SDRAM */

/* LED */
#define CONFIG_AT91_LED
#define	CONFIG_RED_LED		AT91_PIN_PD31	/* this is the user1 led */
#define	CONFIG_GREEN_LED	AT91_PIN_PD0	/* this is the user2 led */

#define CONFIG_BOOTDELAY	3

/*
 * BOOTP options
 */
#define CONFIG_BOOTP_BOOTFILESIZE	1
#define CONFIG_BOOTP_BOOTPATH		1
#define CONFIG_BOOTP_GATEWAY		1
#define CONFIG_BOOTP_HOSTNAME		1

/*
 * Command line configuration.
 */
#include <config_cmd_default.h>
#undef CONFIG_CMD_NET
#undef CONFIG_CMD_NFS
#undef CONFIG_CMD_BDI
#undef CONFIG_CMD_FPGA
#undef CONFIG_CMD_IMI
#undef CONFIG_CMD_IMLS
#undef CONFIG_CMD_AUTOSCRIPT
#undef CONFIG_CMD_LOADS

#define CONFIG_YAFFS2 1

#undef CONFIG_CMD_PING
#undef CONFIG_CMD_DHCP
#define CONFIG_CMD_NAND		1
#define CONFIG_CMD_USB

// returning MMC, size probably should go up.

/*
#define MMCI_BASE 0xFFFB4000
#define CONFIG_CMD_MMC		1
#define CONFIG_MMC		1
#define CONFIG_ATMEL_MCI	1
#define CONFIG_CMD_EXT2		1
#define CONFIG_GENERAL_MMC	1
*/

/* SDRAM */
//#define CONFIG_NR_DRAM_BANKS		1
#define PHYS_SDRAM			0x70000000
#define PHYS_SDRAM_SIZE			0x04000000	/* 64 megs */

#define CONFIG_NR_DRAM_BANKS		1
#define PHYS_SDRAM_1			0x70000000
#define PHYS_SDRAM_1_SIZE		0x04000000	/* 64 megs */
//#define PHYS_SDRAM_2			0x20000000
//#define PHYS_SDRAM_2_SIZE		0x02000000	/* 32 megs */

/* DataFlash */
#ifdef CONFIG_ATMEL_SPI
#define CONFIG_CMD_SF
#define CONFIG_CMD_SPI
#define CONFIG_SPI_FLASH		0
#define CONFIG_SPI_FLASH_ATMEL		0
#define CONFIG_SYS_MAX_DATAFLASH_BANKS	0
#endif

/* NOR flash, if populated */
#ifndef CONFIG_CMD_NAND
#define CONFIG_SYS_NO_FLASH		1
#else
#define CONFIG_SYS_FLASH_CFI		0
#define CONFIG_FLASH_CFI_DRIVER		1
#define PHYS_FLASH_1			0x10000000
#define CONFIG_SYS_FLASH_BASE			PHYS_FLASH_1
#define CONFIG_SYS_MAX_FLASH_SECT		256
#define CONFIG_SYS_MAX_FLASH_BANKS		1
#endif

/* NAND flash */
#ifdef CONFIG_CMD_NAND
#define CONFIG_NAND_MAX_CHIPS			1
#define CONFIG_NAND_ATMEL
#define CONFIG_SYS_MAX_NAND_DEVICE		1
#define CONFIG_SYS_NAND_BASE			0x40000000
#define CONFIG_SYS_NAND_DBW_8			1
/* our ALE is AD21 */
#define CONFIG_SYS_NAND_MASK_ALE		(1 << 21)
/* our CLE is AD22 */
#define CONFIG_SYS_NAND_MASK_CLE		(1 << 22)
#define CONFIG_SYS_NAND_ENABLE_PIN		AT91_PIN_PC14
#define CONFIG_SYS_NAND_READY_PIN		AT91_PIN_PC8

#endif

/* Ethernet */
/*
#define CONFIG_MACB			1
#define CONFIG_MACB_SEARCH_PHY		1
//#define CONFIG_RMII			1
#undef CONFIG_RMII
#define CONFIG_NET_MULTI		1
#define CONFIG_NET_RETRY_COUNT		20
#define CONFIG_RESET_PHY_R		1
*/
#undef CONFIG_MACB

/* USB */

#define CONFIG_USB_ATMEL
#define CONFIG_USB_OHCI_NEW		1
#define CONFIG_DOS_PARTITION		1
#define CONFIG_SYS_USB_OHCI_CPU_INIT		1
#define CONFIG_SYS_USB_OHCI_REGS_BASE		0x00700000	/* AT91SAM9G45_UHP_OHCI_BASE */

#define CONFIG_SYS_USB_OHCI_SLOT_NAME		"at91sam9g45"
#define CONFIG_SYS_USB_OHCI_MAX_ROOT_PORTS	2
#define CONFIG_USB_STORAGE		1
#define CONFIG_CMD_FAT		1

#define CONFIG_SYS_LOAD_ADDR			0x72000000	/* load address */

#define CONFIG_SYS_MEMTEST_START		PHYS_SDRAM
#define CONFIG_SYS_MEMTEST_END			0x73e00000

#ifdef CONFIG_SYS_USE_DATAFLASH

/* bootstrap + u-boot + env + linux in dataflash on CS0 */
#define CONFIG_ENV_IS_IN_SPI_FLASH	1
#define CONFIG_SYS_MONITOR_BASE	(0xC0000000 + 0x8400)
#define CONFIG_ENV_OFFSET		0x4200
#define CONFIG_ENV_ADDR		(0xC0000000 + CONFIG_ENV_OFFSET)
#define CONFIG_ENV_SIZE		0x4200
#define CONFIG_ENV_SECT_SIZE		0x10000
#define CONFIG_BOOTCOMMAND	"cp.b 0xC0042000 0x22000000 0x210000; bootm"
#define CONFIG_BOOTARGS		"console=ttyS0,115200 " \
				"root=/dev/mtdblock0 " \
				"mtdparts=atmel_nand:-(root) "\
				"rw rootfstype=jffs2"

#else /* CONFIG_SYS_USE_NANDFLASH */

/* bootstrap + u-boot + env + linux in nandflash */
#define CONFIG_ENV_IS_IN_NAND	1
#define CONFIG_ENV_OFFSET		0x60000
#define CONFIG_ENV_OFFSET_REDUND	0x60000
#define CONFIG_ENV_SIZE		0x20000		/* 1 sector = 128 kB */
//#define CONFIG_BOOTCOMMAND	"nand read 0x72000000 0x200000 0x200000; bootm"
/*pi#define CONFIG_BOOTARGS		"console=ttyS0,115200 " \
				"root=/dev/mtdblock5 " \
				"mtdparts=atmel_nand:128k(bootstrap)ro, \
				256k(uboot)ro,128k(env1)ro,128k(env2)ro, \
				2M(linux),-(root) " \
				"rw rootfstype=jffs2"*/
#define CONFIG_BOOTARGS		"console=ttyS0,115200 " \
				"root=/dev/ram0 rw " \
				"initrd=0x73100000,0x800000 " \
				"mem=64M"

#endif

#define CONFIG_BAUDRATE		115200
#define CONFIG_SYS_BAUDRATE_TABLE	{115200 , 19200, 38400, 57600, 9600 }

#define CONFIG_SYS_PROMPT		"U-Boot> "
#define CONFIG_SYS_CBSIZE		256
#define CONFIG_SYS_MAXARGS		16
#define CONFIG_SYS_PBSIZE		(CONFIG_SYS_CBSIZE + sizeof(CONFIG_SYS_PROMPT) + 16)
#define CONFIG_SYS_LONGHELP		1
#define CONFIG_CMDLINE_EDITING	1
#define CONFIG_AUTO_COMPLETE
#define CONFIG_SYS_HUSH_PARSER
#define CONFIG_SYS_PROMPT_HUSH_PS2	"> "

#define CONFIG_BOOTCOMMAND "run nand_boot"

#define CONFIG_EXTRA_ENV_SETTINGS \
    "tftp_boot=tftpboot 70400000 zlinux; bootm 70400000\0" \
    "system_update=nand erase 80000 790000; tftpboot 70400000 zlinux; nand write 70400000 80000 790000; run nand_boot\0" \
    "nand_boot=nand read 70400000 80000 790000; bootm 70400000\0" \
    "uboot_update= tftpboot 70200000 uboot; nand erase 20000 40000; nand write 70200000 20000 40000; reset\0" \
    "bootstrap_update= tftpboot 70200000 bootstrap; nand erase 0 20000; nand write 70200000 0 20000; reset\0" \
    "clean_env= nand erase 60000 20000\0" \
    "safe_boot=nand read 70400000 900000 700000; bootm 70400000\0" \
    "safe_update=nand erase 900000 700000; tftpboot 70200000 zlinux_safe; nand write 70200000 900000 700000; run safe_boot\0" \
    "all_update=nand erase 80000 F00000; tftpboot 70200000 zlinux; nand write 70200000 80000 790000; tftpboot 70200000 zlinux_safe; nand write 70200000 900000 700000 run nand_boot\0" \
    "ipaddr=192.168.0.136\0" \
    "netmask=255.255.255.0\0" \
    "ethaddr=00:1f:f2:00:00:00\0" \
    "serverip=192.168.0.2\0"


/*
 * Size of malloc() pool
 */
#define CONFIG_SYS_MALLOC_LEN		ROUND(3 * CONFIG_ENV_SIZE + 128*1024, 0x1000)
#define CONFIG_SYS_GBL_DATA_SIZE	128	/* 128 bytes for initial data */

#define CONFIG_STACKSIZE	(32*1024)	/* regular stack */

#ifdef CONFIG_USE_IRQ
#error CONFIG_USE_IRQ not supported
#endif

#endif
