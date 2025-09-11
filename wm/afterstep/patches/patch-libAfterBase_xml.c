$NetBSD: patch-libAfterBase_xml.c,v 1.1 2025/09/11 21:35:01 gutteridge Exp $

Use ctype.h correctly.

--- libAfterBase/xml.c.orig	2013-05-01 13:34:11.000000000 +0000
+++ libAfterBase/xml.c
@@ -57,7 +57,7 @@ void asxml_var_insert(const char* name, 
 static char* lcstring(char* str) 
 {
 	char* ptr = str;
-	for ( ; *ptr ; ptr++) if (isupper((int)*ptr)) *ptr = tolower((int)*ptr);
+	for ( ; *ptr ; ptr++) if (isupper((unsigned char)*ptr)) *ptr = tolower((unsigned char)*ptr);
 	return str;
 }
 
@@ -157,7 +157,7 @@ xml_elem_t* xml_parse_parm(const char* p
 		const char* eval;
 
 		/* Spin past any leading whitespace. */
-		for (bname = eparm ; isspace((int)*bname) ; bname++);
+		for (bname = eparm ; isspace((unsigned char)*bname) ; bname++);
 
 		/* Check for a parm.  First is the parm name. */
 		for (ename = bname ; xml_tagchar((int)*ename) ; ename++);
@@ -167,10 +167,10 @@ xml_elem_t* xml_parse_parm(const char* p
 
 		/* No "=" equals broken tag.  We do not support HTML-style parms */
 		/* with no value.                                                */
-		for (bval = ename ; isspace((int)*bval) ; bval++);
+		for (bval = ename ; isspace((unsigned char)*bval) ; bval++);
 		if (*bval != '=') { eparm = NULL; break; }
 
-		while (isspace((int)*++bval));
+		while (isspace((unsigned char)*++bval));
 
 		/* If the next character is a quote, spin until we see another one. */
 		if (*bval == '"' || *bval == '\'') {
@@ -178,10 +178,10 @@ xml_elem_t* xml_parse_parm(const char* p
 			bval++;
 			for (eval = bval ; *eval && *eval != quote ; eval++);
 		} else {
-			for (eval = bval ; *eval && !isspace((int)*eval) ; eval++);
+			for (eval = bval ; *eval && !isspace((unsigned char)*eval) ; eval++);
 		}
 
-		for (eparm = eval ; *eparm && !isspace((int)*eparm) ; eparm++);
+		for (eparm = eval ; *eparm && !isspace((unsigned char)*eparm) ; eparm++);
 
 		/* Add the parm to our list. */
 		p = xml_elem_new();
@@ -217,7 +217,7 @@ static Bool xml_print_r(xml_elem_t* root
 	
 	if (root->tag_id == XML_CDATA_ID || !strcmp(root->tag, cdata_str)) {
 		char* ptr = root->parm;
-		while (isspace((int)*ptr)) ptr++;
+		while (isspace((unsigned char)*ptr)) ptr++;
 		fprintf(stderr, "%s", ptr);
 	} else {
 		if( root->child != NULL || root->next != NULL  ) 
@@ -352,7 +352,7 @@ int xml_parse(const char* str, xml_elem_
 			/* Find the end of the tag. */
 			for (etag = oab + 2 ; xml_tagchar((int)*etag) ; etag++);
 
-			while (isspace((int)*etag)) ++etag;
+			while (isspace((unsigned char)*etag)) ++etag;
 			/* If this is an end tag, and the tag matches the tag we're parsing, */
 			/* we're done.  If not, continue on blindly. */
 			if (*etag == '>') 
@@ -390,7 +390,7 @@ int xml_parse(const char* str, xml_elem_
 			if (!*etag) { ptr = oab + 1; continue; }
 
 			/* Find the beginning of the parameters, if they exist. */
-			for (bparm = etag ; isspace((int)*bparm) ; bparm++);
+			for (bparm = etag ; isspace((unsigned char)*bparm) ; bparm++);
 
 			/* From here on, we're looking for a sequence of parms, which have
 			 * the form [a-z0-9-]+=("[^"]"|'[^']'|[^ \t\n]), followed by either
@@ -399,7 +399,7 @@ int xml_parse(const char* str, xml_elem_
 				const char* tmp;
 
 				/* Spin past any leading whitespace. */
-				for ( ; isspace((int)*eparm) ; eparm++);
+				for ( ; isspace((unsigned char)*eparm) ; eparm++);
 
 				/* Are we at the end of the tag? */
 				if (*eparm == '>' || (*eparm == '/' && eparm[1] == '>')) break;
@@ -412,10 +412,10 @@ int xml_parse(const char* str, xml_elem_
 
 				/* No "=" equals broken tag.  We do not support HTML-style parms
 				   with no value. */
-				for ( ; isspace((int)*tmp) ; tmp++);
+				for ( ; isspace((unsigned char)*tmp) ; tmp++);
 				if (*tmp != '=') { eparm = NULL; break; }
 
-				do { ++tmp; } while (isspace((int)*tmp));
+				do { ++tmp; } while (isspace((unsigned char)*tmp));
 
 				/* If the next character is a quote, spin until we see another one. */
 				if (*tmp == '"' || *tmp == '\'') {
@@ -424,7 +424,7 @@ int xml_parse(const char* str, xml_elem_
 				}
 
 				/* Now look for a space or the end of the tag. */
-				for ( ; *tmp && !isspace((int)*tmp) && *tmp != '>' && !(*tmp == '/' && tmp[1] == '>') ; tmp++);
+				for ( ; *tmp && !isspace((unsigned char)*tmp) && *tmp != '>' && !(*tmp == '/' && tmp[1] == '>') ; tmp++);
 
 				/* If we reach the end of the string, there cannot be a '>'. */
 				if (!*tmp) { eparm = NULL; break; }
@@ -432,8 +432,8 @@ int xml_parse(const char* str, xml_elem_
 				/* End of the parm.  */
 				eparm = tmp;
 				
-				if (!isspace((int)*tmp)) break; 
-				for ( ; isspace((int)*tmp) ; tmp++);
+				if (!isspace((unsigned char)*tmp)) break; 
+				for ( ; isspace((unsigned char)*tmp) ; tmp++);
 				if( *tmp == '>' || (*tmp == '/' && tmp[1] == '>') )
 					break;
 			}
@@ -452,7 +452,7 @@ int xml_parse(const char* str, xml_elem_
 			}
 
 			/* We found a tag!  Advance the pointer. */
-			for (ptr = eparm ; isspace((int)*ptr) ; ptr++);
+			for (ptr = eparm ; isspace((unsigned char)*ptr) ; ptr++);
 			empty = (*ptr == '/');
 			ptr += empty + 1;
 
@@ -652,7 +652,7 @@ spool_xml_tag( ASXmlBuffer *xb, char *tm
 	if( !xb->verbatim && !xb->quoted && 
 		(xb->state != ASXML_Start || xb->level == 0 )) 
 	{	/* skip spaces if we are not in string */
-		while( i < len && isspace( (int)tmp[i] )) ++i;
+		while( i < len && isspace((unsigned char)tmp[i] )) ++i;
 		if( i >= len ) 
 			return i;
 	}
@@ -689,7 +689,7 @@ spool_xml_tag( ASXmlBuffer *xb, char *tm
 			add_xml_buffer_chars( xb, "/", 1 );
 			if( ++i >= len ) 
 				return i;
-		}else if( isalnum((int)tmp[i]) )	
+		}else if( isalnum((unsigned char)tmp[i]) )	
 		{	 
 			xb->state = ASXML_TagName; 		   
 			xb->verbatim = True ; 		   
@@ -701,12 +701,12 @@ spool_xml_tag( ASXmlBuffer *xb, char *tm
 	{     /* we are looking for the tag name */
 		int start = i ;
 		/* need to store attribute name in form : ' attr_name' */
-		while( i < len && isalnum((int)tmp[i]) ) ++i ;
+		while( i < len && isalnum((unsigned char)tmp[i]) ) ++i ;
 		if( i > start ) 
 			add_xml_buffer_chars( xb, &tmp[start], i - start );
 		if( i < len ) 
 		{	
-			if( isspace( (int)tmp[i] ) || tmp[i] == '>' ) 
+			if( isspace((unsigned char)tmp[i] ) || tmp[i] == '>' ) 
 			{
 				xb->state = ASXML_TagAttrOrClose;
 				xb->verbatim = False ; 
@@ -748,7 +748,7 @@ spool_xml_tag( ASXmlBuffer *xb, char *tm
 					}else
 						--(xb->level);			
 				}		 			   
-			}else if( !isalnum( (int)tmp[i] ) )	  
+			}else if( !isalnum((unsigned char)tmp[i] ) )	  
 				xb->state = ASXML_BadAttrName ;
 			else
 			{	
@@ -764,12 +764,12 @@ spool_xml_tag( ASXmlBuffer *xb, char *tm
 	{	
 		int start = i ;
 		/* need to store attribute name in form : ' attr_name' */
-		while( i < len && isalnum((int)tmp[i]) ) ++i ;
+		while( i < len && isalnum((unsigned char)tmp[i]) ) ++i ;
 		if( i > start ) 
 			add_xml_buffer_chars( xb, &tmp[start], i - start );
 		if( i < len ) 
 		{	
-			if( isspace( (int)tmp[i] ) || tmp[i] == '=' ) 
+			if( isspace((unsigned char)tmp[i] ) || tmp[i] == '=' ) 
 			{
 				xb->state = ASXML_AttrEq;
 				xb->verbatim = False ; 
@@ -807,7 +807,7 @@ spool_xml_tag( ASXmlBuffer *xb, char *tm
 	
 	if( xb->state == ASXML_AttrValue )  /* looking for attribute value : */
 	{
-		if( !xb->quoted && isspace((int)tmp[i]) ) 
+		if( !xb->quoted && isspace((unsigned char)tmp[i]) ) 
 		{
 			add_xml_buffer_chars( xb, " ", 1 );
 			++i ;
