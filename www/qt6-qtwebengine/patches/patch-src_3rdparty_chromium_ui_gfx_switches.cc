$NetBSD: patch-src_3rdparty_chromium_ui_gfx_switches.cc,v 1.2 2026/04/30 06:39:45 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/ui/gfx/switches.cc.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/ui/gfx/switches.cc
@@ -36,7 +36,7 @@ const char kHeadless[] = "headless";
 // See //components/headless/screen_info/README.md for more details.
 const char kScreenInfo[] = "screen-info";
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Which X11 display to connect to. Emulates the GTK+ "--display=" command line
 // argument. In use only with Ozone/X11.
 const char kX11Display[] = "display";
