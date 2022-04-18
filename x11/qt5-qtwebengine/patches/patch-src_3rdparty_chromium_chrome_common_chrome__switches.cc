$NetBSD: patch-src_3rdparty_chromium_chrome_common_chrome__switches.cc,v 1.2 2022/04/18 11:18:18 adam Exp $

--- src/3rdparty/chromium/chrome/common/chrome_switches.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/chrome/common/chrome_switches.cc
@@ -809,7 +809,7 @@ const char kAllowNaClSocketAPI[]        
 #endif
 
 #if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || \
-    defined(OS_WIN)
+    defined(OS_WIN) || defined(OS_BSD)
 const char kEnableNewAppMenuIcon[] = "enable-new-app-menu-icon";
 
 // Causes the browser to launch directly in guest mode.
