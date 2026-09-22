$NetBSD: patch-chrome_browser_ui_startup_startup__browser__creator__impl.cc,v 1.26 2026/09/22 13:41:21 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/startup/startup_browser_creator_impl.cc.orig	2026-09-14 22:17:16.000000000 +0000
+++ chrome/browser/ui/startup/startup_browser_creator_impl.cc
@@ -70,7 +70,7 @@
 #include "content/public/common/content_switches.h"
 #include "url/origin.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/nix/xdg_util.h"
 #include "ui/display/screen.h"
 #endif
@@ -93,7 +93,7 @@
 #include "chrome/browser/ui/browser_window/public/profile_browser_collection.h"
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/search_integrity/search_integrity.h"
 #include "chrome/browser/search_integrity/search_integrity_factory.h"
 #include "chrome/browser/ui/webui/whats_new/whats_new_fetcher.h"
@@ -166,7 +166,7 @@ Browser* GetExistingBrowserForOpenBehavi
       BrowserCollection::Order::kActivation);
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   const bool match_original_profiles =
       process_startup == chrome::startup::IsProcessStartup::kYes;
   display::Screen* const screen = display::Screen::Get();
@@ -254,7 +254,7 @@ void StartupBrowserCreatorImpl::Launch(
   DCHECK(profile);
   profile_ = profile;
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Check for DSE integrity if flag is enabled.
   if (base::FeatureList::IsEnabled(features::kDseIntegrity)) {
     if (auto* search_integrity_service =
@@ -308,7 +308,7 @@ BrowserWindowInterface* StartupBrowserCr
     profile_ = browser->GetProfile();
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::string startup_id =
       command_line_->GetSwitchValueASCII(base::nix::kXdgActivationTokenSwitch);
   if (startup_id.empty()) {
@@ -337,7 +337,7 @@ BrowserWindowInterface* StartupBrowserCr
     BrowserWindowCreateParams params(profile_, false);
     params.creation_source =
         BrowserWindowCreateParams::CreationSource::kStartupCreator;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     params.startup_id = startup_id;
 #endif
     if (command_line_->HasSwitch(switches::kWindowName)) {
@@ -374,7 +374,7 @@ BrowserWindowInterface* StartupBrowserCr
       continue;
     }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // Start the What's New fetch but don't add the tab at this point. The tab
     // will open as the foreground tab only if the remote content can be
     // retrieved successfully. This prevents needing to automatically close the
@@ -465,7 +465,7 @@ BrowserWindowInterface* StartupBrowserCr
     }
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!create_new_browser && !startup_id.empty()) {
     base::nix::SetActivationToken(startup_id);
   }
