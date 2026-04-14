$NetBSD: patch-sway_commands_move.c,v 1.1 2026/04/14 11:32:14 kikadf Exp $

* Fix ctype usage

--- sway/commands/move.c.orig	2026-02-06 14:59:39.044165905 +0000
+++ sway/commands/move.c
@@ -472,7 +472,7 @@ static struct cmd_results *cmd_move_cont
 				if (argc < 3) {
 					return cmd_results_new(CMD_INVALID, "%s", expected_syntax);
 				}
-				if (!isdigit(argv[2][0])) {
+				if (!isdigit((unsigned char)argv[2][0])) {
 					return cmd_results_new(CMD_INVALID,
 							"Invalid workspace number '%s'", argv[2]);
 				}
