$NetBSD: patch-ui_gfx_linux_gbm__wrapper.cc,v 1.14 2026/01/19 16:14:22 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/gfx/linux/gbm_wrapper.cc.orig	2026-01-07 00:50:30.000000000 +0000
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
