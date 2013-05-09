$NetBSD: patch-Source_ThirdParty_gtest_include_gtest_internal_gtest-port.h,v 1.2 2013/05/09 14:04:42 joerg Exp $

--- Source/ThirdParty/gtest/include/gtest/internal/gtest-port.h.orig	2012-05-12 19:43:43.000000000 +0000
+++ Source/ThirdParty/gtest/include/gtest/internal/gtest-port.h
@@ -35,6 +35,7 @@
 
 #ifndef GTEST_INCLUDE_GTEST_INTERNAL_GTEST_PORT_H_
 #define GTEST_INCLUDE_GTEST_INTERNAL_GTEST_PORT_H_
+#include <ciso646>
 
 // The user can define the following macros in the build script to
 // control Google Test's behavior.  If the user doesn't define a macro
@@ -173,6 +174,7 @@
 #include <stdlib.h>
 #include <stdio.h>
 #include <string.h>
+#include <unistd.h>
 #ifndef _WIN32_WCE
 #include <sys/stat.h>
 #endif  // !_WIN32_WCE
@@ -443,7 +445,14 @@
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
