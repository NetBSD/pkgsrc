$NetBSD: patch-tinyxml.cpp,v 1.1 2014/02/16 23:16:05 wiz Exp $

Fix entity encoding. From
http://sourceforge.net/p/tinyxml/patches/51/

--- tinyxml.cpp.orig	2011-05-15 02:24:57.000000000 +0000
+++ tinyxml.cpp
@@ -57,30 +57,7 @@ void TiXmlBase::EncodeString( const TIXM
 	{
 		unsigned char c = (unsigned char) str[i];
 
-		if (    c == '&' 
-		     && i < ( (int)str.length() - 2 )
-			 && str[i+1] == '#'
-			 && str[i+2] == 'x' )
-		{
-			// Hexadecimal character reference.
-			// Pass through unchanged.
-			// &#xA9;	-- copyright symbol, for example.
-			//
-			// The -1 is a bug fix from Rob Laveaux. It keeps
-			// an overflow from happening if there is no ';'.
-			// There are actually 2 ways to exit this loop -
-			// while fails (error case) and break (semicolon found).
-			// However, there is no mechanism (currently) for
-			// this function to return an error.
-			while ( i<(int)str.length()-1 )
-			{
-				outString->append( str.c_str() + i, 1 );
-				++i;
-				if ( str[i] == ';' )
-					break;
-			}
-		}
-		else if ( c == '&' )
+		if ( c == '&' )
 		{
 			outString->append( entity[0].str, entity[0].strLength );
 			++i;
