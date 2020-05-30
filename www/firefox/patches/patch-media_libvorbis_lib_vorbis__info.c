$NetBSD: patch-media_libvorbis_lib_vorbis__info.c,v 1.1 2020/05/30 08:02:52 rillig Exp $

Fix undefined behavior when calling <ctype.h> functions with illegal values.

media/libvorbis/lib/vorbis_info.c:81:8: error: array subscript is of type 'char' [-Werror,-Wchar-subscripts]

https://bugzilla.mozilla.org/show_bug.cgi?id=1642081

--- media/libvorbis/lib/vorbis_info.c.orig	2020-05-07 18:34:46.000000000 +0000
+++ media/libvorbis/lib/vorbis_info.c
@@ -78,7 +78,7 @@ void vorbis_comment_add_tag(vorbis_comme
 static int tagcompare(const char *s1, const char *s2, int n){
   int c=0;
   while(c < n){
-    if(toupper(s1[c]) != toupper(s2[c]))
+    if(toupper((unsigned char) s1[c]) != toupper((unsigned char) s2[c]))
       return !0;
     c++;
   }
