$NetBSD: patch-Headers_AppKit_NSNibDeclarations.h,v 1.1 2013/03/23 12:20:43 joerg Exp $

--- Headers/AppKit/NSNibDeclarations.h.orig	2013-03-23 11:48:31.000000000 +0000
+++ Headers/AppKit/NSNibDeclarations.h
@@ -32,7 +32,7 @@
 #define _NSNibDeclarations_H_
 #import <GNUstepBase/GSVersionMacros.h>
 
-#if OS_API_VERSION(GS_API_MACOSX, GS_API_LATEST)
+#if OS_API_VERSION(GS_API_MACOSX, GS_API_LATEST) && !defined(__NetBSD__)
 #define IBOutlet
 #define IBAction void
 #endif
