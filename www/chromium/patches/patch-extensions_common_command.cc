$NetBSD: patch-extensions_common_command.cc,v 1.18 2026/04/21 15:21:16 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- extensions/common/command.cc.orig	2026-04-14 23:31:37.000000000 +0200
+++ extensions/common/command.cc
@@ -117,7 +117,7 @@ std::string Command::CommandPlatform() {
   return ui::kKeybindingPlatformMac;
 #elif BUILDFLAG(IS_CHROMEOS)
   return ui::kKeybindingPlatformChromeOs;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return ui::kKeybindingPlatformLinux;
 #elif BUILDFLAG(IS_DESKTOP_ANDROID)
   // For now, we use linux keybindings on desktop android.
