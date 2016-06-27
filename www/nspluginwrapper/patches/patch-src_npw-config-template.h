$NetBSD: patch-src_npw-config-template.h,v 1.1 2016/06/27 11:03:29 tnn Exp $

Make sure FUNC macro is defined. (exec_elf.h v1.155)

--- src/npw-config-template.h.orig	2011-07-01 03:18:57.000000000 +0000
+++ src/npw-config-template.h
@@ -19,7 +19,7 @@
  */
 
 #ifdef ELF_CLASS
-#ifndef ElfW
+#if !defined(ElfW) || defined(__NetBSD__)
 # if ELF_CLASS == ELFCLASS32
 #  define ElfW(x)		Elf32_ ## x
 #  define ELFW(x)		ELF32_ ## x
