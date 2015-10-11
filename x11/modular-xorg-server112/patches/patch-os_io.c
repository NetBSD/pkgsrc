$NetBSD: patch-os_io.c,v 1.1 2015/10/11 17:51:47 tnn Exp $

move X11/Xpoll.h include earlier than sys/select.h to avoid missing
out on setting FD_SETSIZE early enough.

--- os/io.c.orig	2015-05-21 14:23:54.000000000 +0000
+++ os/io.c
@@ -51,6 +51,10 @@ SOFTWARE.
  *
  *****************************************************************/
 
+#ifdef __NetBSD__
+#include <X11/Xpoll.h>
+#endif
+
 #ifdef HAVE_DIX_CONFIG_H
 #include <dix-config.h>
 #endif
