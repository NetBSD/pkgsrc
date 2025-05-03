$NetBSD: patch-src_uinput.c,v 1.1 2025/05/03 16:51:15 nia Exp $

Fix building on older Linux systems, e.g. CentOS 7.

--- src/uinput.c.orig	2025-05-03 16:33:30.192475504 +0000
+++ src/uinput.c
@@ -433,7 +433,9 @@ int initialize_uinput(void) {
 	ioctl(fd, UI_SET_RELBIT, REL_X);
 	ioctl(fd, UI_SET_RELBIT, REL_Y);
 	ioctl(fd, UI_SET_RELBIT, REL_WHEEL);
+#ifdef REL_WHEEL_HI_RES
 	ioctl(fd, UI_SET_RELBIT, REL_WHEEL_HI_RES);
+#endif
 
 	ioctl(fd, UI_SET_EVBIT, EV_KEY);
 
@@ -1019,16 +1021,20 @@ static void button_click(int down, int b
 		ev.code = REL_WHEEL;
 		ev.type = EV_REL;
 		ev.value = 1;
+#ifdef REL_WHEEL_HI_RES
 		write(d, &ev, sizeof(ev));
 		ev.code = REL_WHEEL_HI_RES;
 		ev.value = 120;
+#endif
 	} else if (btn == 5) {
 		ev.code = REL_WHEEL;
 		ev.type = EV_REL;
 		ev.value = -1;
+#ifdef REL_WHEEL_HI_RES
 		write(d, &ev, sizeof(ev));
 		ev.code = REL_WHEEL_HI_RES;
 		ev.value = -120;
+#endif
 	} else {
 		return;
 	}
