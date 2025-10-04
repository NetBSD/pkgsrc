$NetBSD: patch-src_corelib_text_qstring.cpp,v 1.1 2025/10/04 02:55:33 tsutsui Exp $

- fix moc --collect-json error on NetBSD/earmv7hfeb due to tokenizer()
  and split() corruptions by SIMD (neon) on armeb issue
> [ 11%] Running moc --collect-json for target Core
> Error opening [snip]/qtbase-everywhere-src-6.9.1/src/corelib/Core_autogen/
> include/../GSVTHXPFFC/moc_qsequentialanimationgroup_p.cpp.json for reading

--- src/corelib/text/qstring.cpp.orig	2025-10-03 14:44:24.989995160 +0000
+++ src/corelib/text/qstring.cpp
@@ -749,7 +749,7 @@ const char16_t *QtPrivate::qustrchr(QStr
                                    [=](qsizetype i) { return n[i] == c; },
                                    [=](qsizetype i) { return n + i; });
 #  endif
-#elif defined(__ARM_NEON__)
+#elif defined(__ARM_NEON__) && !defined(__ARMEB__)
     const uint16x8_t vmask = qvsetq_n_u16(1, 1 << 1, 1 << 2, 1 << 3, 1 << 4, 1 << 5, 1 << 6, 1 << 7);
     const uint16x8_t ch_vec = vdupq_n_u16(c);
     for (const char16_t *next = n + 8; next <= e; n = next, next += 8) {
@@ -1278,7 +1278,7 @@ static int ucstrncmp(const char16_t *a, 
     }
 #  elif defined(__SSE2__)
     return ucstrncmp_sse2<Mode>(a, b, l);
-#  elif defined(__ARM_NEON__)
+#  elif defined(__ARM_NEON__) && !defined(__ARMEB__)
     if (l >= 8) {
         const char16_t *end = a + l;
         const uint16x8_t mask = qvsetq_n_u16( 1, 1 << 1, 1 << 2, 1 << 3, 1 << 4, 1 << 5, 1 << 6, 1 << 7 );
