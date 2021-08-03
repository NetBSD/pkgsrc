$NetBSD: patch-src_3rdparty_chromium_components_plugins_renderer_plugin__placeholder.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/components/plugins/renderer/plugin_placeholder.cc.orig	2020-07-08 21:40:40.000000000 +0000
+++ src/3rdparty/chromium/components/plugins/renderer/plugin_placeholder.cc
@@ -17,7 +17,7 @@
 #include "third_party/blink/public/web/web_plugin_container.h"
 #include "third_party/blink/public/web/web_script_source.h"
 #include "third_party/blink/public/web/web_serialized_script_value.h"
-#include "third_party/re2/src/re2/re2.h"
+#include <re2/re2.h>
 
 namespace plugins {
 
