$NetBSD: patch-src_sass.hpp,v 1.1 2021/01/12 13:06:11 jperkin Exp $

Undefining __EXTENSIONS__ breaks headers, do not do that.

--- src/sass.hpp.orig	2020-05-01 11:17:16.000000000 +0000
+++ src/sass.hpp
@@ -5,7 +5,7 @@
 // undefine extensions macro to tell sys includes
 // that we do not want any macros to be exported
 // mainly fixes an issue on SmartOS (SEC macro)
-#undef __EXTENSIONS__
+//#undef __EXTENSIONS__
 
 #ifdef _MSC_VER
 #pragma warning(disable : 4005)
