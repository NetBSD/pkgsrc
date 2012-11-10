$NetBSD: patch-lib_Xm_XpmI.h,v 1.1 2012/11/10 17:10:11 ryoon Exp $

--- lib/Xm/XpmI.h.orig	2012-10-22 14:50:34.000000000 +0000
+++ lib/Xm/XpmI.h
@@ -182,6 +182,18 @@ extern FILE *popen();
 		boundCheckingCalloc((long)(nelem),(long) (elsize))
 #endif
 
+#if defined(SCO) || defined(__USLC__)
+#include <stdint.h>	/* For SIZE_MAX */
+#endif
+#include <limits.h>
+#ifndef SIZE_MAX
+# ifdef ULONG_MAX
+#  define SIZE_MAX ULONG_MAX
+# else 
+#  define SIZE_MAX UINT_MAX
+# endif
+#endif
+
 #define XPMMAXCMTLEN BUFSIZ
 typedef struct {
     unsigned int type;
