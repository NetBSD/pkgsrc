$NetBSD: patch-src_3rdparty_chromium_v8_src_regexp_regexp-parser.cc,v 1.1 2026/11/11 11:48:37 wiz Exp $

ICU 79 support, based on
https://www.linuxfromscratch.org/patches/blfs/svn/qtwebengine-6.11.3-icu4c_79-1.patch

--- src/3rdparty/chromium/v8/src/regexp/regexp-parser.cc.orig	2025-04-22 13:00:44.000000000 +0000
+++ src/3rdparty/chromium/v8/src/regexp/regexp-parser.cc
@@ -12,6 +12,7 @@
 #include "src/regexp/property-sequences.h"
 #include "src/regexp/regexp-macro-assembler.h"
 #include "src/regexp/regexp.h"
+#include "src/regexp/special-case.h"
 #include "src/strings/char-predicates-inl.h"
 #include "src/utils/ostreams.h"
 #include "src/utils/utils.h"
@@ -2056,9 +2057,14 @@ bool RegExpBuilder::NeedsDesugaringForIgnoreCase(uc32 
 bool RegExpBuilder::NeedsDesugaringForIgnoreCase(uc32 c) {
 #ifdef V8_INTL_SUPPORT
   if (unicode() && ignore_case()) {
+    if (c <= unibrow::Utf16::kMaxNonSurrogateCharCode) {
+      return RegExpCaseFolding::HasSupplementaryEquivalents(
+          static_cast<uc16>(c));
+    }
     icu::UnicodeSet set(c, c);
     set.closeOver(USET_CASE_INSENSITIVE);
     set.removeAllStrings();
+    RegExpCaseFolding::CloseOver(set, RegExpCaseFolding::Mode::kUnicode);
     return set.size() > 1;
   }
   // In the case where ICU is not included, we act as if the unicode flag is
