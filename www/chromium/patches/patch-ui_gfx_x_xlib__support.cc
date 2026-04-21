$NetBSD: patch-ui_gfx_x_xlib__support.cc,v 1.18 2026/04/21 15:21:24 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/gfx/x/xlib_support.cc.orig	2026-04-14 23:31:37.000000000 +0200
+++ ui/gfx/x/xlib_support.cc
@@ -39,10 +39,18 @@ void InitXlib() {
     return;
   }
 
+#if BUILDFLAG(IS_BSD)
+  CHECK(xlib_loader->Load("libX11.so"));
+#else
   CHECK(xlib_loader->Load("libX11.so.6"));
+#endif
 
   auto* xlib_xcb_loader = GetXlibXcbLoader();
+#if BUILDFLAG(IS_BSD)
+  CHECK(xlib_xcb_loader->Load("libX11-xcb.so"));
+#else
   CHECK(xlib_xcb_loader->Load("libX11-xcb.so.1"));
+#endif
 
   CHECK(xlib_loader->XInitThreads());
 
