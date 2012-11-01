$NetBSD: patch-wmzcalock.c,v 1.2 2012/11/01 19:28:26 joerg Exp $

--- wmzcalock.c.orig	2000-07-11 17:11:00.000000000 +0000
+++ wmzcalock.c
@@ -144,7 +144,7 @@ int use_font_wday = TRUE;
 
 void clock_routine(int, char **);
 void set_locale_vars(void);
-inline void draw_display(void);
+void draw_display(void);
 void set_time_strings (void);
 void draw_string (char *, int, int, unsigned long, int, unsigned long);
 void draw_binary_time (void);
@@ -258,7 +258,9 @@ int main(int argc, char *argv[])
 		{
 			i++; if (i == argc) usage (1);
 			gmt = TRUE;
-			sscanf(argv[i],"%i",&tzoff);
+			int off;
+			sscanf(argv[i],"%i",&off);
+			tzoff = off;
 		}
 
 		else if (!strcmp(argv[i],"-swatch") |
@@ -645,7 +647,7 @@ void set_time_strings (void)
 	{
 		gettimeofday(&timeV, NULL);
 		dday = ((float)hour/24)+((float)min/1440)+
-			((float)sec/86400)+((float)timeV.tv_usec/86400000000);
+			((float)sec/86400);
 	}
 
 	switch (tmmode)
@@ -803,7 +805,7 @@ Pixmap colorized_pixmap_file(char *pixma
 	{
 		fprintf(stderr,
 			"Warning: Couldn't open file '%s', using font instead\n",pixmap_file);
-		(int *)the_pixmap = NULL;
+		the_pixmap = (Pixmap)NULL;
 	}
 	else
 	{
