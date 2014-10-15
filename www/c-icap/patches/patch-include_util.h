$NetBSD: patch-include_util.h,v 1.2 2014/10/15 22:10:21 joerg Exp $

--- include/util.h.orig	2014-10-15 13:40:56.000000000 +0000
+++ include/util.h
@@ -41,7 +41,7 @@ CI_DECLARE_FUNC(struct tm*) localtime_r(
 CI_DECLARE_FUNC(struct tm*) gmtime_r(const time_t *t, struct tm *tm);
 #endif
 
-#ifndef HAVE_STRNSTR
+#if !CI_HAVE_STRNSTR
 CI_DECLARE_FUNC(const char *) strnstr(const char *s, const char *find, size_t slen);
 #endif
 
