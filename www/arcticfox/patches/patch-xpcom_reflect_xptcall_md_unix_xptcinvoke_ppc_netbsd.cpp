$NetBSD: patch-xpcom_reflect_xptcall_md_unix_xptcinvoke_ppc_netbsd.cpp,v 1.2 2022/05/05 14:07:39 nia Exp $

Update to fit current code

--- xpcom/reflect/xptcall/md/unix/xptcinvoke_ppc_netbsd.cpp.orig	2022-02-03 04:20:33.000000000 +0000
+++ xpcom/reflect/xptcall/md/unix/xptcinvoke_ppc_netbsd.cpp
@@ -110,6 +110,6 @@ invoke_copy_to_stack(uint32_t* d,
 }
 
 extern "C"
-XPTC_PUBLIC_API(nsresult)
+EXPORT_XPCOM_API(nsresult)
 XPTC_InvokeByIndex(nsISupports* that, uint32_t methodIndex,
                    uint32_t paramCount, nsXPTCVariant* params);
