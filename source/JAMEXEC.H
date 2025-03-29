/*****************************************************************************/
/*                                                                           */
/* Module:           jamexec.h                                               */
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
/* Description:      Prototypes for statement execution functions            */
/*                                                                           */
/*****************************************************************************/

#ifndef INC_JAMEXEC_H
#define INC_JAMEXEC_H

/****************************************************************************/
/*																			*/
/*	Global variables														*/
/*																			*/
/****************************************************************************/

extern long jam_current_file_position;

extern long jam_current_statement_position;

extern long jam_next_statement_position;

extern unsigned int jam_statement_buffer_size;

/****************************************************************************/
/*																			*/
/*	Function Prototypes														*/
/*																			*/
/****************************************************************************/

JAM_RETURN_TYPE jam_init_statement_buffer
(
	char **statement_buffer,
	unsigned int *statement_buffer_size
);

void jam_free_statement_buffer
(
	char **statement_buffer,
	unsigned int *statement_buffer_size
);

JAM_RETURN_TYPE jam_get_statement
(
	char *statement_buffer,
	char *label_buffer
);

long jam_get_line_of_position
(
	long position
);

JAME_INSTRUCTION jam_get_instruction
(
	char *statement_buffer
);

int jam_skip_instruction_name
(
	char *statement_buffer
);

#endif /* INC_JAMEXEC_H */
