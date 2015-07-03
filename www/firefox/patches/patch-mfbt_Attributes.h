$NetBSD: patch-mfbt_Attributes.h,v 1.5 2015/07/03 10:25:40 ryoon Exp $

--- mfbt/Attributes.h.orig	2015-06-18 20:55:34.000000000 +0000
+++ mfbt/Attributes.h
@@ -50,6 +50,7 @@
  * don't indicate support for them here, due to
  * http://stackoverflow.com/questions/20498142/visual-studio-2013-explicit-keyword-bug
  */
+#  define MOZ_HAVE_CXX11_ALIGNAS
 #  define MOZ_HAVE_NEVER_INLINE          __declspec(noinline)
 #  define MOZ_HAVE_NORETURN              __declspec(noreturn)
 #  ifdef __clang__
@@ -70,6 +71,9 @@
 #  ifndef __has_extension
 #    define __has_extension __has_feature /* compatibility, for older versions of clang */
 #  endif
+#  if __has_extension(cxx_alignas)
+#    define MOZ_HAVE_CXX11_ALIGNAS
+#  endif
 #  if __has_extension(cxx_constexpr)
 #    define MOZ_HAVE_CXX11_CONSTEXPR
 #  endif
@@ -86,6 +90,7 @@
 #  if defined(__GXX_EXPERIMENTAL_CXX0X__) || __cplusplus >= 201103L
 #    define MOZ_HAVE_CXX11_CONSTEXPR
 #    if MOZ_GCC_VERSION_AT_LEAST(4, 8, 0)
+#      define MOZ_HAVE_CXX11_ALIGNAS
 #      define MOZ_HAVE_CXX11_CONSTEXPR_IN_TEMPLATES
 #    endif
 #    define MOZ_HAVE_EXPLICIT_CONVERSION
