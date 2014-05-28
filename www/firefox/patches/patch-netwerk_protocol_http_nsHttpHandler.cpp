$NetBSD: patch-netwerk_protocol_http_nsHttpHandler.cpp,v 1.1 2014/05/28 10:08:18 pho Exp $

nsCocoaFeatures is only available when the toolkit is cocoa.

--- netwerk/protocol/http/nsHttpHandler.cpp.orig	2014-05-06 22:56:20.000000000 +0000
+++ netwerk/protocol/http/nsHttpHandler.cpp
@@ -57,7 +57,7 @@
 #include <windows.h>
 #endif
 
-#if defined(XP_MACOSX)
+#if defined(MOZ_WIDGET_COCOA)
 #include <CoreServices/CoreServices.h>
 #include "nsCocoaFeatures.h"
 #endif
@@ -671,7 +671,7 @@ nsHttpHandler::InitUserAgentComponents()
     "OS/2"
 #elif defined(XP_WIN)
     "Windows"
-#elif defined(XP_MACOSX)
+#elif defined(MOZ_WIDGET_COCOA)
     "Macintosh"
 #elif defined(MOZ_X11)
     "X11"
@@ -734,7 +734,7 @@ nsHttpHandler::InitUserAgentComponents()
             PR_smprintf_free(buf);
         }
     }
-#elif defined (XP_MACOSX)
+#elif defined (MOZ_WIDGET_COCOA)
 #if defined(__ppc__)
     mOscpu.AssignLiteral("PPC Mac OS X");
 #elif defined(__i386__) || defined(__x86_64__)
