$NetBSD: patch-clients_mwm_WmResParse.c,v 1.1 2022/04/05 10:01:06 riastradh Exp $

Fix ctype(3) abuse.

--- clients/mwm/WmResParse.c.orig	2017-08-17 00:38:43.000000000 +0000
+++ clients/mwm/WmResParse.c
@@ -3329,7 +3329,7 @@ static Boolean ParseClientCommand (unsig
 #ifndef NO_MULTIBYTE
 			   mblen ((char *)stream, MB_CUR_MAX) == 1 &&
 #endif
-			   (isalnum(*stream) || *stream == ' ' ||
+			   (isalnum((unsigned char)*stream) || *stream == ' ' ||
 			    *stream == '\t'  || *stream == '_' ))
 		      ++stream;
 		}
@@ -6449,7 +6449,7 @@ static Boolean ParseKeySym (unsigned cha
     if ((*detail = XStringToKeysym(keySymName)) == NoSymbol)
 #endif
     {
-        if (!isdigit (keySymName[0]) ||
+        if (!isdigit ((unsigned char)keySymName[0]) ||
             ((*detail = StrToNum ((unsigned char *)&keySymName[0])) == -1))
         {
             *detail = NoSymbol;
