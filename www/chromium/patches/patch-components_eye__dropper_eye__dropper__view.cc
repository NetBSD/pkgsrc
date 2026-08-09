$NetBSD: patch-components_eye__dropper_eye__dropper__view.cc,v 1.24 2026/08/09 06:31:14 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/eye_dropper/eye_dropper_view.cc.orig	2026-08-05 20:17:42.000000000 +0000
+++ components/eye_dropper/eye_dropper_view.cc
@@ -350,7 +350,7 @@ EyeDropperView::EyeDropperView(gfx::Nati
   contents_view->SetPreferredSize(contents_view->GetSize());
   delegate_->SetContentsView(std::move(contents_view));
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Use TYPE_MENU for Linux to ensure that the eye dropper view is displayed
   // above the color picker.
   views::Widget::InitParams params(
