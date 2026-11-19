$NetBSD: patch-chrome_browser_speech_chrome__speech__recognition__service.cc,v 1.2 2026/11/19 19:45:54 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/speech/chrome_speech_recognition_service.cc.orig	2026-11-11 21:01:38.000000000 +0000
+++ chrome/browser/speech/chrome_speech_recognition_service.cc
@@ -303,7 +303,7 @@ void ChromeSpeechRecognitionService::Lau
 
   content::ServiceProcessHost::Options options;
   options.WithDisplayName(IDS_UTILITY_PROCESS_SPEECH_RECOGNITION_SERVICE_NAME);
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // libsoda.so has to be dlopen()ed before the sandbox is engaged, so tell the
   // utility process which binary it is going to be asked to load below.
   options.WithExtraCommandLineSwitchKeyValues(
