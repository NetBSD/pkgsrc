$NetBSD: patch-src_bltTree.c,v 1.1 2022/06/06 04:27:14 dholland Exp $

Silence gcc warnings in the interests of being able to see the
real build problems.

--- src/bltTree.c~	2022-06-06 02:53:11.389200304 +0000
+++ src/bltTree.c
@@ -405,7 +405,7 @@ FreeNode(TreeObject *treeObjPtr, Node *n
     TreeDestroyValues(nodePtr);
     UnlinkNode(nodePtr);
     treeObjPtr->nNodes--;
-    hPtr = Blt_FindHashEntry(&treeObjPtr->nodeTable, (char *)nodePtr->inode);
+    hPtr = Blt_FindHashEntry(&treeObjPtr->nodeTable, (char *)(intptr_t)nodePtr->inode);
     assert(hPtr);
     Blt_DeleteHashEntry(&treeObjPtr->nodeTable, hPtr);
     Blt_PoolFreeItem(treeObjPtr->nodePool, (char *)nodePtr);
@@ -838,7 +838,7 @@ Blt_TreeCreateNode(
     /* Generate an unique serial number for this node.  */
     do {
 	inode = treeObjPtr->nextInode++;
-	hPtr = Blt_CreateHashEntry(&treeObjPtr->nodeTable,(char *)inode, 
+	hPtr = Blt_CreateHashEntry(&treeObjPtr->nodeTable,(char *)(intptr_t)inode, 
 		   &isNew);
     } while (!isNew);
     nodePtr = NewNode(treeObjPtr, name, inode);
@@ -893,7 +893,7 @@ Blt_TreeCreateNodeWithId(
     int isNew;
 
     treeObjPtr = parentPtr->treeObject;
-    hPtr = Blt_CreateHashEntry(&treeObjPtr->nodeTable,(char *)inode, &isNew);
+    hPtr = Blt_CreateHashEntry(&treeObjPtr->nodeTable,(char *)(intptr_t)inode, &isNew);
     if (!isNew) {
 	return NULL;
     }
@@ -999,7 +999,7 @@ Blt_TreeGetNode(TreeClient *clientPtr, u
     TreeObject *treeObjPtr = clientPtr->treeObject;
     Blt_HashEntry *hPtr;
 
-    hPtr = Blt_FindHashEntry(&treeObjPtr->nodeTable, (char *)inode);
+    hPtr = Blt_FindHashEntry(&treeObjPtr->nodeTable, (char *)(uintptr_t)inode);
     if (hPtr != NULL) {
 	return (Blt_TreeNode)Blt_GetHashValue(hPtr);
     }
@@ -2433,7 +2433,7 @@ Blt_TreeClearTags(TreeClient *clientPtr,
 	Blt_TreeTagEntry *tPtr;
 
 	tPtr = Blt_GetHashValue(hPtr);
-	h2Ptr = Blt_FindHashEntry(&tPtr->nodeTable, (char *)node);
+	h2Ptr = Blt_FindHashEntry(&tPtr->nodeTable, node);
 	if (h2Ptr != NULL) {
 	    Blt_DeleteHashEntry(&tPtr->nodeTable, h2Ptr);
 	}
@@ -2461,7 +2461,7 @@ Blt_TreeHasTag(
 	return FALSE;
     }
     tPtr = Blt_GetHashValue(hPtr);
-    hPtr = Blt_FindHashEntry(&tPtr->nodeTable, (char *)node);
+    hPtr = Blt_FindHashEntry(&tPtr->nodeTable, node);
     if (hPtr == NULL) {
 	return FALSE;
     }
@@ -2495,7 +2495,7 @@ Blt_TreeAddTag(
     } else {
 	tPtr = Blt_GetHashValue(hPtr);
     }
-    hPtr = Blt_CreateHashEntry(&tPtr->nodeTable, (char *)node, &isNew);
+    hPtr = Blt_CreateHashEntry(&tPtr->nodeTable, node, &isNew);
     assert(hPtr);
     if (isNew) {
 	Blt_SetHashValue(hPtr, node);
