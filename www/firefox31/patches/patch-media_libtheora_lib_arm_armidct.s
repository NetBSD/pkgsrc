$NetBSD: patch-media_libtheora_lib_arm_armidct.s,v 1.1 2015/04/28 12:06:34 joerg Exp $

--- media/libtheora/lib/arm/armidct.s.orig	2015-04-10 13:12:08.000000000 +0000
+++ media/libtheora/lib/arm/armidct.s
@@ -765,22 +765,22 @@ oc_idct8x8_1_v6 PROC
 	; r1 = ogg_uint16_t  _dc
 	ORR	r2, r1, r1, LSL #16
 	ORR	r3, r1, r1, LSL #16
-	STRD	r2, [r0], #8
-	STRD	r2, [r0], #8
-	STRD	r2, [r0], #8
-	STRD	r2, [r0], #8
-	STRD	r2, [r0], #8
-	STRD	r2, [r0], #8
-	STRD	r2, [r0], #8
-	STRD	r2, [r0], #8
-	STRD	r2, [r0], #8
-	STRD	r2, [r0], #8
-	STRD	r2, [r0], #8
-	STRD	r2, [r0], #8
-	STRD	r2, [r0], #8
-	STRD	r2, [r0], #8
-	STRD	r2, [r0], #8
-	STRD	r2, [r0], #8
+	STRD	r2, r3, [r0], #8
+	STRD	r2, r3, [r0], #8
+	STRD	r2, r3, [r0], #8
+	STRD	r2, r3, [r0], #8
+	STRD	r2, r3, [r0], #8
+	STRD	r2, r3, [r0], #8
+	STRD	r2, r3, [r0], #8
+	STRD	r2, r3, [r0], #8
+	STRD	r2, r3, [r0], #8
+	STRD	r2, r3, [r0], #8
+	STRD	r2, r3, [r0], #8
+	STRD	r2, r3, [r0], #8
+	STRD	r2, r3, [r0], #8
+	STRD	r2, r3, [r0], #8
+	STRD	r2, r3, [r0], #8
+	STRD	r2, r3, [r0], #8
 	MOV	PC, r14
 	ENDP
 
@@ -812,22 +812,22 @@ oc_idct8x8_slow_v6
 	BEQ	oc_idct8x8_slow_v6_cols
 	MOV	r4, #0
 	MOV	r5, #0
-	STRD	r4, [r2], #8
-	STRD	r4, [r2], #8
-	STRD	r4, [r2], #8
-	STRD	r4, [r2], #8
-	STRD	r4, [r2], #8
-	STRD	r4, [r2], #8
-	STRD	r4, [r2], #8
-	STRD	r4, [r2], #8
-	STRD	r4, [r2], #8
-	STRD	r4, [r2], #8
-	STRD	r4, [r2], #8
-	STRD	r4, [r2], #8
-	STRD	r4, [r2], #8
-	STRD	r4, [r2], #8
-	STRD	r4, [r2], #8
-	STRD	r4, [r2], #8
+	STRD	r4, r5, [r2], #8
+	STRD	r4, r5, [r2], #8
+	STRD	r4, r5, [r2], #8
+	STRD	r4, r5, [r2], #8
+	STRD	r4, r5, [r2], #8
+	STRD	r4, r5, [r2], #8
+	STRD	r4, r5, [r2], #8
+	STRD	r4, r5, [r2], #8
+	STRD	r4, r5, [r2], #8
+	STRD	r4, r5, [r2], #8
+	STRD	r4, r5, [r2], #8
+	STRD	r4, r5, [r2], #8
+	STRD	r4, r5, [r2], #8
+	STRD	r4, r5, [r2], #8
+	STRD	r4, r5, [r2], #8
+	STRD	r4, r5, [r2], #8
 oc_idct8x8_slow_v6_cols
 ; Column transforms
 	BL	idct8_8core_down_v6
@@ -856,8 +856,8 @@ oc_idct8x8_10_v6 PROC
 	BEQ	oc_idct8x8_10_v6_cols
 	MOV	r4, #0
 	MOV	r5, #0
