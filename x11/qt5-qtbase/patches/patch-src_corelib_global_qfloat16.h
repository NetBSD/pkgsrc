$NetBSD: patch-src_corelib_global_qfloat16.h,v 1.1 2021/07/09 22:48:47 markd Exp $

Fix build with GCC 11: include <limits> 
Fixes: QTBUG-90395 
Change-Id: Iecc74d2000eb40dfbe7bfffd165b5dd3708b7a40 
(cherry picked from commit 9c56d4da 

--- src/corelib/global/qfloat16.h.orig	2020-10-27 08:02:11.000000000 +0000
+++ src/corelib/global/qfloat16.h
@@ -43,6 +43,7 @@
 
 #include <QtCore/qglobal.h>
 #include <QtCore/qmetatype.h>
+#include <limits>
 #include <string.h>
 
 #if defined(QT_COMPILER_SUPPORTS_F16C) && defined(__AVX2__) && !defined(__F16C__)
