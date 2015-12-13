$NetBSD: patch-SoObjects_SOGo_NSData+Crypto.m,v 1.3 2015/12/13 14:59:35 taca Exp $

--- SoObjects/SOGo/NSData+Crypto.m.orig	2015-11-18 15:19:39.000000000 +0000
+++ SoObjects/SOGo/NSData+Crypto.m
@@ -23,7 +23,7 @@
  * Boston, MA 02111-1307, USA.
  */
 
-#if !defined(__OpenBSD__) && !defined(__FreeBSD__)
+#ifdef __sun
 #include <crypt.h>
 #endif
 
