$NetBSD: patch-mozilla_media_webrtc_trunk_testing_gtest_include_gtest_internal_gtest-port.h,v 1.1 2013/05/23 13:25:30 ryoon Exp $

--- mozilla/media/webrtc/trunk/testing/gtest/include/gtest/internal/gtest-port.h.orig	2013-05-03 03:08:06.000000000 +0000
+++ mozilla/media/webrtc/trunk/testing/gtest/include/gtest/internal/gtest-port.h
@@ -490,10 +490,10 @@
 #  define GTEST_ENV_HAS_TR1_TUPLE_ 1
 # endif
 
-// C++11 specifies that <tuple> provides std::tuple. Users can't use
-// gtest in C++11 mode until their standard library is at least that
-// compliant.
-# if GTEST_LANG_CXX11
+// C++11 specifies that <tuple> provides std::tuple. Use that if gtest is used
+// in C++11 mode and libstdc++ isn't very old (binaries targeting OS X 10.6
+// can build with clang but need to use gcc4.2's libstdc++).
+# if GTEST_LANG_CXX11 && (!defined(__GLIBCXX__) || __GLIBCXX__ > 20110325)
 #  define GTEST_ENV_HAS_STD_TUPLE_ 1
 # endif
 
