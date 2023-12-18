$NetBSD: patch-intl_lwbrk_nsJISx4051LineBreaker.cpp,v 1.1 2023/12/18 09:31:44 abs Exp $

Update for icu >= 74.1 support.

--- intl/lwbrk/nsJISx4051LineBreaker.cpp.orig	2023-12-13 23:14:55.231839980 +0000
+++ intl/lwbrk/nsJISx4051LineBreaker.cpp
@@ -550,8 +550,13 @@ GetClass(uint32_t u)
     /* REGIONAL_INDICATOR = 39,           [RI] */ CLASS_CHARACTER,
     /* E_BASE = 40,                       [EB] */ CLASS_BREAKABLE,
     /* E_MODIFIER = 41,                   [EM] */ CLASS_CHARACTER,
-    /* ZWJ = 42,                          [ZWJ]*/ CLASS_CHARACTER
-  };
+    /* ZWJ = 42,                          [ZWJ]*/ CLASS_CHARACTER,
+    /* AKSARA = 43,                       [AK] */ CLASS_CHARACTER,
+    /* AKSARA_PREBASE = 44,               [AP] */ CLASS_CHARACTER,
+    /* AKSARA_START = 45,                 [AS] */ CLASS_CHARACTER,
+    /* VIRAMA_FINAL = 46,                 [VF] */ CLASS_CHARACTER,
+    /* VIRAMA = 47,                       [VI] */ CLASS_CHARACTER,
+};
 
 #if ENABLE_INTL_API
   static_assert(U_LB_COUNT == mozilla::ArrayLength(sUnicodeLineBreakToClass),
