#!/bin/sh

# $NetBSD: binpatch-x86-unknown-linux2.2.5-7.1.sh,v 1.1 2004/07/27 04:36:06 atatat Exp $
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

# % objdump -h libsoftokn3.so
# libsoftokn3.so:     file format elf32-i386
#
file=$2
size=417992

# % objdump -h libsoftokn3.so
# Sections:
# Idx Name          Size      VMA       LMA       File off  Algn
# ...
#  10 .text         0004d1e0  00003e10  00003e10  00003e10  2**4
#                   CONTENTS, ALLOC, LOAD, READONLY, CODE
#
# % pmap -a 13475 | grep libsoftokn3.so
# bbb3a000-bbb9afff     388k 00000000 r-xp+ (rwx) 1/0/0 00:04   77819 - /usr/pkg/lib/netscape/netscape7/libsoftokn3.so [0xc64927f0]
# bbb9b000-bbb9efff      16k 00061000 rw-p- (rwx) 1/0/0 00:04   77819 - /usr/pkg/lib/netscape/netscape7/libsoftokn3.so [0xc64927f0]
#
# % objdump -d -j .text --adjust-vma=0xbbb3a000 libsoftokn3.so
# ...
# bbb62a3d:       6a 00                   push   $0x0
# bbb62a3f:       e8 f8 ad fd ff          call   0xbbb3d83c
# bbb62a44:       e8 23 af fd ff          call   0xbbb3d96c
# ...
#
#  ins addr  -    lma     - adjust-vma +  file off
# 0xbbb62a3d - 0x00003e10 - 0xbbb3a000 + 0x00003e10 = 0x00028a3d
#
offset=0x00028a3d

# compare the push/call/call instruction bytes
#
compare=6a00e8f8adfdffe823affdff

# the push instruction is two bytes long
#
skip=2

# five nops will overwrite the call to 0xbbb3d83c
#
replace=9090909090

binpatch \
    file=$file \
    size=$size \
    offset=$offset \
    compare=$compare \
    skip=$skip \
    replace=$replace
