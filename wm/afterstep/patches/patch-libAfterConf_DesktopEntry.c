$NetBSD: patch-libAfterConf_DesktopEntry.c,v 1.3 2021/07/11 12:13:17 bsiegert Exp $

Use ctype.h correctly.

--- libAfterConf/DesktopEntry.c.orig	2013-05-01 13:34:11.000000000 +0000
+++ libAfterConf/DesktopEntry.c
@@ -85,27 +85,27 @@ static char *filter_desktop_entry_exec (
 	char *clean_exec = mystrdup (exec);
 	int start = 0, ts;
 
-	while (clean_exec[start] != '\0' && !isspace (clean_exec[start]))
+	while (clean_exec[start] != '\0' && !isspace ((unsigned char)clean_exec[start]))
 		++start;
 	while (clean_exec[start] != '\0') {
 		ts = start;
-		while (isspace (clean_exec[ts]))
+		while (isspace ((unsigned char)clean_exec[ts]))
 			++ts;
-		if (clean_exec[ts] == '%' && isalpha (clean_exec[ts + 1])) {
-			while (!isspace (clean_exec[ts]) && clean_exec[ts] != '\0') {
+		if (clean_exec[ts] == '%' && isalpha ((unsigned char)clean_exec[ts + 1])) {
+			while (!isspace ((unsigned char)clean_exec[ts]) && clean_exec[ts] != '\0') {
 				clean_exec[ts] = ' ';
 				++ts;
 			}
 			start = ts;
 		} else if (mystrncasecmp (&clean_exec[ts], "-caption ", 9) == 0) {
 			ts += 9;
-			while (isspace (clean_exec[ts]))
+			while (isspace ((unsigned char)clean_exec[ts]))
 				++ts;
 			if (mystrncasecmp (&clean_exec[ts], "\"%c\"", 4) == 0) {
 				ts += 3;
 				while (start < ts)
 					clean_exec[++start] = ' ';
-			} else if (clean_exec[ts] == '%' && isalpha (clean_exec[ts + 1])) {
+			} else if (clean_exec[ts] == '%' && isalpha ((unsigned char)clean_exec[ts + 1])) {
 				ts += 1;
 				while (start < ts)
 					clean_exec[++start] = ' ';
@@ -120,10 +120,10 @@ static char *filter_desktop_entry_exec (
 			++start;
 		} else
 			for (start = ts;
-					 !isspace (clean_exec[start]) && clean_exec[start] != '\0';
+					 !isspace ((unsigned char)clean_exec[start]) && clean_exec[start] != '\0';
 					 ++start) ;
 	}
-	while (isspace (clean_exec[start - 1])) {
+	while (isspace ((unsigned char)clean_exec[start - 1])) {
 		--start;
 		clean_exec[start] = '\0';
 	}
