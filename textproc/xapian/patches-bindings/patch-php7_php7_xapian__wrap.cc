$NetBSD: patch-php7_php7_xapian__wrap.cc,v 1.1 2019/08/28 19:23:38 schmonz Exp $

Reorder includes to fix SmartOS bulk build error:
"/usr/include/locale.h:53:12: error: 'lconv' is already declared in this scope"
<https://trac.xapian.org/ticket/793>

--- php7/php7/xapian_wrap.cc.orig	2019-07-24 03:37:42.000000000 +0000
+++ php7/php7/xapian_wrap.cc
@@ -17,6 +17,8 @@
 #define SWIG_PREFIX "Xapian"
 #define SWIG_PREFIX_LEN 6
 
+#include <string>
+
 #ifdef __cplusplus
 /* SwigValueWrapper is described in swig.swg */
 template<typename T> class SwigValueWrapper {
