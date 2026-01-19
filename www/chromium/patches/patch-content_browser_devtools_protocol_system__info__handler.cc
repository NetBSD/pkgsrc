$NetBSD: patch-content_browser_devtools_protocol_system__info__handler.cc,v 1.14 2026/01/19 16:14:14 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/browser/devtools/protocol/system_info_handler.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ content/browser/devtools/protocol/system_info_handler.cc
@@ -52,7 +52,7 @@ std::unique_ptr<SystemInfo::Size> GfxSiz
 // 1046598, and 1153667.
 // Windows builds need more time -- see Issue 873112 and 1004472.
 // Mac builds need more time - see Issue angleproject:6182.
-#if ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && !defined(NDEBUG)) || \
+#if ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)) && !defined(NDEBUG)) || \
     BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_OZONE)
 static constexpr int kGPUInfoWatchdogTimeoutMultiplierOS = 3;
 #else
