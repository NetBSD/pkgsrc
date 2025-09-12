$NetBSD: patch-ui_views_widget_desktop__aura_desktop__drag__drop__client__ozone.cc,v 1.7 2025/09/12 16:02:39 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/views/widget/desktop_aura/desktop_drag_drop_client_ozone.cc.orig	2025-09-08 23:21:33.000000000 +0000
+++ ui/views/widget/desktop_aura/desktop_drag_drop_client_ozone.cc
@@ -203,7 +203,7 @@ DragOperation DesktopDragDropClientOzone
   return selected_operation_;
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void DesktopDragDropClientOzone::UpdateDragImage(const gfx::ImageSkia& image,
                                                  const gfx::Vector2d& offset) {
   DCHECK(drag_handler_);
