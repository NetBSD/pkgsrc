$NetBSD: patch-Source_bmalloc_bmalloc_AvailableMemory.cpp,v 1.1 2022/05/29 17:47:15 leot Exp $

sysinfo() is used only on FreeBSD and Linux.

Shared upstream via <https://bugs.webkit.org/show_bug.cgi?id=241077>.

--- Source/bmalloc/bmalloc/AvailableMemory.cpp.orig	2022-02-23 08:59:06.000000000 +0000
+++ Source/bmalloc/bmalloc/AvailableMemory.cpp
@@ -44,15 +44,16 @@
 #import <mach/mach_error.h>
 #import <math.h>
 #elif BOS(UNIX)
-#include <sys/sysinfo.h>
 #if BOS(LINUX)
 #include <algorithm>
 #include <fcntl.h>
+#include <sys/sysinfo.h>
 #elif BOS(FREEBSD)
 #include "VMAllocate.h"
 #include <sys/sysctl.h>
 #include <sys/types.h>
 #include <sys/user.h>
+#include <sys/sysinfo.h>
 #endif
 #include <unistd.h>
 #endif
