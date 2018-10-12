$NetBSD: patch-lib_Unicode.cc,v 1.1 2018/10/12 18:00:55 he Exp $

--- lib/Unicode.cc.orig	2016-07-10 16:31:38.000000000 +0000
+++ lib/Unicode.cc
@@ -83,8 +83,8 @@ namespace bt {
     if (cd == invalid)
       return;
 
-    char *inp =
-      reinterpret_cast<char *>
+    const char *inp =
+      reinterpret_cast<const char *>
       (const_cast<typename _Source::value_type *>(in.data()));
     const typename _Source::size_type in_size =
       in.size() * sizeof(typename _Source::value_type);
@@ -109,7 +109,7 @@ namespace bt {
           {
             const typename _Source::size_type off = in_size - in_bytes + 1;
             inp =
-              reinterpret_cast<char *>
+              reinterpret_cast<const char *>
               (const_cast<typename _Source::value_type *>(in.data()));
             in_bytes = in_size - off;
             break;
