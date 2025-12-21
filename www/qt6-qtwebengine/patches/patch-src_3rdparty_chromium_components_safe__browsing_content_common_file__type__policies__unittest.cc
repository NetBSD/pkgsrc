$NetBSD: patch-src_3rdparty_chromium_components_safe__browsing_content_common_file__type__policies__unittest.cc,v 1.1 2025/12/21 09:38:24 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/components/safe_browsing/content/common/file_type_policies_unittest.cc.orig	2025-10-02 00:36:39.000000000 +0000
+++ src/3rdparty/chromium/components/safe_browsing/content/common/file_type_policies_unittest.cc
@@ -146,7 +146,7 @@ TEST_F(FileTypePoliciesTest, UnpackResou
   EXPECT_EQ(142, file_type.uma_value());
   EXPECT_FALSE(file_type.is_archive());
   EXPECT_EQ(DownloadFileType::FULL_PING, file_type.ping_setting());
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   EXPECT_EQ(DownloadFileType::ALLOW_ON_USER_GESTURE,
             file_type.platform_settings(0).danger_level());
   EXPECT_EQ(DownloadFileType::DISALLOW_AUTO_OPEN,
