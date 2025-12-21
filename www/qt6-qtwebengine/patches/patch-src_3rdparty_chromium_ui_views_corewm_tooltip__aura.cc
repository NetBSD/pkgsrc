$NetBSD: patch-src_3rdparty_chromium_ui_views_corewm_tooltip__aura.cc,v 1.1 2025/12/21 09:38:49 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/ui/views/corewm/tooltip_aura.cc.orig	2025-10-02 00:36:39.000000000 +0000
+++ src/3rdparty/chromium/ui/views/corewm/tooltip_aura.cc
@@ -38,7 +38,8 @@ static constexpr int kTooltipMaxWidth = 
 
 // TODO(varkha): Update if native widget can be transparent on Linux.
 bool CanUseTranslucentTooltipWidget() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
+
   return false;
 #else
   return true;
