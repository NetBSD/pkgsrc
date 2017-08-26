$NetBSD: patch-xpcom_reflect_xptcall_md_unix_xptcstubs__ppc__netbsd.cpp,v 1.1 2017/08/26 10:36:01 he Exp $

Adapt in the direction of xptcstubs_ppc_linux.cpp.
This apparently hasn't built for a while.

--- xpcom/reflect/xptcall/md/unix/xptcstubs_ppc_netbsd.cpp.orig	2017-06-15 20:52:36.000000000 +0000
+++ xpcom/reflect/xptcall/md/unix/xptcstubs_ppc_netbsd.cpp
@@ -6,6 +6,7 @@
 // Implement shared vtbl methods.
 
 #include "xptcprivate.h"
+#include "xptiprivate.h"
 
 // The Linux/PPC ABI (aka PPC/SYSV ABI) passes the first 8 integral
 // parameters and the first 8 floating point parameters in registers
@@ -36,20 +37,14 @@ PrepareAndDispatch(nsXPTCStubBase* self,
 {
     nsXPTCMiniVariant paramBuffer[PARAM_BUFFER_COUNT];
     nsXPTCMiniVariant* dispatchParams = nullptr;
-    nsIInterfaceInfo* iface_info = nullptr;
-    const nsXPTMethodInfo* info;
+    const nsXPTMethodInfo* info = nullptr;
     uint32_t paramCount;
     uint32_t i;
     nsresult result = NS_ERROR_FAILURE;
 
     NS_ASSERTION(self,"no self");
 
-    self->GetInterfaceInfo(&iface_info);
-    NS_ASSERTION(iface_info,"no interface info");
-    if (! iface_info)
-        return NS_ERROR_UNEXPECTED;
-
-    iface_info->GetMethodInfo(uint16_t(methodIndex), &info);
+    self->mEntry->GetMethodInfo(uint16_t(methodIndex), &info);
     NS_ASSERTION(info,"no method info");
     if (! info)
         return NS_ERROR_UNEXPECTED;
@@ -147,9 +142,7 @@ PrepareAndDispatch(nsXPTCStubBase* self,
         }
     }
 
-    result = self->CallMethod((uint16_t) methodIndex, info, dispatchParams);
-
-    NS_RELEASE(iface_info);
+    result = self->mOuter->CallMethod((uint16_t) methodIndex, info, dispatchParams);
 
     if (dispatchParams != paramBuffer)
         delete [] dispatchParams;
@@ -163,16 +156,44 @@ PrepareAndDispatch(nsXPTCStubBase* self,
 // however, it's quick, dirty, and'll break when the ABI changes on
 // us, which is what we want ;-).
 
-#define STUB_ENTRY(n)                                       \
-__asm__ (                                                   \
-        ".section \".text\" \n\t"                           \
-        ".align 2 \n\t"                                     \
-	".globl  Stub"#n"__14nsXPTCStubBase \n\t"           \
-	".type   Stub"#n"__14nsXPTCStubBase,@function \n\n" \
-                                                            \
-"Stub"#n"__14nsXPTCStubBase: \n\t"                          \
-	"li     11,"#n" \n\t"                               \
-	"b      SharedStub@local \n"                        \
+// gcc-3 version
+//
+// As G++3 ABI contains the length of the functionname in the mangled
+// name, it is difficult to get a generic assembler mechanism like
+// in the G++ 2.95 case.
+// Create names would be like:
+// _ZN14nsXPTCStubBase5Stub1Ev
+// _ZN14nsXPTCStubBase6Stub12Ev
+// _ZN14nsXPTCStubBase7Stub123Ev
+// _ZN14nsXPTCStubBase8Stub1234Ev
+// etc.
+// Use assembler directives to get the names right...
+
+#define STUB_ENTRY(n)							\
+__asm__ (								\
+	".section \".text\" \n\t"					\
+	".align 2 \n\t"							\
+	".if	"#n" < 10 \n\t"						\
+	".globl _ZN14nsXPTCStubBase5Stub"#n"Ev \n\t"			\
+	".type	_ZN14nsXPTCStubBase5Stub"#n"Ev,@function \n\n"		\
+"_ZN14nsXPTCStubBase5Stub"#n"Ev: \n\t"					\
+									\
+	".elseif "#n" < 100 \n\t"					\
+	".globl _ZN14nsXPTCStubBase6Stub"#n"Ev \n\t"			\
+	".type	_ZN14nsXPTCStubBase6Stub"#n"Ev,@function \n\n"		\
+"_ZN14nsXPTCStubBase6Stub"#n"Ev: \n\t"					\
+									\
+	".elseif "#n" < 1000 \n\t"					\
+	".globl _ZN14nsXPTCStubBase7Stub"#n"Ev \n\t"			\
+	".type	_ZN14nsXPTCStubBase7Stub"#n"Ev,@function \n\n"		\
+"_ZN14nsXPTCStubBase7Stub"#n"Ev: \n\t"					\
+									\
+	".else \n\t"							\
+	".err	\"stub number "#n" >= 1000 not yet supported\"\n"	\
+	".endif \n\t"							\
+									\
+	"li	11,"#n" \n\t"						\
+	"b	SharedStub@local \n"					\
 );
 
 #define SENTINEL_ENTRY(n)                            \
