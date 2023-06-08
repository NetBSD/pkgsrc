$NetBSD: patch-src_3rdparty_chromium_third__party_blink_renderer_build_scripts_core_css_make__style__shorthands.py,v 1.1 2023/06/08 20:38:06 markd Exp $

build with python3

--- src/3rdparty/chromium/third_party/blink/renderer/build/scripts/core/css/make_style_shorthands.py.orig	2022-03-30 09:48:18.000000000 +0000
+++ src/3rdparty/chromium/third_party/blink/renderer/build/scripts/core/css/make_style_shorthands.py
@@ -71,7 +71,7 @@ class Expansion(object):
     def enabled_longhands(self):
         include = lambda longhand: not longhand[
             'runtime_flag'] or self.is_enabled(longhand['runtime_flag'])
-        return filter(include, self._longhands)
+        return list(filter(include, self._longhands))
 
     @property
     def index(self):
@@ -87,8 +87,9 @@ class Expansion(object):
 
 def create_expansions(longhands):
     flags = collect_runtime_flags(longhands)
-    expansions = map(lambda mask: Expansion(longhands, flags, mask),
-                     range(1 << len(flags)))
+    expansions = list(
+        map(lambda mask: Expansion(longhands, flags, mask),
+            range(1 << len(flags))))
     assert len(expansions) > 0
     # We generate 2^N expansions for N flags, so enforce some limit.
     assert len(flags) <= 4, 'Too many runtime flags for a single shorthand'
@@ -114,14 +115,14 @@ class StylePropertyShorthandWriter(json5
 
         self._longhand_dictionary = defaultdict(list)
         for property_ in json5_properties.shorthands:
-            property_['longhand_enum_keys'] = map(enum_key_for_css_property,
-                                                  property_['longhands'])
-            property_['longhand_property_ids'] = map(id_for_css_property,
-                                                     property_['longhands'])
-
-            longhands = map(
-                lambda name: json5_properties.properties_by_name[name],
-                property_['longhands'])
+            property_['longhand_enum_keys'] = list(
+                map(enum_key_for_css_property, property_['longhands']))
+            property_['longhand_property_ids'] = list(
+                map(id_for_css_property, property_['longhands']))
+
+            longhands = list(
+                map(lambda name: json5_properties.properties_by_name[name],
+                    property_['longhands']))
             property_['expansions'] = create_expansions(longhands)
             for longhand_enum_key in property_['longhand_enum_keys']:
                 self._longhand_dictionary[longhand_enum_key].append(property_)
