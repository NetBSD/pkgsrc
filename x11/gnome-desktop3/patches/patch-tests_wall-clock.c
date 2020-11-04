$NetBSD: patch-tests_wall-clock.c,v 1.1 2020/11/04 12:12:48 nia Exp $

Disable tests that rely on uselocale()

--- tests/wall-clock.c.orig	2020-10-05 19:11:19.000000000 +0000
+++ tests/wall-clock.c
@@ -23,6 +23,9 @@
 #include <libgnome-desktop/gnome-wall-clock.h>
 #include <locale.h>
 #include <string.h>
+#ifdef __APPLE__
+#include <xlocale.h>
+#endif
 
 #define COLON ":"
 #define RATIO "∶"
@@ -36,8 +39,7 @@ test_utf8_character (const char *utf8_ch
 {
 	GDateTime  *datetime;
 	GnomeWallClock *clock;
-	locale_t locale;
-	locale_t save_locale;
+	g_autofree char *save_locale;
 	const char *str;
 
 	/* When testing that UTF8 locales don't use double spaces
@@ -47,9 +49,9 @@ test_utf8_character (const char *utf8_ch
 
 	/* In the C locale, make sure the time string is formatted with regular
          * colons */
-	locale = newlocale (LC_ALL_MASK, "C", (locale_t) 0);
-	g_assert_true (locale != (locale_t)0);
-	save_locale = uselocale (locale);
+	save_locale = setlocale (LC_ALL_MASK, NULL);
+	g_assert_true (save_locale != NULL);
+	setlocale (LC_ALL_MASK, "C");
 	clock = gnome_wall_clock_new ();
 	str = gnome_wall_clock_string_for_datetime (clock,
 	                                            datetime,
@@ -60,13 +62,7 @@ test_utf8_character (const char *utf8_ch
 	g_object_unref (clock);
 
 	/* In a UTF8 locale, we want ratio characters and no colons. */
-	locale = newlocale (LC_ALL_MASK, "en_US.utf8", locale);
-	if (locale == (locale_t)0) {
-		g_test_message ("en_US.utf8 locale not found");
-		g_test_fail ();
-		return;
-	}
-	uselocale (locale);
+	setlocale (LC_ALL_MASK, "en_US.utf8");
 	clock = gnome_wall_clock_new ();
 	str = gnome_wall_clock_string_for_datetime (clock,
 	                                            datetime,
@@ -78,13 +74,7 @@ test_utf8_character (const char *utf8_ch
 
 	/* ... and same thing with an RTL locale: should be formatted with
          * ratio characters */
-	locale = newlocale (LC_ALL_MASK, "he_IL.utf8", locale);
-	if (locale == (locale_t)0) {
-		g_test_message ("he_IL.utf8 locale not found");
-		g_test_fail ();
-		return;
-	}
-	uselocale (locale);
+	setlocale (LC_ALL_MASK, "he_IL.utf8");
 	clock = gnome_wall_clock_new ();
 	str = gnome_wall_clock_string_for_datetime (clock,
 	                                            datetime,
@@ -97,8 +87,7 @@ test_utf8_character (const char *utf8_ch
 	g_date_time_unref (datetime);
 
 	/* Restore previous locale */
-	uselocale (save_locale);
-	freelocale (locale);
+	setlocale (LC_ALL_MASK, save_locale);
 }
 
 static void
@@ -197,6 +186,7 @@ test_notify_clock (void)
 	g_object_unref (settings);
 }
 
+#if !defined(__NetBSD__)
 static void
 test_weekday_setting (void)
 {
@@ -248,6 +238,7 @@ test_weekday_setting (void)
 	uselocale (save_locale);
 	freelocale (locale);
 }
+#endif
 
 int
 main (int   argc,
@@ -257,11 +248,15 @@ main (int   argc,
 
 	g_test_init (&argc, &argv, NULL);
 
+#if !defined(__NetBSD__)
 	g_test_add_func ("/wall-clock/colon-vs-ratio", test_colon_vs_ratio);
 	g_test_add_func ("/wall-clock/space-vs-en-space", test_space_vs_en_space);
 	g_test_add_func ("/wall-clock/24h-clock-format", test_clock_format_setting);
+#endif
 	g_test_add_func ("/wall-clock/notify-clock", test_notify_clock);
+#if !defined(__NetBSD__)
 	g_test_add_func ("/wall-clock/weekday-setting", test_weekday_setting);
+#endif
 
 	return g_test_run ();
 }
