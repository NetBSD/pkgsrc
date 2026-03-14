$NetBSD: patch-ui_base_accelerators_command.cc,v 1.15 2026/03/14 12:40:43 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/base/accelerators/command.cc.orig	2026-03-11 22:12:25.000000000 +0000
+++ ui/base/accelerators/command.cc
@@ -80,7 +80,7 @@ std::string Command::CommandPlatform() {
   return ui::kKeybindingPlatformMac;
 #elif BUILDFLAG(IS_CHROMEOS)
   return ui::kKeybindingPlatformChromeOs;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return ui::kKeybindingPlatformLinux;
 #elif BUILDFLAG(IS_FUCHSIA)
   // TODO(crbug.com/40220501): Change this once we decide what string should be
