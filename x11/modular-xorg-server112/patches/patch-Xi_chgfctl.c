$NetBSD: patch-Xi_chgfctl.c,v 1.1 2015/04/03 09:46:18 tnn Exp $

X.Org Security Advisory:  Dec. 9, 2014
Protocol handling issues in X Window System servers

--- Xi/chgfctl.c.orig	2012-05-17 17:09:01.000000000 +0000
+++ Xi/chgfctl.c
@@ -467,6 +467,8 @@ ProcXChangeFeedbackControl(ClientPtr cli
         xStringFeedbackCtl *f = ((xStringFeedbackCtl *) &stuff[1]);
 
         if (client->swapped) {
+            if (len < bytes_to_int32(sizeof(xStringFeedbackCtl)))
+                return BadLength;
             swaps(&f->num_keysyms);
         }
         if (len !=
