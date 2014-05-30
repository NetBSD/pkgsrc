$NetBSD: patch-xpcom_build_BinaryPath.h,v 1.1 2014/05/30 03:03:36 pho Exp $

Don't assume cocoa toolkit just because OS_ARCH is Darwin.

--- xpcom/build/BinaryPath.h.orig	2014-05-06 22:56:38.000000000 +0000
+++ xpcom/build/BinaryPath.h
@@ -8,7 +8,7 @@
 #include "nsXPCOMPrivate.h" // for MAXPATHLEN
 #ifdef XP_WIN
 #include <windows.h>
-#elif defined(XP_MACOSX)
+#elif defined(MOZ_WIDGET_COCOA)
 #include <CoreFoundation/CoreFoundation.h>
 #elif defined(XP_UNIX)
 #include <sys/stat.h>
@@ -39,7 +39,7 @@ private:
     return NS_ERROR_FAILURE;
   }
 
-#elif defined(XP_MACOSX)
+#elif defined(MOZ_WIDGET_COCOA)
   static nsresult Get(const char *argv0, char aResult[MAXPATHLEN])
   {
     // Works even if we're not bundled.
