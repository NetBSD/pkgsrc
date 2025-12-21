$NetBSD: patch-src_3rdparty_chromium_ui_gfx_linux_gbm__wrapper.cc,v 1.1 2025/12/21 09:38:48 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/ui/gfx/linux/gbm_wrapper.cc.orig	2025-05-29 01:27:28.000000000 +0000
+++ src/3rdparty/chromium/ui/gfx/linux/gbm_wrapper.cc
@@ -331,7 +331,7 @@ class Device final : public ui::GbmDevic
     // of 1x1 BOs which are destroyed before creating the final BO creation used
     // to instantiate the returned GbmBuffer.
     gfx::Size size_for_verification =
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
         gfx::Size(1, 1);
 #else
         requested_size;
