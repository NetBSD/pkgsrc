#!/bin/sh

# $NetBSD: binpatch-x86-unknown-linux2.2-4.80.sh,v 1.1 2004/07/23 03:46:06 atatat Exp $
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

# % objdump -h netscape
# netscape:     file format elf32-i386
#
file=$2
size=13823336

# % objdump -h netscape
# Sections:
# Idx Name          Size      VMA       LMA       File off  Algn
# ...
#  12 .text         006c77ac  082819e0  082819e0  002399e0  2**4
#                   CONTENTS, ALLOC, LOAD, READONLY, CODE
#
# % objdump -d -j .text netscape
# ...
#  884f3e9:       6a 00                   push   $0x0
#  884f3eb:       e8 24 06 a3 ff          call   0x827fa14
#  884f3f0:       e8 1f 0c a3 ff          call   0x8280014
# ...
#
# 0x00884f3e9 - 0x0082819e0 + 0x002399e0 = 0x008073e9
#
offset=0x008073e9

# compare the push/call/call instruction bytes
#
compare=6a00e82406a3ffe81f0ca3ff

# the push instruction is two bytes long
#
skip=2

# five nops will overwrite the call to 0x827fa14
#
replace=9090909090

binpatch \
    file=$file \
    size=$size \
    offset=$offset \
    compare=$compare \
    skip=$skip \
    replace=$replace
