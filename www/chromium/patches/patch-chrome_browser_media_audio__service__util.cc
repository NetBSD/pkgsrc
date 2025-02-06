$NetBSD: patch-chrome_browser_media_audio__service__util.cc,v 1.1 2025/02/06 09:57:48 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/media/audio_service_util.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ chrome/browser/media/audio_service_util.cc
@@ -21,7 +21,7 @@
 
 namespace {
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD) || \
     (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS))
 const base::Value* GetPolicy(const char* policy_name) {
   const policy::PolicyMap& policies =
@@ -43,7 +43,7 @@ bool GetPolicyOrFeature(const char* poli
 bool IsAudioServiceSandboxEnabled() {
 // TODO(crbug.com/40118868): Remove !IS_CHROMEOS_LACROS once lacros starts being
 // built with OS_CHROMEOS instead of OS_LINUX.
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD) || \
     (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS))
   return GetPolicyOrFeature(policy::key::kAudioSandboxEnabled,
                             features::kAudioServiceSandbox);
