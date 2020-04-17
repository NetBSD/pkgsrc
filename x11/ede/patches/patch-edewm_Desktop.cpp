$NetBSD: patch-edewm_Desktop.cpp,v 1.1 2020/04/17 13:31:46 joerg Exp $

--- edewm/Desktop.cpp.orig	2020-04-17 12:33:44.077015717 +0000
+++ edewm/Desktop.cpp
@@ -152,7 +152,7 @@ void Desktop::update_desktop_viewport()
 
 void Desktop::update_desktop_geometry()
 {
-    CARD32 val[2] = { Fl::w(), Fl::h() };
+    CARD32 val[2] = { CARD32(Fl::w()), CARD32(Fl::h()) };
     XChangeProperty(fl_display, root_win, _XA_NET_DESKTOP_GEOMETRY, XA_CARDINAL, 32,
                     PropModeReplace, (unsigned char *)&val, 2);
 
