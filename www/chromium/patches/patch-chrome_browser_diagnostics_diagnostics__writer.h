$NetBSD: patch-chrome_browser_diagnostics_diagnostics__writer.h,v 1.26 2026/09/22 13:41:19 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/diagnostics/diagnostics_writer.h.orig	2026-09-14 22:17:16.000000000 +0000
+++ chrome/browser/diagnostics/diagnostics_writer.h
@@ -16,6 +16,8 @@ namespace diagnostics {
 // Console base class used internally.
 class SimpleConsole;
 
+#undef MACHINE
+
 class DiagnosticsWriter : public DiagnosticsModel::Observer {
  public:
   // The type of formatting done by this writer.
