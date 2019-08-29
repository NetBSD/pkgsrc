$NetBSD: patch-php_php5_xapian__wrap.cc,v 1.1 2019/08/29 13:41:15 schmonz Exp $

Reorder includes to fix SmartOS bulk build error:
"/usr/include/locale.h:53:12: error: 'lconv' is already declared in this scope"
<https://trac.xapian.org/ticket/793>

--- php/php5/xapian_wrap.cc.orig	2019-07-24 03:37:23.000000000 +0000
+++ php/php5/xapian_wrap.cc
@@ -17,6 +17,8 @@
 #define SWIG_PREFIX "Xapian"
 #define SWIG_PREFIX_LEN 6
 
+#include <string>
+
 #ifdef __cplusplus
 /* SwigValueWrapper is described in swig.swg */
 template<typename T> class SwigValueWrapper {
