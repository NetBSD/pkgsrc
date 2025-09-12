$NetBSD: patch-chrome_browser_ui_color_native__chrome__color__mixer.cc,v 1.7 2025/09/12 16:02:23 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/color/native_chrome_color_mixer.cc.orig	2025-09-08 23:21:33.000000000 +0000
+++ chrome/browser/ui/color/native_chrome_color_mixer.cc
@@ -7,7 +7,7 @@
 #include "build/build_config.h"
 
 #if !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_MAC) && \
-    !BUILDFLAG(IS_WIN)
+    !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_BSD)
 void AddNativeChromeColorMixer(ui::ColorProvider* provider,
                                const ui::ColorProviderKey& key) {}
 #endif
