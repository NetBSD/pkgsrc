$NetBSD: patch-lib_Xm_ResConvert.c,v 1.1 2022/04/05 09:59:56 riastradh Exp $

Fix ctype(3) abuse.

--- lib/Xm/ResConvert.c.orig	2017-08-17 00:38:43.000000000 +0000
+++ lib/Xm/ResConvert.c
@@ -1519,14 +1519,14 @@ CvtStringToCardinalList(
 			(crd_array_size,sizeof(Cardinal));
     while (*p != '\0')
 	{
-	while ((isspace(*p) || ispunct(*p)) && *p != '\0') /* Skip blanks */
+	while ((isspace((unsigned char)*p) || ispunct((unsigned char)*p)) && *p != '\0') /* Skip blanks */
 	    p++;
 	if (*p == '\0')				/* end-of data */
 	    break;
-	if (isdigit(*p))
+	if (isdigit((unsigned char)*p))
 	    {
 	    new_element = atoi(p);		/* Grab number */
-	    while (isdigit(*p))		/* advance pointer past number */
+	    while (isdigit((unsigned char)*p))		/* advance pointer past number */
 		p++;
 	    if (crd_array_size == crd_array_count)
 		{
