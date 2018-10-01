$NetBSD: patch-src_assistant_assistant_assistant.pro,v 1.2 2018/10/01 17:44:48 adam Exp $

Don't build webkit dependent parts even if webkit detected.

--- src/assistant/assistant/assistant.pro.orig	2018-09-03 15:13:05.000000000 +0000
+++ src/assistant/assistant/assistant.pro
@@ -1,8 +1,4 @@
-qtHaveModule(webkitwidgets):!contains(QT_CONFIG, static) {
-    BROWSER = qtwebkit
-} else {
     BROWSER = qtextbrowser
-}
 
 QT += widgets network help sql
 qtHaveModule(printsupport): QT += printsupport
