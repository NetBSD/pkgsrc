$NetBSD: patch-src_Screen.cc,v 1.1 2018/10/12 18:00:55 he Exp $

Sunpro has problems with a non-const const_reverse_iterator.

--- src/Screen.cc.orig	2016-07-10 16:31:38.000000000 +0000
+++ src/Screen.cc
@@ -616,8 +616,8 @@ void BScreen::setCurrentWorkspace(unsign
 
     // withdraw windows in reverse order to minimize the number of
     // Expose events
-    StackingList::const_reverse_iterator it = _stackingList.rbegin();
-    const StackingList::const_reverse_iterator end = _stackingList.rend();
+    StackingList::reverse_iterator it = _stackingList.rbegin();
+    const StackingList::reverse_iterator end = _stackingList.rend();
     for (; it != end; ++it) {
       BlackboxWindow *win = dynamic_cast<BlackboxWindow *>(*it);
       if (win && win->workspace() == current_workspace)
