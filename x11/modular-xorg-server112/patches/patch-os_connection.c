$NetBSD: patch-os_connection.c,v 1.1 2015/10/11 17:51:47 tnn Exp $

move X11/Xpoll.h include earlier than sys/select.h to avoid missing
out on setting FD_SETSIZE early enough.

--- os/connection.c.orig	2015-06-16 15:21:07.000000000 +0000
+++ os/connection.c
@@ -60,6 +60,10 @@ SOFTWARE.
  *
  *****************************************************************/
 
+#ifdef __NetBSD__
+#include <X11/Xpoll.h>
+#endif
+
 #ifdef HAVE_DIX_CONFIG_H
 #include <dix-config.h>
 #endif
