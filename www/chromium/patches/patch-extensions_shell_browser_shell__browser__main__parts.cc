$NetBSD: patch-extensions_shell_browser_shell__browser__main__parts.cc,v 1.19 2026/05/10 15:29:59 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- extensions/shell/browser/shell_browser_main_parts.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ extensions/shell/browser/shell_browser_main_parts.cc
@@ -126,7 +126,7 @@ void ShellBrowserMainParts::PostCreateMa
       switches::kAppShellAllowRoaming)) {
     network_controller_->SetCellularAllowRoaming(true);
   }
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // app_shell doesn't need GTK, so the fake input method context can work.
   // See crbug.com/40369323 and revision fb69f142.
   // TODO(michaelpg): Verify this works for target environments.
