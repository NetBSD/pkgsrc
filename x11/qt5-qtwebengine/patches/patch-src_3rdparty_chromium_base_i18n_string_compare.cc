$NetBSD: patch-src_3rdparty_chromium_base_i18n_string_compare.cc,v 1.1 2021/08/03 21:04:34 markd Exp $

icu >= 68

--- src/3rdparty/chromium/base/i18n/string_compare.cc.orig	2020-11-07 01:22:36.000000000 +0000
+++ src/3rdparty/chromium/base/i18n/string_compare.cc
@@ -18,8 +18,8 @@ UCollationResult CompareString16WithColl
                                              StringPiece16 rhs) {
   UErrorCode error = U_ZERO_ERROR;
   UCollationResult result = collator.compare(
-      icu::UnicodeString(FALSE, lhs.data(), static_cast<int>(lhs.length())),
-      icu::UnicodeString(FALSE, rhs.data(), static_cast<int>(rhs.length())),
+      icu::UnicodeString(false, lhs.data(), static_cast<int>(lhs.length())),
+      icu::UnicodeString(false, rhs.data(), static_cast<int>(rhs.length())),
       error);
   DCHECK(U_SUCCESS(error));
   return result;
