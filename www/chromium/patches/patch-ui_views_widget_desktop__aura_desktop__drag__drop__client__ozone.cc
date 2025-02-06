$NetBSD: patch-ui_views_widget_desktop__aura_desktop__drag__drop__client__ozone.cc,v 1.1 2025/02/06 09:58:35 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/views/widget/desktop_aura/desktop_drag_drop_client_ozone.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ ui/views/widget/desktop_aura/desktop_drag_drop_client_ozone.cc
@@ -204,7 +204,7 @@ DragOperation DesktopDragDropClientOzone
   return selected_operation_;
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void DesktopDragDropClientOzone::UpdateDragImage(const gfx::ImageSkia& image,
                                                  const gfx::Vector2d& offset) {
   DCHECK(drag_handler_);
