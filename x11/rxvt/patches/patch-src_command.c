$NetBSD: patch-src_command.c,v 1.3 2025/10/20 18:32:10 vins Exp $

* Fix CVE-2021-33477.
* Fix CVE-2017-7483.
* Prefer safer vsnprtinf().
* Replace deprecated XKeycodeToKeysym.

--- src/command.c.orig	2003-03-26 06:01:23.000000000 +0000
+++ src/command.c
@@ -45,6 +45,7 @@
 
 /*{{{ includes: */
 #include "../config.h"		/* NECESSARY */
+#include <X11/XKBlib.h>	/* XKB */
 #include "rxvt.h"		/* NECESSARY */
 #include "version.h"
 #include "command.h"
@@ -961,8 +962,9 @@ rxvt_process_x_event(rxvt_t *r, XEvent *
 		h->mouse_slip_wheel_speed = 0;
 	    else {
 		KeySym          ks;
-		
-		ks = XKeycodeToKeysym(r->Xdisplay, ev->xkey.keycode, 0);
+
+		ks = XkbKeycodeToKeysym(r->Xdisplay, ev->xkey.keycode,
+			0, ev->xkey.state & ControlMask ? 1 : 0);
 		if (ks == XK_Control_L || ks == XK_Control_R)
 		    h->mouse_slip_wheel_speed = 0;
 	    }
@@ -1954,10 +1956,12 @@ rxvt_process_escape_seq(rxvt_t *r)
 	rxvt_scr_add_lines(r, (const unsigned char *)"\n\r", 1, 2);
 	break;
 
+#if 0 /* disabled because embedded newlines can make exploits easier */
     /* kidnapped escape sequence: Should be 8.3.48 */
     case C1_ESA:		/* ESC G */
 	rxvt_process_graphics(r);
 	break;
+#endif
 
     /* 8.3.63: CHARACTER TABULATION SET */
     case C1_HTS:		/* ESC H */
@@ -2096,7 +2100,7 @@ rxvt_process_csi_seq(rxvt_t *r)
     i = ch - CSI_ICH;
     ndef = get_byte_array_bit(csi_defaults, i);
     for (p = 0; p < nargs; p++)
-	if (arg[p] == -1)
+	if (arg[p] < 0 || arg[p] > 30000)
 	    arg[p] = ndef;
 
 #ifdef DEBUG_CMD
@@ -3098,7 +3102,7 @@ rxvt_tt_printf(rxvt_t *r, const char *fm
     unsigned char   buf[256];
 
     va_start(arg_ptr, fmt);
-    vsprintf((char *)buf, fmt, arg_ptr);
+    vsnprintf((char *)buf, sizeof(buf), fmt, arg_ptr);
     va_end(arg_ptr);
     rxvt_tt_write(r, buf, (unsigned int)STRLEN(buf));
 }
