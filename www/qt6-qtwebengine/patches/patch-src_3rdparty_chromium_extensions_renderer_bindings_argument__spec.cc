$NetBSD: patch-src_3rdparty_chromium_extensions_renderer_bindings_argument__spec.cc,v 1.1 2025/12/21 09:38:29 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/extensions/renderer/bindings/argument_spec.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/extensions/renderer/bindings/argument_spec.cc
@@ -18,6 +18,8 @@
 #include "gin/data_object_builder.h"
 #include "gin/dictionary.h"
 
+#include <cmath>
+
 namespace extensions {
 
 namespace {
