$NetBSD: patch-lib_Xm_Scale.c,v 1.1 2012/11/10 17:10:10 ryoon Exp $

--- lib/Xm/Scale.c.orig	2012-10-22 14:50:34.000000000 +0000
+++ lib/Xm/Scale.c
@@ -74,6 +74,9 @@ static char rcsid[] = "$TOG: Scale.c /ma
 extern "C" { /* some 'locale.h' do not have prototypes (sun) */
 #endif
 #include <X11/Xlocale.h>
+#ifdef __DARWIN__
+#include <locale.h> /* Xlocale.h doesn't define struct lconv */
+#endif
 #ifdef __cplusplus
 } /* Close scope of 'extern "C"' declaration */
 #endif /* __cplusplus */
