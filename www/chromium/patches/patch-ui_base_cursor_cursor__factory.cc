$NetBSD: patch-ui_base_cursor_cursor__factory.cc,v 1.14 2026/01/19 16:14:22 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/base/cursor/cursor_factory.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ ui/base/cursor/cursor_factory.cc
@@ -97,7 +97,7 @@ void CursorFactory::ObserveThemeChanges(
   NOTIMPLEMENTED();
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 
 // Returns a cursor name compatible with either X11 or the FreeDesktop.org
 // cursor spec ([1] and [2]), followed by fallbacks that can work as
