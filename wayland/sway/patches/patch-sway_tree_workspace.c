$NetBSD: patch-sway_tree_workspace.c,v 1.1 2026/04/14 11:32:15 kikadf Exp $

* Fix ctype usage

--- sway/tree/workspace.c.orig	2026-02-06 15:19:36.101349296 +0000
+++ sway/tree/workspace.c
@@ -256,7 +256,7 @@ static void workspace_name_from_binding(
 			sway_log(SWAY_DEBUG, "Isolated name from workspace number: '%s'", _target);
 
 			// Make sure the workspace number doesn't already exist
-			if (isdigit(_target[0]) && workspace_by_number(_target)) {
+			if (isdigit((unsigned char)_target[0]) && workspace_by_number(_target)) {
 				free(_target);
 				free(dup);
 				return;
@@ -346,12 +346,12 @@ char *workspace_next_name(const char *ou
 static bool _workspace_by_number(struct sway_workspace *ws, void *data) {
 	char *name = data;
 	char *ws_name = ws->name;
-	while (isdigit(*name)) {
+	while (isdigit((unsigned char)*name)) {
 		if (*name++ != *ws_name++) {
 			return false;
 		}
 	}
-	return !isdigit(*ws_name);
+	return !isdigit((unsigned char)*ws_name);
 }
 
 struct sway_workspace *workspace_by_number(const char* name) {
