$NetBSD: patch-mozilla_xpcom_build_PoisonIOInterposer.h,v 1.1 2014/06/22 08:54:39 ryoon Exp $

--- mozilla/xpcom/build/PoisonIOInterposer.h.orig	2014-06-13 00:46:13.000000000 +0000
+++ mozilla/xpcom/build/PoisonIOInterposer.h
@@ -26,7 +26,7 @@ void MozillaUnRegisterDebugFILE(FILE *f)
 
 MOZ_END_EXTERN_C
 
-#if defined(MOZ_ENABLE_PROFILER_SPS) && (defined(XP_WIN) || defined(XP_MACOSX))
+#if defined(MOZ_ENABLE_PROFILER_SPS) && (defined(XP_WIN) || defined(XP_DARWIN))
 
 #ifdef __cplusplus
 namespace mozilla {
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
@@ -63,19 +63,19 @@ void ClearPoisonIOInterposer();
 } // namespace mozilla
 #endif /* __cplusplus */
 
-#else /* MOZ_ENABLE_PROFILER_SPS && (XP_WIN || XP_MACOSX) */
+#else /* MOZ_ENABLE_PROFILER_SPS && (XP_WIN || XP_DARWIN) */
 
 #ifdef __cplusplus
 namespace mozilla {
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
 
-#endif /* MOZ_ENABLE_PROFILER_SPS && (XP_WIN || XP_MACOSX) */
+#endif /* MOZ_ENABLE_PROFILER_SPS && (XP_WIN || XP_DARWIN) */
 
 #endif // mozilla_PoisonIOInterposer_h
