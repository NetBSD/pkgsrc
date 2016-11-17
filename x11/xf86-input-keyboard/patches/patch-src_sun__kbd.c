$NetBSD: patch-src_sun__kbd.c,v 1.2 2016/11/17 08:05:55 wiz Exp $

rearrange includes to fix build on OmniOS. Include unistd.h for ioctl(2).

--- src/sun_kbd.c.orig	2013-03-27 00:56:38.000000000 +0000
+++ src/sun_kbd.c
@@ -49,6 +49,12 @@
 #include "config.h"
 #endif
 
+#include <unistd.h> /* for ioctl */
+#include <sys/stropts.h>
+#include <sys/vuid_event.h>
+#include <sys/kbd.h>
+#include <sys/note.h>	/* needed before including older versions of hid.h */
+#include <sys/usb/clients/hid/hid.h>
 #include <xorg-server.h>
 #include "xf86.h"
 #include "xf86Priv.h"
@@ -56,11 +62,6 @@
 #include "xf86OSKbd.h"
 #include "sun_kbd.h"
 
-#include <sys/stropts.h>
-#include <sys/vuid_event.h>
-#include <sys/kbd.h>
-#include <sys/note.h>	/* needed before including older versions of hid.h */
-#include <sys/usb/clients/hid/hid.h>
 
 static int KbdOn(InputInfoPtr pInfo, int what);
 static Bool OpenKeyboard(InputInfoPtr pInfo);
