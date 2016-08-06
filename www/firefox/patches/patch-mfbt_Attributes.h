$NetBSD: patch-mfbt_Attributes.h,v 1.7 2016/08/06 08:46:59 ryoon Exp $

--- mfbt/Attributes.h.orig	2016-07-25 20:22:04.000000000 +0000
+++ mfbt/Attributes.h
@@ -50,6 +50,7 @@
  * don't indicate support for them here, due to
  * http://stackoverflow.com/questions/20498142/visual-studio-2013-explicit-keyword-bug
  */
+#  define MOZ_HAVE_CXX11_ALIGNAS
 #  define MOZ_HAVE_NEVER_INLINE          __declspec(noinline)
 #  define MOZ_HAVE_NORETURN              __declspec(noreturn)
 #  if _MSC_VER >= 1900
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
