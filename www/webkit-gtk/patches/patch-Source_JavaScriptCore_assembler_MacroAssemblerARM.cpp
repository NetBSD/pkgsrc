$NetBSD: patch-Source_JavaScriptCore_assembler_MacroAssemblerARM.cpp,v 1.1 2013/08/14 22:16:54 jmcneill Exp $

--- Source/JavaScriptCore/assembler/MacroAssemblerARM.cpp.orig	2012-11-23 20:12:15.000000000 +0000
+++ Source/JavaScriptCore/assembler/MacroAssemblerARM.cpp
@@ -37,6 +37,8 @@
 #include <unistd.h>
 #include <elf.h>
 #include <asm/hwcap.h>
+#elif OS(NETBSD)
+#include <sys/sysctl.h>
 #endif
 
 namespace JSC {
@@ -57,6 +59,16 @@ static bool isVFPPresent()
     }
 #endif
 
+#if OS(NETBSD)
+    size_t len;
+    int flag;
+
+    len = sizeof(flag);
+    if (sysctlbyname("machdep.fpu_present", &flag, &len, NULL, 0) == 0) {
+        return flag == 1;
+    }
+#endif
+
 #if (COMPILER(RVCT) && defined(__TARGET_FPU_VFP)) || (COMPILER(GCC) && defined(__VFP_FP__))
     return true;
 #else
