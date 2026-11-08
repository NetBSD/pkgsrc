$NetBSD: patch-third__party_perfetto_src_tracing_ipc_memfd.h,v 1.1 2026/11/08 15:39:11 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/perfetto/src/tracing/ipc/memfd.h.orig	2026-11-02 23:22:33.000000000 +0000
+++ third_party/perfetto/src/tracing/ipc/memfd.h
@@ -24,7 +24,8 @@
 // The build has the memfd code. HasMemfdSupport() also checks the kernel.
 #define PERFETTO_MEMFD_ENABLED()              \
   (PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID) || \
-   PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX_BUT_NOT_QNX))
+  (PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX_BUT_NOT_QNX) && \
+  !PERFETTO_BUILDFLAG(PERFETTO_OS_BSD)))
 
 // Some android build bots use a sysroot that doesn't support memfd when
 // compiling for the host, so we define the flags we need ourselves.
