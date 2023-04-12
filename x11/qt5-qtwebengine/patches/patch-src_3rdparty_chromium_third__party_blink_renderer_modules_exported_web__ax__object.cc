$NetBSD: patch-src_3rdparty_chromium_third__party_blink_renderer_modules_exported_web__ax__object.cc,v 1.1 2023/04/12 19:24:06 adam Exp $

https://github.com/macports/macports-ports/pull/16605

--- src/3rdparty/chromium/third_party/blink/renderer/modules/exported/web_ax_object.cc.orig	2023-04-11 15:21:20.000000000 +0000
+++ src/3rdparty/chromium/third_party/blink/renderer/modules/exported/web_ax_object.cc
@@ -1480,7 +1480,12 @@ void WebAXObject::GetRelativeBounds(WebA
   private_->GetRelativeBounds(&container, bounds, container_transform,
                               clips_children);
   offset_container = WebAXObject(container);
+#ifdef __APPLE__
+  CGRect r = bounds;
+  bounds_in_container = gfx::RectF(r);
+#else
   bounds_in_container = gfx::RectF(bounds);
+#endif
 }
 
 void WebAXObject::GetAllObjectsWithChangedBounds(
