$NetBSD: patch-src_gui_image_qiconloader.cpp,v 1.1 2026/09/08 20:34:46 markd Exp $

Don't consider fallbackThemeName() in themeName()
https://codereview.qt-project.org/c/qt/qtbase/+/763319
https://bugs.kde.org/show_bug.cgi?id=524657

--- src/gui/image/qiconloader.cpp.orig	2026-05-11 20:54:55.000000000 +0000
+++ src/gui/image/qiconloader.cpp
@@ -151,8 +151,7 @@ QString QIconLoader::themeName() const
         return m_userTheme;
 
     if (m_systemTheme.isEmpty()) {
-        const QString &themeName = systemThemeName();
-        m_systemTheme = !themeName.isEmpty() ? themeName : fallbackThemeName();
+        m_systemTheme = systemThemeName();
     }
     return m_systemTheme;
 }
