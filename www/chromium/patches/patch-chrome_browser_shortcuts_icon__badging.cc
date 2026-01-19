$NetBSD: patch-chrome_browser_shortcuts_icon__badging.cc,v 1.14 2026/01/19 16:14:09 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/shortcuts/icon_badging.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ chrome/browser/shortcuts/icon_badging.cc
@@ -59,7 +59,7 @@ enum class BadgeSize {
 constexpr ShortcutSize kSizesNeededForShortcutCreation[] = {
     ShortcutSize::k16, ShortcutSize::k32, ShortcutSize::k128,
     ShortcutSize::k256, ShortcutSize::k512};
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 constexpr ShortcutSize kSizesNeededForShortcutCreation[] = {ShortcutSize::k32,
                                                             ShortcutSize::k128};
 #elif BUILDFLAG(IS_WIN)
