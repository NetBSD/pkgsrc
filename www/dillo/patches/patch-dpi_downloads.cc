$NetBSD: patch-dpi_downloads.cc,v 1.1.2.2 2026/02/18 17:00:59 maya Exp $

Avoid ctype(3) abuses

Valid argument of ctype(3) functions must be either EOF or non-negative
value within the range representable as unsigned char.  Invalid values
leads to undefined behavior.

Add all missing d*() ctype(3) helper functions and switch to use them.

Noticed by running dillo on NetBSD where dillo crashes due such
abuses.

See: https://lists.mailman3.com/hyperkitty/list/dillo-dev@mailman3.com/thread/L6QLXSD6UBDK3M5CMXQMRWD6ZB4C65MR/

--- dpi/downloads.cc.orig	2025-01-18 10:51:30.000000000 +0000
+++ dpi/downloads.cc
@@ -20,7 +20,6 @@
 #include <unistd.h>
 #include <errno.h>
 #include <fcntl.h>
-#include <ctype.h>
 #include <math.h>
 #include <time.h>
 #include <signal.h>
@@ -513,7 +512,7 @@ void DLItem::log_text_add(const char *bu
       case ST_newline:
          if (*p == ' ') {
             log_state = ST_discard;
-         } else if (isdigit(*p)) {
+         } else if (dIsdigit(*p)) {
             *q++ = *p; log_state = ST_number;
          } else if (*p == '\n') {
             *q++ = *p;
@@ -522,10 +521,10 @@ void DLItem::log_text_add(const char *bu
          }
          break;
       case ST_number:
-         if (isdigit(*q++ = *p)) {
+         if (dIsdigit((*q++ = *p))) {
             // keep here
          } else if (*p == 'K') {
-            for (--q; isdigit(q[-1]); --q) ; 
+            for (--q; dIsdigit(q[-1]); --q) ;
             log_state = ST_discard;
          } else {
             log_state = ST_copy;
@@ -549,9 +548,9 @@ void DLItem::log_text_add(const char *bu
    // Now scan for the length of the file
    if (total_bytesize == -1) {
       p = strstr(log_text, "\nLength: ");
-      if (p && isdigit(p[9]) && strchr(p + 9, ' ')) {
+      if (p && dIsdigit(p[9]) && strchr(p + 9, ' ')) {
          for (p += 9, d = &num[0]; *p != ' '; ++p)
-            if (isdigit(*p))
+            if (dIsdigit(*p))
                *d++ = *p;
          *d = 0;
          total_bytesize = strtol (num, NULL, 10);
