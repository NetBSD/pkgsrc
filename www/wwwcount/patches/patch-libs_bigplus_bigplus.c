$NetBSD: patch-libs_bigplus_bigplus.c,v 1.1 2025/10/12 01:00:48 mrg Exp $

Include <ctype.h> to use these definitions.


--- libs/bigplus/bigplus.c.orig	1998-12-30 17:24:50.000000000 -0800
+++ libs/bigplus/bigplus.c	2025-10-11 16:10:22.177825696 -0700
@@ -32,6 +32,10 @@
 #include <string.h>
 #endif
 
+#if HAVE_CTYPE_H
+#include <ctype.h>
+#endif
+
 #include "bigplus.h"
 
 _PROTOTYPE(static bc_num _do_add, (bc_num n1, bc_num n2, int scale_min));
