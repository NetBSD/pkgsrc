$NetBSD: patch-mkf_lib_mkf__ucs4__map.c,v 1.1 2013/05/28 15:22:18 tsutsui Exp $

Pull a change from upstream:
 https://bitbucket.org/arakiken/mlterm/commits/8f6a1a969340b78cbeee5ace4a7200383ca18abe#chg-mkf/lib/mkf_ucs4_map.c
 > mkf_ucs4_map.c: mkf_map_ucs4_to_jisx0213_2000_1 is not cached
 > in mkf_map_ucs4_to() to prefer JISX0208 to JISX0213 all the time.

--- mkf/lib/mkf_ucs4_map.c.orig	2013-05-26 02:13:01.000000000 +0000
+++ mkf/lib/mkf_ucs4_map.c
@@ -246,7 +246,14 @@ mkf_map_ucs4_to(
 	{
 		if( (*map_table[count].map_ucs4_to)( non_ucs , ucs4_code))
 		{
-			cached_map = &map_table[count] ;
+			/*
+			 * Don't cache the map function of JISX0213_2000_1 to
+			 * prefer JISX0208 to JISX0213 all the time.
+			 */
+			if( map_table[count].cs != JISX0213_2000_1)
+			{
+				cached_map = &map_table[count] ;
+			}
 
 			return  1 ;
 		}
