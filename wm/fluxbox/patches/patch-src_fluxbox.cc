$NetBSD: patch-src_fluxbox.cc,v 1.1 2017/02/22 12:20:51 wiz Exp $

--- src/fluxbox.cc.orig	2015-02-08 10:44:45.000000000 +0000
+++ src/fluxbox.cc
@@ -1045,7 +1045,7 @@ void Fluxbox::saveWindowSearchGroup(Wind
 }
 
 void Fluxbox::saveGroupSearch(Window window, WinClient *data) {
-    m_group_search.insert(pair<const Window, WinClient *>(window, data));
+    m_group_search.insert(std::multimap<Window, WinClient *>::value_type(window, data));
 }
 
 
