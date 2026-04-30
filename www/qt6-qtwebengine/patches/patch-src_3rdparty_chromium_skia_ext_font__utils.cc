$NetBSD: patch-src_3rdparty_chromium_skia_ext_font__utils.cc,v 1.2 2026/04/30 06:39:43 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/skia/ext/font_utils.cc.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/skia/ext/font_utils.cc
@@ -21,7 +21,7 @@
 #include "third_party/skia/include/ports/SkFontMgr_mac_ct.h"
 #endif
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "third_party/skia/include/ports/SkFontConfigInterface.h"
 #include "third_party/skia/include/ports/SkFontMgr_FontConfigInterface.h"
 #include "third_party/skia/include/ports/SkFontScanner_Fontations.h"
@@ -64,7 +64,7 @@ static sk_sp<SkFontMgr> fontmgr_factory(
   return SkFontMgr_New_Android(nullptr, SkFontScanner_Make_Fontations());
 #elif BUILDFLAG(IS_APPLE)
   return SkFontMgr_New_CoreText(nullptr);
-#elif BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   sk_sp<SkFontConfigInterface> fci(SkFontConfigInterface::RefGlobal());
 #if defined(SK_TYPEFACE_FACTORY_FONTATIONS)
   return fci ? SkFontMgr_New_FCI(std::move(fci),
