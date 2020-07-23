$NetBSD: patch-frankenwm.c,v 1.1 2020/07/23 19:53:51 pin Exp $

Move include into a reasonable place.
Don't re-define things that are already in Xlib.h

--- frankenwm.c.orig	2020-05-21 08:59:23.000000000 +0000
+++ frankenwm.c
@@ -10,6 +10,7 @@
 #include <signal.h>
 #include <regex.h>
 #include <sys/wait.h>
+#include <X11/Xlib.h>
 #include <X11/keysym.h>
 #include <xcb/xcb.h>
 #include <xcb/xcb_atom.h>
@@ -27,16 +28,6 @@
 #  define DEBUGP(x, ...);
 #endif
 
-/* upstream compatility */
-#define True  true
-#define False false
-#define Mod1Mask     XCB_MOD_MASK_1
-#define Mod4Mask     XCB_MOD_MASK_4
-#define ShiftMask    XCB_MOD_MASK_SHIFT
-#define ControlMask  XCB_MOD_MASK_CONTROL
-#define Button1      XCB_BUTTON_INDEX_1
-#define Button2      XCB_BUTTON_INDEX_2
-#define Button3      XCB_BUTTON_INDEX_3
 #define XCB_MOVE_RESIZE XCB_CONFIG_WINDOW_X | XCB_CONFIG_WINDOW_Y | XCB_CONFIG_WINDOW_WIDTH | XCB_CONFIG_WINDOW_HEIGHT
 #define XCB_MOVE        XCB_CONFIG_WINDOW_X | XCB_CONFIG_WINDOW_Y
 #define XCB_RESIZE      XCB_CONFIG_WINDOW_WIDTH | XCB_CONFIG_WINDOW_HEIGHT
@@ -3582,7 +3573,6 @@ void xerror(xcb_generic_event_t *e)
 
 static void ungrab_focus(void)
 {
-#include <X11/Xlib.h>
     Display * dpy;
 
 
