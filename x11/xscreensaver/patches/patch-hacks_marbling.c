$NetBSD: patch-hacks_marbling.c,v 1.1 2022/02/19 17:58:22 wiz Exp $

Upstream patch from jwz to fix compilation with gcc 7.5.

--- hacks/marbling.c.orig	2021-10-04 23:20:23.052312294 +0000
+++ hacks/marbling.c
@@ -44,6 +44,13 @@
 #include "thread_util.h"
 #include "xshm.h"
 
+#if defined __GNUC__ || defined __clang__ || \
+  defined __STDC_VERSION__ && __STDC_VERSION__ > 199901L
+# define INLINE inline
+#else
+# define INLINE
+#endif
+
 /* Use GCC/Clang's vector SIMD extensions, when possible.
    https://gcc.gnu.org/onlinedocs/gcc/Vector-Extensions.html
  */
@@ -59,17 +66,21 @@
  */
 #  if defined __AVX2__
 #   define VSIZE 16
-#   define IMUL_HI __builtin_ia32_pmulhw256
-#   define MUL_HI __builtin_ia32_pmulhuw256
+#   define IMUL_HI_OP __builtin_ia32_pmulhw256
+#   define MUL_HI_OP __builtin_ia32_pmulhuw256
 #  elif defined __SSE2__
 #   define VSIZE 8
-#   define IMUL_HI __builtin_ia32_pmulhw128
-#   define MUL_HI __builtin_ia32_pmulhuw128
+#   define IMUL_HI_OP __builtin_ia32_pmulhw128
+#   define MUL_HI_OP __builtin_ia32_pmulhuw128
 #  endif
 
 #  ifdef VSIZE
-typedef int16_t v_uhi __attribute__((vector_size(VSIZE * 2)));
+typedef uint16_t v_uhi __attribute__((vector_size(VSIZE * 2)));
 typedef int16_t v_hi __attribute__((vector_size(VSIZE * 2)));
+
+static INLINE v_hi IMUL_HI(v_hi a, v_hi b) { return IMUL_HI_OP(a, b); }
+static INLINE v_uhi MUL_HI(v_uhi a, v_uhi b) { return (v_uhi)MUL_HI_OP((v_hi)a, (v_hi)b); }
+
 #  endif
 # endif
 
@@ -114,13 +125,6 @@ typedef int16_t v_hi;
 # define VEC_INDEX(v, i) ((v)[i])
 #endif
 
-#if defined __GNUC__ || defined __clang__ || \
-  defined __STDC_VERSION__ && __STDC_VERSION__ > 199901L
-# define INLINE inline
-#else
-# define INLINE
-#endif
-
 struct state {
   Display *dpy;
   Window window;
@@ -156,18 +160,20 @@ const unsigned lerp_loss = 2; /* Min: 2 
 #endif
 
 /* == 8 for x86 and scalar. (Nice.) */
-const unsigned noise_out_bits = noise_work_bits - 3 * lerp_loss + 1;
+/* const unsigned noise_out_bits = noise_work_bits - 3 * lerp_loss + 1; */
+#define noise_out_bits ((noise_work_bits - 3) * (lerp_loss + 1))
 const unsigned noise_in_bits = 8;
 
-static INLINE v_hi
+static INLINE v_uhi
 broadcast (int16_t x)
 {
 #if VSIZE == 1
-  return x;
+  v_hi r = x;
 #else
   v_hi r = {0};
-  return r + x;
+  r = r + x;
 #endif
+  return (v_uhi)r;
 }
 
 static INLINE v_uhi
@@ -175,11 +181,22 @@ fade (v_uhi t)
 {
   const uint16_t F = 256;
 
+  /* This whole thing is playing fast and loose with signdedness, mostly
+     because __builtin_ia32_pmulhuw256 is an unsigned op that requires signed
+     params, and Android's clang doesn't seem to care about signed vs.
+     unsigned vector variables.
+
+     The multiplications below should be unsigned, but the result is the same
+     either way, because it's getting the low 16 bits (not the high 16).
+   */
 #if __ARM_NEON
-  v_uhi t2 = (t * t) >> 1;
-  return
-    vqdmulhq_s16(t2, 10 * t - vqdmulhq_s16(t2, (uint16_t)(15 * F) - t * 6)) <<
+  v_uhi ut2 = (t * t) >> 1;
+  v_hi it2 = (v_hi)ut2;
+  v_hi it = (v_hi)t;
+  v_hi iret =
+    vqdmulhq_s16(it2, 10 * it - vqdmulhq_s16(it2, (int16_t)(15 * F) - it * 6)) <<
     (noise_work_bits - noise_in_bits + 1);
+  return (v_uhi)iret;
 #else
   v_uhi t2 = t * t;
   return
@@ -239,7 +256,7 @@ noise (v_uhi x, v_uhi y, v_uhi z)
 {
   const v_uhi one = broadcast(1 << noise_work_bits);
   v_uhi X, Y, Z, A, B, AA, AB, BA, BB;
-  v_uhi u, v, w;
+  v_hi u, v, w;
   v_hi c0, c1, c2, c3, c4, c5, c6, c7;
   X = x >> noise_in_bits;			/* FIND UNIT CUBE THAT */
   Y = y >> noise_in_bits;			/* CONTAINS POINT. */
@@ -247,9 +264,9 @@ noise (v_uhi x, v_uhi y, v_uhi z)
   x &= (uint16_t)((1 << noise_in_bits) - 1);	/* FIND RELATIVE X,Y,Z */
   y &= (uint16_t)((1 << noise_in_bits) - 1);	/* OF POINT IN CUBE. */
   z &= (uint16_t)((1 << noise_in_bits) - 1);
-  u = fade(x);					/* COMPUTE FADE CURVES */
-  v = fade(y);					/* FOR EACH OF X,Y,Z. */
-  w = fade(z);
+  u = (v_hi)fade(x);				/* COMPUTE FADE CURVES */
+  v = (v_hi)fade(y);				/* FOR EACH OF X,Y,Z. */
+  w = (v_hi)fade(z);
 
   A = noise_rand(X)+Y, AA = P(A)+Z, AB = P(A+1)+Z; /* HASH COORDINATES OF */
   B = P(X+1)+Y,        BA = P(B)+Z, BB = P(B+1)+Z; /* THE 8 CUBE CORNERS, */
@@ -265,7 +282,8 @@ noise (v_uhi x, v_uhi y, v_uhi z)
   c6 = grad(P(AB+1), x,     y-one, z-one );
   c7 = grad(P(BB+1), x-one, y-one, z-one );
 
-  return SCALE(LERP(w, LERP(v, LERP(u, c0, c1),  /* AND ADD BLENDED */
+  return
+  (v_uhi)SCALE(LERP(w, LERP(v, LERP(u, c0, c1),  /* AND ADD BLENDED */
                                LERP(u, c2, c3)), /* RESULTS FROM  8 */
                        LERP(v, LERP(u, c4, c5),  /* CORNERS OF CUBE */
                                LERP(u, c6, c7))));
@@ -292,7 +310,7 @@ fbm (v_uhi x, v_uhi y, v_uhi z)
   for (i = 0; i < octaves; i++)
     {
 #if __ARM_NEON
-      t += vqdmulhq_n_s16(noise (f*x, f*y, f*z), a);
+      t += (v_uhi)vqdmulhq_n_s16((v_hi)noise (f*x, f*y, f*z), a);
       a = ((uint32_t)a * iG) >> 16;
 #else
       t += MUL_HI(noise (f*x, f*y, f*z), a);
