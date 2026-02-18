$NetBSD: patch-dpi_dpiutil.c,v 1.1.2.2 2026/02/18 17:00:59 maya Exp $

Avoid ctype(3) abuses

Valid argument of ctype(3) functions must be either EOF or non-negative
value within the range representable as unsigned char.  Invalid values
leads to undefined behavior.

Add all missing d*() ctype(3) helper functions and switch to use them.

Noticed by running dillo on NetBSD where dillo crashes due such
abuses.

See: https://lists.mailman3.com/hyperkitty/list/dillo-dev@mailman3.com/thread/L6QLXSD6UBDK3M5CMXQMRWD6ZB4C65MR/

--- dpi/dpiutil.c.orig	2025-01-18 10:51:30.000000000 +0000
+++ dpi/dpiutil.c
@@ -14,7 +14,6 @@
 #include <stdio.h>
 #include <stdarg.h>
 #include <string.h>
-#include <ctype.h>
 #include <errno.h>
 #include <sys/socket.h>
 
@@ -67,10 +66,10 @@ char *Unescape_uri_str(const char *s)
 
    if (strchr(s, '%')) {
       for (p = buf; (*p = *s); ++s, ++p) {
-         if (*p == '%' && isxdigit(s[1]) && isxdigit(s[2])) {
-            *p = (isdigit(s[1]) ? (s[1] - '0')
+         if (*p == '%' && dIsxdigit(s[1]) && dIsxdigit(s[2])) {
+            *p = (dIsdigit(s[1]) ? (s[1] - '0')
                                 : D_ASCII_TOUPPER(s[1]) - 'A' + 10) * 16;
-            *p += isdigit(s[2]) ? (s[2] - '0')
+            *p += dIsdigit(s[2]) ? (s[2] - '0')
                                 : D_ASCII_TOUPPER(s[2]) - 'A' + 10;
             s += 2;
          }
