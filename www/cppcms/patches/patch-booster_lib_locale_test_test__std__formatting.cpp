$NetBSD: patch-booster_lib_locale_test_test__std__formatting.cpp,v 1.1 2013/07/16 10:12:48 joerg Exp $

--- booster/lib/locale/test/test_std_formatting.cpp.orig	2013-07-02 19:33:35.000000000 +0000
+++ booster/lib/locale/test/test_std_formatting.cpp
@@ -153,10 +153,10 @@ void test_by_char(std::locale const &l,s
 
         ss << as::currency << as::currency_iso;
         ss << 1043.34;
-        TEST(ss);
+        TEST(!ss.bad());
         double v1;
         ss >> v1;
-        TEST(ss);
+        TEST(!ss.bad());
         TEST(v1==1043.34);
 
         ss_ref_type ss_ref;
