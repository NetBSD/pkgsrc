$NetBSD: patch-third__party_perfetto_include_perfetto_ext_base_futex.h,v 1.1 2026/11/08 15:39:11 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/perfetto/include/perfetto/ext/base/futex.h.orig	2026-11-02 23:22:33.000000000 +0000
+++ third_party/perfetto/include/perfetto/ext/base/futex.h
@@ -26,7 +26,8 @@
 // TODO(rsavitski): Add support for other platforms.
 #define PERFETTO_HAS_FUTEX()                            \
   (PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX_BUT_NOT_QNX) || \
-   PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID))
+   PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)) && \
+   !PERFETTO_BUILDFLAG(PERFETTO_OS_NETBSD)
 
 namespace perfetto::base {
 
