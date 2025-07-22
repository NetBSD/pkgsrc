$NetBSD: patch-src_3rdparty_chromium_third__party_perfetto_include_perfetto_tracing_internal_track__event__data__source.h,v 1.1 2025/07/22 10:16:36 adam Exp $

Fix building with Clang.
https://github.com/google/perfetto/commit/e2f661907a717551235563389977b7468da6d45e

--- src/3rdparty/chromium/third_party/perfetto/include/perfetto/tracing/internal/track_event_data_source.h.orig	2025-07-22 06:25:53.953593549 +0000
+++ src/3rdparty/chromium/third_party/perfetto/include/perfetto/tracing/internal/track_event_data_source.h
@@ -107,7 +107,7 @@ class TrackEventDataSource
   }
 
   static void Flush() {
-    Base::template Trace([](typename Base::TraceContext ctx) { ctx.Flush(); });
+    Base::Trace([](typename Base::TraceContext ctx) { ctx.Flush(); });
   }
 
   // Determine if tracing for the given static category is enabled.
@@ -121,7 +121,7 @@ class TrackEventDataSource
   static bool IsDynamicCategoryEnabled(
       const DynamicCategory& dynamic_category) {
     bool enabled = false;
-    Base::template Trace([&](typename Base::TraceContext ctx) {
+    Base::Trace([&](typename Base::TraceContext ctx) {
       enabled = IsDynamicCategoryEnabled(&ctx, dynamic_category);
     });
     return enabled;
@@ -428,7 +428,7 @@ class TrackEventDataSource
                                  const protos::gen::TrackDescriptor& desc) {
     PERFETTO_DCHECK(track.uuid == desc.uuid());
     TrackRegistry::Get()->UpdateTrack(track, desc.SerializeAsString());
-    Base::template Trace([&](typename Base::TraceContext ctx) {
+    Base::Trace([&](typename Base::TraceContext ctx) {
       TrackEventInternal::WriteTrackDescriptor(
           track, ctx.tls_inst_->trace_writer.get());
     });
@@ -545,7 +545,7 @@ class TrackEventDataSource
   static void TraceWithInstances(uint32_t instances,
                                  Lambda lambda) PERFETTO_ALWAYS_INLINE {
     if (CategoryIndex == TrackEventCategoryRegistry::kDynamicCategoryIndex) {
-      Base::template TraceWithInstances(instances, std::move(lambda));
+      Base::TraceWithInstances(instances, std::move(lambda));
     } else {
       Base::template TraceWithInstances<
           CategoryTracePointTraits<CategoryIndex>>(instances,
@@ -560,7 +560,7 @@ class TrackEventDataSource
       const TrackType& track,
       std::function<void(protos::pbzero::TrackDescriptor*)> callback) {
     TrackRegistry::Get()->UpdateTrack(track, std::move(callback));
-    Base::template Trace([&](typename Base::TraceContext ctx) {
+    Base::Trace([&](typename Base::TraceContext ctx) {
       TrackEventInternal::WriteTrackDescriptor(
           track, ctx.tls_inst_->trace_writer.get());
     });
