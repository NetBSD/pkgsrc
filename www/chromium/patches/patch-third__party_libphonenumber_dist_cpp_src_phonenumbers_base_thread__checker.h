$NetBSD: patch-third__party_libphonenumber_dist_cpp_src_phonenumbers_base_thread__checker.h,v 1.14 2026/01/19 16:14:20 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/libphonenumber/dist/cpp/src/phonenumbers/base/thread_checker.h.orig	2026-01-07 00:50:30.000000000 +0000
+++ third_party/libphonenumber/dist/cpp/src/phonenumbers/base/thread_checker.h
@@ -22,8 +22,8 @@
 // Note that I18N_PHONENUMBERS_NO_THREAD_SAFETY must be defined only to let the
 // user of the library know that it can't be used in a thread-safe manner when
 // it is not depending on Boost.
-#if !defined(__linux__) && !defined(__APPLE__) && !defined(I18N_PHONENUMBERS_HAVE_POSIX_THREAD) && \
-    !defined(I18N_PHONENUMBERS_NO_THREAD_SAFETY) && \
+#if !defined(__linux__) && !defined(__APPLE__) && !defined(__OpenBSD__) && !defined(__FreeBSD__) && !defined(I18N_PHONENUMBERS_HAVE_POSIX_THREAD) && \
+    !defined(__NetBSD__) && !defined(I18N_PHONENUMBERS_NO_THREAD_SAFETY) && \
 	!((__cplusplus >= 201103L) && defined(I18N_PHONENUMBERS_USE_STDMUTEX)) && \
 	!defined(WIN32)
 #error Building without Boost, please provide \
@@ -33,7 +33,8 @@
 #endif
 
 #if !defined(NDEBUG) && !defined(I18N_PHONENUMBERS_USE_BOOST) && \
-    (defined(__linux__) || defined(__APPLE__) || defined(I18N_PHONENUMBERS_HAVE_POSIX_THREAD))
+    (defined(__linux__) || defined(__APPLE__) || defined(__OpenBSD__) || defined(__FreeBSD__) || \
+    defined(__NetBSD__) || defined(I18N_PHONENUMBERS_HAVE_POSIX_THREAD))
 
 #include <pthread.h>
 
