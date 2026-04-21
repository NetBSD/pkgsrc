$NetBSD: patch-third__party_perfetto_src_base_clock__snapshots.cc,v 1.18 2026/04/21 15:21:22 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/perfetto/src/base/clock_snapshots.cc.orig	2026-04-14 23:31:37.000000000 +0200
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
