$NetBSD: patch-src_IO_http.c,v 1.1.2.2 2026/02/18 17:01:00 maya Exp $

Avoid ctype(3) abuses

Valid argument of ctype(3) functions must be either EOF or non-negative
value within the range representable as unsigned char.  Invalid values
leads to undefined behavior.

Add all missing d*() ctype(3) helper functions and switch to use them.

Noticed by running dillo on NetBSD where dillo crashes due such
abuses.

See: https://lists.mailman3.com/hyperkitty/list/dillo-dev@mailman3.com/thread/L6QLXSD6UBDK3M5CMXQMRWD6ZB4C65MR/

--- src/IO/http.c.orig	2025-01-18 10:51:30.000000000 +0000
+++ src/IO/http.c
@@ -17,7 +17,6 @@
 
 #include <config.h>
 
-#include <ctype.h>              /* isdigit */
 #include <unistd.h>
 #include <errno.h>              /* for errno */
 #include <stdlib.h>
@@ -701,7 +700,7 @@ static char *Http_get_connect_str(const 
    dstr = dStr_new("");
    auth1 = URL_AUTHORITY(url);
    auth_len = strlen(auth1);
-   if (auth_len > 0 && !isdigit(auth1[auth_len - 1]))
+   if (auth_len > 0 && !dIsdigit(auth1[auth_len - 1]))
       /* if no port number, add HTTPS port */
       auth2 = dStrconcat(auth1, ":443", NULL);
    else
