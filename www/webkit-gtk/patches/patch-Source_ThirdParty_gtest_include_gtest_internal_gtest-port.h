$NetBSD: patch-Source_ThirdParty_gtest_include_gtest_internal_gtest-port.h,v 1.5 2021/09/28 22:11:54 leot Exp $

--- Source/ThirdParty/gtest/include/gtest/internal/gtest-port.h.orig	2021-09-01 09:16:47.000000000 +0000
+++ Source/ThirdParty/gtest/include/gtest/internal/gtest-port.h
@@ -42,6 +42,7 @@
 
 #ifndef GOOGLETEST_INCLUDE_GTEST_INTERNAL_GTEST_PORT_H_
 #define GOOGLETEST_INCLUDE_GTEST_INTERNAL_GTEST_PORT_H_
+#include <ciso646>
 
 // Environment-describing macros
 // -----------------------------
@@ -261,6 +262,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#include <unistd.h>
 
 #include <cerrno>
 #include <cstdint>
