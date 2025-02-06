$NetBSD: patch-chrome_browser_ui_views_chrome__views__delegate__linux.cc,v 1.1 2025/02/06 09:57:53 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/chrome_views_delegate_linux.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ chrome/browser/ui/views/chrome_views_delegate_linux.cc
@@ -26,7 +26,7 @@ bool IsDesktopEnvironmentUnity() {
   return desktop_env == base::nix::DESKTOP_ENVIRONMENT_UNITY;
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 int GetWindowIconResourceId() {
 #if BUILDFLAG(GOOGLE_CHROME_BRANDING)
   switch (chrome::GetChannel()) {
@@ -80,7 +80,7 @@ views::NativeWidget* ChromeViewsDelegate
                               delegate);
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 gfx::ImageSkia* ChromeViewsDelegate::GetDefaultWindowIcon() const {
   ui::ResourceBundle& rb = ui::ResourceBundle::GetSharedInstance();
   return rb.GetImageSkiaNamed(GetWindowIconResourceId());
