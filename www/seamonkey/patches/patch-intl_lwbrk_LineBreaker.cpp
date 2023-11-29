$NetBSD: patch-intl_lwbrk_LineBreaker.cpp,v 1.1 2023/11/29 05:38:25 dholland Exp $

icu 74.1 support.

--- intl/lwbrk/LineBreaker.cpp.orig	2023-02-25 21:24:12.000000000 +0000
+++ intl/lwbrk/LineBreaker.cpp
@@ -559,7 +559,12 @@ GetClass(uint32_t u)
     /* REGIONAL_INDICATOR = 39,           [RI] */ CLASS_CHARACTER,
     /* E_BASE = 40,                       [EB] */ CLASS_BREAKABLE,
     /* E_MODIFIER = 41,                   [EM] */ CLASS_CHARACTER,
-    /* ZWJ = 42,                          [ZWJ]*/ CLASS_CHARACTER
+    /* ZWJ = 42,                          [ZWJ]*/ CLASS_CHARACTER,
+    /* AKSARA = 43,                       [AK] */ CLASS_CHARACTER,
+    /* AKSARA_PREBASE = 44,               [AP] */ CLASS_CHARACTER,
+    /* AKSARA_START = 45,                 [AS] */ CLASS_CHARACTER,
+    /* VIRAMA_FINAL = 46,                 [VF] */ CLASS_CHARACTER,
+    /* VIRAMA = 47,                       [VI] */ CLASS_CHARACTER,
   };
 
   static_assert(U_LB_COUNT == mozilla::ArrayLength(sUnicodeLineBreakToClass),
