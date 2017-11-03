$NetBSD: patch-layout_style_ServoBindingList.h,v 1.1 2017/11/03 22:07:27 ryoon Exp $

--- layout/style/ServoBindingList.h.orig	2017-09-14 20:16:05.000000000 +0000
+++ layout/style/ServoBindingList.h
@@ -377,10 +377,10 @@ SERVO_BINDING_FUNC(Servo_DeclarationBloc
                    nsCSSPropertyID property)
 // Compose animation value for a given property.
 // |base_values| is nsRefPtrHashtable<nsUint32HashKey, RawServoAnimationValue>.
-// We use void* to avoid exposing nsRefPtrHashtable in FFI.
+// We use RawServoAnimationValueTableBorrowed to avoid exposing nsRefPtrHashtable in FFI.
 SERVO_BINDING_FUNC(Servo_AnimationCompose, void,
                    RawServoAnimationValueMapBorrowedMut animation_values,
-                   void* base_values,
+                   RawServoAnimationValueTableBorrowed base_values,
                    nsCSSPropertyID property,
                    RawGeckoAnimationPropertySegmentBorrowed animation_segment,
                    RawGeckoAnimationPropertySegmentBorrowed last_segment,
