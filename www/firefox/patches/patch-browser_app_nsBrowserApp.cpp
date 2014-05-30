$NetBSD: patch-browser_app_nsBrowserApp.cpp,v 1.4 2014/05/30 03:03:36 pho Exp $

* Don't assume cocoa toolkit just because OS_ARCH is Darwin.

--- browser/app/nsBrowserApp.cpp.orig	2014-05-06 22:55:09.000000000 +0000
+++ browser/app/nsBrowserApp.cpp
@@ -20,6 +20,8 @@
 
 #ifdef XP_MACOSX
 #include <mach/mach_time.h>
+#endif
+#ifdef MOZ_WIDGET_COCOA
 #include "MacQuirks.h"
 #endif
 
@@ -499,7 +501,7 @@ InitXPCOMGlue(const char *argv0, nsIFile
   lastSlash += sizeof(XPCOM_PATH) - sizeof(XPCOM_DLL);
 
   if (!FileExists(exePath)) {
-#if defined(LIBXUL_SDK) && defined(XP_MACOSX)
+#if defined(LIBXUL_SDK) && defined(MOZ_WIDGET_COCOA)
     // Check for <bundle>/Contents/Frameworks/XUL.framework/libxpcom.dylib
     bool greFound = false;
     CFBundleRef appBundle = CFBundleGetMainBundle();
@@ -582,10 +584,11 @@ int main(int argc, char* argv[])
 #endif
   uint64_t start = TimeStamp_Now();
 
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
   TriggerQuirks();
 #endif
 
+  setenv("MOZ_PLUGIN_PATH", "%%LOCALBASE%%/lib/browser_plugins/symlinks/gecko", 0);
   int gotCounters;
 #if defined(XP_UNIX)
   struct rusage initialRUsage;
@@ -644,7 +647,7 @@ int main(int argc, char* argv[])
 
   NS_LogTerm();
 
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
   // Allow writes again. While we would like to catch writes from static
   // destructors to allow early exits to use _exit, we know that there is
   // at least one such write that we don't control (see bug 826029). For
