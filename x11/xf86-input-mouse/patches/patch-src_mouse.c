$NetBSD: patch-src_mouse.c,v 1.1 2013/08/19 09:19:27 wiz Exp $

Set mouse protocol version, so xserver knows how to talk to us.
Do not lose emulate3buttons setting for multiplexed mouse.

--- src/mouse.c.orig	2012-10-08 01:40:07.000000000 +0000
+++ src/mouse.c
@@ -67,6 +67,12 @@
 #include "xserver-properties.h"
 #include "xf86-mouse-properties.h"
 
+#ifdef __NetBSD__
+#include <time.h>
+#include <dev/wscons/wsconsio.h>
+#include <sys/ioctl.h>
+#endif
+
 #include "compiler.h"
 
 #include "xisb.h"
@@ -1733,6 +1739,11 @@ MouseProc(DeviceIntPtr device, int what)
         if (pInfo->fd == -1)
             xf86Msg(X_WARNING, "%s: cannot open input device\n", pInfo->name);
         else {
+#if defined(__NetBSD__) && defined(WSCONS_SUPPORT) && defined(WSMOUSEIO_SETVERSION)
+            int version = WSMOUSE_EVENT_VERSION;
+            if (ioctl(pInfo->fd, WSMOUSEIO_SETVERSION, &version) == -1)
+                xf86Msg(X_WARNING, "%s: cannot set version\n", pInfo->name);
+#endif
             if (pMse->xisbscale)
                 pMse->buffer = XisbNew(pInfo->fd, pMse->xisbscale * 4);
             else
@@ -2046,6 +2057,17 @@ Emulate3ButtonsSoft(InputInfoPtr pInfo)
     if (!pMse->emulate3ButtonsSoft)
         return TRUE;
 
+#if defined(__NetBSD__) && defined(WSCONS_SUPPORT)
+   /*
+    * On NetBSD a wsmouse is a multiplexed device. Imagine a notebook
+    * with two-button mousepad, and an external USB mouse plugged in
+    * temporarily. After using button 3 on the external mouse and
+    * unplugging it again, the mousepad will still need to emulate
+    * 3 buttons.
+    */
+   return TRUE;
+#endif
+
     LogMessageVerbSigSafe(X_INFO, 4, "mouse: 3rd Button detected: disabling emulate3Button\n");
 
     Emulate3ButtonsSetEnabled(pInfo, FALSE);
