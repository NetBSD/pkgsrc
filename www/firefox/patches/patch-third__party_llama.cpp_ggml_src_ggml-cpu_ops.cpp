$NetBSD: patch-third__party_llama.cpp_ggml_src_ggml-cpu_ops.cpp,v 1.1 2026/11/05 03:16:51 gutteridge Exp $

Fix builds with recent GCC.

--- third_party/llama.cpp/ggml/src/ggml-cpu/ops.cpp.orig	2026-11-02 17:55:38.000000000 +0000
+++ third_party/llama.cpp/ggml/src/ggml-cpu/ops.cpp
@@ -2137,8 +2137,8 @@ static void ggml_compute_forward_gelu_f32(
         for (int k = 0; k < nc; k++) {
             const float x = ((float *) ((char *) dst->data + i3*nb3 + i2*nb2 + i1*(dst->nb[1])))[k];
             GGML_UNUSED(x);
-            assert(!isnan(x));
-            assert(!isinf(x));
+            assert(!std::isnan(x));
+            assert(!std::isinf(x));
         }
 #endif // NDEBUG
     }
@@ -2185,8 +2185,8 @@ static void ggml_compute_forward_gelu_f16(
             const ggml_fp16_t x = ((ggml_fp16_t *) ((char *) dst->data + i3*nb3 + i2*nb2 + i1*( dst->nb[1])))[k];
             const float v = GGML_CPU_FP16_TO_FP32(x);
             GGML_UNUSED(v);
-            assert(!isnan(v));
-            assert(!isinf(v));
+            assert(!std::isnan(v));
+            assert(!std::isinf(v));
         }
 #endif // NDEBUG
     }
@@ -2367,8 +2367,8 @@ static void ggml_compute_forward_gelu_erf_f32(
         for (int k = 0; k < nc; k++) {
             const float x = ((float *) ((char *) dst->data + i3*nb3 + i2*nb2 + i1*(dst->nb[1])))[k];
             GGML_UNUSED(x);
-            assert(!isnan(x));
-            assert(!isinf(x));
+            assert(!std::isnan(x));
+            assert(!std::isinf(x));
         }
 #endif // NDEBUG
     }
@@ -2415,8 +2415,8 @@ static void ggml_compute_forward_gelu_erf_f16(
             const ggml_fp16_t x = ((ggml_fp16_t *) ((char *) dst->data + i3*nb3 + i2*nb2 + i1*( dst->nb[1])))[k];
             const float v = GGML_CPU_FP16_TO_FP32(x);
             GGML_UNUSED(v);
-            assert(!isnan(v));
-            assert(!isinf(v));
+            assert(!std::isnan(v));
+            assert(!std::isinf(v));
         }
 #endif // NDEBUG
     }
@@ -2486,8 +2486,8 @@ static void ggml_compute_forward_gelu_quick_f32(
         for (int k = 0; k < nc; k++) {
             const float x = ((float *) ((char *) dst->data + i3*nb3 + i2*nb2 + i1*(dst->nb[1])))[k];
             GGML_UNUSED(x);
-            assert(!isnan(x));
-            assert(!isinf(x));
+            assert(!std::isnan(x));
+            assert(!std::isinf(x));
         }
 #endif // NDEBUG
     }
@@ -2534,8 +2534,8 @@ static void ggml_compute_forward_gelu_quick_f16(
             const ggml_fp16_t x = ((ggml_fp16_t *) ((char *) dst->data + i3*nb3 + i2*nb2 + i1*( dst->nb[1])))[k];
             const float v = GGML_CPU_FP16_TO_FP32(x);
             GGML_UNUSED(v);
-            assert(!isnan(v));
-            assert(!isinf(v));
+            assert(!std::isnan(v));
+            assert(!std::isinf(v));
         }
 #endif // NDEBUG
     }
@@ -2605,8 +2605,8 @@ static void ggml_compute_forward_silu_f32(
         for (int k = 0; k < nc; k++) {
             const float x = ((float *) ((char *) dst->data + i3*nb3 + i2*nb2 + i1*(dst->nb[1])))[k];
             GGML_UNUSED(x);
-            assert(!isnan(x));
-            assert(!isinf(x));
+            assert(!std::isnan(x));
+            assert(!std::isinf(x));
         }
 #endif // NDEBUG
     }
@@ -2653,8 +2653,8 @@ static void ggml_compute_forward_silu_f16(
             const ggml_fp16_t x = ((ggml_fp16_t *) ((char *) dst->data + i3*nb3 + i2*nb2 + i1*( dst->nb[1])))[k];
             const float v = GGML_CPU_FP16_TO_FP32(x);
             GGML_UNUSED(v);
-            assert(!isnan(v));
-            assert(!isinf(v));
+            assert(!std::isnan(v));
+            assert(!std::isinf(v));
         }
 #endif // NDEBUG
     }
