$NetBSD: patch-xpcom_reflect_xptcall_md_unix_xptcstubs_ppc_linux.cpp,v 1.1 2022/05/01 00:36:11 manu Exp $

Update to fit current code

--- xpcom/reflect/xptcall/md/unix/xptcstubs_ppc_linux.cpp.orig	2022-04-18 02:30:50.539220748 +0000
+++ xpcom/reflect/xptcall/md/unix/xptcstubs_ppc_linux.cpp	2022-04-18 01:42:03.669133784 +0000
@@ -48,8 +48,13 @@
     NS_ASSERTION(self,"no self");
 
     self->mEntry->GetMethodInfo(uint16_t(methodIndex), &info);
     NS_ASSERTION(info,"no method info");
+    if (!info)
+        return NS_ERROR_UNEXPECTED;
+
+    iface_info->GetMethodInfo(uint16_t(methodIndex), &info);
+    NS_ASSERTION(info,"no method info");
     if (! info)
         return NS_ERROR_UNEXPECTED;
 
     paramCount = info->GetParamCount();
