$NetBSD: patch-mozilla_mfbt_Attributes.h,v 1.1 2014/11/02 05:40:31 ryoon Exp $

--- mozilla/mfbt/Attributes.h.orig	2014-10-14 06:36:32.000000000 +0000
+++ mozilla/mfbt/Attributes.h
@@ -51,6 +51,7 @@
  * http://stackoverflow.com/questions/20498142/visual-studio-2013-explicit-keyword-bug
  */
 #  if _MSC_VER >= 1800
+#    define MOZ_HAVE_CXX11_ALIGNAS
 #    define MOZ_HAVE_CXX11_DELETE
 #  endif
 #  if _MSC_VER >= 1700
@@ -74,6 +75,9 @@
 #  ifndef __has_extension
 #    define __has_extension __has_feature /* compatibility, for older versions of clang */
 #  endif
+#  if __has_extension(cxx_alignas)
+#    define MOZ_HAVE_CXX11_ALIGNAS
+#  endif
 #  if __has_extension(cxx_constexpr)
 #    define MOZ_HAVE_CXX11_CONSTEXPR
 #  endif
@@ -95,6 +99,9 @@
 #  endif
 #elif defined(__GNUC__)
 #  if defined(__GXX_EXPERIMENTAL_CXX0X__) || __cplusplus >= 201103L
+#    if MOZ_GCC_VERSION_AT_LEAST(4, 8, 0)
+#      define MOZ_HAVE_CXX11_ALIGNAS
+#    endif
 #    if MOZ_GCC_VERSION_AT_LEAST(4, 7, 0)
 #      define MOZ_HAVE_CXX11_OVERRIDE
 #      define MOZ_HAVE_CXX11_FINAL       final
