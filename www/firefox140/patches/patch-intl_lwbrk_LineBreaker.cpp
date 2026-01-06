$NetBSD: patch-intl_lwbrk_LineBreaker.cpp,v 1.1 2026/01/06 23:27:50 gutteridge Exp $

Fix builds with ICU >= 78.1.

--- intl/lwbrk/LineBreaker.cpp.orig	2026-01-06 23:10:28.979699230 +0000
+++ intl/lwbrk/LineBreaker.cpp
@@ -453,6 +453,7 @@ static int8_t GetClass(uint32_t u, LineB
       /* AKSARA_START = 45,                 [AS] */ CLASS_CHARACTER,
       /* VIRAMA_FINAL = 46,                 [VF] */ CLASS_CHARACTER,
       /* VIRAMA = 47,                       [VI] */ CLASS_CHARACTER,
+      /* UNAMBIGUOUS_HYPHEN = 48,           [HH] */ CLASS_CHARACTER,
   };
 
   static_assert(U_LB_COUNT == std::size(sUnicodeLineBreakToClass),
