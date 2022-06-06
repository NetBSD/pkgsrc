$NetBSD: patch-src_bltArrayObj.c,v 1.1 2022/06/06 04:27:14 dholland Exp $

Silence const warning.

--- src/bltArrayObj.c~	2002-07-12 18:38:47.000000000 +0000
+++ src/bltArrayObj.c
@@ -54,7 +54,7 @@ SetArrayFromAny(interp, objPtr)
     Blt_HashEntry *hPtr;
     Blt_HashTable *tablePtr;
     Tcl_Obj *elemObjPtr;
-    Tcl_ObjType *oldTypePtr = objPtr->typePtr;
+    const Tcl_ObjType *oldTypePtr = objPtr->typePtr;
     char **elemArr;
     char *string;
     int isNew;
