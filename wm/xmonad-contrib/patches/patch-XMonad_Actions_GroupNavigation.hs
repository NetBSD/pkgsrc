$NetBSD: patch-XMonad_Actions_GroupNavigation.hs,v 1.1 2023/10/28 20:30:25 pho Exp $

Prelude doesn't export >=>. No idea why it worked before.

--- XMonad/Actions/GroupNavigation.hs.orig	2023-10-28 20:25:50.601702893 +0000
+++ XMonad/Actions/GroupNavigation.hs
@@ -33,6 +33,7 @@ module XMonad.Actions.GroupNavigation ( 
                                       , isOnAnyVisibleWS
                                       ) where
 
+import Control.Monad ((>=>))
 import Control.Monad.Reader
 import Control.Monad.State
 import Control.DeepSeq
