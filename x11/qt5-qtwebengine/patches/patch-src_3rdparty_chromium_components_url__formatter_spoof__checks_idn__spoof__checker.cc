$NetBSD: patch-src_3rdparty_chromium_components_url__formatter_spoof__checks_idn__spoof__checker.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

icu >= 68

--- src/3rdparty/chromium/components/url_formatter/spoof_checks/idn_spoof_checker.cc.orig	2020-11-07 01:22:36.000000000 +0000
+++ src/3rdparty/chromium/components/url_formatter/spoof_checks/idn_spoof_checker.cc
@@ -271,7 +271,7 @@ IDNSpoofChecker::IDNSpoofChecker() {
   // The ideal fix would be to change the omnibox font used for Thai. In
   // that case, the Linux-only list should be revisited and potentially
   // removed.
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
        "[ทนบพรหเแ๐ดลปฟม]",
 #else
        "[บพเแ๐]",
@@ -347,7 +347,7 @@ bool IDNSpoofChecker::SafeToDisplayAsUni
   if (U_FAILURE(status) || (result & USPOOF_ALL_CHECKS))
     return false;
 
-  icu::UnicodeString label_string(FALSE /* isTerminated */, label.data(),
+  icu::UnicodeString label_string(false /* isTerminated */, label.data(),
                                   base::checked_cast<int32_t>(label.size()));
 
   // A punycode label with 'xn--' prefix is not subject to the URL
@@ -677,7 +677,7 @@ bool IDNSpoofChecker::IsWholeScriptConfu
     base::StringPiece tld,
     base::StringPiece16 tld_unicode) {
   icu::UnicodeString tld_string(
-      FALSE /* isTerminated */, tld_unicode.data(),
+      false /* isTerminated */, tld_unicode.data(),
       base::checked_cast<int32_t>(tld_unicode.size()));
   // Allow if the TLD contains any letter from the script, in which case it's
   // likely to be a TLD in that script.
