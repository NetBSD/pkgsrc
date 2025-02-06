$NetBSD: patch-components_feed_core_v2_feed__network__impl__unittest.cc,v 1.1 2025/02/06 09:58:00 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/feed/core/v2/feed_network_impl_unittest.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ components/feed/core/v2/feed_network_impl_unittest.cc
@@ -747,8 +747,8 @@ TEST_F(FeedNetworkTest, SendApiRequest_D
 
   EXPECT_EQ(feedwire::ClientInfo::CHROME_ANDROID, client_info.app_type());
   EXPECT_EQ(feedwire::Version::RELEASE, client_info.app_version().build_type());
-  EXPECT_EQ(1, client_info.app_version().major());
-  EXPECT_EQ(2, client_info.app_version().minor());
+  EXPECT_EQ(1, client_info.app_version().gmajor());
+  EXPECT_EQ(2, client_info.app_version().gminor());
   EXPECT_EQ(3, client_info.app_version().build());
   EXPECT_EQ(4, client_info.app_version().revision());
   EXPECT_FALSE(client_info.chrome_client_info().start_surface());
