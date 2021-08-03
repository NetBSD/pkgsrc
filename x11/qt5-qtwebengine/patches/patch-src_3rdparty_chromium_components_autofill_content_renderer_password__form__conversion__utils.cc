$NetBSD: patch-src_3rdparty_chromium_components_autofill_content_renderer_password__form__conversion__utils.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/components/autofill/content/renderer/password_form_conversion_utils.cc.orig	2020-07-08 21:40:39.000000000 +0000
+++ src/3rdparty/chromium/components/autofill/content/renderer/password_form_conversion_utils.cc
@@ -19,7 +19,7 @@
 #include "third_party/blink/public/web/web_form_control_element.h"
 #include "third_party/blink/public/web/web_input_element.h"
 #include "third_party/blink/public/web/web_local_frame.h"
-#include "third_party/re2/src/re2/re2.h"
+#include <re2/re2.h>
 #include "url/gurl.h"
 
 using blink::WebElement;
