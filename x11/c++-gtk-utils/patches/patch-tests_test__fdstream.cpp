$NetBSD: patch-tests_test__fdstream.cpp,v 1.1 2014/08/19 13:45:48 joerg Exp $

Don't test char16 / char32 support as it isn't used by the package.

--- tests/test_fdstream.cpp.orig	2014-08-18 21:02:31.000000000 +0000
+++ tests/test_fdstream.cpp
@@ -171,7 +171,7 @@ static void test_fdstream_wide_copy() {
 }
 
 static void test_fdstream_u16_copy() {
-
+#if 0
   unlink(U16_COPY_FILENAME "1");
   unlink(U16_COPY_FILENAME "2");
 
@@ -224,10 +224,11 @@ static void test_fdstream_u16_copy() {
 
   unlink(U16_COPY_FILENAME "1");
   unlink(U16_COPY_FILENAME "2");
+#endif
 }
 
 static void test_fdstream_u32_copy() {
-
+#if 0
   unlink(U32_COPY_FILENAME "1");
   unlink(U32_COPY_FILENAME "2");
 
@@ -280,6 +281,7 @@ static void test_fdstream_u32_copy() {
 
   unlink(U32_COPY_FILENAME "1");
   unlink(U32_COPY_FILENAME "2");
+#endif
 }
 
 static void test_fdstream_random() {
