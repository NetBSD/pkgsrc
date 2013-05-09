$NetBSD: patch-src_3rdparty_clucene_src_CLucene_config_repl__tchar.h,v 1.1 2013/05/09 14:07:08 joerg Exp $

--- src/3rdparty/clucene/src/CLucene/config/repl_tchar.h.orig	2012-11-23 10:10:12.000000000 +0000
+++ src/3rdparty/clucene/src/CLucene/config/repl_tchar.h
@@ -33,7 +33,7 @@
     #define _tcscpy wcscpy //copy a string to another string
     #define _tcsncpy wcsncpy //copy a specified amount of one string to another string.
     #define _tcscat wcscat //copy a string onto the end of the other string
-    #define _tcschr wcschr //find location of one character
+    #define _tcschr ::std::wcschr //find location of one character
     #define _tcsstr wcsstr //find location of a string
     #define _tcslen wcslen //get length of a string
     #define _tcscmp wcscmp //case sensitive compare two strings
