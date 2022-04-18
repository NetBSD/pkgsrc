$NetBSD: patch-src_3rdparty_chromium_content_public_common_content__features.cc,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/content/public/common/content_features.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/content/public/common/content_features.cc
@@ -54,7 +54,7 @@ const base::Feature kAudioServiceLaunchO
 // Runs the audio service in a separate process.
 const base::Feature kAudioServiceOutOfProcess {
   "AudioServiceOutOfProcess",
-#if defined(OS_WIN) || defined(OS_MAC) || \
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_BSD) || \
     (defined(OS_LINUX) && !defined(OS_CHROMEOS))
       base::FEATURE_ENABLED_BY_DEFAULT
 #else
@@ -788,7 +788,7 @@ const base::Feature kWebAssemblyThreads 
 
 // Enable WebAssembly trap handler.
 #if (defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_WIN) || \
-     defined(OS_MAC)) &&                                             \
+     defined(OS_MAC) || defined(OS_BSD)) &&                                             \
     defined(ARCH_CPU_X86_64)
 const base::Feature kWebAssemblyTrapHandler{"WebAssemblyTrapHandler",
                                             base::FEATURE_ENABLED_BY_DEFAULT};
@@ -818,7 +818,7 @@ const base::Feature kWebAuth{"WebAuthent
 // https://w3c.github.io/webauthn
 const base::Feature kWebAuthCable {
   "WebAuthenticationCable",
-#if !defined(OS_CHROMEOS) && defined(OS_LINUX)
+#if !defined(OS_CHROMEOS) && (defined(OS_LINUX) || defined(OS_BSD))
       base::FEATURE_DISABLED_BY_DEFAULT
 #else
       base::FEATURE_ENABLED_BY_DEFAULT
