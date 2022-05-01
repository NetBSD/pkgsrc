$NetBSD: patch-xpcom_reflect_xptcall_md_unix_xptcstubs_ppc_netbsd.cpp,v 1.1 2022/05/01 00:36:11 manu Exp $

Update to fit current code

--- xpcom/reflect/xptcall/md/unix/xptcstubs_ppc_netbsd.cpp.orig	2022-04-18 02:30:50.549401901 +0000
+++ xpcom/reflect/xptcall/md/unix/xptcstubs_ppc_netbsd.cpp	2022-04-18 01:58:29.047568136 +0000
@@ -5,8 +5,9 @@
 
 // Implement shared vtbl methods.
 
 #include "xptcprivate.h"
+#include "xptiprivate.h"
 
 // The Linux/PPC ABI (aka PPC/SYSV ABI) passes the first 8 integral
 // parameters and the first 8 floating point parameters in registers
 // (r3-r10 and f1-f8), no stack space is allocated for these by the
@@ -35,24 +36,18 @@
                    double *fprData)
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
-    if (! info)
+    if (!info)
         return NS_ERROR_UNEXPECTED;
 
     paramCount = info->GetParamCount();
 
@@ -143,11 +138,9 @@
             break;
         }
     }
 
-    result = self->CallMethod((uint16_t) methodIndex, info, dispatchParams);
-
-    NS_RELEASE(iface_info);
+    result = self->mOuter->CallMethod((uint16_t) methodIndex, info, dispatchParams);
 
     if (dispatchParams != paramBuffer)
         delete [] dispatchParams;
 
