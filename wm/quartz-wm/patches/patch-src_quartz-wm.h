$NetBSD: patch-src_quartz-wm.h,v 1.1 2021/12/09 09:49:30 schmonz Exp $

Apply upstream patch to fix macOS 12 build.
Upstream: https://trac.macports.org/ticket/63355

--- src/quartz-wm.h.orig	2012-04-29 00:27:13.000000000 +0000
+++ src/quartz-wm.h
@@ -30,6 +30,7 @@
 #define Cursor OSX_Cursor
 #define Picture OSX_Picture
 #import  <Foundation/Foundation.h>
+#include <ApplicationServices/ApplicationServices.h>
 #undef Picture
 #undef Cursor
 
