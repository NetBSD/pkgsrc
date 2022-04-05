$NetBSD: patch-clients_uil_UilSymStor.c,v 1.1 2022/04/05 10:01:06 riastradh Exp $

Fix ctype(3) abuse.

--- clients/uil/UilSymStor.c.orig	2017-08-17 00:38:43.000000000 +0000
+++ clients/uil/UilSymStor.c
@@ -1716,7 +1716,7 @@ output_text(XmConst int length, XmConst 
 
 	for (i=0;  i<last;  i++)
 	{
-	    if (iscntrl( c_buffer[ i ] ))
+	    if (iscntrl( (unsigned char)c_buffer[ i ] ))
 		c_buffer[ i ] = '.';
 	}
 
