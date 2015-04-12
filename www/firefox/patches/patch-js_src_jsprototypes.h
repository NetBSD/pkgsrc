$NetBSD: patch-js_src_jsprototypes.h,v 1.1 2015/04/12 06:24:32 martin Exp $

Hack around #ifdef inconsistency (depending on exact include order) in
some unified builds, 
see https://bugzilla.mozilla.org/show_bug.cgi?id=1152776

Remove this patch once we switch to the firefox-38 branch (where the
#ifdef JS_HAVE_SYMBOLS is gone).

--- js/src/jsprototypes.h.orig	2015-04-11 19:06:44.000000000 +0200
+++ js/src/jsprototypes.h	2015-04-11 19:06:31.000000000 +0200
@@ -62,7 +62,7 @@
 #define IF_SAB(real,imaginary) imaginary
 #endif
 
-#ifdef JS_HAS_SYMBOLS
+#if 1
 #define IF_SYMBOLS(real,imaginary) real
 #else
 #define IF_SYMBOLS(real,imaginary) imaginary
