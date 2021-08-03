$NetBSD: patch-src_3rdparty_chromium_ui_views_bubble_bubble__dialog__delegate__view.cc,v 1.1 2021/08/03 21:04:36 markd Exp $

--- src/3rdparty/chromium/ui/views/bubble/bubble_dialog_delegate_view.cc.orig	2020-11-07 01:22:36.000000000 +0000
+++ src/3rdparty/chromium/ui/views/bubble/bubble_dialog_delegate_view.cc
@@ -171,7 +171,7 @@ Widget* BubbleDialogDelegateView::Create
   bubble_delegate->Init();
   Widget* bubble_widget = CreateBubbleWidget(bubble_delegate);
 
-#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_MACOSX)
+#if ((defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)) || defined(OS_MACOSX)
   // Linux clips bubble windows that extend outside their parent window bounds.
   // Mac never adjusts.
   bubble_delegate->set_adjust_if_offscreen(false);
