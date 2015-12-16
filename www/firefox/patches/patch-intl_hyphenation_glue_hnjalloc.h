$NetBSD: patch-intl_hyphenation_glue_hnjalloc.h,v 1.1 2015/12/16 09:34:56 ryoon Exp $

--- intl/hyphenation/glue/hnjalloc.h.orig	2015-12-04 00:36:54.000000000 +0000
+++ intl/hyphenation/glue/hnjalloc.h
@@ -24,6 +24,9 @@
  */
 
 #include <stdio.h> /* ensure stdio.h is loaded before our macros */
+#ifdef __sun
+#include <wchar.h>
+#endif
 
 #undef FILE
 #define FILE hnjFile
