$NetBSD: patch-libAfterStep_freestor.c,v 1.1 2016/05/01 19:26:35 dholland Exp $

Use ctype.h correctly.

--- libAfterStep/freestor.c~	2008-06-13 16:32:51.000000000 +0000
+++ libAfterStep/freestor.c
@@ -478,11 +478,11 @@ args2FreeStorage (FreeStorageElem * pele
 			cur = data;
 			while (*cur)
 			{
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
 		} else
@@ -501,7 +501,7 @@ args2FreeStorage (FreeStorageElem * pele
 			while (argc < max_argc)
 			{
 				dst = argv[argc];
-				while (!isspace ((int)*cur) && *cur)
+				while (!isspace ((unsigned char)*cur) && *cur)
 				{
 					if (*cur == '"')
 					{
@@ -520,7 +520,7 @@ args2FreeStorage (FreeStorageElem * pele
 				if (++argc <= max_argc)
 					argv[argc] = dst;
 
-				while (isspace ((int)*cur) && *cur)
+				while (isspace ((unsigned char)*cur) && *cur)
 					cur++;
 			}
 			if (*cur && argc <= max_argc)
@@ -576,7 +576,7 @@ LOCAL_DEBUG_OUT("argv=%p, arc=%d, sub=%p
 	{
 		register char *cur = stored->argv[pos];
 
-		if (isdigit ((int)*cur) || ((*cur == '-' || *cur == '+') && isdigit ((int)*(cur + 1))))
+		if (isdigit ((unsigned char)*cur) || ((*cur == '-' || *cur == '+') && isdigit ((unsigned char)*(cur + 1))))
 			break;
 		pos++;
 	}
@@ -833,14 +833,14 @@ parse_context (char *string, int *output
 	char          tmp1;
 
 	*output = 0;
-	for (ptr = string; isspace (*ptr); ptr++);
-	for (; *ptr && !isspace (*ptr); ptr++)
+	for (ptr = string; isspace ((unsigned char)*ptr); ptr++);
+	for (; *ptr && !isspace ((unsigned char)*ptr); ptr++)
 	{
 		/* in some BSD implementations, tolower(c) is not defined
 		 * unless isupper(c) is true */
 		tmp1 = *ptr;
-        if (islower (tmp1))
-            tmp1 = toupper (tmp1);
+        if (islower ((unsigned char)tmp1))
+            tmp1 = toupper ((unsigned char)tmp1);
 		/* end of ugly BSD patch */
 		for (j = 0; table[j].key != 0; j++)
 			if (tmp1 == table[j].key)
@@ -904,7 +904,7 @@ context2string (char *string, int input,
                 string[i++] = table[j].key ;
 	if( terminate )
     {
-        while ( string[i] != '\0' && !isspace((int)string[i])) i++;
+        while ( string[i] != '\0' && !isspace((unsigned char)string[i])) i++;
 	    string[i] = '\0' ;
     }else
 	    string[j] = '\0' ;
@@ -955,10 +955,10 @@ free_storage2bitlist (FreeStorageElem * 
         ptr = stored->argv[i] ;
         while ( *ptr )
         {
-            while( *ptr && !isdigit((int)*ptr)) ptr++ ;
+            while( *ptr && !isdigit((unsigned char)*ptr)) ptr++ ;
             bit_num = 0 ;
             valid = False ;
-            while( *ptr && isdigit((int)*ptr))
+            while( *ptr && isdigit((unsigned char)*ptr))
             {
                 valid = True ;
                 bit_num = bit_num*10+((*ptr)-'0');
@@ -1539,7 +1539,7 @@ Path2FreeStorage (SyntaxDef * syntax, Fr
 		register char *ptr;
 
 		for (ptr = path; *ptr; ptr++)
-			if (isspace ((int)*ptr))
+			if (isspace ((unsigned char)*ptr))
 				return QuotedString2FreeStorage (syntax, tail, index, path, id);
 	}
 	if (index)
