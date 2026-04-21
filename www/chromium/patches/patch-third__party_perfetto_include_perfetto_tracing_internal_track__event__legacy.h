$NetBSD: patch-third__party_perfetto_include_perfetto_tracing_internal_track__event__legacy.h,v 1.18 2026/04/21 15:21:22 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/perfetto/include/perfetto/tracing/internal/track_event_legacy.h.orig	2026-04-14 23:31:37.000000000 +0200
+++ third_party/perfetto/include/perfetto/tracing/internal/track_event_legacy.h
@@ -253,7 +253,7 @@ class PERFETTO_EXPORT_COMPONENT LegacyTr
 // are different. E.g. on Mac size_t is considered a different type from
 // uint64_t even though it has the same size and signedness.
 // Below we add overloads for those types that are known to cause ambiguity.
-#if PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE)
+#if PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE) || defined(__OpenBSD__)
   explicit LegacyTraceId(size_t raw_id) : raw_id_(raw_id) {}
   explicit LegacyTraceId(intptr_t raw_id)
       : raw_id_(static_cast<uint64_t>(raw_id)) {}
