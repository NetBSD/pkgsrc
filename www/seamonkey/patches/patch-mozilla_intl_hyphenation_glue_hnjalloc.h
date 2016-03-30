$NetBSD: patch-mozilla_intl_hyphenation_glue_hnjalloc.h,v 1.1 2016/03/30 12:56:53 ryoon Exp $

--- mozilla/intl/hyphenation/glue/hnjalloc.h.orig	2016-01-19 02:46:55.000000000 +0000
+++ mozilla/intl/hyphenation/glue/hnjalloc.h
@@ -24,6 +24,9 @@
  */
 
 #include <stdio.h> /* ensure stdio.h is loaded before our macros */
+#ifdef __sun
+#include <wchar.h>
+#endif
 
 #undef FILE
 #define FILE hnjFile
