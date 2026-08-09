$NetBSD: patch-ui_base_cursor_cursor__factory.cc,v 1.24 2026/08/09 06:31:24 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/base/cursor/cursor_factory.cc.orig	2026-08-05 20:17:42.000000000 +0000
+++ ui/base/cursor/cursor_factory.cc
@@ -98,7 +98,7 @@ void CursorFactory::ObserveThemeChanges(
   NOTIMPLEMENTED();
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 
 bool IsValidCursorThemeName(std::string_view name) {
   if (name.empty() || name == ".") {
