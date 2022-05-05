$NetBSD: patch-xpcom_reflect_xptcall_md_unix_xptcstubs_ppc_linux.cpp,v 1.2 2022/05/05 14:07:39 nia Exp $

Update to fit current code

--- xpcom/reflect/xptcall/md/unix/xptcstubs_ppc_linux.cpp.orig	2022-02-03 04:20:33.000000000 +0000
+++ xpcom/reflect/xptcall/md/unix/xptcstubs_ppc_linux.cpp
@@ -49,6 +49,11 @@ PrepareAndDispatch(nsXPTCStubBase* self,
 
     self->mEntry->GetMethodInfo(uint16_t(methodIndex), &info);
     NS_ASSERTION(info,"no method info");
+    if (!info)
+        return NS_ERROR_UNEXPECTED;
+
+    iface_info->GetMethodInfo(uint16_t(methodIndex), &info);
+    NS_ASSERTION(info,"no method info");
     if (! info)
         return NS_ERROR_UNEXPECTED;
 
