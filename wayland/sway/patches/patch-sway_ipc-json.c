$NetBSD: patch-sway_ipc-json.c,v 1.1 2026/04/14 11:32:14 kikadf Exp $

* Fix ctype usage

--- sway/ipc-json.c.orig	2026-02-06 14:36:33.994077551 +0000
+++ sway/ipc-json.c
@@ -494,7 +494,7 @@ static json_object *ipc_json_describe_sc
 static void ipc_json_describe_workspace(struct sway_workspace *workspace,
 		json_object *object) {
 	int num;
-	if (isdigit(workspace->name[0])) {
+	if (isdigit((unsigned char)workspace->name[0])) {
 		errno = 0;
 		char *endptr = NULL;
 		long long parsed_num = strtoll(workspace->name, &endptr, 10);
