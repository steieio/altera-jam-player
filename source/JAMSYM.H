/*****************************************************************************/
/*                                                                           */
/* Module:           jamsym.h                                                */
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
/* Description:      Prototypes for symbol-table management functions        */
/*                                                                           */
/* Revisions:        1.1 added jam_free_symbol_table()                       */
/*                                                                           */
/*****************************************************************************/

#ifndef INC_JAMSYM_H
#define INC_JAMSYM_H

/****************************************************************************/
/*																			*/
/*	Type definitions														*/
/*																			*/
/****************************************************************************/

/* types of symbolic names */
typedef enum
{
	JAM_ILLEGAL_SYMBOL_TYPE = 0,
	JAM_LABEL,
	JAM_INTEGER_SYMBOL,
	JAM_BOOLEAN_SYMBOL,
	JAM_INTEGER_ARRAY_WRITABLE,
	JAM_BOOLEAN_ARRAY_WRITABLE,
	JAM_INTEGER_ARRAY_INITIALIZED,
	JAM_BOOLEAN_ARRAY_INITIALIZED,
	JAM_DATA_BLOCK,
	JAM_PROCEDURE_BLOCK,
	JAM_SYMBOL_MAX

} JAME_SYMBOL_TYPE;

/* symbol record structure */
typedef struct JAMS_SYMBOL_STRUCT
{
	char name[JAMC_MAX_NAME_LENGTH + 1];
	JAME_SYMBOL_TYPE type;
	long value;
	long position;
	struct JAMS_SYMBOL_STRUCT *parent;
	struct JAMS_SYMBOL_STRUCT *next;

} JAMS_SYMBOL_RECORD;

/****************************************************************************/
/*																			*/
/*	Global variables														*/
/*																			*/
/****************************************************************************/

extern JAMS_SYMBOL_RECORD **jam_symbol_table;

extern void *jam_symbol_bottom;

extern JAMS_SYMBOL_RECORD *jam_current_block;

extern int jam_version;

/****************************************************************************/
/*																			*/
/*	Function prototypes														*/
/*																			*/
/****************************************************************************/

JAM_RETURN_TYPE jam_init_symbol_table
(
	void
);

void jam_free_symbol_table
(
	void
);

JAM_RETURN_TYPE jam_add_symbol
(
	JAME_SYMBOL_TYPE type,
	char *name,
	long value,
	long position
);

JAM_RETURN_TYPE jam_get_symbol_value
(
	JAME_SYMBOL_TYPE type,
	char *name,
	long *value
);

JAM_RETURN_TYPE jam_set_symbol_value
(
	JAME_SYMBOL_TYPE type,
	char *name,
	long value
);

JAM_RETURN_TYPE jam_get_symbol_record
(
	char *name,
	JAMS_SYMBOL_RECORD **symbol_record
);

#endif /* INC_JAMSYM_H */
