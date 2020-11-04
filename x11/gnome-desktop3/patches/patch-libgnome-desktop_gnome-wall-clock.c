$NetBSD: patch-libgnome-desktop_gnome-wall-clock.c,v 1.1 2020/11/04 12:12:48 nia Exp $

Replace usage of uselocale() - not available on NetBSD

--- libgnome-desktop/gnome-wall-clock.c.orig	2020-04-29 01:53:29.076934000 +0000
+++ libgnome-desktop/gnome-wall-clock.c
@@ -279,22 +279,19 @@ translate_time_format_string (const char
   const char *locale = g_getenv ("LC_TIME");
   const char *res;
   char *sep;
-  locale_t old_loc;
-  locale_t loc = (locale_t)0;
+  g_autofree char *old_locale = NULL;
 
-  if (locale)
-    loc = newlocale (LC_MESSAGES_MASK, locale, (locale_t)0);
-
-  old_loc = uselocale (loc);
+  if (locale) {
+    old_locale = g_strdup (setlocale (LC_MESSAGES, NULL));
+    setlocale (LC_MESSAGES, locale);
+  }
 
   sep = strchr (str, '\004');
   res = g_dpgettext (GETTEXT_PACKAGE, str, sep ? sep - str + 1 : 0);
 
-  uselocale (old_loc);
-
-  if (loc != (locale_t)0)
-    freelocale (loc);
-
+  if (locale)
+    setlocale (LC_MESSAGES, old_locale);
+  
   return res;
 }
 
