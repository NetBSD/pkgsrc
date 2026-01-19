$NetBSD: patch-ui_base_accelerators_global__accelerator__listener_global__accelerator__listener__ozone.cc,v 1.13 2026/01/19 16:14:22 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/base/accelerators/global_accelerator_listener/global_accelerator_listener_ozone.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ ui/base/accelerators/global_accelerator_listener/global_accelerator_listener_ozone.cc
@@ -12,7 +12,7 @@
 #include "ui/base/accelerators/accelerator.h"
 #include "ui/ozone/public/ozone_platform.h"
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(USE_DBUS)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(USE_DBUS)
 #include "base/environment.h"
 #include "base/feature_list.h"
 #include "base/nix/xdg_util.h"
@@ -24,7 +24,7 @@
 using content::BrowserThread;
 
 namespace {
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(USE_DBUS)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(USE_DBUS)
 BASE_FEATURE(kGlobalShortcutsPortal, base::FEATURE_ENABLED_BY_DEFAULT);
 
 constexpr char kSessionSuffix[] = "_global_shortcuts";
@@ -49,7 +49,7 @@ GlobalAcceleratorListener* GlobalAcceler
     return instance->get();
   }
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(USE_DBUS)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(USE_DBUS)
   // ListShortcuts on GNOME will return an empty list when the session is
   // created, making this class incorrectly believe it must rebind all
   // shortcuts, leading to a dialog shown on every browser start.
