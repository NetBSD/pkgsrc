$NetBSD: patch-cherokee_common-internal.h,v 1.1 2012/03/22 22:40:18 asau Exp $

NetBSD uses int64_t for time_t.

--- cherokee/common-internal.h.orig	2011-10-12 18:07:44.000000000 +0000
+++ cherokee/common-internal.h
@@ -239,6 +239,8 @@ char *strcasestr(char *s, char *find);
 #  define TIME_MAX ((time_t)INT_MAX)
 # elif (SIZEOF_TIME_T == SIZEOF_LONG)
 #  define TIME_MAX ((time_t)LONG_MAX)
+# elif (SIZEOF_TIME_T == 8) /* sizeof(int64_t) */
+#  define TIME_MAX ((time_t)0x7fffffffffffffffULL)
 # else
 #  error "Can't define TIME_MAX"
 # endif
