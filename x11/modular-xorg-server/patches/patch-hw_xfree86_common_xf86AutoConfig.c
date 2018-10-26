$NetBSD: patch-hw_xfree86_common_xf86AutoConfig.c,v 1.3 2018/10/26 10:20:12 maya Exp $

Look for wsfb on netbsd (needed by genfb)

--- hw/xfree86/common/xf86AutoConfig.c.orig	2018-10-25 14:13:21.000000000 +0000
+++ hw/xfree86/common/xf86AutoConfig.c
@@ -313,6 +313,10 @@ listPossibleVideoDrivers(XF86MatchedDriv
 #elif defined(__sparc__) && !defined(__sun)
     xf86AddMatchedDriver(md, "sunffb");
 #endif
+#if defined(__NetBSD__)
+    xf86AddMatchedDriver(md, "wsfb");
+#endif
+
 }
 
 /* copy a screen section and enter the desired driver
