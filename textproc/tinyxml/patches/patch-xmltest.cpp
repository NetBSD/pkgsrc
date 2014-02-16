$NetBSD: patch-xmltest.cpp,v 1.1 2014/02/16 23:16:05 wiz Exp $

Fix entity encoding. From
http://sourceforge.net/p/tinyxml/patches/51/

--- xmltest.cpp.orig	2011-05-15 02:24:57.000000000 +0000
+++ xmltest.cpp
@@ -1366,6 +1366,16 @@ int main()
 		}*/
 	}
 
+	#ifdef TIXML_USE_STL
+	{
+		TiXmlDocument xml;
+		xml.Parse("<foo>foo&amp;#xa+bar</foo>");
+		std::string str;
+		str << xml;
+		XmlTest( "Entity escaping", "<foo>foo&amp;#xa+bar</foo>", str.c_str() );
+	}
+	#endif
+
 	/*  1417717 experiment
 	{
 		TiXmlDocument xml;
