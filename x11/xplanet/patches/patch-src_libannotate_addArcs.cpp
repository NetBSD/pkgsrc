$NetBSD: patch-src_libannotate_addArcs.cpp,v 1.1 2018/02/13 12:45:02 ryoon Exp $

--- src/libannotate/addArcs.cpp.orig	2008-11-13 23:43:42.000000000 +0000
+++ src/libannotate/addArcs.cpp
@@ -258,10 +258,14 @@ addArcs(PlanetProperties *planetProperti
         {
             ifstream inFile(arcFile.c_str());
             char *line = new char[MAX_LINE_LENGTH];
-            while (inFile.getline (line, MAX_LINE_LENGTH, '\n') != NULL)
-                readArcFile(line, planet, view, projection,
-                            planetProperties, annotationMap);
-            
+	    while (1)
+	    {
+		inFile.getline (line, MAX_LINE_LENGTH, '\n');
+ 		if (inFile.eof() || inFile.fail())
+		    break;
+		readArcFile(line, planet, view, projection,
+			    planetProperties, annotationMap);
+	    }            
             inFile.close();
             delete [] line;
         }
@@ -292,9 +296,13 @@ addArcs(View *view, multimap<double, Ann
         {
             ifstream inFile(arcFile.c_str());
             char *line = new char[256];
-            while (inFile.getline (line, 256, '\n') != NULL)
-                readArcFile(line, NULL, view, NULL, NULL, annotationMap);
-
+	    while (1)
+	    {
+		inFile.getline (line, 256, '\n');
+ 		if (inFile.eof() || inFile.fail())
+		    break;
+		readArcFile(line, NULL, view, NULL, NULL, annotationMap);
+	    }            
             inFile.close();
             delete [] line;
         }
