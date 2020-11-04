$NetBSD: patch-libgnome-desktop_gnome-languages.c,v 1.1 2020/11/04 12:12:48 nia Exp $

Replace usage of uselocale() - not available on NetBSD

--- libgnome-desktop/gnome-languages.c.orig	2020-10-05 19:11:19.070822700 +0000
+++ libgnome-desktop/gnome-languages.c
@@ -303,16 +303,13 @@ language_name_get_codeset_details (const
                                    gboolean    *is_utf8)
 {
         locale_t locale;
-        locale_t old_locale;
         const char *codeset = NULL;
 
         locale = newlocale (LC_CTYPE_MASK, language_name, (locale_t) 0);
         if (locale == (locale_t) 0)
                 return;
 
-        old_locale = uselocale (locale);
-
-        codeset = nl_langinfo (CODESET);
+        codeset = nl_langinfo_l (CODESET, locale);
 
         if (pcodeset != NULL) {
                 *pcodeset = g_strdup (codeset);
@@ -324,7 +321,6 @@ language_name_get_codeset_details (const
                 *is_utf8 = strcmp (normalized_codeset, "UTF-8") == 0;
         }
 
-        uselocale (old_locale);
         freelocale (locale);
 }
 
@@ -703,14 +699,11 @@ get_translated_language (const char *cod
         name = NULL;
         if (language != NULL) {
                 const char *translated_name;
-                locale_t loc = 0;
-                locale_t old_locale = 0;
+                g_autofree char *old_locale = NULL;		
 
                 if (locale != NULL) {
-                        loc = newlocale (LC_MESSAGES_MASK, locale, (locale_t) 0);
-                        if (loc == (locale_t) 0)
-                                return NULL;
-                        old_locale = uselocale (loc);
+                        old_locale = g_strdup (setlocale (LC_MESSAGES, NULL));
+			setlocale (LC_MESSAGES, locale);
                 }
 
                 if (is_fallback_language (code)) {
@@ -723,8 +716,7 @@ get_translated_language (const char *cod
                 }
 
                 if (locale != NULL) {
-                        uselocale (old_locale);
-                        freelocale (loc);
+                        setlocale (LC_MESSAGES, locale);
                 }
         }
 
@@ -761,15 +753,12 @@ get_translated_territory (const char *co
         name = NULL;
         if (territory != NULL) {
                 const char *translated_territory;
-                locale_t loc;
-                locale_t old_locale = 0;
+                g_autofree char *old_locale = NULL;
                 g_autofree char *tmp = NULL;
 
                 if (locale != NULL) {
-                        loc = newlocale (LC_MESSAGES_MASK, locale, (locale_t) 0);
-                        if (loc == (locale_t) 0)
-                                return NULL;
-                        old_locale = uselocale (loc);
+                        old_locale = g_strdup (setlocale(LC_MESSAGES, NULL));
+                        setlocale(LC_MESSAGES, locale);
                 }
 
                 translated_territory = dgettext ("iso_3166", territory);
@@ -777,8 +766,7 @@ get_translated_territory (const char *co
                 name = capitalize_utf8_string (tmp);
 
                 if (locale != NULL) {
-                        uselocale (old_locale);
-                        freelocale (loc);
+                        setlocale (LC_MESSAGES, old_locale);
                 }
         }
 
@@ -1358,17 +1346,13 @@ gnome_get_translated_modifier (const cha
 {
         char *retval;
         GHashTable *modifiers_map;
-        locale_t loc;
-        locale_t old_locale;
+	g_autofree char *old_locale = NULL;
 
         g_return_val_if_fail (modifier != NULL, NULL);
 
         if (translation != NULL) {
-                loc = newlocale (LC_MESSAGES_MASK, translation, (locale_t) 0);
-                if (loc == (locale_t) 0) {
-                        return NULL;
-                }
-                old_locale = uselocale (loc);
+                old_locale = g_strdup (setlocale (LC_MESSAGES, NULL));
+		setlocale (LC_MESSAGES, translation);
         }
 
         /* Modifiers as listed in glibc's SUPPORTED file:
@@ -1408,8 +1392,7 @@ gnome_get_translated_modifier (const cha
         g_hash_table_destroy (modifiers_map);
 
         if (translation != NULL) {
-                uselocale (old_locale);
-                freelocale (loc);
+                setlocale (LC_MESSAGES, old_locale);
         }
 
         return retval;
