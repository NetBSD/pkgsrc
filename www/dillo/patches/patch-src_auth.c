$NetBSD: patch-src_auth.c,v 1.1.2.2 2026/02/18 17:01:00 maya Exp $

Avoid ctype(3) abuses

Valid argument of ctype(3) functions must be either EOF or non-negative
value within the range representable as unsigned char.  Invalid values
leads to undefined behavior.

Add all missing d*() ctype(3) helper functions and switch to use them.

Noticed by running dillo on NetBSD where dillo crashes due such
abuses.

See: https://lists.mailman3.com/hyperkitty/list/dillo-dev@mailman3.com/thread/L6QLXSD6UBDK3M5CMXQMRWD6ZB4C65MR/

--- src/auth.c.orig	2025-01-18 10:51:30.000000000 +0000
+++ src/auth.c
@@ -17,7 +17,6 @@
  */
 
 
-#include <ctype.h> /* iscntrl, isascii */
 #include "auth.h"
 #include "msg.h"
 #include "misc.h"
@@ -105,7 +104,7 @@ static int Auth_path_is_inside(const cha
 static int Auth_is_token_char(char c)
 {
    const char *invalid = "\"()<>@,;:\\[]?=/{} \t";
-   return (!d_isascii(c) || strchr(invalid, c) || iscntrl((uchar_t)c)) ? 0 : 1;
+   return (!d_isascii(c) || strchr(invalid, c) || dIscntrl(c)) ? 0 : 1;
 }
 
 /**
