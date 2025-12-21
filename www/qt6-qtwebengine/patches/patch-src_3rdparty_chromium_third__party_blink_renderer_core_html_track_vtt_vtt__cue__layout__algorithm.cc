$NetBSD: patch-src_3rdparty_chromium_third__party_blink_renderer_core_html_track_vtt_vtt__cue__layout__algorithm.cc,v 1.1 2025/12/21 09:38:39 markd Exp $

--- src/3rdparty/chromium/third_party/blink/renderer/core/html/track/vtt/vtt_cue_layout_algorithm.cc.orig	2024-11-21 04:36:37.000000000 +0000
+++ src/3rdparty/chromium/third_party/blink/renderer/core/html/track/vtt/vtt_cue_layout_algorithm.cc
@@ -72,7 +72,7 @@ void VttCueLayoutAlgorithm::Layout() {
   // https://w3c.github.io/webvtt/#apply-webvtt-cue-settings
   // 10. Adjust the positions of boxes according to the appropriate steps
   // from the following list:
-  if (isfinite(snap_to_lines_position_)) {
+  if (std::isfinite(snap_to_lines_position_)) {
     // ↪ If cue’s WebVTT cue snap-to-lines flag is true
     AdjustPositionWithSnapToLines();
   } else {
@@ -104,7 +104,7 @@ PhysicalSize VttCueLayoutAlgorithm::Firs
 LayoutUnit VttCueLayoutAlgorithm::ComputeInitialPositionAdjustment(
     LayoutUnit max_dimension,
     const gfx::Rect& controls_rect) {
-  DCHECK(isfinite(snap_to_lines_position_));
+  DCHECK(std::isfinite(snap_to_lines_position_));
 
   // 4. Let line be cue's computed line.
   // 5. Round line to an integer by adding 0.5 and then flooring it.
