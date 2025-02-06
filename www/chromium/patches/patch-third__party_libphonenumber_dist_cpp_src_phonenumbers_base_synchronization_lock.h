$NetBSD: patch-third__party_libphonenumber_dist_cpp_src_phonenumbers_base_synchronization_lock.h,v 1.1 2025/02/06 09:58:26 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/libphonenumber/dist/cpp/src/phonenumbers/base/synchronization/lock.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ third_party/libphonenumber/dist/cpp/src/phonenumbers/base/synchronization/lock.h
@@ -22,7 +22,8 @@
 #elif (__cplusplus >= 201103L) && defined(I18N_PHONENUMBERS_USE_STDMUTEX)
 // C++11 Lock implementation based on std::mutex.
 #include "phonenumbers/base/synchronization/lock_stdmutex.h"
-#elif defined(__linux__) || defined(__APPLE__) || defined(I18N_PHONENUMBERS_HAVE_POSIX_THREAD)
+#elif defined(__linux__) || defined(__APPLE__) || defined(__OpenBSD__) || defined(__FreeBSD__) || \
+  defined(__NetBSD__) || defined(I18N_PHONENUMBERS_HAVE_POSIX_THREAD)
 #include "phonenumbers/base/synchronization/lock_posix.h"
 #elif defined(WIN32)
 #include "phonenumbers/base/synchronization/lock_win32.h"
