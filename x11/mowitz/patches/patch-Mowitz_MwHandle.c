$NetBSD: patch-Mowitz_MwHandle.c,v 1.1 2025/12/20 16:16:55 nia Exp $

Include <stdlib.h> for abs(3).

--- Mowitz/MwHandle.c.orig	2025-12-20 16:05:47.033560943 +0000
+++ Mowitz/MwHandle.c
@@ -4,6 +4,7 @@
  */
 
 #include <stdio.h>
+#include <stdlib.h>
 #include <X11/IntrinsicP.h>
 #include <X11/StringDefs.h>
 #include "MwUtils.h"
