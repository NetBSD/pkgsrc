$NetBSD: patch-glx_indirect__util.c,v 1.1 2015/04/03 09:46:18 tnn Exp $

X.Org Security Advisory:  Dec. 9, 2014
Protocol handling issues in X Window System servers

--- glx/indirect_util.c.orig	2012-05-17 17:09:02.000000000 +0000
+++ glx/indirect_util.c
@@ -78,7 +78,7 @@ __glXGetAnswerBuffer(__GLXclientState * 
                      void *local_buffer, size_t local_size, unsigned alignment)
 {
     void *buffer = local_buffer;
-    const unsigned mask = alignment - 1;
+    const intptr_t mask = alignment - 1;
 
     if (local_size < required_size) {
         const size_t worst_case_size = required_size + alignment;
