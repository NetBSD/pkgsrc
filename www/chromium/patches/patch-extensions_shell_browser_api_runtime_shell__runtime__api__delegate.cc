$NetBSD: patch-extensions_shell_browser_api_runtime_shell__runtime__api__delegate.cc,v 1.1 2025/02/06 09:58:09 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- extensions/shell/browser/api/runtime/shell_runtime_api_delegate.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ extensions/shell/browser/api/runtime/shell_runtime_api_delegate.cc
@@ -45,7 +45,7 @@ void ShellRuntimeAPIDelegate::OpenURL(co
 bool ShellRuntimeAPIDelegate::GetPlatformInfo(PlatformInfo* info) {
 #if BUILDFLAG(IS_CHROMEOS_ASH)
   info->os = api::runtime::PlatformOs::kCros;
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   info->os = api::runtime::PlatformOs::kLinux;
 #endif
   return true;
