$NetBSD: patch-components_private__ai_proto__utils_client__metadata__utils.cc,v 1.1 2026/09/22 13:41:24 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/private_ai/proto_utils/client_metadata_utils.cc.orig	2026-09-14 22:17:16.000000000 +0000
+++ components/private_ai/proto_utils/client_metadata_utils.cc
@@ -41,7 +41,7 @@ proto::ChromeClientMetadata::Platform Ge
   return proto::ChromeClientMetadata::PLATFORM_ANDROID;
 #elif BUILDFLAG(IS_IOS)
   return proto::ChromeClientMetadata::PLATFORM_IOS;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return proto::ChromeClientMetadata::PLATFORM_LINUX;
 #else
   return proto::ChromeClientMetadata::PLATFORM_UNKNOWN;
