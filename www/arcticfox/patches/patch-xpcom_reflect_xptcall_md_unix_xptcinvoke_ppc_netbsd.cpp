$NetBSD: patch-xpcom_reflect_xptcall_md_unix_xptcinvoke_ppc_netbsd.cpp,v 1.1 2022/05/01 00:36:11 manu Exp $

Update to fit current code

--- xpcom/reflect/xptcall/md/unix/xptcinvoke_ppc_netbsd.cpp.orig	2022-04-18 02:30:50.508558042 +0000
+++ xpcom/reflect/xptcall/md/unix/xptcinvoke_ppc_netbsd.cpp	2022-04-17 06:36:22.117064855 +0000
@@ -109,7 +109,7 @@
     }
 }
 
 extern "C"
-XPTC_PUBLIC_API(nsresult)
+EXPORT_XPCOM_API(nsresult)
 XPTC_InvokeByIndex(nsISupports* that, uint32_t methodIndex,
                    uint32_t paramCount, nsXPTCVariant* params);
