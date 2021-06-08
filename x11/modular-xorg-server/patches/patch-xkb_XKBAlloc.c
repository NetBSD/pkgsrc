$NetBSD: patch-xkb_XKBAlloc.c,v 1.1 2021/06/08 22:51:11 khorben Exp $

Fix build on Solaris 10/amd64 (from pkg/56169)

--- xkb/XKBAlloc.c.orig	2021-04-13 14:11:40.000000000 +0000
+++ xkb/XKBAlloc.c
@@ -36,7 +36,13 @@ THE USE OR PERFORMANCE OF THIS SOFTWARE.
 #include <xkbsrv.h>
 #include "xkbgeom.h"
 #include <os.h>
+#if defined(HAVE_NBCOMPAT_H)
+#include <nbcompat/config.h>
+#include <nbcompat/cdefs.h>
+#include <nbcompat/string.h>
+#else
 #include <string.h>
+#endif
 
 /***===================================================================***/
 
