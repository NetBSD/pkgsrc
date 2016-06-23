$NetBSD: patch-src_libecap_common_memory.h,v 1.2 2016/06/23 15:05:38 prlw1 Exp $

https://bugs.launchpad.net/bugs/1595488

--- src/libecap/common/memory.h.orig	2014-10-02 04:05:24.000000000 +0000
+++ src/libecap/common/memory.h
@@ -4,14 +4,12 @@
 #define LIBECAP__COMMON_MEMORY_H
 
 #include <libecap/common/libecap.h>
-#include <tr1/memory>
-
-// TODO: add support for boost pointers if std::tr1 is not available
+#include <memory>
 
 namespace libecap {
 
-using std::tr1::weak_ptr;
-using std::tr1::shared_ptr;
+using std::weak_ptr;
+using std::shared_ptr;
 
 } // namespace libecap
 
