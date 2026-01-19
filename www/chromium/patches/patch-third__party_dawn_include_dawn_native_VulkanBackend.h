$NetBSD: patch-third__party_dawn_include_dawn_native_VulkanBackend.h,v 1.14 2026/01/19 16:14:20 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/dawn/include/dawn/native/VulkanBackend.h.orig	2026-01-07 00:50:30.000000000 +0000
+++ third_party/dawn/include/dawn/native/VulkanBackend.h
@@ -83,7 +83,8 @@ struct ExternalImageExportInfoVk : Exter
 };
 
 // Can't use DAWN_PLATFORM_IS(LINUX) since header included in both Dawn and Chrome
-#if defined(__linux__) || defined(__Fuchsia__)
+#if defined(__linux__) || defined(__Fuchsia__) || defined(__OpenBSD__) || defined(__FreeBSD__) || \
+    defined(__NetBSD__)
 
 // Common properties of external images represented by FDs. On successful import the file
 // descriptor's ownership is transferred to the Dawn implementation and they shouldn't be
