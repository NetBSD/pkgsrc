$NetBSD: patch-src_corelib_global_qsimd__p.h,v 1.1 2025/10/07 11:57:14 tsutsui Exp $

- fix ARMEB NEON qvset*() lane order bugs that cause corructions
  of QString functions like tokenizer() and split() and break
  qt6 packages builds:
> [ 11%] Running moc --collect-json for target Core
> Error opening [snip]/qtbase-everywhere-src-6.9.1/src/corelib/Core_autogen/
> include/../GSVTHXPFFC/moc_qsequentialanimationgroup_p.cpp.json for reading
  etc.

--- src/corelib/global/qsimd_p.h.orig	2025-09-22 07:03:29.000000000 +0000
+++ src/corelib/global/qsimd_p.h
@@ -300,7 +300,8 @@ inline uint16x8_t qvsetq_n_u16(uint16_t 
         v5 | (v6 << 16) | (u64(v7) << 32) | (u64(v8) << 48)
     };
 #else
-    const uint16x8_t vmask = { v1, v2, v3, v4, v5, v6, v7, v8 };
+    alignas(16) uint16_t mask[8] = { v1, v2, v3, v4, v5, v6, v7, v8 };
+    const uint16x8_t vmask = vld1q_u16(mask);
 #endif
     return vmask;
 }
@@ -313,7 +314,8 @@ inline uint8x8_t qvset_n_u8(uint8_t v1, 
         (u64(v5) << 32) | (u64(v6) << 40) | (u64(v7) << 48) | (u64(v8) << 56)
     };
 #else
-    const uint8x8_t vmask = { v1, v2, v3, v4, v5, v6, v7, v8 };
+    alignas(16) uint8_t mask[8] = { v1, v2, v3, v4, v5, v6, v7, v8 };
+    const uint8x8_t vmask = vld1_u8(mask);
 #endif
     return vmask;
 }
@@ -330,8 +332,9 @@ inline uint8x16_t qvsetq_n_u8(uint8_t v1
         (u64(v13) << 32) | (u64(v14) << 40) | (u64(v15) << 48) | (u64(v16) << 56)
     };
 #else
-    const uint8x16_t vmask = { v1, v2,  v3,  v4,  v5,  v6,  v7,  v8,
-                               v9, v10, v11, v12, v13, v14, v15, v16};
+    alignas(16) uint8_t mask[16] = { v1, v2,  v3,  v4,  v5,  v6,  v7,  v8,
+                                     v9, v10, v11, v12, v13, v14, v15, v16};
+    const uint8x16_t vmask = vld1q_u8(mask);
 #endif
     return vmask;
 }
@@ -340,7 +343,8 @@ inline uint32x4_t qvsetq_n_u32(uint32_t 
 #if defined(Q_CC_MSVC) && !defined(Q_CC_CLANG)
     return uint32x4_t{ (uint64_t(b) << 32) | a, (uint64_t(d) << 32) | c };
 #else
-    return uint32x4_t{ a, b, c, d };
+    alignas(16) uint32_t mask[4] = { a, b, c, d };
+    return vld1q_u32(mask);
 #endif
 }
 #endif
