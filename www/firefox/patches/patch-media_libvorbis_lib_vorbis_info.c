$NetBSD: patch-media_libvorbis_lib_vorbis_info.c,v 1.2 2016/06/16 12:08:21 ryoon Exp $

* For NetBSD

--- media/libvorbis/lib/vorbis_info.c.orig	2015-01-23 05:59:59.000000000 +0000
+++ media/libvorbis/lib/vorbis_info.c	2015-02-16 14:36:05.000000000 +0000
@@ -87,7 +87,7 @@
 static int tagcompare(const char *s1, const char *s2, int n){
   int c=0;
   while(c < n){
-    if(toupper(s1[c]) != toupper(s2[c]))
+    if(toupper((unsigned char)s1[c]) != toupper((unsigned char)s2[c]))
       return !0;
     c++;
   }
