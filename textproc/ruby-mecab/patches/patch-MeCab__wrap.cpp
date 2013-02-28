$NetBSD: patch-MeCab__wrap.cpp,v 1.1 2013/02/28 12:31:39 obache Exp $

* Ruby-1.8 compatibility fix
  http://code.google.com/p/mecab/issues/detail?id=3

--- MeCab_wrap.cpp.orig	2013-02-17 17:24:16.000000000 +0000
+++ MeCab_wrap.cpp
@@ -1856,8 +1856,7 @@ static VALUE mMeCab;
 
 /* Workaround for ruby1.9.x */
 #if defined SWIGRUBY
-#include "ruby/version.h"
-#if RUBY_API_VERSION_CODE >= 10900
+#if HAVE_RUBY_ENCODING_H
 #include "ruby/encoding.h"
 #define rb_str_new rb_external_str_new
 #endif
