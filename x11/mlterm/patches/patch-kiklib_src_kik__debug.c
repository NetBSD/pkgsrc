$NetBSD: patch-kiklib_src_kik__debug.c,v 1.1 2014/03/26 16:47:39 tsutsui Exp $

Pull post-3.3.4 bug fixes patch:
http://sourceforge.net/projects/mlterm/files/01release/mlterm-3.3.4/mlterm-3.3.4-fixes.patch/download
 - fix build error with gcc-4.8.x

--- kiklib/src/kik_debug.c.orig	2014-03-22 22:06:35.000000000 +0000
+++ kiklib/src/kik_debug.c
@@ -160,16 +160,38 @@ kik_error_printf(
 	)
 {
 	va_list  arg_list ;
+	char *  prefix ;
+	int  ret ;
 
 	va_start( arg_list , format) ;
 
 #ifdef  HAVE_ERRNO_H
-	debug_printf( "ERROR(" , strerror( errno) , NULL) ;
+	if( errno != 0)
+	{
+		char *  error ;
+
+		error = strerror( errno) ;
+
+		if( ! ( prefix = alloca( 6 + strlen( error) + 3 + 1)))
+		{
+			ret = 0 ;
+			goto  end ;
+		}
 
-	return  debug_printf( "): " , format , arg_list) ;
-#else
-	return  debug_printf( "ERROR: " , format , arg_list) ;
+		sprintf( prefix , "ERROR(%s): " , error) ;
+	}
+	else
 #endif
+	{
+		prefix = "ERROR: " ;
+	}
+
+	ret = debug_printf( prefix , format , arg_list) ;
+
+end:
+	va_end( arg_list) ;
+
+	return  ret ;
 }
 
 /*
