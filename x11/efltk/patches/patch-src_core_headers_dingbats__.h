$NetBSD: patch-src_core_headers_dingbats__.h,v 1.1 2018/04/20 01:36:00 christos Exp $

Avoid gcc-6 narrowing warnings

--- src/core/headers/dingbats_.h.orig	2003-01-01 21:37:15.000000000 -0500
+++ src/core/headers/dingbats_.h	2018-04-19 21:26:44.519960223 -0400
@@ -1,6 +1,6 @@
 /* dingbats */
 
-static const char unicode_to_dingbats_1b_0020[] = {
+static const unsigned char unicode_to_dingbats_1b_0020[] = {
 /* U+0020 */ 0x20,
 0x00,
 0x00,
@@ -132,14 +132,14 @@
 /* U+00A0 */ 0x20,
 };
 
-static const char unicode_to_dingbats_1b_2192[] = {
+static const unsigned char unicode_to_dingbats_1b_2192[] = {
 /* U+2192 */ 0xD5,
 0x00,
 /* U+2194 */ 0xD6,
 /* U+2195 */ 0xD7,
 };
 
-static const char unicode_to_dingbats_1b_2460[] = {
+static const unsigned char unicode_to_dingbats_1b_2460[] = {
 /* U+2460 */ 0xAC,
 /* U+2461 */ 0xAD,
 /* U+2462 */ 0xAE,
@@ -152,7 +152,7 @@
 /* U+2469 */ 0xB5,
 };
 
-static const char unicode_to_dingbats_1b_25A0[] = {
+static const unsigned char unicode_to_dingbats_1b_25A0[] = {
 /* U+25A0 */ 0x6E,
 0x00,
 0x00,
@@ -354,7 +354,7 @@
 /* U+2666 */ 0xA9,
 };
 
-static const char unicode_to_dingbats_1b_2701[] = {
+static const unsigned char unicode_to_dingbats_1b_2701[] = {
 /* U+2701 */ 0x21,
 /* U+2702 */ 0x22,
 /* U+2703 */ 0x23,
@@ -547,7 +547,7 @@
 /* U+27BE */ 0xFE,
 };
 
-static const char unicode_to_dingbats_1b_F8D7[] = {
+static const unsigned char unicode_to_dingbats_1b_F8D7[] = {
 /* U+F8D7 */ 0x80,
 /* U+F8D8 */ 0x81,
 /* U+F8D9 */ 0x82,
