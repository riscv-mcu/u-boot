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
	writel (0xec000000, 0x10012008);
	writel (0x10000000, 0x10012004);
	writel (0xfc030000, 0x10012038);
	printf ("Hummingbird Platform Initialized\n");
	return 0;
}
