$NetBSD: patch-tinyxml.h,v 1.1 2014/02/16 23:05:33 wiz Exp $

Force the use of STL in tinyxml.h.

--- tinyxml.h~	2011-05-15 04:24:57.000000000 +0200
+++ tinyxml.h	2013-06-20 23:42:16.000000000 +0200
@@ -26,6 +26,10 @@
 #ifndef TINYXML_INCLUDED
 #define TINYXML_INCLUDED
 
+#ifndef TIXML_USE_STL
+#	define TIXML_USE_STL
+#endif
+
 #ifdef _MSC_VER
 #pragma warning( push )
 #pragma warning( disable : 4530 )
