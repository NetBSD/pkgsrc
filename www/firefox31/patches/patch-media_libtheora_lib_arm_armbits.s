$NetBSD: patch-media_libtheora_lib_arm_armbits.s,v 1.2 2015/06/02 20:04:43 joerg Exp $

--- media/libtheora/lib/arm/armbits.s.orig	2015-04-10 13:06:36.000000000 +0000
+++ media/libtheora/lib/arm/armbits.s
@@ -15,6 +15,7 @@
 ;
 ;********************************************************************
 
+	.syntax unified
 	AREA	|.text|, CODE, READONLY
 
 	; Explicitly specifying alignment here because some versions of
@@ -73,28 +74,28 @@ oc_pack_read_refill
 ;  negative.
 	CMP r10,r11            ; ptr<stop => HI
 	CMPHI r3,#7            ;   available<=24 => HI
-	LDRHIB r14,[r11],#1    ;     r14 = *ptr++
+	LDRBHI r14,[r11],#1    ;     r14 = *ptr++
 	SUBHI r3,#8            ;     available += 8
 	; (HI) Stall...
-	ORRHI r2,r14,LSL r3    ;     r2 = window|=r14<<32-available
+	ORRHI r2,r2,r14,LSL r3    ;     r2 = window|=r14<<32-available
 	CMPHI r10,r11          ;     ptr<stop => HI
 	CMPHI r3,#7            ;       available<=24 => HI
-	LDRHIB r14,[r11],#1    ;         r14 = *ptr++
+	LDRBHI r14,[r11],#1    ;         r14 = *ptr++
 	SUBHI r3,#8            ;         available += 8
 	; (HI) Stall...
-	ORRHI r2,r14,LSL r3    ;         r2 = window|=r14<<32-available
+	ORRHI r2,r2,r14,LSL r3    ;         r2 = window|=r14<<32-available
 	CMPHI r10,r11          ;         ptr<stop => HI
 	CMPHI r3,#7            ;           available<=24 => HI
-	LDRHIB r14,[r11],#1    ;             r14 = *ptr++
+	LDRBHI r14,[r11],#1    ;             r14 = *ptr++
 	SUBHI r3,#8            ;             available += 8
 	; (HI) Stall...
-	ORRHI r2,r14,LSL r3    ;             r2 = window|=r14<<32-available
+	ORRHI r2,r2,r14,LSL r3    ;             r2 = window|=r14<<32-available
 	CMPHI r10,r11          ;             ptr<stop => HI
 	CMPHI r3,#7            ;               available<=24 => HI
-	LDRHIB r14,[r11],#1    ;                 r14 = *ptr++
+	LDRBHI r14,[r11],#1    ;                 r14 = *ptr++
 	SUBHI r3,#8            ;                 available += 8
 	; (HI) Stall...
-	ORRHI r2,r14,LSL r3    ;                 r2 = window|=r14<<32-available
+	ORRHI r2,r2,r14,LSL r3    ;                 r2 = window|=r14<<32-available
 	SUBS r3,r0,r3          ; r3 = available-=_bits, available<bits => GT
 	BLT oc_pack_read_refill_last
 	MOV r0,r2,LSR r0       ; r0 = window>>32-_bits
@@ -110,7 +111,7 @@ oc_pack_read_refill_last
 	CMP r11,r10            ; ptr<stop => LO
 ; If we didn't hit the end of the packet, then pull enough of the next byte to
 ;  to fill up the window.
-	LDRLOB r14,[r11]       ; (LO) r14 = *ptr
+	LDRBLO r14,[r11]       ; (LO) r14 = *ptr
 ; Otherwise, set the EOF flag and pretend we have lots of available bits.
 	MOVHS r14,#1           ; (HS) r14 = 1
 	ADDLO r10,r3,r1        ; (LO) r10 = available
@@ -189,32 +190,32 @@ oc_huff_token_decode_refill
 ; We can't possibly need more than 15 bits, so available must be <= 15.
 ; Therefore we can load at least two bytes without checking it.
 	CMP r2,r3              ; ptr<stop => HI
-	LDRHIB r14,[r3],#1     ;   r14 = *ptr++
+	LDRBHI r14,[r3],#1     ;   r14 = *ptr++
 	RSBHI r5,r5,#24        ; (HI) available = 32-(available+=8)
 	RSBLS r5,r5,#32        ; (LS) r5 = 32-available
-	ORRHI r4,r14,LSL r5    ;   r4 = window|=r14<<32-available
+	ORRHI r4,r4,r14,LSL r5    ;   r4 = window|=r14<<32-available
 	CMPHI r2,r3            ;   ptr<stop => HI
-	LDRHIB r14,[r3],#1     ;     r14 = *ptr++
+	LDRBHI r14,[r3],#1     ;     r14 = *ptr++
 	SUBHI r5,#8            ;     available += 8
 	; (HI) Stall...
-	ORRHI r4,r14,LSL r5    ;     r4 = window|=r14<<32-available
+	ORRHI r4,r4,r14,LSL r5    ;     r4 = window|=r14<<32-available
 ; We can use unsigned compares for both the pointers and for available
 ;  (allowing us to chain condition codes) because available will never be
 ;  larger than 32 (or we wouldn't be here), and thus 32-available will never be
 ;  negative.
 	CMPHI r2,r3            ;     ptr<stop => HI
 	CMPHI r5,#7            ;       available<=24 => HI
-	LDRHIB r14,[r3],#1     ;         r14 = *ptr++
+	LDRBHI r14,[r3],#1     ;         r14 = *ptr++
 	SUBHI r5,#8            ;         available += 8
 	; (HI) Stall...
-	ORRHI r4,r14,LSL r5    ;         r4 = window|=r14<<32-available
+	ORRHI r4,r4,r14,LSL r5    ;         r4 = window|=r14<<32-available
 	CMP r2,r3              ; ptr<stop => HI
 	MOVLS r5,#-1<<30       ; (LS) available = OC_LOTS_OF_BITS+32
 	CMPHI r5,#7            ; (HI) available<=24 => HI
-	LDRHIB r14,[r3],#1     ; (HI)   r14 = *ptr++
+	LDRBHI r14,[r3],#1     ; (HI)   r14 = *ptr++
 	SUBHI r5,#8            ; (HI)   available += 8
 	; (HI) Stall...
-	ORRHI r4,r14,LSL r5    ; (HI)   r4 = window|=r14<<32-available
+	ORRHI r4,r4,r14,LSL r5    ; (HI)   r4 = window|=r14<<32-available
 	RSB r14,r10,#32        ; r14 = 32-n
 	MOV r14,r4,LSR r14     ; r14 = bits=window>>32-n
 	ADD r12,r12,r14        ;
