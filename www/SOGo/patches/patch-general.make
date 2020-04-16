$NetBSD: patch-general.make,v 1.1 2020/04/16 09:42:42 manu Exp $

Prevent -frecord-gcc-switches to be added, because pkgsrc
checks choke on the presence of working directory strings
inside the binaries.

--- general.make.orig	2020-04-15 11:01:50.012506113 +0200
+++ general.make	2020-04-15 11:02:01.180611005 +0200
@@ -22,6 +22,6 @@
 # Ensure we store in the ELF files minimal debugging
 # information plus the compiler flags used; that can
 # be afterwards read with:
 # readelf -p .GCC.command.line /path/to/elf_file
-ADDITIONAL_OBJCFLAGS += -g $(call cc-option,-frecord-gcc-switches)
+ADDITIONAL_OBJCFLAGS += -g $(call cc-option)
 
