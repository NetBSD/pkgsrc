$NetBSD: patch-Library_src_HTRDF.c,v 1.1 2026/06/14 12:57:43 nia Exp $

Use correct format argument. XML_GetCurrentLineNumber
returns a long int.

--- Library/src/HTRDF.c.orig	2026-06-14 12:54:01.392916670 +0000
+++ Library/src/HTRDF.c
@@ -2701,7 +2701,7 @@ PUBLIC BOOL HTRDF_parseFile (const char *file_name, 
         else
             buff_len = strlen (buff);
         if (! XML_Parse(xmlparser, buff, buff_len, done)) {
-            fprintf (stderr, "Parse error at line %d:\n%s\n",
+            fprintf (stderr, "Parse error at line %ld:\n%s\n",
                      XML_GetCurrentLineNumber(xmlparser),
                      XML_ErrorString(XML_GetErrorCode(xmlparser)));
             HT_FREE(uri);
@@ -2779,7 +2779,7 @@ PUBLIC BOOL HTRDF_parseBuffer (const char *buffer, con
         return NO;
 
     if (! XML_Parse(xmlparser, buffer, buffer_len, 1)) {
-        fprintf(stderr, "Parse error at line %d:\n%s\n",
+        fprintf(stderr, "Parse error at line %ld:\n%s\n",
                 XML_GetCurrentLineNumber(xmlparser),
                 XML_ErrorString(XML_GetErrorCode(xmlparser)));
         HT_FREE(uri);
