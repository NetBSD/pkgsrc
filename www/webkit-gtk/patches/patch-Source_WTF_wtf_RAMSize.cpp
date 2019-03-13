$NetBSD: patch-Source_WTF_wtf_RAMSize.cpp,v 1.2 2019/03/13 20:49:40 leot Exp $

Add support for NetBSD.

--- Source/WTF/wtf/RAMSize.cpp.orig	2019-02-12 11:21:17.000000000 +0000
+++ Source/WTF/wtf/RAMSize.cpp
@@ -35,13 +35,16 @@
 #if OS(LINUX)
 #include <sys/sysinfo.h>
 #endif // OS(LINUX)
+#if OS(NETBSD)
+#include <sys/sysctl.h>
+#endif // OS(NETBSD)
 #else
 #include <bmalloc/bmalloc.h>
 #endif
 
 namespace WTF {
 
-#if OS(WINDOWS)
+#if OS(WINDOWS) || (OS(NETBSD) && defined(USE_SYSTEM_MALLOC) && USE_SYSTEM_MALLOC)
 static const size_t ramSizeGuess = 512 * MB;
 #endif
 
@@ -59,9 +62,18 @@ static size_t computeRAMSize()
     struct sysinfo si;
     sysinfo(&si);
     return si.totalram * si.mem_unit;
+#elif OS(NETBSD)
+    int mib[2];
+    size_t len, totalram;
+    mib[0] = CTL_HW;
+    mib[1] = HW_USERMEM64;
+    len = sizeof(totalram);
+    if (sysctl(mib, 2, &totalram, &len, NULL, 0))
+        return ramSizeGuess;
+    return totalram;
 #else
 #error "Missing a platform specific way of determining the available RAM"
-#endif // OS(LINUX)
+#endif // USE_SYSTEM_MALLOC
 #else
     return bmalloc::api::availableMemory();
 #endif
