$NetBSD: patch-media_libtheora_lib_arm_armfrag.s,v 1.1 2015/04/28 12:06:34 joerg Exp $

--- media/libtheora/lib/arm/armfrag.s.orig	2015-04-10 13:13:44.000000000 +0000
+++ media/libtheora/lib/arm/armfrag.s
@@ -305,26 +305,26 @@ ofcl_edsp_lp
 	LDR	r5, [r14,r5, LSL #2]	; r5 = _frag_buf_offs[_fragis[fragii]]
 	SUBS	r12, r12, #1
 	; Stall (on XScale)
-	LDRD	r6, [r4, r5]!		; r4 = _src_frame+frag_buf_off
-	LDRD	r8, [r4, r2]!
+	LDRD	r6, r7, [r4, r5]!		; r4 = _src_frame+frag_buf_off
+	LDRD	r8, r9, [r4, r2]!
 	; Stall
-	STRD	r6, [r5, r0]!		; r5 = _dst_frame+frag_buf_off
-	STRD	r8, [r5, r2]!
+	STRD	r6, r7, [r5, r0]!		; r5 = _dst_frame+frag_buf_off
+	STRD	r8, r9, [r5, r2]!
 	; Stall
-	LDRD	r6, [r4, r2]!	; On Xscale at least, doing 3 consecutive
-	LDRD	r8, [r4, r2]!	; loads causes a stall, but that's no worse
-	LDRD	r10,[r4, r2]!	; than us only doing 2, and having to do
+	LDRD	r6, r7, [r4, r2]!	; On Xscale at least, doing 3 consecutive
+	LDRD	r8, r9, [r4, r2]!	; loads causes a stall, but that's no worse
+	LDRD	r10,r11,[r4, r2]!	; than us only doing 2, and having to do
 				; another pair of LDRD/STRD later on.
 	; Stall
-	STRD	r6, [r5, r2]!
-	STRD	r8, [r5, r2]!
-	STRD	r10,[r5, r2]!
-	LDRD	r6, [r4, r2]!
-	LDRD	r8, [r4, r2]!
-	LDRD	r10,[r4, r2]!
-	STRD	r6, [r5, r2]!
-	STRD	r8, [r5, r2]!
-	STRD	r10,[r5, r2]!
+	STRD	r6, r7, [r5, r2]!
+	STRD	r8, r9, [r5, r2]!
+	STRD	r10,r11,[r5, r2]!
+	LDRD	r6, r7, [r4, r2]!
+	LDRD	r8, r9, [r4, r2]!
+	LDRD	r10,r11,[r4, r2]!
+	STRD	r6, r7, [r5, r2]!
+	STRD	r8, r9, [r5, r2]!
+	STRD	r10,r11,[r5, r2]!
 	LDRGE	r5, [r3],#4		; r5 = _fragis[fragii]
 	BGE	ofcl_edsp_lp
 ofcl_edsp_end
@@ -346,8 +346,8 @@ oc_frag_recon_intra_v6 PROC
 	MOV	r12,r2
 	LDR	r6, =0x00800080
 ofrintra_v6_lp
-	LDRD	r2, [r12],#8	; r2 = 11110000 r3 = 33332222
-	LDRD	r4, [r12],#8	; r4 = 55554444 r5 = 77776666
+	LDRD	r2, r3, [r12],#8	; r2 = 11110000 r3 = 33332222
+	LDRD	r4, r5, [r12],#8	; r4 = 55554444 r5 = 77776666
 	SUBS	r14,r14,#1
 	QADD16	r2, r2, r6
 	QADD16	r3, r3, r6
@@ -363,7 +363,7 @@ ofrintra_v6_lp
 	ORR	r5, r5, r5, LSR #8	; r5 = __777766
 	PKHBT   r2, r2, r3, LSL #16     ; r2 = 33221100
 	PKHBT   r3, r4, r5, LSL #16     ; r3 = 77665544
-	STRD	r2, [r0], r1
+	STRD	r2, r3, [r0], r1
 	BGT	ofrintra_v6_lp
 	LDMFD	r13!,{r4-r6,PC}
 	ENDP
@@ -376,10 +376,10 @@ oc_frag_recon_inter_v6 PROC
 	STMFD	r13!,{r4-r7,r14}
 	MOV	r14,#8
 ofrinter_v6_lp
-	LDRD	r6, [r3], #8		; r6 = 11110000 r7 = 33332222
+	LDRD	r6, r7, [r3], #8		; r6 = 11110000 r7 = 33332222
 	SUBS	r14,r14,#1
  [ OC_ARM_CAN_UNALIGN_LDRD
-	LDRD	r4, [r1], r2	; Unaligned ; r4 = 33221100 r5 = 77665544
+	LDRD	r4, r5, [r1], r2	; Unaligned ; r4 = 33221100 r5 = 77665544
  |
 	LDR	r5, [r1, #4]
 	LDR	r4, [r1], r2
@@ -390,7 +390,7 @@ ofrinter_v6_lp
 	UXTB16	r4,r4, ROR #8		; r4 = __33__11
 	QADD16	r12,r12,r6		; r12= xx22xx00
 	QADD16	r4, r7, r4		; r4 = xx33xx11
-	LDRD	r6, [r3], #8		; r6 = 55554444 r7 = 77776666
+	LDRD	r6, r7, [r3], #8		; r6 = 55554444 r7 = 77776666
 	USAT16	r4, #8, r4		; r4 = __33__11
 	USAT16	r12,#8,r12		; r12= __22__00
 	ORR	r4, r12,r4, LSL #8	; r4 = 33221100
@@ -403,7 +403,7 @@ ofrinter_v6_lp
 	USAT16	r12,#8, r12		; r12= __66__44
 	USAT16	r5, #8, r5		; r4 = __77__55
 	ORR	r5, r12,r5, LSL #8	; r5 = 33221100
-	STRD	r4, [r0], r2
+	STRD	r4, r5, [r0], r2
 	BGT	ofrinter_v6_lp
 	LDMFD	r13!,{r4-r7,PC}
 	ENDP
@@ -418,7 +418,7 @@ oc_frag_recon_inter2_v6 PROC
 	STMFD	r13!,{r4-r9,r14}
 	MOV	r14,#8
 ofrinter2_v6_lp
-	LDRD	r6, [r12,#8]	; r6 = 55554444 r7 = 77776666
+	LDRD	r6, r7, [r12,#8]	; r6 = 55554444 r7 = 77776666
 	SUBS	r14,r14,#1
 	LDR	r4, [r1, #4]	; Unaligned	; r4 = src1[1] = 77665544
 	LDR	r5, [r2, #4]	; Unaligned	; r5 = src2[1] = 77665544
@@ -429,7 +429,7 @@ ofrinter2_v6_lp
 	UXTB16	r4, r4, ROR #8		; r4 = __77__55
 	QADD16	r8, r8, r5		; r8 = xx66xx44
 	QADD16	r9, r9, r4		; r9 = xx77xx55
-	LDRD	r6,[r12],#16	; r6 = 33332222 r7 = 11110000
+	LDRD	r6, r7, [r12],#16	; r6 = 33332222 r7 = 11110000
 	USAT16	r8, #8, r8		; r8 = __66__44
 	LDR	r4, [r1], r3	; Unaligned	; r4 = src1[0] = 33221100
 	USAT16	r9, #8, r9		; r9 = __77__55
@@ -445,7 +445,7 @@ ofrinter2_v6_lp
 	USAT16	r8, #8, r8		; r8 = __22__00
 	USAT16	r7, #8, r7		; r7 = __33__11
 	ORR	r8, r8, r7, LSL #8	; r8 = 33221100
-	STRD	r8, [r0], r3
+	STRD	r8, r9, [r0], r3
 	BGT	ofrinter2_v6_lp
 	LDMFD	r13!,{r4-r9,PC}
 	ENDP
