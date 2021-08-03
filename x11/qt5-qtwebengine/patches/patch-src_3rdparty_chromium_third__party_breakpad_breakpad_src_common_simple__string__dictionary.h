$NetBSD: patch-src_3rdparty_chromium_third__party_breakpad_breakpad_src_common_simple__string__dictionary.h,v 1.1 2021/08/03 21:04:36 markd Exp $

--- src/3rdparty/chromium/third_party/breakpad/breakpad/src/common/simple_string_dictionary.h.orig	2020-07-15 19:01:31.000000000 +0000
+++ src/3rdparty/chromium/third_party/breakpad/breakpad/src/common/simple_string_dictionary.h
@@ -33,7 +33,7 @@
 #include <assert.h>
 #include <string.h>
 
-#include "common/basictypes.h"
+#include "third_party/breakpad/breakpad/src/common/basictypes.h"
 
 namespace google_breakpad {
 
