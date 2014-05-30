$NetBSD: patch-uriloader_exthandler_nsLocalHandlerApp.h,v 1.1 2014/05/30 03:03:36 pho Exp $

Don't assume cocoa toolkit just because OS_ARCH is Darwin.

--- uriloader/exthandler/nsLocalHandlerApp.h.orig	2014-05-06 22:56:37.000000000 +0000
+++ uriloader/exthandler/nsLocalHandlerApp.h
@@ -47,7 +47,7 @@ protected:
 
 // any platforms that need a platform-specific class instead of just 
 // using nsLocalHandlerApp need to add an include and a typedef here.
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
 # ifndef NSLOCALHANDLERAPPMAC_H_  
 # include "mac/nsLocalHandlerAppMac.h"
 typedef nsLocalHandlerAppMac PlatformLocalHandlerApp_t;
