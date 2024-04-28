$NetBSD: patch-lib_Web_Browser.hs,v 1.1 2024/04/28 12:12:55 pho Exp $

Too restrictive. xdg-open(1) is a cross-platform tool.

--- lib/Web/Browser.hs.orig	2024-04-28 12:04:09.488942537 +0000
+++ lib/Web/Browser.hs
@@ -19,7 +19,6 @@ openBrowser :: String -> IO Bool
 openBrowser = openBrowserWindows
 #else
 openBrowser
-    | any (`isInfixOf` os) ["linux", "bsd"] = openBrowserLinux
     | "darwin"  `isInfixOf` os              = openBrowserOSX
-    | otherwise                             = error "unsupported platform"
+    | otherwise                             = openBrowserLinux
 #endif
