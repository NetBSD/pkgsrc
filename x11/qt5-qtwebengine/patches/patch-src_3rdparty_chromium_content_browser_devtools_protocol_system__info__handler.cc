$NetBSD: patch-src_3rdparty_chromium_content_browser_devtools_protocol_system__info__handler.cc,v 1.2 2022/04/18 11:18:18 adam Exp $

--- src/3rdparty/chromium/content/browser/devtools/protocol/system_info_handler.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/content/browser/devtools/protocol/system_info_handler.cc
@@ -47,7 +47,7 @@ std::unique_ptr<SystemInfo::Size> GfxSiz
 // Give the GPU process a few seconds to provide GPU info.
 // Linux Debug builds need more time -- see Issue 796437 and 1046598.
 // Windows builds need more time -- see Issue 873112 and 1004472.
-#if ((defined(OS_LINUX) || defined(OS_CHROMEOS)) && !defined(NDEBUG)) || \
+#if ((defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)) && !defined(NDEBUG)) || \
     defined(OS_WIN)
 const int kGPUInfoWatchdogTimeoutMs = 30000;
 #else
