$NetBSD: patch-content_shell_browser_shell__paths.cc,v 1.2 2025/05/16 16:08:26 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/shell/browser/shell_paths.cc.orig	2025-05-05 19:21:24.000000000 +0000
+++ content/shell/browser/shell_paths.cc
@@ -13,7 +13,7 @@
 
 #if BUILDFLAG(IS_FUCHSIA)
 #include "base/fuchsia/file_utils.h"
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "base/nix/xdg_util.h"
 #endif
 
@@ -25,7 +25,7 @@ bool GetDefaultUserDataDirectory(base::F
 #if BUILDFLAG(IS_WIN)
   CHECK(base::PathService::Get(base::DIR_LOCAL_APP_DATA, result));
   *result = result->Append(std::wstring(L"content_shell"));
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   std::unique_ptr<base::Environment> env(base::Environment::Create());
   base::FilePath config_dir(base::nix::GetXDGDirectory(
       env.get(), base::nix::kXdgConfigHomeEnvVar, base::nix::kDotConfigDir));
