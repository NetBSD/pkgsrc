$NetBSD: patch-src_libical_icalrecur.c,v 1.2 2020/11/07 10:30:20 nia Exp $

[PATCH] Fix build with icu-68.1

https://github.com/libical/libical/commit/a3308a23912bba2db654a8c456165c31888cc897.patch

--- src/libical/icalrecur.c.orig	2020-03-07 14:42:42.000000000 +0000
+++ src/libical/icalrecur.c
@@ -145,6 +145,12 @@
 #if defined(HAVE_LIBICU)
 #include <unicode/ucal.h>
 #include <unicode/ustring.h>
+#if defined(HAVE_STDBOOL_H)
+#include <stdbool.h>
+#else
+#define false 0
+#define true 1
+#endif
 #define RSCALE_IS_SUPPORTED 1
 #else
 #define RSCALE_IS_SUPPORTED 0
@@ -1018,7 +1024,7 @@ icalarray *icalrecurrencetype_rscale_sup
 
     calendars = icalarray_new(sizeof(const char **), 20);
 
-    en = ucal_getKeywordValuesForLocale("calendar", NULL, FALSE, &status);
+    en = ucal_getKeywordValuesForLocale("calendar", NULL, false, &status);
     while ((cal = uenum_next(en, NULL, &status))) {
         cal = icalmemory_tmp_copy(cal);
         icalarray_append(calendars, &cal);
@@ -1411,7 +1417,7 @@ static int initialize_rscale(icalrecur_i
         }
 
         /* Check if specified calendar is supported */
-        en = ucal_getKeywordValuesForLocale("calendar", NULL, FALSE, &status);
+        en = ucal_getKeywordValuesForLocale("calendar", NULL, false, &status);
         while ((cal = uenum_next(en, NULL, &status))) {
             if (!strcmp(cal, rule.rscale)) {
                 is_hebrew = !strcmp(rule.rscale, "hebrew");
