$NetBSD: patch-src_platformsupport_fontdatabases_mac_qfontengine_coretext.mm,v 1.1 2018/01/31 14:08:26 adam Exp $

Fix compilation error.

--- src/platformsupport/fontdatabases/mac/qfontengine_coretext.mm.orig	2018-01-31 12:52:17.000000000 +0000
+++ src/platformsupport/fontdatabases/mac/qfontengine_coretext.mm
@@ -830,7 +830,7 @@ void QCoreTextFontEngine::getUnscaledGly
 
 QFixed QCoreTextFontEngine::emSquareSize() const
 {
-    return QFixed::QFixed(int(CTFontGetUnitsPerEm(ctfont)));
+    return QFixed(int(CTFontGetUnitsPerEm(ctfont)));
 }
 
 QFontEngine *QCoreTextFontEngine::cloneWithSize(qreal pixelSize) const
