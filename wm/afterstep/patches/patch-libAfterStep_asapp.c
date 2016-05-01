$NetBSD: patch-libAfterStep_asapp.c,v 1.1 2016/05/01 19:26:35 dholland Exp $

Use ctype.h correctly.

--- libAfterStep/asapp.c~	2009-10-05 16:32:59.000000000 +0000
+++ libAfterStep/asapp.c
@@ -1208,7 +1208,7 @@ spawn_child( const char *cmd, int single
 
             while( display[i] ) ++i;
 
-            while( i > 0 && isdigit(display[--i]) );
+            while( i > 0 && isdigit((unsigned char)display[--i]) );
             if( display[i] == '.' )
                 display[i+1] = '\0' ;
 /*
@@ -1288,7 +1288,7 @@ spawn_child( const char *cmd, int single
             if( as_app_args.verbosity_level != OUTPUT_DEFAULT_THRESHOLD )
                 ptr += sprintf( ptr, " -V %d", as_app_args.verbosity_level );
 LOCAL_DEBUG_OUT( "len = %d, cmdl = \"%s\" strlen = %d, locale = \"%s\", ptr-cmdl = %d", len, cmdl, (int)strlen(cmdl), as_app_args.locale, (int)(ptr-cmdl) );
-			if( as_app_args.locale && as_app_args.locale[0] && !isspace(as_app_args.locale[0]))
+			if( as_app_args.locale && as_app_args.locale[0] && !isspace((unsigned char)as_app_args.locale[0]))
                 ptr += sprintf( ptr, " -L %s", as_app_args.locale );
 			
 #ifdef DEBUG_TRACE_X
@@ -1314,7 +1314,7 @@ LOCAL_DEBUG_OUT( "len = %d, cmdl = \"%s\
         if( do_fork )
         {
             int i = ptr-cmdl;
-            while( --i >= 0 ) if( !isspace(cmdl[i]) ) break;
+            while( --i >= 0 ) if( !isspace((unsigned char)cmdl[i]) ) break;
             do_fork = ( i < 0 || cmdl[i] != '&' );
         }
 		strcpy (ptr, do_fork?" &\n":"\n");
