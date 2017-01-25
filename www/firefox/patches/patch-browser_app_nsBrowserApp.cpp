$NetBSD: patch-browser_app_nsBrowserApp.cpp,v 1.10 2017/01/25 13:24:51 ryoon Exp $

--- browser/app/nsBrowserApp.cpp.orig	2017-01-16 16:16:49.000000000 +0000
+++ browser/app/nsBrowserApp.cpp
@@ -358,6 +358,9 @@ int main(int argc, char* argv[], char* e
 {
   mozilla::TimeStamp start = mozilla::TimeStamp::Now();
 
+  setenv("MOZ_GMP_PATH", "%%LOCALBASE%%/lib/browser_plugins/symlinks/gecko", 0);
+  setenv("MOZ_PLUGIN_PATH", "%%LOCALBASE%%/lib/browser_plugins/symlinks/gecko", 0);
+
 #ifdef HAS_DLL_BLOCKLIST
   DllBlocklist_Initialize();
 
