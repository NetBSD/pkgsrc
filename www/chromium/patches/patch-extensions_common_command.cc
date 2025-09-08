$NetBSD: patch-extensions_common_command.cc,v 1.6 2025/09/08 13:24:26 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- extensions/common/command.cc.orig	2025-08-29 18:50:09.000000000 +0000
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
