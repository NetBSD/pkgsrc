$NetBSD: patch-third__party_libphonenumber_dist_cpp_src_phonenumbers_base_memory_singleton.h,v 1.14 2026/01/19 16:14:20 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/libphonenumber/dist/cpp/src/phonenumbers/base/memory/singleton.h.orig	2026-01-07 00:50:30.000000000 +0000
+++ third_party/libphonenumber/dist/cpp/src/phonenumbers/base/memory/singleton.h
@@ -22,7 +22,8 @@
 #elif (__cplusplus >= 201103L) && defined(I18N_PHONENUMBERS_USE_STDMUTEX)
 // C++11 Lock implementation based on std::mutex.
 #include "phonenumbers/base/memory/singleton_stdmutex.h"
-#elif defined(__linux__) || defined(__APPLE__) || defined(I18N_PHONENUMBERS_HAVE_POSIX_THREAD)
+#elif defined(__linux__) || defined(__APPLE__) || defined(__OpenBSD__) || defined(__FreeBSD__) || \
+    defined(__NetBSD__) || defined(I18N_PHONENUMBERS_HAVE_POSIX_THREAD)
 #include "phonenumbers/base/memory/singleton_posix.h"
 #elif defined(WIN32)
 #include "phonenumbers/base/memory/singleton_win32.h"
