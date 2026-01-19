$NetBSD: patch-components_paint__preview_browser_paint__preview__client__unittest.cc,v 1.14 2026/01/19 16:14:13 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/paint_preview/browser/paint_preview_client_unittest.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ components/paint_preview/browser/paint_preview_client_unittest.cc
@@ -228,8 +228,8 @@ TEST_P(PaintPreviewClientRenderViewHostT
   metadata->set_version(kPaintPreviewVersion);
   auto* chromeVersion = metadata->mutable_chrome_version();
   const auto& current_chrome_version = version_info::GetVersion();
-  chromeVersion->set_major(current_chrome_version.components()[0]);
-  chromeVersion->set_minor(current_chrome_version.components()[1]);
+  chromeVersion->set_gmajor(current_chrome_version.components()[0]);
+  chromeVersion->set_gminor(current_chrome_version.components()[1]);
   chromeVersion->set_build(current_chrome_version.components()[2]);
   chromeVersion->set_patch(current_chrome_version.components()[3]);
   PaintPreviewFrameProto* main_frame = expected_proto.mutable_root_frame();
