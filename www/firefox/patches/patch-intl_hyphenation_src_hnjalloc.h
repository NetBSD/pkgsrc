$NetBSD: patch-intl_hyphenation_src_hnjalloc.h,v 1.2 2014/02/08 09:36:00 ryoon Exp $

--- intl/hyphenation/src/hnjalloc.h.orig	2014-01-28 04:03:43.000000000 +0000
+++ intl/hyphenation/src/hnjalloc.h
@@ -24,6 +24,9 @@
  */
 
 #include <stdio.h> /* ensure stdio.h is loaded before our macros */
+#ifdef __sun
+#include <wchar.h>
+#endif
 
 #undef FILE
 #define FILE hnjFile
