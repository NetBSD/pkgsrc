$NetBSD: patch-src_cycle_osd-field.c,v 1.1 2026/07/20 17:42:40 kikadf Exp $

* Fix ctype usage

--- src/cycle/osd-field.c.orig	2026-07-20 14:37:04.467641606 +0000
+++ src/cycle/osd-field.c
@@ -242,7 +242,7 @@ cycle_osd_field_set_custom(struct buf *b
 		 * change (*p >= '0' && *p <= '9') to isdigit(*p)
 		 * changes by droc12345
 		 */
-		if (*p == '-' || isdigit(*p)) {
+		if (*p == '-' || isdigit((unsigned char)*p)) {
 			if (fmt_position >= LAB_FIELD_SINGLE_FMT_MAX_LEN - 2) {
 				/* Leave space for terminating 's' and NULL byte */
 				wlr_log(WLR_ERROR,
