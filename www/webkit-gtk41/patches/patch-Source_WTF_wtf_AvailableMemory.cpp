$NetBSD: patch-Source_WTF_wtf_AvailableMemory.cpp,v 1.1 2026/09/22 12:27:02 wiz Exp $

Add NetBSD support for memoryStatus.

--- Source/WTF/wtf/AvailableMemory.cpp.orig	2026-09-16 19:58:03.960294163 +0000
+++ Source/WTF/wtf/AvailableMemory.cpp
@@ -50,6 +50,9 @@
 #include <sys/sysctl.h>
 #include <sys/types.h>
 #include <sys/user.h>
+#elif OS(NETBSD)
+#include <sys/sysctl.h>
+#include <sys/types.h>
 #endif
 #include <unistd.h>
 #elif OS(WINDOWS)
@@ -182,7 +185,7 @@ size_t availableMemory()
     return availableMemory;
 }
 
-#if PLATFORM(IOS_FAMILY) || OS(LINUX) || OS(FREEBSD)
+#if PLATFORM(IOS_FAMILY) || OS(LINUX) || OS(FREEBSD) || OS(NETBSD)
 MemoryStatus memoryStatus()
 {
 #if PLATFORM(IOS_FAMILY)
@@ -204,6 +207,15 @@ MemoryStatus memoryStatus()
     size_t memoryFootprint = 0;
     if (!sysctl(mib.data(), mib.size(), &info, &infolen, nullptr, 0))
         memoryFootprint = static_cast<size_t>(info.ki_rssize) * pageSize();
+#elif OS(NETBSD)
+    struct kinfo_proc2 info;
+    size_t infolen = sizeof(info);
+
+    std::array<int, 4> mib { CTL_KERN, KERN_PROC2, KERN_PROC_PID, getpid() };
+
+    size_t memoryFootprint = 0;
+    if (!sysctl(mib.data(), mib.size(), &info, &infolen, nullptr, 0))
+        memoryFootprint = static_cast<size_t>(info.p_vm_rssize) * pageSize();
 #endif
 
     double percentInUse = static_cast<double>(memoryFootprint) / static_cast<double>(availableMemory());
