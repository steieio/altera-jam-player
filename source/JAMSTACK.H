/*****************************************************************************/
/*                                                                           */
/* Module:           jamstack.h                                              */
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
/* Description:      Prototypes for stack management functions               */
/*                                                                           */
/* Revisions:        1.1 added jam_free_stack()                              */
/*                                                                           */
/*****************************************************************************/

#ifndef INC_JAMSTACK_H
#define INC_JAMSTACK_H

/****************************************************************************/
/*																			*/
/*	Type definitions														*/
/*																			*/
/****************************************************************************/

/* types of stack records */
typedef enum
{
	JAM_ILLEGAL_STACK_TYPE = 0,
	JAM_STACK_FOR_NEXT,
	JAM_STACK_PUSH_POP,
	JAM_STACK_CALL_RETURN,
	JAM_STACK_MAX

} JAME_STACK_RECORD_TYPE;

/* stack record structure */
typedef struct
{
	JAME_STACK_RECORD_TYPE type;
	JAMS_SYMBOL_RECORD *iterator;	/* used only for FOR/NEXT */
	long for_position;				/* used only for FOR/NEXT */
	long stop_value;				/* used only for FOR/NEXT */
	long step_value;				/* used only for FOR/NEXT */
	long push_value;				/* used only for PUSH/POP */
	long return_position;			/* used only for CALL/RETURN */

} JAMS_STACK_RECORD;

/****************************************************************************/
/*																			*/
/*	Global variables														*/
/*																			*/
/****************************************************************************/

extern JAMS_STACK_RECORD *jam_stack;

/****************************************************************************/
/*																			*/
/*	Function prototypes														*/
/*																			*/
/****************************************************************************/

JAM_RETURN_TYPE jam_init_stack
(
	void
);

void jam_free_stack
(
	void
);

JAM_RETURN_TYPE jam_push_stack_record
(
	JAMS_STACK_RECORD *stack_record
);

JAMS_STACK_RECORD *jam_peek_stack_record
(
	void
);

JAM_RETURN_TYPE jam_pop_stack_record
(
	void
);

JAM_RETURN_TYPE jam_push_fornext_record
(
	JAMS_SYMBOL_RECORD *iterator,
	long for_position,
	long stop_value,
	long step_value
);

JAM_RETURN_TYPE jam_push_pushpop_record
(
	long value
);

JAM_RETURN_TYPE jam_push_callret_record
(
	long return_position
);

#endif /* INC_JAMSTACK_H */
