$NetBSD: patch-wmweather.c,v 1.2 2021/07/10 17:13:44 dholland Exp $

Use ctype.h functions correctly.
Use the proper type with time().

--- wmweather.c.orig	2019-02-13 19:54:49.000000000 +0000
+++ wmweather.c
@@ -269,7 +269,7 @@ static void do_conf(const char *rcfile)
 				exit(1);
 			}
 			for (i = 0; i < 4; i++)
-				optarg[i] = toupper(optarg[i]);
+				optarg[i] = toupper((unsigned char)optarg[i]);
 			if (station != NULL)
 				free(station);
 			station = strdup(optarg);
@@ -406,7 +406,7 @@ static void do_opts(int argc, char *argv
 				exit(1);
 			}
 			for (i = 0; i < 4; i++)
-				optarg[i] = toupper(optarg[i]);
+				optarg[i] = toupper((unsigned char)optarg[i]);
 			if (station != NULL)
 				free(station);
 			station = optarg;
@@ -690,11 +690,12 @@ static void update(int force_read)
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
@@ -1129,8 +1130,8 @@ static void update(int force_read)
 
 	} else {
 
-		time(&l);
-		tm = localtime(&l);
+		time(&tl);
+		tm = localtime(&tl);
 		if (gusting) {
 			showwinddir = tm->tm_sec % 30 < 10;
 			showgusting = tm->tm_sec % 30 >= 10 && tm->tm_sec % 30 < 20;
