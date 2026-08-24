$NetBSD: patch-src_util_icon__loader.cpp,v 1.1 2026/08/24 14:25:32 kikadf Exp $

* Fix ctype usage

--- src/util/icon_loader.cpp.orig	2026-07-27 13:52:11.975754660 +0000
+++ src/util/icon_loader.cpp
@@ -185,7 +185,7 @@ Glib::RefPtr<Gio::DesktopAppInfo> IconLo
 
     auto lower_app_id = app_id;
     std::ranges::transform(lower_app_id, lower_app_id.begin(),
-                           [](char c) { return std::tolower(c); });
+                           [](char c) { return static_cast<char>(std::tolower(static_cast<unsigned char>(c))); });
     app_info_ = get_desktop_app_info(lower_app_id);
     if (app_info_) {
       return app_info_;