@@ -2803,8 +2803,8 @@ static void ggml_compute_forward_silu_back_f32(
         for (int k = 0; k < nc; k++) {
             const float x = ((float *) ((char *) dst->data + i1*( dst->nb[1])))[k];
             GGML_UNUSED(x);
-            assert(!isnan(x));
-            assert(!isinf(x));
+            assert(!std::isnan(x));
+            assert(!std::isinf(x));
         }
 #endif // NDEBUG
     }
@@ -2847,8 +2847,8 @@ static void ggml_compute_forward_silu_back_f16(
             const float x = ((ggml_fp16_t *) ((char *) dst->data + i1*( dst->nb[1])))[k];
             const float v = GGML_CPU_FP16_TO_FP32(x);
             GGML_UNUSED(v);
-            assert(!isnan(v));
-            assert(!isinf(v));
+            assert(!std::isnan(v));
+            assert(!std::isinf(v));
         }
 #endif // NDEBUG
     }
@@ -2930,8 +2930,8 @@ static void ggml_compute_forward_reglu_f32(
         for (int k = 0; k < nc; k++) {
             const float x = ((float *) ((char *) dst->data + i1*( dst->nb[1])))[k];
             GGML_UNUSED(x);
-            assert(!isnan(x));
-            assert(!isinf(x));
+            assert(!std::isnan(x));
+            assert(!std::isinf(x));
         }
 #endif // NDEBUG
     }
@@ -2990,8 +2990,8 @@ static void ggml_compute_forward_reglu_f16(
             const ggml_fp16_t x = ((ggml_fp16_t *) ((char *) dst->data + i1*( dst->nb[1])))[k];
             const float v = GGML_FP16_TO_FP32(x);
             GGML_UNUSED(v);
-            assert(!isnan(v));
-            assert(!isinf(v));
+            assert(!std::isnan(v));
+            assert(!std::isinf(v));
         }
 #endif // NDEBUG
     }
@@ -3073,8 +3073,8 @@ static void ggml_compute_forward_geglu_f32(
         for (int k = 0; k < nc; k++) {
             const float x = ((float *) ((char *) dst->data + i1*( dst->nb[1])))[k];
             GGML_UNUSED(x);
-            assert(!isnan(x));
-            assert(!isinf(x));
+            assert(!std::isnan(x));
+            assert(!std::isinf(x));
         }
 #endif // NDEBUG
     }
@@ -3133,8 +3133,8 @@ static void ggml_compute_forward_geglu_f16(
             const ggml_fp16_t x = ((ggml_fp16_t *) ((char *) dst->data + i1*( dst->nb[1])))[k];
             const float v = GGML_FP16_TO_FP32(x);
             GGML_UNUSED(v);
-            assert(!isnan(v));
-            assert(!isinf(v));
+            assert(!std::isnan(v));
+            assert(!std::isinf(v));
         }
 #endif // NDEBUG
     }
@@ -3216,8 +3216,8 @@ static void ggml_compute_forward_swiglu_f32(
         for (int k = 0; k < nc; k++) {
             const float x = ((float *) ((char *) dst->data + i1*( dst->nb[1])))[k];
             GGML_UNUSED(x);
-            assert(!isnan(x));
-            assert(!isinf(x));
+            assert(!std::isnan(x));
+            assert(!std::isinf(x));
         }
 #endif // NDEBUG
     }
@@ -3276,8 +3276,8 @@ static void ggml_compute_forward_swiglu_f16(
             const ggml_fp16_t x = ((ggml_fp16_t *) ((char *) dst->data + i1*( dst->nb[1])))[k];
             const float v = GGML_FP16_TO_FP32(x);
             GGML_UNUSED(v);
-            assert(!isnan(v));
-            assert(!isinf(v));
+            assert(!std::isnan(v));
+            assert(!std::isinf(v));
         }
 #endif // NDEBUG
     }
@@ -3367,8 +3367,8 @@ static void ggml_compute_forward_swiglu_oai_f32(
         for (int k = 0; k < nc; k++) {
             const float x = dst_p[k];
             GGML_UNUSED(x);
-            assert(!isnan(x));
-            assert(!isinf(x));
+            assert(!std::isnan(x));
+            assert(!std::isinf(x));
         }
 #endif // NDEBUG
     }
@@ -3446,8 +3446,8 @@ static void ggml_compute_forward_geglu_erf_f32(
         for (int k = 0; k < nc; k++) {
             const float x = ((float *) ((char *) dst->data + i1*( dst->nb[1])))[k];
             GGML_UNUSED(x);
-            assert(!isnan(x));
-            assert(!isinf(x));
+            assert(!std::isnan(x));
+            assert(!std::isinf(x));
         }
 #endif // NDEBUG
     }
