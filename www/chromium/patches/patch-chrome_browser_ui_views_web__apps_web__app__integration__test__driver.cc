$NetBSD: patch-chrome_browser_ui_views_web__apps_web__app__integration__test__driver.cc,v 1.1 2025/02/06 09:57:54 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/web_apps/web_app_integration_test_driver.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ chrome/browser/ui/views/web_apps/web_app_integration_test_driver.cc
@@ -516,7 +516,7 @@ std::string GetFileExtension(FileExtensi
 }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 SiteConfig GetSiteConfigurationFromAppName(const std::string& app_name) {
   SiteConfig config;
   bool is_app_found = false;
@@ -2109,7 +2109,7 @@ void WebAppIntegrationTestDriver::Delete
   if (app_name.empty()) {
     app_name = GetSiteConfiguration(site).app_name;
   }
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   ASSERT_TRUE(override_registration_->test_override().IsShortcutCreated(
       profile(), app_id, app_name));
   ASSERT_TRUE(
@@ -3452,7 +3452,7 @@ void WebAppIntegrationTestDriver::CheckR
           app_state->id, app_state->name);
   ASSERT_TRUE(icon_color.has_value());
   ASSERT_THAT(site_config.icon_color, testing::Eq(icon_color.value()));
-#elif BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   ASSERT_TRUE(override_registration_->test_override().IsRunOnOsLoginEnabled(
       profile(), app_state->id, app_state->name));
 #endif
@@ -3467,7 +3467,7 @@ void WebAppIntegrationTestDriver::CheckR
       GetAppBySiteMode(after_state_change_action_state_.get(), profile(), site);
   ASSERT_TRUE(app_state);
   base::ScopedAllowBlockingForTesting allow_blocking;
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   ASSERT_FALSE(override_registration_->test_override().IsRunOnOsLoginEnabled(
       profile(), app_state->id, app_state->name));
 #endif
@@ -3477,7 +3477,7 @@ void WebAppIntegrationTestDriver::CheckR
 void WebAppIntegrationTestDriver::CheckSiteHandlesFile(
     Site site,
     FileExtension file_extension) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!BeforeStateCheckAction(__FUNCTION__)) {
     return;
   }
@@ -3493,7 +3493,7 @@ void WebAppIntegrationTestDriver::CheckS
 void WebAppIntegrationTestDriver::CheckSiteNotHandlesFile(
     Site site,
     FileExtension file_extension) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!BeforeStateCheckAction(__FUNCTION__)) {
     return;
   }
@@ -4310,7 +4310,7 @@ base::FilePath WebAppIntegrationTestDriv
     base::FilePath shortcut_dir,
     const std::string& app_name,
     const webapps::AppId& app_id) {
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   return override_registration_->test_override().GetShortcutPath(
       profile(), shortcut_dir, app_id, app_name);
 #else
@@ -4510,7 +4510,7 @@ bool WebAppIntegrationTestDriver::IsShor
     const webapps::AppId& id) {
   base::ScopedAllowBlockingForTesting allow_blocking;
   bool is_shortcut_and_icon_correct = false;
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool is_shortcut_correct =
       override_registration_->test_override().IsShortcutCreated(profile, id,
                                                                 name);
@@ -4554,7 +4554,7 @@ bool WebAppIntegrationTestDriver::DoIcon
     do_icon_colors_match =
         (expected_icon_pixel_color == shortcut_pixel_color_apps_folder.value());
   }
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   SkColor expected_icon_pixel_color =
       GetSiteConfigurationFromAppName(name).icon_color;
   std::optional<SkColor> actual_color_install_icon_size =
