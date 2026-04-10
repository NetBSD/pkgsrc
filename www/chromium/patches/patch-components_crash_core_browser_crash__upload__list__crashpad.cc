$NetBSD: patch-components_crash_core_browser_crash__upload__list__crashpad.cc,v 1.17 2026/04/10 17:31:52 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/crash/core/browser/crash_upload_list_crashpad.cc.orig	2026-04-06 16:25:54.000000000 +0000
+++ components/crash/core/browser/crash_upload_list_crashpad.cc
@@ -37,7 +37,9 @@ CrashUploadListCrashpad::~CrashUploadLis
 std::vector<std::unique_ptr<UploadList::UploadInfo>>
 CrashUploadListCrashpad::LoadUploadList() {
   std::vector<crash_reporter::Report> reports;
+#if !BUILDFLAG(IS_BSD)
   crash_reporter::GetReports(&reports);
+#endif
 
   std::vector<std::unique_ptr<UploadInfo>> uploads;
   for (const crash_reporter::Report& report : reports) {
@@ -51,9 +53,13 @@ CrashUploadListCrashpad::LoadUploadList(
 
 void CrashUploadListCrashpad::ClearUploadList(const base::Time& begin,
                                               const base::Time& end) {
+#if !BUILDFLAG(IS_BSD)
   crash_reporter::ClearReportsBetween(begin, end);
+#endif
 }
 
 void CrashUploadListCrashpad::RequestSingleUpload(const std::string& local_id) {
+#if !BUILDFLAG(IS_BSD)
   crash_reporter::RequestSingleCrashUpload(local_id);
+#endif
 }
