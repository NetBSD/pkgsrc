$NetBSD: patch-third__party_libunwind_src_src_Registers.hpp,v 1.1 2026/02/15 09:04:11 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/libunwind/src/src/Registers.hpp.orig	2026-02-03 22:07:10.000000000 +0000
+++ third_party/libunwind/src/src/Registers.hpp
@@ -20,7 +20,7 @@
 #include "libunwind_ext.h"
 #include "shadow_stack_unwind.h"
 
-#if __has_include(<sys/auxv.h>)
+#if __has_include(<sys/auxv.h>) && !defined(__OpenBSD__) && !defined(__FreeBSD__)
 #include <sys/auxv.h>
 #define HAVE_SYS_AUXV_H
 #endif
