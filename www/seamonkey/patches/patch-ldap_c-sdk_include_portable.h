$NetBSD: patch-ldap_c-sdk_include_portable.h,v 1.2 2020/05/06 14:34:53 ryoon Exp $

--- ldap/c-sdk/include/portable.h.orig	2020-02-17 23:36:19.000000000 +0000
+++ ldap/c-sdk/include/portable.h
@@ -122,7 +122,7 @@
  * some systems don't have the BSD re_comp and re_exec routines
  */
 #ifndef NEED_BSDREGEX
-#if ( defined( SYSV ) || defined( NETBSD ) || defined( FREEBSD ) || defined(__OpenBSD__) || defined( linux ) || defined( DARWIN )) && !defined(sgi)
+#if ( defined( SYSV ) || defined( NETBSD ) || defined(DRAGONFLY) || defined( FREEBSD ) || defined(__OpenBSD__) || defined( linux ) || defined( DARWIN )) && !defined(sgi)
 #define NEED_BSDREGEX
 #endif
 #endif
