$NetBSD: patch-SoObjects_SOGo_NSData+Crypto.m,v 1.1 2012/11/24 14:06:44 manu Exp $

--- SoObjects/SOGo/NSData+Crypto.m.orig	2012-11-22 18:43:09.000000000 +0100
+++ SoObjects/SOGo/NSData+Crypto.m	2012-11-22 18:43:47.000000000 +0100
@@ -22,9 +22,9 @@
  * the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
  * Boston, MA 02111-1307, USA.
  */
 
-#ifndef __OpenBSD__
+#ifdef __sun
 #include <crypt.h>
 #endif
 
 #include <sys/types.h>
