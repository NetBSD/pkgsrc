$NetBSD: patch-src_3rdparty_chromium_components_media__router_common_providers_cast_channel_cast__message__util.cc,v 1.1 2025/12/21 09:38:23 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/components/media_router/common/providers/cast/channel/cast_message_util.cc.orig	2025-11-14 07:55:10.000000000 +0000
+++ src/3rdparty/chromium/components/media_router/common/providers/cast/channel/cast_message_util.cc
@@ -168,7 +168,7 @@ int GetVirtualConnectPlatformValue() {
   return 4;
 #elif BUILDFLAG(IS_CHROMEOS)
   return 5;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return 6;
 #else
   return 0;
