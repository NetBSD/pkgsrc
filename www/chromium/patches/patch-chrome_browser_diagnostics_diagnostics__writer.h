$NetBSD: patch-chrome_browser_diagnostics_diagnostics__writer.h,v 1.15 2026/02/15 09:03:57 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/diagnostics/diagnostics_writer.h.orig	2026-02-03 22:07:10.000000000 +0000
+++ chrome/browser/diagnostics/diagnostics_writer.h
@@ -16,6 +16,8 @@ namespace diagnostics {
 // Console base class used internally.
 class SimpleConsole;
 
+#undef MACHINE
+
 class DiagnosticsWriter : public DiagnosticsModel::Observer {
  public:
   // The type of formatting done by this writer.
