$NetBSD: patch-ui_views_widget_desktop__aura_desktop__drag__drop__client__ozone.h,v 1.1 2025/02/06 09:58:35 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/views/widget/desktop_aura/desktop_drag_drop_client_ozone.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ ui/views/widget/desktop_aura/desktop_drag_drop_client_ozone.h
@@ -67,7 +67,7 @@ class VIEWS_EXPORT DesktopDragDropClient
     // The offset of |drag_widget_| relative to the mouse position.
     gfx::Vector2d offset;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // The last received drag location.  The drag widget is moved asynchronously
     // so its position is updated when the UI thread has time for that.  When
     // the first change to the location happens, a call to UpdateDragWidget()
@@ -88,7 +88,7 @@ class VIEWS_EXPORT DesktopDragDropClient
       const gfx::Point& root_location,
       int allowed_operations,
       ui::mojom::DragEventSource source) override;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void UpdateDragImage(const gfx::ImageSkia& image,
                        const gfx::Vector2d& offset) override;
 #endif