-	STRD	r4, [r2]
-	STRD	r4, [r2,#16]
+	STRD	r4, r5, [r2]
+	STRD	r4, r5, [r2,#16]
 	STR	r4, [r2,#32]
 	STR	r4, [r2,#48]
 oc_idct8x8_10_v6_cols
@@ -903,7 +903,7 @@ idct2_1core_v6 PROC
 	LDR	r3, OC_C4S4
 	LDRSH	r6, [r1], #16		; r6 = x[1,0]
 	SMULWB	r12,r3, r2		; r12= t[0,0]=OC_C4S4*x[0,0]>>16
-	LDRD	r4, OC_C7S1		; r4 = OC_C7S1; r5 = OC_C1S7
+	LDRD	r4, r5, OC_C7S1		; r4 = OC_C7S1; r5 = OC_C1S7
 	SMULWB	r6, r3, r6		; r6 = t[1,0]=OC_C4S4*x[1,0]>>16
 	SMULWT	r4, r4, r2		; r4 = t[0,4]=OC_C7S1*x[0,1]>>16
 	SMULWT	r7, r5, r2		; r7 = t[0,7]=OC_C1S7*x[0,1]>>16
@@ -965,7 +965,7 @@ idct2_2core_down_v6 PROC
 	MOV	r7 ,#8			; r7  = 8
 	LDR	r6, [r1], #16		; r6 = <x[1,1]|x[1,0]>
 	SMLAWB	r12,r3, r2, r7		; r12= (t[0,0]=OC_C4S4*x[0,0]>>16)+8
-	LDRD	r4, OC_C7S1		; r4 = OC_C7S1; r5 = OC_C1S7
+	LDRD	r4, r5, OC_C7S1		; r4 = OC_C7S1; r5 = OC_C1S7
 	SMLAWB	r7, r3, r6, r7		; r7 = (t[1,0]=OC_C4S4*x[1,0]>>16)+8
 	SMULWT  r5, r5, r2		; r2 = t[0,7]=OC_C1S7*x[0,1]>>16
 	PKHBT	r12,r12,r7, LSL #16	; r12= <t[1,0]+8|t[0,0]+8>
@@ -1048,7 +1048,7 @@ oc_idct8x8_6_v6 PROC
 	BEQ	oc_idct8x8_6_v6_cols
 	MOV	r4, #0
 	MOV	r5, #0
-	STRD	r4, [r0]
+	STRD	r4, r5, [r0]
 	STR	r4, [r0,#16]
 	STR	r4, [r0,#32]
 	MOV	r0, r8		; Write to the final destination.
@@ -1084,15 +1084,15 @@ idct3_2core_v6 PROC
 	; r0 =       ogg_int16_t *_y (destination)
 	; r1 = const ogg_int16_t *_x (source)
 ; Stage 1:
-	LDRD	r4, [r1], #16		; r4 = <x[0,1]|x[0,0]>; r5 = <*|x[0,2]>
-	LDRD	r10,OC_C6S2_3_v6	; r10= OC_C6S2; r11= OC_C2S6
+	LDRD	r4, r5, [r1], #16		; r4 = <x[0,1]|x[0,0]>; r5 = <*|x[0,2]>
+	LDRD	r10,r11, OC_C6S2_3_v6	; r10= OC_C6S2; r11= OC_C2S6
 	; Stall
 	SMULWB	r3, r11,r5		; r3 = t[0,3]=OC_C2S6*x[0,2]>>16
 	LDR	r11,OC_C4S4
 	SMULWB	r2, r10,r5		; r2 = t[0,2]=OC_C6S2*x[0,2]>>16
 	LDR	r5, [r1], #16		; r5 = <x[1,1]|x[1,0]>
 	SMULWB	r12,r11,r4		; r12= (t[0,0]=OC_C4S4*x[0,0]>>16)
-	LDRD	r6, OC_C7S1_3_v6	; r6 = OC_C7S1; r7 = OC_C1S7
+	LDRD	r6, r7, OC_C7S1_3_v6	; r6 = OC_C7S1; r7 = OC_C1S7
 	SMULWB	r10,r11,r5		; r10= (t[1,0]=OC_C4S4*x[1,0]>>16)
 	PKHBT	r12,r12,r10,LSL #16	; r12= <t[1,0]|t[0,0]>
 	SMULWT  r10,r7, r5		; r10= t[1,7]=OC_C1S7*x[1,1]>>16
@@ -1128,8 +1128,8 @@ idct3_3core_down_v6 PROC
 	; r0 =       ogg_int16_t *_y (destination)
 	; r1 = const ogg_int16_t *_x (source)
 ; Stage 1:
-	LDRD	r10,[r1], #16		; r10= <x[0,1]|x[0,0]>; r11= <??|x[0,2]>
-	LDRD	r6, OC_C6S2_3_v6	; r6 = OC_C6S2; r7 = OC_C2S6
+	LDRD	r10,r11,[r1], #16		; r10= <x[0,1]|x[0,0]>; r11= <??|x[0,2]>
+	LDRD	r6, r7, OC_C6S2_3_v6	; r6 = OC_C6S2; r7 = OC_C2S6
 	LDR	r4, [r1], #16		; r4 = <x[1,1]|x[1,0]>
 	SMULWB	r3, r7, r11		; r3 = t[0,3]=OC_C2S6*x[0,2]>>16
 	MOV	r7,#8
@@ -1140,7 +1140,7 @@ idct3_3core_down_v6 PROC
 	PKHBT	r3, r3, r3, LSL #16	; r3 = <t[0,3]|t[0,3]>
 	SMLAWB	r5, r11,r4, r7		; r5 = t[1,0]+8=(OC_C4S4*x[1,0]>>16)+8
 	PKHBT	r2, r2, r2, LSL #16	; r2 = <t[0,2]|t[0,2]>
-	LDRD	r6, OC_C7S1_3_v6	; r6 = OC_C7S1; r7 = OC_C1S7
+	LDRD	r6, r7, OC_C7S1_3_v6	; r6 = OC_C7S1; r7 = OC_C1S7
 	PKHBT	r12,r12,r5, LSL #16	; r12= <t[1,0]+8|t[0,0]+8>
 	SMULWT  r5, r7, r4		; r5 = t[1,7]=OC_C1S7*x[1,1]>>16
 	SMULWT  r7, r7, r10		; r7 = t[0,7]=OC_C1S7*x[0,1]>>16
@@ -1163,13 +1163,13 @@ idct4_3core_v6 PROC
 	; r0 =       ogg_int16_t *_y (destination)
 	; r1 = const ogg_int16_t *_x (source)
 ; Stage 1:
-	LDRD	r10,[r1], #16	; r10= <x[0,1]|x[0,0]>; r11= <x[0,3]|x[0,2]>
-	LDRD	r2, OC_C5S3_4_v6	; r2 = OC_C5S3; r3 = OC_C3S5
-	LDRD	r4, [r1], #16		; r4 = <x[1,1]|x[1,0]>; r5 = <??|x[1,2]>
+	LDRD	r10,r11,[r1], #16	; r10= <x[0,1]|x[0,0]>; r11= <x[0,3]|x[0,2]>
+	LDRD	r2, r3, OC_C5S3_4_v6	; r2 = OC_C5S3; r3 = OC_C3S5
+	LDRD	r4, r5, [r1], #16		; r4 = <x[1,1]|x[1,0]>; r5 = <??|x[1,2]>
 	SMULWT	r9, r3, r11		; r9 = t[0,6]=OC_C3S5*x[0,3]>>16
 	SMULWT	r8, r2, r11		; r8 = -t[0,5]=OC_C5S3*x[0,3]>>16
 	PKHBT	r9, r9, r2		; r9 = <0|t[0,6]>
-	LDRD	r6, OC_C6S2_4_v6	; r6 = OC_C6S2; r7 = OC_C2S6
+	LDRD	r6, r7, OC_C6S2_4_v6	; r6 = OC_C6S2; r7 = OC_C2S6
 	PKHBT	r8, r8, r2		; r9 = <0|-t[0,5]>
 	SMULWB	r3, r7, r11		; r3 = t[0,3]=OC_C2S6*x[0,2]>>16
 	SMULWB	r2, r6, r11		; r2 = t[0,2]=OC_C6S2*x[0,2]>>16
@@ -1180,7 +1180,7 @@ idct4_3core_v6 PROC
 	SMULWB	r12,r11,r10		; r12= t[0,0]=OC_C4S4*x[0,0]>>16
 	PKHBT	r2, r2, r5, LSL #16	; r2 = <t[1,2]|t[0,2]>
 	SMULWB	r5, r11,r4		; r5 = t[1,0]=OC_C4S4*x[1,0]>>16
-	LDRD	r6, OC_C7S1_4_v6	; r6 = OC_C7S1; r7 = OC_C1S7
+	LDRD	r6, r7, OC_C7S1_4_v6	; r6 = OC_C7S1; r7 = OC_C1S7
 	PKHBT	r12,r12,r5, LSL #16	; r12= <t[1,0]|t[0,0]>
 	SMULWT  r5, r7, r4		; r5 = t[1,7]=OC_C1S7*x[1,1]>>16
 	SMULWT  r7, r7, r10		; r7 = t[0,7]=OC_C1S7*x[0,1]>>16
@@ -1247,11 +1247,11 @@ idct4_4core_down_v6 PROC
 	; r0 =       ogg_int16_t *_y (destination)
 	; r1 = const ogg_int16_t *_x (source)
 ; Stage 1:
-	LDRD	r10,[r1], #16	; r10= <x[0,1]|x[0,0]>; r11= <x[0,3]|x[0,2]>
-	LDRD	r2, OC_C5S3_4_v6	; r2 = OC_C5S3; r3 = OC_C3S5
-	LDRD	r4, [r1], #16	; r4 = <x[1,1]|x[1,0]>; r5 = <x[1,3]|x[1,2]>
+	LDRD	r10,r11,[r1], #16	; r10= <x[0,1]|x[0,0]>; r11= <x[0,3]|x[0,2]>
+	LDRD	r2, r3, OC_C5S3_4_v6	; r2 = OC_C5S3; r3 = OC_C3S5
+	LDRD	r4, r5, [r1], #16	; r4 = <x[1,1]|x[1,0]>; r5 = <x[1,3]|x[1,2]>
 	SMULWT	r9, r3, r11		; r9 = t[0,6]=OC_C3S5*x[0,3]>>16
-	LDRD	r6, OC_C6S2_4_v6	; r6 = OC_C6S2; r7 = OC_C2S6
+	LDRD	r6, r7, OC_C6S2_4_v6	; r6 = OC_C6S2; r7 = OC_C2S6
 	SMULWT	r8, r2, r11		; r8 = -t[0,5]=OC_C5S3*x[0,3]>>16
 ; Here we cheat: row 3 had just a DC, so x[0,3]==x[1,3] by definition.
 	PKHBT	r9, r9, r9, LSL #16	; r9 = <t[0,6]|t[0,6]>
@@ -1266,7 +1266,7 @@ idct4_4core_down_v6 PROC
 	SMLAWB	r12,r11,r10,r7		; r12= t[0,0]+8=(OC_C4S4*x[0,0]>>16)+8
 	PKHBT	r2, r2, r5, LSL #16	; r2 = <t[1,2]|t[0,2]>
 	SMLAWB	r5, r11,r4 ,r7		; r5 = t[1,0]+8=(OC_C4S4*x[1,0]>>16)+8
-	LDRD	r6, OC_C7S1_4_v6	; r6 = OC_C7S1; r7 = OC_C1S7
+	LDRD	r6, r7, OC_C7S1_4_v6	; r6 = OC_C7S1; r7 = OC_C1S7
 	PKHBT	r12,r12,r5, LSL #16	; r12= <t[1,0]+8|t[0,0]+8>
 	SMULWT  r5, r7, r4		; r5 = t[1,7]=OC_C1S7*x[1,1]>>16
 	SMULWT  r7, r7, r10		; r7 = t[0,7]=OC_C1S7*x[0,1]>>16
@@ -1296,7 +1296,7 @@ idct8_8core_v6 PROC
 	STMFD	r13!,{r0,r14}
 ; Stage 1:
 	;5-6 rotation by 3pi/16
-	LDRD	r10,OC_C5S3_4_v6	; r10= OC_C5S3, r11= OC_C3S5
+	LDRD	r10,r11,OC_C5S3_4_v6	; r10= OC_C5S3, r11= OC_C3S5
 	LDR	r4, [r1,#8]		; r4 = <x[0,5]|x[0,4]>
 	LDR	r7, [r1,#24]		; r7 = <x[1,5]|x[1,4]>
 	SMULWT	r5, r11,r4		; r5 = OC_C3S5*x[0,5]>>16
@@ -1313,7 +1313,7 @@ idct8_8core_v6 PROC
 	PKHBT	r6, r6, r11,LSL #16	; r6 = <t[1,6]|t[0,6]>
 	SMULWT	r8, r10,r12		; r8 = OC_C5S3*x[1,3]>>16
 	;2-3 rotation by 6pi/16
-	LDRD	r10,OC_C6S2_4_v6	; r10= OC_C6S2, r11= OC_C2S6
+	LDRD	r10,r11,OC_C6S2_4_v6	; r10= OC_C6S2, r11= OC_C2S6
 	PKHBT	r3, r3, r8, LSL #16	; r3 = <r8|r3>
 	LDR	r8, [r1,#12]		; r8 = <x[0,7]|x[0,6]>
 	SMULWB	r2, r10,r0		; r2 = OC_C6S2*x[0,2]>>16
@@ -1329,7 +1329,7 @@ idct8_8core_v6 PROC
 	PKHBT	r3, r3, r10,LSL #16	; r3 = <t[1,6]|t[0,6]>
 	SMULWB	r12,r11,r7		; r12= OC_C2S6*x[1,6]>>16
 	;4-7 rotation by 7pi/16
-	LDRD	r10,OC_C7S1_8_v6	; r10= OC_C7S1, r11= OC_C1S7
+	LDRD	r10,r11,OC_C7S1_8_v6	; r10= OC_C7S1, r11= OC_C1S7
 	PKHBT	r9, r9, r12,LSL #16	; r9 = <r9|r12>
 	LDR	r0, [r1],#16		; r0 = <x[0,1]|x[0,0]>
 	PKHTB	r7, r7, r8, ASR #16	; r7 = <x[1,7]|x[0,7]>
@@ -1395,7 +1395,7 @@ idct8_8core_down_v6 PROC
 	STMFD	r13!,{r0,r14}
 ; Stage 1:
 	;5-6 rotation by 3pi/16
-	LDRD	r10,OC_C5S3_8_v6	; r10= OC_C5S3, r11= OC_C3S5
+	LDRD	r10,r11,OC_C5S3_8_v6	; r10= OC_C5S3, r11= OC_C3S5
 	LDR	r4, [r1,#8]		; r4 = <x[0,5]|x[0,4]>
 	LDR	r7, [r1,#24]		; r7 = <x[1,5]|x[1,4]>
 	SMULWT	r5, r11,r4		; r5 = OC_C3S5*x[0,5]>>16
@@ -1412,7 +1412,7 @@ idct8_8core_down_v6 PROC
 	PKHBT	r6, r6, r11,LSL #16	; r6 = <t[1,6]|t[0,6]>
 	SMULWT	r8, r10,r12		; r8 = OC_C5S3*x[1,3]>>16
 	;2-3 rotation by 6pi/16
-	LDRD	r10,OC_C6S2_8_v6	; r10= OC_C6S2, r11= OC_C2S6
+	LDRD	r10,r11,OC_C6S2_8_v6	; r10= OC_C6S2, r11= OC_C2S6
 	PKHBT	r3, r3, r8, LSL #16	; r3 = <r8|r3>
 	LDR	r8, [r1,#12]		; r8 = <x[0,7]|x[0,6]>
 	SMULWB	r2, r10,r0		; r2 = OC_C6S2*x[0,2]>>16
@@ -1428,7 +1428,7 @@ idct8_8core_down_v6 PROC
 	PKHBT	r3, r3, r10,LSL #16	; r3 = <t[1,6]|t[0,6]>
 	SMULWB	r12,r11,r7		; r12= OC_C2S6*x[1,6]>>16
 	;4-7 rotation by 7pi/16
-	LDRD	r10,OC_C7S1_8_v6	; r10= OC_C7S1, r11= OC_C1S7
+	LDRD	r10,r11,OC_C7S1_8_v6	; r10= OC_C7S1, r11= OC_C1S7
 	PKHBT	r9, r9, r12,LSL #16	; r9 = <r9|r12>
 	LDR	r0, [r1],#16		; r0 = <x[0,1]|x[0,0]>
 	PKHTB	r7, r7, r8, ASR #16	; r7 = <x[1,7]|x[0,7]>
