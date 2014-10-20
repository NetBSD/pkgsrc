$NetBSD: patch-image_xcb__image.c,v 1.2 2014/10/20 11:15:38 wiz Exp $

gcc44 complains "control reaches end of non-void function" on DragonFly
Apparently gcc45+ recognizes the assert, but for those compilers that don't,
putting a dummy return value won't hurt anything.

--- image/xcb_image.c.orig	2014-06-11 08:49:48.000000000 +0000
+++ image/xcb_image.c
@@ -187,6 +187,8 @@ xcb_image_create_native (xcb_connection_
 			      setup->image_byte_order,
 			      XCB_IMAGE_ORDER_MSB_FIRST,
 			      base, bytes, data);
+/* gcc44 complains "control reaches end of non-void function", fix below */
+  return (-1);
   default:
       assert(0);
   }
@@ -658,6 +660,8 @@ xcb_image_put_pixel (xcb_image_t *image,
       break;
   default:
       assert(0);
+/* gcc44 complains "control reaches end of non-void function", fix below */
+  return (-1);
   }
 }
 
