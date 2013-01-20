$NetBSD: patch-mozilla_dom_system_OSFileConstants.cpp,v 1.1 2013/01/20 08:33:13 ryoon Exp $

--- mozilla/dom/system/OSFileConstants.cpp.orig	2013-01-06 06:26:13.000000000 +0000
+++ mozilla/dom/system/OSFileConstants.cpp
@@ -41,6 +41,11 @@
 #include "OSFileConstants.h"
 #include "nsIOSFileConstantsService.h"
 
+#if defined(__DragonFly__) || defined(__FreeBSD__) \
+  || defined(__NetBSD__) || defined(__OpenBSD__)
+#define __dd_fd dd_fd
+#endif
+
 /**
  * This module defines the basic libc constants (error numbers, open modes,
  * etc.) used by OS.File and possibly other OS-bound JavaScript libraries.
