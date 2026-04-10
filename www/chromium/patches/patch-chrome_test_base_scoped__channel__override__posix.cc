$NetBSD: patch-chrome_test_base_scoped__channel__override__posix.cc,v 1.17 2026/04/10 17:31:52 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/test/base/scoped_channel_override_posix.cc.orig	2026-04-06 16:25:54.000000000 +0000
+++ chrome/test/base/scoped_channel_override_posix.cc
@@ -22,7 +22,7 @@ version_info::Channel GetBaseChannel(Sco
       return version_info::Channel::BETA;
     case ScopedChannelOverride::Channel::kDev:
       return version_info::Channel::DEV;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     case ScopedChannelOverride::Channel::kCanary:
       return version_info::Channel::CANARY;
 #endif  // BUILDFLAG(IS_LINUX)
