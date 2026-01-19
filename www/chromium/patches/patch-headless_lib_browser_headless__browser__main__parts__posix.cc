$NetBSD: patch-headless_lib_browser_headless__browser__main__parts__posix.cc,v 1.14 2026/01/19 16:14:16 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- headless/lib/browser/headless_browser_main_parts_posix.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ headless/lib/browser/headless_browser_main_parts_posix.cc
@@ -22,7 +22,7 @@
 #include "content/public/browser/browser_thread.h"
 #include "headless/lib/browser/headless_browser_impl.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/command_line.h"
 #include "components/os_crypt/sync/key_storage_config_linux.h"
 #include "components/os_crypt/sync/os_crypt.h"
@@ -164,7 +164,7 @@ class BrowserShutdownHandler {
 
 }  // namespace
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 constexpr char kProductName[] = "HeadlessChrome";
 #endif
 
@@ -172,9 +172,9 @@ void HeadlessBrowserMainParts::PostCreat
   BrowserShutdownHandler::Install(base::BindOnce(
       &HeadlessBrowserImpl::ShutdownWithExitCode, browser_->GetWeakPtr()));
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
-#if BUILDFLAG(USE_DBUS)
+#if BUILDFLAG(USE_DBUS) && !BUILDFLAG(IS_BSD)
   bluez::BluezDBusManager::Initialize(
       dbus_thread_linux::GetSharedSystemBus().get());
 #endif
