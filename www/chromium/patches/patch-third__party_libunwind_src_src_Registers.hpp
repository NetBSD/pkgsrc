$NetBSD: patch-third__party_libunwind_src_src_Registers.hpp,v 1.2 2026/03/14 12:40:42 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/libunwind/src/src/Registers.hpp.orig	2026-03-11 22:12:25.000000000 +0000
+++ third_party/libunwind/src/src/Registers.hpp
@@ -20,7 +20,7 @@
 #include "libunwind_ext.h"
 #include "shadow_stack_unwind.h"
 
-#if __has_include(<sys/auxv.h>)
+#if __has_include(<sys/auxv.h>) && !defined(__OpenBSD__) && !defined(__FreeBSD__)
 #include <sys/auxv.h>
 #define HAVE_SYS_AUXV_H
 #endif
