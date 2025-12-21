$NetBSD: patch-src_3rdparty_chromium_content_ppapi__plugin_ppapi__plugin__main.cc,v 1.1 2025/12/21 09:38:28 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/content/ppapi_plugin/ppapi_plugin_main.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/content/ppapi_plugin/ppapi_plugin_main.cc
@@ -52,6 +52,11 @@
 #include "gin/v8_initializer.h"
 #endif
 
+#if BUILDFLAG(IS_BSD)
+#include "sandbox/policy/sandbox.h"
+#include "sandbox/policy/sandbox_type.h"
+#endif
+
 #if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_ANDROID)
 #include <stdlib.h>
 #endif
@@ -141,7 +146,7 @@ int PpapiPluginMain(MainFunctionParams p
   gin::V8Initializer::LoadV8Snapshot();
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_OPENBSD)
   sandbox::policy::SandboxLinux::GetInstance()->InitializeSandbox(
       sandbox::policy::SandboxTypeFromCommandLine(command_line),
       sandbox::policy::SandboxLinux::PreSandboxHook(),
