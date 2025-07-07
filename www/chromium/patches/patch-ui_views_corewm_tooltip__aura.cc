$NetBSD: patch-ui_views_corewm_tooltip__aura.cc,v 1.3 2025/07/07 09:23:40 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/views/corewm/tooltip_aura.cc.orig	2025-06-30 06:54:11.000000000 +0000
+++ ui/views/corewm/tooltip_aura.cc
@@ -42,7 +42,7 @@ static constexpr int kTooltipMaxWidth = 
 
 // TODO(varkha): Update if native widget can be transparent on Linux.
 bool CanUseTranslucentTooltipWidget() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   return false;
 #else
   return true;
