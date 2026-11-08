$NetBSD: patch-chrome_browser_chrome__browser__main__linux.cc,v 1.32 2026/11/08 15:38:53 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/chrome_browser_main_linux.cc.orig	2026-11-02 23:22:33.000000000 +0000
+++ chrome/browser/chrome_browser_main_linux.cc
@@ -24,7 +24,7 @@
 #include "device/bluetooth/dbus/bluez_dbus_manager.h"
 #include "ui/base/l10n/l10n_util.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/ozone/public/ozone_platform.h"
 #if BUILDFLAG(USE_DBUS)
 #include "components/dbus/thread_linux/dbus_thread_linux.h"
@@ -82,8 +82,10 @@ void ChromeBrowserMainPartsLinux::PostCr
 
 #if !BUILDFLAG(IS_CHROMEOS)
 #if BUILDFLAG(USE_DBUS)
+#if !BUILDFLAG(IS_BSD)
   bluez::BluezDBusManager::Initialize(
       dbus_thread_linux::GetSharedSystemBus().get());
+#endif
   session_end_listener_ = SessionEndListenerLinux::Create();
 #endif  // BUILDFLAG(USE_DBUS)
 #endif  // !BUILDFLAG(IS_CHROMEOS)
@@ -91,7 +93,7 @@ void ChromeBrowserMainPartsLinux::PostCr
   ChromeBrowserMainPartsPosix::PostCreateMainMessageLoop();
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void ChromeBrowserMainPartsLinux::PostMainMessageLoopRun() {
   ChromeBrowserMainPartsPosix::PostMainMessageLoopRun();
   ui::OzonePlatform::GetInstance()->PostMainMessageLoopRun();
@@ -131,7 +133,9 @@ void ChromeBrowserMainPartsLinux::PostDe
 #if BUILDFLAG(USE_DBUS)
   session_end_listener_.reset();
 #endif
+#if !BUILDFLAG(IS_BSD)
   bluez::BluezDBusManager::Shutdown();
+#endif
   // TODO(shelley.vohr): Call dbus_thread_linux::Shutdown() here. It cannot run
   // yet because the in-process device service (battery, wifi, wake lock) is
   // destroyed after this last BrowserMainParts hook and still dereferences
