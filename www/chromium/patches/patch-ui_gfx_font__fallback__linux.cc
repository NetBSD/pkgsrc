$NetBSD: patch-ui_gfx_font__fallback__linux.cc,v 1.8 2025/10/16 19:43:37 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/gfx/font_fallback_linux.cc.orig	2025-10-13 21:41:26.000000000 +0000
+++ ui/gfx/font_fallback_linux.cc
@@ -28,6 +28,8 @@
 #include "ui/gfx/linux/fontconfig_util.h"
 #include "ui/gfx/platform_font.h"
 
+#include <unistd.h>
+
 namespace gfx {
 
 namespace {
