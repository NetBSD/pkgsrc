$NetBSD: patch-src_libs_mcfg_mcfg.h,v 1.1 2025/10/12 01:00:48 mrg Exp $

Fix <ctype.h> include.  (For some reason, STDC_HEADERS and GCC 14 is
a problem but I'm struggling to figure it out.  But there's already
an explicit check for ctype.h so use that.)

builds with GCC 14 now.


--- src/libs/mcfg/mcfg.h.orig	1998-12-27 12:53:54.000000000 -0800
+++ src/libs/mcfg/mcfg.h	2025-10-11 16:09:07.642409935 -0700
@@ -4,10 +4,13 @@
 
 #if STDC_HEADERS
 #include <stdlib.h>
-#include <ctype.h>
 #include <string.h>
 #endif
 
+#if HAVE_CTYPE_H
+#include <ctype.h>
+#endif
+
 #if HAVE_STRING_H
 #include <string.h>
 #endif
