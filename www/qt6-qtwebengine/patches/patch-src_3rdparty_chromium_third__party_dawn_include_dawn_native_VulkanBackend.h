$NetBSD: patch-src_3rdparty_chromium_third__party_dawn_include_dawn_native_VulkanBackend.h,v 1.1 2025/12/21 09:38:41 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/third_party/dawn/include/dawn/native/VulkanBackend.h.orig	2025-05-29 01:27:28.000000000 +0000
+++ src/3rdparty/chromium/third_party/dawn/include/dawn/native/VulkanBackend.h
@@ -83,7 +83,7 @@ struct ExternalImageExportInfoVk : Exter
 };
 
 // Can't use DAWN_PLATFORM_IS(LINUX) since header included in both Dawn and Chrome
-#if defined(__linux__) || defined(__Fuchsia__)
+#if defined(__linux__) || defined(__Fuchsia__) || defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__NetBSD__)
 
 // Common properties of external images represented by FDs. On successful import the file
 // descriptor's ownership is transferred to the Dawn implementation and they shouldn't be
