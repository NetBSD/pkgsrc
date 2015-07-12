$NetBSD: patch-Source_JavaScriptCore_assembler_MacroAssemblerARM.cpp,v 1.3 2015/07/12 00:44:46 wiz Exp $

--- Source/JavaScriptCore/assembler/MacroAssemblerARM.cpp.orig	2015-03-04 14:25:16.000000000 +0000
+++ Source/JavaScriptCore/assembler/MacroAssemblerARM.cpp
@@ -38,6 +38,8 @@
 #include <unistd.h>
 #include <elf.h>
 #include <asm/hwcap.h>
+#elif OS(NETBSD)
+#include <sys/sysctl.h>
 #endif
 
 namespace JSC {
@@ -58,6 +60,16 @@ static bool isVFPPresent()
     }
 #endif // OS(LINUX)
 
+#if OS(NETBSD)
+    size_t len;
+    int flag;
+
+    len = sizeof(flag);
+    if (sysctlbyname("machdep.fpu_present", &flag, &len, NULL, 0) == 0) {
+        return flag == 1;
+    }
+#endif // OS(NETBSD)
+
 #if (COMPILER(GCC) && defined(__VFP_FP__))
     return true;
 #else
