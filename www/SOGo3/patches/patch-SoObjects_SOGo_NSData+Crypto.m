$NetBSD: patch-SoObjects_SOGo_NSData+Crypto.m,v 1.2 2017/08/22 14:15:33 jperkin Exp $

Expect crypt(3) to be provided by unistd.h, not the ancient crypt.h.
Update _XOPEN_SOURCE for SUSv3 / POSIX.1-2001

https://github.com/inverse-inc/sogo/pull/238

--- SoObjects/SOGo/NSData+Crypto.m.orig	2017-05-09 13:12:07.000000000 +0000
+++ SoObjects/SOGo/NSData+Crypto.m
@@ -23,16 +23,11 @@
  * Boston, MA 02111-1307, USA.
  */
 
-#if !defined(__OpenBSD__) && !defined(__FreeBSD__)
-#include <crypt.h>
-#endif
+#define _XOPEN_SOURCE 600
 
 #include <fcntl.h>
 #include <unistd.h>
 
-#define _XOPEN_SOURCE 1
-#include <unistd.h>
-
 #if defined(HAVE_GNUTLS)
 #include <gnutls/gnutls.h>
 #include <gnutls/crypto.h>
