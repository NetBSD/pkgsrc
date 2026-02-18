$NetBSD: patch-src_hsts.c,v 1.1.2.2 2026/02/18 17:01:00 maya Exp $

Avoid ctype(3) abuses

Valid argument of ctype(3) functions must be either EOF or non-negative
value within the range representable as unsigned char.  Invalid values
leads to undefined behavior.

Add all missing d*() ctype(3) helper functions and switch to use them.

Noticed by running dillo on NetBSD where dillo crashes due such
abuses.

See: https://lists.mailman3.com/hyperkitty/list/dillo-dev@mailman3.com/thread/L6QLXSD6UBDK3M5CMXQMRWD6ZB4C65MR/

--- src/hsts.c.orig	2025-01-18 10:51:30.000000000 +0000
+++ src/hsts.c
@@ -26,7 +26,6 @@
 #include <time.h>
 #include <errno.h>
 #include <limits.h> /* for INT_MAX */
-#include <ctype.h> /* for isspace */
 #include <stdlib.h> /* for strtol */
 
 #include "hsts.h"
@@ -223,7 +222,7 @@ void a_Hsts_set(const char *header, cons
       /* Get the value for the attribute and store it */
       if (dStrAsciiCasecmp(attr, "max-age") == 0) {
          value = Hsts_parse_value(&header);
-         if (isdigit(*value)) {
+         if (dIsdigit(*value)) {
             errno = 0;
             max_age = strtol(value, NULL, 10);
             if (errno == ERANGE)
