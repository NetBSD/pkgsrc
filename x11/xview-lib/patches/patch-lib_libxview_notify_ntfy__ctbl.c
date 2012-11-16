$NetBSD: patch-lib_libxview_notify_ntfy__ctbl.c,v 1.1 2012/11/16 00:29:40 joerg Exp $

--- lib/libxview/notify/ntfy_ctbl.c.orig	2012-11-14 14:18:33.000000000 +0000
+++ lib/libxview/notify/ntfy_ctbl.c
@@ -15,7 +15,7 @@ NTFY_CNDTBL *ntfy_cndtbl[NTFY_LAST_CND];
  * has an interest in.
  */
 
-ntfy_add_to_table(client, condition, type)
+void ntfy_add_to_table(client, condition, type)
     NTFY_CLIENT    *client;
     NTFY_CONDITION *condition;
     int             type;
@@ -70,6 +70,7 @@ ntfy_add_to_table(client, condition, typ
  * table.
  */
 
+void
 ntfy_remove_from_table(client, condition)
     NTFY_CLIENT    *client;
     NTFY_CONDITION *condition;
