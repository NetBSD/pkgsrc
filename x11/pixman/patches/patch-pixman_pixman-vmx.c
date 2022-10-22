$NetBSD: patch-pixman_pixman-vmx.c,v 1.5 2022/10/22 12:22:01 he Exp $

Add a fix so that this builds without warnings on NetBSD/powerpc.
Also do some simplification.

https://gitlab.freedesktop.org/pixman/pixman/-/merge_requests/64/

--- pixman/pixman-vmx.c.orig	2021-03-01 13:49:17.000000000 +0000
+++ pixman/pixman-vmx.c
@@ -278,21 +278,10 @@ save_128_aligned (uint32_t* data,
     STORE_VECTOR(data)
 }
 
-static force_inline vector unsigned int
-create_mask_1x32_128 (const uint32_t *src)
-{
-    vector unsigned int vsrc;
-    DECLARE_SRC_MASK_VAR;
-
-    COMPUTE_SHIFT_MASK (src);
-    LOAD_VECTOR (src);
-    return vec_splat(vsrc, 0);
-}
-
 static force_inline vector unsigned int
 create_mask_32_128 (uint32_t mask)
 {
-    return create_mask_1x32_128(&mask);
+    return (vector unsigned int) {mask, mask, mask, mask};
 }
 
 static force_inline vector unsigned int
@@ -2471,7 +2460,7 @@ vmx_fill (pixman_implementation_t *imp,
 	return FALSE;
     }
 
-    vfiller = create_mask_1x32_128(&filler);
+    vfiller = create_mask_32_128(filler);
 
     while (height--)
     {
@@ -2913,32 +2902,26 @@ scaled_nearest_scanline_vmx_8888_8888_OVER (uint32_t*       pd,
 
     while (w >= 4)
     {
-	vector unsigned int tmp;
-	uint32_t tmp1, tmp2, tmp3, tmp4;
+	uint32_t tmp[4];
 
-	tmp1 = *(ps + pixman_fixed_to_int (vx));
+	tmp[0] = *(ps + pixman_fixed_to_int (vx));
 	vx += unit_x;
 	while (vx >= 0)
 	    vx -= src_width_fixed;
-	tmp2 = *(ps + pixman_fixed_to_int (vx));
+	tmp[1] = *(ps + pixman_fixed_to_int (vx));
 	vx += unit_x;
 	while (vx >= 0)
 	    vx -= src_width_fixed;
-	tmp3 = *(ps + pixman_fixed_to_int (vx));
+	tmp[2] = *(ps + pixman_fixed_to_int (vx));
 	vx += unit_x;
 	while (vx >= 0)
 	    vx -= src_width_fixed;
-	tmp4 = *(ps + pixman_fixed_to_int (vx));
+	tmp[3] = *(ps + pixman_fixed_to_int (vx));
 	vx += unit_x;
 	while (vx >= 0)
 	    vx -= src_width_fixed;
 
-	tmp[0] = tmp1;
-	tmp[1] = tmp2;
-	tmp[2] = tmp3;
-	tmp[3] = tmp4;
-
-	vsrc = combine4 ((const uint32_t *) &tmp, pm);
+	vsrc = combine4 (tmp, pm);
 
 	if (is_opaque (vsrc))
 	{
