$NetBSD: patch-src_3rdparty_chromium_ui_webui_resources_js_icon.js,v 1.1 2021/08/03 21:04:36 markd Exp $

--- src/3rdparty/chromium/ui/webui/resources/js/icon.js.orig	2020-07-15 18:56:34.000000000 +0000
+++ src/3rdparty/chromium/ui/webui/resources/js/icon.js
@@ -16,7 +16,7 @@ cr.define('cr.icon', function() {
       // supports SCALE_FACTOR_100P on all non-iOS platforms.
       supportedScaleFactors.push(1);
     }
-    if (cr.isMac || cr.isChromeOS || cr.isWindows || cr.isLinux) {
+    if (cr.isMac || cr.isChromeOS || cr.isWindows || cr.isLinux || cr.isBSD) {
       // All desktop platforms support zooming which also updates the renderer's
       // device scale factors (a.k.a devicePixelRatio), and these platforms have
       // high DPI assets for 2x.  Let the renderer pick the closest image for
