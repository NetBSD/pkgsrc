$NetBSD: patch-src_3rdparty_chromium_components_spellcheck_renderer_spellcheck__worditerator.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

icu >= 68

--- src/3rdparty/chromium/components/spellcheck/renderer/spellcheck_worditerator.cc.orig	2020-11-07 01:22:36.000000000 +0000
+++ src/3rdparty/chromium/components/spellcheck/renderer/spellcheck_worditerator.cc
@@ -424,7 +424,7 @@ bool SpellcheckWordIterator::Normalize(s
   // spellchecker and we need manual normalization as well. The normalized
   // text does not have to be NUL-terminated since its characters are copied to
   // string16, which adds a NUL character when we need.
-  icu::UnicodeString input(FALSE, &text_[input_start],
+  icu::UnicodeString input(false, &text_[input_start],
                            base::checked_cast<int32_t>(input_length));
   UErrorCode status = U_ZERO_ERROR;
   icu::UnicodeString output;
