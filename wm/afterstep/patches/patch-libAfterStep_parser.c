$NetBSD: patch-libAfterStep_parser.c,v 1.1 2016/05/01 19:26:35 dholland Exp $

Use ctype.h correctly.

--- libAfterStep/parser.c~	2008-03-28 22:41:23.000000000 +0000
+++ libAfterStep/parser.c
@@ -613,9 +613,9 @@ GetNextStatement (ConfigDef * config)
 			if (*cur == file_terminator)
 				return NULL;
 #ifdef __CYGWIN__
-            if (!isspace ((int)*cur) && *cur != 0x0D)
+            if (!isspace ((unsigned char)*cur) && *cur != 0x0D)
 #else
-            if (!isspace ((int)*cur))
+            if (!isspace ((unsigned char)*cur))
 #endif
 			{
 				register int  i;
@@ -632,7 +632,7 @@ GetNextStatement (ConfigDef * config)
 					{						   /* comments - skip entire line */
 						config->current_flags |= CF_DISABLED_OPTION;
 						/* let's skip few spaces here */
-						while (isspace ((int)cur[i]) && cur[i] != terminator) ++i;
+						while (isspace ((unsigned char)cur[i]) && cur[i] != terminator) ++i;
 						if (cur[i] == '\0' || cur[i] == terminator)
 							break;				   /* not a valid option */
 						cur = &cur[i];
@@ -647,7 +647,7 @@ GetNextStatement (ConfigDef * config)
                     print_trimmed_str(  "private option at", cur );
 					++cur;
 					for( i = 0 ; mname[i] != '\0' && cur[i] != '\0' ; ++i ) 
-						if (tolower (mname[i]) != tolower (cur[i]) )
+						if (tolower ((unsigned char)mname[i]) != tolower ((unsigned char)cur[i]) )
 							break;
 					if (mname[i] != '\0')
 					{						   /* that was a foreign optiion - belongs to the other executable */
@@ -673,9 +673,9 @@ GetNextStatement (ConfigDef * config)
 				if( *cur != COMMENTS_CHAR )
 				{	
                 	i = 0 ;
-                	while (cur[i] && !isspace ((int)cur[i]) && cur[i] != terminator && cur[i] != file_terminator)
+                	while (cur[i] && !isspace ((unsigned char)cur[i]) && cur[i] != terminator && cur[i] != file_terminator)
                     	++i;
-                	while (isspace ((int)cur[i]) && cur[i] != terminator && cur[i] != file_terminator)
+                	while (isspace ((unsigned char)cur[i]) && cur[i] != terminator && cur[i] != file_terminator)
                     	++i;
 				}else
 					i = 1;
@@ -711,7 +711,7 @@ GetNextStatement (ConfigDef * config)
 					{
 						if (config->tdata[i] == file_terminator)
 							set_flags(config->current_flags, CF_LAST_OPTION);
-						if (!isspace ((int)data[i]))
+						if (!isspace ((unsigned char)data[i]))
 							break;
 					}
 					i++;
@@ -750,10 +750,10 @@ FindStatementTerm (char *tline, SyntaxDe
 	if( tline[0] == COMMENTS_CHAR )
 		return &_as_comments_term;
 
-	if( isspace(tline[0]) )
+	if( isspace((unsigned char)tline[0]) )
 	{
 		int i = 0; 
-		while( isspace(tline[i]) ) 	   ++i;
+		while( isspace((unsigned char)tline[i]) ) 	   ++i;
 		if( tline[i] == '~') 
 			if( get_hash_item (syntax->term_hash, AS_HASHABLE(&tline[i]), &hdata.vptr)==ASH_Success  )
 				return hdata.vptr;
@@ -793,7 +793,7 @@ config2tree_storage (ConfigDef * config,
 				{	
 					++i;       /* it's ok - we can start with 1, since myname should have at least 1 char */
 					pterm = FindStatementTerm (&(config->tline[i]), config->syntax);
-				}while( pterm == NULL && !isspace(config->tline[i]) && config->tline[i] != '\0' );
+				}while( pterm == NULL && !isspace((unsigned char)config->tline[i]) && config->tline[i] != '\0' );
 			}else
 				pterm = FindStatementTerm (config->tline, config->syntax);
 
@@ -804,7 +804,7 @@ config2tree_storage (ConfigDef * config,
 			config->current_term = pterm;
 			
 			LOCAL_DEBUG_OUT("Term:[%s]", config->current_term->keyword);
-			if( isspace(config->tline[0]) &&  pterm->keyword_len > 0 &&
+			if( isspace((unsigned char)config->tline[0]) &&  pterm->keyword_len > 0 &&
 				mystrncasecmp(pterm->keyword, config->current_data, pterm->keyword_len) == 0 ) 
 			{              /* we need to skip one token in current_data :  */
 				char *src = tokenskip( config->current_data, 1 ) ;
