$NetBSD: patch-lib_Xm_Xmfuncs.h,v 1.1 2012/01/12 16:01:46 hans Exp $

Avoid all the outdated #ifdef mess on SunOS. SunOS had both bcopy/bzero/bcmp
and memmove/memcmp/memset since at least 1996.

--- lib/Xm/Xmfuncs.h.orig	2002-01-04 22:23:20.000000000 +0100
+++ lib/Xm/Xmfuncs.h	2012-01-10 19:15:58.346463824 +0100
@@ -34,6 +34,8 @@ in this Software without prior written a
 
 /* the old Xfuncs.h, for pre-R6 */
 
+#ifndef __sun
+
 #ifdef X_USEBFUNCS
 void bcopy();
 void bzero();
@@ -88,4 +90,6 @@ int bcmp();
 #endif /* SYSV else */
 #endif /* ! X_NOT_STDC_ENV else */
 
+#endif /* __sun */
+
 #endif /* _XFUNCS_H_ */
