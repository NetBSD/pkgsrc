$NetBSD: patch-mozilla_mfbt_Alignment.h,v 1.2 2015/12/03 12:22:27 ryoon Exp $

--- mozilla/mfbt/Alignment.h.orig	2015-11-04 01:56:08.000000000 +0000
+++ mozilla/mfbt/Alignment.h
@@ -15,6 +15,13 @@
 
 namespace mozilla {
 
+#if defined(MOZ_HAVE_CXX11_ALIGNAS)
+#define MOZ_ALIGNOF(T) alignof(T)
+#elif defined(__GNUC__)
+#define MOZ_ALIGNOF(T) __alignof__(T)
+#elif defined(_MSC_VER)
+#define MOZ_ALIGNOF(T) __alignof(T)
+#else
 /*
  * This class, and the corresponding macro MOZ_ALIGNOF, figures out how many
  * bytes of alignment a given type needs.
@@ -33,6 +40,7 @@ public:
 };
 
 #define MOZ_ALIGNOF(T) mozilla::AlignmentFinder<T>::alignment
+#endif
 
 /*
  * Declare the MOZ_ALIGNED_DECL macro for declaring aligned types.
@@ -44,7 +52,10 @@ public:
  * will declare a two-character array |arr| aligned to 8 bytes.
  */
 
-#if defined(__GNUC__)
+#if defined(MOZ_HAVE_CXX11_ALIGNAS)
+#  define MOZ_ALIGNED_DECL(_type, _align) \
+     alignas(_align) _type
+#elif defined(__GNUC__)
 #  define MOZ_ALIGNED_DECL(_type, _align) \
      _type __attribute__((aligned(_align)))
 #elif defined(_MSC_VER)
