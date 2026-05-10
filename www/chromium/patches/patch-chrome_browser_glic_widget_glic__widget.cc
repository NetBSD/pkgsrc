$NetBSD: patch-chrome_browser_glic_widget_glic__widget.cc,v 1.15 2026/05/10 15:29:50 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/glic/widget/glic_widget.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ chrome/browser/glic/widget/glic_widget.cc
@@ -54,7 +54,7 @@
 #include "ui/views/win/hwnd_util.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/shell_integration_linux.h"
 #include "chrome/browser/ui/views/frame/opaque_browser_frame_view_layout.h"
 #endif
@@ -109,7 +109,7 @@ class GlicClientView : public views::Cli
   GlicView* glic_view() { return static_cast<GlicView*>(contents_view()); }
 };
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 class GlicFrameView : public views::NativeFrameView {
  public:
   explicit GlicFrameView(views::Widget* widget)
@@ -128,7 +128,7 @@ class GlicFrameView : public views::Nati
 #if BUILDFLAG(IS_WIN)
     int resize_border = resize_border =
         display::win::GetScreenWin()->GetSystemMetricsInDIP(SM_CXSIZEFRAME);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     int resize_border = OpaqueBrowserFrameViewLayout::kFrameBorderThickness;
 #endif
     const bool can_resize = GetWidget()->widget_delegate()->CanResize();
@@ -338,7 +338,7 @@ std::unique_ptr<views::WidgetDelegate> G
         return std::make_unique<GlicClientView>(widget, contents_view);
       }));
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   delegate->SetFrameViewFactory(base::BindRepeating(
       [](views::Widget* widget) -> std::unique_ptr<views::FrameView> {
         return std::make_unique<GlicFrameView>(widget);
@@ -416,7 +416,7 @@ std::unique_ptr<GlicWidget> GlicWidget::
 #if BUILDFLAG(IS_MAC)
   params.animation_enabled = true;
 #endif  // BUILDFLAG(IS_MAC)
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   params.wm_class_class = shell_integration_linux::GetProgramClassClass();
   params.wayland_app_id = params.wm_class_class + "-glic";
 #endif  // BUILDFLAG(IS_LINUX)
