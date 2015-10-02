$NetBSD: patch-mozilla_browser_app_nsBrowserApp.cpp,v 1.5 2015/10/02 22:49:36 ryoon Exp $

--- mozilla/browser/app/nsBrowserApp.cpp.orig	2015-09-25 07:35:01.000000000 +0000
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
 
@@ -276,7 +278,7 @@ TimeStamp_Now()
   }
 
   return sGetTickCount64() * freq.QuadPart;
-#elif defined(XP_MACOSX)
+#elif defined(XP_DARWIN)
   return mach_absolute_time();
 #elif defined(HAVE_CLOCK_MONOTONIC)
   struct timespec ts;
