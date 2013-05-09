$NetBSD: patch-src_corelib_tools_qiterator.h,v 1.1 2013/05/09 14:07:08 joerg Exp $

--- src/corelib/tools/qiterator.h.orig	2013-05-09 12:25:20.000000000 +0000
+++ src/corelib/tools/qiterator.h
@@ -47,10 +47,7 @@
 QT_BEGIN_HEADER
 
 #ifdef QT_NO_STL
-namespace std {
-    struct bidirectional_iterator_tag;
-    struct random_access_iterator_tag;
-}
+#include <iterator>
 #endif
 
 QT_BEGIN_NAMESPACE
