$NetBSD: patch-src_3rdparty_chromium_third__party_blink_renderer_build_scripts_core_css_properties_make__css__property__instances.py,v 1.1 2023/06/08 20:38:06 markd Exp $

build with python3

--- src/3rdparty/chromium/third_party/blink/renderer/build/scripts/core/css/properties/make_css_property_instances.py.orig	2022-03-30 09:48:18.000000000 +0000
+++ src/3rdparty/chromium/third_party/blink/renderer/build/scripts/core/css/properties/make_css_property_instances.py
@@ -42,8 +42,8 @@ class CSSPropertyInstancesWriter(json5_g
         aliases = self._css_properties.aliases
 
         # Lists of PropertyClassData.
-        self._property_classes_by_id = map(self.get_class, properties)
-        self._alias_classes_by_id = map(self.get_class, aliases)
+        self._property_classes_by_id = list(map(self.get_class, properties))
+        self._alias_classes_by_id = list(map(self.get_class, aliases))
 
         # Sort by enum value.
         self._property_classes_by_id.sort(key=lambda t: t.enum_value)
