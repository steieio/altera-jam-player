/*****************************************************************************/
/*                                                                           */
/* Module:           jamarray.h                                              */
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
/* Description: Constants and function prototypes for array support          */
/*                                                                           */
/*****************************************************************************/

#ifndef INC_JAMARRAY_H
#define INC_JAMARRAY_H

/****************************************************************************/
/*																			*/
/*	Function Prototypes														*/
/*																			*/
/****************************************************************************/

JAM_RETURN_TYPE jam_read_boolean_array_data
(
	JAMS_HEAP_RECORD *heap_record,
	char *statement_buffer
);

JAM_RETURN_TYPE jam_read_integer_array_data
(
	JAMS_HEAP_RECORD *heap_record,
	char *statement_buffer
);

JAM_RETURN_TYPE jam_get_array_value
(
	JAMS_SYMBOL_RECORD *symbol_record,
	long index,
	long *value
);

#endif	/* INC_JAMARRAY_H */
