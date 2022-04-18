$NetBSD: patch-src_3rdparty_chromium_ui_views_bubble_bubble__dialog__delegate__view.cc,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/ui/views/bubble/bubble_dialog_delegate_view.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/ui/views/bubble/bubble_dialog_delegate_view.cc
@@ -319,7 +319,7 @@ Widget* BubbleDialogDelegate::CreateBubb
   bubble_delegate->SetAnchorView(bubble_delegate->GetAnchorView());
   Widget* bubble_widget = CreateBubbleWidget(bubble_delegate);
 
-#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_APPLE)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_APPLE) || defined(OS_BSD)
   // Linux clips bubble windows that extend outside their parent window bounds.
   // Mac never adjusts.
   bubble_delegate->set_adjust_if_offscreen(false);
