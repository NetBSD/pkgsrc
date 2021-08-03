$NetBSD: patch-src_3rdparty_chromium_chrome_common_chrome__paths.h,v 1.1 2021/08/03 21:04:34 markd Exp $

--- src/3rdparty/chromium/chrome/common/chrome_paths.h.orig	2020-07-08 21:40:36.000000000 +0000
+++ src/3rdparty/chromium/chrome/common/chrome_paths.h
@@ -51,7 +51,7 @@ enum {
                      // contains subdirectories.
 #endif
 #if defined(OS_CHROMEOS) || \
-    (defined(OS_LINUX) && BUILDFLAG(CHROMIUM_BRANDING)) || defined(OS_MACOSX)
+    ((defined(OS_LINUX) || defined(OS_BSD)) && BUILDFLAG(CHROMIUM_BRANDING)) || defined(OS_MACOSX)
   DIR_USER_EXTERNAL_EXTENSIONS,  // Directory for per-user external extensions
                                  // on Chrome Mac and Chromium Linux.
                                  // On Chrome OS, this path is used for OEM
@@ -59,7 +59,7 @@ enum {
                                  // create it.
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   DIR_STANDALONE_EXTERNAL_EXTENSIONS,  // Directory for 'per-extension'
                                        // definition manifest files that
                                        // describe extensions which are to be
@@ -91,7 +91,7 @@ enum {
   DIR_PNACL_BASE,                   // Full path to the base dir for PNaCl.
   DIR_PNACL_COMPONENT,              // Full path to the latest PNaCl version
                                     // (subdir of DIR_PNACL_BASE).
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   DIR_BUNDLED_WIDEVINE_CDM,  // Full path to the directory containing the
                              // bundled Widevine CDM.
 #if !defined(OS_CHROMEOS)
@@ -120,7 +120,7 @@ enum {
   DIR_SUPERVISED_USER_INSTALLED_WHITELISTS,  // Directory where sanitized
                                              // supervised user whitelists are
                                              // installed.
-#if defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
   DIR_NATIVE_MESSAGING,       // System directory where native messaging host
                               // manifest files are stored.
   DIR_USER_NATIVE_MESSAGING,  // Directory with Native Messaging Hosts
@@ -135,7 +135,7 @@ enum {
   DIR_GEN_TEST_DATA,  // Directory where generated test data resides.
   DIR_TEST_DATA,      // Directory where unit test data resides.
   DIR_TEST_TOOLS,     // Directory where unit test tools reside.
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   FILE_COMPONENT_FLASH_HINT,  // A file in a known location that points to
                               // the component updated flash plugin.
 #endif  // defined(OS_LINUX)
