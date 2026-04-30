$NetBSD: patch-src_3rdparty_chromium_ui_base_accelerators_global__accelerator__listener_global__accelerator__listener__ozone.cc,v 1.1 2026/04/30 06:39:45 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/ui/base/accelerators/global_accelerator_listener/global_accelerator_listener_ozone.cc.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/ui/base/accelerators/global_accelerator_listener/global_accelerator_listener_ozone.cc
@@ -12,7 +12,7 @@
 #include "ui/base/accelerators/accelerator.h"
 #include "ui/ozone/public/ozone_platform.h"
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(USE_DBUS)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(USE_DBUS)
 #include "base/environment.h"
 #include "base/feature_list.h"
 #include "base/nix/xdg_util.h"
@@ -23,7 +23,7 @@
 using content::BrowserThread;
 
 namespace {
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(USE_DBUS)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(USE_DBUS)
 BASE_FEATURE(kGlobalShortcutsPortal,
              "GlobalShortcutsPortal",
              base::FEATURE_ENABLED_BY_DEFAULT);
