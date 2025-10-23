$NetBSD: patch-src_afterstep_configure.c,v 1.1 2025/10/23 01:28:09 gutteridge Exp $

Use ctype.h correctly.

--- src/afterstep/configure.c.orig	2013-05-01 13:34:11.000000000 +0000
+++ src/afterstep/configure.c
@@ -1989,7 +1989,7 @@ void LoadASConfig (int thisdesktop, ASFl
 				else {
 					char *name = md->name;
 					Bool newline = (count % 10 == 0);
-					if (isdigit (name[0]))
+					if (isdigit ((unsigned char)name[0]))
 						if (md->first != NULL && md->first->fdata->func == F_TITLE)
 							name = md->first->item;
 					display_progress (newline, newline ? "    %s" : "%s", name);
@@ -2151,16 +2151,16 @@ void SetTitleButton (char *tline, FILE *
 	}
 
 	/* going the hard way to prevent buffer overruns */
-	while (isspace (tline[offset]))
+	while (isspace ((unsigned char)tline[offset]))
 		offset++;
-	while (isdigit (tline[offset]))
+	while (isdigit ((unsigned char)tline[offset]))
 		offset++;
-	while (isspace (tline[offset]))
+	while (isspace ((unsigned char)tline[offset]))
 		offset++;
 
 	tline = parse_filename (&(tline[offset]), &(files[0]));
 	offset = 0;
-	while (isspace (tline[offset]))
+	while (isspace ((unsigned char)tline[offset]))
 		++offset;
 	if (tline[offset] != '\0')
 		parse_filename (&(tline[offset]), &(files[1]));
@@ -2445,7 +2445,7 @@ void SetTButtonOrder (char *text, FILE *
 	if (xref && rbtn) {
 		register int i = 0, btn = 0;
 		*rbtn = TITLE_BUTTONS;
-		while (!isspace (text[i]) && text[i] != '\0') {
+		while (!isspace ((unsigned char)text[i]) && text[i] != '\0') {
 			int context = C_NO_CONTEXT;
 			switch (text[i]) {
 			case '0':
@@ -2607,14 +2607,14 @@ void deskback_parse (char *text, FILE * 
 		return;
 	}
 
-	while (isdigit (text[i]))
+	while (isdigit ((unsigned char)text[i]))
 		++i;
-	if (i == 0 || !isspace (text[i])) {
+	if (i == 0 || !isspace ((unsigned char)text[i])) {
 		show_error ("missing desktop number in: \"%s\"", text);
 		return;
 	}
 
-	while (isspace (text[i]))
+	while (isspace ((unsigned char)text[i]))
 		++i;
 	if (text[i] == '#')
 		return;
@@ -2646,7 +2646,7 @@ match_string (struct config *table, char
 	table = find_config (table, text);
 	if (table != NULL) {
 		i = strlen (table->keyword);
-		while (isspace (text[i]))
+		while (isspace ((unsigned char)text[i]))
 			++i;
 		table->action (&(text[i]), fd, table->arg, table->arg2);
 	} else
