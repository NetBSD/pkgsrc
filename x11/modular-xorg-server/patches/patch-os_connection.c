$NetBSD: patch-os_connection.c,v 1.1 2015/07/25 04:10:53 markd Exp $

move X11/Xpoll.h include earlier than sys/select.h to avoid missing
out on setting FD_SETSIZE early enough.

--- os/connection.c.orig	2015-07-21 21:58:52.000000000 +0000
+++ os/connection.c
@@ -60,6 +60,8 @@ SOFTWARE.
  *
  *****************************************************************/
 
+#include <X11/Xpoll.h>
+
 #ifdef HAVE_DIX_CONFIG_H
 #include <dix-config.h>
 #endif
@@ -103,7 +105,6 @@ SOFTWARE.
 #endif                          /* WIN32 */
 #include "misc.h"               /* for typedef of pointer */
 #include "osdep.h"
-#include <X11/Xpoll.h>
 #include "opaque.h"
 #include "dixstruct.h"
 #include "xace.h"
