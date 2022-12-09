$NetBSD: patch-version.h,v 1.1 2022/12/09 14:13:00 vins Exp $

Fix wrong hardcoded version number.

--- version.h.orig	2006-06-22 09:23:28.000000000 +0000
+++ version.h
@@ -2,6 +2,6 @@
  * Keep track of version and patch level of sunclock.
  */
 
-#define	VERSION		"3.56"
-#define RELEASE         "22 06 2006"
+#define	VERSION		"3.57"
+#define RELEASE         "22 08 2008"
 #define COPYRIGHT       "© J.-P. Demailly"
