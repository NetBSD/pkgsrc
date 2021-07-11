$NetBSD: patch-libAfterStep_functions.c,v 1.3 2021/07/11 12:13:17 bsiegert Exp $

- use ctype.h correctly
- patch up gcc inline mess

--- libAfterStep/functions.c.orig	2013-05-01 13:34:11.000000000 +0000
+++ libAfterStep/functions.c
@@ -63,7 +63,7 @@ int txt2func_code (const char *text)
 {
 	TermDef *fterm;
 
-	for (; isspace (*text); text++) ;
+	for (; isspace ((unsigned char)*text); text++) ;
 	fterm = txt2fterm (text, True);
 	return (fterm != NULL) ? fterm->id : F_FUNCTIONS_NUM;
 }
@@ -72,17 +72,17 @@ int txt2func (const char *text, Function
 {
 	TermDef *fterm;
 
-	for (; isspace (*text); text++) ;
+	for (; isspace ((unsigned char)*text); text++) ;
 	fterm = txt2fterm (text, quiet);
 	if (fterm != NULL) {
 		init_func_data (fdata);
 		fdata->func = fterm->id;
-		for (; !isspace (*text) && *text; text++) ;
-		for (; isspace (*text); text++) ;
+		for (; !isspace ((unsigned char)*text) && *text; text++) ;
+		for (; isspace ((unsigned char)*text); text++) ;
 		if (*text) {
 			const char *ptr = text + strlen ((char *)text);
 
-			for (; isspace (*(ptr - 1)); ptr--) ;
+			for (; isspace ((unsigned char)*(ptr - 1)); ptr--) ;
 			fdata->text = mystrndup (text, ptr - text);
 		}
 	}
@@ -97,7 +97,7 @@ int parse_func (const char *text, Functi
 	int sign = 0;
 
 	init_func_data (data);
-	for (ptr = (char *)text; isspace (*ptr); ptr++) ;
+	for (ptr = (char *)text; isspace ((unsigned char)*ptr); ptr++) ;
 	if (*ptr == '\0') {
 		if (!quiet)
 			show_error ("empty function specification encountered.%s");
@@ -110,7 +110,7 @@ int parse_func (const char *text, Functi
 	if (IsInternFunc (fterm->id))
 		return 0;
 
-	while (!isspace (*ptr) && *ptr)
+	while (!isspace ((unsigned char)*ptr) && *ptr)
 		ptr++;
 	data->func = fterm->id;
 	if (fterm->flags & TF_SYNTAX_TERMINATOR)
@@ -124,13 +124,13 @@ int parse_func (const char *text, Functi
 	else {												/* we still want to strip trailing whitespaces */
 		char *tail = ptr + strlen (ptr) - 1;
 
-		for (; isspace (*tail) && tail > ptr; tail--) ;
+		for (; isspace ((unsigned char)*tail) && tail > ptr; tail--) ;
 		*(tail + 1) = '\0';
 	}
 	/* this function is very often called so we try to use as little
 	   calls to other function as possible */
 	for (; *ptr; ptr++) {
-		if (!isspace (*ptr)) {
+		if (!isspace ((unsigned char)*ptr)) {
 			int is_text = 0;
 
 			if (*ptr == '"') {
@@ -149,13 +149,13 @@ int parse_func (const char *text, Functi
 				else if (data->text == NULL)
 					data->text = text;
 				ptr = tail + 1;
-			} else if (isdigit (*ptr)) {
+			} else if (isdigit ((unsigned char)*ptr)) {
 				int count;
 				char unit = '\0';
 				int val = 0;
 
-				for (count = 1; isdigit (*(ptr + count)); count++) ;
-				if (*(ptr + count) != '\0' && !isspace (*(ptr + count)))
+				for (count = 1; isdigit ((unsigned char)*(ptr + count)); count++) ;
+				if (*(ptr + count) != '\0' && !isspace ((unsigned char)*(ptr + count)))
 					is_text = (!isspace (*(ptr + count + 1))
 										 && *(ptr + count + 1) != '\0') ? 1 : 0;
 				if (is_text == 0)
@@ -190,7 +190,7 @@ int parse_func (const char *text, Functi
 					}
 					ptr = parse_token (ptr, &(data->text)) - 1;
 				} else
-					while (*(ptr + 1) && !isspace (*(ptr + 1)))
+					while (*(ptr + 1) && !isspace ((unsigned char)*(ptr + 1)))
 						ptr++;
 			}
 			sign = 0;
@@ -307,7 +307,7 @@ void dup_func_data (FunctionData * dst, 
 	}
 }
 
-inline FunctionData *create_named_function (int func, char *name)
+FunctionData *create_named_function (int func, char *name)
 {
 	FunctionData *fdata = safecalloc (1, sizeof (FunctionData));
 
