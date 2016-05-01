$NetBSD: patch-libAfterBase_parse.c,v 1.2 2016/05/01 19:26:35 dholland Exp $

- Use ctype.h correctly.
- Patch up gcc inline mess.

--- libAfterBase/parse.c.orig	2009-02-11 23:32:02.000000000 +0000
+++ libAfterBase/parse.c
@@ -119,7 +119,7 @@ const char *parse_argb_part( const char 
 
 	for( i = 0 ; i < 3 ; ++i )
 	{
-		if( !isdigit(ptr[i]) )
+		if( !isdigit((unsigned char)ptr[i]) )
 			break;
 		buf[i] = ptr[i] ;
 	}
@@ -279,7 +279,7 @@ const char *parse_hsv_part( const char *
 
 	for( i = 0 ; i < 3 ; ++i )
 	{
-		if( !isdigit(ptr[i]) )
+		if( !isdigit((unsigned char)ptr[i]) )
 			break;
 		buf[i] = ptr[i] ;
 	}
@@ -328,7 +328,7 @@ const char *parse_argb_dec( const char *
 
 	for( k = has_alpha?0:1 ; k < 4 ; ++k )
 	{
-		if( !isdigit(ptr[0]) )
+		if( !isdigit((unsigned char)ptr[0]) )
 		{
 			CARD32 tmp_argb = 0xFF000000 ;
 			const char *tmp = parse_argb_color( ptr, &tmp_argb );
@@ -350,14 +350,14 @@ const char *parse_argb_dec( const char *
 		{
 			for( i = 0 ; i < 3 ; ++i )
 			{
-				if( !isdigit(ptr[i]) )
+				if( !isdigit((unsigned char)ptr[i]) )
 					break;
 				buf[i] = ptr[i] ;
 			}
 			buf[i] = '\0' ;
 			dec_val[k] = atoi( &(buf[0]) );
 		}
-		if( !isdigit(ptr[i]) )
+		if( !isdigit((unsigned char)ptr[i]) )
 		{
 			if( ptr[i] != ',' )
 				break;
@@ -394,15 +394,15 @@ const char *parse_argb_color( const char
 			CARD32 argb = 0 ;
 			int len = 0 ;
 			register const char *ptr = color+1 ;
-			while( isxdigit((int)ptr[len]) ) len++;
+			while( isxdigit((unsigned char)ptr[len]) ) len++;
 			if( len >= 3)
 			{
 				if( (len&0x3) == 0 && len != 12 )
 				{  /* we do have alpha channel !!! */
 					len = len>>2 ;
-					argb = (hextoi((int)ptr[0])<<28)&0xF0000000 ;
+					argb = ((unsigned)hextoi((unsigned char)ptr[0])<<28)&0xF0000000 ;
 					if( len > 1 )
-						argb |= (hextoi((int)ptr[1])<<24)&0x0F000000 ;
+						argb |= ((unsigned)hextoi((unsigned char)ptr[1])<<24)&0x0F000000 ;
 					else
 						argb |= 0x0F000000;
 					ptr += len ;
@@ -415,20 +415,20 @@ const char *parse_argb_color( const char
 				if( len == 1 )
 				{
 					argb |= 0x000F0F0F;
-					argb |= (hextoi((int)ptr[0])<<20)&0x00F00000 ;
-					argb |= (hextoi((int)ptr[1])<<12)&0x0000F000 ;
-					argb |= (hextoi((int)ptr[2])<<4 )&0x000000F0 ;
+					argb |= ((unsigned)hextoi((unsigned char)ptr[0])<<20)&0x00F00000 ;
+					argb |= ((unsigned)hextoi((unsigned char)ptr[1])<<12)&0x0000F000 ;
+					argb |= ((unsigned)hextoi((unsigned char)ptr[2])<<4 )&0x000000F0 ;
 					ptr += 3 ;
 				}else
 				{
-					argb |= (hextoi((int)ptr[0])<<20)&0x00F00000 ;
-					argb |= (hextoi((int)ptr[1])<<16)&0x000F0000 ;
+					argb |= ((unsigned)hextoi((unsigned char)ptr[0])<<20)&0x00F00000 ;
+					argb |= ((unsigned)hextoi((unsigned char)ptr[1])<<16)&0x000F0000 ;
 					ptr += len ;
-					argb |= (hextoi((int)ptr[0])<<12)&0x0000F000 ;
-					argb |= (hextoi((int)ptr[1])<<8) &0x00000F00 ;
+					argb |= ((unsigned)hextoi((unsigned char)ptr[0])<<12)&0x0000F000 ;
+					argb |= ((unsigned)hextoi((unsigned char)ptr[1])<<8) &0x00000F00 ;
 					ptr += len ;
-					argb |= (hextoi((int)ptr[0])<<4 )&0x000000F0 ;
-					argb |= (hextoi((int)ptr[1]))    &0x0000000F ;
+					argb |= ((unsigned)hextoi((unsigned char)ptr[0])<<4 )&0x000000F0 ;
+					argb |= ((unsigned)hextoi((unsigned char)ptr[1]))    &0x0000000F ;
 					ptr += len ;
 				}
 				*pargb = argb ;
@@ -486,7 +486,7 @@ const char *parse_argb_color( const char
 			register int i = 0;
 			Bool success = True ;
 
-			while( isalnum((int)ptr[i]) ) ++i;
+			while( isalnum((unsigned char)ptr[i]) ) ++i;
 			if( ptr[i] != '\0' )
 				ptr = mystrndup(&(color[0]), i );
 
@@ -514,7 +514,7 @@ const char *parse_argb_color( const char
 				int orig_i = i ;
 				ptr = (char*)&(color[0]);
 
-				while( isalnum((int)ptr[i]) || ptr[i] == '.' || ptr[i] == '_') ++i;
+				while( isalnum((unsigned char)ptr[i]) || ptr[i] == '.' || ptr[i] == '_') ++i;
 				if( orig_i < i )
 				{
 					if( ptr[i] != '\0' )
@@ -590,8 +590,8 @@ stripcpy (const char *source)
 
 	if( source == NULL ) 
 		return NULL;
-	for (; isspace ((int)*source); source++);
-	for (ptr = source + strlen (source); ptr > source && isspace ((int)*(ptr - 1)); ptr--);
+	for (; isspace ((unsigned char)*source); source++);
+	for (ptr = source + strlen (source); ptr > source && isspace ((unsigned char)*(ptr - 1)); ptr--);
 	return mystrndup (source, ptr - source);
 }
 
@@ -627,7 +627,7 @@ stripcomments2 (char *source, char **com
 	int start = 0, curr = 0 ;
 
 	/* remove comments from the line */
-	while (isspace ((int)source[start])) ++start;
+	while (isspace ((unsigned char)source[start])) ++start;
 	
 	for (curr = start; source[curr]; curr++)
 	{
@@ -645,9 +645,9 @@ stripcomments2 (char *source, char **com
 		{									   /* checking if it is not a hex color code */
 			int           i = curr;
 
-			while(isxdigit ((int)source[++i]));
+			while(isxdigit ((unsigned char)source[++i]));
 
-			if (i-curr < 4 || i-curr > 13 || (source[i] && !isspace ((int)source[i])))
+			if (i-curr < 4 || i-curr > 13 || (source[i] && !isspace ((unsigned char)source[i])))
 			{
 				if( comments ) 
 					*comments = mystrdup( &source[curr+1] );
@@ -657,7 +657,7 @@ stripcomments2 (char *source, char **com
 			curr = i - 1;
 		}
 	}
-	do{ --curr ; }while( curr > start && isspace ((int)source[curr]));
+	do{ --curr ; }while( curr > start && isspace ((unsigned char)source[curr]));
 	source[curr+1] = '\0';
 	return &source[start];
 }
@@ -676,10 +676,10 @@ strip_whitespace (char *str)
 	char         *ptr;
 
 	/* strip trailing whitespace */
-	for (ptr = str + strlen (str); ptr > str && isspace ((int)*(ptr - 1)); ptr--)
+	for (ptr = str + strlen (str); ptr > str && isspace ((unsigned char)*(ptr - 1)); ptr--)
 		*(ptr - 1) = '\0';
 	/* skip leading whitespace */
-	for (ptr = str; isspace ((int)*ptr); ptr++);
+	for (ptr = str; isspace ((unsigned char)*ptr); ptr++);
 	return ptr;
 }
 
@@ -699,7 +699,7 @@ tokenskip( const char *ptr, unsigned int
     if( ptr == NULL ) return NULL ;
     while( ++tok_no <= n_tokens && ptr[curr] != '\0' )
 	{
-		while (!isspace ((int)ptr[curr]) && ptr[curr])
+		while (!isspace ((unsigned char)ptr[curr]) && ptr[curr])
         {   /* we have to match doublequotes if we encounter any, to allow for spaces in filenames */
 			if (ptr[curr] == '"')
 			{
@@ -710,7 +710,7 @@ tokenskip( const char *ptr, unsigned int
 			++curr;
 		}
 
-		while (isspace ((int)ptr[curr])) ++curr;
+		while (isspace ((unsigned char)ptr[curr])) ++curr;
 	}
     return (char*)&ptr[curr];
 }
@@ -725,12 +725,12 @@ parse_token (const char *source, char **
 {
 	int tok_start = 0, tok_end;
 	char *next_tok_ptr ; 
-	while( isspace(source[tok_start]) ) ++tok_start;
+	while( isspace((unsigned char)source[tok_start]) ) ++tok_start;
 	next_tok_ptr = tokenskip( &source[tok_start], 1 );
 	tok_end = (int)(next_tok_ptr-source) ; 
 	if( tok_end > tok_start )
 		if( source[tok_end] != '\0' )  /* then it points to beginning of the next token */ 	
-			do{	--tok_end;}while( tok_end > tok_start && isspace(source[tok_end-1]));
+			do{	--tok_end;}while( tok_end > tok_start && isspace((unsigned char)source[tok_end-1]));
 	
 	if( trg ) 
 		*trg = mystrndup (&source[tok_start], tok_end - tok_start );
@@ -752,7 +752,7 @@ parse_tab_token (const char *source, cha
 {
 	char         *ptr;
 
-	for (; isspace ((int)*source); source++);
+	for (; isspace ((unsigned char)*source); source++);
 	for (ptr = (char *)source; *ptr != '\t' && *ptr; ptr++);
 	*trg = mystrndup (source, ptr - source);
 	return ptr;
@@ -806,7 +806,7 @@ make_shell_str (char *dest, const char *
 	n--;
 	while (n && *src)
 	{
-		if (!isalnum ((int)*src) && n > 1)
+		if (!isalnum ((unsigned char)*src) && n > 1)
 		{
 			*dest++ = '\\';
 			n--;
@@ -853,7 +853,7 @@ parse_signed_int (register char *tline, 
 	int  val = 0, sign = 0;
 	register int i = 0 ;
 
-	while (isspace ((int)tline[i])) ++i;
+	while (isspace ((unsigned char)tline[i])) ++i;
 
 	switch( tline[i] )
 	{ /* handling constructs like --10 or -+10 which is equivalent to -0-10or -0+10 */
@@ -875,7 +875,7 @@ parse_signed_int (register char *tline, 
 		case 'X' :  sign = 4; break;
 	  default : --i ;
 	}
-	while (isdigit ((int)tline[++i]))
+	while (isdigit ((unsigned char)tline[++i]))
 		val = val * 10 + (int)(tline[i] - '0');
 
 	if( val_return )
@@ -891,7 +891,7 @@ parse_func_args (char *tline, char *unit
 	tline = parse_signed_int( tline, func_val, NULL );
 
 	*unit = *tline;
-	if (isspace ((int)*tline))
+	if (isspace ((unsigned char)*tline))
 		*unit = '\0' ;
 	return tline[0]?tline+1:tline;
 }
@@ -906,7 +906,7 @@ double parse_math(const char* str, char*
 	if( str == NULL ) 
 		return 0 ;
 
-	while (isspace((int)*str)) str++;
+	while (isspace((unsigned char)*str)) str++;
 	if( *str == '!' ) 
 	{
 		logical_not = 1;
@@ -919,7 +919,7 @@ double parse_math(const char* str, char*
 
 	while (*str) 
 	{
-		while (isspace((int)*str)) str++;
+		while (isspace((unsigned char)*str)) str++;
 		if (!op) 
 		{
 			if (*str == '+' || *str == '-' || *str == '*' || *str == '/') op = *str++;
@@ -936,7 +936,7 @@ double parse_math(const char* str, char*
 				num = parse_math(str + 1, &ptr, size);
             else if (*str == '$') 
 			{
-            	for (ptr = (char*)str + 1 ; *ptr && !isspace(*ptr) && *ptr != '+' && *ptr != '-' && *ptr != '*' && *ptr != '!' && *ptr != '/' && *ptr != ')' ; ptr++);
+            	for (ptr = (char*)str + 1 ; *ptr && !isspace((unsigned char)*ptr) && *ptr != '+' && *ptr != '-' && *ptr != '*' && *ptr != '!' && *ptr != '/' && *ptr != ')' ; ptr++);
                	num = asxml_var_nget((char*)str + 1, ptr - (str + 1));
             }else 
 				num = strtod(str, &ptr);
@@ -1027,7 +1027,7 @@ parse_geometry (register char *tline,
 
 static char _as_hex_to_char_table[] = "0123456789ABCDEF";
 
-inline int
+int
 unsigned_int2buffer_end (char *buffer, int buffer_size, unsigned int val)
 {
 	int i = buffer_size-1 ; 
@@ -1174,7 +1174,7 @@ get_string_list_item (char *ptr, char **
 
 	if (ptr == NULL)
 		return NULL;
-	while (*ptr && (isspace ((int)*ptr) || *ptr == separator))
+	while (*ptr && (isspace ((unsigned char)*ptr) || *ptr == separator))
 		ptr++;
 	if (*ptr == '\0')
 		return NULL;
@@ -1185,7 +1185,7 @@ get_string_list_item (char *ptr, char **
 		if ((*item_end = find_doublequotes (ptr)) == NULL)
 			return NULL;
 		ptr = *item_end;
-		while (*ptr && !(isspace ((int)*ptr) || *ptr == separator))
+		while (*ptr && !(isspace ((unsigned char)*ptr) || *ptr == separator))
 			ptr++;
 	} else
 	{
