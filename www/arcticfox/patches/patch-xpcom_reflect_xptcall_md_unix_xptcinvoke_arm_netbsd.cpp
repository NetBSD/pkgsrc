$NetBSD: patch-xpcom_reflect_xptcall_md_unix_xptcinvoke_arm_netbsd.cpp,v 1.2 2022/05/05 14:07:39 nia Exp $

Update to fit current code

--- xpcom/reflect/xptcall/md/unix/xptcinvoke_arm_netbsd.cpp.orig	2022-02-03 04:20:33.000000000 +0000
+++ xpcom/reflect/xptcall/md/unix/xptcinvoke_arm_netbsd.cpp
@@ -101,7 +101,8 @@ struct my_params_struct {
     uint32_t fn_copy;      
 };
 
-XPTC_PUBLIC_API(nsresult)
+
+EXPORT_XPCOM_API(nsresult)
 XPTC_InvokeByIndex(nsISupports* that, uint32_t methodIndex,
                    uint32_t paramCount, nsXPTCVariant* params)
 {
