$NetBSD: patch-browser_app_nsBrowserApp.cpp,v 1.13 2017/06/14 11:28:44 ryoon Exp $

--- browser/app/nsBrowserApp.cpp.orig	2017-06-05 20:45:13.000000000 +0000
+++ browser/app/nsBrowserApp.cpp
@@ -261,6 +261,11 @@ int main(int argc, char* argv[], char* e
 {
   mozilla::TimeStamp start = mozilla::TimeStamp::Now();
 
+  setenv("MOZ_PLUGIN_PATH", "@PREFIX@/lib/browser_plugins/symlinks/gecko", 0);
+
+  setenv("MOZ_GMP_PATH", "@PREFIX@/lib/browser_plugins/symlinks/gecko", 0);
+  setenv("MOZ_PLUGIN_PATH", "@PREFIX@/lib/browser_plugins/symlinks/gecko", 0);
+
 #ifdef HAS_DLL_BLOCKLIST
   DllBlocklist_Initialize();
 #endif
