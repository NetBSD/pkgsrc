$NetBSD: patch-swisswatch.c,v 1.1 2025/12/18 13:02:19 nia Exp $

Include <stdlib.h> for exit(3).

--- swisswatch.c.orig	2025-12-18 12:51:25.077745919 +0000
+++ swisswatch.c
@@ -11,6 +11,7 @@
 #include <X11/StringDefs.h>
 #include "SwissWatch.h"
 #include <stdio.h>
+#include <stdlib.h>
 
 #if NeedFunctionPrototypes
 static Widget initialize_user_interface(int*argcp,char**argv);
