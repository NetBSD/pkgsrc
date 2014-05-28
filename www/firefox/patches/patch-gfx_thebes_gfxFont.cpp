$NetBSD: patch-gfx_thebes_gfxFont.cpp,v 1.1 2014/05/28 15:11:29 pho Exp $

Don't assume cocoa toolkit just because OS_ARCH is Darwin.

--- gfx/thebes/gfxFont.cpp.orig	2014-05-06 22:55:35.000000000 +0000
+++ gfx/thebes/gfxFont.cpp
@@ -40,7 +40,7 @@
 #include "gfxSVGGlyphs.h"
 #include "gfx2DGlue.h"
 
-#if defined(XP_MACOSX)
+#if defined(MOZ_WIDGET_COCOA)
 #include "nsCocoaFeatures.h"
 #endif
 
@@ -1297,7 +1297,7 @@ gfxFontFamily::ReadFaceNames(gfxPlatform
 
     bool asyncFontLoaderDisabled = false;
 
-#if defined(XP_MACOSX)
+#if defined(MOZ_WIDGET_COCOA)
     // bug 975460 - async font loader crashes sometimes under 10.6, disable
     if (!nsCocoaFeatures::OnLionOrLater()) {
         asyncFontLoaderDisabled = true;
@@ -4177,7 +4177,7 @@ gfxFontGroup::BuildFontList()
 {
 // "#if" to be removed once all platforms are moved to gfxPlatformFontList interface
 // and subclasses of gfxFontGroup eliminated
-#if defined(XP_MACOSX) || defined(XP_WIN) || defined(ANDROID)
+#if defined(MOZ_WIDGET_COCOA) || defined(XP_WIN) || defined(ANDROID)
     ForEachFont(FindPlatformFont, this);
 
     if (mFonts.Length() == 0) {
@@ -5236,7 +5236,7 @@ gfxFontGroup::UpdateFontList()
         mSkipDrawing = false;
 
         // bug 548184 - need to clean up FT2, OS/2 platform code to use BuildFontList
-#if defined(XP_MACOSX) || defined(XP_WIN) || defined(ANDROID)
+#if defined(MOZ_WIDGET_COCOA) || defined(XP_WIN) || defined(ANDROID)
         BuildFontList();
 #else
         ForEachFont(FindPlatformFont, this);
