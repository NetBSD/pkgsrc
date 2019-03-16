$NetBSD: patch-src_libxosd_xosd.c,v 1.1 2019/03/16 08:50:48 bsiegert Exp $

Support for y-offset monitors, http://gnats.netbsd.org/53994

--- src/libxosd/xosd.c.orig	2004-11-17 19:27:11.000000000 +0000
+++ src/libxosd/xosd.c
@@ -326,13 +326,13 @@ event_loop(void *osdv)
       }
       switch (osd->pos) {
       case XOSD_bottom:
-        y = osd->screen_height - osd->height - osd->voffset;
+        y = osd->screen_height + osd->screen_ypos - osd->height - osd->voffset;
         break;
       case XOSD_middle:
-        y = (osd->screen_height - osd->height) / 2 - osd->voffset;
+        y = (osd->screen_height  + osd->screen_ypos - osd->height) / 2 - osd->voffset;
         break;
       case XOSD_top:
-        y = osd->voffset;
+        y = osd->screen_ypos + osd->voffset;
       }
       XMoveWindow(osd->display, osd->window, x, y);
     }
@@ -746,12 +746,14 @@ xosd_create(int number_lines)
     osd->screen_width = screeninfo[0].width;
     osd->screen_height = screeninfo[0].height;
     osd->screen_xpos = screeninfo[0].x_org;
+    osd->screen_ypos = screeninfo[0].y_org;
   } else
 #endif
   {
     osd->screen_width = XDisplayWidth(osd->display, osd->screen);
     osd->screen_height = XDisplayHeight(osd->display, osd->screen);
     osd->screen_xpos = 0;
+    osd->screen_ypos = 0;
   }
 #ifdef HAVE_XINERAMA
   if (screeninfo)
