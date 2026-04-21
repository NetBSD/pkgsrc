$NetBSD: patch-ui_gfx_font__fallback__linux.cc,v 1.18 2026/04/21 15:21:23 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/gfx/font_fallback_linux.cc.orig	2026-04-14 23:31:37.000000000 +0200
+++ ui/gfx/font_fallback_linux.cc
@@ -28,6 +28,8 @@
 #include "ui/gfx/linux/fontconfig_util.h"
 #include "ui/gfx/platform_font.h"
 
+#include <unistd.h>
+
 namespace gfx {
 
 namespace {
