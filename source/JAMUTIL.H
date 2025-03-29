/*****************************************************************************/
/*                                                                           */
/* Module:           jamutil.h                                               */
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
/* Description:      Prototypes for miscelleneous utility functions          */
/*                                                                           */
/*****************************************************************************/

#ifndef INC_JAMUTIL_H
#define INC_JAMUTIL_H

/****************************************************************************/
/*																			*/
/*	Function Prototypes														*/
/*																			*/
/****************************************************************************/

char jam_toupper(char ch);

int jam_iscntrl(char ch);

int jam_isalpha(char ch);

int jam_isdigit(char ch);

int jam_isalnum(char ch);

int jam_isspace(char ch);

int jam_is_name_char(char ch);

int jam_is_hex_char(char ch);

int jam_strlen(char *string);

long jam_atol(char *string);

void jam_ltoa(char *string, long value);

int jam_strcmp(char *left, char *right);

int jam_stricmp(char *left, char *right);

int jam_strncmp(char *left, char *right, int count);

int jam_strnicmp(char *left, char *right, int count);

void jam_strcpy(char *dest, char *source);

void jam_strncpy(char *dest, char *source, int count);

#endif /* INC_JAMUTIL_H */
