$NetBSD: patch-qtwebkit_Source_ThirdParty_gtest_include_gtest_internal_gtest-port.h,v 1.1 2013/12/13 14:38:35 ryoon Exp $

--- qtwebkit/Source/ThirdParty/gtest/include/gtest/internal/gtest-port.h.orig	2013-11-27 01:01:50.000000000 +0000
+++ qtwebkit/Source/ThirdParty/gtest/include/gtest/internal/gtest-port.h
@@ -173,6 +173,7 @@
 #include <stdlib.h>
 #include <stdio.h>
 #include <string.h>
+#include <unistd.h>
 #ifndef _WIN32_WCE
 #include <sys/stat.h>
 #endif  // !_WIN32_WCE
@@ -441,7 +442,14 @@
 // GCC 4.0+ implements tr1/tuple in the <tr1/tuple> header.  This does
 // not conform to the TR1 spec, which requires the header to be <tuple>.
 
-#if !GTEST_HAS_RTTI && GTEST_GCC_VER_ < 40302
+#if defined(_LIBCPP_VERSION)
+#include <tuple>
+namespace std {
+  namespace tr1 {
+    using ::std::tuple;
+  }
+}
+#elif !GTEST_HAS_RTTI && GTEST_GCC_VER_ < 40302
 // Until version 4.3.2, gcc has a bug that causes <tr1/functional>,
 // which is #included by <tr1/tuple>, to not compile when RTTI is
 // disabled.  _TR1_FUNCTIONAL is the header guard for
