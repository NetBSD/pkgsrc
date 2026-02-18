$NetBSD: patch-dw_textblock.cc,v 1.1.2.2 2026/02/18 17:01:00 maya Exp $

Avoid ctype(3) abuses

Valid argument of ctype(3) functions must be either EOF or non-negative
value within the range representable as unsigned char.  Invalid values
leads to undefined behavior.

Add all missing d*() ctype(3) helper functions and switch to use them.

Noticed by running dillo on NetBSD where dillo crashes due such
abuses.

See: https://lists.mailman3.com/hyperkitty/list/dillo-dev@mailman3.com/thread/L6QLXSD6UBDK3M5CMXQMRWD6ZB4C65MR/

--- dw/textblock.cc.orig	2025-01-18 10:51:30.000000000 +0000
+++ dw/textblock.cc
@@ -1238,14 +1238,14 @@ void Textblock::drawText(core::View *vie
                bool initial_seen = false;
 
                for (int i = 0; i < start; i++)
-                  if (!ispunct(text[i]))
+                  if (!dIspunct(text[i]))
                      initial_seen = true;
                if (initial_seen)
                   break;
 
                int after = 0;
                text += start;
-               while (ispunct(text[after]))
+               while (dIspunct(text[after]))
                   after++;
                if (text[after])
                   after = layout->nextGlyph(text, after);
@@ -1931,7 +1931,7 @@ int Textblock::textWidth(const char *tex
                bool initial_seen = false;
 
                for (int i = 0; i < start; i++)
-                  if (!ispunct(text[i]))
+                  if (!dIspunct(text[i]))
                      initial_seen = true;
                if (initial_seen) {
                   ret = layout->textWidth(style->font, text+start, len);
@@ -1939,7 +1939,7 @@ int Textblock::textWidth(const char *tex
                   int after = 0;
 
                   text += start;
-                  while (ispunct(text[after]))
+                  while (dIspunct(text[after]))
                      after++;
                   if (text[after])
                      after = layout->nextGlyph(text, after);
