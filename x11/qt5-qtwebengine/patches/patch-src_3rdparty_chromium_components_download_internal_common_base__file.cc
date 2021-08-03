$NetBSD: patch-src_3rdparty_chromium_components_download_internal_common_base__file.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/components/download/internal/common/base_file.cc.orig	2020-07-08 21:40:39.000000000 +0000
+++ src/3rdparty/chromium/components/download/internal/common/base_file.cc
@@ -604,7 +604,7 @@ GURL GetEffectiveAuthorityURL(const GURL
 
 }  // namespace
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 
 DownloadInterruptReason BaseFile::AnnotateWithSourceInformationSync(
     const std::string& client_guid,
