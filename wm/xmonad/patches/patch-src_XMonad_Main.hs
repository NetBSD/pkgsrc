$NetBSD: patch-src_XMonad_Main.hs,v 1.1 2021/04/25 14:19:34 pho Exp $

Fix build with GHC 9. "as-pattern" can no longer be surrounded by
whitespace because it's going to make an ambiguity with dependent
Haskell.

--- src/XMonad/Main.hs.orig	2021-04-25 14:11:38.974316759 +0000
+++ src/XMonad/Main.hs
@@ -61,7 +61,7 @@ xmonad conf = do
 
     let launch' args = do
               catchIO buildLaunch
-              conf' @ XConfig { layoutHook = Layout l }
+              conf'@XConfig { layoutHook = Layout l }
                   <- handleExtraArgs conf args conf{ layoutHook = Layout (layoutHook conf) }
               withArgs [] $ launch (conf' { layoutHook = l })
 
