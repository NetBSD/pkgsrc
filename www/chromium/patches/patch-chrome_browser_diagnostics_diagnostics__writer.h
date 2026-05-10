$NetBSD: patch-chrome_browser_diagnostics_diagnostics__writer.h,v 1.19 2026/05/10 15:29:49 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/diagnostics/diagnostics_writer.h.orig	2026-04-28 23:05:57.000000000 +0200
+++ chrome/browser/diagnostics/diagnostics_writer.h
@@ -16,6 +16,8 @@ namespace diagnostics {
 // Console base class used internally.
 class SimpleConsole;
 
+#undef MACHINE
+
 class DiagnosticsWriter : public DiagnosticsModel::Observer {
  public:
   // The type of formatting done by this writer.
