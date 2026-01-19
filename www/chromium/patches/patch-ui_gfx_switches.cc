$NetBSD: patch-ui_gfx_switches.cc,v 1.14 2026/01/19 16:14:23 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/gfx/switches.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ ui/gfx/switches.cc
@@ -36,7 +36,7 @@ const char kHeadless[] = "headless";
 // See //components/headless/screen_info/README.md for more details.
 const char kScreenInfo[] = "screen-info";
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Which X11 display to connect to. Emulates the GTK+ "--display=" command line
 // argument. In use only with Ozone/X11.
 const char kX11Display[] = "display";
