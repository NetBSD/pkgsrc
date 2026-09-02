$NetBSD: patch-components_feed_core_v2_proto__util__unittest.cc,v 1.25 2026/09/02 13:13:28 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/feed/core/v2/proto_util_unittest.cc.orig	2026-08-31 22:47:51.000000000 +0000
+++ components/feed/core/v2/proto_util_unittest.cc
@@ -46,8 +46,8 @@ TEST(ProtoUtilTest, CreateClientInfo) {
   feedwire::ClientInfo result = CreateClientInfo(request_metadata);
   EXPECT_EQ(feedwire::ClientInfo::CHROME_ANDROID, result.app_type());
   EXPECT_EQ(feedwire::Version::RELEASE, result.app_version().build_type());
-  EXPECT_EQ(1, result.app_version().major());
-  EXPECT_EQ(2, result.app_version().minor());
+  EXPECT_EQ(1, result.app_version().gmajor());
+  EXPECT_EQ(2, result.app_version().gminor());
   EXPECT_EQ(3, result.app_version().build());
   EXPECT_EQ(4, result.app_version().revision());
 
