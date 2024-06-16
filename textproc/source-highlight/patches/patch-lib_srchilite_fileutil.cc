$NetBSD: patch-lib_srchilite_fileutil.cc,v 1.1 2024/06/16 18:47:42 wiz Exp $

commit 904949c9026cb772dc93fbe0947a252ef47127f4
Author: Tom Tromey <tom@tromey.com>
Date:   Wed Jun 10 20:38:27 2020 -0600

    Remove "throw" specifications

    C++ throw specifications were deprecated in C++11.
    This patch removes them from the library.

--- lib/srchilite/fileutil.cc.orig	2024-06-16 18:45:32.449771762 +0000
+++ lib/srchilite/fileutil.cc
@@ -48,7 +48,7 @@ void set_file_util_verbose(bool b) {
 // FIXME avoid using a global variable
 std::string start_path;
 
-string readFile(const string &fileName) throw (IOException) {
+string readFile(const string &fileName) {
     ifstream file(fileName.c_str());
 
     if (!file.is_open()) {
