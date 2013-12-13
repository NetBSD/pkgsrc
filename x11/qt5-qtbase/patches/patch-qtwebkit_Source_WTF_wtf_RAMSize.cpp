$NetBSD: patch-qtwebkit_Source_WTF_wtf_RAMSize.cpp,v 1.1 2013/12/13 14:38:35 ryoon Exp $

* Add NetBSD support

--- qtwebkit/Source/WTF/wtf/RAMSize.cpp.orig	2013-11-27 01:01:20.000000000 +0000
+++ qtwebkit/Source/WTF/wtf/RAMSize.cpp
@@ -27,7 +27,7 @@
 #include "RAMSize.h"
 
 #include "StdLibExtras.h"
-#if OS(DARWIN)
+#if OS(DARWIN) || OS(NETBSD)
 #include <sys/param.h>
 #include <sys/types.h>
 #include <sys/sysctl.h>
@@ -45,13 +45,17 @@ static const size_t ramSizeGuess = 128 *
 
 static size_t computeRAMSize()
 {
-#if OS(DARWIN)
+#if OS(DARWIN) || OS(NETBSD)
     int mib[2];
     uint64_t ramSize;
     size_t length;
 
     mib[0] = CTL_HW;
+#if OS(DARWIN)
     mib[1] = HW_MEMSIZE;
+#else
+    mib[1] = HW_PHYSMEM64;
+#endif
     length = sizeof(int64_t);
     int sysctlResult = sysctl(mib, 2, &ramSize, &length, 0, 0);
     if (sysctlResult == -1)
