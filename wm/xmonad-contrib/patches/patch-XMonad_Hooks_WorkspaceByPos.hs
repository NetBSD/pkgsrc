$NetBSD: patch-XMonad_Hooks_WorkspaceByPos.hs,v 1.1 2023/10/28 20:30:25 pho Exp $

Control.Monad.Except no longer exports lift.

--- XMonad/Hooks/WorkspaceByPos.hs.orig	2023-10-28 20:20:33.648633472 +0000
+++ XMonad/Hooks/WorkspaceByPos.hs
@@ -26,7 +26,8 @@ import XMonad
 import XMonad.Prelude
 import qualified XMonad.StackSet as W
 
-import Control.Monad.Except (lift, runExceptT, throwError)
+import Control.Monad.Except (runExceptT, throwError)
+import Control.Monad.Trans.Class (lift)
 
 -- $usage
 -- You can use this module with the following in your @~\/.xmonad\/xmonad.hs@:
