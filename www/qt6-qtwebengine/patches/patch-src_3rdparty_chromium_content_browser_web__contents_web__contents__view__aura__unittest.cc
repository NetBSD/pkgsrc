$NetBSD: patch-src_3rdparty_chromium_content_browser_web__contents_web__contents__view__aura__unittest.cc,v 1.1 2025/12/21 09:38:27 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/content/browser/web_contents/web_contents_view_aura_unittest.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/content/browser/web_contents/web_contents_view_aura_unittest.cc
@@ -97,7 +97,7 @@ class TestDragDropClient : public aura::
     drag_drop_data_ = std::move(data);
     return DragOperation::kCopy;
   }
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void UpdateDragImage(const gfx::ImageSkia& image,
                        const gfx::Vector2d& offset) override {}
 #endif
