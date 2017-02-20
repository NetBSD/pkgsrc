$NetBSD: patch-klinkstatus_src_tidy_tidyx.h,v 1.1 2017/02/20 09:35:17 wiz Exp $

tidy-5.x compatibility.

--- klinkstatus/src/tidy/tidyx.h.orig	2008-07-28 16:04:32.000000000 +0000
+++ klinkstatus/src/tidy/tidyx.h
@@ -49,7 +49,7 @@
 */
 
 #include <tidy.h>
-#include <buffio.h>
+#include <tidybuffio.h>
 
 #include <config-tidy.h>
     
