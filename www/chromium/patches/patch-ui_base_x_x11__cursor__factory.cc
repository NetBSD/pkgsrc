$NetBSD: patch-ui_base_x_x11__cursor__factory.cc,v 1.15 2026/02/15 09:04:13 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/base/x/x11_cursor_factory.cc.orig	2026-02-03 22:07:10.000000000 +0000
+++ ui/base/x/x11_cursor_factory.cc
@@ -13,7 +13,7 @@
 #include "ui/gfx/geometry/point.h"
 #include "ui/gfx/x/connection.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/linux/linux_ui.h"
 #endif
 
@@ -70,7 +70,7 @@ scoped_refptr<PlatformCursor> X11CursorF
 }
 
 void X11CursorFactory::ObserveThemeChanges() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   auto* linux_ui = LinuxUi::instance();
   DCHECK(linux_ui);
   cursor_theme_observation_.Observe(linux_ui);
