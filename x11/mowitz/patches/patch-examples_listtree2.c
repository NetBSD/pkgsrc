$NetBSD: patch-examples_listtree2.c,v 1.1 2025/12/20 16:16:55 nia Exp $

Need <stdlib.h> for exit(3).

--- examples/listtree2.c.orig	2025-12-20 16:07:29.886573352 +0000
+++ examples/listtree2.c
@@ -1,4 +1,5 @@
 #include <stdio.h>
+#include <stdlib.h>
 #include <X11/Intrinsic.h>
 #include <X11/StringDefs.h>
 #include "TreeFSel.h"
