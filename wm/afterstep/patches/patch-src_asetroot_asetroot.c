$NetBSD: patch-src_asetroot_asetroot.c,v 1.1 2025/10/23 01:28:09 gutteridge Exp $

Use ctype.h correctly.

--- src/asetroot/asetroot.c.orig	2013-05-01 13:34:11.000000000 +0000
+++ src/asetroot/asetroot.c
@@ -270,11 +270,11 @@ main (int argc, char **argv)
       while (*cptr)
 	{
 	  bad_option = 0;
-	  while (isspace (*cptr))
+	  while (isspace ((unsigned char)*cptr))
 	    cptr++;
 	  if (*cptr == '\0')
 	    break;
-	  if (isdigit (*cptr))
+	  if (isdigit ((unsigned char)*cptr))
 	    {
 	      if (curr_desk < 2)
 		{
@@ -316,7 +316,7 @@ main (int argc, char **argv)
 	      fprintf (stderr, "\n%s: unknown option %s!", MyName, cptr);
 	      usage ();
 	    }
-	  while (!isspace (*cptr) && *cptr != '\0')
+	  while (!isspace ((unsigned char)*cptr) && *cptr != '\0')
 	    cptr++;
 	}
     }
