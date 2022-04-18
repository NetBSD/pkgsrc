$NetBSD: patch-src_3rdparty_chromium_content_browser_utility__process__host.cc,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/content/browser/utility_process_host.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/content/browser/utility_process_host.cc
@@ -59,7 +59,7 @@ UtilityProcessHost::UtilityProcessHost()
 
 UtilityProcessHost::UtilityProcessHost(std::unique_ptr<Client> client)
     : sandbox_type_(sandbox::policy::SandboxType::kUtility),
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
       child_flags_(ChildProcessHost::CHILD_ALLOW_SELF),
 #else
       child_flags_(ChildProcessHost::CHILD_NORMAL),
@@ -270,7 +270,7 @@ bool UtilityProcessHost::StartProcess() 
       switches::kMuteAudio,
       switches::kUseFileForFakeAudioCapture,
       switches::kAgcStartupMinVolume,
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_FREEBSD) || \
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD) || \
     defined(OS_SOLARIS)
       switches::kAlsaInputDevice,
       switches::kAlsaOutputDevice,
