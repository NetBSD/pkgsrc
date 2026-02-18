$NetBSD: patch-src_misc.c,v 1.1.2.2 2026/02/18 17:01:01 maya Exp $

Avoid ctype(3) abuses

Valid argument of ctype(3) functions must be either EOF or non-negative
value within the range representable as unsigned char.  Invalid values
leads to undefined behavior.

Add all missing d*() ctype(3) helper functions and switch to use them.

Noticed by running dillo on NetBSD where dillo crashes due such
abuses.

See: https://lists.mailman3.com/hyperkitty/list/dillo-dev@mailman3.com/thread/L6QLXSD6UBDK3M5CMXQMRWD6ZB4C65MR/

--- src/misc.c.orig	2025-01-18 10:51:30.000000000 +0000
+++ src/misc.c
@@ -12,7 +12,6 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
-#include <ctype.h>
 #include <assert.h>
 
 #include "utf8.hh"
@@ -222,13 +221,13 @@ void a_Misc_parse_content_type(const cha
    if (!(str = type))
       return;
 
-   for (s = str; *s && d_isascii((uchar_t)*s) && !iscntrl((uchar_t)*s) &&
+   for (s = str; *s && d_isascii((uchar_t)*s) && !dIscntrl(*s) &&
         !strchr(tspecials_space, *s); s++) ;
    if (major)
       *major = dStrndup(str, s - str);
 
    if (*s == '/') {
-      for (str = ++s; *s && d_isascii((uchar_t)*s) && !iscntrl((uchar_t)*s) &&
+      for (str = ++s; *s && d_isascii((uchar_t)*s) && !dIscntrl(*s) &&
            !strchr(tspecials_space, *s); s++) ;
       if (minor)
          *minor = dStrndup(str, s - str);
