$NetBSD: patch-src_util_patcache.c,v 1.1.2.2 2014/05/21 13:14:03 tron Exp $

Fix compatibility with fontsproto-2.1.3.

--- src/util/patcache.c.orig	2014-01-07 16:25:08.000000000 +0000
+++ src/util/patcache.c
@@ -128,7 +128,7 @@ Hash (const char *string, int len)
 /* add entry */
 void
 CacheFontPattern (FontPatternCachePtr cache,
-		  char *pattern,
+		  const char *pattern,
 		  int patlen,
 		  FontPtr pFont)
 {
@@ -174,7 +174,7 @@ CacheFontPattern (FontPatternCachePtr ca
 /* find matching entry */
 FontPtr
 FindCachedFontPattern (FontPatternCachePtr cache,
-		       char *pattern,
+		       const char *pattern,
 		       int patlen)
 {
     int				hash;
