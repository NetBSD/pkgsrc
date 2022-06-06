$NetBSD: patch-src_bltList.h,v 1.1 2022/06/06 04:27:14 dholland Exp $

Make the node type stuff consistent with bltHash to silence compiler warnings.

--- src/bltList.h~	2002-09-18 22:30:51.000000000 +0000
+++ src/bltList.h
@@ -57,12 +57,12 @@ struct Blt_ListStruct {
     struct Blt_ListNodeStruct *headPtr;	/* Pointer to first element in list */
     struct Blt_ListNodeStruct *tailPtr;	/* Pointer to last element in list */
     int nNodes;			/* Number of node currently in the list. */
-    int type;			/* Type of keys in list. */
+    size_t type;		/* Type of keys in list. */
 };
 
-EXTERN void Blt_ListInit _ANSI_ARGS_((Blt_List list, int type));
+EXTERN void Blt_ListInit _ANSI_ARGS_((Blt_List list, size_t type));
 EXTERN void Blt_ListReset _ANSI_ARGS_((Blt_List list));
-EXTERN Blt_List Blt_ListCreate _ANSI_ARGS_((int type));
+EXTERN Blt_List Blt_ListCreate _ANSI_ARGS_((size_t type));
 EXTERN void Blt_ListDestroy _ANSI_ARGS_((Blt_List list));
 EXTERN Blt_ListNode Blt_ListCreateNode _ANSI_ARGS_((Blt_List list, 
 	CONST char *key));
