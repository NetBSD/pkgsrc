$NetBSD: patch-ui_message__center_views_message__popup__view.cc,v 1.14 2026/01/19 16:14:23 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/message_center/views/message_popup_view.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ ui/message_center/views/message_popup_view.cc
@@ -164,7 +164,7 @@ std::unique_ptr<views::Widget> MessagePo
       views::Widget::InitParams::CLIENT_OWNS_WIDGET,
       views::Widget::InitParams::TYPE_POPUP);
   params.z_order = ui::ZOrderLevel::kFloatingWindow;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Make the widget explicitly activatable as TYPE_POPUP is not activatable by
   // default but we need focus for the inline reply textarea.
   params.activatable = views::Widget::InitParams::Activatable::kYes;
