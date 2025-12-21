$NetBSD: patch-src_3rdparty_chromium_components_url__formatter_spoof__checks_idn__spoof__checker.cc,v 1.1 2025/12/21 09:38:25 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/components/url_formatter/spoof_checks/idn_spoof_checker.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/components/url_formatter/spoof_checks/idn_spoof_checker.cc
@@ -294,7 +294,7 @@ IDNSpoofChecker::IDNSpoofChecker() {
   // The ideal fix would be to change the omnibox font used for Thai. In
   // that case, the Linux-only list should be revisited and potentially
   // removed.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
        "[ทนบพรหเแ๐ดลปฟม]",
 #else
        "[บพเแ๐]",
