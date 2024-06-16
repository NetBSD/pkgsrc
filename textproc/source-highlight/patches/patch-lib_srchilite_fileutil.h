$NetBSD: patch-lib_srchilite_fileutil.h,v 1.1 2024/06/16 18:47:42 wiz Exp $

commit 904949c9026cb772dc93fbe0947a252ef47127f4
Author: Tom Tromey <tom@tromey.com>
Date:   Wed Jun 10 20:38:27 2020 -0600

    Remove "throw" specifications

    C++ throw specifications were deprecated in C++11.
    This patch removes them from the library.

--- lib/srchilite/fileutil.h.orig	2024-06-16 18:45:39.263792391 +0000
+++ lib/srchilite/fileutil.h
@@ -27,7 +27,7 @@ extern std::string start_path;
  * @return the contents of the file
  * @throw IOException
  */
-string readFile(const string &fileName) throw (IOException);
+string readFile(const string &fileName);
 
 //char *read_file(const string &fileName);
 
