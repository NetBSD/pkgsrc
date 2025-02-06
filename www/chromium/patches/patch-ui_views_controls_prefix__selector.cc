$NetBSD: patch-ui_views_controls_prefix__selector.cc,v 1.1 2025/02/06 09:58:35 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/views/controls/prefix_selector.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ ui/views/controls/prefix_selector.cc
@@ -178,7 +178,7 @@ bool PrefixSelector::ShouldDoLearning() 
   return false;
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 bool PrefixSelector::SetCompositionFromExistingText(
     const gfx::Range& range,
     const std::vector<ui::ImeTextSpan>& ui_ime_text_spans) {
