$NetBSD: patch-lib_libxview_rect_rectlist.c,v 1.1 2012/11/16 00:29:40 joerg Exp $

--- lib/libxview/rect/rectlist.c.orig	2012-11-14 15:15:07.000000000 +0000
+++ lib/libxview/rect/rectlist.c
@@ -39,6 +39,9 @@ extern struct rectlist rl_null;
 struct rectnode *_rl_getrectnode(), **_rl_removerectnode();
 unsigned        rl_boundintersectsrect();
 
+void _rl_appendrect(struct rect *r, struct rectlist *rl);
+void _rl_removerect(struct rect *r, struct rectlist *rl);
+
 /*
  * rectlist geometry functions
  */
@@ -85,7 +88,7 @@ rl_intersection(rl1, rl2, rl)
     *rl = rlresult;
 }
 
-rl_sort(rl1, rl, sortorder)
+void rl_sort(rl1, rl, sortorder)
     register struct rectlist *rl1, *rl;
     int             sortorder;
 {
@@ -130,7 +133,7 @@ rl_sort(rl1, rl, sortorder)
     *rl = rlresult;
 }
 
-rl_union(rl1, rl2, rl)
+void rl_union(rl1, rl2, rl)
     register struct rectlist *rl1, *rl2, *rl;
 {
     if (rl1 == rl)
@@ -143,7 +146,7 @@ rl_union(rl1, rl2, rl)
     }
 }
 
-rl_difference(rl1, rl2, rl)
+void rl_difference(rl1, rl2, rl)
     register struct rectlist *rl1, *rl2, *rl;
 {
     struct rect     r;
@@ -245,7 +248,7 @@ rl_rectintersects(r, rl)
     return (FALSE);
 }
 
-rl_rectintersection(r, rl1, rl)
+void rl_rectintersection(r, rl1, rl)
     register struct rect *r;
     register struct rectlist *rl1, *rl;
 {
@@ -265,7 +268,7 @@ rl_rectintersection(r, rl1, rl)
     *rl = rlresult;
 }
 
-rl_rectunion(r, rl1, rl)
+void rl_rectunion(r, rl1, rl)
     register struct rect *r;
     register struct rectlist *rl1, *rl;
 {
@@ -284,7 +287,7 @@ rl_rectunion(r, rl1, rl)
     _rl_append(rl, &rlresult);
 }
 
-rl_rectdifference(r, rl1, rl)
+void rl_rectdifference(r, rl1, rl)
     register struct rect *r;
     register struct rectlist *rl1, *rl;
 {
@@ -316,7 +319,7 @@ rl_rectdifference(r, rl1, rl)
  * rectlist initialization functions
  */
 
-rl_initwithrect(r, rl)
+void rl_initwithrect(r, rl)
     register struct rect *r;
     struct rectlist *rl;
 {
@@ -328,7 +331,7 @@ rl_initwithrect(r, rl)
 /*
  * rectlist List Memory Management functions
  */
-rl_copy(rl1, rl)
+void rl_copy(rl1, rl)
     register struct rectlist *rl1, *rl;
 {
     register struct rectnode *rn;
@@ -343,8 +346,7 @@ rl_copy(rl1, rl)
     }
 }
 
-rl_free(rl)
-    register struct rectlist *rl;
+void rl_free(struct rectlist *rl)
 {
     register struct rectnode *rn, *rn_next, *rn_last = (struct rectnode *) 0;
 
@@ -362,7 +364,7 @@ rl_free(rl)
     *rl = rl_null;
 }
 
-rl_coalesce(rl)
+void rl_coalesce(rl)
     register struct rectlist *rl;
 {
     struct rectnode *rn;
@@ -390,7 +392,7 @@ rl_coalesce(rl)
     }
 }
 
-rl_normalize(rl)
+void rl_normalize(rl)
     register struct rectlist *rl;
 {
     struct rectnode *rn;
@@ -407,7 +409,7 @@ rl_normalize(rl)
 
 /* Debug Utilities	 */
 
-rl_print(rl, tag)
+void rl_print(rl, tag)
     struct rectlist *rl;
     char           *tag;
 {
@@ -432,7 +434,7 @@ rl_print(rl, tag)
 /*
  * Create node for r and app to rl
  */
-_rl_appendrect(r, rl)
+void _rl_appendrect(r, rl)
     register struct rect *r;
     register struct rectlist *rl;
 {
@@ -579,7 +581,7 @@ _rl_freerectnode(rn)
     rnFree = rn;
 }
 
-_rl_removerect(r, rl)
+void _rl_removerect(r, rl)
     register struct rect *r;
     register struct rectlist *rl;
 {
