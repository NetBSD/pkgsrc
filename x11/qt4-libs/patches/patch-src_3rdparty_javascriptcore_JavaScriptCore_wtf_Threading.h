$NetBSD: patch-src_3rdparty_javascriptcore_JavaScriptCore_wtf_Threading.h,v 1.3 2014/08/10 17:36:09 wiz Exp $

Fix build with clang.

--- src/3rdparty/javascriptcore/JavaScriptCore/wtf/Threading.h.orig	2014-04-10 18:37:12.000000000 +0000
+++ src/3rdparty/javascriptcore/JavaScriptCore/wtf/Threading.h
@@ -78,7 +78,9 @@
 #elif OS(QNX)
 #include <atomic.h>
 #elif COMPILER(GCC) && !OS(SYMBIAN)
-#if (__GNUC__ > 4) || ((__GNUC__ == 4) && (__GNUC_MINOR__ >= 2))
+#include <ciso646>
+#ifdef _LIBCPP_VERSION
+#elif (__GNUC__ > 4) || ((__GNUC__ == 4) && (__GNUC_MINOR__ >= 2))
 #include <ext/atomicity.h>
 #else
 #include <bits/atomicity.h>
