$NetBSD: patch-browser_app_nsBrowserApp.cpp,v 1.12 2017/04/27 01:49:47 ryoon Exp $

--- browser/app/nsBrowserApp.cpp.orig	2017-04-11 04:15:14.000000000 +0000
+++ browser/app/nsBrowserApp.cpp
@@ -259,6 +259,9 @@ int main(int argc, char* argv[], char* e
 {
   mozilla::TimeStamp start = mozilla::TimeStamp::Now();
 
+  setenv("MOZ_GMP_PATH", "@PREFIX@/lib/browser_plugins/symlinks/gecko", 0);
+  setenv("MOZ_PLUGIN_PATH", "@PREFIX@/lib/browser_plugins/symlinks/gecko", 0);
+
 #ifdef HAS_DLL_BLOCKLIST
   DllBlocklist_Initialize();
 #endif
