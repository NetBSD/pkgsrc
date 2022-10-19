$NetBSD: patch-pixman_pixman-vmx.c,v 1.3 2022/10/19 17:14:32 he Exp $

Add a fix so that this builds on NetBSD/powerpc.  Otherwise we get
pixman-vmx.c:2936:5: error: subscripted value is neither array nor pointer
Also fix something which clearly must be bugs with loading
vector registers from single 32-bit ints.

https://gitlab.freedesktop.org/pixman/pixman/-/merge_requests/64/

--- pixman/pixman-vmx.c.orig	2016-01-04 09:13:54.000000000 +0000
+++ pixman/pixman-vmx.c
@@ -2913,32 +2913,29 @@ scaled_nearest_scanline_vmx_8888_8888_OV
@@ -292,7 +292,9 @@ create_mask_1x32_128 (const uint32_t *sr
 static force_inline vector unsigned int
 create_mask_32_128 (uint32_t mask)
 {
-    return create_mask_1x32_128(&mask);
+    uint32_t nmask[4]; /* vector sized array */
+    nmask[3] = nmask[2] = nmask[1] = nmask[0] = mask;
+    return create_mask_1x32_128(nmask);
 }
 
 static force_inline vector unsigned int
@@ -2435,6 +2437,9 @@ vmx_fill (pixman_implementation_t *imp,
     uint8_t *byte_line;
 
     vector unsigned int vfiller;
+    uint32_t fillers[4];
+
+    fillers[3] = fillers[2] = fillers[1] = fillers[0] = filler;
 
     if (bpp == 8)
     {
@@ -2471,7 +2476,7 @@ vmx_fill (pixman_implementation_t *imp,
 	return FALSE;
     }
 
-    vfiller = create_mask_1x32_128(&filler);
+    vfiller = create_mask_1x32_128(fillers);
 
     while (height--)
     {
@@ -2913,32 +2918,29 @@ scaled_nearest_scanline_vmx_8888_8888_OV
 
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
