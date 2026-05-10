$NetBSD: patch-chrome_browser_ui_views_tabs_dragging_tab__drag__controller.cc,v 1.18 2026/05/10 15:29:52 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/tabs/dragging/tab_drag_controller.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ chrome/browser/ui/views/tabs/dragging/tab_drag_controller.cc
@@ -220,7 +220,7 @@ BrowserView* GetBrowserViewForContext(co
 
 void UpdateSystemDnDDragImage(TabDragContext* attached_context,
                               const gfx::ImageSkia& image) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   VLOG(1) << __func__ << " image size=" << image.size().ToString();
   aura::Window* root_window =
       attached_context->GetWidget()->GetNativeWindow()->GetRootWindow();
@@ -430,7 +430,7 @@ TabDragController::Liveness TabDragContr
   //     synchronous on desktop Linux, so use that.
   // - ChromeOS Ash
   //     Releasing capture on Ash cancels gestures so avoid it.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   ref->can_release_capture_ = false;
 #endif
   ref->start_point_in_screen_ =
@@ -1036,7 +1036,7 @@ TabDragController::Liveness TabDragContr
       CHECK_EQ(SetCapture(target_context), Liveness::kAlive);
     }
 
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
     // EndMoveLoop is going to snap the window back to its original location.
     // Hide it so users don't see this. Hiding a window in Linux aura causes
     // it to lose capture so skip it.
@@ -2259,7 +2259,7 @@ void TabDragController::CompleteDrag() {
     }
 
     // If source window was maximized - maximize the new window as well.
-#if !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_MAC)
+#if !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_BSD)
     // Keeping maximized state breaks snap to Grid on Windows when dragging
     // tabs from maximized windows. TODO:(crbug.com/727051) Explore doing this
     // for other desktop OS's. kMaximizedStateRetainedOnTabDrag in
@@ -2694,7 +2694,7 @@ TabDragController::Liveness TabDragContr
     }
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Exclude windows which are pending deletion via Browser::TabStripEmpty().
   // These windows can be returned in the Linux Aura port because the browser
   // window which was used for dragging is not hidden once all of its tabs are
