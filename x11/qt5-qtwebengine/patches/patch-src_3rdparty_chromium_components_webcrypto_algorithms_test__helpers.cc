$NetBSD: patch-src_3rdparty_chromium_components_webcrypto_algorithms_test__helpers.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/components/webcrypto/algorithms/test_helpers.cc.orig	2020-07-08 21:40:42.000000000 +0000
+++ src/3rdparty/chromium/components/webcrypto/algorithms/test_helpers.cc
@@ -25,7 +25,7 @@
 #include "components/webcrypto/status.h"
 #include "third_party/blink/public/platform/web_crypto_algorithm_params.h"
 #include "third_party/blink/public/platform/web_crypto_key_algorithm.h"
-#include "third_party/re2/src/re2/re2.h"
+#include <re2/re2.h>
 
 namespace webcrypto {
 
