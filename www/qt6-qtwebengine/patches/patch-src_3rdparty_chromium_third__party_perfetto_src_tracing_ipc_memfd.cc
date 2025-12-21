$NetBSD: patch-src_3rdparty_chromium_third__party_perfetto_src_tracing_ipc_memfd.cc,v 1.1 2025/12/21 09:38:44 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/third_party/perfetto/src/tracing/ipc/memfd.cc.orig	2025-10-02 00:36:39.000000000 +0000
+++ src/3rdparty/chromium/third_party/perfetto/src/tracing/ipc/memfd.cc
@@ -20,7 +20,8 @@
 
 #define PERFETTO_MEMFD_ENABLED()             \
   PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID) || \
-  PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX_BUT_NOT_QNX)
+  (PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX_BUT_NOT_QNX) && \
+   !PERFETTO_BUILDFLAG(PERFETTO_OS_BSD))
 
 #if PERFETTO_MEMFD_ENABLED()
 
