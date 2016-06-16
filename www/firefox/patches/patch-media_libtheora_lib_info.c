$NetBSD: patch-media_libtheora_lib_info.c,v 1.2 2016/06/16 12:08:21 ryoon Exp $

* For NetBSD

--- media/libtheora/lib/info.c.orig	2015-01-23 05:59:59.000000000 +0000
+++ media/libtheora/lib/info.c	2015-02-16 14:49:17.000000000 +0000
@@ -29,7 +29,7 @@
 static int oc_tagcompare(const char *_s1,const char *_s2,int _n){
   int c;
   for(c=0;c<_n;c++){
-    if(toupper(_s1[c])!=toupper(_s2[c]))return !0;
+    if(toupper((unsigned char)_s1[c])!=toupper((unsigned char)_s2[c]))return !0;
   }
   return _s1[c]!='=';
 }
