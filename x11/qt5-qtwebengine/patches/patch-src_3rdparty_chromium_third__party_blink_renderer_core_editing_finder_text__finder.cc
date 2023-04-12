$NetBSD: patch-src_3rdparty_chromium_third__party_blink_renderer_core_editing_finder_text__finder.cc,v 1.1 2023/04/12 19:24:06 adam Exp $

https://github.com/macports/macports-ports/pull/16605

--- src/3rdparty/chromium/third_party/blink/renderer/core/editing/finder/text_finder.cc.orig	2023-04-11 15:10:26.000000000 +0000
+++ src/3rdparty/chromium/third_party/blink/renderer/core/editing/finder/text_finder.cc
@@ -629,7 +629,12 @@ gfx::RectF TextFinder::ActiveFindMatchRe
   if (!current_active_match_frame_ || !active_match_)
     return gfx::RectF();
 
+#ifdef __APPLE__
+  CGRect r = FindInPageRectFromRange(EphemeralRange(ActiveMatch()));
+  return gfx::RectF(r);
+#else
   return gfx::RectF(FindInPageRectFromRange(EphemeralRange(ActiveMatch())));
+#endif
 }
 
 Vector<gfx::RectF> TextFinder::FindMatchRects() {
@@ -639,7 +644,12 @@ Vector<gfx::RectF> TextFinder::FindMatch
   match_rects.ReserveCapacity(match_rects.size() + find_matches_cache_.size());
   for (const FindMatch& match : find_matches_cache_) {
     DCHECK(!match.rect_.IsEmpty());
+#ifdef __APPLE__
+    CGRect r = match.rect_;
+    match_rects.push_back(r);
+#else
     match_rects.push_back(match.rect_);
+#endif
   }
 
   return match_rects;
