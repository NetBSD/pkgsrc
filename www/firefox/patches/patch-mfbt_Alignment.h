$NetBSD: patch-mfbt_Alignment.h,v 1.1 2014/06/19 20:31:03 martin Exp $

Make MOZ_ALIGNOF() use gcc's builtin __alignof__.
From https://bugzilla.mozilla.org/show_bug.cgi?id=1026499

--- mfbt/Alignment.h.orig	2014-06-06 03:15:37.000000000 +0200
+++ mfbt/Alignment.h	2014-06-18 18:12:22.000000000 +0200
@@ -14,6 +14,9 @@
 
 namespace mozilla {
 
+#if defined(__GNUC__)
+#define MOZ_ALIGNOF(T) __alignof__(T)
+#else
 /*
  * This class, and the corresponding macro MOZ_ALIGNOF, figures out how many
  * bytes of alignment a given type needs.
@@ -32,6 +35,7 @@
 };
 
 #define MOZ_ALIGNOF(T) mozilla::AlignmentFinder<T>::alignment
+#endif
 
 /*
  * Declare the MOZ_ALIGNED_DECL macro for declaring aligned types.

