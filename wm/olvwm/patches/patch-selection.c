$NetBSD: patch-selection.c,v 1.1 2013/03/28 21:40:11 joerg Exp $

--- selection.c.orig	2013-03-28 19:18:31.000000000 +0000
+++ selection.c
@@ -299,10 +299,8 @@ IsSelected(cli)
  * Add this client to the list of clients on the PRIMARY selection and mark
  * the client as being selected.  Acquires the PRIMARY selection if necessary.
  */
-int
-AddSelection(cli, timestamp)
-	Client *cli;
-	Time timestamp;
+void
+AddSelection(Client *cli, Time timestamp)
 {
 	List *l = selectList;
 	Client *tc;
