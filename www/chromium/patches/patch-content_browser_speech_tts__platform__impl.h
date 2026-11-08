$NetBSD: patch-content_browser_speech_tts__platform__impl.h,v 1.1 2026/11/08 15:39:03 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/browser/speech/tts_platform_impl.h.orig	2026-11-02 23:22:33.000000000 +0000
+++ content/browser/speech/tts_platform_impl.h
@@ -15,7 +15,7 @@
 
 namespace content {
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Overrides the library path captured when the Linux TTS singleton is created.
 // Must be called before TtsPlatform::GetInstance().
 CONTENT_EXPORT base::AutoReset<std::string>
