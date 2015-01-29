$NetBSD: patch-mozilla_browser_app_nsBrowserApp.cpp,v 1.3 2015/01/29 22:22:26 wiz Exp $

--- mozilla/browser/app/nsBrowserApp.cpp.orig	2014-06-13 00:46:02.000000000 +0000
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
 
@@ -447,7 +449,7 @@ TimeStamp_Now()
   }
 
   return sGetTickCount64() * freq.QuadPart;
-#elif defined(XP_MACOSX)
+#elif defined(XP_DARWIN)
   return mach_absolute_time();
 #elif defined(HAVE_CLOCK_MONOTONIC)
   struct timespec ts;
