$NetBSD: patch-dpi_cookies.c,v 1.1.2.2 2026/02/18 17:00:59 maya Exp $

Avoid ctype(3) abuses

Valid argument of ctype(3) functions must be either EOF or non-negative
value within the range representable as unsigned char.  Invalid values
leads to undefined behavior.

Add all missing d*() ctype(3) helper functions and switch to use them.

Noticed by running dillo on NetBSD where dillo crashes due such
abuses.

See: https://lists.mailman3.com/hyperkitty/list/dillo-dev@mailman3.com/thread/L6QLXSD6UBDK3M5CMXQMRWD6ZB4C65MR/

--- dpi/cookies.c.orig	2025-01-18 10:51:30.000000000 +0000
+++ dpi/cookies.c
@@ -44,7 +44,6 @@ int main(void)
 #include <stdlib.h>
 #include <stdio.h>
 #include <time.h>       /* for time() and time_t */
-#include <ctype.h>
 #include <limits.h>
 #include <netdb.h>
 #include <signal.h>
@@ -487,14 +486,14 @@ static int Cookies_get_timefield(const c
    int n;
    const char *s = *str;
 
-   if (!isdigit(*s))
+   if (!dIsdigit(*s))
       return -1;
 
    n = *(s++) - '0';
-   if (isdigit(*s)) {
+   if (dIsdigit(*s)) {
       n *= 10;
       n += *(s++) - '0';
-      if (isdigit(*s))
+      if (dIsdigit(*s))
          return -1;
    }
    *str = s;
@@ -550,24 +549,24 @@ static bool_t Cookies_get_year(struct tm
    int n;
    const char *s = *str;
 
-   if (isdigit(*s))
+   if (dIsdigit(*s))
       n = *(s++) - '0';
    else
       return FALSE;
-   if (isdigit(*s)) {
+   if (dIsdigit(*s)) {
       n *= 10;
       n += *(s++) - '0';
    } else
       return FALSE;
-   if (isdigit(*s)) {
+   if (dIsdigit(*s)) {
       n *= 10;
       n += *(s++) - '0';
    }
-   if (isdigit(*s)) {
+   if (dIsdigit(*s)) {
       n *= 10;
       n += *(s++) - '0';
    }
-   if (isdigit(*s)) {
+   if (dIsdigit(*s)) {
       /* Sorry, users of prehistoric software in the year 10000! */
       return FALSE;
    }
@@ -936,7 +935,7 @@ static CookieData_t *Cookies_parse(char 
          cookie->domain = value;
       } else if (dStrAsciiCasecmp(attr, "Max-Age") == 0) {
          value = Cookies_parse_value(&str);
-         if (isdigit(*value) || *value == '-') {
+         if (dIsdigit(*value) || *value == '-') {
             long age;
             time_t now = time(NULL);
             struct tm *tm = gmtime(&now);
