$NetBSD: patch-kwalletd_backend_blowfish.h,v 1.1 2013/05/22 07:11:58 jperkin Exp $

--- kwalletd/backend/blowfish.h.orig	2013-03-01 06:34:47.475075625 +0000
+++ kwalletd/backend/blowfish.h
@@ -29,6 +29,10 @@
 #ifdef HAVE_SYS_BITYPES_H
 #include <sys/bitypes.h> /* For uintXX_t on Tru64 */
 #endif
+#ifdef __sun
+#undef _S
+#undef _P
+#endif
 
 #include "blockcipher.h"
 #include <kwallet_export.h>
