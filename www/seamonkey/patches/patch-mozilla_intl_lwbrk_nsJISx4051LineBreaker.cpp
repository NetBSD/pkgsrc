$NetBSD: patch-mozilla_intl_lwbrk_nsJISx4051LineBreaker.cpp,v 1.1 2017/08/18 23:55:07 ryoon Exp $

--- mozilla/intl/lwbrk/nsJISx4051LineBreaker.cpp.orig	2017-07-07 05:36:43.000000000 +0000
+++ mozilla/intl/lwbrk/nsJISx4051LineBreaker.cpp
@@ -12,6 +12,10 @@
 #include "nsTArray.h"
 #include "nsUnicodeProperties.h"
 
+#if ENABLE_INTL_API
+#include "unicode/uchar.h"  // for U_LB_COUNT until bug 1305700
+#endif
+
 /* 
 
    Simplification of Pair Table in JIS X 4051
@@ -547,10 +551,22 @@ GetClass(uint32_t u)
     /* CLOSE_PARENTHESIS = 36,            [CP] */ CLASS_CLOSE_LIKE_CHARACTER,
     /* CONDITIONAL_JAPANESE_STARTER = 37, [CJ] */ CLASS_CLOSE,
     /* HEBREW_LETTER = 38,                [HL] */ CLASS_CHARACTER,
-    /* REGIONAL_INDICATOR = 39,           [RI] */ CLASS_CHARACTER
+    /* REGIONAL_INDICATOR = 39,           [RI] */ CLASS_CHARACTER,
+#if U_ICU_VERSION_MAJOR_NUM > 57
+    /* E_BASE = 40,                       [EB] */ CLASS_BREAKABLE,
+    /* E_MODIFIER = 41,                   [EM] */ CLASS_CHARACTER,
+    /* ZWJ = 42,                          [ZWJ]*/ CLASS_CHARACTER,
+#endif
   };
 
-  return sUnicodeLineBreakToClass[mozilla::unicode::GetLineBreakClass(u)];
+#if ENABLE_INTL_API
+  static_assert(U_LB_COUNT == mozilla::ArrayLength(sUnicodeLineBreakToClass),
+                "Gecko vs ICU LineBreak class mismatch");
+#endif
+
+  auto cls = mozilla::unicode::GetLineBreakClass(u);
+  MOZ_ASSERT(cls < mozilla::ArrayLength(sUnicodeLineBreakToClass));
+  return sUnicodeLineBreakToClass[cls];
 }
 
 static bool
