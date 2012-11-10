$NetBSD: patch-lib_Xm_Xmfuncs.h,v 1.1 2012/11/10 17:10:10 ryoon Exp $

Avoid all the outdated #ifdef mess on SunOS. SunOS had both bcopy/bzero/bcmp
and memmove/memcmp/memset since at least 1996.

--- lib/Xm/Xmfuncs.h.orig	2012-10-22 14:50:38.000000000 +0000
+++ lib/Xm/Xmfuncs.h
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
