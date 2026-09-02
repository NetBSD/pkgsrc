$NetBSD: patch-components_enterprise_browser_reporting_report__util.cc,v 1.21 2026/09/02 13:13:28 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/enterprise/browser/reporting/report_util.cc.orig	2026-08-31 22:47:51.000000000 +0000
+++ components/enterprise/browser/reporting/report_util.cc
@@ -201,7 +201,7 @@ std::string GetSecuritySignalsInReport(
     signals_dict.Set("antivirus_info", std::move(anti_virus_list));
 
     signals_dict.Set("hotfixes", RepeatedFieldptrToList(os_report.hotfixes()));
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     if (os_report.has_distribution_version()) {
       signals_dict.Set("distribution_version",
                        os_report.distribution_version());
