$NetBSD: patch-clients_mwm_WmMenu.c,v 1.1 2022/04/05 10:01:06 riastradh Exp $

Fix ctype(3) abuse.

--- clients/mwm/WmMenu.c.orig	2017-08-17 00:38:43.000000000 +0000
+++ clients/mwm/WmMenu.c
@@ -933,8 +933,8 @@ static MenuItem *PerformClientCommandMat
 	/* Skip past the '<' at the beginning of the next segment and
 	   any whitespace. */
 	++menuItemCommand; ++clientCommand;
-	while (isspace(*menuItemCommand)) ++menuItemCommand;
-	while (isspace(*clientCommand)) ++clientCommand;
+	while (isspace((unsigned char)*menuItemCommand)) ++menuItemCommand;
+	while (isspace((unsigned char)*clientCommand)) ++clientCommand;
 	
 	/* First check whether the current menuItemCommand segment is
 	   a wildcard. */
@@ -946,7 +946,7 @@ static MenuItem *PerformClientCommandMat
 	       the client command. */
 	    wildcardPositions[wildcards++] = segments;
 	    ++menuItemCommand;
-	    while (isspace(*menuItemCommand)) ++menuItemCommand;
+	    while (isspace((unsigned char)*menuItemCommand)) ++menuItemCommand;
 	    while (*clientCommand != '>' && *clientCommand != '\0')
 	      ++clientCommand;
 	    foundWildcard = TRUE;
@@ -967,7 +967,7 @@ static MenuItem *PerformClientCommandMat
 	    /* Get rid of trailing white space on the segment. */
 	    for (; seglength > 0; --seglength)
 	    {
-		if (!isspace(menuItemCommand[seglength - 1]))
+		if (!isspace((unsigned char)menuItemCommand[seglength - 1]))
 		  break;
 	    }
 	    
@@ -980,14 +980,14 @@ static MenuItem *PerformClientCommandMat
 		   have anything but whitespace after its seglength
 		   character. */
 		clientCommand += seglength;
-		while (isspace(*clientCommand)) ++clientCommand;
+		while (isspace((unsigned char)*clientCommand)) ++clientCommand;
 		if (*clientCommand != '>') return(bestMatchSoFar);
 		
 		/* We have a match. Clear the foundWildcard since we
 		   have sync'ed up and keep trying to match. */
 		foundWildcard = FALSE;
 		menuItemCommand += seglength;
-		while (isspace(*menuItemCommand)) ++menuItemCommand;
+		while (isspace((unsigned char)*menuItemCommand)) ++menuItemCommand;
 	    }
 	    else if (foundWildcard == FALSE)
 	    {
@@ -1056,7 +1056,7 @@ static MenuItem *PerformClientCommandMat
 	/* Skip past the '<' at the beginning of the next segment and
 	   any whitespace. */
 	++bestMatchStr;
-	while (isspace(*bestMatchStr)) ++bestMatchStr;
+	while (isspace((unsigned char)*bestMatchStr)) ++bestMatchStr;
 	
 	/* First check whether the current bestMatchStr segment is
 	   a wildcard. @RGC: We are assuming that there is nothing
