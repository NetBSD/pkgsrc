$NetBSD: patch-sway_commands_workspace.c,v 1.1 2026/04/14 11:32:14 kikadf Exp $

* Fix ctype usage

--- sway/commands/workspace.c.orig	2026-02-06 14:28:42.650855570 +0000
+++ sway/commands/workspace.c
@@ -194,7 +194,7 @@ struct cmd_results *cmd_workspace(int ar
 				return cmd_results_new(CMD_INVALID,
 						"Expected workspace number");
 			}
-			if (!isdigit(argv[1][0])) {
+			if (!isdigit((unsigned char)argv[1][0])) {
 				return cmd_results_new(CMD_INVALID,
 						"Invalid workspace number '%s'", argv[1]);
 			}
