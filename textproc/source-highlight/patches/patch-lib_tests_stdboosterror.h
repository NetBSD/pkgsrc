$NetBSD: patch-lib_tests_stdboosterror.h,v 1.1 2020/04/19 01:17:11 joerg Exp $

Make sure that it actually declares a variable.

--- lib/tests/stdboosterror.h.orig	2020-04-18 23:28:34.703528997 +0000
+++ lib/tests/stdboosterror.h
@@ -4,7 +4,7 @@
 #include <boost/regex/pattern_except.hpp>
 
 static boost::regex_error
-        std_boost_exception(boost::regex_error(boost::regex_constants::error_bad_pattern));
+        std_boost_exception = boost::regex_error(boost::regex_constants::error_bad_pattern);
 
 /**
  * returns the string representing a standard exception (which
