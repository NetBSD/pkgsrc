$NetBSD: patch-ui_accessibility_ax__node.h,v 1.14 2026/02/15 09:04:13 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/accessibility/ax_node.h.orig	2026-02-03 22:07:10.000000000 +0000
+++ ui/accessibility/ax_node.h
@@ -582,7 +582,7 @@ class AX_EXPORT AXNode final {
   const std::vector<raw_ptr<AXNode, VectorExperimental>>* GetExtraMacNodes()
       const;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   AXNode* GetExtraAnnouncementNode(
       ax::mojom::AriaNotificationPriority priority_property) const;
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
