$NetBSD: patch-ccm_Utils.py,v 1.1 2023/07/14 08:13:26 pho Exp $

CCSM: No icons and text in main screen, submenus of the plugins work
normally

https://bugs.launchpad.net/ubuntu/+source/compiz/+bug/1130941

--- ccm/Utils.py.orig	2023-07-14 07:56:20.403539555 +0000
+++ ccm/Utils.py
@@ -184,7 +184,7 @@ class PrettyButton (gtk.Button):
         if has_focus:
             self.unset_flags (gtk.HAS_FOCUS)
 
-        ret = super (PrettyButton, self).do_expose_event (self, event)
+        ret = gtk.Button.do_expose_event (self, event)
 
         if has_focus:
             self.set_flags (gtk.HAS_FOCUS)
