$NetBSD: patch-ui_message__center_views_message__popup__view.cc,v 1.3 2025/07/07 09:23:40 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/message_center/views/message_popup_view.cc.orig	2025-06-30 06:54:11.000000000 +0000
+++ ui/message_center/views/message_popup_view.cc
@@ -153,7 +153,7 @@ std::unique_ptr<views::Widget> MessagePo
       views::Widget::InitParams::CLIENT_OWNS_WIDGET,
       views::Widget::InitParams::TYPE_POPUP);
   params.z_order = ui::ZOrderLevel::kFloatingWindow;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Make the widget explicitly activatable as TYPE_POPUP is not activatable by
   // default but we need focus for the inline reply textarea.
   params.activatable = views::Widget::InitParams::Activatable::kYes;
