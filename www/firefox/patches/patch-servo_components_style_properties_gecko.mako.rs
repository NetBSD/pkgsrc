$NetBSD: patch-servo_components_style_properties_gecko.mako.rs,v 1.1 2017/11/03 22:07:27 ryoon Exp $

--- servo/components/style/properties/gecko.mako.rs.orig	2017-09-14 20:15:57.000000000 +0000
+++ servo/components/style/properties/gecko.mako.rs
@@ -2081,7 +2081,7 @@ fn static_assert() {
             return (parent_size, parent_unconstrained_size)
         }
 
-        /// XXXManishearth this should also handle text zoom
+        // XXXManishearth this should also handle text zoom
         let min = Au(parent.gecko.mScriptMinSize);
 
         let scale = (parent.gecko.mScriptSizeMultiplier as f32).powi(delta as i32);
@@ -4136,14 +4136,14 @@ fn static_assert() {
                     fn init_shadow(filter: &mut nsStyleFilter) -> &mut nsCSSShadowArray {
                         unsafe {
                             let ref mut union = filter.__bindgen_anon_1;
-                            let mut shadow_array: &mut *mut nsCSSShadowArray = union.mDropShadow.as_mut();
+                            let shadow_array: &mut *mut nsCSSShadowArray = union.mDropShadow.as_mut();
                             *shadow_array = Gecko_NewCSSShadowArray(1);
 
                             &mut **shadow_array
                         }
                     }
 
-                    let mut gecko_shadow = init_shadow(gecko_filter);
+                    let gecko_shadow = init_shadow(gecko_filter);
                     gecko_shadow.mArray[0].set_from_simple_shadow(shadow);
                 },
                 Url(ref url) => {
@@ -4665,14 +4665,14 @@ fn static_assert() {
                     unsafe {
                         // We have to be very careful to avoid a copy here!
                         let ref mut union = ${ident}.__bindgen_anon_1;
-                        let mut shape: &mut *mut StyleBasicShape = union.mBasicShape.as_mut();
+                        let shape: &mut *mut StyleBasicShape = union.mBasicShape.as_mut();
                         *shape = Gecko_NewBasicShape(ty);
                         &mut **shape
                     }
                 }
                 match servo_shape {
                     BasicShape::Inset(inset) => {
-                        let mut shape = init_shape(${ident}, StyleBasicShapeType::Inset);
+                        let shape = init_shape(${ident}, StyleBasicShapeType::Inset);
                         unsafe { shape.mCoordinates.set_len(4) };
 
                         // set_len() can't call constructors, so the coordinates
@@ -4694,7 +4694,7 @@ fn static_assert() {
                         set_corners_from_radius(inset.round, &mut shape.mRadius);
                     }
                     BasicShape::Circle(circ) => {
-                        let mut shape = init_shape(${ident}, StyleBasicShapeType::Circle);
+                        let shape = init_shape(${ident}, StyleBasicShapeType::Circle);
                         unsafe { shape.mCoordinates.set_len(1) };
                         shape.mCoordinates[0].leaky_set_null();
                         circ.radius.to_gecko_style_coord(&mut shape.mCoordinates[0]);
@@ -4702,7 +4702,7 @@ fn static_assert() {
                         shape.mPosition = circ.position.into();
                     }
                     BasicShape::Ellipse(el) => {
-                        let mut shape = init_shape(${ident}, StyleBasicShapeType::Ellipse);
+                        let shape = init_shape(${ident}, StyleBasicShapeType::Ellipse);
                         unsafe { shape.mCoordinates.set_len(2) };
                         shape.mCoordinates[0].leaky_set_null();
                         el.semiaxis_x.to_gecko_style_coord(&mut shape.mCoordinates[0]);
@@ -4712,7 +4712,7 @@ fn static_assert() {
                         shape.mPosition = el.position.into();
                     }
                     BasicShape::Polygon(poly) => {
-                        let mut shape = init_shape(${ident}, StyleBasicShapeType::Polygon);
+                        let shape = init_shape(${ident}, StyleBasicShapeType::Polygon);
                         unsafe {
                             shape.mCoordinates.set_len(poly.coordinates.len() as u32 * 2);
                         }
@@ -4797,7 +4797,7 @@ clip-path
             bindings::Gecko_nsStyleSVG_SetDashArrayLength(&mut self.gecko, v.len() as u32);
         }
 
-        for (mut gecko, servo) in self.gecko.mStrokeDasharray.iter_mut().zip(v) {
+        for (gecko, servo) in self.gecko.mStrokeDasharray.iter_mut().zip(v) {
             match servo {
                 Either::First(number) => gecko.set_value(CoordDataValue::Factor(number)),
                 Either::Second(lop) => gecko.set(lop),
@@ -4885,7 +4885,7 @@ clip-path
         }
 
         self.gecko.mContextPropsBits = 0;
-        for (mut gecko, servo) in self.gecko.mContextProps.iter_mut().zip(v) {
+        for (gecko, servo) in self.gecko.mContextProps.iter_mut().zip(v) {
             if servo.0 == atom!("fill") {
                 self.gecko.mContextPropsBits |= structs::NS_STYLE_CONTEXT_PROPERTY_FILL as u8;
             } else if servo.0 == atom!("stroke") {
