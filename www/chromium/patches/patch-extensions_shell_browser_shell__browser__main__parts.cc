$NetBSD: patch-extensions_shell_browser_shell__browser__main__parts.cc,v 1.15 2026/02/15 09:04:06 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- extensions/shell/browser/shell_browser_main_parts.cc.orig	2026-02-03 22:07:10.000000000 +0000
+++ extensions/shell/browser/shell_browser_main_parts.cc
@@ -126,7 +126,7 @@ void ShellBrowserMainParts::PostCreateMa
       switches::kAppShellAllowRoaming)) {
     network_controller_->SetCellularAllowRoaming(true);
   }
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // app_shell doesn't need GTK, so the fake input method context can work.
   // See crbug.com/381852 and revision fb69f142.
   // TODO(michaelpg): Verify this works for target environments.
