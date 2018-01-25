$NetBSD: patch-image_xcb__bitops.h,v 1.1 2018/01/25 13:47:22 jperkin Exp $

Workaround clang "error: control may reach end of non-void function".

--- image/xcb_bitops.h.orig	2011-06-30 08:05:22.000000000 +0000
+++ image/xcb_bitops.h
@@ -207,6 +207,7 @@ xcb_host_byte_order(void) {
       return XCB_IMAGE_ORDER_LSB_FIRST;
   }
   assert(0);
+  return -1;
 }
 
 #endif /* __XCB_BITOPS_H__ */
