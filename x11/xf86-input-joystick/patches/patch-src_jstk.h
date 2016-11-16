$NetBSD: patch-src_jstk.h,v 1.1 2016/11/16 22:57:33 wiz Exp $

Fix build with xorg-server-1.19, from upstream git
60d0e9c451b3f259d524b0ddcc5c1f21a4f82293

--- src/jstk.h.orig	2012-10-06 14:00:57.000000000 +0000
+++ src/jstk.h
@@ -55,6 +55,9 @@
 #define XI_JOYSTICK "JOYSTICK"
 #endif
 
+#ifndef XI86_SERVER_FD
+#define XI86_SERVER_FD 0x20
+#endif
 
 typedef enum _JOYSTICKEVENT {
     EVENT_NONE=0,
@@ -106,6 +109,7 @@ typedef struct _JoystickDevRec {
     jstkReadDataProc read_proc; /* Callback for reading data from the backend */
     void         *devicedata; /* Extra platform device dependend data */
     char         *device;     /* Name of the device */
+    InputInfoPtr joystick_device; /* Back pointer to the joystick device */
     InputInfoPtr keyboard_device; /* Slave device for keyboard events */
 
     OsTimerPtr   timer;       /* Timer for axis movement */
@@ -123,4 +127,6 @@ typedef struct _JoystickDevRec {
     BUTTON button[MAXBUTTONS];    /* Configuration per button */
 } JoystickDevRec;
 
+void jstkCloseDevice(JoystickDevPtr priv);
+
 #endif
