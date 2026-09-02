$NetBSD: patch-remoting_host_config__file__watcher.h,v 1.5 2026/09/02 13:13:34 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/host/config_file_watcher.h.orig	2026-08-31 22:47:51.000000000 +0000
+++ remoting/host/config_file_watcher.h
@@ -20,7 +20,7 @@ namespace remoting {
 extern const char kHostConfigSwitchName[];
 extern const base::FilePath::CharType kDefaultHostConfigFile[];
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 extern const base::FilePath::CharType kDefaultUnprivilegedConfigFileName[];
 #endif
 
