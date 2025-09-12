$NetBSD: patch-libAfterBase_mystring.c,v 1.1 2025/09/12 02:18:42 gutteridge Exp $

Use ctype.h correctly.

--- libAfterBase/mystring.c.orig	2013-05-01 13:34:11.000000000 +0000
+++ libAfterBase/mystring.c
@@ -43,11 +43,11 @@ mystrcasecmp (const char *s1, const char
 		/* in some BSD implementations, tolower(c) is not defined
 		 * unless isupper(c) is true */
 		c1 = s1[i];
-		if (isupper (c1))
-			c1 = tolower (c1);
+		if (isupper((unsigned char)c1))
+			c1 = tolower((unsigned char)c1);
 		c2 = s2[i];
-		if (isupper (c2))
-			c2 = tolower (c2);
+		if (isupper((unsigned char)c2))
+			c2 = tolower((unsigned char)c2);
 
 		++i ;
 		if (c1 != c2)
@@ -70,10 +70,10 @@ mystrncasecmp (const char *s1, const cha
 		++i ;
 		if (c1==0)
 			return -c2;
-		if (isupper (c1))
-			c1 = tolower(c1);
-		if (isupper (c2))
-			c2 = tolower(c2);
+		if (isupper((unsigned char)c1))
+			c1 = tolower((unsigned char)c1);
+		if (isupper((unsigned char)c2))
+			c2 = tolower((unsigned char)c2);
 		if (c1 != c2)
 			return (c1 - c2);
 	}
