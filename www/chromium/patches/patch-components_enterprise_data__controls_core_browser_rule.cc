$NetBSD: patch-components_enterprise_data__controls_core_browser_rule.cc,v 1.28 2026/11/08 15:38:59 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/enterprise/data_controls/core/browser/rule.cc.orig	2026-11-02 23:22:33.000000000 +0000
+++ components/enterprise/data_controls/core/browser/rule.cc
@@ -665,7 +665,7 @@ bool Rule::AddUnsupportedAttributeErrors
           AttributesCondition::kKeyUrlRegexprs,
       });
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   static constexpr auto kFileDownloadAttributes =
       std::to_array<std::string_view>({
           AttributesCondition::kKeyUrls,
@@ -683,7 +683,7 @@ bool Rule::AddUnsupportedAttributeErrors
           {Restriction::kClipboard, kClipboardAttributes},
           {Restriction::kScreenshot, kScreenshotAttributes},
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
           {Restriction::kFileDownload, kFileDownloadAttributes},
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
         // BUILDFLAG(IS_CHROMEOS)
@@ -694,7 +694,7 @@ bool Rule::AddUnsupportedAttributeErrors
           {Restriction::kClipboard, kSourceClipboardAttributes},
           {Restriction::kScreenshot, kSourceAndDestinationScreenshotAttributes},
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
           {Restriction::kFileDownload, kFileDownloadAttributes},
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
         // BUILDFLAG(IS_CHROMEOS)
@@ -705,7 +705,7 @@ bool Rule::AddUnsupportedAttributeErrors
           {Restriction::kClipboard, kDestinationClipboardAttributes},
           {Restriction::kScreenshot, kSourceAndDestinationScreenshotAttributes},
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
           {Restriction::kFileDownload, kFileDownloadAttributes},
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
         // BUILDFLAG(IS_CHROMEOS)
@@ -781,7 +781,7 @@ bool Rule::AddUnsupportedRestrictionErro
   });
 #endif  // BUILDFLAG(ENTERPRISE_SCREENSHOT_PROTECTION)
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   static constexpr auto kFileDownloadSupportedLevels = std::to_array<Level>({
       Level::kNotSet,
       Level::kReport,
@@ -798,7 +798,7 @@ bool Rule::AddUnsupportedRestrictionErro
           {Restriction::kScreenshot, kScreenshotSupportedLevels},
 #endif  // BUILDFLAG(ENTERPRISE_SCREENSHOT_PROTECTION)
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
           {Restriction::kFileDownload, kFileDownloadSupportedLevels},
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
         // BUILDFLAG(IS_CHROMEOS)
