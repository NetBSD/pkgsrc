$NetBSD: patch-remoting_base_branding.cc,v 1.2 2026/04/21 15:21:18 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/base/branding.cc.orig	2026-04-14 23:31:37.000000000 +0200
+++ remoting/base/branding.cc
@@ -10,7 +10,7 @@
 #include "base/path_service.h"
 #include "build/build_config.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include <unistd.h>
 
 #include "remoting/base/file_path_util_linux.h"
@@ -34,12 +34,12 @@ const base::FilePath::CharType kConfigDi
 #elif BUILDFLAG(IS_APPLE)
 const base::FilePath::CharType kConfigDir[] =
     FILE_PATH_LITERAL("Chrome Remote Desktop");
-#elif !BUILDFLAG(IS_LINUX)
+#elif !BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 const base::FilePath::CharType kConfigDir[] =
     FILE_PATH_LITERAL(".config/chrome-remote-desktop");
 #endif
 
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 base::FilePath GetConfigDirWithPrefix(int prefix_path_key) {
   base::FilePath app_data_dir;
   base::PathService::Get(prefix_path_key, &app_data_dir);
@@ -60,7 +60,7 @@ const wchar_t kWindowsServiceName[] = L"
 #endif
 
 base::FilePath GetConfigDir() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (getuid() == /*root*/ 0 || GetUsername() == GetNetworkProcessUsername()) {
     // Processes run as root:
     //     daemon process,
