$NetBSD: patch-components_autofill_core_common_autofill__features.cc,v 1.10 2026/04/10 17:31:52 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/autofill/core/common/autofill_features.cc.orig	2026-04-06 16:25:54.000000000 +0000
+++ components/autofill/core/common/autofill_features.cc
@@ -10,7 +10,7 @@ namespace autofill::features {
 
 namespace {
 constexpr bool IS_AUTOFILL_AI_PLATFORM = BUILDFLAG(IS_CHROMEOS) ||
-                                         BUILDFLAG(IS_LINUX) ||
+                                         BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD) ||
                                          BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN);
 }  // namespace
 
