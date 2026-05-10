$NetBSD: patch-components_enterprise_browser_reporting_report__util.cc,v 1.15 2026/05/10 15:29:55 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/enterprise/browser/reporting/report_util.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ components/enterprise/browser/reporting/report_util.cc
@@ -200,7 +200,7 @@ std::string GetSecuritySignalsInReport(
     signals_dict.Set("antivirus_info", std::move(anti_virus_list));
 
     signals_dict.Set("hotfixes", RepeatedFieldptrToList(os_report.hotfixes()));
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     if (os_report.has_distribution_version()) {
       signals_dict.Set("distribution_version",
                        os_report.distribution_version());
