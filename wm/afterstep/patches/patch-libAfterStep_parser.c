$NetBSD: patch-libAfterStep_parser.c,v 1.2 2021/07/11 12:13:17 bsiegert Exp $

Use ctype.h correctly.

--- libAfterStep/parser.c.orig	2013-05-01 13:34:11.000000000 +0000
+++ libAfterStep/parser.c
@@ -602,9 +602,9 @@ char *GetNextStatement (ConfigDef * conf
 			if (*cur == file_terminator)
 				return NULL;
 #ifdef __CYGWIN__
-			if (!isspace ((int)*cur) && *cur != 0x0D)
+			if (!isspace ((unsigned char)*cur) && *cur != 0x0D)
 #else
-			if (!isspace ((int)*cur))
+			if (!isspace ((unsigned char)*cur))
 #endif
 			{
 				register int i;
@@ -619,7 +619,7 @@ char *GetNextStatement (ConfigDef * conf
 					if (i == DISABLED_KEYWORD_SIZE) {	/* comments - skip entire line */
 						config->current_flags |= CF_DISABLED_OPTION;
 						/* let's skip few spaces here */
-						while (isspace ((int)cur[i]) && cur[i] != terminator)
+						while (isspace ((unsigned char)cur[i]) && cur[i] != terminator)
 							++i;
 						if (cur[i] == '\0' || cur[i] == terminator)
 							break;						/* not a valid option */
@@ -634,7 +634,7 @@ char *GetNextStatement (ConfigDef * conf
 					print_trimmed_str ("private option at", cur);
 					++cur;
 					for (i = 0; mname[i] != '\0' && cur[i] != '\0'; ++i)
-						if (tolower (mname[i]) != tolower (cur[i]))
+						if (tolower ((unsigned char)mname[i]) != tolower ((unsigned char)cur[i]))
 							break;
 					if (mname[i] != '\0') {	/* that was a foreign optiion - belongs to the other executable */
 						if (get_flags (config->flags, CP_IgnoreForeign))
@@ -657,10 +657,10 @@ char *GetNextStatement (ConfigDef * conf
 				   config->current_data and set current_data_len ; (unless its a comment) */
 				if (*cur != COMMENTS_CHAR) {
 					i = 0;
-					while (cur[i] && !isspace ((int)cur[i]) && cur[i] != terminator
+					while (cur[i] && !isspace ((unsigned char)cur[i]) && cur[i] != terminator
 								 && cur[i] != file_terminator)
 						++i;
-					while (isspace ((int)cur[i]) && cur[i] != terminator
+					while (isspace ((unsigned char)cur[i]) && cur[i] != terminator
 								 && cur[i] != file_terminator)
 						++i;
 				} else
@@ -697,7 +697,7 @@ char *GetNextStatement (ConfigDef * conf
 					while (--i >= 0) {
 						if (config->tdata[i] == file_terminator)
 							set_flags (config->current_flags, CF_LAST_OPTION);
-						if (!isspace ((int)data[i]))
+						if (!isspace ((unsigned char)data[i]))
 							break;
 					}
 					i++;
@@ -741,10 +741,10 @@ TermDef *FindStatementTerm (char *tline,
 	if (tline[0] == COMMENTS_CHAR)
 		return &_as_comments_term;
 
-	if (isspace (tline[0])) {
+	if (isspace ((unsigned char)tline[0])) {
 		int i = 0;
 
-		while (isspace (tline[i]))
+		while (isspace ((unsigned char)tline[i]))
 			++i;
 		if (tline[i] == '~')
 			if (get_hash_item
@@ -786,7 +786,7 @@ int config2tree_storage (ConfigDef * con
 					++i;									/* it's ok - we can start with 1, since myname should have at least 1 char */
 					pterm = FindStatementTerm (&(config->tline[i]), config->syntax);
 				}
-				while (pterm == NULL && !isspace (config->tline[i])
+				while (pterm == NULL && !isspace ((unsigned char)config->tline[i])
 							 && config->tline[i] != '\0');
 			} else
 				pterm = FindStatementTerm (config->tline, config->syntax);
@@ -798,7 +798,7 @@ int config2tree_storage (ConfigDef * con
 			config->current_term = pterm;
 
 			LOCAL_DEBUG_OUT ("Term:[%s]", config->current_term->keyword);
-			if (isspace (config->tline[0]) && pterm->keyword_len > 0 && mystrncasecmp (pterm->keyword, config->current_data, pterm->keyword_len) == 0) {	/* we need to skip one token in current_data :  */
+			if (isspace ((unsigned char)config->tline[0]) && pterm->keyword_len > 0 && mystrncasecmp (pterm->keyword, config->current_data, pterm->keyword_len) == 0) {	/* we need to skip one token in current_data :  */
 				char *src = tokenskip (config->current_data, 1);
 				char *dst = config->current_data;
 
