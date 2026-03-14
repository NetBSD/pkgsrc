$NetBSD: patch-chrome_browser_ui_browser__view__prefs.cc,v 1.16 2026/03/14 12:40:27 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/browser_view_prefs.cc.orig	2026-03-11 22:12:25.000000000 +0000
+++ chrome/browser/ui/browser_view_prefs.cc
@@ -14,7 +14,7 @@
 
 namespace {
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool GetCustomFramePrefDefault() {
 #if BUILDFLAG(IS_OZONE)
   return ui::OzonePlatform::GetInstance()
@@ -30,7 +30,7 @@ bool GetCustomFramePrefDefault() {
 
 void RegisterBrowserViewProfilePrefs(
     user_prefs::PrefRegistrySyncable* registry) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   registry->RegisterBooleanPref(prefs::kUseCustomChromeFrame,
                                 GetCustomFramePrefDefault());
 #endif
