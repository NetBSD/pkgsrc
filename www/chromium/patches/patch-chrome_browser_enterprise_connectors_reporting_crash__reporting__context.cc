$NetBSD: patch-chrome_browser_enterprise_connectors_reporting_crash__reporting__context.cc,v 1.33 2026/11/19 19:45:52 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/enterprise/connectors/reporting/crash_reporting_context.cc.orig	2026-11-11 21:01:38.000000000 +0000
+++ chrome/browser/enterprise/connectors/reporting/crash_reporting_context.cc
@@ -30,7 +30,7 @@
 
 namespace enterprise_connectors {
 
-#if !BUILDFLAG(IS_CHROMEOS)
+#if !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_BSD)
 
 namespace {
 
