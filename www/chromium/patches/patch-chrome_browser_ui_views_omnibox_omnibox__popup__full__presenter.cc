$NetBSD: patch-chrome_browser_ui_views_omnibox_omnibox__popup__full__presenter.cc,v 1.2 2026/11/08 15:38:57 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/omnibox/omnibox_popup_full_presenter.cc.orig	2026-11-02 23:22:33.000000000 +0000
+++ chrome/browser/ui/views/omnibox/omnibox_popup_full_presenter.cc
@@ -52,7 +52,7 @@
 #include "ui/views/view_class_properties.h"
 #include "ui/views/view_utils.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/aura/window.h"
 #include "ui/aura/window_tree_host.h"
 #include "ui/views/widget/desktop_aura/desktop_window_tree_host_platform.h"
@@ -68,7 +68,7 @@ namespace {
 
 // Returns whether the browser widget's platform window is active.
 bool IsBrowserPlatformWindowActive(views::Widget* browser_widget) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (aura::Window* native_window = browser_widget->GetNativeWindow();
       native_window && native_window->GetHost()) {
     if (auto* host = views::DesktopWindowTreeHostPlatform::GetHostForWidget(
