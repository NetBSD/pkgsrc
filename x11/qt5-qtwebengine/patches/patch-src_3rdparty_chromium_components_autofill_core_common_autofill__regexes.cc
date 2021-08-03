$NetBSD: patch-src_3rdparty_chromium_components_autofill_core_common_autofill__regexes.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

icu >= 68

--- src/3rdparty/chromium/components/autofill/core/common/autofill_regexes.cc.orig	2020-11-07 01:22:36.000000000 +0000
+++ src/3rdparty/chromium/components/autofill/core/common/autofill_regexes.cc
@@ -43,7 +43,7 @@ class AutofillRegexes {
 icu::RegexMatcher* AutofillRegexes::GetMatcher(const base::string16& pattern) {
   auto it = matchers_.find(pattern);
   if (it == matchers_.end()) {
-    const icu::UnicodeString icu_pattern(FALSE, pattern.data(),
+    const icu::UnicodeString icu_pattern(false, pattern.data(),
                                          pattern.length());
 
     UErrorCode status = U_ZERO_ERROR;
@@ -70,20 +70,20 @@ bool MatchesPattern(const base::string16
   base::AutoLock lock(*g_lock);
 
   icu::RegexMatcher* matcher = g_autofill_regexes->GetMatcher(pattern);
-  icu::UnicodeString icu_input(FALSE, input.data(), input.length());
+  icu::UnicodeString icu_input(false, input.data(), input.length());
   matcher->reset(icu_input);
 
   UErrorCode status = U_ZERO_ERROR;
   UBool matched = matcher->find(0, status);
   DCHECK(U_SUCCESS(status));
 
-  if (matched == TRUE && match) {
+  if (matched == true && match) {
     icu::UnicodeString match_unicode = matcher->group(0, status);
     DCHECK(U_SUCCESS(status));
     *match = base::i18n::UnicodeStringToString16(match_unicode);
   }
 
-  return matched == TRUE;
+  return matched == true;
 }
 
 }  // namespace autofill
