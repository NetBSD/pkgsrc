$NetBSD: patch-XMonad_Util_PureX.hs,v 1.1 2023/10/28 20:30:25 pho Exp $

Prelude no longer exports void or join.

--- XMonad/Util/PureX.hs.orig	2023-10-28 20:24:11.741267584 +0000
+++ XMonad/Util/PureX.hs
@@ -58,6 +58,7 @@ import qualified XMonad.StackSet as W
 import qualified XMonad.Actions.FocusNth
 
 -- mtl
+import Control.Monad (void, join)
 import Control.Monad.State
 import Control.Monad.Reader
 
