$NetBSD: patch-layout_style_ServoBindings.h,v 1.1 2017/11/03 22:07:27 ryoon Exp $

--- layout/style/ServoBindings.h.orig	2017-09-14 20:16:05.000000000 +0000
+++ layout/style/ServoBindings.h
@@ -267,9 +267,9 @@ double Gecko_GetPositionInSegment(
 // Get servo's AnimationValue for |aProperty| from the cached base style
 // |aBaseStyles|.
 // |aBaseStyles| is nsRefPtrHashtable<nsUint32HashKey, RawServoAnimationValue>.
-// We use void* to avoid exposing nsRefPtrHashtable in FFI.
+// We use RawServoAnimationValueTableBorrowed to avoid exposing nsRefPtrHashtable in FFI.
 RawServoAnimationValueBorrowedOrNull Gecko_AnimationGetBaseStyle(
-  void* aBaseStyles,
+  RawServoAnimationValueTableBorrowed aBaseStyles,
   nsCSSPropertyID aProperty);
 void Gecko_StyleTransition_SetUnsupportedProperty(
   mozilla::StyleTransition* aTransition,
