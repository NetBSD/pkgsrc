$NetBSD: patch-src_bltTable.c,v 1.1 2022/06/06 04:27:14 dholland Exp $

Fix ctype abuse.

--- src/bltTable.c~	2002-10-14 23:31:24.000000000 +0000
+++ src/bltTable.c
@@ -1382,7 +1382,7 @@ ParseRowColumn2(tablePtr, string, number
     int n;
     PartitionInfo *infoPtr;
 
-    c = tolower(string[0]);
+    c = tolower((unsigned char)string[0]);
     if (c == 'c') {
 	infoPtr = &(tablePtr->columnInfo);
     } else if (c == 'r') {
@@ -2363,7 +2363,7 @@ ParseItem(tablePtr, string, rowPtr, colu
     char c;
     long partNum;
 
-    c = tolower(string[0]);
+    c = tolower((unsigned char)string[0]);
     *rowPtr = *columnPtr = -1;
     if (c == 'r') {
 	if (Tcl_ExprLong(tablePtr->interp, string + 1, &partNum) != TCL_OK) {
@@ -3827,7 +3827,7 @@ DeleteOp(dataPtr, interp, argc, argv)
 	return TCL_ERROR;
     }
     for (i = 3; i < argc; i++) {
-	c = tolower(argv[i][0]);
+	c = tolower((unsigned char)argv[i][0]);
 	if ((c != 'r') && (c != 'c')) {
 	    Tcl_AppendResult(interp, "bad index \"", argv[i],
 		"\": must start with \"r\" or \"c\"", (char *)NULL);
@@ -3836,7 +3836,7 @@ DeleteOp(dataPtr, interp, argc, argv)
     }
     matches = 0;
     for (i = 3; i < argc; i++) {
-	c = tolower(argv[i][0]);
+	c = tolower((unsigned char)argv[i][0]);
 	infoPtr = (c == 'r') ? &(tablePtr->rowInfo) : &(tablePtr->columnInfo);
 	for (linkPtr = Blt_ChainFirstLink(infoPtr->chainPtr); linkPtr != NULL;
 	    linkPtr = nextPtr) {
@@ -4022,7 +4022,7 @@ ExtentsOp(dataPtr, interp, argc, argv)
     if (Blt_GetTable(dataPtr, interp, argv[2], &tablePtr) != TCL_OK) {
 	return TCL_ERROR;
     }
-    c = tolower(argv[3][0]);
+    c = tolower((unsigned char)argv[3][0]);
     if (c == 'r') {
 	infoPtr = &(tablePtr->rowInfo);
     } else if (c == 'c') {
