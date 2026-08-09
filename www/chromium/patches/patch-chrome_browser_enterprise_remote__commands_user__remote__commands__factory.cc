$NetBSD: patch-chrome_browser_enterprise_remote__commands_user__remote__commands__factory.cc,v 1.4 2026/08/09 06:31:08 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/enterprise/remote_commands/user_remote_commands_factory.cc.orig	2026-08-05 20:17:42.000000000 +0000
+++ chrome/browser/enterprise/remote_commands/user_remote_commands_factory.cc
@@ -22,7 +22,7 @@ UserRemoteCommandsFactory::BuildJobForTy
   switch (type) {
     case enterprise_management::RemoteCommand_Type_BROWSER_CLEAR_BROWSING_DATA:
       return std::make_unique<ClearBrowsingDataJob>(profile_);
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     case enterprise_management::
         RemoteCommand_Type_BROWSER_EXTENSION_UPDATE_CHECK:
       return std::make_unique<ExtensionUpdateCheckJob>(profile_);
