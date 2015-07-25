$NetBSD: patch-os_io.c,v 1.1 2015/07/25 04:10:53 markd Exp $

move X11/Xpoll.h include earlier than sys/select.h to avoid missing
out on setting FD_SETSIZE early enough.

--- os/io.c.orig	2015-07-21 21:58:59.000000000 +0000
+++ os/io.c
@@ -51,6 +51,8 @@ SOFTWARE.
  *
  *****************************************************************/
 
+#include <X11/Xpoll.h>
+
 #ifdef HAVE_DIX_CONFIG_H
 #include <dix-config.h>
 #endif
@@ -74,7 +76,6 @@ SOFTWARE.
 #include <X11/Xproto.h>
 #include "os.h"
 #include "osdep.h"
-#include <X11/Xpoll.h>
 #include "opaque.h"
 #include "dixstruct.h"
 #include "misc.h"
