$NetBSD: patch-src_3rdparty_chromium_content_browser_devtools_protocol_system__info__handler.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/content/browser/devtools/protocol/system_info_handler.cc.orig	2020-11-07 01:22:36.000000000 +0000
+++ src/3rdparty/chromium/content/browser/devtools/protocol/system_info_handler.cc
@@ -48,7 +48,7 @@ std::unique_ptr<SystemInfo::Size> GfxSiz
 // Give the GPU process a few seconds to provide GPU info.
 // Linux Debug builds need more time -- see Issue 796437.
 // Windows builds need more time -- see Issue 873112 and 1004472.
-#if (defined(OS_LINUX) && !defined(NDEBUG))
+#if ((defined(OS_LINUX) || defined(OS_BSD)) && !defined(NDEBUG))
 const int kGPUInfoWatchdogTimeoutMs = 20000;
 #elif defined(OS_WIN)
 const int kGPUInfoWatchdogTimeoutMs = 30000;
