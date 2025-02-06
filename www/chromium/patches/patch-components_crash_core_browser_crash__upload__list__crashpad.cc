$NetBSD: patch-components_crash_core_browser_crash__upload__list__crashpad.cc,v 1.1 2025/02/06 09:57:58 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/crash/core/browser/crash_upload_list_crashpad.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ components/crash/core/browser/crash_upload_list_crashpad.cc
@@ -38,7 +38,9 @@ CrashUploadListCrashpad::~CrashUploadLis
 std::vector<std::unique_ptr<UploadList::UploadInfo>>
 CrashUploadListCrashpad::LoadUploadList() {
   std::vector<crash_reporter::Report> reports;
+#if !BUILDFLAG(IS_BSD)
   crash_reporter::GetReports(&reports);
+#endif
 
   std::vector<std::unique_ptr<UploadInfo>> uploads;
   for (const crash_reporter::Report& report : reports) {
@@ -52,9 +54,13 @@ CrashUploadListCrashpad::LoadUploadList(
 
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
