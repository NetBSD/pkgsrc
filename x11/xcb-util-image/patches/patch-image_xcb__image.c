$NetBSD: patch-image_xcb__image.c,v 1.1 2012/08/18 08:04:25 marino Exp $

gcc44 complains "control reaches end of non-void function" on DragonFly
Apparently gcc45+ recognizes the assert, but for those compilers that don't,
putting a dummy return value won't hurt anything.

--- image/xcb_image.c.orig	2011-06-30 08:05:22.000000000 +0000
+++ image/xcb_image.c
@@ -187,6 +187,8 @@ xcb_image_create_native (xcb_connection_
       assert(0);
   }
   assert(0);
+/* gcc44 complains "control reaches end of non-void function", fix below */
+  return (-1);
 }
 
 
@@ -750,6 +752,8 @@ xcb_image_get_pixel (xcb_image_t *image,
       return pixel;
   default:
       assert(0);
+/* gcc44 complains "control reaches end of non-void function", fix below */
+  return (-1);
   }
 }
 
