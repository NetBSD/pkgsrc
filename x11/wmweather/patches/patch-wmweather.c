$NetBSD: patch-wmweather.c,v 1.1 2016/06/23 18:24:07 dholland Exp $

Use ctype.h functions correctly.

--- wmweather.c~	2009-07-03 16:00:38.000000000 +0000
+++ wmweather.c
@@ -270,7 +270,7 @@ static void do_conf(const char *rcfile)
 				exit(1);
 			}
 			for (i = 0; i < 4; i++)
-				optarg[i] = toupper(optarg[i]);
+				optarg[i] = toupper((unsigned char)optarg[i]);
 			if (station != NULL)
 				free(station);
 			station = strdup(optarg);
@@ -407,7 +407,7 @@ static void do_opts(int argc, char *argv
 				exit(1);
 			}
 			for (i = 0; i < 4; i++)
-				optarg[i] = toupper(optarg[i]);
+				optarg[i] = toupper((unsigned char)optarg[i]);
 			if (station != NULL)
 				free(station);
 			station = optarg;
