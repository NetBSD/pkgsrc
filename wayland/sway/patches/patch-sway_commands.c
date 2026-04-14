$NetBSD: patch-sway_commands.c,v 1.1 2026/04/14 11:32:14 kikadf Exp $

* Fix ctype usage

--- sway/commands.c.orig	2026-02-06 14:32:11.294383795 +0000
+++ sway/commands.c
@@ -228,7 +228,7 @@ list_t *execute_command(char *_exec, str
 	config->handler_context.seat = seat;
 
 	do {
-		for (; isspace(*head); ++head) {}
+		for (; isspace((unsigned char)*head); ++head) {}
 		// Extract criteria (valid for this command list only).
 		if (matched_delim == ';') {
 			using_criteria = false;
@@ -247,12 +247,12 @@ list_t *execute_command(char *_exec, str
 				criteria_destroy(criteria);
 				using_criteria = true;
 				// Skip leading whitespace
-				for (; isspace(*head); ++head) {}
+				for (; isspace((unsigned char)*head); ++head) {}
 			}
 		}
 		// Split command list
 		cmd = argsep(&head, ";,", &matched_delim);
-		for (; isspace(*cmd); ++cmd) {}
+		for (; isspace((unsigned char)*cmd); ++cmd) {}
 
 		if (strcmp(cmd, "") == 0) {
 			sway_log(SWAY_INFO, "Ignoring empty command.");
