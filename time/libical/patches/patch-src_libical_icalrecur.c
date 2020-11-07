$NetBSD: patch-src_libical_icalrecur.c,v 1.1 2020/11/07 09:06:32 mef Exp $

Adhoc fix:  FALSE is not defined

/tmp/time/libical/work/libical-3.0.8/src/libical/icalrecur.c:1021:59: error: 'FALSE' undeclared (first use in this function); did you mean 'FILE'?
     en = ucal_getKeywordValuesForLocale("calendar", NULL, FALSE, &status);
                                                           ^~~~~
                                                           FILE
/tmp/time/libical/work/libical-3.0.8/src/libical/icalrecur.c:1021:59: note: each undeclared identifier is reported only once for each function it appears in

--- src/libical/icalrecur.c.orig	2020-03-07 14:42:42.000000000 +0000
+++ src/libical/icalrecur.c
@@ -127,6 +127,9 @@
   end_of_data to 1x. This signals next_month to increment the month.
 
  ======================================================================*/
+#ifndef FALSE
+#define FALSE (0)
+#endif
 
 #ifdef HAVE_CONFIG_H
 #include <config.h>
