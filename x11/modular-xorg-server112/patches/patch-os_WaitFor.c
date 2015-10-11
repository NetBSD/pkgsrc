$NetBSD: patch-os_WaitFor.c,v 1.1 2015/10/11 17:51:47 tnn Exp $

move X11/Xpoll.h include earlier than sys/select.h to avoid missing
out on setting FD_SETSIZE early enough.

--- os/WaitFor.c.orig	2015-05-21 14:23:54.000000000 +0000
+++ os/WaitFor.c
@@ -52,6 +52,10 @@ SOFTWARE.
  *
  *****************************************************************/
 
+#ifdef __NetBSD__
+#include <X11/Xpoll.h>
+#endif
+
 #ifdef HAVE_DIX_CONFIG_H
 #include <dix-config.h>
 #endif
