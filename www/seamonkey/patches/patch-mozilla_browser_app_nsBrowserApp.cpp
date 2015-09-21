$NetBSD: patch-mozilla_browser_app_nsBrowserApp.cpp,v 1.4 2015/09/21 05:03:45 ryoon Exp $

--- mozilla/browser/app/nsBrowserApp.cpp.orig	2015-09-02 09:27:14.000000000 +0000
+++ mozilla/browser/app/nsBrowserApp.cpp
@@ -18,8 +18,10 @@
 #include <unistd.h>
 #endif
 
-#ifdef XP_MACOSX
+#ifdef XP_DARWIN
 #include <mach/mach_time.h>
+#endif
+#ifdef MOZ_WIDGET_COCOA
 #include "MacQuirks.h"
 #endif
 
@@ -459,7 +461,7 @@ TimeStamp_Now()
   }
 
   return sGetTickCount64() * freq.QuadPart;
-#elif defined(XP_MACOSX)
+#elif defined(XP_DARWIN)
   return mach_absolute_time();
 #elif defined(HAVE_CLOCK_MONOTONIC)
   struct timespec ts;
@@ -606,6 +608,7 @@ int main(int argc, char* argv[])
   TriggerQuirks();
 #endif
 
+  setenv("MOZ_PLUGIN_PATH", "%%LOCALBASE%%/lib/browser_plugins/symlinks/gecko", 0);
   int gotCounters;
 #if defined(XP_UNIX)
   struct rusage initialRUsage;
