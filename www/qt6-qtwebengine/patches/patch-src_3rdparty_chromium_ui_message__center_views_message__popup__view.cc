$NetBSD: patch-src_3rdparty_chromium_ui_message__center_views_message__popup__view.cc,v 1.1 2025/12/21 09:38:48 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/ui/message_center/views/message_popup_view.cc.orig	2025-10-02 00:36:39.000000000 +0000
+++ src/3rdparty/chromium/ui/message_center/views/message_popup_view.cc
@@ -153,7 +153,7 @@ std::unique_ptr<views::Widget> MessagePo
       views::Widget::InitParams::CLIENT_OWNS_WIDGET,
       views::Widget::InitParams::TYPE_POPUP);
   params.z_order = ui::ZOrderLevel::kFloatingWindow;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Make the widget explicitly activatable as TYPE_POPUP is not activatable by
   // default but we need focus for the inline reply textarea.
   params.activatable = views::Widget::InitParams::Activatable::kYes;
