$NetBSD: patch-xpcom_build_PoisonIOInterposer.h,v 1.2 2014/06/11 00:40:59 ryoon Exp $

Replace XP_MACOSX with XP_DARWIN as the former is not defined when
the toolkit is not cocoa.

--- xpcom/build/PoisonIOInterposer.h.orig	2014-05-29 23:31:50.000000000 +0000
+++ xpcom/build/PoisonIOInterposer.h
@@ -44,7 +44,7 @@ bool IsDebugFile(intptr_t aFileID);
  */
 void InitPoisonIOInterposer();
 
-#ifdef XP_MACOSX
+#ifdef XP_DARWIN
 /**
  * Check that writes are dirty before reporting I/O (Mac OS X only)
  * This is necessary for late-write checks on Mac OS X, but reading the buffer
@@ -52,7 +52,7 @@ void InitPoisonIOInterposer();
  * to do this for everything else that uses
  */
 void OnlyReportDirtyWrites();
-#endif /* XP_MACOSX */
+#endif /* XP_DARWIN */
 
 /**
  * Clear IO poisoning, this is only safe to do on the main-thread when no other
@@ -70,9 +70,9 @@ namespace mozilla {
 inline bool IsDebugFile(intptr_t aFileID){ return true; }
 inline void InitPoisonIOInterposer(){}
 inline void ClearPoisonIOInterposer(){}
-#ifdef XP_MACOSX
+#ifdef XP_DARWIN
 inline void OnlyReportDirtyWrites(){}
-#endif /* XP_MACOSX */
+#endif /* XP_DARWIN */
 } // namespace mozilla
 #endif /* __cplusplus */
 
