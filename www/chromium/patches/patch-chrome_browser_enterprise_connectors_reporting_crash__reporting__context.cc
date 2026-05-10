$NetBSD: patch-chrome_browser_enterprise_connectors_reporting_crash__reporting__context.cc,v 1.19 2026/05/10 15:29:49 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/enterprise/connectors/reporting/crash_reporting_context.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ chrome/browser/enterprise/connectors/reporting/crash_reporting_context.cc
@@ -29,7 +29,7 @@
 
 namespace enterprise_connectors {
 
-#if !BUILDFLAG(IS_CHROMEOS)
+#if !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_BSD)
 
 namespace {
 
