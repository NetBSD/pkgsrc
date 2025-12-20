$NetBSD: patch-src_wbxml.h,v 1.1 2025/12/20 14:56:32 nia Exp $

Include <strings.h> for strcasecmp.

--- src/wbxml.h.orig	2025-12-20 14:45:23.322281989 +0000
+++ src/wbxml.h
@@ -47,6 +47,7 @@
  */
 #include <stdlib.h>
 #include <string.h>
+#include <strings.h>
 
 
 /** @addtogroup wbxml
