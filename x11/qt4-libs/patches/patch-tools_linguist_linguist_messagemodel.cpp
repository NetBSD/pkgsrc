$NetBSD: patch-tools_linguist_linguist_messagemodel.cpp,v 1.1 2016/12/16 00:06:46 joerg Exp $

Don't order pointers relative to 0.

--- tools/linguist/linguist/messagemodel.cpp.orig	2016-12-13 21:07:03.441711305 +0000
+++ tools/linguist/linguist/messagemodel.cpp
@@ -183,7 +183,7 @@ static int calcMergeScore(const DataMode
         if (ContextItem *c = one->findContext(oc->context())) {
             for (int j = 0; j < oc->messageCount(); ++j) {
                 MessageItem *m = oc->messageItem(j);
-                if (c->findMessage(m->text(), m->comment()) >= 0)
+                if (c->findMessage(m->text(), m->comment()))
                     ++inBoth;
             }
         }
