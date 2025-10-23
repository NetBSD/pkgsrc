$NetBSD: patch-src_ASDocGen_ASDocGen.c,v 1.1 2025/10/23 01:28:08 gutteridge Exp $

Use ctype.h correctly.

--- src/ASDocGen/ASDocGen.c.orig	2013-05-01 13:34:11.000000000 +0000
+++ src/ASDocGen/ASDocGen.c
@@ -616,7 +616,7 @@ check_syntax_source( const char *source_
 					sub_syntax = pFuncSyntax ;
 				if (sub_syntax)
 					check_syntax_source( source_dir, sub_syntax, False );
-				if( isalnum( syntax->terms[i].keyword[0] ) )					
+				if( isalnum( (unsigned char)syntax->terms[i].keyword[0] ) )					
 					check_option_source( syntax_dir, syntax->terms[i].keyword, sub_syntax, module?syntax->doc_path:NULL ) ;
 			}
 		}
@@ -676,7 +676,7 @@ write_options_keywords(const char *sourc
 
 		if (sub_syntax)
 			gen_syntax_doc( source_dir, state->dest_dir, sub_syntax, state->doc_type );
-		if( isalnum( sorted_list[i]->keyword[0] ) )					
+		if( isalnum( (unsigned char)sorted_list[i]->keyword[0] ) )					
 			convert_xml_file( syntax_dir, sorted_list[i]->keyword, state );
 	}
 	free( sorted_list );
@@ -1008,7 +1008,7 @@ gen_index( const char *dest_dir, const c
 	  					sublist = True ;
 					}
 					item_text += sublist_name_len ;
-					while( *item_text != '\0' && isspace( *item_text ) ) 
+					while( *item_text != '\0' && isspace( (unsigned char)*item_text ) ) 
 						++item_text ;
 				}else if( sublist ) 
 				{	
