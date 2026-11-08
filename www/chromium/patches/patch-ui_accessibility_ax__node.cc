$NetBSD: patch-ui_accessibility_ax__node.cc,v 1.31 2026/11/08 15:39:12 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/accessibility/ax_node.cc.orig	2026-11-02 23:22:33.000000000 +0000
+++ ui/accessibility/ax_node.cc
@@ -1582,7 +1582,7 @@ AXNode::GetExtraMacNodes() const {
   return &table_info->extra_mac_nodes;
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 AXNode* AXNode::GetExtraAnnouncementNode(
     ax::mojom::AriaNotificationPriority priority_property) const {
   if (!tree_->extra_announcement_nodes()) {
@@ -1610,7 +1610,7 @@ bool AXNode::IsGenerated() const {
       GetRole() == ax::mojom::Role::kColumn ||
       GetRole() == ax::mojom::Role::kTableHeaderContainer;
   DCHECK_EQ(is_generated_node, is_extra_mac_node_role);
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   // On Linux and Windows, generated nodes are always children of the root, but
   // not necessarily the root tree.
   if (GetParent() && GetParent()->GetManager()) {
