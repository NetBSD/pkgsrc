$NetBSD: patch-sway_tree_output.c,v 1.1 2026/04/14 11:32:14 kikadf Exp $

* Fix ctype usage

--- sway/tree/output.c.orig	2026-02-06 15:15:06.294449317 +0000
+++ sway/tree/output.c
@@ -381,13 +381,13 @@ static int sort_workspace_cmp_qsort(cons
 	struct sway_workspace *a = *(void **)_a;
 	struct sway_workspace *b = *(void **)_b;
 
-	if (isdigit(a->name[0]) && isdigit(b->name[0])) {
+	if (isdigit((unsigned char)a->name[0]) && isdigit((unsigned char)b->name[0])) {
 		int a_num = strtol(a->name, NULL, 10);
 		int b_num = strtol(b->name, NULL, 10);
 		return (a_num < b_num) ? -1 : (a_num > b_num);
-	} else if (isdigit(a->name[0])) {
+	} else if (isdigit((unsigned char)a->name[0])) {
 		return -1;
-	} else if (isdigit(b->name[0])) {
+	} else if (isdigit((unsigned char)b->name[0])) {
 		return 1;
 	}
 	return 0;
