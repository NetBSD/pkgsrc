$NetBSD: patch-mozilla_browser_app_nsBrowserApp.cpp,v 1.1 2014/03/30 04:13:17 ryoon Exp $

--- mozilla/browser/app/nsBrowserApp.cpp.orig	2014-03-19 01:41:43.000000000 +0000
+++ mozilla/browser/app/nsBrowserApp.cpp
@@ -586,6 +586,7 @@ int main(int argc, char* argv[])
   TriggerQuirks();
 #endif
 
+  setenv("MOZ_PLUGIN_PATH", "%%LOCALBASE%%/lib/browser_plugins/symlinks/gecko", 0);
   int gotCounters;
 #if defined(XP_UNIX)
   struct rusage initialRUsage;
