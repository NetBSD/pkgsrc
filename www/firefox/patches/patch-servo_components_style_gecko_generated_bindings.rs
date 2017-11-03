$NetBSD: patch-servo_components_style_gecko_generated_bindings.rs,v 1.1 2017/11/03 22:07:27 ryoon Exp $

--- servo/components/style/gecko/generated/bindings.rs.orig	2017-09-14 20:15:56.000000000 +0000
+++ servo/components/style/gecko/generated/bindings.rs
@@ -8,6 +8,7 @@ type nsAString_internal = nsAString;
 pub type ServoStyleContextBorrowed<'a> = &'a ::properties::ComputedValues;
 pub type ServoStyleContextBorrowedOrNull<'a> = Option<&'a ::properties::ComputedValues>;
 pub type ServoComputedDataBorrowed<'a> = &'a ServoComputedData;
+pub type RawServoAnimationValueTableBorrowed<'a> = &'a ();
 use gecko_bindings::structs::mozilla::css::GridTemplateAreasValue;
 use gecko_bindings::structs::mozilla::css::ErrorReporter;
 use gecko_bindings::structs::mozilla::css::ImageValue;
@@ -37,7 +38,7 @@ use gecko_bindings::structs::RawServoSty
 use gecko_bindings::structs::RawGeckoPresContext;
 use gecko_bindings::structs::RawGeckoPresContextOwned;
 use gecko_bindings::structs::RawGeckoStyleAnimationList;
-use gecko_bindings::structs::RawGeckoStyleChildrenIteratorBorrowedMut;
+use gecko_bindings::structs::RawGeckoStyleChildrenIterator;
 use gecko_bindings::structs::RawGeckoServoStyleRuleList;
 use gecko_bindings::structs::RawGeckoURLExtraData;
 use gecko_bindings::structs::RawGeckoXBLBinding;
@@ -316,6 +317,10 @@ pub type RawGeckoServoAnimationValueList
 pub type RawGeckoServoAnimationValueListBorrowedOrNull<'a> = Option<&'a RawGeckoServoAnimationValueList>;
 pub type RawGeckoServoAnimationValueListBorrowedMut<'a> = &'a mut RawGeckoServoAnimationValueList;
 pub type RawGeckoServoAnimationValueListBorrowedMutOrNull<'a> = Option<&'a mut RawGeckoServoAnimationValueList>;
+pub type RawGeckoStyleChildrenIteratorBorrowed<'a> = &'a RawGeckoStyleChildrenIterator;
+pub type RawGeckoStyleChildrenIteratorBorrowedOrNull<'a> = Option<&'a RawGeckoStyleChildrenIterator>;
+pub type RawGeckoStyleChildrenIteratorBorrowedMut<'a> = &'a mut RawGeckoStyleChildrenIterator;
+pub type RawGeckoStyleChildrenIteratorBorrowedMutOrNull<'a> = Option<&'a mut RawGeckoStyleChildrenIterator>;
 pub type ServoCssRulesStrong = ::gecko_bindings::sugar::ownership::Strong<ServoCssRules>;
 pub type ServoCssRulesBorrowed<'a> = &'a ServoCssRules;
 pub type ServoCssRulesBorrowedOrNull<'a> = Option<&'a ServoCssRules>;
@@ -836,7 +841,7 @@ extern "C" {
 }
 extern "C" {
     pub fn Gecko_AnimationGetBaseStyle(aBaseStyles:
-                                           *mut ::std::os::raw::c_void,
+                                           RawServoAnimationValueTableBorrowed,
                                        aProperty: nsCSSPropertyID)
      -> RawServoAnimationValueBorrowedOrNull;
 }
@@ -2588,7 +2593,8 @@ extern "C" {
 extern "C" {
     pub fn Servo_AnimationCompose(animation_values:
                                       RawServoAnimationValueMapBorrowedMut,
-                                  base_values: *mut ::std::os::raw::c_void,
+                                  base_values:
+                                      RawServoAnimationValueTableBorrowed,
                                   property: nsCSSPropertyID,
                                   animation_segment:
                                       RawGeckoAnimationPropertySegmentBorrowed,
