$NetBSD: patch-components_feed_core_v2_proto__util.cc,v 1.14 2026/01/19 16:14:13 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/feed/core/v2/proto_util.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ components/feed/core/v2/proto_util.cc
@@ -92,8 +92,8 @@ feedwire::Version GetPlatformVersionMess
 
   int32_t major, minor, revision;
   base::SysInfo::OperatingSystemVersionNumbers(&major, &minor, &revision);
-  result.set_major(major);
-  result.set_minor(minor);
+  result.set_gmajor(major);
+  result.set_gminor(minor);
   result.set_revision(revision);
 #if BUILDFLAG(IS_ANDROID)
   result.set_api_version(base::android::android_info::sdk_int());
@@ -108,8 +108,8 @@ feedwire::Version GetAppVersionMessage(c
   // Chrome's version is in the format: MAJOR,MINOR,BUILD,PATCH.
   const std::vector<uint32_t>& numbers = chrome_info.version.components();
   if (numbers.size() > 3) {
-    result.set_major(static_cast<int32_t>(numbers[0]));
-    result.set_minor(static_cast<int32_t>(numbers[1]));
+    result.set_gmajor(static_cast<int32_t>(numbers[0]));
+    result.set_gminor(static_cast<int32_t>(numbers[1]));
     result.set_build(static_cast<int32_t>(numbers[2]));
     result.set_revision(static_cast<int32_t>(numbers[3]));
   }
