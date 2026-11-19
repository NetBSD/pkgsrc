$NetBSD: patch-gpu_vulkan_generate__bindings.py,v 1.33 2026/11/19 19:46:02 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- gpu/vulkan/generate_bindings.py.orig	2026-11-11 21:01:38.000000000 +0000
+++ gpu/vulkan/generate_bindings.py
@@ -275,7 +275,7 @@ VULKAN_DEVICE_FUNCTIONS = [
     ],
   },
   {
-    'ifdef': 'BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)',
+    'ifdef': 'BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)',
     'extension': 'VK_EXT_IMAGE_DRM_FORMAT_MODIFIER_EXTENSION_NAME',
     'functions': [
       'vkGetImageDrmFormatModifierPropertiesEXT',
