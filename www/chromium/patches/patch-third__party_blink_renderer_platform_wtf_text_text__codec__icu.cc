$NetBSD: patch-third__party_blink_renderer_platform_wtf_text_text__codec__icu.cc,v 1.1 2025/02/06 09:58:24 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/renderer/platform/wtf/text/text_codec_icu.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ third_party/blink/renderer/platform/wtf/text/text_codec_icu.cc
@@ -323,7 +323,7 @@ void TextCodecICU::CreateICUConverter() 
   DCHECK(!converter_icu_);
 
 #if defined(USING_SYSTEM_ICU)
-  const char* name = encoding_.GetName();
+  const AtomicString& name = encoding_.GetName();
   needs_gbk_fallbacks_ =
       name[0] == 'G' && name[1] == 'B' && name[2] == 'K' && !name[3];
 #endif
@@ -448,7 +448,7 @@ String TextCodecICU::Decode(base::span<c
   // <http://bugs.webkit.org/show_bug.cgi?id=17014>
   // Simplified Chinese pages use the code A3A0 to mean "full-width space", but
   // ICU decodes it as U+E5E5.
-  if (!strcmp(encoding_.GetName(), "GBK")) {
+  if (!strcmp(encoding_.GetName().Utf8().c_str(), "GBK")) {
     if (EqualIgnoringASCIICase(encoding_.GetName(), "gb18030"))
       resultString.Replace(0xE5E5, kIdeographicSpaceCharacter);
     // Make GBK compliant to the encoding spec and align with GB18030
@@ -611,6 +611,7 @@ static void GbkUrlEscapedEntityCallack(
                               code_point, reason, err);
 }
 
+#if !BUILDFLAG(IS_BSD)
 static void GbkCallbackSubstitute(const void* context,
                                   UConverterFromUnicodeArgs* from_unicode_args,
                                   const UChar* code_units,
@@ -628,6 +629,7 @@ static void GbkCallbackSubstitute(const 
   UCNV_FROM_U_CALLBACK_SUBSTITUTE(context, from_unicode_args, code_units,
                                   length, code_point, reason, err);
 }
+#endif
 #endif  // USING_SYSTEM_ICU
 
 static void NotReachedEntityCallback(const void* context,
