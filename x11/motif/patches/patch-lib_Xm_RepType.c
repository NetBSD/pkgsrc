$NetBSD: patch-lib_Xm_RepType.c,v 1.1 2022/04/05 09:59:56 riastradh Exp $

Fix ctype(3) abuse.

--- lib/Xm/RepType.c.orig	2017-08-17 00:38:43.000000000 +0000
+++ lib/Xm/RepType.c
@@ -1197,8 +1197,8 @@ CopyStringArray(
 		TmpStr[Index][1] = 'm' ;
 		i = 2 ;
 		while (TmpStr[Index][i]) {
-		    if (islower(TmpStr[Index][i]))
-			TmpStr[Index][i] = toupper(TmpStr[Index][i]);
+		    if (islower((unsigned char)TmpStr[Index][i]))
+			TmpStr[Index][i] = toupper((unsigned char)TmpStr[Index][i]);
 		    i++;
 		}
 		++Index ;
@@ -1762,8 +1762,8 @@ _XmConvertActionParamToRepTypeId(Widget 
     if (can_be_numeric)
     {
 	value = i = 0;
-	while (isspace(parameter[i])) ++i; /* skip leading white space */
-	if (isdigit(parameter[i]))
+	while (isspace((unsigned char)parameter[i])) ++i; /* skip leading white space */
+	if (isdigit((unsigned char)parameter[i]))
 	{
 	    value = atoi(parameter + i);
 	    /* If the number was converted, verify that it is a valid value
