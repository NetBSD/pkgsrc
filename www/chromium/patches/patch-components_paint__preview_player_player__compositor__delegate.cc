$NetBSD: patch-components_paint__preview_player_player__compositor__delegate.cc,v 1.23 2026/07/08 13:42:21 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/paint_preview/player/player_compositor_delegate.cc.orig	2026-07-06 22:58:46.000000000 +0000
+++ components/paint_preview/player/player_compositor_delegate.cc
@@ -395,8 +395,8 @@ void PlayerCompositorDelegate::ValidateP
   auto chrome_version = capture_result_->proto.metadata().chrome_version();
   const auto& current_chrome_version = version_info::GetVersion();
   if (capture_result_->proto.metadata().has_chrome_version() &&
-      chrome_version.major() == current_chrome_version.components()[0] &&
-      chrome_version.minor() == current_chrome_version.components()[1] &&
+      chrome_version.gmajor() == current_chrome_version.components()[0] &&
+      chrome_version.gminor() == current_chrome_version.components()[1] &&
       chrome_version.build() == current_chrome_version.components()[2] &&
       chrome_version.patch() == current_chrome_version.components()[3]) {
     paint_preview_service_->GetFileMixin()->GetAXTreeUpdate(
