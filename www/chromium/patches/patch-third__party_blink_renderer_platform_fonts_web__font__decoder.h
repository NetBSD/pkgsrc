$NetBSD: patch-third__party_blink_renderer_platform_fonts_web__font__decoder.h,v 1.1 2026/10/23 15:05:34 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/renderer/platform/fonts/web_font_decoder.h.orig	2026-10-19 20:07:21.000000000 +0000
+++ third_party/blink/renderer/platform/fonts/web_font_decoder.h
@@ -31,8 +31,6 @@
 #ifndef THIRD_PARTY_BLINK_RENDERER_PLATFORM_FONTS_WEB_FONT_DECODER_H_
 #define THIRD_PARTY_BLINK_RENDERER_PLATFORM_FONTS_WEB_FONT_DECODER_H_
 
-#include <memory>
-
 #include "base/types/expected.h"
 #include "third_party/blink/renderer/platform/platform_export.h"
 #include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"
@@ -42,7 +40,6 @@ class SkTypeface;
 
 namespace blink {
 
-class IftPatcher;
 class SegmentedBuffer;
 
 // Represents a font that has been successfully decoded and sanitized.
@@ -56,32 +53,18 @@ struct PLATFORM_EXPORT DecodedWebFont {
   // The size of the font after decoding and sanitizing.
   size_t decoded_size = 0;
 
-  // Used to discover and apply patches to fonts. `nullptr` if the font is not
-  // IFT-encoded or if Incremental Font Transfer is disabled.
-  std::unique_ptr<IftPatcher> ift_patcher;
-
-  // Defined out of line so that `IftPatcher` only needs to be forward declared
-  // here.
-  DecodedWebFont();
-  DecodedWebFont(DecodedWebFont&&) noexcept;
-  DecodedWebFont& operator=(DecodedWebFont&&) noexcept;
-  DecodedWebFont(const DecodedWebFont&) = delete;
-  DecodedWebFont& operator=(const DecodedWebFont&) = delete;
-  ~DecodedWebFont();
+  // Decodes, decompresses, and sanitizes the raw font data from the provided
+  // `buffer` (which typically contains WOFF, WOFF2, or TTF data).
+  //
+  // Returns:
+  // - On success: A `DecodedWebFont` containing the successfully created
+  //   font.
+  // - On failure: A `String` containing a descriptive error message (e.g., if
+  //   the buffer is empty, the decompressed size exceeds limits, or OTS
+  //   validation fails).
+  static base::expected<DecodedWebFont, String> Create(SegmentedBuffer*);
 };
 
-// Decodes, decompresses, and sanitizes the raw font data from the provided
-// `buffer` (which typically contains WOFF, WOFF2, or TTF data).
-//
-// Returns:
-// - On success: A `DecodedWebFont` containing the successfully created
-//   font.
-// - On failure: A `String` containing a descriptive error message (e.g., if
-//   the buffer is empty, the decompressed size exceeds limits, or OTS
-//   validation fails).
-PLATFORM_EXPORT base::expected<DecodedWebFont, String> DecodeWebFont(
-    SegmentedBuffer* buffer);
-
 }  // namespace blink
 
 #endif  // THIRD_PARTY_BLINK_RENDERER_PLATFORM_FONTS_WEB_FONT_DECODER_H_
