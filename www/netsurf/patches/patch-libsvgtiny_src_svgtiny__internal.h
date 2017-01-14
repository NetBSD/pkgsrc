$NetBSD: patch-libsvgtiny_src_svgtiny__internal.h,v 1.1 2017/01/14 23:33:34 leot Exp $

Fix build for gperf>=3.1 where 'len' parameter of the hash function
and of the lookup function is of type 'size_t'.

--- libsvgtiny/src/svgtiny_internal.h.orig	2016-11-19 14:22:38.000000000 +0000
+++ libsvgtiny/src/svgtiny_internal.h
@@ -105,6 +105,6 @@ void svgtiny_list_free(struct svgtiny_li
 /* colors.gperf */
 const struct svgtiny_named_color *
 		svgtiny_color_lookup(register const char *str,
-				register unsigned int len);
+				register size_t len);
 
 #endif
