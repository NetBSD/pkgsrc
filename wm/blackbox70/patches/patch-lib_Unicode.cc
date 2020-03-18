$NetBSD: patch-lib_Unicode.cc,v 1.2 2020/03/18 18:02:41 joerg Exp $

--- lib/Unicode.cc.orig	2014-08-30 08:23:20.000000000 +0000
+++ lib/Unicode.cc
@@ -35,6 +35,9 @@
 #  include <langinfo.h>
 #endif
 
+#ifdef __NetBSD__
+#include <sys/param.h>
+#endif
 
 namespace bt {
 
@@ -83,9 +86,13 @@ namespace bt {
     if (cd == invalid)
       return;
 
-    char *inp =
-      reinterpret_cast<char *>
+#if defined(__NetBSD__) && (__NetBSD_Version__-0 < 999001700)
+    const char *inp =
+      reinterpret_cast<const char *>
       (const_cast<typename _Source::value_type *>(in.data()));
+#else
+    char *inp = const_cast<char *>(reinterpret_cast<const char *>((in.data())));
+#endif
     const typename _Source::size_type in_size =
       in.size() * sizeof(typename _Source::value_type);
     typename _Source::size_type in_bytes = in_size;
@@ -108,9 +115,13 @@ namespace bt {
         case EINVAL:
           {
             const typename _Source::size_type off = in_size - in_bytes + 1;
+#if defined(__NetBSD__) && (__NetBSD_Version__-0 < 999001700)
             inp =
-              reinterpret_cast<char *>
+              reinterpret_cast<const char *>
               (const_cast<typename _Source::value_type *>(in.data()));
+#else
+            inp = const_cast<char *>(reinterpret_cast<const char *>((in.data())));
+#endif
             in_bytes = in_size - off;
             break;
           }
