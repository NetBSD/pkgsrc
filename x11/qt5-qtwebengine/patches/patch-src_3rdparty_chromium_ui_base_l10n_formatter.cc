$NetBSD: patch-src_3rdparty_chromium_ui_base_l10n_formatter.cc,v 1.1 2021/08/03 21:04:36 markd Exp $

icu >= 68

--- src/3rdparty/chromium/ui/base/l10n/formatter.cc.orig	2020-11-07 01:22:36.000000000 +0000
+++ src/3rdparty/chromium/ui/base/l10n/formatter.cc
@@ -232,7 +232,7 @@ void Formatter::Format(Unit unit,
                        int value,
                        icu::UnicodeString* formatted_string) const {
   DCHECK(simple_format_[unit]);
-  DCHECK(formatted_string->isEmpty() == TRUE);
+  DCHECK(formatted_string->isEmpty() == true);
   UErrorCode error = U_ZERO_ERROR;
   FormatNumberInPlural(*simple_format_[unit],
                         value, formatted_string, &error);
@@ -248,7 +248,7 @@ void Formatter::Format(TwoUnits units,
       << "Detailed() not implemented for your (format, length) combination!";
   DCHECK(detailed_format_[units][1])
       << "Detailed() not implemented for your (format, length) combination!";
-  DCHECK(formatted_string->isEmpty() == TRUE);
+  DCHECK(formatted_string->isEmpty() == true);
   UErrorCode error = U_ZERO_ERROR;
   FormatNumberInPlural(*detailed_format_[units][0], value_1,
                        formatted_string, &error);
@@ -281,7 +281,7 @@ std::unique_ptr<icu::MessageFormat> Form
     base::string16 pattern = l10n_util::GetStringUTF16(pluralities.id);
     UErrorCode error = U_ZERO_ERROR;
     std::unique_ptr<icu::MessageFormat> format(new icu::MessageFormat(
-        icu::UnicodeString(FALSE, pattern.data(), pattern.length()), error));
+        icu::UnicodeString(false, pattern.data(), pattern.length()), error));
     DCHECK(U_SUCCESS(error));
     if (format.get())
       return format;
