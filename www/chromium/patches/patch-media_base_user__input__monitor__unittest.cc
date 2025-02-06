$NetBSD: patch-media_base_user__input__monitor__unittest.cc,v 1.1 2025/02/06 09:58:12 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- media/base/user_input_monitor_unittest.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ media/base/user_input_monitor_unittest.cc
@@ -13,7 +13,7 @@
 #include "build/build_config.h"
 #include "testing/gtest/include/gtest/gtest.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "base/files/file_descriptor_watcher_posix.h"
 #endif
 
@@ -49,7 +49,7 @@ class UserInputMonitorTest : public test
 }  // namespace
 
 TEST_F(UserInputMonitorTest, CreatePlatformSpecific) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   base::test::TaskEnvironment task_environment(
       base::test::TaskEnvironment::MainThreadType::IO);
 #else
@@ -72,7 +72,7 @@ TEST_F(UserInputMonitorTest, CreatePlatf
 }
 
 TEST_F(UserInputMonitorTest, CreatePlatformSpecificWithMapping) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   base::test::TaskEnvironment task_environment(
       base::test::TaskEnvironment::MainThreadType::IO);
 #else
