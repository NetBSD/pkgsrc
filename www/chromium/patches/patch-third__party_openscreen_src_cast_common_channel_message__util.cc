$NetBSD: patch-third__party_openscreen_src_cast_common_channel_message__util.cc,v 1.1 2026/09/22 13:41:32 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/openscreen/src/cast/common/channel/message_util.cc.orig	2026-09-14 22:17:16.000000000 +0000
+++ third_party/openscreen/src/cast/common/channel/message_util.cc
@@ -59,7 +59,7 @@ constexpr VirtualConnectPlatformValue Ge
   return kMacOSX;
 #elif BUILDFLAG(IS_CHROMEOS)
   return kChromeOS;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return kLinux;
 #else
   return kOtherPlatform;
