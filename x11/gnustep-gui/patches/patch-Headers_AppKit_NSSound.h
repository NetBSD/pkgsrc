$NetBSD: patch-Headers_AppKit_NSSound.h,v 1.1 2023/03/02 15:14:27 wiz Exp $

Add missing include
https://github.com/gnustep/libs-gui/pull/175

--- Headers/AppKit/NSSound.h.orig	2022-12-29 09:05:31.000000000 +0000
+++ Headers/AppKit/NSSound.h
@@ -30,6 +30,7 @@
 
 #ifndef _GNUstep_H_NSSound
 #define _GNUstep_H_NSSound
+#import <AppKit/AppKitDefines.h>
 
 #import <Foundation/NSObject.h>
 #import <Foundation/NSBundle.h>
