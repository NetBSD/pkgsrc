$NetBSD: patch-src_3rdparty_chromium_third_party_skia_src_utils_SkParseColor.cpp,v 1.1 2023/09/20 02:10:54 mrg Exp $

Fix GCC 12 support, from upstream:

   https://chromium.googlesource.com/skia/+/cd397f3c4738beb6%5E%21/


--- src/3rdparty/chromium/third_party/skia/src/utils/SkParseColor.cpp.orig	2022-04-06 08:32:17.000000000 -0500
+++ src/3rdparty/chromium/third_party/skia/src/utils/SkParseColor.cpp	2023-09-19 17:23:45.603492707 -0500
@@ -8,6 +8,8 @@
 
 #include "include/utils/SkParse.h"
 
+#include <iterator>
+
 static constexpr const char* gColorNames[] = {
     "aliceblue",
     "antiquewhite",
