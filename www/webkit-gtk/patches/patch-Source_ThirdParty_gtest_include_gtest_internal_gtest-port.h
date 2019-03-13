$NetBSD: patch-Source_ThirdParty_gtest_include_gtest_internal_gtest-port.h,v 1.4 2019/03/13 20:49:40 leot Exp $

--- Source/ThirdParty/gtest/include/gtest/internal/gtest-port.h.orig	2019-02-12 11:21:03.000000000 +0000
+++ Source/ThirdParty/gtest/include/gtest/internal/gtest-port.h
@@ -42,6 +42,7 @@
 
 #ifndef GTEST_INCLUDE_GTEST_INTERNAL_GTEST_PORT_H_
 #define GTEST_INCLUDE_GTEST_INTERNAL_GTEST_PORT_H_
+#include <ciso646>
 
 // Environment-describing macros
 // -----------------------------
@@ -268,6 +269,7 @@
 #include <stdlib.h>
 #include <stdio.h>
 #include <string.h>
+#include <unistd.h>
 #ifndef _WIN32_WCE
 # include <sys/types.h>
 # include <sys/stat.h>
@@ -755,7 +757,14 @@ typedef struct _RTL_CRITICAL_SECTION GTE
 // GCC 4.0+ implements tr1/tuple in the <tr1/tuple> header.  This does
 // not conform to the TR1 spec, which requires the header to be <tuple>.
 
-#  if !GTEST_HAS_RTTI && GTEST_GCC_VER_ < 40302
+#if defined(_LIBCPP_VERSION)
+#include <tuple>
+namespace std {
+  namespace tr1 {
+     using ::std::tuple;
+  }
+}   
+#elif !GTEST_HAS_RTTI && GTEST_GCC_VER_ < 40302
 // Until version 4.3.2, gcc has a bug that causes <tr1/functional>,
 // which is #included by <tr1/tuple>, to not compile when RTTI is
 // disabled.  _TR1_FUNCTIONAL is the header guard for
