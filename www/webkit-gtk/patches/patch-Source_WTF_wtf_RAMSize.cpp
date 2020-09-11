$NetBSD: patch-Source_WTF_wtf_RAMSize.cpp,v 1.5 2020/09/11 14:47:35 leot Exp $

Add support for NetBSD and SunOS.

--- Source/WTF/wtf/RAMSize.cpp.orig	2020-08-12 09:17:54.000000000 +0000
+++ Source/WTF/wtf/RAMSize.cpp
@@ -34,13 +34,19 @@
 #if OS(LINUX)
 #include <sys/sysinfo.h>
 #endif // OS(LINUX)
+#if OS(SOLARIS)
+#include <unistd.h>
+#endif
+#if OS(NETBSD)
+#include <sys/sysctl.h>
+#endif // OS(NETBSD)
 #else
 #include <bmalloc/bmalloc.h>
 #endif
 
 namespace WTF {
 
-#if OS(WINDOWS)
+#if OS(WINDOWS) || (OS(NETBSD) && defined(USE_SYSTEM_MALLOC) && USE_SYSTEM_MALLOC)
 static constexpr size_t ramSizeGuess = 512 * MB;
 #endif
 
@@ -58,9 +64,20 @@ static size_t computeRAMSize()
     struct sysinfo si;
     sysinfo(&si);
     return si.totalram * si.mem_unit;
+#elif OS(SOLARIS)
+    return (sysconf(_SC_PHYS_PAGES) * sysconf(_SC_PAGESIZE));
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
-#endif // OS(LINUX) || OS(FREEBSD)
+#endif // USE_SYSTEM_MALLOC
 #else
     return bmalloc::api::availableMemory();
 #endif
