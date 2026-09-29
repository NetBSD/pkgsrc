$NetBSD: patch-chrome_common_extensions_permissions_chrome__permission__message__rules.cc,v 1.27 2026/09/29 07:42:53 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/common/extensions/permissions/chrome_permission_message_rules.cc.orig	2026-09-22 00:09:16.000000000 +0000
+++ chrome/common/extensions/permissions/chrome_permission_message_rules.cc
@@ -281,7 +281,7 @@ class USBDevicesFormatter : public Chrom
 int GetEnterpriseReportingPrivatePermissionMessageId() {
 #if BUILDFLAG(IS_WIN)
   return IDS_EXTENSION_PROMPT_WARNING_ENTERPRISE_REPORTING_PRIVATE_ENABLED_WIN;
-#elif BUILDFLAG(IS_LINUX) or BUILDFLAG(IS_MAC)
+#elif BUILDFLAG(IS_LINUX) or BUILDFLAG(IS_MAC) or BUILDFLAG(IS_BSD)
   return IDS_EXTENSION_PROMPT_WARNING_ENTERPRISE_REPORTING_PRIVATE_ENABLED_LINUX_AND_MACOS;
 #else
   return IDS_EXTENSION_PROMPT_WARNING_ENTERPRISE_REPORTING_PRIVATE;
