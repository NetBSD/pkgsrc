$NetBSD: patch-src_gui_text_qfontengine__coretext.mm,v 1.1 2019/12/01 13:28:09 adam Exp $

Fix compiler error.

--- src/gui/text/qfontengine_coretext.mm.orig	2019-12-01 12:38:26.000000000 +0000
+++ src/gui/text/qfontengine_coretext.mm
@@ -886,7 +886,7 @@ void QCoreTextFontEngine::getUnscaledGly
 
 QFixed QCoreTextFontEngine::emSquareSize() const
 {
-    return QFixed::QFixed(int(CTFontGetUnitsPerEm(ctfont)));
+    return QFixed(int(CTFontGetUnitsPerEm(ctfont)));
 }
 
 QFontEngine *QCoreTextFontEngine::cloneWithSize(qreal pixelSize) const
