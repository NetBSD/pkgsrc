$NetBSD: patch-swaybar_i3bar.c,v 1.1 2026/04/14 11:32:15 kikadf Exp $

* Fix ctype usage

--- swaybar/i3bar.c.orig	2026-02-06 15:09:17.576197045 +0000
+++ swaybar/i3bar.c
@@ -126,7 +126,7 @@ bool i3bar_handle_readable(struct status
 				status->buffer_index -= ++c;
 				memmove(status->buffer, &status->buffer[c], status->buffer_index);
 				break;
-			} else if (!isspace(status->buffer[c])) {
+			} else if (!isspace((unsigned char)status->buffer[c])) {
 				sway_log(SWAY_DEBUG, "Invalid i3bar json: expected '[' but encountered '%c'",
 						status->buffer[c]);
 				status_error(status, "[invalid i3bar json]");
@@ -166,7 +166,7 @@ bool i3bar_handle_readable(struct status
 					status->expecting_comma = false;
 					++buffer_pos;
 					break;
-				} else if (!isspace(status->buffer[buffer_pos])) {
+				} else if (!isspace((unsigned char)status->buffer[buffer_pos])) {
 					sway_log(SWAY_DEBUG, "Invalid i3bar json: expected ',' but encountered '%c'",
 							status->buffer[buffer_pos]);
 					status_error(status, "[invalid i3bar json]");
@@ -197,7 +197,7 @@ bool i3bar_handle_readable(struct status
 				char *last_char_pos =
 					&status->buffer[buffer_pos + status->tokener->char_offset - 1];
 				char last_char = *last_char_pos;
-				while (isspace(last_char)) {
+				while (isspace((unsigned char)last_char)) {
 					last_char = *--last_char_pos;
 				}
 				*last_char_pos = '\0';
