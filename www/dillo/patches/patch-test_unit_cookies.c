$NetBSD: patch-test_unit_cookies.c,v 1.1.2.2 2026/02/18 17:01:01 maya Exp $

Avoid ctype(3) abuses

Valid argument of ctype(3) functions must be either EOF or non-negative
value within the range representable as unsigned char.  Invalid values
leads to undefined behavior.

Add all missing d*() ctype(3) helper functions and switch to use them.

Noticed by running dillo on NetBSD where dillo crashes due such
abuses.

See: https://lists.mailman3.com/hyperkitty/list/dillo-dev@mailman3.com/thread/L6QLXSD6UBDK3M5CMXQMRWD6ZB4C65MR/

--- test/unit/cookies.c.orig	2025-01-18 10:51:30.000000000 +0000
+++ test/unit/cookies.c
@@ -26,7 +26,6 @@
 #include <stdarg.h>  /* va_list */
 #include <string.h> /* strchr */
 #include <errno.h>
-#include <ctype.h>
 #include <time.h>
 /* net */
 #include <sys/types.h>
@@ -126,7 +125,7 @@ static int Dpi_read_comm_keys(int *port)
       MSG_ERR("[Dpi_read_comm_keys] empty file: %s\n", fname);
    } else {
       *port = strtol(rcline, &tail, 10);
-      for (i = 0; *tail && isxdigit(tail[i+1]); ++i)
+      for (i = 0; *tail && dIsxdigit(tail[i+1]); ++i)
          SharedKey[i] = tail[i+1];
       SharedKey[i] = 0;
       ret = 1;
