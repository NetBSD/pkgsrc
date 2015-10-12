$NetBSD: patch-os_xdmcp.c,v 1.1 2015/10/12 21:48:33 tnn Exp $

move X11/Xpoll.h include earlier than sys/select.h to avoid missing
out on setting FD_SETSIZE early enough.

--- os/xdmcp.c.orig	2012-05-17 17:09:04.000000000 +0000
+++ os/xdmcp.c
@@ -13,6 +13,10 @@
  *
  */
 
+#ifdef __NetBSD__
+#include <X11/Xpoll.h>
+#endif
+
 #ifdef HAVE_DIX_CONFIG_H
 #include <dix-config.h>
 #endif
