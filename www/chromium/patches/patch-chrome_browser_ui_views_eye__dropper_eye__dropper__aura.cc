$NetBSD: patch-chrome_browser_ui_views_eye__dropper_eye__dropper__aura.cc,v 1.1 2026/09/22 13:41:21 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/eye_dropper/eye_dropper_aura.cc.orig	2026-09-14 22:17:16.000000000 +0000
+++ chrome/browser/ui/views/eye_dropper/eye_dropper_aura.cc
@@ -13,7 +13,7 @@
 #include "content/public/browser/web_contents.h"
 #include "ui/base/ui_base_features.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/environment.h"
 #include "base/nix/xdg_util.h"
 #if BUILDFLAG(USE_DBUS)
@@ -33,7 +33,7 @@ std::unique_ptr<content::EyeDropper> Sho
     return nullptr;
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Check the session type from the environment variable (XDG_SESSION_TYPE)
   // instead of the Ozone platform, because XWayland sessions still require
   // the portal eye dropper for reliable screen capture.
