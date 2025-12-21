$NetBSD: patch-src_3rdparty_chromium_base_system_sys__info__unittest.cc,v 1.1 2025/12/21 09:38:16 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/base/system/sys_info_unittest.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/base/system/sys_info_unittest.cc
@@ -265,12 +265,16 @@ TEST_F(SysInfoTest, GetHardwareInfo) {
   EXPECT_TRUE(IsStringUTF8(hardware_info->model));
   bool empty_result_expected =
 #if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || \
+    BUILDFLAG(IS_BSD)
       false;
 #else
       true;
 #endif
   EXPECT_EQ(hardware_info->manufacturer.empty(), empty_result_expected);
+#if BUILDFLAG(IS_BSD)
+  empty_result_expected = true;
+#endif
   EXPECT_EQ(hardware_info->model.empty(), empty_result_expected);
 }
 
