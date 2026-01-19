$NetBSD: patch-content_browser_font__access_font__enumeration__data__source.cc,v 1.14 2026/01/19 16:14:14 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/browser/font_access/font_enumeration_data_source.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ content/browser/font_access/font_enumeration_data_source.cc
@@ -16,7 +16,7 @@
 #include "content/browser/font_access/font_enumeration_data_source_win.h"
 #elif BUILDFLAG(IS_APPLE)
 #include "content/browser/font_access/font_enumeration_data_source_mac.h"
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "content/browser/font_access/font_enumeration_data_source_linux.h"
 #endif  // BUILDFLAG(IS_WIN)
 
@@ -61,7 +61,7 @@ std::unique_ptr<FontEnumerationDataSourc
   return std::make_unique<FontEnumerationDataSourceWin>();
 #elif BUILDFLAG(IS_APPLE)
   return std::make_unique<FontEnumerationDataSourceMac>();
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return std::make_unique<FontEnumerationDataSourceLinux>();
 #else
   return std::make_unique<FontEnumerationDataSourceNull>();
@@ -76,7 +76,7 @@ bool FontEnumerationDataSource::IsOsSupp
   return true;
 #elif BUILDFLAG(IS_APPLE)
   return true;
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return false;
