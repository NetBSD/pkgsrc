$NetBSD: patch-third__party_perfetto_src_base_clock__snapshots.cc,v 1.13 2025/12/23 13:22:25 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/perfetto/src/base/clock_snapshots.cc.orig	2025-12-17 23:05:18.000000000 +0000
+++ third_party/perfetto/src/base/clock_snapshots.cc
@@ -27,6 +27,7 @@ ClockSnapshotVector CaptureClockSnapshot
 #if !PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE) && \
     !PERFETTO_BUILDFLAG(PERFETTO_OS_WIN) &&   \
     !PERFETTO_BUILDFLAG(PERFETTO_OS_NACL) &&  \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_BSD) &&  \
     !PERFETTO_BUILDFLAG(PERFETTO_OS_QNX)
   struct {
     clockid_t id;
