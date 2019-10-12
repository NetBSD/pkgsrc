$NetBSD: patch-src_cpp_base64.cpp,v 1.1 2019/10/12 22:57:08 he Exp $

Don't assume that "char" is signed.

--- src/cpp/base64.cpp.orig	2010-05-20 22:57:38.000000000 +0000
+++ src/cpp/base64.cpp
@@ -14,7 +14,7 @@ using namespace xmlrpc_c;
 
 namespace {
 
-char const table_a2b_base64[] = {
+int const table_a2b_base64[] = {
     -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1,
     -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1,
     -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,62, -1,-1,-1,63,
