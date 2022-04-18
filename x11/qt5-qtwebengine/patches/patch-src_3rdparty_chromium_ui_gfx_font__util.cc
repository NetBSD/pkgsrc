$NetBSD: patch-src_3rdparty_chromium_ui_gfx_font__util.cc,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/ui/gfx/font_util.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/ui/gfx/font_util.cc
@@ -6,7 +6,7 @@
 
 #include "build/build_config.h"
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include <fontconfig/fontconfig.h>
 #include "ui/gfx/linux/fontconfig_util.h"
 #endif
@@ -24,7 +24,7 @@ void InitializeFonts() {
   // background (resources have not yet been granted to cast) since it prevents
   // the long delay the user would have seen on first rendering.
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // Ensures the config is created on this thread.
   FcConfig* config = GetGlobalFontConfig();
   DCHECK(config);
