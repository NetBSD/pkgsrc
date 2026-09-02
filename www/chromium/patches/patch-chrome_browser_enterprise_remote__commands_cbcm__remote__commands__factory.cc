$NetBSD: patch-chrome_browser_enterprise_remote__commands_cbcm__remote__commands__factory.cc,v 1.25 2026/09/02 13:13:23 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/enterprise/remote_commands/cbcm_remote_commands_factory.cc.orig	2026-08-31 22:47:51.000000000 +0000
+++ chrome/browser/enterprise/remote_commands/cbcm_remote_commands_factory.cc
@@ -12,7 +12,7 @@
 #include "chrome/browser/profiles/profile_manager.h"
 #include "components/policy/core/common/remote_commands/remote_command_job.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/remote_commands/rotate_attestation_credential_job.h"
 #include "chrome/browser/policy/chrome_browser_policy_connector.h"
 #include "components/enterprise/browser/controller/chrome_browser_cloud_management_controller.h"
@@ -31,7 +31,7 @@ CBCMRemoteCommandsFactory::BuildJobForTy
         g_browser_process->profile_manager());
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   if (type == enterprise_management::
                   RemoteCommand_Type_BROWSER_EXTENSION_UPDATE_CHECK) {
     return std::make_unique<ExtensionUpdateCheckJob>(
