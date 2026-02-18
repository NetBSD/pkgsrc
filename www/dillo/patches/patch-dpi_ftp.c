$NetBSD: patch-dpi_ftp.c,v 1.1.2.2 2026/02/18 17:00:59 maya Exp $

Avoid ctype(3) abuses

Valid argument of ctype(3) functions must be either EOF or non-negative
value within the range representable as unsigned char.  Invalid values
leads to undefined behavior.

Add all missing d*() ctype(3) helper functions and switch to use them.

Noticed by running dillo on NetBSD where dillo crashes due such
abuses.

See: https://lists.mailman3.com/hyperkitty/list/dillo-dev@mailman3.com/thread/L6QLXSD6UBDK3M5CMXQMRWD6ZB4C65MR/

--- dpi/ftp.c.orig	2025-01-18 10:51:30.000000000 +0000
+++ dpi/ftp.c
@@ -39,7 +39,6 @@
 #include <sys/wait.h>
 #include <errno.h>
 #include <sys/time.h>
-#include <ctype.h>
 
 #include "../dpip/dpip.h"
 #include "dpiutil.h"
