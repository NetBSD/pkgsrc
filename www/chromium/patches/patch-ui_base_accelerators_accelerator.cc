$NetBSD: patch-ui_base_accelerators_accelerator.cc,v 1.1 2025/05/16 16:08:33 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/base/accelerators/accelerator.cc.orig	2025-05-05 19:21:24.000000000 +0000
+++ ui/base/accelerators/accelerator.cc
@@ -336,7 +336,7 @@ std::u16string Accelerator::ApplyLongFor
     result = ApplyModifierToAcceleratorString(result, IDS_APP_SEARCH_KEY);
 #elif BUILDFLAG(IS_WIN)
     result = ApplyModifierToAcceleratorString(result, IDS_APP_WINDOWS_KEY);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     result = ApplyModifierToAcceleratorString(result, IDS_APP_SUPER_KEY);
 #else
     NOTREACHED();
