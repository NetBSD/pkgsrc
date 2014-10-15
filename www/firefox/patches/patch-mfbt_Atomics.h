$NetBSD: patch-mfbt_Atomics.h,v 1.3 2014/10/15 13:43:32 ryoon Exp $

--- mfbt/Atomics.h.orig	2014-10-11 09:06:41.000000000 +0000
+++ mfbt/Atomics.h
@@ -34,10 +34,12 @@
     * loose typing of the atomic builtins. GCC 4.5 and 4.6 lacks inline
     * definitions for unspecialized std::atomic and causes linking errors.
     * Therefore, we require at least 4.7.0 for using libstdc++.
+    *
+    * libc++ <atomic> is only functional with clang.
     */
 #  if MOZ_USING_LIBSTDCXX && MOZ_LIBSTDCXX_VERSION_AT_LEAST(4, 7, 0)
 #    define MOZ_HAVE_CXX11_ATOMICS
-#  elif MOZ_USING_LIBCXX
+#  elif MOZ_USING_LIBCXX && defined(__clang__)
 #    define MOZ_HAVE_CXX11_ATOMICS
 #  endif
 #elif defined(_MSC_VER) && _MSC_VER >= 1700
