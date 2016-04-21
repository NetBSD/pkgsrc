$NetBSD: patch-pixman_pixman-vmx.c,v 1.1 2016/04/21 21:39:36 he Exp $

Add a fix so that this builds on NetBSD/powerpc.  Otherwise we get
pixman-vmx.c:2936:5: error: subscripted value is neither array nor pointer

--- pixman/pixman-vmx.c.orig	2016-01-04 09:13:54.000000000 +0000
+++ pixman/pixman-vmx.c
@@ -2913,32 +2913,29 @@ scaled_nearest_scanline_vmx_8888_8888_OV
 
     while (w >= 4)
     {
-	vector unsigned int tmp;
-	uint32_t tmp1, tmp2, tmp3, tmp4;
+	union {
+		vector unsigned int tmp;
+		uint32_t tmp1[4];
+	} u;
 
-	tmp1 = *(ps + pixman_fixed_to_int (vx));
+	u.tmp1[0] = *(ps + pixman_fixed_to_int (vx));
 	vx += unit_x;
 	while (vx >= 0)
 	    vx -= src_width_fixed;
-	tmp2 = *(ps + pixman_fixed_to_int (vx));
+	u.tmp1[1] = *(ps + pixman_fixed_to_int (vx));
 	vx += unit_x;
 	while (vx >= 0)
 	    vx -= src_width_fixed;
-	tmp3 = *(ps + pixman_fixed_to_int (vx));
+	u.tmp1[2] = *(ps + pixman_fixed_to_int (vx));
 	vx += unit_x;
 	while (vx >= 0)
 	    vx -= src_width_fixed;
-	tmp4 = *(ps + pixman_fixed_to_int (vx));
+	u.tmp1[3] = *(ps + pixman_fixed_to_int (vx));
 	vx += unit_x;
 	while (vx >= 0)
 	    vx -= src_width_fixed;
 
-	tmp[0] = tmp1;
-	tmp[1] = tmp2;
-	tmp[2] = tmp3;
-	tmp[3] = tmp4;
-
-	vsrc = combine4 ((const uint32_t *) &tmp, pm);
+	vsrc = combine4 ((const uint32_t *) &u.tmp, pm);
 
 	if (is_opaque (vsrc))
 	{
