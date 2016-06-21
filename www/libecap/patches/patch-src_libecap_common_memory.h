$NetBSD: patch-src_libecap_common_memory.h,v 1.1 2016/06/21 17:57:07 joerg Exp $

--- src/libecap/common/memory.h.orig	2016-06-20 16:15:17.012240492 +0000
+++ src/libecap/common/memory.h
@@ -4,14 +4,24 @@
 #define LIBECAP__COMMON_MEMORY_H
 
 #include <libecap/common/libecap.h>
+#include <ciso646>
+
+#if __cplusplus >= 201103L || defined(_LIBCPP_VERSION)
+#include <functional>
+#else
 #include <tr1/memory>
+#endif
 
 // TODO: add support for boost pointers if std::tr1 is not available
 
 namespace libecap {
-
+#if __cplusplus >= 201103L || defined(_LIBCPP_VERSION)
+using std::weak_ptr;
+using std::shared_ptr;
+#else
 using std::tr1::weak_ptr;
 using std::tr1::shared_ptr;
+#endif
 
 } // namespace libecap
 
