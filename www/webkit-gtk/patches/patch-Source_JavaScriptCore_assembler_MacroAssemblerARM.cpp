$NetBSD: patch-Source_JavaScriptCore_assembler_MacroAssemblerARM.cpp,v 1.4 2015/09/26 10:16:38 leot Exp $

--- Source/JavaScriptCore/assembler/MacroAssemblerARM.cpp.orig	2015-09-21 07:29:46.000000000 +0000
+++ Source/JavaScriptCore/assembler/MacroAssemblerARM.cpp
@@ -38,6 +38,8 @@
 #include <unistd.h>
 #include <elf.h>
 #include <asm/hwcap.h>
+#elif OS(NETBSD)
+#include <sys/sysctl.h>
 #endif
 
 namespace JSC {
@@ -57,6 +59,16 @@ static bool isVFPPresent()
         close(fd);
     }
 #endif // OS(LINUX)
+ 
+#if OS(NETBSD)
+    size_t len;
+    int flag;
+
+    len = sizeof(flag);
+    if (sysctlbyname("machdep.fpu_present", &flag, &len, NULL, 0) == 0) {
+        return flag == 1;
+    }
+#endif // OS(NETBSD)
 
 #if (COMPILER(GCC_OR_CLANG) && defined(__VFP_FP__))
     return true;
