$NetBSD: patch-components_safe__browsing_content_common_file__type__policies__unittest.cc,v 1.1 2025/02/06 09:58:02 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/safe_browsing/content/common/file_type_policies_unittest.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ components/safe_browsing/content/common/file_type_policies_unittest.cc
@@ -148,7 +148,7 @@ TEST_F(FileTypePoliciesTest, UnpackResou
   EXPECT_EQ(DownloadFileType::FULL_PING, file_type.ping_setting());
 // TODO(crbug.com/40118868): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   EXPECT_EQ(DownloadFileType::ALLOW_ON_USER_GESTURE,
             file_type.platform_settings(0).danger_level());
   EXPECT_EQ(DownloadFileType::DISALLOW_AUTO_OPEN,
