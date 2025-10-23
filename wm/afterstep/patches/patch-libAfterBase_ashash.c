$NetBSD: patch-libAfterBase_ashash.c,v 1.5 2025/10/23 01:28:08 gutteridge Exp $

Patch up gcc inline mess.
Use ctype.h correctly.

--- libAfterBase/ashash.c.orig	2013-05-01 13:34:11.000000000 +0000
+++ libAfterBase/ashash.c
@@ -39,7 +39,7 @@
 static ASHashItem*  deallocated_mem[DEALLOC_CACHE_SIZE+10] ;
 static unsigned int deallocated_used = 0 ;
 
-static inline void
+static void
 free_ashash_item( ASHashItem *item )
 {
 
@@ -533,7 +533,7 @@ remove_curr_hash_item (ASHashIterator * 
 		}
 }
 
-inline ASHashableValue
+ASHashableValue
 curr_hash_value (ASHashIterator * iterator)
 {
 	if (iterator)
@@ -544,7 +544,7 @@ curr_hash_value (ASHashIterator * iterat
 	return (ASHashableValue) ((char *)NULL);
 }
 
-inline void         *
+void         *
 curr_hash_data (ASHashIterator * iterator)
 {
 	if (iterator)
@@ -663,19 +663,19 @@ casestring_hash_value (ASHashableValue v
 	{
 		if( (c=string[i]) != 0)
 		{
-			if (isupper (c))c = tolower (c);
+			if (isupper ((unsigned char)c))c = tolower ((unsigned char)c);
 			hash_key += (ASHashKey) c;
 			if( string[++i] != 0 && (c=string[++i]) != 0)
 			{
-				if (isupper (c))c = tolower (c);
+				if (isupper ((unsigned char)c))c = tolower ((unsigned char)c);
 				hash_key += ((ASHashKey) c)<<1;
 				if( string[++i] != 0 && (c=string[++i]) != 0)
 				{
-					if (isupper (c))c = tolower (c);
+					if (isupper ((unsigned char)c))c = tolower ((unsigned char)c);
 					hash_key += ((ASHashKey) c)<<2;
 					if( string[++i] != 0 && (c=string[++i]) != 0)
 					{
-						if (isupper (c))c = tolower (c);
+						if (isupper ((unsigned char)c))c = tolower ((unsigned char)c);
 						hash_key += ((ASHashKey) c)<<3;
 					}
 				}
@@ -706,10 +706,10 @@ casestring_compare (ASHashableValue valu
 
 		u1 = str1[i];
 		u2 = str2[i];
-		if (islower (u1))
-			u1 = toupper (u1);
-		if (islower (u2))
-			u2 = toupper (u2);
+		if (islower ((unsigned char)u1))
+			u1 = toupper ((unsigned char)u1);
+		if (islower ((unsigned char)u2))
+			u2 = toupper ((unsigned char)u2);
 		if (u1 != u2)
 			return (long)u1 - (long)u2;
 	}while( str1[i++] );
@@ -728,11 +728,11 @@ option_hash_value (ASHashableValue value
 	do
 	{
 		c = opt[i];
-#define VALID_OPTION_CHAR(c)		(isalnum ((int)c) || (c) == '~' || (c) == '_')
+#define VALID_OPTION_CHAR(c)		(isalnum ((unsigned char)c) || (c) == '~' || (c) == '_')
 		if (c == '\0' || !VALID_OPTION_CHAR(c))
 			break;
-		if (isupper ((int)c))
-			c = tolower ((int)c);
+		if (isupper ((unsigned char)c))
+			c = tolower ((unsigned char)c);
 		hash_key += (((ASHashKey) c) << i);
 		++i;
 	}while( i < ((sizeof (ASHashKey) - sizeof (char)) << 3) );
@@ -762,10 +762,10 @@ option_compare (ASHashableValue value1, 
 			return ( VALID_OPTION_CHAR(u2) )? (long)u1 - (long)u2: 0;
 		++i ;
 
-		if (islower (u1))
-			u1 = toupper (u1);
-		if (islower (u2))
-			u2 = toupper (u2);
+		if (islower ((unsigned char)u1))
+			u1 = toupper ((unsigned char)u1);
+		if (islower ((unsigned char)u2))
+			u2 = toupper ((unsigned char)u2);
 		if (u1 != u2)
 			return (long)u1 - (long)u2;
 	}
