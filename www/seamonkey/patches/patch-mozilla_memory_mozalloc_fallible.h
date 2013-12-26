$NetBSD: patch-mozilla_memory_mozalloc_fallible.h,v 1.1 2013/12/26 13:17:37 ryoon Exp $

--- mozilla/memory/mozalloc/fallible.h.orig	2013-12-11 04:29:01.000000000 +0000
+++ mozilla/memory/mozalloc/fallible.h
@@ -5,9 +5,22 @@
 #ifndef mozilla_fallible_h
 #define mozilla_fallible_h
 
+#if defined(MOZALLOC_EXPORT)
+/* do nothing: it's been defined to __declspec(dllexport) by
+ * mozalloc*.cpp on platforms where that's required. */
+#elif defined(XP_WIN) || (defined(XP_OS2) && defined(__declspec))
+#  define MOZALLOC_EXPORT __declspec(dllimport)
+#elif defined(HAVE_VISIBILITY_ATTRIBUTE)
+/* Make sure symbols are still exported even if we're wrapped in a
+ * |visibility push(hidden)| blanket. */
+#  define MOZALLOC_EXPORT __attribute__ ((visibility ("default")))
+#else
+#  define MOZALLOC_EXPORT
+#endif
+
 namespace mozilla {
 
-struct fallible_t { };
+struct MOZALLOC_EXPORT fallible_t { };
 
 } // namespace mozilla
 
