$NetBSD: patch-components_autofill_core_browser_form__parsing_autofill__scanner.h,v 1.1 2025/11/04 14:55:37 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/autofill/core/browser/form_parsing/autofill_scanner.h.orig	2025-10-24 16:42:30.000000000 +0000
+++ components/autofill/core/browser/form_parsing/autofill_scanner.h
@@ -11,9 +11,10 @@
 #include "base/containers/span.h"
 #include "base/memory/raw_span.h"
 
-namespace autofill {
+// https://sources.debian.org/patches/chromium/142.0.7444.59-1~deb13u1/fixes/chromium-142-iwyu-field-form-data.patch/
+#include "components/autofill/core/common/form_field_data.h"
 
-class FormFieldData;
+namespace autofill {
 
 // A helper class for parsing a stream of |FormFieldData|'s with lookahead.
 class AutofillScanner {
