$NetBSD: patch-stddef.h,v 1.1 2025/02/14 07:00:15 vins Exp $

Silence makedepend warnings:
`#error __PTRDIFF_TYPE__ not present'

--- stddef.h.orig	2025-02-14 05:27:20.805605781 +0000
+++ stddef.h
@@ -0,0 +1,30 @@
+/*
+ * stddef.h
+ *
+ * Prepocessor defined type definitions.
+ *
+ */
+
+#ifndef __PTRDIFF_TYPE__
+#define __PTRDIFF_TYPE__ long int
+#endif
+typedef __PTRDIFF_TYPE__ ptrdiff_t;
+
+#ifndef __SIZE_TYPE__
+#define __SIZE_TYPE__ long unsigned int
+#endif
+#if !(defined (__GNUG__) && defined (size_t))
+typedef __SIZE_TYPE__ size_t;
+#endif
+
+#ifndef __WCHAR_TYPE__
+#define __WCHAR_TYPE__ int
+#endif
+#ifndef __cplusplus
+typedef __WCHAR_TYPE__ wchar_t;
+#endif
+
+#ifndef __WINT_TYPE__
+#define __WINT_TYPE__ unsigned int
+#endif
+typedef __WINT_TYPE__ wint_t;
