$NetBSD: patch-liblilxml_base64.c,v 1.1 2026/06/28 00:51:59 gdt Exp $

Fix ctype(3) UB.  Cherry-picked from https://github.com/XEphem/XEphem/pull/126

--- liblilxml/base64.c.orig	2024-02-13 14:35:36.000000000 +0000
+++ liblilxml/base64.c
@@ -108,7 +108,7 @@ from64tobits(char *out, const char *in)
                 ++len;
             }
         }
-	while (isspace(*in))
+	while (isspace((unsigned char)*in))
 	    in++;
     } while (*in && digit4 != '=');
 
