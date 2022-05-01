$NetBSD: patch-xpcom_reflect_xptcall_md_unix_xptcstubs_netbsd_m68k.cpp,v 1.1 2022/05/01 00:36:11 manu Exp $

Update to fit current code

--- xpcom/reflect/xptcall/md/unix/xptcstubs_netbsd_m68k.cpp.orig	2022-04-18 02:30:50.528949644 +0000
+++ xpcom/reflect/xptcall/md/unix/xptcstubs_netbsd_m68k.cpp	2022-04-18 01:58:14.671629551 +0000
@@ -5,8 +5,9 @@
 
 /* Implement shared vtbl methods. */
 
 #include "xptcprivate.h"
+#include "xptiprivate.h"
 
 #if !defined(__NetBSD__) || !defined(__m68k__)
 #error This code is for NetBSD/m68k only
 #endif
@@ -18,21 +19,19 @@
 #define PARAM_BUFFER_COUNT     16
 
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
 
         // setup variant array pointer
@@ -79,11 +78,9 @@
                 break;
             }
         }
 
-        result = self->CallMethod((uint16_t)methodIndex, info, dispatchParams);
-
-        NS_RELEASE(iface_info);
+        result = self->mOuter->CallMethod((uint16_t)methodIndex, info, dispatchParams);
 
         if(dispatchParams != paramBuffer)
             delete [] dispatchParams;
 
