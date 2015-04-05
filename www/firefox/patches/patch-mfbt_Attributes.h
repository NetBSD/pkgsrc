$NetBSD: patch-mfbt_Attributes.h,v 1.3 2015/04/05 12:54:12 ryoon Exp $

--- mfbt/Attributes.h.orig	2015-03-27 02:20:26.000000000 +0000
+++ mfbt/Attributes.h
@@ -50,6 +50,7 @@
  * don't indicate support for them here, due to
  * http://stackoverflow.com/questions/20498142/visual-studio-2013-explicit-keyword-bug
  */
+#  define MOZ_HAVE_CXX11_ALIGNAS
 #  define MOZ_HAVE_CXX11_FINAL         final
 #  define MOZ_HAVE_CXX11_OVERRIDE
 #  define MOZ_HAVE_NEVER_INLINE          __declspec(noinline)
@@ -72,6 +73,9 @@
 #  ifndef __has_extension
 #    define __has_extension __has_feature /* compatibility, for older versions of clang */
 #  endif
+#  if __has_extension(cxx_alignas)
+#    define MOZ_HAVE_CXX11_ALIGNAS
+#  endif
 #  if __has_extension(cxx_constexpr)
 #    define MOZ_HAVE_CXX11_CONSTEXPR
 #  endif
@@ -90,6 +94,9 @@
 #  endif
 #elif defined(__GNUC__)
 #  if defined(__GXX_EXPERIMENTAL_CXX0X__) || __cplusplus >= 201103L
+#    if MOZ_GCC_VERSION_AT_LEAST(4, 8, 0)
+#      define MOZ_HAVE_CXX11_ALIGNAS
+#    endif
 #    if MOZ_GCC_VERSION_AT_LEAST(4, 7, 0)
 #      define MOZ_HAVE_CXX11_OVERRIDE
 #      define MOZ_HAVE_CXX11_FINAL       final
