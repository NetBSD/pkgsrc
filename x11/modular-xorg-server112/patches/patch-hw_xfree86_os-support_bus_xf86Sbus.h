$NetBSD: patch-hw_xfree86_os-support_bus_xf86Sbus.h,v 1.1 2015/09/20 16:39:18 tnn Exp $

NetBSD/sparc64 support.

--- hw/xfree86/os-support/bus/xf86Sbus.h.orig	2012-05-17 17:09:03.000000000 +0000
+++ hw/xfree86/os-support/bus/xf86Sbus.h
@@ -36,6 +36,8 @@
 #elif defined(SVR4)
 #include <sys/fbio.h>
 #include <sys/openpromio.h>
+#elif defined(__NetBSD__) && defined(__sparc64__)
+#include <dev/sun/fbio.h>
 #elif defined(__OpenBSD__) && defined(__sparc64__)
 /* XXX */
 #elif defined(CSRG_BASED)
