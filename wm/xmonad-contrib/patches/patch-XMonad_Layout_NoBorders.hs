$NetBSD: patch-XMonad_Layout_NoBorders.hs,v 1.1 2021/04/25 14:32:12 pho Exp $

Fix build with GHC 9. Data.List now exports 'singleton' which
conflicts with a function defined in this module.

--- XMonad/Layout/NoBorders.hs.orig	2021-04-25 14:24:34.138776187 +0000
+++ XMonad/Layout/NoBorders.hs
@@ -38,7 +38,7 @@ import           XMonad.Layout.LayoutMod
 import qualified XMonad.StackSet                as W
 import qualified XMonad.Util.Rectangle          as R
 
-import           Data.List
+import           Data.List                      ((\\), union, delete, intersect)
 import           Data.Monoid
 import qualified Data.Map                       as M
 import           Data.Function                  (on)
