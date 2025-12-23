$NetBSD: patch-components_url__formatter_spoof__checks_idn__spoof__checker.cc,v 1.13 2025/12/23 13:22:18 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/url_formatter/spoof_checks/idn_spoof_checker.cc.orig	2025-12-17 23:05:18.000000000 +0000
+++ components/url_formatter/spoof_checks/idn_spoof_checker.cc
@@ -305,7 +305,7 @@ IDNSpoofChecker::IDNSpoofChecker() {
   // The ideal fix would be to change the omnibox font used for Thai. In
   // that case, the Linux-only list should be revisited and potentially
   // removed.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
        "[ทนบพรหเแ๐ดลปฟม]",
 #else
        "[บพเแ๐]",
