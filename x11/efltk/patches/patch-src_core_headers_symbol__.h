$NetBSD: patch-src_core_headers_symbol__.h,v 1.1 2018/04/20 01:36:00 christos Exp $

Avoid gcc-6 narrowing warnings

--- src/core/headers/symbol_.h.orig	2003-01-01 21:37:15.000000000 -0500
+++ src/core/headers/symbol_.h	2018-04-19 21:27:17.409980104 -0400
@@ -1,6 +1,6 @@
 /* symbol */
 
-static const char unicode_to_symbol_1b_0020[] = {
+static const unsigned char unicode_to_symbol_1b_0020[] = {
 /* U+0020 */ 0x20,
 /* U+0021 */ 0x21,
 0x00,
@@ -219,11 +219,11 @@
 /* U+00F7 */ 0xB8,
 };
 
-static const char unicode_to_symbol_1b_0192[] = {
+static const unsigned char unicode_to_symbol_1b_0192[] = {
 /* U+0192 */ 0xA6,
 };
 
-static const char unicode_to_symbol_1b_0391[] = {
+static const unsigned char unicode_to_symbol_1b_0391[] = {
 /* U+0391 */ 0x41,
 /* U+0392 */ 0x42,
 /* U+0393 */ 0x47,
@@ -296,7 +296,7 @@
 /* U+03D6 */ 0x76,
 };
 
-static const char unicode_to_symbol_1b_2022[] = {
+static const unsigned char unicode_to_symbol_1b_2022[] = {
 /* U+2022 */ 0xB7,
 0x00,
 0x00,
@@ -1076,11 +1076,11 @@
 /* U+232A */ 0xF1,
 };
 
-static const char unicode_to_symbol_1b_25CA[] = {
+static const unsigned char unicode_to_symbol_1b_25CA[] = {
 /* U+25CA */ 0xE0,
 };
 
-static const char unicode_to_symbol_1b_2660[] = {
+static const unsigned char unicode_to_symbol_1b_2660[] = {
 /* U+2660 */ 0xAA,
 0x00,
 0x00,
@@ -1090,13 +1090,13 @@
 /* U+2666 */ 0xA8,
 };
 
-static const char unicode_to_symbol_1b_F6D9[] = {
+static const unsigned char unicode_to_symbol_1b_F6D9[] = {
 /* U+F6D9 */ 0xD3,
 /* U+F6DA */ 0xD2,
 /* U+F6DB */ 0xD4,
 };
 
-static const char unicode_to_symbol_1b_F8E5[] = {
+static const unsigned char unicode_to_symbol_1b_F8E5[] = {
 /* U+F8E5 */ 0x60,
 /* U+F8E6 */ 0xBD,
 /* U+F8E7 */ 0xBE,
