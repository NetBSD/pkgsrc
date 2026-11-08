$NetBSD: patch-components_device__signals_core_browser_linux_browser__utils__linux.cc,v 1.7 2026/11/08 15:38:59 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/device_signals/core/browser/linux/browser_utils_linux.cc.orig	2026-11-02 23:22:33.000000000 +0000
+++ components/device_signals/core/browser/linux/browser_utils_linux.cc
@@ -81,7 +81,7 @@ SettingValue GetOSFirewall() {
 #endif
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 const char** GetUfwConfigPath() {
   static const char* path = "/etc/ufw/ufw.conf";
   return &path;
