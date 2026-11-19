$NetBSD: patch-extensions_renderer_bindings_argument__spec.cc,v 1.33 2026/11/19 19:46:02 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- extensions/renderer/bindings/argument_spec.cc.orig	2026-11-11 21:01:38.000000000 +0000
+++ extensions/renderer/bindings/argument_spec.cc
@@ -20,6 +20,8 @@
 #include "gin/data_object_builder.h"
 #include "gin/dictionary.h"
 
+#include <cmath>
+
 namespace extensions {
 
 namespace {
