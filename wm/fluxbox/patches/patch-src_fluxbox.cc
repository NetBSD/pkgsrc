$NetBSD: patch-src_fluxbox.cc,v 1.2 2026/05/10 23:01:44 gutteridge Exp $

Fix builds with the SunPro compiler.

Apply upstream patch to fix handling of monitor power cycling.
https://github.com/fluxbox/fluxbox/commit/36f99b92464abd389d815dbf29a65d740b8145c6

--- src/fluxbox.cc.orig	2015-02-08 10:44:45.377187009 +0000
+++ src/fluxbox.cc
@@ -798,7 +798,12 @@ void Fluxbox::handleEvent(XEvent * const e) {
     default: {
 
 #if defined(HAVE_RANDR) || defined(HAVE_RANDR1_2)
-        if (e->type == s_randr_event_type) {
+        bool is_randr_event = (e->type == s_randr_event_type);
+#ifdef RRNotify
+        is_randr_event = is_randr_event ||
+                         (e->type == s_randr_event_type + RRNotify);
+#endif
+        if (is_randr_event) {
 #ifdef HAVE_RANDR1_2
             XRRUpdateConfiguration(e);
 #endif
@@ -1045,7 +1050,7 @@ void Fluxbox::saveGroupSearch(Window window, WinClient
 }
 
 void Fluxbox::saveGroupSearch(Window window, WinClient *data) {
-    m_group_search.insert(pair<const Window, WinClient *>(window, data));
+    m_group_search.insert(std::multimap<Window, WinClient *>::value_type(window, data));
 }
 
 
