$NetBSD: patch-tests_test__gstream.cpp,v 1.1 2014/08/19 13:45:48 joerg Exp $

Don't test char16 / char32 support as it isn't used by the package.

--- tests/test_gstream.cpp.orig	2014-08-18 21:08:50.000000000 +0000
+++ tests/test_gstream.cpp
@@ -195,7 +195,7 @@ static void test_gstream_wide_copy() {
 }
 
 static void test_gstream_u16_copy() {
-
+#if 0
   unlink(U16_COPY_FILENAME "1");
   unlink(U16_COPY_FILENAME "2");
 
@@ -260,10 +260,11 @@ static void test_gstream_u16_copy() {
 
   unlink(U16_COPY_FILENAME "1");
   unlink(U16_COPY_FILENAME "2");
+#endif
 }
 
 static void test_gstream_u32_copy() {
-
+#if 0
   unlink(U32_COPY_FILENAME "1");
   unlink(U32_COPY_FILENAME "2");
 
@@ -328,6 +329,7 @@ static void test_gstream_u32_copy() {
 
   unlink(U32_COPY_FILENAME "1");
   unlink(U32_COPY_FILENAME "2");
+#endif
 }
 
 static void test_gstream_convert() {
