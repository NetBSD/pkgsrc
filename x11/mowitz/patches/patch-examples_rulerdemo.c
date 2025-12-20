$NetBSD: patch-examples_rulerdemo.c,v 1.1 2025/12/20 16:16:55 nia Exp $

Need <stdlib.h> for exit(3).

--- examples/rulerdemo.c.orig	2025-12-20 16:06:34.670315723 +0000
+++ examples/rulerdemo.c
@@ -1,5 +1,6 @@
 
 #include <stdio.h>
+#include <stdlib.h>
 
 #include <X11/StringDefs.h>
 #include <X11/Intrinsic.h>
