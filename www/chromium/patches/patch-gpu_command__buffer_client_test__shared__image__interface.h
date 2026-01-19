$NetBSD: patch-gpu_command__buffer_client_test__shared__image__interface.h,v 1.10 2026/01/19 16:14:16 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- gpu/command_buffer/client/test_shared_image_interface.h.orig	2026-01-07 00:50:30.000000000 +0000
+++ gpu/command_buffer/client/test_shared_image_interface.h
@@ -136,7 +136,7 @@ class TestSharedImageInterface : public 
       bool premapped,
       const ClientSharedImage::AsyncMapInvokedCallback& callback);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Creates a mappable SI backed by a NativePixmapHandle.
   scoped_refptr<ClientSharedImage> CreateNativePixmapBackedSharedImage(
       const SharedImageInfo& si_info,
