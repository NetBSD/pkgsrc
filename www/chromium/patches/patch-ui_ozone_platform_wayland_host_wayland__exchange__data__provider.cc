$NetBSD: patch-ui_ozone_platform_wayland_host_wayland__exchange__data__provider.cc,v 1.1 2026/03/14 12:40:45 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/ozone/platform/wayland/host/wayland_exchange_data_provider.cc.orig	2026-03-11 22:12:25.000000000 +0000
+++ ui/ozone/platform/wayland/host/wayland_exchange_data_provider.cc
@@ -74,7 +74,7 @@ int MimeTypeToFormat(const std::string& 
   if (mime_type == ui::kMimeTypeDataTransferCustomData) {
     return OSExchangeData::PICKLED_DATA;
   }
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (mime_type == ui::kMimeTypePortalFileTransfer ||
       mime_type == ui::kMimeTypePortalFiles) {
     return OSExchangeData::PICKLED_DATA;
@@ -213,7 +213,7 @@ std::unique_ptr<OSExchangeDataProvider> 
     const {
   auto clone = std::make_unique<WaylandExchangeDataProvider>();
   CopyData(clone.get());
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   clone->additional_data_ = additional_data_;
 #endif
   return clone;
@@ -223,7 +223,7 @@ void WaylandExchangeDataProvider::SetFil
     const std::vector<FileInfo>& filenames) {
   OSExchangeDataProviderNonBacked::SetFilenames(filenames);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Synchronously register files to get the key. This blocks the UI thread
   // briefly but ensures the key is ready for the data offer.
   std::string key = ui::clipboard_util::RegisterFilesWithPortal(filenames);
@@ -267,7 +267,7 @@ std::vector<std::string> WaylandExchange
     mime_types.push_back(mime_type);
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   for (const auto& item : additional_data_) {
     mime_types.push_back(item.first);
   }
@@ -285,7 +285,7 @@ void WaylandExchangeDataProvider::AddDat
   DCHECK(data);
   DCHECK(IsMimeTypeSupported(mime_type));
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (mime_type == ui::kMimeTypePortalFileTransfer ||
       mime_type == ui::kMimeTypePortalFiles) {
     additional_data_[mime_type] = base::as_string_view(*data);
@@ -359,7 +359,7 @@ bool WaylandExchangeDataProvider::Extrac
                                pickle->size());
     return true;
   }
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   auto it = additional_data_.find(mime_type);
   if (it != additional_data_.end()) {
     *out_content = it->second;
