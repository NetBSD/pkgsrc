$NetBSD: patch-components_variations_net_variations__command__line.cc,v 1.1 2025/07/07 09:23:31 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/variations/net/variations_command_line.cc.orig	2025-06-30 06:54:11.000000000 +0000
+++ components/variations/net/variations_command_line.cc
@@ -50,7 +50,7 @@ void ExitWithMessage(const std::string& 
 namespace variations {
 
 #if !BUILDFLAG(IS_CHROMEOS)
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kFeedbackIncludeVariations,
              "FeedbackIncludeVariations",
              base::FEATURE_ENABLED_BY_DEFAULT);
