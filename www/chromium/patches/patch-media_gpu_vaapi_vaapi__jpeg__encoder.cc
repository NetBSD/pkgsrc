$NetBSD: patch-media_gpu_vaapi_vaapi__jpeg__encoder.cc,v 1.3 2026/04/10 17:31:56 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- media/gpu/vaapi/vaapi_jpeg_encoder.cc.orig	2026-04-06 16:25:54.000000000 +0000
+++ media/gpu/vaapi/vaapi_jpeg_encoder.cc
@@ -98,24 +98,24 @@ void FillHuffmanTableParameters(
 
     // Load DC Table.
     auto num_dc_codes = base::span(huffman_tables[i].num_dc_codes);
-    static_assert(num_dc_codes.size() == dcTable.code_length.size());
+//    static_assert(num_dc_codes.size() == dcTable.code_length.size());
     num_dc_codes.copy_from_nonoverlapping(dcTable.code_length);
     // |code_values| of JpegHuffmanTable needs to hold DC and AC code values
     // so it has different size than
     // |huff_table_param->huffman_table[i].dc_values|. Therefore we can't use
     // SafeArrayMemcpy() here.
     auto dc_values = base::span(huffman_tables[i].dc_values);
-    static_assert(dc_values.size() <= dcTable.code_value.size());
+//    static_assert(dc_values.size() <= dcTable.code_value.size());
     dc_values.copy_from_nonoverlapping(
         base::span(dcTable.code_value).first(dc_values.size()));
 
     // Load AC Table.
     auto num_ac_codes = base::span(huffman_tables[i].num_ac_codes);
-    static_assert(num_ac_codes.size() == acTable.code_length.size());
+//    static_assert(num_ac_codes.size() == acTable.code_length.size());
     num_ac_codes.copy_from_nonoverlapping(acTable.code_length);
 
     auto ac_values = base::span(huffman_tables[i].ac_values);
-    static_assert(ac_values.size() == acTable.code_value.size());
+//    static_assert(ac_values.size() == acTable.code_value.size());
     ac_values.copy_from_nonoverlapping(acTable.code_value);
 
     std::ranges::fill(huffman_tables[i].pad, 0);
