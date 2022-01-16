$NetBSD: patch-src_FbTk_Font.cc,v 1.1 2022/01/16 20:10:50 gutteridge Exp $

Do not segfault when fonts cannot be found.
https://github.com/fluxbox/fluxbox/commit/43ae328658518a4ee1b3bf363f8865234c64a674

--- src/FbTk/Font.cc.orig	2015-02-08 10:44:45.357187009 +0000
+++ src/FbTk/Font.cc
@@ -43,6 +43,7 @@
 #include <map>
 #include <typeinfo>
 #include <langinfo.h>
+#include <iostream>
 
 #ifdef HAVE_SETLOCALE
 #include <locale.h>
@@ -231,6 +232,9 @@ bool Font::load(const string &name) {
             m_fontstr = name;
             resetEffects(*this);
             return true;
+        } else {
+            std::cerr << "Couldn't initialize fonts. Check your fontconfig installation.\n";
+            exit(1);
         }
 
         delete tmp_font;
