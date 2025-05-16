$NetBSD: patch-chrome_browser_screen__ai_screen__ai__service__router.cc,v 1.2 2025/05/16 16:08:18 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/screen_ai/screen_ai_service_router.cc.orig	2025-05-05 19:21:24.000000000 +0000
+++ chrome/browser/screen_ai/screen_ai_service_router.cc
@@ -403,7 +403,7 @@ void ScreenAIServiceRouter::LaunchIfNotR
   base::FilePath binary_path = state_instance->get_component_binary_path();
 #if BUILDFLAG(IS_WIN)
   std::vector<base::FilePath> preload_libraries = {binary_path};
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   std::vector<std::string> extra_switches = {
       base::StringPrintf("--%s=%s", screen_ai::GetBinaryPathSwitch(),
                          binary_path.MaybeAsASCII().c_str())};
@@ -417,7 +417,7 @@ void ScreenAIServiceRouter::LaunchIfNotR
           .WithPreloadedLibraries(
               preload_libraries,
               content::ServiceProcessHostPreloadLibraries::GetPassKey())
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
           .WithExtraCommandLineSwitches(extra_switches)
 #endif  // BUILDFLAG(IS_WIN)
           .Pass());
