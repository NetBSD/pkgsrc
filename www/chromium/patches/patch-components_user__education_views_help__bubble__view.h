$NetBSD: patch-components_user__education_views_help__bubble__view.h,v 1.18 2026/05/10 15:29:56 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/user_education/views/help_bubble_view.h.orig	2026-04-28 23:05:57.000000000 +0200
+++ components/user_education/views/help_bubble_view.h
@@ -173,7 +173,7 @@ class HelpBubbleView : public views::Bub
 // work around this problem by closing the bubble if the widget is minimized.
 // When the underlying issue is fixed at the framework level, this can be
 // removed.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   class PrimaryWidgetObserver;
   std::unique_ptr<PrimaryWidgetObserver> primary_widget_observer_;
 #endif
