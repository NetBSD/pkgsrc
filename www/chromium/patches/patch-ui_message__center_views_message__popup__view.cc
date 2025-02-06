$NetBSD: patch-ui_message__center_views_message__popup__view.cc,v 1.1 2025/02/06 09:58:33 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/message_center/views/message_popup_view.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ ui/message_center/views/message_popup_view.cc
@@ -144,7 +144,7 @@ std::unique_ptr<views::Widget> MessagePo
   params.z_order = ui::ZOrderLevel::kFloatingWindow;
 // TODO(crbug.com/40118868): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   // Make the widget explicitly activatable as TYPE_POPUP is not activatable by
   // default but we need focus for the inline reply textarea.
   params.activatable = views::Widget::InitParams::Activatable::kYes;
