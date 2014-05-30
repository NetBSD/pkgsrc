$NetBSD: patch-netwerk_build_nsNetModule.cpp,v 1.1 2014/05/30 03:03:36 pho Exp $

Don't assume cocoa toolkit just because OS_ARCH is Darwin.

--- netwerk/build/nsNetModule.cpp.orig	2014-05-06 22:56:19.000000000 +0000
+++ netwerk/build/nsNetModule.cpp
@@ -44,7 +44,7 @@
 
 #include "nsNetCID.h"
 
-#ifndef XP_MACOSX
+#ifndef MOZ_WIDGET_COCOA
 #define BUILD_BINHEX_DECODER 1
 #endif
 
@@ -664,7 +664,7 @@ static void nsNetShutdown()
 
     // Release global state used by the URL helper module.
     net_ShutdownURLHelper();
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
     net_ShutdownURLHelperOSX();
 #endif
     
