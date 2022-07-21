$NetBSD: patch-media_libtheora_lib_info.c,v 1.1 2022/07/21 23:56:39 nia Exp $

Fix undefined behavior when calling <ctype.h> functions with illegal values.

media/libtheora/lib/info.c:32:8: error: array subscript is of type 'char' [-Werror,-Wchar-subscripts]

https://bugzilla.mozilla.org/show_bug.cgi?id=1642081

--- media/libtheora/lib/info.c.orig	2020-05-07 18:34:12.000000000 +0000
+++ media/libtheora/lib/info.c
@@ -29,7 +29,7 @@
 static int oc_tagcompare(const char *_s1,const char *_s2,int _n){
   int c;
   for(c=0;c<_n;c++){
-    if(toupper(_s1[c])!=toupper(_s2[c]))return !0;
+    if(toupper((unsigned char)_s1[c])!=toupper((unsigned char)_s2[c]))return !0;
   }
   return _s1[c]!='=';
 }
