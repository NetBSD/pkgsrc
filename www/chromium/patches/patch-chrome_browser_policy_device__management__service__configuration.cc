$NetBSD: patch-chrome_browser_policy_device__management__service__configuration.cc,v 1.30 2026/10/16 15:30:45 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/policy/device_management_service_configuration.cc.orig	2026-10-14 21:09:54.000000000 +0000
+++ chrome/browser/policy/device_management_service_configuration.cc
@@ -22,7 +22,7 @@
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) ||           \
     ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && \
-     !BUILDFLAG(IS_ANDROID))
+     !BUILDFLAG(IS_ANDROID)) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/connectors/common.h"
 #include "chrome/browser/enterprise/connectors/connectors_service.h"
 #endif
