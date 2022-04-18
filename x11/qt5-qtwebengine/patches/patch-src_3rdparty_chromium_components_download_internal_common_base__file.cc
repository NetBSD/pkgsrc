$NetBSD: patch-src_3rdparty_chromium_components_download_internal_common_base__file.cc,v 1.2 2022/04/18 11:18:18 adam Exp $

--- src/3rdparty/chromium/components/download/internal/common/base_file.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/components/download/internal/common/base_file.cc
@@ -605,7 +605,7 @@ GURL GetEffectiveAuthorityURL(const GURL
 }  // namespace
 
 #if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || \
-    defined(OS_CHROMEOS)
+    defined(OS_CHROMEOS) || defined(OS_BSD)
 
 DownloadInterruptReason BaseFile::AnnotateWithSourceInformationSync(
     const std::string& client_guid,
