$NetBSD: patch-mozilla_intl_hyphenation_hnjalloc.h,v 1.1 2015/01/02 04:26:21 ryoon Exp $

--- mozilla/intl/hyphenation/hnjalloc.h.orig	2014-12-03 06:22:43.000000000 +0000
+++ mozilla/intl/hyphenation/hnjalloc.h
@@ -24,6 +24,9 @@
  */
 
 #include <stdio.h> /* ensure stdio.h is loaded before our macros */
+#ifdef __sun
+#include <wchar.h>
+#endif
 
 #undef FILE
 #define FILE hnjFile
