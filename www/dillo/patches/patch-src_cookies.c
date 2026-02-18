$NetBSD: patch-src_cookies.c,v 1.1.2.2 2026/02/18 17:01:00 maya Exp $

Avoid ctype(3) abuses

Valid argument of ctype(3) functions must be either EOF or non-negative
value within the range representable as unsigned char.  Invalid values
leads to undefined behavior.

Add all missing d*() ctype(3) helper functions and switch to use them.

Noticed by running dillo on NetBSD where dillo crashes due such
abuses.

See: https://lists.mailman3.com/hyperkitty/list/dillo-dev@mailman3.com/thread/L6QLXSD6UBDK3M5CMXQMRWD6ZB4C65MR/

--- src/cookies.c.orig	2025-01-18 10:51:30.000000000 +0000
+++ src/cookies.c
@@ -36,7 +36,6 @@ void a_Cookies_init(void)
 #include <unistd.h>
 #include <stdlib.h>
 #include <stdio.h>
-#include <ctype.h>
 #include <errno.h>
 
 #include "IO/Url.h"
