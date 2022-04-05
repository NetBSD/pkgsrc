$NetBSD: patch-lib_Xm_Picture.c,v 1.1 2022/04/05 09:59:56 riastradh Exp $

Fix ctype(3) abuse.

--- lib/Xm/Picture.c.orig	2016-03-16 02:14:09.000000000 +0000
+++ lib/Xm/Picture.c
@@ -245,15 +245,15 @@ XmPictureDoAutoFill(XmPictureState state
 
 	if(fill.c == '\0')
 	    fill.reject = True;
-	if(fill.digit && (isdigit(fill.c) == 0))
+	if(fill.digit && (isdigit((unsigned char)fill.c) == 0))
 	    fill.reject = True;
-	if(fill.hexdigit && (isxdigit(fill.c) == 0))
+	if(fill.hexdigit && (isxdigit((unsigned char)fill.c) == 0))
 	    fill.reject = True;
 	if(fill.octaldigit && (fill.c < '0' || fill.c > '7'))
 	    fill.reject = True;
-	if(fill.letter && (isalpha(fill.c) == 0))
+	if(fill.letter && (isalpha((unsigned char)fill.c) == 0))
 	    fill.reject = True;
-	if(fill.upcase && islower(fill.c))
+	if(fill.upcase && islower((unsigned char)fill.c))
 	    fill.reject = True;
 
 	if(fill.reject) return state->current_string;
@@ -582,12 +582,12 @@ _XmPictureFollowTransitions(XmPictureSta
 		accepted = False;
 	    break;
 	case NumericDigit:
-	    if(isdigit(inc)) {
+	    if(isdigit((unsigned char)inc)) {
 		found = True;
 	    }
 	    break;
 	case HexDigit:
-	    if(isdigit(inc) ||
+	    if(isdigit((unsigned char)inc) ||
 		(inc >= 'a' && inc <= 'f') ||
 		(inc >= 'A' && inc <= 'F')) {
 		found = True;
@@ -599,24 +599,24 @@ _XmPictureFollowTransitions(XmPictureSta
 	    }
 	    break;
 	case AnyLetter:
-	    if(isalpha(inc)) {
+	    if(isalpha((unsigned char)inc)) {
 		found = True;
 	    }
 	    break;
 	case UpCaseLetter:
-	    if(isalpha(inc)) {
-		changed_c = toupper(inc);
+	    if(isalpha((unsigned char)inc)) {
+		changed_c = toupper((unsigned char)inc);
 		found = True;
 	    }
 	    break;
 	case AnyCharacter:
-	    if(isalnum(inc)) {
+	    if(isalnum((unsigned char)inc)) {
 		found = True;
 	    }
 	    break;
 	case UpCaseCharacter:
-	    if(isalnum(inc)) {
-		changed_c = toupper(inc);
+	    if(isalnum((unsigned char)inc)) {
+		changed_c = toupper((unsigned char)inc);
 		found = True;
 	    }
 	    break;
