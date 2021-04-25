$NetBSD: patch-XMonad_Actions_GridSelect.hs,v 1.1 2021/04/25 14:32:12 pho Exp $

Fix build with GHC 9. "as-pattern" can no longer be surrounded by
whitespace because it's going to make an ambiguity with dependent
Haskell.

--- XMonad/Actions/GridSelect.hs.orig	2021-04-25 14:23:05.054475749 +0000
+++ XMonad/Actions/GridSelect.hs
@@ -394,7 +394,7 @@ updateElementsWithColorizer colorizer el
 stdHandle :: Event -> TwoD a (Maybe a) -> TwoD a (Maybe a)
 stdHandle (ButtonEvent { ev_event_type = t, ev_x = x, ev_y = y }) contEventloop
     | t == buttonRelease = do
-        s @  TwoDState { td_paneX = px, td_paneY = py,
+        s@TwoDState { td_paneX = px, td_paneY = py,
                          td_gsconfig = (GSConfig ch cw _ _ _ _ _ _ _ _) } <- get
         let gridX = (fi x - (px - cw) `div` 2) `div` cw
             gridY = (fi y - (py - ch) `div` 2) `div` ch
