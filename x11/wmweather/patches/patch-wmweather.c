$NetBSD: patch-wmweather.c,v 1.3 2025/12/20 15:54:13 nia Exp $

Include <strings.h> for rindex(3).
Use ctype.h functions correctly.
Use the proper type with time().

--- wmweather.c.orig	2019-02-13 19:54:49.000000000 +0000
+++ wmweather.c
@@ -25,6 +25,7 @@
 #include <signal.h>
 #include <stdlib.h>
 #include <string.h>
+#include <strings.h>
 #include <sys/stat.h>
 #include <sys/wait.h>
 #include <unistd.h>
@@ -269,7 +270,7 @@ static void do_conf(const char *rcfile)
 				exit(1);
 			}
 			for (i = 0; i < 4; i++)
-				optarg[i] = toupper(optarg[i]);
+				optarg[i] = toupper((unsigned char)optarg[i]);
 			if (station != NULL)
 				free(station);
 			station = strdup(optarg);
@@ -406,7 +407,7 @@ static void do_opts(int argc, char *argv[])
 				exit(1);
 			}
 			for (i = 0; i < 4; i++)
-				optarg[i] = toupper(optarg[i]);
+				optarg[i] = toupper((unsigned char)optarg[i]);
 			if (station != NULL)
 				free(station);
 			station = optarg;
@@ -690,11 +691,12 @@ static void update(int force_read)
 	char   buffer[MAX_STRING], *i;
 	int    line, n, q, sgn;
 	long   l = 0;
+	time_t tl;
 
-	time(&l);
-	tm = gmtime(&l);
+	time(&tl);
+	tm = gmtime(&tl);
 	utc_diff = tm->tm_hour;
-	tm = localtime(&l);
+	tm = localtime(&tl);
 	utc_diff = (tm->tm_hour - utc_diff + 24) % 24 * 3600;
 
 	if (stat(report, &rst) < 0 && errno != ENOENT) {
@@ -1129,8 +1131,8 @@ static void update(int force_read)
 
 	} else {
 
-		time(&l);
-		tm = localtime(&l);
+		time(&tl);
+		tm = localtime(&tl);
 		if (gusting) {
 			showwinddir = tm->tm_sec % 30 < 10;
 			showgusting = tm->tm_sec % 30 >= 10 && tm->tm_sec % 30 < 20;
