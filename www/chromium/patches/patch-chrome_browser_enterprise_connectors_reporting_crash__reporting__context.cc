$NetBSD: patch-chrome_browser_enterprise_connectors_reporting_crash__reporting__context.cc,v 1.17 2026/04/10 17:31:48 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/enterprise/connectors/reporting/crash_reporting_context.cc.orig	2026-04-06 16:25:54.000000000 +0000
+++ chrome/browser/enterprise/connectors/reporting/crash_reporting_context.cc
@@ -29,7 +29,7 @@
 
 namespace enterprise_connectors {
 
-#if !BUILDFLAG(IS_CHROMEOS)
+#if !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_BSD)
 
 namespace {
 
