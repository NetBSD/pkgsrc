$NetBSD: patch-headless_lib_browser_headless__browser__impl.cc,v 1.4 2026/01/19 16:14:16 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- headless/lib/browser/headless_browser_impl.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ headless/lib/browser/headless_browser_impl.cc
@@ -36,7 +36,7 @@
 #include "components/os_crypt/async/browser/keychain_key_provider.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(USE_DBUS)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(USE_DBUS)
 #include "base/command_line.h"
 #include "components/os_crypt/async/browser/freedesktop_secret_key_provider.h"
 #include "components/password_manager/core/browser/password_manager_switches.h"  // nogncheck
@@ -410,7 +410,7 @@ void HeadlessBrowserImpl::CreateOSCryptA
   providers.emplace_back(std::make_pair(
       /*precedence=*/10u,
       std::make_unique<os_crypt_async::KeychainKeyProvider>()));
-#elif BUILDFLAG(IS_LINUX) && BUILDFLAG(USE_DBUS)
+#elif (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(USE_DBUS)
   base::CommandLine* cmd_line = base::CommandLine::ForCurrentProcess();
   const auto password_store =
       cmd_line->GetSwitchValueASCII(password_manager::kPasswordStore);
