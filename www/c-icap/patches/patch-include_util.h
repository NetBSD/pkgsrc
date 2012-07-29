$NetBSD: patch-include_util.h,v 1.1 2012/07/29 10:11:17 adam Exp $

On Mac OS X, strnstr declaration is different

--- include/util.h.orig	2012-05-27 20:30:13.000000000 +0000
+++ include/util.h
@@ -42,8 +42,12 @@ CI_DECLARE_FUNC(struct tm*) gmtime_r(con
 #endif
 
 #ifndef HAVE_STRNSTR
+#ifdef __APPLE__
+CI_DECLARE_FUNC(char *) strnstr(const char *s, const char *find, size_t slen);
+#else
 CI_DECLARE_FUNC(const char *) strnstr(const char *s, const char *find, size_t slen);
 #endif
+#endif
 
 #ifndef HAVE_STRNCASESTR
 CI_DECLARE_FUNC(const char *) strncasestr(const char *s, const char *find, size_t slen);
