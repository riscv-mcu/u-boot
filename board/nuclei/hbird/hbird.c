// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright (c) 2019 Nuclei System Technologies
 *
 * Authors:
 *   Ruigang Wan <rgwan@nucleisys.com>
 */

#include <common.h>
#include <dm.h>
#include <linux/delay.h>
#include <linux/io.h>


int board_init(void)
{
	/* Set Pinmux to enable QSPI2 for SD boot */
	writel (0x01, (void *)0x10034000);
	writel (0xec000000, (void *)0x10012008);
	writel (0x10000000, (void *)0x10012004);
	writel (0xfc030000, (void *)0x10012038);
	writel (0x00, (void *)0x10034000); /* NUSPI Prescaler = 4 */
	__asm__ __volatile__ ("fence w,o" : : : "memory");

	printf ("Board: Initialized\n");
	return 0;
}
