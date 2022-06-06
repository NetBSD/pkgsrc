$NetBSD: patch-src_bltTreeCmd.c,v 1.1 2022/06/06 04:27:14 dholland Exp $

Silence gcc warnings in the interests of being able to see the
real build problems.

Fix ctype misuse.

--- src/bltTreeCmd.c~	2002-09-27 22:23:01.000000000 +0000
+++ src/bltTreeCmd.c
@@ -1283,7 +1283,7 @@ ParseNode5(TreeCmd *cmdPtr, char **argv,
     if (parentId == -1) {	/* Dump marks root's parent as -1. */
 	node = dataPtr->root;
 	/* Create a mapping between the old id and the new node */
-	hPtr = Blt_CreateHashEntry(&dataPtr->idTable, (char *)nodeId, 
+	hPtr = Blt_CreateHashEntry(&dataPtr->idTable, (char *)(intptr_t)nodeId,
 		   &isNew);
 	Blt_SetHashValue(hPtr, node);
 	Blt_TreeRelabelNode(cmdPtr->tree, node, names[0]);
@@ -1293,7 +1293,7 @@ ParseNode5(TreeCmd *cmdPtr, char **argv,
 	 * This can happen when there's a id collision with an
 	 * existing node. 
 	 */
-	hPtr = Blt_FindHashEntry(&dataPtr->idTable, (char *)parentId);
+	hPtr = Blt_FindHashEntry(&dataPtr->idTable, (char *)(intptr_t)parentId);
 	if (hPtr != NULL) {
 	    parent = Blt_GetHashValue(hPtr);
 	} else {
@@ -1330,7 +1330,7 @@ ParseNode5(TreeCmd *cmdPtr, char **argv,
 	if (dataPtr->flags & RESTORE_OVERWRITE) {
 	    node = Blt_TreeFindChild(parent, names[nNames - 1]);
 	    /* Create a mapping between the old id and the new node */
-	    hPtr = Blt_CreateHashEntry(&dataPtr->idTable, (char *)nodeId, 
+	    hPtr = Blt_CreateHashEntry(&dataPtr->idTable, (char *)(intptr_t)nodeId, 
 				       &isNew);
 	    Blt_SetHashValue(hPtr, node);
 	}
@@ -1340,7 +1340,7 @@ ParseNode5(TreeCmd *cmdPtr, char **argv,
 		node = Blt_TreeCreateNode(cmdPtr->tree, parent, 
 					  names[nNames - 1], -1);
 		/* Create a mapping between the old id and the new node */
-		hPtr = Blt_CreateHashEntry(&dataPtr->idTable, (char *)nodeId,
+		hPtr = Blt_CreateHashEntry(&dataPtr->idTable, (char *)(intptr_t)nodeId,
 					   &isNew);
 		Blt_SetHashValue(hPtr, node);
 	    } else {
@@ -1570,7 +1570,7 @@ GetTraceFlags(char *string)
 
     flags = 0;
     for (p = string; *p != '\0'; p++) {
-	switch (toupper(*p)) {
+	switch (toupper((unsigned char)*p)) {
 	case 'R':
 	    flags |= TREE_TRACE_READ;
 	    break;
