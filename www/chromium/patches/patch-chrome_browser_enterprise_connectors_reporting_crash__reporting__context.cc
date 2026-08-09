$NetBSD: patch-chrome_browser_enterprise_connectors_reporting_crash__reporting__context.cc,v 1.24 2026/08/09 06:31:08 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/enterprise/connectors/reporting/crash_reporting_context.cc.orig	2026-08-05 20:17:42.000000000 +0000
+++ chrome/browser/enterprise/connectors/reporting/crash_reporting_context.cc
@@ -30,7 +30,7 @@
 
 namespace enterprise_connectors {
 
-#if !BUILDFLAG(IS_CHROMEOS)
+#if !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_BSD)
 
 namespace {
 
