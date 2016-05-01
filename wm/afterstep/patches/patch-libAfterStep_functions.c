$NetBSD: patch-libAfterStep_functions.c,v 1.2 2016/05/01 19:26:35 dholland Exp $

- use ctype.h correctly
- patch up gcc inline mess

--- libAfterStep/functions.c.orig	2009-12-11 22:38:48.000000000 +0000
+++ libAfterStep/functions.c
@@ -52,19 +52,19 @@ txt2func (const char *text, FunctionData
 {
 	TermDef      *fterm;
 
-	for (; isspace (*text); text++);
+	for (; isspace ((unsigned char)*text); text++);
 	fterm = txt2fterm (text, quiet);
 	if (fterm != NULL)
 	{
 		init_func_data (fdata);
 		fdata->func = fterm->id;
-		for (; !isspace (*text) && *text; text++);
-		for (; isspace (*text); text++);
+		for (; !isspace ((unsigned char)*text) && *text; text++);
+		for (; isspace ((unsigned char)*text); text++);
 		if (*text)
 		{
 			const char   *ptr = text + strlen ((char*)text);
 
-			for (; isspace (*(ptr - 1)); ptr--);
+			for (; isspace ((unsigned char)*(ptr - 1)); ptr--);
 			fdata->text = mystrndup (text, ptr - text);
 		}
 	}
@@ -80,7 +80,7 @@ parse_func (const char *text, FunctionDa
 	int           sign = 0;
 
 	init_func_data (data);
-	for (ptr = (char *)text; isspace (*ptr); ptr++);
+	for (ptr = (char *)text; isspace ((unsigned char)*ptr); ptr++);
 	if (*ptr == '\0')
 	{
 		if (!quiet)
@@ -94,7 +94,7 @@ parse_func (const char *text, FunctionDa
 	if (IsInternFunc (fterm->id))
 		return 0;
 
-	while (!isspace (*ptr) && *ptr)
+	while (!isspace ((unsigned char)*ptr) && *ptr)
 		ptr++;
 	data->func = fterm->id;
 	if (fterm->flags & TF_SYNTAX_TERMINATOR)
@@ -109,14 +109,14 @@ parse_func (const char *text, FunctionDa
 	{										   /* we still want to strip trailing whitespaces */
 		char         *tail = ptr + strlen (ptr) - 1;
 
-		for (; isspace (*tail) && tail > ptr; tail--);
+		for (; isspace ((unsigned char)*tail) && tail > ptr; tail--);
 		*(tail + 1) = '\0';
 	}
 	/* this function is very often called so we try to use as little
 	   calls to other function as possible */
 	for (; *ptr; ptr++)
 	{
-		if (!isspace (*ptr))
+		if (!isspace ((unsigned char)*ptr))
 		{
 			int           is_text = 0;
 
@@ -138,15 +138,15 @@ parse_func (const char *text, FunctionDa
 				else if (data->text == NULL)
 					data->text = text;
 				ptr = tail + 1;
-			} else if (isdigit (*ptr))
+			} else if (isdigit ((unsigned char)*ptr))
 			{
 				int           count;
 				char          unit = '\0';
 				int           val = 0;
 
-				for (count = 1; isdigit (*(ptr + count)); count++);
-				if (*(ptr + count) != '\0' && !isspace (*(ptr + count)))
-					is_text = (!isspace (*(ptr + count + 1)) && *(ptr + count + 1) != '\0') ? 1 : 0;
+				for (count = 1; isdigit ((unsigned char)*(ptr + count)); count++);
+				if (*(ptr + count) != '\0' && !isspace ((unsigned char)*(ptr + count)))
+					is_text = (!isspace ((unsigned char)*(ptr + count + 1)) && *(ptr + count + 1) != '\0') ? 1 : 0;
 				if (is_text == 0)
 					ptr = parse_func_args (ptr, &unit, &val) - 1;
 				if (curr_arg < MAX_FUNC_ARGS)
@@ -187,7 +187,7 @@ parse_func (const char *text, FunctionDa
 					}
 					ptr = parse_token (ptr, &(data->text)) - 1;
 				} else
-					while (*(ptr + 1) && !isspace (*(ptr + 1)))
+					while (*(ptr + 1) && !isspace ((unsigned char)*(ptr + 1)))
 						ptr++;
 			}
 			sign = 0;
@@ -314,7 +314,7 @@ dup_func_data (FunctionData * dst, Funct
     }
 }
 
-inline FunctionData *
+FunctionData *
 create_named_function( int func, char *name)
 {
     FunctionData *fdata = safecalloc( 1, sizeof(FunctionData) );
