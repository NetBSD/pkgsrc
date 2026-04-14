$NetBSD: patch-sway_commands_rename.c,v 1.1 2026/04/14 11:32:14 kikadf Exp $

* Fix ctype usage

--- sway/commands/rename.c.orig	2026-02-06 15:17:20.504788687 +0000
+++ sway/commands/rename.c
@@ -37,7 +37,7 @@ struct cmd_results *cmd_rename(int argc,
 		workspace = config->handler_context.workspace;
 	} else if (strcasecmp(argv[1], "number") == 0) {
 		// 'rename workspace number x to new_name'
-		if (!isdigit(argv[2][0])) {
+		if (!isdigit((unsigned char)argv[2][0])) {
 			return cmd_results_new(CMD_INVALID,
 					"Invalid workspace number '%s'", argv[2]);
 		}
