$NetBSD: patch-libAfterConf_DesktopEntry.c,v 1.2 2016/05/01 19:30:58 dholland Exp $

Use ctype.h correctly.

--- libAfterConf/DesktopEntry.c~	2007-07-13 17:18:26.000000000 +0000
+++ libAfterConf/DesktopEntry.c
@@ -88,14 +88,14 @@ filter_desktop_entry_exec( const char *e
 	char *clean_exec = mystrdup(exec); 	
 	int start = 0, ts;
 
-	while( clean_exec[start] != '\0' && !isspace(clean_exec[start]) ) ++start;
+	while( clean_exec[start] != '\0' && !isspace((unsigned char)clean_exec[start]) ) ++start;
 	while( clean_exec[start] != '\0')
 	{
 		ts = start ; 	  
-		while( isspace(clean_exec[ts]) ) ++ts;
-		if( clean_exec[ts] == '%' && isalpha(clean_exec[ts+1]) ) 
+		while( isspace((unsigned char)clean_exec[ts]) ) ++ts;
+		if( clean_exec[ts] == '%' && isalpha((unsigned char)clean_exec[ts+1]) ) 
 		{	
-			while( !isspace(clean_exec[ts]) && clean_exec[ts] != '\0' ) 
+			while( !isspace((unsigned char)clean_exec[ts]) && clean_exec[ts] != '\0' ) 
 			{
 				clean_exec[ts] = ' ' ;
 				++ts ;
@@ -104,12 +104,12 @@ filter_desktop_entry_exec( const char *e
 		}else if( mystrncasecmp(&clean_exec[ts], "-caption ", 9 ) == 0 )
 		{
 			ts += 9 ;
-			while( isspace(clean_exec[ts]) ) ++ts;
+			while( isspace((unsigned char)clean_exec[ts]) ) ++ts;
 			if( mystrncasecmp(&clean_exec[ts], "\"%c\"", 4 ) == 0 )
 			{
 				ts += 3 ;	
 				while( start < ts ) clean_exec[++start] = ' ';
-			}else if( clean_exec[ts] == '%' && isalpha(clean_exec[ts+1]) )
+			}else if( clean_exec[ts] == '%' && isalpha((unsigned char)clean_exec[ts+1]) )
 			{
 				ts += 1 ;	
 				while( start < ts ) clean_exec[++start] = ' ';
@@ -123,9 +123,9 @@ filter_desktop_entry_exec( const char *e
 				start = ts ;	
 			++start;
 		}else
-			for( start = ts ; !isspace(clean_exec[start]) && clean_exec[start] != '\0'	; ++start );
+			for( start = ts ; !isspace((unsigned char)clean_exec[start]) && clean_exec[start] != '\0'	; ++start );
 	}
-	while( isspace(clean_exec[start-1]))
+	while( isspace((unsigned char)clean_exec[start-1]))
 	{
 		--start ;	
 		clean_exec[start] = '\0' ;
