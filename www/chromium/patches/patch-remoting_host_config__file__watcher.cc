$NetBSD: patch-remoting_host_config__file__watcher.cc,v 1.5 2026/09/02 13:13:34 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/host/config_file_watcher.cc.orig	2026-08-31 22:47:51.000000000 +0000
+++ remoting/host/config_file_watcher.cc
@@ -27,7 +27,7 @@ const char kHostConfigSwitchName[] = "ho
 const base::FilePath::CharType kDefaultHostConfigFile[] =
     FILE_PATH_LITERAL("host.json");
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 const base::FilePath::CharType kDefaultUnprivilegedConfigFileName[] =
     FILE_PATH_LITERAL("host_unprivileged.json");
 #endif
