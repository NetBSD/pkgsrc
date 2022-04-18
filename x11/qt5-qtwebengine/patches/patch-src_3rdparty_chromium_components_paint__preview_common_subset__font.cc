$NetBSD: patch-src_3rdparty_chromium_components_paint__preview_common_subset__font.cc,v 1.1 2022/04/18 11:18:18 adam Exp $

https://codereview.qt-project.org/c/qt/qtwebengine-chromium/+/376502
[Backport] Ease HarfBuzz API change with feature detection

--- src/3rdparty/chromium/components/paint_preview/common/subset_font.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/components/paint_preview/common/subset_font.cc
@@ -59,6 +59,41 @@ void AddGlyphs(hb_set_t* glyph_id_set, u
 
 }  // namespace
 
+template <class T, void(*P)(T*)> using resource =
+    std::unique_ptr<T, SkFunctionWrapper<std::remove_pointer_t<decltype(P)>, P>>;
+using HBBlob = resource<hb_blob_t, &hb_blob_destroy>;
+using HBFace = resource<hb_face_t, &hb_face_destroy>;
+using HBSubsetInput = resource<hb_subset_input_t, &hb_subset_input_destroy>;
+using HBSet = resource<hb_set_t, &hb_set_destroy>;
+
+template<typename...> using void_t = void;
+template<typename T, typename = void>
+struct SkPDFHarfBuzzSubset {
+    // This is the HarfBuzz 3.0 interface.
+    // hb_subset_flags_t does not exist in 2.0. It isn't dependent on T, so inline the value of
+    // HB_SUBSET_FLAGS_RETAIN_GIDS until 2.0 is no longer supported.
+    static HBFace Make(T input, hb_face_t* face) {
+        // TODO: When possible, check if a font is 'tricky' with FT_IS_TRICKY.
+        // If it isn't known if a font is 'tricky', retain the hints.
+        hb_subset_input_set_flags(input, 2/*HB_SUBSET_FLAGS_RETAIN_GIDS*/);
+        return HBFace(hb_subset_or_fail(face, input));
+    }
+};
+template<typename T>
+struct SkPDFHarfBuzzSubset<T, void_t<
+    decltype(hb_subset_input_set_retain_gids(std::declval<T>(), std::declval<bool>())),
+    decltype(hb_subset_input_set_drop_hints(std::declval<T>(), std::declval<bool>())),
+    decltype(hb_subset(std::declval<hb_face_t*>(), std::declval<T>()))
+    >>
+{
+    // This is the HarfBuzz 2.0 (non-public) interface, used if it exists.
+    // This code should be removed as soon as all users are migrated to the newer API.
+    static HBFace Make(T input, hb_face_t* face) {
+        hb_subset_input_set_retain_gids(input, true);
+        return HBFace(hb_subset(face, input));
+    }
+};
+
 // Implementation based on SkPDFSubsetFont() using harfbuzz.
 sk_sp<SkData> SubsetFont(SkTypeface* typeface, const GlyphUsage& usage) {
   int ttc_index = 0;
@@ -71,10 +106,12 @@ sk_sp<SkData> SubsetFont(SkTypeface* typ
   hb_set_t* glyphs =
       hb_subset_input_glyph_set(input.get());  // Owned by |input|.
   usage.ForEach(base::BindRepeating(&AddGlyphs, base::Unretained(glyphs)));
-  hb_subset_input_set_retain_gids(input.get(), true);
+  HBFace subset = SkPDFHarfBuzzSubset<hb_subset_input_t*>::Make(input.get(), face.get());
+  if (!subset) {
+    return nullptr;
+  }
 
-  HbScoped<hb_face_t> subset_face(hb_subset(face.get(), input.get()));
-  HbScoped<hb_blob_t> subset_blob(hb_face_reference_blob(subset_face.get()));
+  HbScoped<hb_blob_t> subset_blob(hb_face_reference_blob(subset.get()));
   if (!subset_blob)
     return nullptr;
 
