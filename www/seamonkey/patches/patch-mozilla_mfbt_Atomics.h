$NetBSD: patch-mozilla_mfbt_Atomics.h,v 1.3 2014/11/02 05:40:31 ryoon Exp $

--- mozilla/mfbt/Atomics.h.orig	2014-10-14 06:36:32.000000000 +0000
+++ mozilla/mfbt/Atomics.h
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
