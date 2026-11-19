$NetBSD: patch-third__party_vulkan-loader_src_loader_vk__loader__platform.h,v 1.11 2026/11/19 19:46:09 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/vulkan-loader/src/loader/vk_loader_platform.h.orig	2026-11-11 21:01:38.000000000 +0000
+++ third_party/vulkan-loader/src/loader/vk_loader_platform.h
@@ -29,6 +29,7 @@
 #if defined(__FreeBSD__) || defined(__OpenBSD__)
 #include <sys/types.h>
 #include <sys/select.h>
+#include <sys/param.h>
 #endif
 
 #include <assert.h>
