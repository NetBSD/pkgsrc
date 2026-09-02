$NetBSD: patch-third__party_perfetto_src_tracing_ipc_memfd.cc,v 1.25 2026/09/02 13:13:37 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/perfetto/src/tracing/ipc/memfd.cc.orig	2026-08-31 22:47:51.000000000 +0000
+++ third_party/perfetto/src/tracing/ipc/memfd.cc
@@ -20,7 +20,8 @@
 
 #define PERFETTO_MEMFD_ENABLED()             \
   PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID) || \
-      PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX_BUT_NOT_QNX)
+  (PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX_BUT_NOT_QNX) && \
+  !PERFETTO_BUILDFLAG(PERFETTO_OS_BSD))
 
 #if PERFETTO_MEMFD_ENABLED()
 
