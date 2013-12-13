$NetBSD: patch-qtwebkit_Source_JavaScriptCore_assembler_MacroAssemblerARM.cpp,v 1.1 2013/12/13 14:38:35 ryoon Exp $

* Add NetBSD support

--- qtwebkit/Source/JavaScriptCore/assembler/MacroAssemblerARM.cpp.orig	2013-11-27 01:01:49.000000000 +0000
+++ qtwebkit/Source/JavaScriptCore/assembler/MacroAssemblerARM.cpp
@@ -46,6 +46,8 @@ typedef struct
         uint32_t a_val;
     } a_un;
 } Elf32_auxv_t;
+#elif OS(NETBSD)
+#include <sys/sysctl.h>
 # else
 # include <asm/hwcap.h>
 # endif
@@ -69,6 +71,16 @@ static bool isVFPPresent()
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
