$NetBSD: patch-third__party_perfetto_src_trace__processor_importers_ftrace_v4l2__tracker.cc,v 1.1 2025/02/06 09:58:27 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/perfetto/src/trace_processor/importers/ftrace/v4l2_tracker.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ third_party/perfetto/src/trace_processor/importers/ftrace/v4l2_tracker.cc
@@ -62,7 +62,7 @@ void V4l2Tracker::ParseV4l2Event(uint64_
     case FtraceEvent::kV4l2QbufFieldNumber: {
       V4l2QbufFtraceEvent::Decoder pb_evt(bytes.data, bytes.size);
       BufferEvent evt;
-      evt.device_minor = pb_evt.minor();
+      evt.device_minor = pb_evt.gminor();
       evt.index = pb_evt.index();
       evt.type = pb_evt.type();
       evt.bytesused = pb_evt.bytesused();
@@ -103,7 +103,7 @@ void V4l2Tracker::ParseV4l2Event(uint64_
     case FtraceEvent::kV4l2DqbufFieldNumber: {
       V4l2DqbufFtraceEvent::Decoder pb_evt(bytes.data, bytes.size);
       BufferEvent evt;
-      evt.device_minor = pb_evt.minor();
+      evt.device_minor = pb_evt.gminor();
       evt.index = pb_evt.index();
       evt.type = pb_evt.type();
       evt.bytesused = pb_evt.bytesused();
@@ -149,7 +149,7 @@ void V4l2Tracker::ParseV4l2Event(uint64_
     case FtraceEvent::kVb2V4l2BufQueueFieldNumber: {
       Vb2V4l2BufQueueFtraceEvent::Decoder pb_evt(bytes.data, bytes.size);
       BufferEvent evt;
-      evt.device_minor = pb_evt.minor();
+      evt.device_minor = pb_evt.gminor();
       evt.index = std::nullopt;
       evt.type = std::nullopt;
       evt.bytesused = std::nullopt;
@@ -180,7 +180,7 @@ void V4l2Tracker::ParseV4l2Event(uint64_
     case FtraceEvent::kVb2V4l2BufDoneFieldNumber: {
       Vb2V4l2BufDoneFtraceEvent::Decoder pb_evt(bytes.data, bytes.size);
       BufferEvent evt;
-      evt.device_minor = pb_evt.minor();
+      evt.device_minor = pb_evt.gminor();
       evt.index = std::nullopt;
       evt.type = std::nullopt;
       evt.bytesused = std::nullopt;
@@ -211,7 +211,7 @@ void V4l2Tracker::ParseV4l2Event(uint64_
     case FtraceEvent::kVb2V4l2QbufFieldNumber: {
       Vb2V4l2QbufFtraceEvent::Decoder pb_evt(bytes.data, bytes.size);
       BufferEvent evt;
-      evt.device_minor = pb_evt.minor();
+      evt.device_minor = pb_evt.gminor();
       evt.index = std::nullopt;
       evt.type = std::nullopt;
       evt.bytesused = std::nullopt;
@@ -242,7 +242,7 @@ void V4l2Tracker::ParseV4l2Event(uint64_
     case FtraceEvent::kVb2V4l2DqbufFieldNumber: {
       Vb2V4l2DqbufFtraceEvent::Decoder pb_evt(bytes.data, bytes.size);
       BufferEvent evt;
-      evt.device_minor = pb_evt.minor();
+      evt.device_minor = pb_evt.gminor();
       evt.index = std::nullopt;
       evt.type = std::nullopt;
       evt.bytesused = std::nullopt;
