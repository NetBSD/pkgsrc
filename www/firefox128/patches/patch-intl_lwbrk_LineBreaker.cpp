$NetBSD: patch-intl_lwbrk_LineBreaker.cpp,v 1.2 2026/01/06 16:16:39 ryoon Exp $

icu 74.1 and 78.1 support.

--- intl/lwbrk/LineBreaker.cpp.orig	2025-12-01 17:21:02.000000000 +0000
+++ intl/lwbrk/LineBreaker.cpp
@@ -434,7 +434,14 @@ static int8_t GetClass(uint32_t u, LineBreakRule aLeve
       /* REGIONAL_INDICATOR = 39,           [RI] */ CLASS_CHARACTER,
       /* E_BASE = 40,                       [EB] */ CLASS_BREAKABLE,
       /* E_MODIFIER = 41,                   [EM] */ CLASS_CHARACTER,
-      /* ZWJ = 42,                          [ZWJ]*/ CLASS_CHARACTER};
+      /* ZWJ = 42,                          [ZWJ]*/ CLASS_CHARACTER,
+      /* AKSARA = 43,                       [AK] */ CLASS_CHARACTER,
+      /* AKSARA_PREBASE = 44,               [AP] */ CLASS_CHARACTER,
+      /* AKSARA_START = 45,                 [AS] */ CLASS_CHARACTER,
+      /* VIRAMA_FINAL = 46,                 [VF] */ CLASS_CHARACTER,
+      /* VIRAMA = 47,                       [VI] */ CLASS_CHARACTER,
+      /* UNAMBIGUOUS_HYPHEN = 48,           [HH] */ CLASS_CHARACTER,
+};
 
   static_assert(U_LB_COUNT == mozilla::ArrayLength(sUnicodeLineBreakToClass),
                 "Gecko vs ICU LineBreak class mismatch");
