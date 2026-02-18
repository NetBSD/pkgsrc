$NetBSD: patch-dlib_dlib.c,v 1.1.2.2 2026/02/18 17:00:59 maya Exp $

Avoid ctype(3) abuses

Valid argument of ctype(3) functions must be either EOF or non-negative
value within the range representable as unsigned char.  Invalid values
leads to undefined behavior.

Add all missing d*() ctype(3) helper functions and switch to use them.

Noticed by running dillo on NetBSD where dillo crashes due such
abuses.

See: https://lists.mailman3.com/hyperkitty/list/dillo-dev@mailman3.com/thread/L6QLXSD6UBDK3M5CMXQMRWD6ZB4C65MR/

--- dlib/dlib.c.orig	2025-01-18 10:51:30.000000000 +0000
+++ dlib/dlib.c
@@ -24,7 +24,6 @@
 #include <string.h>
 #include <unistd.h>
 #include <errno.h>
-#include <ctype.h>
 #include <time.h>
 
 #include "dlib.h"
@@ -525,7 +524,7 @@ const char *dStr_printable(Dstr *in, int
       out = dStr_sized_new(in->len);
 
    for (i = 0; (i < in->len) && (out->len < maxlen); ++i) {
-      if (isprint(in->str[i]) || (in->str[i] == '\n')) {
+      if (dIsprint(in->str[i]) || (in->str[i] == '\n')) {
          dStr_append_c(out, in->str[i]);
       } else {
          dStr_append_l(out, "\\x", 2);
