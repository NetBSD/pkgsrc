$NetBSD: patch-ui_base_resource_resource__bundle.cc,v 1.6 2025/09/08 13:24:34 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/base/resource/resource_bundle.cc.orig	2025-08-29 18:50:09.000000000 +0000
+++ ui/base/resource/resource_bundle.cc
@@ -1002,7 +1002,7 @@ void ResourceBundle::ReloadFonts() {
 }
 
 ResourceScaleFactor ResourceBundle::GetMaxResourceScaleFactor() const {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return max_scale_factor_;
 #else
   return GetMaxSupportedResourceScaleFactor();
