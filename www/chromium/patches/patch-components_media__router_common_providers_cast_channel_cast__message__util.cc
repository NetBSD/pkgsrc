$NetBSD: patch-components_media__router_common_providers_cast_channel_cast__message__util.cc,v 1.11 2025/12/11 09:13:36 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/media_router/common/providers/cast/channel/cast_message_util.cc.orig	2025-11-19 21:40:05.000000000 +0000
+++ components/media_router/common/providers/cast/channel/cast_message_util.cc
@@ -168,7 +168,7 @@ int GetVirtualConnectPlatformValue() {
   return 4;
 #elif BUILDFLAG(IS_CHROMEOS)
   return 5;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return 6;
 #else
   return 0;