@@ -3506,8 +3506,8 @@ static void ggml_compute_forward_geglu_erf_f16(
             const ggml_fp16_t x = ((ggml_fp16_t *) ((char *) dst->data + i1*( dst->nb[1])))[k];
             const float v = GGML_FP16_TO_FP32(x);
             GGML_UNUSED(v);
-            assert(!isnan(v));
-            assert(!isinf(v));
+            assert(!std::isnan(v));
+            assert(!std::isinf(v));
         }
 #endif // NDEBUG
     }
@@ -3589,8 +3589,8 @@ static void ggml_compute_forward_geglu_quick_f32(
         for (int k = 0; k < nc; k++) {
             const float x = ((float *) ((char *) dst->data + i1*( dst->nb[1])))[k];
             GGML_UNUSED(x);
-            assert(!isnan(x));
-            assert(!isinf(x));
+            assert(!std::isnan(x));
+            assert(!std::isinf(x));
         }
 #endif // NDEBUG
     }
@@ -3649,8 +3649,8 @@ static void ggml_compute_forward_geglu_quick_f16(
             const ggml_fp16_t x = ((ggml_fp16_t *) ((char *) dst->data + i1*( dst->nb[1])))[k];
             const float v = GGML_FP16_TO_FP32(x);
             GGML_UNUSED(v);
-            assert(!isnan(v));
-            assert(!isinf(v));
+            assert(!std::isnan(v));
+            assert(!std::isinf(v));
         }
 #endif // NDEBUG
     }
@@ -5393,7 +5393,7 @@ static void ggml_compute_forward_soft_max_f32(
 #ifndef NDEBUG
                 for (int i = 0; i < ne00; ++i) {
                     //printf("p[%d] = %f\n", i, p[i]);
-                    assert(!isnan(wp[i]));
+                    assert(!std::isnan(wp[i]));
                 }
 #endif // NDEBUG
 
@@ -5417,8 +5417,8 @@ static void ggml_compute_forward_soft_max_f32(
 
 #ifndef NDEBUG
                 for (int i = 0; i < ne00; ++i) {
-                    assert(!isnan(dp[i]));
-                    assert(!isinf(dp[i]));
+                    assert(!std::isnan(dp[i]));
+                    assert(!std::isinf(dp[i]));
                 }
 #endif // NDEBUG
             }
@@ -5491,8 +5491,8 @@ static void ggml_compute_forward_soft_max_ext_back_f32
 #ifndef NDEBUG
         for (int i = 0; i < nc; ++i) {
             //printf("p[%d] = %f\n", i, p[i]);
-            assert(!isnan(dy[i]));
-            assert(!isnan(y[i]));
+            assert(!std::isnan(dy[i]));
+            assert(!std::isnan(y[i]));
         }
 #endif // NDEBUG
         // Jii = yi - yi*yi
@@ -5524,8 +5524,8 @@ static void ggml_compute_forward_soft_max_ext_back_f32
 
 #ifndef NDEBUG
         for (int i = 0; i < nc; ++i) {
-            assert(!isnan(dx[i]));
-            assert(!isinf(dx[i]));
+            assert(!std::isnan(dx[i]));
+            assert(!std::isinf(dx[i]));
         }
 #endif // NDEBUG
     }
@@ -11114,8 +11114,8 @@ static void ggml_compute_forward_cross_entropy_loss_f3
 #ifndef NDEBUG
         for (int64_t i = 0; i < nc; ++i) {
             //printf("p[%d] = %f\n", i, p[i]);
-            assert(!isnan(s0[i]));
-            assert(!isnan(s1[i]));
+            assert(!std::isnan(s0[i]));
+            assert(!std::isnan(s1[i]));
         }
 #endif // NDEBUG
 
@@ -11133,8 +11133,8 @@ static void ggml_compute_forward_cross_entropy_loss_f3
 
 #ifndef NDEBUG
         for (int64_t i = 0; i < nc; ++i) {
-            assert(!isnan(st[i]));
-            assert(!isinf(st[i]));
+            assert(!std::isnan(st[i]));
+            assert(!std::isinf(st[i]));
         }
 #endif // NDEBUG
     }
@@ -11206,8 +11206,8 @@ static void ggml_compute_forward_cross_entropy_loss_ba
 #ifndef NDEBUG
         for (int64_t i = 0; i < nc; ++i) {
             //printf("p[%d] = %f\n", i, p[i]);
-            assert(!isnan(s0[i]));
-            assert(!isnan(s1[i]));
+            assert(!std::isnan(s0[i]));
+            assert(!std::isnan(s1[i]));
         }
 #endif // NDEBUG
 
@@ -11224,8 +11224,8 @@ static void ggml_compute_forward_cross_entropy_loss_ba
 
 #ifndef NDEBUG
         for (int64_t i = 0; i < nc; ++i) {
-            assert(!isnan(ds0[i]));
-            assert(!isinf(ds0[i]));
+            assert(!std::isnan(ds0[i]));
+            assert(!std::isinf(ds0[i]));
         }
 #endif // NDEBUG
     }
