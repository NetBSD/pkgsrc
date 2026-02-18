$NetBSD: patch-src_IO_tls__openssl.c,v 1.1.2.2 2026/02/18 17:01:00 maya Exp $

Avoid ctype(3) abuses

Valid argument of ctype(3) functions must be either EOF or non-negative
value within the range representable as unsigned char.  Invalid values
leads to undefined behavior.

Add all missing d*() ctype(3) helper functions and switch to use them.

Noticed by running dillo on NetBSD where dillo crashes due such
abuses.

See: https://lists.mailman3.com/hyperkitty/list/dillo-dev@mailman3.com/thread/L6QLXSD6UBDK3M5CMXQMRWD6ZB4C65MR/

--- src/IO/tls_openssl.c.orig	2025-01-18 10:51:30.000000000 +0000
+++ src/IO/tls_openssl.c
@@ -39,7 +39,6 @@
 #include <sys/stat.h>
 #include <sys/types.h>
 
-#include <ctype.h>            /* tolower for wget stuff */
 #include <stdio.h>
 #include <errno.h>
 #include "../../dlib/dlib.h"
@@ -576,13 +575,13 @@ static bool_t pattern_match (const char 
 
   const char *p = pattern, *n = string;
   char c;
-  for (; (c = tolower (*p++)) != '\0'; n++)
+  for (; (c = dTolower (*p++)) != '\0'; n++)
     if (c == '*')
       {
-        for (c = tolower (*p); c == '*'; c = tolower (*++p))
+        for (c = dTolower (*p); c == '*'; c = dTolower (*++p))
           ;
         for (; *n != '\0'; n++)
-          if (tolower (*n) == c && pattern_match (p, n))
+          if (dTolower (*n) == c && pattern_match (p, n))
             return TRUE;
 #ifdef ASTERISK_EXCLUDES_DOT
           else if (*n == '.')
@@ -592,7 +591,7 @@ static bool_t pattern_match (const char 
       }
     else
       {
-        if (c != tolower (*n))
+        if (c != dTolower (*n))
           return FALSE;
       }
   return *n == '\0';
