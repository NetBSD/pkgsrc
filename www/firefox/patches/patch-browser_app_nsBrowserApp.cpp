$NetBSD: patch-browser_app_nsBrowserApp.cpp,v 1.3 2014/04/30 15:07:18 ryoon Exp $

--- browser/app/nsBrowserApp.cpp.orig	2014-04-18 02:02:30.000000000 +0000
+++ browser/app/nsBrowserApp.cpp
@@ -586,6 +586,7 @@ int main(int argc, char* argv[])
   TriggerQuirks();
 #endif
 
+  setenv("MOZ_PLUGIN_PATH", "%%LOCALBASE%%/lib/browser_plugins/symlinks/gecko", 0);
   int gotCounters;
 #if defined(XP_UNIX)
   struct rusage initialRUsage;
