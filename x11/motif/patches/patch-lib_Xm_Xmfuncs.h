$NetBSD: patch-lib_Xm_Xmfuncs.h,v 1.2 2025/07/09 10:51:32 jperkin Exp $

Avoid all the outdated #ifdef mess on SunOS. SunOS had both bcopy/bzero/bcmp
and memmove/memcmp/memset since at least 1996.

--- lib/Xm/Xmfuncs.h.orig	2016-03-16 02:10:08.000000000 +0000
+++ lib/Xm/Xmfuncs.h
@@ -34,6 +34,8 @@ in this Software without prior written a
 
 /* the old Xfuncs.h, for pre-R6 */
 
+#ifndef __sun
+
 #ifdef X_USEBFUNCS
 void bcopy();
 void bzero();
@@ -88,4 +90,8 @@ int bcmp();
 #endif /* SYSV else */
 #endif /* ! X_NOT_STDC_ENV else */
 
+#else
+#include <strings.h>
+#endif /* __sun */
+
 #endif /* _XFUNCS_H_ */
