$NetBSD: patch-ui_base_accelerators_accelerator.cc,v 1.8 2025/11/04 14:55:49 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/base/accelerators/accelerator.cc.orig	2025-10-24 16:42:30.000000000 +0000
+++ ui/base/accelerators/accelerator.cc
@@ -335,7 +335,7 @@ std::vector<std::u16string> Accelerator:
     modifiers.push_back(l10n_util::GetStringUTF16(IDS_APP_SEARCH_KEY));
 #elif BUILDFLAG(IS_WIN)
     modifiers.push_back(l10n_util::GetStringUTF16(IDS_APP_WINDOWS_KEY));
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     modifiers.push_back(l10n_util::GetStringUTF16(IDS_APP_SUPER_KEY));
 #else
     NOTREACHED();
