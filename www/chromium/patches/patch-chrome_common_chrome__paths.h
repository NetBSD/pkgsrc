$NetBSD: patch-chrome_common_chrome__paths.h,v 1.14 2026/01/19 16:14:12 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/common/chrome_paths.h.orig	2026-01-07 00:50:30.000000000 +0000
+++ chrome/common/chrome_paths.h
@@ -58,7 +58,7 @@ enum {
                      // to set policies for chrome. This directory
                      // contains subdirectories.
 #endif
-#if BUILDFLAG(IS_CHROMEOS) || \
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD) || \
     (BUILDFLAG(IS_LINUX) && BUILDFLAG(CHROMIUM_BRANDING)) || BUILDFLAG(IS_MAC)
   DIR_USER_EXTERNAL_EXTENSIONS,  // Directory for per-user external extensions
                                  // on Chrome Mac and Chromium Linux.
@@ -67,7 +67,7 @@ enum {
                                  // create it.
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   DIR_STANDALONE_EXTERNAL_EXTENSIONS,  // Directory for 'per-extension'
                                        // definition manifest files that
                                        // describe extensions which are to be
@@ -107,7 +107,7 @@ enum {
 
 #if BUILDFLAG(ENABLE_EXTENSIONS_CORE) &&                                   \
     (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-     BUILDFLAG(IS_ANDROID))
+     BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD))
   DIR_NATIVE_MESSAGING,       // System directory where native messaging host
                               // manifest files are stored.
   DIR_USER_NATIVE_MESSAGING,  // Directory with Native Messaging Hosts
