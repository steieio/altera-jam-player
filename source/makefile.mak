#
# Module:            makefile
#
#                   Copyright 2025 Altera Corporation                       
#                                                                           
# SPDX-License-Identifier: MIT-0
#
# Permission is hereby granted, free of charge, to any person obtaining a   
# copy of this software and associated documentation files (the             
# "Software"),to deal in the Software without restriction, including        
# without limitation the rights to use, copy, modify, merge, publish,       
# distribute, sublicense, and/or sell copies of the Software, and to permit 
# persons to whom the Software is furnished to do so.                       
#                                                                           
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS   
# OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF                
# MERCHANTABILITY,  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   
# IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY      
# CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT 
# OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR  
# THE USE OR OTHER DEALINGS IN THE SOFTWARE.                                
#                                                                           
#
# Description:       Makefile for JAM Interpreter
#

OBJS = \
	jamstub.obj \
	jamexec.obj \
	jamnote.obj \
	jamcrc.obj \
	jamsym.obj \
	jamstack.obj \
	jamheap.obj \
	jamarray.obj \
	jamcomp.obj \
	jamjtag.obj \
	jamutil.obj \
	jamexp.obj

%.obj : %.c
	cl /W4 /c /O2 /ML /DWINNT $<

# LINK: add appropriate linker command here

jam.exe : $(OBJS)
	link $(OBJS) advapi32.lib /out:jam.exe

# Dependencies:

jamstub.obj : \
	jamstub.c \
	jamport.h \
	jamexprt.h

jamexec.obj : \
	jamexec.c \
	jamport.h \
	jamexprt.h \
	jamdefs.h \
	jamexec.h \
	jamutil.h \
	jamexp.h \
	jamsym.h \
	jamstack.h \
	jamheap.h \
	jamarray.h \
	jamjtag.h

jamnote.obj : \
	jamnote.c \
	jamexprt.h \
	jamdefs.h \
	jamexec.h \
	jamutil.h

jamcrc.obj : \
	jamcrc.c \
	jamexprt.h \
	jamdefs.h \
	jamexec.h \
	jamutil.h

jamsym.obj : \
	jamsym.c \
	jamexprt.h \
	jamdefs.h \
	jamsym.h \
	jamheap.h \
	jamutil.h

jamstack.obj : \
	jamstack.c \
	jamexprt.h \
	jamdefs.h \
	jamutil.h \
	jamsym.h \
	jamstack.h

jamheap.obj : \
	jamheap.c \
	jamport.h \
	jamexprt.h \
	jamdefs.h \
	jamsym.h \
	jamstack.h \
	jamheap.h \
	jamutil.h

jamarray.obj : \
	jamarray.c \
	jamexprt.h \
	jamdefs.h \
	jamexec.h \
	jamexp.h \
	jamsym.h \
	jamstack.h \
	jamheap.h \
	jamutil.h \
	jamcomp.h \
	jamarray.h

jamcomp.obj : \
	jamcomp.c \
	jamdefs.h \
	jamcomp.h

jamjtag.obj : \
	jamjtag.c \
	jamexprt.h \
	jamdefs.h \
	jamsym.h \
	jamutil.h \
	jamjtag.h

jamutil.obj : \
	jamutil.c \
	jamutil.h

jamexp.obj : \
	jamexp.c \
	jamexprt.h \
	jamdefs.h \
	jamexp.h \
	jamsym.h \
	jamheap.h \
	jamarray.h \
	jamutil.h \
	jamytab.h
