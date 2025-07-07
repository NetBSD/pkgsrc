$NetBSD: patch-ui_accessibility_ax__node.h,v 1.2 2025/07/07 09:23:39 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/accessibility/ax_node.h.orig	2025-06-30 06:54:11.000000000 +0000
+++ ui/accessibility/ax_node.h
@@ -587,7 +587,7 @@ class AX_EXPORT AXNode final {
   const std::vector<raw_ptr<AXNode, VectorExperimental>>* GetExtraMacNodes()
       const;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   AXNode* GetExtraAnnouncementNode(
       ax::mojom::AriaNotificationPriority priority_property) const;
 #endif  // BUILDFLAG(IS_LINUX)
