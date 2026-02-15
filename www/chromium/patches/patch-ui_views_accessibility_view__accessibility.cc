$NetBSD: patch-ui_views_accessibility_view__accessibility.cc,v 1.14 2026/02/15 09:04:14 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/views/accessibility/view_accessibility.cc.orig	2026-02-03 22:07:10.000000000 +0000
+++ ui/views/accessibility/view_accessibility.cc
@@ -35,7 +35,7 @@
 #include "ui/views/accessibility/view_ax_platform_node_delegate_win.h"
 #elif BUILDFLAG(IS_MAC)
 #include "ui/views/accessibility/view_ax_platform_node_delegate_mac.h"
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/views/accessibility/view_ax_platform_node_delegate_auralinux.h"
 #endif
 
@@ -102,7 +102,7 @@ std::unique_ptr<ViewAccessibility> ViewA
   return ViewAXPlatformNodeDelegateWin::CreatePlatformSpecific(view);
 #elif BUILDFLAG(IS_MAC)
   return ViewAXPlatformNodeDelegateMac::CreatePlatformSpecific(view);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return ViewAXPlatformNodeDelegateAuraLinux::CreatePlatformSpecific(view);
 #endif
 }
