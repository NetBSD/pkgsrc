$NetBSD: patch-src_3rdparty_chromium_weblayer_browser_browser__main__parts__impl.cc,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/weblayer/browser/browser_main_parts_impl.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/weblayer/browser/browser_main_parts_impl.cc
@@ -63,7 +63,7 @@
 #include "ui/base/ui_base_features.h"
 #include "ui/events/devices/x11/touch_factory_x11.h"  // nogncheck
 #endif
-#if !defined(OS_CHROMEOS) && defined(USE_AURA) && defined(OS_LINUX)
+#if !defined(OS_CHROMEOS) && defined(USE_AURA) && (defined(OS_LINUX) || defined(OS_BSD))
 #include "ui/base/ime/init/input_method_initializer.h"
 #endif
 
@@ -157,7 +157,7 @@ int BrowserMainPartsImpl::PreEarlyInitia
   if (!features::IsUsingOzonePlatform())
     ui::SetDefaultX11ErrorHandlers();
 #endif
-#if defined(USE_AURA) && (defined(OS_LINUX) || defined(OS_CHROMEOS))
+#if defined(USE_AURA) && (defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD))
   ui::InitializeInputMethodForTesting();
 #endif
 #if defined(OS_ANDROID)
