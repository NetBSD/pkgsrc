$NetBSD: patch-third__party_libunwind_src_src_Registers.hpp,v 1.4 2026/04/21 15:21:21 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/libunwind/src/src/Registers.hpp.orig	2026-04-14 23:31:37.000000000 +0200
+++ third_party/libunwind/src/src/Registers.hpp
@@ -20,7 +20,7 @@
 #include "libunwind_ext.h"
 #include "shadow_stack_unwind.h"
 
-#if __has_include(<sys/auxv.h>)
+#if __has_include(<sys/auxv.h>) && !defined(__OpenBSD__) && !defined(__FreeBSD__)
 #include <sys/auxv.h>
 #define HAVE_SYS_AUXV_H
 #endif
