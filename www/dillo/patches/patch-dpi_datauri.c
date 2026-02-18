$NetBSD: patch-dpi_datauri.c,v 1.1.2.2 2026/02/18 17:00:59 maya Exp $

Avoid ctype(3) abuses

Valid argument of ctype(3) functions must be either EOF or non-negative
value within the range representable as unsigned char.  Invalid values
leads to undefined behavior.

Add all missing d*() ctype(3) helper functions and switch to use them.

Noticed by running dillo on NetBSD where dillo crashes due such
abuses.

See: https://lists.mailman3.com/hyperkitty/list/dillo-dev@mailman3.com/thread/L6QLXSD6UBDK3M5CMXQMRWD6ZB4C65MR/

--- dpi/datauri.c.orig	2025-01-18 10:51:30.000000000 +0000
+++ dpi/datauri.c
@@ -15,7 +15,6 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
-#include <ctype.h>
 #include <errno.h>
 
 #include "../dpip/dpip.h"
@@ -45,7 +44,7 @@ static void b64strip_illegal_chars(unsig
    MSG("len=%d{%s}\n", strlen((char*)str), str);
 
    for (p = s; (*p = *s); ++s) {
-      if (d_isascii(*p) && (isalnum(*p) || strchr("+/=", *p)))
+      if (d_isascii(*p) && (dIsalnum(*p) || strchr("+/=", *p)))
          ++p;
    }
 
