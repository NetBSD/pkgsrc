$NetBSD: patch-media_libopus_celt_arm_celt__pitch__xcorr__arm.s,v 1.1 2015/04/28 12:06:34 joerg Exp $

--- media/libopus/celt/arm/celt_pitch_xcorr_arm.s.orig	2015-04-10 12:53:15.000000000 +0000
+++ media/libopus/celt/arm/celt_pitch_xcorr_arm.s
@@ -26,6 +26,7 @@
 ; NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 ; SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 
+  .syntax unified
   AREA  |.text|, CODE, READONLY
 
   GET    celt/arm/armopts.s
@@ -309,7 +310,7 @@ xcorr_kernel_edsp_process4_done
   SUBS         r2, r2, #1         ; j--
   ; Stall
   SMLABB       r6, r12, r10, r6   ; sum[0] = MAC16_16(sum[0],x,y_0)
-  LDRGTH       r14, [r4], #2      ; r14 = *x++
+  LDRHGT       r14, [r4], #2      ; r14 = *x++
   SMLABT       r7, r12, r10, r7   ; sum[1] = MAC16_16(sum[1],x,y_1)
   SMLABB       r8, r12, r11, r8   ; sum[2] = MAC16_16(sum[2],x,y_2)
   SMLABT       r9, r12, r11, r9   ; sum[3] = MAC16_16(sum[3],x,y_3)
@@ -319,7 +320,7 @@ xcorr_kernel_edsp_process4_done
   SMLABB       r7, r14, r11, r7   ; sum[1] = MAC16_16(sum[1],x,y_2)
   LDRH         r10, [r5], #2      ; r10 = y_4 = *y++
   SMLABT       r8, r14, r11, r8   ; sum[2] = MAC16_16(sum[2],x,y_3)
-  LDRGTH       r12, [r4], #2      ; r12 = *x++
+  LDRHGT       r12, [r4], #2      ; r12 = *x++
   SMLABB       r9, r14, r10, r9   ; sum[3] = MAC16_16(sum[3],x,y_4)
   BLE xcorr_kernel_edsp_done
   SMLABB       r6, r12, r11, r6   ; sum[0] = MAC16_16(sum[0],tmp,y_2)
@@ -327,7 +328,7 @@ xcorr_kernel_edsp_process4_done
   SMLABT       r7, r12, r11, r7   ; sum[1] = MAC16_16(sum[1],tmp,y_3)
   LDRH         r2, [r5], #2       ; r2 = y_5 = *y++
   SMLABB       r8, r12, r10, r8   ; sum[2] = MAC16_16(sum[2],tmp,y_4)
-  LDRGTH       r14, [r4]          ; r14 = *x
+  LDRHGT       r14, [r4]          ; r14 = *x
   SMLABB       r9, r12, r2, r9    ; sum[3] = MAC16_16(sum[3],tmp,y_5)
   BLE xcorr_kernel_edsp_done
   SMLABT       r6, r14, r11, r6   ; sum[0] = MAC16_16(sum[0],tmp,y_3)
@@ -387,11 +388,11 @@ celt_pitch_xcorr_edsp_process1u_loop4
 celt_pitch_xcorr_edsp_process1u_loop4_done
   ADDS         r12, r12, #4
 celt_pitch_xcorr_edsp_process1u_loop1
-  LDRGEH       r6, [r4], #2
+  LDRHGE       r6, [r4], #2
   ; Stall
   SMLABBGE     r14, r6, r8, r14    ; sum = MAC16_16(sum, *x, *y)
-  SUBGES       r12, r12, #1
-  LDRGTH       r8, [r5], #2
+  SUBSGE       r12, r12, #1
+  LDRHGT       r8, [r5], #2
   BGT celt_pitch_xcorr_edsp_process1u_loop1
   ; Restore _x
   SUB          r4, r4, r3, LSL #1
@@ -474,7 +475,7 @@ celt_pitch_xcorr_edsp_process2_1
   ADDS         r12, r12, #1
   ; Stall
   SMLABB       r10, r6, r8, r10     ; sum0 = MAC16_16(sum0, x_0, y_0)
-  LDRGTH       r7, [r4], #2
+  LDRHGT       r7, [r4], #2
   SMLABT       r11, r6, r8, r11     ; sum1 = MAC16_16(sum1, x_0, y_1)
   BLE celt_pitch_xcorr_edsp_process2_done
   LDRH         r9, [r5], #2
@@ -527,8 +528,8 @@ celt_pitch_xcorr_edsp_process1a_loop_don
   SUBGE        r12, r12, #2
   SMLATTGE     r14, r6, r8, r14     ; sum = MAC16_16(sum, x_1, y_1)
   ADDS         r12, r12, #1
-  LDRGEH       r6, [r4], #2
-  LDRGEH       r8, [r5], #2
+  LDRHGE       r6, [r4], #2
+  LDRHGE       r8, [r5], #2
   ; Stall
   SMLABBGE     r14, r6, r8, r14     ; sum = MAC16_16(sum, *x, *y)
   ; maxcorr = max(maxcorr, sum)
