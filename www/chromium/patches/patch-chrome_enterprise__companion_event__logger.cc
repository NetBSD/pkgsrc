$NetBSD: patch-chrome_enterprise__companion_event__logger.cc,v 1.13 2026/01/19 16:14:12 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/enterprise_companion/event_logger.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ chrome/enterprise_companion/event_logger.cc
@@ -125,7 +125,7 @@ proto::EnterpriseCompanionMetadata GetMe
   metadata.set_application_arch(proto::ARM64);
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   metadata.set_os_platform(proto::LINUX);
 #elif BUILDFLAG(IS_MAC)
   metadata.set_os_platform(proto::MAC);
