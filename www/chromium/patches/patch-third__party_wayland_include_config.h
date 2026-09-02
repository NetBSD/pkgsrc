$NetBSD: patch-third__party_wayland_include_config.h,v 1.25 2026/09/02 13:13:38 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/wayland/include/config.h.orig	2026-08-31 22:47:51.000000000 +0000
+++ third_party/wayland/include/config.h
@@ -9,13 +9,26 @@
 
 #define HAVE_BROKEN_MSG_CMSG_CLOEXEC 0
 
+#if defined(__FreeBSD__)
+#include <osreldate.h>
+#if defined(__FreeBSD_version) && __FreeBSD_version < 1300048
+#undef HAVE_MEMFD_CREATE
+#elif defined(__NetBSD__)
+#undef HAVE_MEMFD_CREATE
+#else
 #define HAVE_MEMFD_CREATE
+#endif
+#endif
 
 #define HAVE_MKOSTEMP
 
 #define HAVE_MREMAP
 
+#if defined(__NetBSD__)
+#undef HAVE_POSIX_FALLOCATE
+#else
 #define HAVE_POSIX_FALLOCATE
+#endif
 
 #define HAVE_PRCTL
 
@@ -25,7 +38,11 @@
 
 #undef HAVE_SYS_PROCCTL_H
 
+#if defined(__FreeBSD__)
+#define HAVE_SYS_UCRED_H
+#else
 #undef HAVE_SYS_UCRED_H
+#endif
 
 #define HAVE_XUCRED_CR_PID 0
 
