$NetBSD: patch-src_3rdparty_chromium_ui_gfx_font__list.cc,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/ui/gfx/font_list.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/ui/gfx/font_list.cc
@@ -24,7 +24,7 @@ base::LazyInstance<scoped_refptr<gfx::Fo
 bool g_default_impl_initialized = false;
 
 bool IsFontFamilyAvailable(const std::string& family, SkFontMgr* fontManager) {
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   return !!fontManager->legacyMakeTypeface(family.c_str(), SkFontStyle());
 #else
   sk_sp<SkFontStyleSet> set(fontManager->matchFamily(family.c_str()));
