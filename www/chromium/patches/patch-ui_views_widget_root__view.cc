$NetBSD: patch-ui_views_widget_root__view.cc,v 1.15 2026/02/15 09:04:15 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/views/widget/root_view.cc.orig	2026-02-03 22:07:10.000000000 +0000
+++ ui/views/widget/root_view.cc
@@ -169,7 +169,7 @@ class AnnounceTextView : public View {
 #if BUILDFLAG(IS_CHROMEOS)
     // On ChromeOS, kAlert role can invoke an unnecessary event on reparenting.
     GetViewAccessibility().SetRole(ax::mojom::Role::kStaticText);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // TODO(crbug.com/40658933): Use live regions (do not use alerts).
     // May require setting kLiveStatus, kContainerLiveStatus to "polite".
     GetViewAccessibility().SetRole(ax::mojom::Role::kAlert);
