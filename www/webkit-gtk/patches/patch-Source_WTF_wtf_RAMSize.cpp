$NetBSD: patch-Source_WTF_wtf_RAMSize.cpp,v 1.1 2018/10/25 09:58:18 leot Exp $

Add support for NetBSD.

--- Source/WTF/wtf/RAMSize.cpp.orig	2017-08-03 11:00:07.000000000 +0000
+++ Source/WTF/wtf/RAMSize.cpp
@@ -32,7 +32,9 @@
 #if OS(WINDOWS)
 #include <windows.h>
 #elif defined(USE_SYSTEM_MALLOC) && USE_SYSTEM_MALLOC
-#if OS(UNIX)
+#if OS(NETBSD)
+#include <sys/sysctl.h>
+#elif OS(UNIX)
 #include <sys/sysinfo.h>
 #endif // OS(UNIX)
 #else
@@ -41,7 +43,7 @@
 
 namespace WTF {
 
-#if OS(WINDOWS)
+#if OS(WINDOWS) || (OS(NETBSD) && defined(USE_SYSTEM_MALLOC) && USE_SYSTEM_MALLOC)
 static const size_t ramSizeGuess = 512 * MB;
 #endif
 
@@ -55,13 +57,22 @@ static size_t computeRAMSize()
         return ramSizeGuess;
     return status.ullTotalPhys;
 #elif defined(USE_SYSTEM_MALLOC) && USE_SYSTEM_MALLOC
-#if OS(UNIX)
+#if OS(NETBSD)
+    int mib[2];
+    size_t len, totalram;
+    mib[0] = CTL_HW;
+    mib[1] = HW_USERMEM64;
+    len = sizeof(totalram);
+    if (sysctl(mib, 2, &totalram, &len, NULL, 0))
+        return ramSizeGuess;
+    return totalram;
+#elif OS(UNIX)
     struct sysinfo si;
     sysinfo(&si);
     return si.totalram * si.mem_unit;
 #else
 #error "Missing a platform specific way of determining the available RAM"
-#endif // OS(UNIX)
+#endif // USE_SYSTEM_MALLOC
 #else
     return bmalloc::api::availableMemory();
 #endif
