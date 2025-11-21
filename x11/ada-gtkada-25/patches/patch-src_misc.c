$NetBSD: patch-src_misc.c,v 1.1 2025/11/21 13:23:22 dkazankov Exp $

Use C preprocessed symbols on NetBSD

--- src/misc.c.orig	2024-06-27 11:52:46.000000000 +0300
+++ src/misc.c
@@ -2227,3 +2227,12 @@
 const GVariantType* ada_gvariant_type_uint64  = G_VARIANT_TYPE_UINT64;
 const GVariantType* ada_gvariant_type_double  = G_VARIANT_TYPE_DOUBLE;
 const GVariantType* ada_gvariant_type_string  = G_VARIANT_TYPE_STRING;
+
+#ifdef __NetBSD__
+
+#include <locale.h>
+char * __netbsd_setlocale (int category, const char *locale) {
+  return setlocale (category, locale);
+}
+
+#endif
