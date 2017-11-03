$NetBSD: patch-layout_style_ServoBindingTypes.h,v 1.1 2017/11/03 22:07:27 ryoon Exp $

--- layout/style/ServoBindingTypes.h.orig	2017-09-14 20:16:05.000000000 +0000
+++ layout/style/ServoBindingTypes.h
@@ -54,6 +54,8 @@ class nsXBLBinding;
 using mozilla::dom::StyleChildrenIterator;
 using mozilla::ServoElementSnapshot;
 
+typedef void* RawServoAnimationValueTableBorrowed;
+
 typedef nsINode RawGeckoNode;
 typedef mozilla::dom::Element RawGeckoElement;
 typedef nsIDocument RawGeckoDocument;
