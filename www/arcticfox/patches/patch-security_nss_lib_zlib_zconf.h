$NetBSD: patch-security_nss_lib_zlib_zconf.h,v 1.1 2025/10/12 09:40:03 mrg Exp $

Terrible hack for GCC 14, and others.  Z_HAVE_UNISTD_H doesn't get set,
so it doesn't try to include <unistd.h>.  Fail happens.


--- security/nss/lib/zlib/zconf.h.orig	2025-07-16 15:47:04.000000000 -0700
+++ security/nss/lib/zlib/zconf.h	2025-10-11 23:59:26.109778584 -0700
@@ -356,6 +356,11 @@ typedef uLong FAR uLongf;
    typedef Byte       *voidp;
 #endif
 
+/* XXXMRG: Doesn't get set. */
+#if defined(__NetBSD__) && !defined(Z_HAVE_UNISTD_H)
+#  define Z_HAVE_UNISTD_H
+#endif
+
 #ifdef HAVE_UNISTD_H    /* may be set to #if 1 by ./configure */
 #  define Z_HAVE_UNISTD_H
 #endif
