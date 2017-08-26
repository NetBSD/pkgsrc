$NetBSD: patch-xpcom_reflect_xptcall_md_unix_xptcinvoke__asm__ppc__netbsd.s,v 1.2 2017/08/26 10:36:01 he Exp $

Adapt to the use of NS_InvokeByIndex instead of XPTC_InvokeByIndex.

--- xpcom/reflect/xptcall/md/unix/xptcinvoke_asm_ppc_netbsd.s.orig	2014-10-11 09:06:50.000000000 +0000
+++ xpcom/reflect/xptcall/md/unix/xptcinvoke_asm_ppc_netbsd.s
@@ -20,15 +20,15 @@
 		      
         .section ".text"
 	.align 2
-	.globl XPTC_InvokeByIndex
-	.type  XPTC_InvokeByIndex,@function
+	.globl NS_InvokeByIndex
+	.type  NS_InvokeByIndex,@function
 
 #
-# XPTC_InvokeByIndex(nsISupports* that, uint32_t methodIndex,
-#                    uint32_t paramCount, nsXPTCVariant* params)
+# NS_InvokeByIndex(nsISupports* that, PRUint32 methodIndex,
+#                    PRUint32 paramCount, nsXPTCVariant* params)
 #
 
-XPTC_InvokeByIndex:
+NS_InvokeByIndex:
 	stwu    sp,-32(sp)			# setup standard stack frame
 	mflr    r0				# save LR
 	stw     r3,8(sp)			# r3 <= that
