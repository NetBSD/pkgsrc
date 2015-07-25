$NetBSD: patch-os_WaitFor.c,v 1.1 2015/07/25 04:10:53 markd Exp $

move X11/Xpoll.h include earlier than sys/select.h to avoid missing
out on setting FD_SETSIZE early enough.

--- os/WaitFor.c.orig	2015-07-21 21:58:16.000000000 +0000
+++ os/WaitFor.c
@@ -52,6 +52,8 @@ SOFTWARE.
  *
  *****************************************************************/
 
+#include <X11/Xpoll.h>
+
 #ifdef HAVE_DIX_CONFIG_H
 #include <dix-config.h>
 #endif
@@ -66,7 +68,6 @@ SOFTWARE.
 #include "misc.h"
 
 #include "osdep.h"
-#include <X11/Xpoll.h>
 #include "dixstruct.h"
 #include "opaque.h"
 #ifdef DPMSExtension
