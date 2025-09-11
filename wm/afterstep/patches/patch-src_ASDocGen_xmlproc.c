$NetBSD: patch-src_ASDocGen_xmlproc.c,v 1.1 2025/09/11 21:35:01 gutteridge Exp $

Use ctype.h correctly.

--- src/ASDocGen/xmlproc.c.orig	2013-05-01 13:34:11.000000000 +0000
+++ src/ASDocGen/xmlproc.c
@@ -111,7 +111,7 @@ write_doc_cdata( const char *cdata, int 
 		Bool special = False ;
 		for( i = 0 ; i < len ; ++i ) 
 		{
-			if( (!isalnum(cdata[i]) && cdata[i] != '_'  && cdata[i] != '(' && cdata[i] != ')') || special )
+			if( (!isalnum((unsigned char)cdata[i]) && cdata[i] != '_'  && cdata[i] != '(' && cdata[i] != ')') || special )
 			{
 				if( token_start < i )
 				{	
@@ -243,7 +243,7 @@ convert_xml_tag( xml_elem_t *doc, xml_el
 					--len ;
 				/* we want to skip as much whitespace as possible in NROFF */
 				for( i = 0 ; i < len ; ++i ) 
-					if( !isspace(data_ptr[i]) )
+					if( !isspace((unsigned char)data_ptr[i]) )
 						break;
 				if( i == len ) 
 					len = 0 ;
@@ -253,9 +253,9 @@ convert_xml_tag( xml_elem_t *doc, xml_el
 					Bool written = 0 ;
 					for( i = 0 ; i < len ; ++i ) 
 					{
-						while( isspace(data_ptr[i]) && i < len ) ++i ;
+						while( isspace((unsigned char)data_ptr[i]) && i < len ) ++i ;
 						from = i ; 
-						while( !isspace(data_ptr[i]) && i < len ) ++i ;
+						while( !isspace((unsigned char)data_ptr[i]) && i < len ) ++i ;
 						to = i ; 
 						if( to > from  ) 
 						{	
@@ -501,12 +501,12 @@ add_glossary_item( xml_elem_t* doc, ASXM
 	LOCAL_DEBUG_OUT( "term_text = \"%s\"", term_text );
 	while(*term_text)
 	{	
-		if( isalnum(*term_text) )
+		if( isalnum((unsigned char)*term_text) )
 			break;
 		++term_text ;
 	}
 	i = 0 ;
-	while( isalnum(term_text[i]) ) ++i ;
+	while( isalnum((unsigned char)term_text[i]) ) ++i ;
 	term_text[i] = '\0' ;
 
 	if( term_text[0] != '\0' ) /* need to add glossary term */
