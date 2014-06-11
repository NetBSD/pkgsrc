$NetBSD: patch-layout_base_nsCSSRendering.cpp,v 1.1 2014/06/11 00:41:36 ryoon Exp $

--- layout/base/nsCSSRendering.cpp.orig	2014-05-29 23:31:05.000000000 +0000
+++ layout/base/nsCSSRendering.cpp
@@ -419,6 +419,10 @@ nsCSSRendering::PaintBorder(nsPresContex
   }
 
   nsStyleBorder newStyleBorder(*styleBorder);
+  // We could do something fancy to avoid the TrackImage/UntrackImage
+  // work, but it doesn't seem worth it.  (We need to call TrackImage
+  // since we're not going through nsRuleNode::ComputeBorderData.)
+  newStyleBorder.TrackImage(aPresContext);
 
   NS_FOR_CSS_SIDES(side) {
     newStyleBorder.SetBorderColor(side,
@@ -428,6 +432,11 @@ nsCSSRendering::PaintBorder(nsPresContex
   PaintBorderWithStyleBorder(aPresContext, aRenderingContext, aForFrame,
                              aDirtyRect, aBorderArea, newStyleBorder,
                              aStyleContext, aSkipSides);
+
+  // We could do something fancy to avoid the TrackImage/UntrackImage
+  // work, but it doesn't seem worth it.  (We need to call UntrackImage
+  // since we're not going through nsStyleBorder::Destroy.)
+  newStyleBorder.UntrackImage(aPresContext);
 }
 
 void
