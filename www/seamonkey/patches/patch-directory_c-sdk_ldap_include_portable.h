$NetBSD: patch-directory_c-sdk_ldap_include_portable.h,v 1.3 2010/07/21 11:48:05 tnn Exp $

Add DragonFly support.
https://bugzilla.mozilla.org/show_bug.cgi?id=577298

--- directory/c-sdk/ldap/include/portable.h.orig	2006-10-03 20:43:40.000000000 +0000
+++ directory/c-sdk/ldap/include/portable.h
@@ -122,8 +122,11 @@
  * some systems don't have the BSD re_comp and re_exec routines
  */
 #ifndef NEED_BSDREGEX
-#if ( defined( SYSV ) || defined( NETBSD ) || defined( freebsd ) || defined( linux ) || defined( DARWIN )) && !defined(sgi)
+#if ( defined( SYSV ) || defined( NETBSD ) || defined( freebsd ) || defined(DRAGONFLY) || defined( linux ) || defined( DARWIN )) && !defined(sgi)
 #define NEED_BSDREGEX
+/* there are conflicting prototypes in unistd.h on DragonFly */
+#define re_comp ldap_compat_re_comp
+#define re_exec ldap_compat_re_exec
 #endif
 #endif
 
@@ -295,7 +298,7 @@ typedef char GETHOSTBYNAME_buf_t [NSLDAP
 #elif defined(HPUX10)
 #define GETHOSTBYNAME_BUF_T struct hostent_data
 #define GETHOSTBYNAME( n, r, b, l, e )	nsldapi_compat_gethostbyname_r( n, r, (char *)&b, l, e )
-#elif defined(LINUX)
+#elif defined(LINUX) || defined(DRAGONFLY)
 typedef char GETHOSTBYNAME_buf_t [NSLDAPI_NETDB_BUF_SIZE];
 #define GETHOSTBYNAME_BUF_T GETHOSTBYNAME_buf_t
 #define GETHOSTBYNAME( n, r, b, l, rp, e )  gethostbyname_r( n, r, b, l, rp, e )
@@ -317,7 +320,7 @@ typedef char GETHOSTBYNAME_buf_t [NSLDAP
 	|| defined(OSF1V4) || defined(AIX) || defined(UnixWare) \
         || defined(hpux) || defined(HPUX11) || defined(NETBSD) \
         || defined(IRIX6) || defined(FREEBSD) || defined(VMS) \
-        || defined(NTO) || defined(OPENBSD)
+        || defined(NTO) || defined(OPENBSD) || defined(DRAGONFLY)
 #define NSLDAPI_CTIME( c, b, l )        ctime_r( c, b )
 #elif defined( OSF1V3 )
 #define NSLDAPI_CTIME( c, b, l )	(ctime_r( c, b, l ) ? NULL : b)
