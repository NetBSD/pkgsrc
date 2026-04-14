$NetBSD: patch-sway_input_input-manager.c,v 1.1 2026/04/14 11:32:14 kikadf Exp $

* Fix ctype usage

--- sway/input/input-manager.c.orig	2026-02-06 14:46:35.813870635 +0000
+++ sway/input/input-manager.c
@@ -81,7 +81,7 @@ char *input_device_get_identifier(struct
 	char *p = name;
 	for (; *p; ++p) {
 		// There are in fact input devices with unprintable characters in its name
-		if (*p == ' ' || !isprint(*p)) {
+		if (*p == ' ' || !isprint((unsigned char)*p)) {
 			*p = '_';
 		}
 	}
