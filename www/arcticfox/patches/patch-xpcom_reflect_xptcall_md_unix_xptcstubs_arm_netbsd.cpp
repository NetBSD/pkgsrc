$NetBSD: patch-xpcom_reflect_xptcall_md_unix_xptcstubs_arm_netbsd.cpp,v 1.2 2022/05/05 14:07:39 nia Exp $

Update to fit current code

--- xpcom/reflect/xptcall/md/unix/xptcstubs_arm_netbsd.cpp.orig	2022-02-03 04:20:33.000000000 +0000
+++ xpcom/reflect/xptcall/md/unix/xptcstubs_arm_netbsd.cpp
@@ -6,6 +6,7 @@
 /* Implement shared vtbl methods. */
 
 #include "xptcprivate.h"
+#include "xptiprivate.h"
 
 nsresult ATTRIBUTE_USED
 PrepareAndDispatch(nsXPTCStubBase* self, uint32_t methodIndex, uint32_t* args)
@@ -14,19 +15,17 @@ PrepareAndDispatch(nsXPTCStubBase* self,
 
     nsXPTCMiniVariant paramBuffer[PARAM_BUFFER_COUNT];
     nsXPTCMiniVariant* dispatchParams = nullptr;
-    nsIInterfaceInfo* iface_info = nullptr;
-    const nsXPTMethodInfo* info;
+    const nsXPTMethodInfo* info = nullptr;
     uint8_t paramCount;
     uint8_t i;
     nsresult result = NS_ERROR_FAILURE;
 
     NS_ASSERTION(self,"no self");
 
-    self->GetInterfaceInfo(&iface_info);
-    NS_ASSERTION(iface_info,"no interface info");
-
-    iface_info->GetMethodInfo(uint16_t(methodIndex), &info);
-    NS_ASSERTION(info,"no interface info");
+    self->mEntry->GetMethodInfo(uint16_t(methodIndex), &info);
+    NS_ASSERTION(info,"no method info");
+    if (!info)
+        return NS_ERROR_UNEXPECTED;
 
     paramCount = info->GetParamCount();
 
@@ -71,9 +70,7 @@ PrepareAndDispatch(nsXPTCStubBase* self,
         }
     }
 
-    result = self->CallMethod((uint16_t)methodIndex, info, dispatchParams);
-
-    NS_RELEASE(iface_info);
+    result = self->mOuter->CallMethod((uint16_t)methodIndex, info, dispatchParams);
 
     if(dispatchParams != paramBuffer)
         delete [] dispatchParams;
