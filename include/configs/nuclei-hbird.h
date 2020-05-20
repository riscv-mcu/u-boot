/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Copyright (c) 2020 Nuclei System Technology
 *
 * Authors:
 *   Ruigang Wan <rgwan@nucleisys.com>
 */

#ifndef __CONFIG_H
#define __CONFIG_H

#include <linux/sizes.h>

#define CONFIG_SYS_SDRAM_BASE		0xA0000000
#define CONFIG_SYS_INIT_SP_ADDR		(CONFIG_SYS_SDRAM_BASE + SZ_2M)

#define CONFIG_SYS_LOAD_ADDR		(CONFIG_SYS_SDRAM_BASE + SZ_2M)

#define CONFIG_SYS_MALLOC_LEN		SZ_8M

#define CONFIG_SYS_BOOTM_LEN		SZ_64M

#define CONFIG_STANDALONE_LOAD_ADDR	0xA0200000

/* Environment options */

#define BOOT_TARGET_DEVICES(func) \
	func(MMC, mmc, 0)

#include <config_distro_bootcmd.h>

#define CONFIG_EXTRA_ENV_SETTINGS \
	"fdt_high=0xffffffffffffffff\0" \
	"initrd_high=0xffffffffffffffff\0" \
	"kernel_addr_r=0xA4000000\0" \
	"fdt_addr_r=0xA8000000\0" \
	"scriptaddr=0xA8100000\0" \
	"pxefile_addr_r=0xA8200000\0" \
	"ramdisk_addr_r=0xA8300000\0" \
	BOOTENV

#define CONFIG_PREBOOT \
	"setenv fdt_addr ${fdtcontroladdr};" \
	"fdt addr ${fdtcontroladdr};"

#endif /* __CONFIG_H */
