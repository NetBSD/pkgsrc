$NetBSD: patch-media_libtheora_lib_arm_armbits.s,v 1.1 2015/04/28 12:06:34 joerg Exp $

--- media/libtheora/lib/arm/armbits.s.orig	2015-04-10 13:06:36.000000000 +0000
+++ media/libtheora/lib/arm/armbits.s
@@ -15,6 +15,7 @@
 ;
 ;********************************************************************
 
+	.syntax unified
 	AREA	|.text|, CODE, READONLY
 
 	; Explicitly specifying alignment here because some versions of
@@ -73,25 +74,25 @@ oc_pack_read_refill
 ;  negative.
 	CMP r10,r11            ; ptr<stop => HI
 	CMPHI r3,#7            ;   available<=24 => HI
-	LDRHIB r14,[r11],#1    ;     r14 = *ptr++
+	LDRBHI r14,[r11],#1    ;     r14 = *ptr++
 	SUBHI r3,#8            ;     available += 8
 	; (HI) Stall...
 	ORRHI r2,r14,LSL r3    ;     r2 = window|=r14<<32-available
 	CMPHI r10,r11          ;     ptr<stop => HI
 	CMPHI r3,#7            ;       available<=24 => HI
-	LDRHIB r14,[r11],#1    ;         r14 = *ptr++
+	LDRBHI r14,[r11],#1    ;         r14 = *ptr++
 	SUBHI r3,#8            ;         available += 8
 	; (HI) Stall...
 	ORRHI r2,r14,LSL r3    ;         r2 = window|=r14<<32-available
 	CMPHI r10,r11          ;         ptr<stop => HI
 	CMPHI r3,#7            ;           available<=24 => HI
-	LDRHIB r14,[r11],#1    ;             r14 = *ptr++
+	LDRBHI r14,[r11],#1    ;             r14 = *ptr++
 	SUBHI r3,#8            ;             available += 8
 	; (HI) Stall...
 	ORRHI r2,r14,LSL r3    ;             r2 = window|=r14<<32-available
 	CMPHI r10,r11          ;             ptr<stop => HI
 	CMPHI r3,#7            ;               available<=24 => HI
-	LDRHIB r14,[r11],#1    ;                 r14 = *ptr++
+	LDRBHI r14,[r11],#1    ;                 r14 = *ptr++
 	SUBHI r3,#8            ;                 available += 8
 	; (HI) Stall...
 	ORRHI r2,r14,LSL r3    ;                 r2 = window|=r14<<32-available
@@ -110,7 +111,7 @@ oc_pack_read_refill_last
 	CMP r11,r10            ; ptr<stop => LO
 ; If we didn't hit the end of the packet, then pull enough of the next byte to
 ;  to fill up the window.
-	LDRLOB r14,[r11]       ; (LO) r14 = *ptr
+	LDRBLO r14,[r11]       ; (LO) r14 = *ptr
 ; Otherwise, set the EOF flag and pretend we have lots of available bits.
 	MOVHS r14,#1           ; (HS) r14 = 1
 	ADDLO r10,r3,r1        ; (LO) r10 = available
@@ -189,12 +190,12 @@ oc_huff_token_decode_refill
 ; We can't possibly need more than 15 bits, so available must be <= 15.
 ; Therefore we can load at least two bytes without checking it.
 	CMP r2,r3              ; ptr<stop => HI
-	LDRHIB r14,[r3],#1     ;   r14 = *ptr++
+	LDRBHI r14,[r3],#1     ;   r14 = *ptr++
 	RSBHI r5,r5,#24        ; (HI) available = 32-(available+=8)
 	RSBLS r5,r5,#32        ; (LS) r5 = 32-available
 	ORRHI r4,r14,LSL r5    ;   r4 = window|=r14<<32-available
 	CMPHI r2,r3            ;   ptr<stop => HI
-	LDRHIB r14,[r3],#1     ;     r14 = *ptr++
+	LDRBHI r14,[r3],#1     ;     r14 = *ptr++
 	SUBHI r5,#8            ;     available += 8
 	; (HI) Stall...
 	ORRHI r4,r14,LSL r5    ;     r4 = window|=r14<<32-available
@@ -204,14 +205,14 @@ oc_huff_token_decode_refill
 ;  negative.
 	CMPHI r2,r3            ;     ptr<stop => HI
 	CMPHI r5,#7            ;       available<=24 => HI
-	LDRHIB r14,[r3],#1     ;         r14 = *ptr++
+	LDRBHI r14,[r3],#1     ;         r14 = *ptr++
 	SUBHI r5,#8            ;         available += 8
 	; (HI) Stall...
 	ORRHI r4,r14,LSL r5    ;         r4 = window|=r14<<32-available
 	CMP r2,r3              ; ptr<stop => HI
 	MOVLS r5,#-1<<30       ; (LS) available = OC_LOTS_OF_BITS+32
 	CMPHI r5,#7            ; (HI) available<=24 => HI
-	LDRHIB r14,[r3],#1     ; (HI)   r14 = *ptr++
+	LDRBHI r14,[r3],#1     ; (HI)   r14 = *ptr++
 	SUBHI r5,#8            ; (HI)   available += 8
 	; (HI) Stall...
 	ORRHI r4,r14,LSL r5    ; (HI)   r4 = window|=r14<<32-available
