$NetBSD: patch-v8_src_base_platform_memory.h,v 1.1 2025/02/06 09:58:36 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- v8/src/base/platform/memory.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ v8/src/base/platform/memory.h
@@ -21,13 +21,13 @@
 #include <malloc/malloc.h>
 #elif V8_OS_OPENBSD
 #include <sys/malloc.h>
-#elif V8_OS_ZOS
+#elif (V8_OS_ZOS || V8_OS_BSD)
 #include <stdlib.h>
 #else
 #include <malloc.h>
 #endif
 
-#if (V8_OS_POSIX && !V8_OS_AIX && !V8_OS_SOLARIS && !V8_OS_ZOS && !V8_OS_OPENBSD) || V8_OS_WIN
+#if (V8_OS_POSIX && !V8_OS_AIX && !V8_OS_SOLARIS && !V8_OS_ZOS && !V8_OS_BSD) || V8_OS_WIN
 #define V8_HAS_MALLOC_USABLE_SIZE 1
 #endif
 
