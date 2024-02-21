$NetBSD: patch-src_input.c,v 1.2 2024/02/21 12:55:17 wiz Exp $

Allow building on systems without evdev.
https://github.com/dunst-project/dunst/pull/1288

--- src/input.c.orig	2022-06-27 12:43:39.000000000 +0000
+++ src/input.c
@@ -4,7 +4,14 @@
 #include "settings.h"
 #include "queues.h"
 #include <stddef.h>
+#if defined(__linux__) || defined(__FreeBSD__)
 #include <linux/input-event-codes.h>
+#else
+#define BTN_LEFT	(0x110)
+#define BTN_RIGHT	(0x111)
+#define BTN_MIDDLE	(0x112)
+#define BTN_TOUCH	(0x14a)
+#endif
 
 int get_notification_clickable_height(struct notification *n, bool first, bool last)
 {
