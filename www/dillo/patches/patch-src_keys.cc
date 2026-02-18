$NetBSD: patch-src_keys.cc,v 1.1.2.2 2026/02/18 17:01:00 maya Exp $

Avoid ctype(3) abuses

Valid argument of ctype(3) functions must be either EOF or non-negative
value within the range representable as unsigned char.  Invalid values
leads to undefined behavior.

Add all missing d*() ctype(3) helper functions and switch to use them.

Noticed by running dillo on NetBSD where dillo crashes due such
abuses.

See: https://lists.mailman3.com/hyperkitty/list/dillo-dev@mailman3.com/thread/L6QLXSD6UBDK3M5CMXQMRWD6ZB4C65MR/

--- src/keys.cc.orig	2025-01-18 10:51:30.000000000 +0000
+++ src/keys.cc
@@ -14,7 +14,6 @@
 #include <stdio.h>
 #include <stdlib.h>        /* strtol */
 #include <string.h>
-#include <ctype.h>
 
 #include "dlib/dlib.h"
 #include "keys.hh"
@@ -203,7 +202,7 @@ KeysCommand_t Keys::getKeyCmd()
    KeyBinding_t keyNode;
 
    keyNode.modifier = Fl::event_state() & (FL_SHIFT | FL_CTRL |FL_ALT|FL_META);
-   if (iscntrl(Fl::event_text()[0])) {
+   if (dIscntrl(Fl::event_text()[0])) {
       keyNode.key = Fl::event_key();
    } else {
       const char *beyond = Fl::event_text() + Fl::event_length();
@@ -326,7 +325,7 @@ void Keys::parseKey(char *key, char *com
    }
 
    // Skip space
-   for (  ; isspace(*key); ++key) ;
+   for (  ; dIsspace(*key); ++key) ;
    // Get modifiers
    while(*key == '<' && (p = strchr(key, '>'))) {
       ++key;
