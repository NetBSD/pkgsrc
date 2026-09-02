$NetBSD: patch-ui_base_accelerators_command.cc,v 1.24 2026/09/02 13:13:38 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/base/accelerators/command.cc.orig	2026-08-31 22:47:51.000000000 +0000
+++ ui/base/accelerators/command.cc
@@ -81,7 +81,7 @@ std::string Command::CommandPlatform() {
   return ui::kKeybindingPlatformMac;
 #elif BUILDFLAG(IS_CHROMEOS)
   return ui::kKeybindingPlatformChromeOs;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return ui::kKeybindingPlatformLinux;
 #elif BUILDFLAG(IS_FUCHSIA)
   // TODO(crbug.com/40220501): Change this once we decide what string should be
