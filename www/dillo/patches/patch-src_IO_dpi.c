$NetBSD: patch-src_IO_dpi.c,v 1.1.2.2 2026/02/18 17:01:00 maya Exp $

Avoid ctype(3) abuses

Valid argument of ctype(3) functions must be either EOF or non-negative
value within the range representable as unsigned char.  Invalid values
leads to undefined behavior.

Add all missing d*() ctype(3) helper functions and switch to use them.

Noticed by running dillo on NetBSD where dillo crashes due such
abuses.

See: https://lists.mailman3.com/hyperkitty/list/dillo-dev@mailman3.com/thread/L6QLXSD6UBDK3M5CMXQMRWD6ZB4C65MR/

--- src/IO/dpi.c.orig	2025-01-18 10:51:30.000000000 +0000
+++ src/IO/dpi.c
@@ -25,7 +25,6 @@
 #include <stdio.h>
 #include <errno.h>           /* for errno */
 #include <fcntl.h>
-#include <ctype.h>           /* isxdigit */
 #include <stdint.h>
 
 #include <sys/socket.h>
@@ -404,7 +403,7 @@ static int Dpi_read_comm_keys(int *port)
       MSG_ERR("[Dpi_read_comm_keys] empty file: %s\n", fname);
    } else {
       *port = strtol(rcline, &tail, 10);
-      for (i = 0; *tail && isxdigit(tail[i+1]); ++i)
+      for (i = 0; *tail && dIsxdigit(tail[i+1]); ++i)
          SharedKey[i] = tail[i+1];
       SharedKey[i] = 0;
       ret = 1;
