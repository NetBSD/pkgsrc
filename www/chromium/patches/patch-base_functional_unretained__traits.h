$NetBSD: patch-base_functional_unretained__traits.h,v 1.16 2026/03/14 12:40:23 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/functional/unretained_traits.h.orig	2026-03-11 22:12:25.000000000 +0000
+++ base/functional/unretained_traits.h
@@ -92,7 +92,7 @@ struct SupportsUnretainedImpl {
 // official builds, and then in non-test code as well.
 #if defined(FORCE_UNRETAINED_COMPLETENESS_CHECKS_FOR_TESTS) || \
     (!defined(UNIT_TEST) && !defined(OFFICIAL_BUILD) &&        \
-     (BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)))
+     (BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)))
       static_assert(v,
                     "Argument requires unretained storage, but type is not "
                     "fully defined. This prevents determining whether "
