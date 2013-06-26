$NetBSD: patch-libAfterBase_parse.c,v 1.1 2013/06/26 21:17:45 joerg Exp $

--- libAfterBase/parse.c.orig	2013-06-26 19:46:08.000000000 +0000
+++ libAfterBase/parse.c
@@ -1027,7 +1027,7 @@ parse_geometry (register char *tline,
 
 static char _as_hex_to_char_table[] = "0123456789ABCDEF";
 
-inline int
+int
 unsigned_int2buffer_end (char *buffer, int buffer_size, unsigned int val)
 {
 	int i = buffer_size-1 ; 
