$NetBSD: patch-src_clean.c,v 1.1 2018/10/13 11:14:38 leot Exp $

Backport patch from upstream for CVE-2017-17497, via uptsream commit:

 <https://github.com/htacg/tidy-html5/commit/a111d7a9691953f903ffa1fdbc3762dec22fc215>

Issue #656 - protect against NULL node set in loop

--- src/clean.c.orig	2017-11-25 13:54:41.000000000 +0000
+++ src/clean.c
@@ -2211,8 +2211,10 @@ Bool TY_(TidyMetaCharset)(TidyDocImpl* d
     tidyBufAppend(&charsetString, "charset=", 8);
     tidyBufAppend(&charsetString, (char*)enc, TY_(tmbstrlen)(enc));
     tidyBufAppend(&charsetString, "\0", 1); /* zero terminate the buffer */
-                                            /* process the children of the head */
-    for (currentNode = head->content; currentNode; currentNode = currentNode->next)
+    /* process the children of the head */
+    /* Issue #656 - guard against 'currentNode' being set NULL in loop */
+    for (currentNode = head->content; currentNode; 
+        currentNode = (currentNode ? currentNode->next : NULL))
     {
         if (!nodeIsMETA(currentNode))
             continue;   /* not a meta node */
