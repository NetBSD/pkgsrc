$NetBSD: patch-src_jstk.c,v 1.1 2016/11/16 22:57:33 wiz Exp $

Fix build with xorg-server-1.19, from upstream git
60d0e9c451b3f259d524b0ddcc5c1f21a4f82293

--- src/jstk.c.orig	2012-10-03 17:17:26.000000000 +0000
+++ src/jstk.c
@@ -34,6 +34,7 @@
 #include <xf86Xinput.h>
 #include <exevents.h>		/* Needed for InitValuator/Proximity stuff */
 #include <xf86Opt.h>
+#include <xf86_OSproc.h>
 
 #include <math.h>
 #include <xf86Module.h>
@@ -79,6 +80,9 @@ jstkOpenDevice(JoystickDevPtr priv, BOOL
     int fd;
     fd = -1;
 
+    if (priv->joystick_device->flags & XI86_SERVER_FD)
+        priv->fd = priv->joystick_device->fd;
+
     if (probe == FALSE && priv->open_proc)
         return priv->open_proc(priv, probe);
 
@@ -98,6 +102,24 @@ jstkOpenDevice(JoystickDevPtr priv, BOOL
     return fd;
 }
 
+/*
+ ***************************************************************************
+ *
+ * jstkCloseDevice --
+ *
+ * Called to close the device specified in priv, this is a helper for
+ * backend proc_close functions
+ *
+ ***************************************************************************
+ */
+void jstkCloseDevice(JoystickDevPtr priv)
+{
+    if ((priv->fd >= 0)) {
+      if (!(priv->joystick_device->flags & XI86_SERVER_FD))
+          xf86CloseSerial(priv->fd);
+      priv->fd = -1;
+    }
+}
 
 /*
  ***************************************************************************
@@ -125,7 +147,7 @@ jstkReadProc(InputInfoPtr pInfo)
             xf86Msg(X_WARNING, "JOYSTICK: Read failed. Deactivating device.\n");
 
             if (pInfo->fd >= 0)
-                RemoveEnabledDevice(pInfo->fd);
+                xf86RemoveEnabledDevice(pInfo);
             return;
         }
 
@@ -392,7 +414,7 @@ jstkDeviceControlProc(DeviceIntPtr      
         if (jstkOpenDevice(priv, FALSE) != -1) {
             pJstk->public.on = TRUE;
             pInfo->fd = priv->fd;
-            AddEnabledDevice(pInfo->fd);
+            xf86AddEnabledDevice(pInfo);
         } else return !Success;
         break;
 
@@ -415,13 +437,19 @@ jstkDeviceControlProc(DeviceIntPtr      
         }
 
         if (pInfo->fd >= 0)
-            RemoveEnabledDevice(pInfo->fd);
-        pInfo->fd = -1;
+            xf86RemoveEnabledDevice(pInfo);
+        if (!(pInfo->flags & XI86_SERVER_FD))
+            pInfo->fd = -1;
         if (priv->close_proc)
             priv->close_proc(priv);
         pJstk->public.on = FALSE;
         break;
 
+#if GET_ABI_MAJOR(ABI_XINPUT_VERSION) * 100 + GET_ABI_MINOR(ABI_XINPUT_VERSION) >= 1901
+    case DEVICE_ABORT:
+        break;
+#endif
+
     default:
         ErrorF("unsupported mode=%d\n", what);
         return BadValue;
@@ -462,7 +490,8 @@ jstkCorePreInit(InputDriverPtr drv, Inpu
     pInfo->read_input = jstkReadProc;
     pInfo->control_proc = NULL;
     pInfo->switch_mode = NULL;
-    pInfo->fd = -1;
+    if (!(pInfo->flags & XI86_SERVER_FD))
+        pInfo->fd = -1;
     pInfo->dev = NULL;
     pInfo->type_name = XI_JOYSTICK;
 
@@ -483,6 +512,7 @@ jstkCorePreInit(InputDriverPtr drv, Inpu
     priv->mouse_enabled = TRUE;
     priv->keys_enabled = TRUE;
     priv->amplify = 1.0f;
+    priv->joystick_device = pInfo;
     priv->keyboard_device = keyboard_device;
     priv->num_axes    = MAXAXES;
     priv->num_buttons = MAXBUTTONS;
@@ -659,7 +689,11 @@ _X_EXPORT InputDriverRec JOYSTICK = {
     NULL,
     jstkCorePreInit,
     jstkCoreUnInit,
-    NULL
+    NULL,
+    NULL,
+#ifdef XI86_DRV_CAP_SERVER_FD
+    XI86_DRV_CAP_SERVER_FD
+#endif
 };
 
 /*
@@ -738,4 +772,3 @@ _X_EXPORT XF86ModuleData joystickModuleD
 };
 
 /* vim: set filetype=c.doxygen ts=4 et: */
-
