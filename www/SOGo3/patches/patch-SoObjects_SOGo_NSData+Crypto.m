$NetBSD: patch-SoObjects_SOGo_NSData+Crypto.m,v 1.1 2017/07/01 22:14:42 joerg Exp $

--- SoObjects/SOGo/NSData+Crypto.m.orig	2017-07-01 20:55:22.227865760 +0000
+++ SoObjects/SOGo/NSData+Crypto.m
@@ -23,16 +23,11 @@
  * Boston, MA 02111-1307, USA.
  */
 
-#if !defined(__OpenBSD__) && !defined(__FreeBSD__)
-#include <crypt.h>
-#endif
+#define _XOPEN_SOURCE 1
 
 #include <fcntl.h>
 #include <unistd.h>
 
-#define _XOPEN_SOURCE 1
-#include <unistd.h>
-
 #if defined(HAVE_GNUTLS)
 #include <gnutls/gnutls.h>
 #include <gnutls/crypto.h>
