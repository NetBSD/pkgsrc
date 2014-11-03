$NetBSD: patch-mfbt_Attributes.h,v 1.1 2014/11/03 12:18:32 ryoon Exp $

--- mfbt/Attributes.h.orig	2014-07-17 01:45:32.000000000 +0000
+++ mfbt/Attributes.h
@@ -54,6 +54,9 @@
 #  ifndef __has_extension
 #    define __has_extension __has_feature /* compatibility, for older versions of clang */
 #  endif
+#  if __has_extension(cxx_alignas)
+#    define MOZ_HAVE_CXX11_ALIGNAS
+#  endif
 #  if __has_extension(cxx_constexpr)
 #    define MOZ_HAVE_CXX11_CONSTEXPR
 #  endif
@@ -75,6 +78,9 @@
 #  endif
 #elif defined(__GNUC__)
 #  if defined(__GXX_EXPERIMENTAL_CXX0X__) || __cplusplus >= 201103L
+#    if MOZ_GCC_VERSION_AT_LEAST(4, 8, 0)
+#      define MOZ_HAVE_CXX11_ALIGNAS
+#    endif
 #    if MOZ_GCC_VERSION_AT_LEAST(4, 7, 0)
 #      define MOZ_HAVE_CXX11_OVERRIDE
 #      define MOZ_HAVE_CXX11_FINAL       final
@@ -96,6 +102,7 @@
 #  define MOZ_HAVE_NORETURN              __attribute__((noreturn))
 #elif defined(_MSC_VER)
 #  if _MSC_VER >= 1800
+#    define MOZ_HAVE_CXX11_ALIGNAS
 #    define MOZ_HAVE_CXX11_DELETE
 #  endif
 #  if _MSC_VER >= 1700
