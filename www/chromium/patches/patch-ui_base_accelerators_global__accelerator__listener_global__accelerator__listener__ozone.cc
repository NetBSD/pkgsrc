$NetBSD: patch-ui_base_accelerators_global__accelerator__listener_global__accelerator__listener__ozone.cc,v 1.6 2025/09/12 16:02:37 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/base/accelerators/global_accelerator_listener/global_accelerator_listener_ozone.cc.orig	2025-09-08 23:21:33.000000000 +0000
+++ ui/base/accelerators/global_accelerator_listener/global_accelerator_listener_ozone.cc
@@ -12,7 +12,7 @@
 #include "ui/base/accelerators/accelerator.h"
 #include "ui/ozone/public/ozone_platform.h"
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(USE_DBUS)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(USE_DBUS)
 #include "base/environment.h"
 #include "base/feature_list.h"
 #include "build/branding_buildflags.h"
@@ -22,7 +22,7 @@
 using content::BrowserThread;
 
 namespace {
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(USE_DBUS)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(USE_DBUS)
 BASE_FEATURE(kGlobalShortcutsPortal,
              "GlobalShortcutsPortal",
              base::FEATURE_ENABLED_BY_DEFAULT);
@@ -74,7 +74,7 @@ GlobalAcceleratorListener* GlobalAcceler
     return instance->get();
   }
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(USE_DBUS)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(USE_DBUS)
   if (base::FeatureList::IsEnabled(kGlobalShortcutsPortal)) {
     static GlobalAcceleratorListenerLinux* const linux_instance =
         new GlobalAcceleratorListenerLinux(nullptr, GetSessionName());
