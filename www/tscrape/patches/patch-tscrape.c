$NetBSD: patch-tscrape.c,v 1.1 2020/03/23 15:06:08 leot Exp $

Ignore possible consecutive `js-stream-item' when parsing a single tweet.

Backport from upstream commit:

 426522824e719e081c9c5e47ba8771779b0fdc85

--- tscrape.c.orig	2020-02-23 19:36:28.000000000 +0000
+++ tscrape.c
@@ -159,6 +159,8 @@ xmltagstartparsed(XMLParser *x, const ch
 		state = 0;
 	} else if (!strcmp(t, "li") &&
 	           isclassmatch(classname, STRP("js-stream-item"))) {
+		if (state & Item)
+			return;
 		state |= Item;
 		datatime[0] = text[0] = timestamp[0] = itemfullname[0] = '\0';
 		itemid[0] = itemusername[0] = retweetid[0] = '\0';
