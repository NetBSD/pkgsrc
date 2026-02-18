$NetBSD: patch-dlib_dlib.h,v 1.1.2.2 2026/02/18 17:00:59 maya Exp $

Avoid ctype(3) abuses

Valid argument of ctype(3) functions must be either EOF or non-negative
value within the range representable as unsigned char.  Invalid values
leads to undefined behavior.

Add all missing d*() ctype(3) helper functions and switch to use them.

Noticed by running dillo on NetBSD where dillo crashes due such
abuses.

See: https://lists.mailman3.com/hyperkitty/list/dillo-dev@mailman3.com/thread/L6QLXSD6UBDK3M5CMXQMRWD6ZB4C65MR/

--- dlib/dlib.h.orig	2025-01-18 10:51:30.000000000 +0000
+++ dlib/dlib.h
@@ -1,6 +1,7 @@
 #ifndef __DLIB_H__
 #define __DLIB_H__
 
+#include <ctype.h>
 #include <stdio.h>     /* for FILE*  */
 #include <stddef.h>    /* for size_t */
 #include <stdarg.h>    /* for va_list */
@@ -30,8 +31,15 @@ extern "C" {
 #define MIN(a, b)  (((a) < (b)) ? (a) : (b))
 
 /* Handle signed char */
-#define dIsspace(c) isspace((uchar_t)(c))
 #define dIsalnum(c) isalnum((uchar_t)(c))
+#define dIsalpha(c) isalpha((uchar_t)(c))
+#define dIscntrl(c) iscntrl((uchar_t)(c))
+#define dIsdigit(c) isdigit((uchar_t)(c))
+#define dIsprint(c) isprint((uchar_t)(c))
+#define dIspunct(c) ispunct((uchar_t)(c))
+#define dIsspace(c) isspace((uchar_t)(c))
+#define dIsxdigit(c) isxdigit((uchar_t)(c))
+#define dTolower(c) tolower((uchar_t)(c))
 
 #define D_ASCII_TOUPPER(c) (((c) >= 'a' && (c) <= 'z') ? (c) - 0x20 : (c))
 #define D_ASCII_TOLOWER(c) (((c) >= 'A' && (c) <= 'Z') ? (c) + 0x20 : (c))
