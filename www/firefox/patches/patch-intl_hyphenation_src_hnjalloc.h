$NetBSD: patch-intl_hyphenation_src_hnjalloc.h,v 1.3 2014/02/20 13:19:03 ryoon Exp $

--- intl/hyphenation/src/hnjalloc.h.orig	2013-05-11 19:19:31.000000000 +0000
+++ intl/hyphenation/src/hnjalloc.h
@@ -56,6 +56,9 @@
  */
 
 #include <stdio.h> /* ensure stdio.h is loaded before our macros */
+#ifdef __sun
+#include <wchar.h>
+#endif
 
 #undef FILE
 #define FILE hnjFile
