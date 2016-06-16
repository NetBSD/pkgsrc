$NetBSD: patch-media_openmax__dl_dl_api_armCOMM__s.h,v 1.2 2016/06/16 12:08:21 ryoon Exp $

* Support NetBSD/earm

--- media/openmax_dl/dl/api/armCOMM_s.h.orig	2015-09-29 21:44:56.000000000 +0000
+++ media/openmax_dl/dl/api/armCOMM_s.h
@@ -11,6 +11,12 @@
 @//  This file was originally licensed as follows. It has been
 @//  relicensed with permission from the copyright holders.
 @//
+
+#if defined(__ARM_EABI__) && !defined(__ARM_DWARF_EH__)
+#define UNWIND
+#else
+#define UNWIND @
+#endif
 	
 @// 
 @// File Name:  armCOMM_s.h
@@ -175,7 +181,8 @@
 	.object_arch armv4
 	.align	2
 \name :		
-.fnstart
+	.cfi_startproc
+	UNWIND .fnstart
 	@ Save specified R registers
 	_M_GETRREGLIST	\rreg
 	_M_PUSH_RREG
@@ -202,7 +209,8 @@
 	.endif
 	@ Restore any saved R or D registers.
 	_M_RET
-	.fnend	
+	UNWIND .fnend	
+	.cfi_endproc
 	.endfunc
         @ Reset the global stack tracking variables back to their
 	@ initial values.
