$NetBSD: patch-third__party_wasm2c_src_c-writer.cc,v 1.1 2025/10/19 11:56:57 leot Exp $

--- third_party/wasm2c/src/c-writer.cc.orig	2025-07-26 13:24:19.226278807 +0000
+++ third_party/wasm2c/src/c-writer.cc
@@ -1490,7 +1490,7 @@ void CWriter::WriteInitExprTerminal(cons
 std::string CWriter::GenerateHeaderGuard() const {
   std::string result;
   for (char c : header_name_) {
-    if (isalnum(c) || c == '_') {
+    if (isalnum((unsigned char)c) || c == '_') {
       result += toupper(c);
     } else {
       result += '_';
