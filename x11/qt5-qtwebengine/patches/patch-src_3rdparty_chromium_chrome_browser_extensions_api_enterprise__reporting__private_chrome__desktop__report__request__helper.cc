$NetBSD: patch-src_3rdparty_chromium_chrome_browser_extensions_api_enterprise__reporting__private_chrome__desktop__report__request__helper.cc,v 1.1 2021/08/03 21:04:34 markd Exp $

--- src/3rdparty/chromium/chrome/browser/extensions/api/enterprise_reporting_private/chrome_desktop_report_request_helper.cc.orig	2020-07-08 21:41:46.000000000 +0000
+++ src/3rdparty/chromium/chrome/browser/extensions/api/enterprise_reporting_private/chrome_desktop_report_request_helper.cc
@@ -40,7 +40,7 @@
 #include "base/win/registry.h"
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "base/environment.h"
 #include "base/nix/xdg_util.h"
 #endif
@@ -386,7 +386,7 @@ base::FilePath GetEndpointVerificationDi
     return *GetEndpointVerificationDirOverride();
 #if defined(OS_WIN)
   if (!base::PathService::Get(base::DIR_LOCAL_APP_DATA, &path))
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   std::unique_ptr<base::Environment> env(base::Environment::Create());
   path = base::nix::GetXDGDirectory(env.get(), base::nix::kXdgConfigHomeEnvVar,
                                     base::nix::kDotConfigDir);
@@ -397,7 +397,7 @@ base::FilePath GetEndpointVerificationDi
   if (true)
 #endif
     return path;
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   path = path.AppendASCII("google");
 #else
   path = path.AppendASCII("Google");
