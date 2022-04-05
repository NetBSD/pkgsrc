$NetBSD: patch-clients_mwm_WmXSMP.c,v 1.1 2022/04/05 10:01:06 riastradh Exp $

Fix ctype(3) abuse.

--- clients/mwm/WmXSMP.c.orig	2017-08-17 00:38:43.000000000 +0000
+++ clients/mwm/WmXSMP.c
@@ -381,7 +381,7 @@ setClientDBName(void)
 
 	for (p1 = ++ptr; *p1 != '\0'; p1++)
 	{
-	    if (!isdigit(*p1))
+	    if (!isdigit((unsigned char)*p1))
 		break;
 	}
 
