$NetBSD: patch-src_bltList.c,v 1.1 2022/06/06 04:27:14 dholland Exp $

Make the node type stuff consistent with bltHash to silence compiler warnings.

--- src/bltList.c~	2002-09-18 22:30:51.000000000 +0000
+++ src/bltList.c
@@ -114,7 +114,7 @@ FreeNode(nodePtr)
 /*LINTLIBRARY*/
 Blt_List 
 Blt_ListCreate(type)
-    int type;
+    size_t type;
 {
     struct Blt_ListStruct *listPtr;
 
@@ -250,7 +250,7 @@ Blt_ListDestroy(listPtr)
 void
 Blt_ListInit(listPtr, type)
     struct Blt_ListStruct *listPtr;
-    int type;
+    size_t type;
 {
     listPtr->nNodes = 0;
     listPtr->headPtr = listPtr->tailPtr = NULL;
