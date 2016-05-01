$NetBSD: patch-libAfterBase_output.c,v 1.1 2016/05/01 19:26:34 dholland Exp $

Fix printing of times.

--- libAfterBase/output.c~	2006-03-29 00:11:15.000000000 +0000
+++ libAfterBase/output.c
@@ -219,9 +219,9 @@ void debugout_print_linestamp(const char
 		last_timestamp = tv.tv_sec ;
 	}
 	if( line > 0 )
-	 	fprintf( stderr, "%s:%2.2li.%5.5li:%s:%s:%d>", ApplicationName, tv.tv_sec-startup_time, tv.tv_usec/10, file, func, line );
+	 	fprintf( stderr, "%s:%2.2lld.%5.5ld:%s:%s:%d>", ApplicationName, (long long)(tv.tv_sec-startup_time), (long)(tv.tv_usec/10), file, func, line );
 	else
-	 	fprintf( stderr, "%s:%2.2li.%5.5li:%s:%s>", ApplicationName, tv.tv_sec-startup_time, tv.tv_usec/10, file, func );
+	 	fprintf( stderr, "%s:%2.2lld.%5.5ld:%s:%s>", ApplicationName, (long long)(tv.tv_sec-startup_time), (long)(tv.tv_usec/10), file, func );
 	
 }
 
