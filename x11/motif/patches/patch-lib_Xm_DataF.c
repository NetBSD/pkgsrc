$NetBSD: patch-lib_Xm_DataF.c,v 1.1 2022/04/05 09:59:56 riastradh Exp $

Fix out-of-bounds array access from off-by-one in backwards iteration.

--- lib/Xm/DataF.c.orig	2017-10-30 20:20:09.000000000 +0000
+++ lib/Xm/DataF.c
@@ -4577,7 +4577,7 @@ _XmDataFieldIsWSpace(
 {
    int i;
 
-   for (i=num_entries; i > 0; i--){
+   for (i=num_entries; i --> 0;){
       if (wide_char == white_space[i]) return True;
    }
    return False;
