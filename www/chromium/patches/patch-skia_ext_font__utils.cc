$NetBSD: patch-skia_ext_font__utils.cc,v 1.14 2026/01/19 16:14:19 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- skia/ext/font_utils.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ skia/ext/font_utils.cc
@@ -24,7 +24,7 @@
 #include "third_party/skia/include/ports/SkFontMgr_mac_ct.h"
 #endif
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "third_party/skia/include/ports/SkFontConfigInterface.h"
 #include "third_party/skia/include/ports/SkFontMgr_FontConfigInterface.h"
 #include "third_party/skia/include/ports/SkFontScanner_Fontations.h"
@@ -82,7 +82,7 @@ static sk_sp<SkFontMgr> fontmgr_factory(
   return SkFontMgr_New_Android(nullptr, SkFontScanner_Make_Fontations());
 #elif BUILDFLAG(IS_APPLE)
   return SkFontMgr_New_CoreText(nullptr);
-#elif BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   sk_sp<SkFontConfigInterface> fci(SkFontConfigInterface::RefGlobal());
   return fci ? SkFontMgr_New_FCI(std::move(fci),
                                  SkFontScanner_Make_Fontations())
