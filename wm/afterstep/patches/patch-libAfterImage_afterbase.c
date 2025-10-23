$NetBSD: patch-libAfterImage_afterbase.c,v 1.1 2025/10/23 01:28:08 gutteridge Exp $

Use ctype.h correctly.

--- libAfterImage/afterbase.c.orig	2013-05-01 13:34:11.000000000 +0000
+++ libAfterImage/afterbase.c
@@ -391,7 +391,7 @@ find_envvar (char *var_start, int *end_p
 		name_start++;
 		for (i = 1; var_start[i] && var_start[i] != '}'; i++);
 	} else
-		for (i = 0; isalnum ((int)var_start[i]) || var_start[i] == '_'; i++);
+		for (i = 0; isalnum ((unsigned char)var_start[i]) || var_start[i] == '_'; i++);
 
 	backup = var_start[i];
 	var_start[i] = '\0';
@@ -520,11 +520,11 @@ asim_mystrcasecmp (const char *s1, const
 		/* in some BSD implementations, tolower(c) is not defined
 		 * unless isupper(c) is true */
 		c1 = s1[i];
-		if (isupper (c1))
-			c1 = tolower (c1);
+		if (isupper ((unsigned char)c1))
+			c1 = tolower ((unsigned char)c1);
 		c2 = s2[i];
-		if (isupper (c2))
-			c2 = tolower (c2);
+		if (isupper ((unsigned char)c2))
+			c2 = tolower ((unsigned char)c2);
 
 		++i ;
 		if (c1 != c2)
@@ -547,10 +547,10 @@ asim_mystrncasecmp (const char *s1, cons
 		++i ;
 		if (c1==0)
 			return -c2;
-		if (isupper (c1))
-			c1 = tolower(c1);
-		if (isupper (c2))
-			c2 = tolower(c2);
+		if (isupper ((unsigned char)c1))
+			c1 = tolower((unsigned char)c1);
+		if (isupper ((unsigned char)c2))
+			c2 = tolower((unsigned char)c2);
 		if (c1 != c2)
 			return (c1 - c2);
 	}
@@ -581,7 +581,7 @@ static int FindColor(const char *name, C
 /* from parse,c : */
 const char *asim_parse_argb_color( const char *color, CARD32 *pargb )
 {
-#define hextoi(h)   (isdigit(h)?((h)-'0'):(isupper(h)?((h)-'A'+10):((h)-'a'+10)))
+#define hextoi(h)   (isdigit((unsigned char)h)?((h)-'0'):(isupper((unsigned char)h)?((h)-'A'+10):((h)-'a'+10)))
 	if( color )
 	{
 		if( *color == '#' )
@@ -589,7 +589,7 @@ const char *asim_parse_argb_color( const
 			CARD32 argb = 0 ;
 			int len = 0 ;
 			register const char *ptr = color+1 ;
-			while( isxdigit((int)ptr[len]) ) len++;
+			while( isxdigit((unsigned char)ptr[len]) ) len++;
 			if( len >= 3)
 			{
 				if( (len&0x3) == 0 && len != 12 )
@@ -637,7 +637,7 @@ const char *asim_parse_argb_color( const
 			register const char *ptr = &(color[0]);
             if(!FindColor(color, pargb))
                 return color;
-    		while( !isspace((int)*ptr) && *ptr != '\0' ) ptr++;
+    		while( !isspace((unsigned char)*ptr) && *ptr != '\0' ) ptr++;
 			return ptr;
 #else
 			if( dpy == NULL )
@@ -652,7 +652,7 @@ const char *asim_parse_argb_color( const
 				if( XLookupColor( dpy, DefaultColormap(dpy,DefaultScreen(dpy)), color, &xcol, &xcol_scr) )
 					*pargb = 0xFF000000|((xcol.red<<8)&0x00FF0000)|(xcol.green&0x0000FF00)|((xcol.blue>>8)&0x000000FF);
 #endif
-				while( !isspace((int)*ptr) && *ptr != '\0' ) ptr++;
+				while( !isspace((unsigned char)*ptr) && *ptr != '\0' ) ptr++;
 				return ptr;
 			}
 #endif
@@ -675,7 +675,7 @@ double asim_parse_math(const char* str, 
 	if( str == NULL ) 
 		return 0 ;
 
-	while (isspace((int)*str)) str++;
+	while (isspace((unsigned char)*str)) str++;
 	if( *str == '!' ) 
 	{
 		logical_not = 1;
@@ -688,7 +688,7 @@ double asim_parse_math(const char* str, 
 
 	while (*str) 
 	{
-		while (isspace((int)*str)) str++;
+		while (isspace((unsigned char)*str)) str++;
 		if (!op) 
 		{
 			if (*str == '+' || *str == '-' || *str == '*' || *str == '/') op = *str++;
@@ -705,7 +705,7 @@ double asim_parse_math(const char* str, 
 				num = asim_parse_math(str + 1, &ptr, size);
             else if (*str == '$') 
 			{
-            	for (ptr = (char*)str + 1 ; *ptr && !isspace(*ptr) && *ptr != '+' && *ptr != '-' && *ptr != '*' && *ptr != '!' && *ptr != '/' && *ptr != ')' ; ptr++);
+            	for (ptr = (char*)str + 1 ; *ptr && !isspace((unsigned char)*ptr) && *ptr != '+' && *ptr != '-' && *ptr != '*' && *ptr != '!' && *ptr != '/' && *ptr != ')' ; ptr++);
                	num = asim_asxml_var_nget((char*)str + 1, ptr - (str + 1));
             }else 
 				num = strtod(str, &ptr);
@@ -1064,8 +1064,8 @@ asim_casestring_hash_value (ASHashableVa
 		c = string[i];
 		if (c == '\0')
 			break;
-		if (isupper (c))
-			c = tolower (c);
+		if (isupper ((unsigned char)c))
+			c = tolower ((unsigned char)c);
 		hash_key += (((ASHashKey) c) << i);
 		++i;
 	}while(i < ((sizeof (ASHashKey) - sizeof (char)) << 3));
@@ -1092,10 +1092,10 @@ asim_casestring_compare (ASHashableValue
 
 		u1 = str1[i];
 		u2 = str2[i];
-		if (islower (u1))
-			u1 = toupper (u1);
-		if (islower (u2))
-			u2 = toupper (u2);
+		if (islower ((unsigned char)u1))
+			u1 = toupper ((unsigned char)u1);
+		if (islower ((unsigned char)u2))
+			u2 = toupper ((unsigned char)u2);
 		if (u1 != u2)
 			return (long)u1 - (long)u2;
 	}while( str1[i++] );
@@ -1376,7 +1376,7 @@ asim_asxml_var_cleanup(void)
 static char* lcstring(char* str) 
 {
 	char* ptr = str;
-	for ( ; *ptr ; ptr++) if (isupper((int)*ptr)) *ptr = tolower((int)*ptr);
+	for ( ; *ptr ; ptr++) if (isupper((unsigned char)*ptr)) *ptr = tolower((unsigned char)*ptr);
 	return str;
 }
 
@@ -1442,20 +1442,20 @@ xml_elem_t* asim_xml_parse_parm(const ch
 		const char* eval;
 
 		/* Spin past any leading whitespace. */
-		for (bname = eparm ; isspace((int)*bname) ; bname++);
+		for (bname = eparm ; isspace((unsigned char)*bname) ; bname++);
 
 		/* Check for a parm.  First is the parm name. */
-		for (ename = bname ; xml_tagchar((int)*ename) ; ename++);
+		for (ename = bname ; xml_tagchar(*ename) ; ename++);
 
 		/* No name equals no parm equals broken tag. */
 		if (!*ename) { eparm = NULL; break; }
 
 		/* No "=" equals broken tag.  We do not support HTML-style parms */
 		/* with no value.                                                */
-		for (bval = ename ; isspace((int)*bval) ; bval++);
+		for (bval = ename ; isspace((unsigned char)*bval) ; bval++);
 		if (*bval != '=') { eparm = NULL; break; }
 
-		while (isspace((int)*++bval));
+		while (isspace((unsigned char)*++bval));
 
 		/* If the next character is a quote, spin until we see another one. */
 		if (*bval == '"' || *bval == '\'') {
@@ -1463,10 +1463,10 @@ xml_elem_t* asim_xml_parse_parm(const ch
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
@@ -1550,9 +1550,9 @@ int asim_xml_parse(const char* str, xml_
 		{
 			const char* etag;
 			/* Find the end of the tag. */
-			for (etag = oab + 2 ; xml_tagchar((int)*etag) ; etag++);
+			for (etag = oab + 2 ; xml_tagchar(*etag) ; etag++);
 
-			while (isspace((int)*etag)) ++etag;
+			while (isspace((unsigned char)*etag)) ++etag;
 			/* If this is an end tag, and the tag matches the tag we're parsing, */
 			/* we're done.  If not, continue on blindly. */
 			if (*etag == '>') 
@@ -1582,13 +1582,13 @@ int asim_xml_parse(const char* str, xml_
 			const char* eparm;
 
 			/* Find the end of the tag. */
-			for (etag = btag ; xml_tagchar((int)*etag) ; etag++);
+			for (etag = btag ; xml_tagchar(*etag) ; etag++);
 
 			/* If we reached the end of the document, continue on. */
 			if (!*etag) { ptr = oab + 1; continue; }
 
 			/* Find the beginning of the parameters, if they exist. */
-			for (bparm = etag ; isspace((int)*bparm) ; bparm++);
+			for (bparm = etag ; isspace((unsigned char)*bparm) ; bparm++);
 
 			/* From here on, we're looking for a sequence of parms, which have
 			 * the form [a-z0-9-]+=("[^"]"|'[^']'|[^ \t\n]), followed by either
@@ -1597,23 +1597,23 @@ int asim_xml_parse(const char* str, xml_
 				const char* tmp;
 
 				/* Spin past any leading whitespace. */
-				for ( ; isspace((int)*eparm) ; eparm++);
+				for ( ; isspace((unsigned char)*eparm) ; eparm++);
 
 				/* Are we at the end of the tag? */
 				if (*eparm == '>' || (*eparm == '/' && eparm[1] == '>')) break;
 
 				/* Check for a parm.  First is the parm name. */
-				for (tmp = eparm ; xml_tagchar((int)*tmp) ; tmp++);
+				for (tmp = eparm ; xml_tagchar(*tmp) ; tmp++);
 
 				/* No name equals no parm equals broken tag. */
 				if (!*tmp) { eparm = NULL; break; }
 
 				/* No "=" equals broken tag.  We do not support HTML-style parms
 				   with no value. */
-				for ( ; isspace((int)*tmp) ; tmp++);
+				for ( ; isspace((unsigned char)*tmp) ; tmp++);
 				if (*tmp != '=') { eparm = NULL; break; }
 
-				do { ++tmp; } while (isspace((int)*tmp));
+				do { ++tmp; } while (isspace((unsigned char)*tmp));
 
 				/* If the next character is a quote, spin until we see another one. */
 				if (*tmp == '"' || *tmp == '\'') {
@@ -1622,7 +1622,7 @@ int asim_xml_parse(const char* str, xml_
 				}
 
 				/* Now look for a space or the end of the tag. */
-				for ( ; *tmp && !isspace((int)*tmp) && *tmp != '>' && !(*tmp == '/' && tmp[1] == '>') ; tmp++);
+				for ( ; *tmp && !isspace((unsigned char)*tmp) && *tmp != '>' && !(*tmp == '/' && tmp[1] == '>') ; tmp++);
 
 				/* If we reach the end of the string, there cannot be a '>'. */
 				if (!*tmp) { eparm = NULL; break; }
@@ -1630,8 +1630,8 @@ int asim_xml_parse(const char* str, xml_
 				/* End of the parm.  */
 				eparm = tmp;
 				
-				if (!isspace((int)*tmp)) break; 
-				for ( ; isspace((int)*tmp) ; tmp++);
+				if (!isspace((unsigned char)*tmp)) break; 
+				for ( ; isspace((unsigned char)*tmp) ; tmp++);
 				if( *tmp == '>' || (*tmp == '/' && tmp[1] == '>') )
 					break;
 			}
@@ -1648,7 +1648,7 @@ int asim_xml_parse(const char* str, xml_
 			}
 
 			/* We found a tag!  Advance the pointer. */
-			for (ptr = eparm ; isspace((int)*ptr) ; ptr++);
+			for (ptr = eparm ; isspace((unsigned char)*ptr) ; ptr++);
 			empty = (*ptr == '/');
 			ptr += empty + 1;
 
@@ -1825,7 +1825,7 @@ asim_spool_xml_tag( ASXmlBuffer *xb, cha
 	if( !xb->verbatim && !xb->quoted && 
 		(xb->state != ASXML_Start || xb->level == 0 )) 
 	{	/* skip spaces if we are not in string */
-		while( i < len && isspace( (int)tmp[i] )) ++i;
+		while( i < len && isspace( (unsigned char)tmp[i] )) ++i;
 		if( i >= len ) 
 			return i;
 	}
@@ -1862,10 +1862,10 @@ asim_spool_xml_tag( ASXmlBuffer *xb, cha
 			add_xml_buffer_chars( xb, "/", 1 );
 			if( ++i >= len ) 
 				return i;
-		}else if( isalnum((int)tmp[i]) )	
+		}else if( isalnum((unsigned char)tmp[i]) )
 		{	 
-			xb->state = ASXML_TagName; 		   
-			xb->verbatim = True ; 		   
+			xb->state = ASXML_TagName;
+			xb->verbatim = True ;
 		}else
 			xb->state = ASXML_BadTagName ;
 	}
@@ -1874,12 +1874,12 @@ asim_spool_xml_tag( ASXmlBuffer *xb, cha
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
+			if( isspace( (unsigned char)tmp[i] ) || tmp[i] == '>' ) 
 			{
 				xb->state = ASXML_TagAttrOrClose;
 				xb->verbatim = False ; 
@@ -1921,7 +1921,7 @@ asim_spool_xml_tag( ASXmlBuffer *xb, cha
 					}else
 						--(xb->level);			
 				}		 			   
-			}else if( !isalnum( (int)tmp[i] ) )	  
+			}else if( !isalnum( (unsigned char)tmp[i] ) )	  
 				xb->state = ASXML_BadAttrName ;
 			else
 			{	
@@ -1937,12 +1937,12 @@ asim_spool_xml_tag( ASXmlBuffer *xb, cha
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
+			if( isspace( (unsigned char)tmp[i] ) || tmp[i] == '=' ) 
 			{
 				xb->state = ASXML_AttrEq;
 				xb->verbatim = False ; 
@@ -1980,7 +1980,7 @@ asim_spool_xml_tag( ASXmlBuffer *xb, cha
 	
 	if( xb->state == ASXML_AttrValue )  /* looking for attribute value : */
 	{
-		if( !xb->quoted && isspace((int)tmp[i]) ) 
+		if( !xb->quoted && isspace((unsigned char)tmp[i]) ) 
 		{
 			add_xml_buffer_chars( xb, " ", 1 );
 			++i ;
