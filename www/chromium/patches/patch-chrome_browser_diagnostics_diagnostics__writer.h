$NetBSD: patch-chrome_browser_diagnostics_diagnostics__writer.h,v 1.33 2026/11/19 19:45:52 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/diagnostics/diagnostics_writer.h.orig	2026-11-11 21:01:38.000000000 +0000
+++ chrome/browser/diagnostics/diagnostics_writer.h
@@ -16,6 +16,8 @@ namespace diagnostics {
 // Console base class used internally.
 class SimpleConsole;
 
+#undef MACHINE
+
 class DiagnosticsWriter : public DiagnosticsModel::Observer {
  public:
   // The type of formatting done by this writer.
