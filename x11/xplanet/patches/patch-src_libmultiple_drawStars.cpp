$NetBSD: patch-src_libmultiple_drawStars.cpp,v 1.1 2018/02/13 12:45:02 ryoon Exp $

--- src/libmultiple/drawStars.cpp.orig	2006-03-26 04:55:59.000000000 +0000
+++ src/libmultiple/drawStars.cpp
@@ -41,8 +41,12 @@ drawStars(DisplayBase *display, View *vi
     ifstream inFile(starMap.c_str());
 
     char line[MAX_LINE_LENGTH];
-    while (inFile.getline(line, MAX_LINE_LENGTH, '\n') != NULL)
+    while (1)
     {
+	inFile.getline(line, MAX_LINE_LENGTH, '\n');
+	if (inFile.eof() || inFile.fail())
+	    break;
+
         if (line[0] == '#') continue;
 
         double Vmag, RA, Dec;
