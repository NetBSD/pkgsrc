$NetBSD: patch-src_Fl_cocoa.mm,v 1.1 2015/07/21 21:36:41 markd Exp $

part of tigervnc.patch from archlinux package. 

--- src/Fl_cocoa.mm.orig	2014-11-02 21:06:07.000000000 +0000
+++ src/Fl_cocoa.mm
@@ -724,7 +724,7 @@ void Fl::remove_timeout(Fl_Timeout_Handl
     return NO;	// prevent the caption to be redrawn as active on click
 		//  when another modal window is currently the key win
 
-  return !(w->tooltip_window() || w->menu_window());
+  return !w->tooltip_window();
 }
 
 - (BOOL)canBecomeMainWindow
