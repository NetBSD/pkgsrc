$NetBSD: patch-src_3rdparty_chromium_content_public_common_content__features.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/content/public/common/content_features.cc.orig	2020-07-08 21:41:48.000000000 +0000
+++ src/3rdparty/chromium/content/public/common/content_features.cc
@@ -48,7 +48,7 @@ const base::Feature kAudioServiceLaunchO
 const base::Feature kAudioServiceOutOfProcess {
   "AudioServiceOutOfProcess",
 #if defined(OS_WIN) || defined(OS_MACOSX) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    ((defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS))
       base::FEATURE_ENABLED_BY_DEFAULT
 #else
       base::FEATURE_DISABLED_BY_DEFAULT
@@ -727,7 +727,7 @@ const base::Feature kWebAssemblyThreads 
 };
 
 // Enable WebAssembly trap handler.
-#if (defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MACOSX)) && \
+#if (defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_BSD)) && \
     defined(ARCH_CPU_X86_64)
 const base::Feature kWebAssemblyTrapHandler{"WebAssemblyTrapHandler",
                                             base::FEATURE_ENABLED_BY_DEFAULT};
@@ -757,7 +757,7 @@ const base::Feature kWebAuth{"WebAuthent
 // https://w3c.github.io/webauthn
 const base::Feature kWebAuthCable {
   "WebAuthenticationCable",
-#if !defined(OS_CHROMEOS) && defined(OS_LINUX)
+#if !defined(OS_CHROMEOS) && (defined(OS_LINUX) || defined(OS_BSD))
       base::FEATURE_DISABLED_BY_DEFAULT
 #else
       base::FEATURE_ENABLED_BY_DEFAULT
