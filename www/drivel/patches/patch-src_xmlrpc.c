$NetBSD: patch-src_xmlrpc.c,v 1.1 2015/03/31 15:54:36 joerg Exp $

--- src/xmlrpc.c.orig	2015-03-28 22:45:45.000000000 +0000
+++ src/xmlrpc.c
@@ -41,7 +41,6 @@ parse_parameter_types (va_list *args, xm
 	GTimeVal value_time;
 	
 	g_return_if_fail (node);
-	g_return_if_fail (*args);
 	
 	xml_param = NULL;
 	xml_value = NULL;
