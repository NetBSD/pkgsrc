$NetBSD: patch-servo_ports_geckolib_glue.rs,v 1.1 2017/11/03 22:07:27 ryoon Exp $

--- servo/ports/geckolib/glue.rs.orig	2017-09-14 20:15:57.000000000 +0000
+++ servo/ports/geckolib/glue.rs
@@ -62,6 +62,7 @@ use style::gecko_bindings::bindings::Raw
 use style::gecko_bindings::bindings::RawServoAnimationValueBorrowed;
 use style::gecko_bindings::bindings::RawServoAnimationValueMapBorrowedMut;
 use style::gecko_bindings::bindings::RawServoAnimationValueStrong;
+use style::gecko_bindings::bindings::RawServoAnimationValueTableBorrowed;
 use style::gecko_bindings::bindings::RawServoStyleRuleBorrowed;
 use style::gecko_bindings::bindings::ServoStyleContextBorrowedOrNull;
 use style::gecko_bindings::bindings::nsTArrayBorrowed_uintptr_t;
@@ -370,7 +371,7 @@ pub extern "C" fn Servo_AnimationValues_
 
 #[no_mangle]
 pub extern "C" fn Servo_AnimationCompose(raw_value_map: RawServoAnimationValueMapBorrowedMut,
-                                         base_values: *mut ::std::os::raw::c_void,
+                                         base_values: RawServoAnimationValueTableBorrowed,
                                          css_property: nsCSSPropertyID,
                                          segment: RawGeckoAnimationPropertySegmentBorrowed,
                                          last_segment: RawGeckoAnimationPropertySegmentBorrowed,
@@ -815,7 +816,7 @@ pub extern "C" fn Servo_StyleSet_AppendS
 ) {
     let global_style_data = &*GLOBAL_STYLE_DATA;
     let mut data = PerDocumentStyleData::from_ffi(raw_data).borrow_mut();
-    let mut data = &mut *data;
+    let data = &mut *data;
     let guard = global_style_data.shared_lock.read();
     data.stylesheets.append_stylesheet(
         &data.stylist,
@@ -867,7 +868,7 @@ pub extern "C" fn Servo_StyleSet_Prepend
 ) {
     let global_style_data = &*GLOBAL_STYLE_DATA;
     let mut data = PerDocumentStyleData::from_ffi(raw_data).borrow_mut();
-    let mut data = &mut *data;
+    let data = &mut *data;
     let guard = global_style_data.shared_lock.read();
     data.stylesheets.prepend_stylesheet(
         &data.stylist,
@@ -885,7 +886,7 @@ pub extern "C" fn Servo_StyleSet_InsertS
 ) {
     let global_style_data = &*GLOBAL_STYLE_DATA;
     let mut data = PerDocumentStyleData::from_ffi(raw_data).borrow_mut();
-    let mut data = &mut *data;
+    let data = &mut *data;
     let guard = global_style_data.shared_lock.read();
     data.stylesheets.insert_stylesheet_before(
         &data.stylist,
@@ -903,7 +904,7 @@ pub extern "C" fn Servo_StyleSet_RemoveS
 ) {
     let global_style_data = &*GLOBAL_STYLE_DATA;
     let mut data = PerDocumentStyleData::from_ffi(raw_data).borrow_mut();
-    let mut data = &mut *data;
+    let data = &mut *data;
     let guard = global_style_data.shared_lock.read();
     data.stylesheets.remove_stylesheet(
         &data.stylist,
@@ -1274,7 +1275,7 @@ pub extern "C" fn Servo_StyleRule_GetSpe
     specificity: *mut u64
 ) {
     read_locked_arc(rule, |rule: &StyleRule| {
-        let mut specificity =  unsafe { specificity.as_mut().unwrap() };
+        let specificity =  unsafe { specificity.as_mut().unwrap() };
         let index = index as usize;
         if index >= rule.selectors.0.len() {
             *specificity = 0;
@@ -2775,7 +2776,7 @@ pub extern "C" fn Servo_NoteExplicitHint
 pub extern "C" fn Servo_TakeChangeHint(element: RawGeckoElementBorrowed,
                                        was_restyled: *mut bool) -> nsChangeHint
 {
-    let mut was_restyled =  unsafe { was_restyled.as_mut().unwrap() };
+    let was_restyled =  unsafe { was_restyled.as_mut().unwrap() };
     let element = GeckoElement(element);
 
     let damage = match element.mutate_data() {
