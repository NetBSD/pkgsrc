$NetBSD: patch-content_browser_web__contents_web__contents__view__aura__unittest.cc,v 1.24 2026/08/09 06:31:17 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/browser/web_contents/web_contents_view_aura_unittest.cc.orig	2026-08-05 20:17:42.000000000 +0000
+++ content/browser/web_contents/web_contents_view_aura_unittest.cc
@@ -45,7 +45,7 @@
 #include "ui/base/dragdrop/os_exchange_data_provider_win.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(SUPPORTS_OZONE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(SUPPORTS_OZONE_X11)
 #include "ui/base/x/selection_utils.h"
 #include "ui/base/x/x11_os_exchange_data_provider.h"
 #include "ui/gfx/x/atom_cache.h"
@@ -103,7 +103,7 @@ class TestDragDropClient : public aura::
     last_source_ = source;
     return DragOperation::kCopy;
   }
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void UpdateDragImage(const gfx::ImageSkia& image,
                        const gfx::Vector2d& offset) override {}
 #endif
@@ -249,7 +249,7 @@ TEST_F(WebContentsViewAuraTest, WebConte
                              ui::EF_LEFT_MOUSE_BUTTON, 0);
   ui::EventHandler* event_handler = GetView();
   event_handler->OnMouseEvent(&mouse_event);
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // The web-content is not activated during mouse-press on Linux.
   // See comment in WebContentsViewAura::OnMouseEvent() for more details.
   EXPECT_NE(web_contents(), nullptr);
@@ -315,7 +315,7 @@ TEST_F(WebContentsViewAuraTest, MAYBE_Dr
   view->OnDragEntered(event);
   ASSERT_NE(nullptr, view->current_drag_data_);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // By design, Linux implementations return an empty string if file data
   // is also present.
   EXPECT_TRUE(!view->current_drag_data_->text ||
@@ -355,7 +355,7 @@ TEST_F(WebContentsViewAuraTest, MAYBE_Dr
 
   CheckDropData(view);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // By design, Linux implementations returns an empty string if file data
   // is also present.
   EXPECT_TRUE(!drop_complete_data_->drop_data.text ||
@@ -413,7 +413,7 @@ TEST_F(WebContentsViewAuraTest, MAYBE_Dr
   view->OnDragEntered(event);
   ASSERT_NE(nullptr, view->current_drag_data_);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // By design, Linux implementations return an empty string if file data
   // is also present.
   EXPECT_TRUE(!view->current_drag_data_->text ||
@@ -445,7 +445,7 @@ TEST_F(WebContentsViewAuraTest, MAYBE_Dr
 
   CheckDropData(view);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // By design, Linux implementations returns an empty string if file data is
   // also present.
   EXPECT_TRUE(!drop_complete_data_->drop_data.text ||
@@ -477,7 +477,7 @@ TEST_F(WebContentsViewAuraTest, MAYBE_Dr
 
   auto data = std::make_unique<ui::OSExchangeData>();
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(SUPPORTS_OZONE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(SUPPORTS_OZONE_X11)
   // FileContents drag-drop in X relies on XDragDropClient::InitDrag() setting
   // window property 'XdndDirectSave0' to filename. Since XDragDropClient is not
   // created in this unittest, we will set this property manually to allow
