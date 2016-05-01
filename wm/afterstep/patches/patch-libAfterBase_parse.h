$NetBSD: patch-libAfterBase_parse.h,v 1.2 2016/05/01 19:30:58 dholland Exp $

Patch up gcc inline mess.

--- libAfterBase/parse.h.orig	2013-06-26 19:42:15.000000000 +0000
+++ libAfterBase/parse.h
@@ -73,7 +73,7 @@ format_geometry ( int x, int y, unsigned
 
 double parse_math(const char* str, char** endptr, double size);
 
-inline int unsigned_int2buffer_end (char *buffer, int buffer_size, unsigned int val);
+int unsigned_int2buffer_end (char *buffer, int buffer_size, unsigned int val);
 char *string_from_int (int param);
 char *hex_to_buffer_reverse(void *data, size_t bytes, char* buffer);
 char *hex_to_buffer(void *data, size_t bytes, char* buffer);
