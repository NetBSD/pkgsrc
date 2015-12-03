$NetBSD: patch-mozilla_mfbt_Attributes.h,v 1.4 2015/12/03 12:22:27 ryoon Exp $

--- mozilla/mfbt/Attributes.h.orig	2015-11-04 01:56:08.000000000 +0000
+++ mozilla/mfbt/Attributes.h
@@ -50,6 +50,7 @@
  * don't indicate support for them here, due to
  * http://stackoverflow.com/questions/20498142/visual-studio-2013-explicit-keyword-bug
  */
+#  define MOZ_HAVE_CXX11_ALIGNAS
 #  define MOZ_HAVE_NEVER_INLINE          __declspec(noinline)
 #  define MOZ_HAVE_NORETURN              __declspec(noreturn)
 #  if _MSC_VER >= 1900
@@ -73,6 +74,9 @@
 #  ifndef __has_extension
 #    define __has_extension __has_feature /* compatibility, for older versions of clang */
 #  endif
+#  if __has_extension(cxx_alignas)
+#    define MOZ_HAVE_CXX11_ALIGNAS
+#  endif
 #  if __has_extension(cxx_constexpr)
 #    define MOZ_HAVE_CXX11_CONSTEXPR
 #  endif
@@ -89,6 +93,7 @@
 #  if defined(__GXX_EXPERIMENTAL_CXX0X__) || __cplusplus >= 201103L
 #    define MOZ_HAVE_CXX11_CONSTEXPR
 #    if MOZ_GCC_VERSION_AT_LEAST(4, 8, 0)
+#      define MOZ_HAVE_CXX11_ALIGNAS
 #      define MOZ_HAVE_CXX11_CONSTEXPR_IN_TEMPLATES
 #    endif
 #    define MOZ_HAVE_EXPLICIT_CONVERSION
