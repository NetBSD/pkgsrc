$NetBSD: patch-src_Yesod_Core_Dispatch.hs,v 1.1 2025/02/02 03:23:58 pho Exp $

Fix build with wai-extra-3.1.17:
https://github.com/yesodweb/yesod/issues/1854

--- src/Yesod/Core/Dispatch.hs.orig	2025-02-02 03:16:47.042395920 +0000
+++ src/Yesod/Core/Dispatch.hs
@@ -244,7 +244,7 @@ serverValue = S8.pack $ concat
 -- Since 1.2.0
 mkDefaultMiddlewares :: Logger -> IO W.Middleware
 mkDefaultMiddlewares logger = do
-    logWare <- mkRequestLogger def
+    logWare <- mkRequestLogger defaultRequestLoggerSettings
         { destination = Network.Wai.Middleware.RequestLogger.Logger $ loggerSet logger
         , outputFormat = Apache FromSocket
         }
