#!/bin/sh

# $NetBSD: binpatch-x86-bsdi-bsd2-4.75.sh,v 1.1 2004/07/23 03:46:06 atatat Exp $
#
# ------------------------------------------------------------------------
# "THE BEER-WARE LICENSE" (Revision 42):
# Andrew Brown <atatat@NetBSD.org> wrote this file.  As long as you
# retain this notice you can do whatever you want with this stuff.
# If we meet some day, and you think this stuff is worth it, you can
# buy me a beer in return.
# ------------------------------------------------------------------------

PATH=$1/bin:$PATH
export PATH

# conversion from "386 compact demand paged pure executable" to "ELF
# 32-bit LSB relocatable, Intel 80386, version 1 (SYSV), not stripped"
# at the same load address so that objdump can disassemble the binary
# adds 0x34, so keep that in mind.  the size below is taken from
# before the objcopy.
#
# % objcopy -I binary -O elf32-i386 -B i386 \
#   --rename-section .data=.text,contents,alloc,load,readonly,code \
#   --adjust-vma 0x1000 netscape
#
# % objdump -h netscape
# netscape:     file format elf32-i386
#
file=$2
size=10739712

# % objdump -h netscape
# Sections:
# Idx Name          Size      VMA       LMA       File off  Algn
#   0 .text         00a3e000  00001000  00001000  00000034  2**0
#                   CONTENTS, ALLOC, LOAD, READONLY, CODE
# ...
#
# % objdump -d -j .text netscape
# ...
#   76df83:       68 bb 33 a2 00          push   $0xa233bb
#   76df88:       e8 57 fd ff ff          call   76dce4 <_binary_netscape_start+0x76cce4>
#   76df8d:       89 c6                   mov    %eax,%esi
# ...
#
# 0x0076df83 - 0x00001000 (+ 0x00000034) = 0x0076cf83
#
# note: 0x34 not added since objcopy added that overhead
#
offset=0x0076cf83

# compare the push/call/mov instruction bytes
#
compare=68bb33a200e857fdffff89c6

# the push instruction is five bytes long
#
skip=5

# five nops will overwrite the call to 0x76dce4
#
replace=9090909090

binpatch \
    file=$file \
    size=$size \
    offset=$offset \
    compare=$compare \
    skip=$skip \
    replace=$replace
