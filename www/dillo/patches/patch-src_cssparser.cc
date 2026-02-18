$NetBSD: patch-src_cssparser.cc,v 1.1.2.2 2026/02/18 17:01:00 maya Exp $

Avoid ctype(3) abuses

Valid argument of ctype(3) functions must be either EOF or non-negative
value within the range representable as unsigned char.  Invalid values
leads to undefined behavior.

Add all missing d*() ctype(3) helper functions and switch to use them.

Noticed by running dillo on NetBSD where dillo crashes due such
abuses.

See: https://lists.mailman3.com/hyperkitty/list/dillo-dev@mailman3.com/thread/L6QLXSD6UBDK3M5CMXQMRWD6ZB4C65MR/

--- src/cssparser.cc.orig	2025-01-18 10:51:30.000000000 +0000
+++ src/cssparser.cc
@@ -16,7 +16,6 @@
  * a dillo1 based CSS prototype written by Sebastian Geerken.
  */
 
-#include <ctype.h>
 #include <stdlib.h>
 #include <stdio.h>
 
@@ -530,7 +529,7 @@ void CssParser::nextToken()
 
    while (true) {
       c = getChar();
-      if (isspace(c)) {                    // ignore whitespace
+      if (dIsspace(c)) {                    // ignore whitespace
          spaceSeparated = true;
       } else if (skipString(c, "/*")) {    // ignore comments
          do {
@@ -550,7 +549,7 @@ void CssParser::nextToken()
       c = getChar();
    }
 
-   if (isdigit(c)) {
+   if (dIsdigit(c)) {
       ttype = CSS_TK_DECINT;
       do {
          if (i < maxStrLen - 1) {
@@ -558,7 +557,7 @@ void CssParser::nextToken()
          }
          /* else silently truncated */
          c = getChar();
-      } while (isdigit(c));
+      } while (dIsdigit(c));
       if (c != '.')
          ungetChar();
 
@@ -567,7 +566,7 @@ void CssParser::nextToken()
 
    if (c == '.') {
       c = getChar();
-      if (isdigit(c)) {
+      if (dIsdigit(c)) {
          ttype = CSS_TK_FLOAT;
          if (i < maxStrLen - 1)
             tval[i++] = '.';
@@ -576,7 +575,7 @@ void CssParser::nextToken()
                tval[i++] = c;
             /* else silently truncated */
             c = getChar();
-         } while (isdigit(c));
+         } while (dIsdigit(c));
 
          ungetChar();
          tval[i] = 0;
@@ -604,13 +603,13 @@ void CssParser::nextToken()
       c = getChar();
    }
 
-   if (isalpha(c) || c == '_' || c == '-') {
+   if (dIsalpha(c) || c == '_' || c == '-') {
       ttype = CSS_TK_SYMBOL;
 
       tval[0] = c;
       i = 1;
       c = getChar();
-      while (isalnum(c) || c == '_' || c == '-') {
+      while (dIsalnum(c) || c == '_' || c == '-') {
          if (i < maxStrLen - 1) {
             tval[i] = c;
             i++;
@@ -633,13 +632,13 @@ void CssParser::nextToken()
       while (c != EOF && c != c1) {
          if (c == '\\') {
             d = getChar();
-            if (isxdigit(d)) {
+            if (dIsxdigit(d)) {
                /* Read hex Unicode char. (Actually, strings are yet only 8
                 * bit.) */
                hexbuf[0] = d;
                j = 1;
                d = getChar();
-               while (j < 4 && isxdigit(d)) {
+               while (j < 4 && dIsxdigit(d)) {
                   hexbuf[j] = d;
                   j++;
                   d = getChar();
@@ -674,7 +673,7 @@ void CssParser::nextToken()
       tval[0] = c;
       i = 1;
       c = getChar();
-      while (isxdigit(c)) {
+      while (dIsxdigit(c)) {
          if (i < maxStrLen - 1) {
             tval[i] = c;
             i++;
