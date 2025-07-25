$NetBSD: patch-chrome_test_base_scoped__channel__override__posix.cc,v 1.4 2025/07/25 16:17:14 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/test/base/scoped_channel_override_posix.cc.orig	2025-07-21 19:32:31.000000000 +0000
+++ chrome/test/base/scoped_channel_override_posix.cc
@@ -43,7 +43,7 @@ std::string GetVersionExtra(ScopedChanne
       return "beta";
     case ScopedChannelOverride::Channel::kDev:
       return "unstable";
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     case ScopedChannelOverride::Channel::kCanary:
       return "canary";
 #endif  // BUILDFLAG(IS_LINUX)
