$NetBSD: patch-src_3rdparty_chromium_base_functional_unretained__traits.h,v 1.1 2025/12/21 09:38:13 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/base/functional/unretained_traits.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/base/functional/unretained_traits.h
@@ -93,7 +93,7 @@ struct SupportsUnretainedImpl {
 // official builds, and then in non-test code as well.
 #if defined(FORCE_UNRETAINED_COMPLETENESS_CHECKS_FOR_TESTS) || \
     (!defined(UNIT_TEST) && !defined(OFFICIAL_BUILD) &&        \
-     (BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)))
+     (BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)))
       static_assert(v,
                     "Argument requires unretained storage, but type is not "
                     "fully defined. This prevents determining whether "
