$NetBSD: patch-src_3rdparty_chromium_chrome_common_channel__info__posix.cc,v 1.2 2022/04/18 11:18:18 adam Exp $

--- src/3rdparty/chromium/chrome/common/channel_info_posix.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/chrome/common/channel_info_posix.cc
@@ -67,7 +67,7 @@ std::string GetChannelSuffixForDataDir()
   }
 }
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 std::string GetDesktopName(base::Environment* env) {
 #if BUILDFLAG(GOOGLE_CHROME_BRANDING)
   // Google Chrome packaged as a snap is a special case: the application name
