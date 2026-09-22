$NetBSD: patch-components_url__formatter_spoof__checks_idn__spoof__checker.cc,v 1.26 2026/09/22 13:41:25 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/url_formatter/spoof_checks/idn_spoof_checker.cc.orig	2026-09-14 22:17:16.000000000 +0000
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
