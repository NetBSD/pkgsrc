$NetBSD: patch-chromeos_ash_components_mojo__proxy_mojo__core_core_channel.cc,v 1.1 2026/08/09 06:31:13 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chromeos/ash/components/mojo_proxy/mojo_core/core/channel.cc.orig	2026-08-05 20:17:42.000000000 +0000
+++ chromeos/ash/components/mojo_proxy/mojo_core/core/channel.cc
@@ -268,7 +268,7 @@ bool ShouldRecordSubsampledHistograms() 
 }  // namespace
 
 #if BUILDFLAG(IS_ANDROID) || \
-    (BUILDFLAG(IS_LINUX) && defined(FUZZING_BUILD_MODE_UNSAFE_FOR_PRODUCTION))
+    ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && defined(FUZZING_BUILD_MODE_UNSAFE_FOR_PRODUCTION))
 
 namespace {
 
@@ -1317,7 +1317,7 @@ bool Channel::OnControlMessage(Message::
 }
 
 // Currently only CrOs, Linux, and Android support upgrades.
-#if !(BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID))
+#if !(BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD))
 // static
 MOJO_LEGACY_SYSTEM_IMPL_EXPORT bool Channel::SupportsChannelUpgrade() {
   return false;
