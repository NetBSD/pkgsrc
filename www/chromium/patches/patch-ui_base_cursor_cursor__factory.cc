$NetBSD: patch-ui_base_cursor_cursor__factory.cc,v 1.25 2026/09/02 13:13:38 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/base/cursor/cursor_factory.cc.orig	2026-08-31 22:47:51.000000000 +0000
+++ ui/base/cursor/cursor_factory.cc
@@ -98,7 +98,7 @@ void CursorFactory::ObserveThemeChanges(
   NOTIMPLEMENTED();
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 
 bool IsValidCursorThemeName(std::string_view name) {
   if (name.empty() || name == ".") {
