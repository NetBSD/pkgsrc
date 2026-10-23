$NetBSD: patch-third__party_perfetto_src_base_clock__snapshots.cc,v 1.31 2026/10/23 15:05:35 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/perfetto/src/base/clock_snapshots.cc.orig	2026-10-19 20:07:21.000000000 +0000
+++ third_party/perfetto/src/base/clock_snapshots.cc
@@ -27,6 +27,8 @@ ClockSnapshotVector CaptureClockSnapshot
 #if !PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE) &&   \
     !PERFETTO_BUILDFLAG(PERFETTO_OS_WIN) &&     \
     !PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD) && \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_OPENBSD) && \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_NETBSD) && \
     !PERFETTO_BUILDFLAG(PERFETTO_OS_NACL) &&    \
     !PERFETTO_BUILDFLAG(PERFETTO_OS_QNX)
   struct {
