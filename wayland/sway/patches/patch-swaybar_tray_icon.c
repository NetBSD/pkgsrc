$NetBSD: patch-swaybar_tray_icon.c,v 1.1 2026/04/14 11:32:15 kikadf Exp $

* Fix ctype usage

--- swaybar/tray/icon.c.orig	2026-02-06 14:22:15.740453549 +0000
+++ swaybar/tray/icon.c
@@ -228,17 +228,17 @@ static struct icon_theme *read_theme_fil
 		++line_no;
 
 		char *line = full_line - 1;
-		while (isspace(*++line)) {} // remove leading whitespace
+		while (isspace((unsigned char)*++line)) {} // remove leading whitespace
 		if (!*line || line[0] == '#') continue; // ignore blank lines & comments
 
 		int len = nread - (line - full_line);
-		while (isspace(line[--len])) {}
+		while (isspace((unsigned char)line[--len])) {}
 		line[++len] = '\0'; // remove trailing whitespace
 
 		if (line[0] == '[') { // group header
 			// check well-formed
 			int i = 1;
-			for (; !iscntrl(line[i]) && line[i] != '[' && line[i] != ']'; ++i) {}
+			for (; !iscntrl((unsigned char)line[i]) && line[i] != '[' && line[i] != ']'; ++i) {}
 			if (i != --len || line[i] != ']') {
 				error = "malformed group header";
 				break;
@@ -268,9 +268,9 @@ static struct icon_theme *read_theme_fil
 
 			// check well-formed
 			int eok = 0;
-			for (; isalnum(line[eok]) || line[eok] == '-'; ++eok) {} // TODO locale?
+			for (; isalnum((unsigned char)line[eok]) || line[eok] == '-'; ++eok) {} // TODO locale?
 			int i = eok - 1;
-			while (isspace(line[++i])) {}
+			while (isspace((unsigned char)line[++i])) {}
 			if (line[i] != '=') {
 				error = "malformed key-value pair";
 				break;
@@ -278,7 +278,7 @@ static struct icon_theme *read_theme_fil
 
 			line[eok] = '\0'; // split into key-value pair
 			char *value = &line[i];
-			while (isspace(*++value)) {}
+			while (isspace((unsigned char)*++value)) {}
 			// TODO unescape value
 
 			error = entry_handler(groups->items[groups->length - 1], line,
