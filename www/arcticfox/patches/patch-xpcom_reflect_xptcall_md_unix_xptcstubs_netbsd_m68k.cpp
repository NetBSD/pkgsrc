$NetBSD: patch-xpcom_reflect_xptcall_md_unix_xptcstubs_netbsd_m68k.cpp,v 1.2 2022/05/05 14:07:39 nia Exp $

Update to fit current code

--- xpcom/reflect/xptcall/md/unix/xptcstubs_netbsd_m68k.cpp.orig	2022-02-03 04:20:33.000000000 +0000
+++ xpcom/reflect/xptcall/md/unix/xptcstubs_netbsd_m68k.cpp
@@ -6,6 +6,7 @@
 /* Implement shared vtbl methods. */
 
 #include "xptcprivate.h"
+#include "xptiprivate.h"
 
 #if !defined(__NetBSD__) || !defined(__m68k__)
 #error This code is for NetBSD/m68k only
@@ -19,19 +20,17 @@ extern "C" {
 
         nsXPTCMiniVariant paramBuffer[PARAM_BUFFER_COUNT];
         nsXPTCMiniVariant* dispatchParams = nullptr;
-        nsIInterfaceInfo* iface_info = nullptr;
-        const nsXPTMethodInfo* info;
+        const nsXPTMethodInfo* info = nullptr;
         uint8_t paramCount;
         uint8_t i;
         nsresult result = NS_ERROR_FAILURE;
 
         NS_ASSERTION(self,"no self");
 
-        self->GetInterfaceInfo(&iface_info);
-        NS_ASSERTION(iface_info,"no interface info");
-
-        iface_info->GetMethodInfo(uint16_t(methodIndex), &info);
-        NS_ASSERTION(info,"no interface info");
+        self->mEntry->GetMethodInfo(uint16_t(methodIndex), &info);
+        NS_ASSERTION(info,"no method info");
+        if (!info)
+            return NS_ERROR_UNEXPECTED;
 
         paramCount = info->GetParamCount();
 
@@ -80,9 +79,7 @@ extern "C" {
             }
         }
 
-        result = self->CallMethod((uint16_t)methodIndex, info, dispatchParams);
-
-        NS_RELEASE(iface_info);
+        result = self->mOuter->CallMethod((uint16_t)methodIndex, info, dispatchParams);
 
         if(dispatchParams != paramBuffer)
             delete [] dispatchParams;
