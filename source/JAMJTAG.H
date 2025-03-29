/*****************************************************************************/
/*                                                                           */
/* Module:           jamjtag.h                                               */
/*                                                                           */
/*                   Copyright 2025 Altera Corporation                       */
/*                                                                           */
/* SPDX-License-Identifier: MIT-0                                            */
/*                                                                           */
/* Permission is hereby granted, free of charge, to any person obtaining a   */
/* copy of this software and associated documentation files (the             */
/* "Software"),to deal in the Software without restriction, including        */
/* without limitation the rights to use, copy, modify, merge, publish,       */
/* distribute, sublicense, and/or sell copies of the Software, and to permit */
/* persons to whom the Software is furnished to do so.                       */
/*                                                                           */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS   */
/* OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF                */
/* MERCHANTABILITY,  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   */
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY      */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT */
/* OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR  */
/* THE USE OR OTHER DEALINGS IN THE SOFTWARE.                                */
/*                                                                           */
/* Description:      Definitions of JTAG constants, types, and functions     */
/*                                                                           */
/*****************************************************************************/

#ifndef INC_JAMJTAG_H
#define INC_JAMJTAG_H

/****************************************************************************/
/*																			*/
/*	Constant definitions													*/
/*																			*/
/****************************************************************************/

#define JAMC_MAX_JTAG_STATE_LENGTH 9

/****************************************************************************/
/*																			*/
/*	Enumerated Types														*/
/*																			*/
/****************************************************************************/

typedef enum
{
	JAM_ILLEGAL_JTAG_STATE = -1,
	RESET = 0,
	IDLE = 1,
	DRSELECT = 2,
	DRCAPTURE = 3,
	DRSHIFT = 4,
	DREXIT1 = 5,
	DRPAUSE = 6,
	DREXIT2 = 7,
	DRUPDATE = 8,
	IRSELECT = 9,
	IRCAPTURE = 10,
	IRSHIFT = 11,
	IREXIT1 = 12,
	IRPAUSE = 13,
	IREXIT2 = 14,
	IRUPDATE = 15

} JAME_JTAG_STATE;

/****************************************************************************/
/*																			*/
/*	Function Prototypes														*/
/*																			*/
/****************************************************************************/

JAM_RETURN_TYPE jam_init_jtag
(
	void
);

JAME_JTAG_STATE jam_get_jtag_state_from_name
(
	char *name
);

JAM_RETURN_TYPE jam_set_drstop_state
(
	JAME_JTAG_STATE state
);

JAM_RETURN_TYPE jam_set_irstop_state
(
	JAME_JTAG_STATE state
);

JAM_RETURN_TYPE jam_set_dr_preamble
(
	int count,
	int start_index,
	long *data
);

JAM_RETURN_TYPE jam_set_ir_preamble
(
	int count,
	int start_index,
	long *data
);

JAM_RETURN_TYPE jam_set_dr_postamble
(
	int count,
	int start_index,
	long *data
);

JAM_RETURN_TYPE jam_set_ir_postamble
(
	int count,
	int start_index,
	long *data
);

JAM_RETURN_TYPE jam_goto_jtag_state
(
	JAME_JTAG_STATE state
);

JAM_RETURN_TYPE jam_do_wait_cycles
(
	long cycles,
	JAME_JTAG_STATE wait_state
);

JAM_RETURN_TYPE jam_do_wait_microseconds
(
	long microseconds,
	JAME_JTAG_STATE wait_state
);

JAM_RETURN_TYPE jam_do_irscan
(
	long count,
	long *data,
	long start_index
);

JAM_RETURN_TYPE jam_swap_ir
(
	long count,
	long *in_data,
	long in_index,
	long *out_data,
	long out_index
);

JAM_RETURN_TYPE jam_do_drscan
(
	long count,
	long *data,
	long start_index
);

JAM_RETURN_TYPE jam_swap_dr
(
	long count,
	long *in_data,
	long in_index,
	long *out_data,
	long out_index
);

void jam_free_jtag_padding_buffers
(
	int reset_jtag
);

#endif /* INC_JAMJTAG_H */
