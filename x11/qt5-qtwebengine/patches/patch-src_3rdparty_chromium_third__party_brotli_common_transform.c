$NetBSD: patch-src_3rdparty_chromium_third__party_brotli_common_transform.c,v 1.1 2021/08/03 21:04:36 markd Exp $

--- src/3rdparty/chromium/third_party/brotli/common/transform.c.orig	2020-06-25 09:32:02.000000000 +0000
+++ src/3rdparty/chromium/third_party/brotli/common/transform.c
@@ -24,7 +24,7 @@ static const char kPrefixSuffix[217] =
 /* 8x  _0 _ _3    _8   _C _E _ _1     _7       _F */
       " not \3er \3al \4ful \4ive \5less \4es"
 /* Ax       _5   _9   _D    _2    _7     _D */
-      "t \4ize \2\xc2\xa0\4ous \5 the \2e \0";
+      "t \4ize \2\xc2\xa0\4ous \5 the \2e ";
 /* Cx    _2    _7___ ___ _A    _F     _5  _8 */
 
 static const uint16_t kPrefixSuffixMap[50] = {
