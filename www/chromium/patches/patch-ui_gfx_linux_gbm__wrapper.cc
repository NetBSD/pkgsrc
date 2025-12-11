$NetBSD: patch-ui_gfx_linux_gbm__wrapper.cc,v 1.11 2025/12/11 09:13:47 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/gfx/linux/gbm_wrapper.cc.orig	2025-11-19 21:40:05.000000000 +0000
+++ ui/gfx/linux/gbm_wrapper.cc
@@ -341,7 +341,7 @@ class Device final : public ui::GbmDevic
     // of 1x1 BOs which are destroyed before creating the final BO creation used
     // to instantiate the returned GbmBuffer.
     gfx::Size size_for_verification =
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
         gfx::Size(1, 1);
 #else
         requested_size;
