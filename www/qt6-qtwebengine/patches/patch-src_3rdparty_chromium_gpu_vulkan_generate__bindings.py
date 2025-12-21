$NetBSD: patch-src_3rdparty_chromium_gpu_vulkan_generate__bindings.py,v 1.1 2025/12/21 09:38:30 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/gpu/vulkan/generate_bindings.py.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/gpu/vulkan/generate_bindings.py
@@ -271,7 +271,7 @@ VULKAN_DEVICE_FUNCTIONS = [
     ]
   },
   {
-    'ifdef': 'BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)',
+    'ifdef': 'BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)',
     'extension': 'VK_EXT_IMAGE_DRM_FORMAT_MODIFIER_EXTENSION_NAME',
     'functions': [
       'vkGetImageDrmFormatModifierPropertiesEXT',
