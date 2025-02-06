$NetBSD: patch-chrome_browser_screen__ai_screen__ai__service__router.cc,v 1.1 2025/02/06 09:57:50 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/screen_ai/screen_ai_service_router.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ chrome/browser/screen_ai/screen_ai_service_router.cc
@@ -318,7 +318,7 @@ void ScreenAIServiceRouter::LaunchIfNotR
   base::FilePath binary_path = state_instance->get_component_binary_path();
 #if BUILDFLAG(IS_WIN)
   std::vector<base::FilePath> preload_libraries = {binary_path};
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   std::vector<std::string> extra_switches = {
       base::StringPrintf("--%s=%s", screen_ai::GetBinaryPathSwitch(),
                          binary_path.MaybeAsASCII().c_str())};
@@ -332,7 +332,7 @@ void ScreenAIServiceRouter::LaunchIfNotR
           .WithPreloadedLibraries(
               preload_libraries,
               content::ServiceProcessHostPreloadLibraries::GetPassKey())
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
           .WithExtraCommandLineSwitches(extra_switches)
 #endif  // BUILDFLAG(IS_WIN)
           .Pass());
