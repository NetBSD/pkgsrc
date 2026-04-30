$NetBSD: patch-src_3rdparty_chromium_components_user__education_views_help__bubble__view.h,v 1.1 2026/04/30 06:39:39 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/components/user_education/views/help_bubble_view.h.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/components/user_education/views/help_bubble_view.h
@@ -160,7 +160,7 @@ class HelpBubbleView : public views::Bub
 // work around this problem by closing the bubble if the widget is minimized.
 // When the underlying issue is fixed at the framework level, this can be
 // removed.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   class PrimaryWidgetObserver;
   std::unique_ptr<PrimaryWidgetObserver> primary_widget_observer_;
 #endif
