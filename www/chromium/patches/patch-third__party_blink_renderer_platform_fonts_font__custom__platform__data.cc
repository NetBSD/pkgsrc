$NetBSD: patch-third__party_blink_renderer_platform_fonts_font__custom__platform__data.cc,v 1.1 2026/10/23 15:05:34 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/renderer/platform/fonts/font_custom_platform_data.cc.orig	2026-10-19 20:07:21.000000000 +0000
+++ third_party/blink/renderer/platform/fonts/font_custom_platform_data.cc
@@ -328,7 +328,8 @@ FontCustomPlatformData* FontCustomPlatfo
     SharedBuffer* buffer,
     String& ots_parse_message) {
   DCHECK(buffer);
-  base::expected<DecodedWebFont, String> decode_result = DecodeWebFont(buffer);
+  base::expected<DecodedWebFont, String> decode_result =
+      DecodedWebFont::Create(buffer);
   if (!decode_result.has_value()) {
     ots_parse_message = std::move(decode_result).error();
     return nullptr;
