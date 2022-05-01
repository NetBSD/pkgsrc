$NetBSD: patch-xpcom_reflect_xptcall_md_unix_xptcinvoke_arm_netbsd.cpp,v 1.1 2022/05/01 00:36:10 manu Exp $

Update to fit current code

--- xpcom/reflect/xptcall/md/unix/xptcinvoke_arm_netbsd.cpp.orig	2022-04-18 02:30:50.498239249 +0000
+++ xpcom/reflect/xptcall/md/unix/xptcinvoke_arm_netbsd.cpp	2022-04-18 01:08:05.177311630 +0000
@@ -100,9 +100,10 @@
     uint32_t fn_count;     
     uint32_t fn_copy;      
 };
 
-XPTC_PUBLIC_API(nsresult)
+
+EXPORT_XPCOM_API(nsresult)
 XPTC_InvokeByIndex(nsISupports* that, uint32_t methodIndex,
                    uint32_t paramCount, nsXPTCVariant* params)
 {
     uint32_t result;
