$NetBSD: patch-src_DisplayList.c,v 1.1 2022/04/04 12:42:19 riastradh Exp $

Fix ctype(3) abuse.

--- src/DisplayList.c.orig	2021-03-27 17:40:21.000000000 +0000
+++ src/DisplayList.c
@@ -1941,7 +1941,7 @@ _Xaw_Xlib_ArgsInitProc(String proc_name,
     case EXPOSURES:
       if (*num_params == 1)
 	{
-	  if (isdigit(params[0][0]) || params[0][0] == '+' || params[0][0] == '-')
+	  if (isdigit((unsigned char)params[0][0]) || params[0][0] == '+' || params[0][0] == '-')
 	    retval = (void *)read_int((char *)params[0], NULL);
 	  else if (XmuCompareISOLatin1(params[0], "true") == 0 ||
 	    XmuCompareISOLatin1(params[0], "on") == 0)
