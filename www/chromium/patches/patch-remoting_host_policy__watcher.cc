$NetBSD: patch-remoting_host_policy__watcher.cc,v 1.24 2026/08/09 06:31:20 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/host/policy_watcher.cc.orig	2026-08-05 20:17:42.000000000 +0000
+++ remoting/host/policy_watcher.cc
@@ -183,7 +183,7 @@ base::DictValue PolicyWatcher::GetDefaul
   result.Set(key::kRemoteAccessHostAllowEnterpriseFileTransfer, false);
   result.Set(key::kClassManagementEnabled, "disabled");
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   result.Set(key::kRemoteAccessHostMatchUsername, false);
 #endif
 #if !BUILDFLAG(IS_CHROMEOS)
