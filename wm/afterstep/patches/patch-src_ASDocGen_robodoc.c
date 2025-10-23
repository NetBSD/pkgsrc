$NetBSD: patch-src_ASDocGen_robodoc.c,v 1.1 2025/10/23 01:28:08 gutteridge Exp $

Use ctype.h correctly.

--- src/ASDocGen/robodoc.c.orig	2013-05-01 13:34:11.000000000 +0000
+++ src/ASDocGen/robodoc.c
@@ -58,7 +58,7 @@ find_robodoc_section( ASRobodocState *ro
 			int count = 0 ;
 			const char *ptr = &(robo_state->source[++(robo_state->curr)]) ;
 
-			while(ptr[count] == '*' || (count == 4 && isalpha(ptr[count])))
+			while(ptr[count] == '*' || (count == 4 && isalpha((unsigned char)ptr[count])))
 				++count ;
 			if( count >= 6 && (ptr[count] == ' ' || get_flags(robo_state->flags, ASRS_InsideSection)))
 				return ; 				       /* we found it ! */
@@ -179,12 +179,12 @@ robodoc_section_header2xml( ASRobodocSta
 	
 	while( ptr[i] != 0 && ptr[i] != '\n' ) ++i ;
 	robo_state->curr += i+1 ;
-	while( i > 0 && isspace(ptr[i])) --i ;
+	while( i > 0 && isspace((unsigned char)ptr[i])) --i ;
 	if( i > 6 ) 
 	{	
 		id_length = i ;
 		i = 6 ; 
-		while( i < id_length && isspace(ptr[i]) ) ++i; 	
+		while( i < id_length && isspace((unsigned char)ptr[i]) ) ++i; 	
 		if( i < id_length ) 
 		{
 			id = (char*)(&ptr[i]);
@@ -229,7 +229,7 @@ handle_varlist_line( ASRobodocState *rob
 	xml_elem_t* varlist_tag = NULL;		
 	xml_elem_t* tmp ;
 	const char *ptr = &(robo_state->source[robo_state->curr]);
-	Bool is_term = !isspace(ptr[0]);
+	Bool is_term = !isspace((unsigned char)ptr[0]);
 
 	*skipped = 0 ;
 
@@ -299,7 +299,7 @@ handle_formalpara_line( ASRobodocState *
 	xml_elem_t* fp_tag = NULL;		
 	xml_elem_t* tmp ;
 	const char *ptr = &(robo_state->source[robo_state->curr]);
-	Bool is_term = !isspace(ptr[0]);
+	Bool is_term = !isspace((unsigned char)ptr[0]);
 
 	*skipped = 0 ;
 
@@ -419,8 +419,8 @@ handle_robodoc_subtitle( ASRobodocState 
 	int robodoc_id = -1 ;
 
 	LOCAL_DEBUG_OUT("robo_state> curr = %d, len = %d", robo_state->curr, robo_state->len );
-	while( isspace(ptr[i]) && i < len ) ++i ;
-	while( isspace(ptr[len]) && i < len ) --len ;
+	while( isspace((unsigned char)ptr[i]) && i < len ) ++i ;
+	while( isspace((unsigned char)ptr[len]) && i < len ) --len ;
 	++len ;
 	LOCAL_DEBUG_OUT("i = %d, len = %d", i, len );
 	ptr = &(ptr[i]);
