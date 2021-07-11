$NetBSD: patch-libAfterStep_freestor.c,v 1.2 2021/07/11 12:13:17 bsiegert Exp $

Use ctype.h correctly.

--- libAfterStep/freestor.c.orig	2013-05-01 13:34:11.000000000 +0000
+++ libAfterStep/freestor.c
@@ -465,11 +465,11 @@ void args2FreeStorage (FreeStorageElem *
 		if (!(pelem->term->flags & TF_DONT_SPLIT)) {
 			cur = data;
 			while (*cur) {
-				if (!isspace ((int)*cur))
+				if (!isspace ((unsigned char)*cur))
 					max_argc++;
-				while (!isspace ((int)*cur) && *cur)
+				while (!isspace ((unsigned char)*cur) && *cur)
 					cur++;
-				while (isspace ((int)*cur) && *cur)
+				while (isspace ((unsigned char)*cur) && *cur)
 					cur++;
 			}
 		} else {
@@ -486,7 +486,7 @@ void args2FreeStorage (FreeStorageElem *
 			max_argc--;
 			while (argc < max_argc) {
 				dst = argv[argc];
-				while (!isspace ((int)*cur) && *cur) {
+				while (!isspace ((unsigned char)*cur) && *cur) {
 					if (*cur == '"') {
 						register char *ptr = find_doublequotes (cur);
 
@@ -503,7 +503,7 @@ void args2FreeStorage (FreeStorageElem *
 				if (++argc <= max_argc)
 					argv[argc] = dst;
 
-				while (isspace ((int)*cur) && *cur)
+				while (isspace ((unsigned char)*cur) && *cur)
 					cur++;
 			}
 			if (*cur && argc <= max_argc)
@@ -557,8 +557,8 @@ FunctionData *free_storage2func (FreeSto
 	while (pos < stored->argc && stored->argv[pos]) {
 		register char *cur = stored->argv[pos];
 
-		if (isdigit ((int)*cur)
-				|| ((*cur == '-' || *cur == '+') && isdigit ((int)*(cur + 1))))
+		if (isdigit ((unsigned char)*cur)
+				|| ((*cur == '-' || *cur == '+') && isdigit ((unsigned char)*(cur + 1))))
 			break;
 		pos++;
 	}
@@ -807,13 +807,13 @@ char *parse_context (char *string, int *
 	char tmp1;
 
 	*output = 0;
-	for (ptr = string; isspace (*ptr); ptr++) ;
-	for (; *ptr && !isspace (*ptr); ptr++) {
+	for (ptr = string; isspace ((unsigned char)*ptr); ptr++) ;
+	for (; *ptr && !isspace ((unsigned char)*ptr); ptr++) {
 		/* in some BSD implementations, tolower(c) is not defined
 		 * unless isupper(c) is true */
 		tmp1 = *ptr;
-		if (islower (tmp1))
-			tmp1 = toupper (tmp1);
+		if (islower ((unsigned char)tmp1))
+			tmp1 = toupper ((unsigned char)tmp1);
 		/* end of ugly BSD patch */
 		for (j = 0; table[j].key != 0; j++)
 			if (tmp1 == table[j].key) {
@@ -879,7 +879,7 @@ context2string (char *string, int input,
 			if (input & table[j].value)
 				string[i++] = table[j].key;
 	if (terminate) {
-		while (string[i] != '\0' && !isspace ((int)string[i]))
+		while (string[i] != '\0' && !isspace ((unsigned char)string[i]))
 			i++;
 		string[i] = '\0';
 	} else
@@ -927,11 +927,11 @@ long free_storage2bitlist (FreeStorageEl
 	for (i = *ppos; i < stored->argc; i++) {
 		ptr = stored->argv[i];
 		while (*ptr) {
-			while (*ptr && !isdigit ((int)*ptr))
+			while (*ptr && !isdigit ((unsigned char)*ptr))
 				ptr++;
 			bit_num = 0;
 			valid = False;
-			while (*ptr && isdigit ((int)*ptr)) {
+			while (*ptr && isdigit ((unsigned char)*ptr)) {
 				valid = True;
 				bit_num = bit_num * 10 + ((*ptr) - '0');
 				ptr++;
@@ -1553,7 +1553,7 @@ FreeStorageElem **Path2FreeStorage (Synt
 		register char *ptr;
 
 		for (ptr = path; *ptr; ptr++)
-			if (isspace ((int)*ptr))
+			if (isspace ((unsigned char)*ptr))
 				return QuotedString2FreeStorage (syntax, tail, index, path, id);
 	}
 	if (index)
